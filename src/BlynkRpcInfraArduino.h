
#include <SerialFramingStream.h>

uint8_t  inputData[2048];
unsigned inputDataLen;

SerialFramingStream stream(SerialNCP);

bool rpc_recv_msg(MessageBuffer* buff, uint32_t timeout)
{
  MessageBuffer_reset(buff);
  const uint32_t tstart = millis();
  do {
    while (stream.available()) {
      // TODO: boundary check
      inputData[inputDataLen++] = stream.read();
    }

    if (stream.finishedPacket()) {
      unsigned packetSize = inputDataLen;
      inputDataLen = 0;

      //TRACE_HEX(">>", inputData, packetSize);
      if (stream.checkPacketCRC()) {
        MessageBuffer_setBuffer(buff, inputData, sizeof(inputData));
        MessageBuffer_setWritten(buff, packetSize);
        return true;
      } else {
        //LOG("NCP message CRC error");
      }
    } else if (timeout > 0) {
      delay(1);
    }
  } while (millis() - tstart < timeout);
  return false;
}

void rpc_send_msg(MessageBuffer* buff)
{
  uint8_t* data = MessageBuffer_getBuffer(buff);
  uint32_t len = MessageBuffer_getWritten(buff);
  //TRACE_HEX("<<", data, len);

  stream.beginPacket();
  stream.write(data, len);
  stream.endPacket();
}
