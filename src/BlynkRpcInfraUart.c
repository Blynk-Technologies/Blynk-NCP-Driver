
#include "BlynkRpc.h"
#include "BlynkRpcUartFraming.h"

uint8_t  inputData[2048];
unsigned inputDataLen;

bool rpc_recv_msg(MessageBuffer* buff, uint32_t timeout)
{
  MessageBuffer_reset(buff);
  const uint32_t tstart = rpc_system_millis();
  do {
    while (RpcUartFraming_available()) {
      // TODO: boundary check
      inputData[inputDataLen++] = RpcUartFraming_read();
    }

    if (RpcUartFraming_finishedPacket()) {
      unsigned packetSize = inputDataLen;
      inputDataLen = 0;

      //TRACE_HEX(">>", inputData, packetSize);
      if (RpcUartFraming_checkPacketCRC()) {
        MessageBuffer_setBuffer(buff, inputData, sizeof(inputData));
        MessageBuffer_setWritten(buff, packetSize);
        return true;
      } else {
        //LOG("NCP message CRC error");
      }
    }
  } while (rpc_system_millis() - tstart < timeout);
  return false;
}

void rpc_send_msg(MessageBuffer* buff)
{
  uint8_t* data = MessageBuffer_getBuffer(buff);
  uint32_t len = MessageBuffer_getWritten(buff);
  //TRACE_HEX("<<", data, len);

  RpcUartFraming_beginPacket();
  RpcUartFraming_write(data, len);
  RpcUartFraming_endPacket();
}