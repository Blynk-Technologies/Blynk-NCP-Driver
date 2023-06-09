#pragma once

#if defined(ARDUINO)
  #include <Stream.h>
  typedef Stream BlynkStream;
#else
  #include <compat/BlynkStream.h>
#endif

class SerialFramingStream
  : public BlynkStream
{
  enum SpecialByte : uint8_t {
    BEG   = 0xAA,
    END   = 0xBB,
    ESC   = 0xCC,
    XON   = 0x11,
    XOFF  = 0x13
  };

  static const uint8_t CRC_TABLE[256];

public:
  SerialFramingStream(BlynkStream &serial)
    : _stream(serial)
  {
    crcReset(_rcrc);
    crcReset(_wcrc);
  }

  void beginPacket() {
    crcReset(_wcrc);
    _stream.write(BEG);
  }

  void endPacket() {
    write(_wcrc); // CRC needs to be escaped, if needed
    _stream.write(END);
    _stream.flush();
  }

  bool finishedPacket() const {
    return _state == State::END && !hasPacketData();
  }

  bool checkPacketCRC() {
    if (!finishedPacket()) { return false; }
    const uint8_t expected = _rcrc;
    const uint8_t actual = _buffer.data[_buffer.read++];
    _buffer.read %= sizeof(_buffer.data);
    _buffer.count--;
    crcReset(_rcrc);
    _state = State::BEG;
    return actual == expected;
  }

  size_t write(const uint8_t *buffer, size_t size) {
    size_t n = 0;
    while (size--) {
      if (write(*buffer++)) n++;
      else break;
    }
    return n;
  }

  size_t write(uint8_t data) override {
    crcUpdate(_wcrc, data);
    if (data == BEG || data == END || data == ESC ||
        (_escapeXonXoff && (data == XON || data == XOFF))
    ) {
      _stream.write(ESC);
      data ^= 0xFF;
    }
    return _stream.write(data);
  }

  int available() override {
    processInput();
    // The last byte of the message is CRC
    return hasPacketData() ? (_buffer.count - 1) : 0;
  }

  int read() override {
    processInput();
    if (_buffer.count <= 1) {
      return -1;
    }
    uint8_t data = _buffer.data[_buffer.read++];
    _buffer.read %= sizeof(_buffer.data);
    _buffer.count--;

    crcUpdate(_rcrc, data);
    return data;
  }

  int peek() {
    processInput();
    return hasPacketData() ? _buffer.data[_buffer.read] : -1;
  }

  void flush() override {
    _stream.flush();
  }

private:
  enum class State {
    BEG,
    DATA,
    ESC,
    END
  };

  struct Buffer {
    uint8_t data[32];
    uint8_t read = 0;
    uint8_t write = 0;
    uint8_t count = 0;
  };

  bool hasPacketData() const { return _buffer.count > 1; }

  static void crcReset(uint8_t& crc) {
    crc = 0;
  }

  static void crcUpdate(uint8_t& crc, uint8_t data) {
    crc = CRC_TABLE[crc ^ data];
  }

  void processInput() {
    // Wait before the existing packet is consumed (including CRC)
    if (_state == State::END && _buffer.count > 0) { return; }

    while (_stream.available() && _buffer.count < sizeof(_buffer.data)) {
      uint8_t data = _stream.read();
      switch (_state) {
        case State::BEG:
          if (data == BEG) {
            _state = State::DATA;
          }
          break;
        case State::DATA:
          if (data == ESC) {
            _state = State::ESC;
          } else if (data == END) {
            _state = State::END;
            return;
          } else {
            _buffer.data[_buffer.write++] = data;
            _buffer.write %= sizeof(_buffer.data);
            _buffer.count++;
          }
          break;
        case State::ESC:
          data ^= 0xFF;
          _buffer.data[_buffer.write++] = data;
          _buffer.write %= sizeof(_buffer.data);
          _buffer.count++;
          _state = State::DATA;
          break;
        case State::END:
          if (data == BEG) {
            _state = State::DATA;
          }
          break;
      }
    }
  }

private:
  BlynkStream& _stream;
  State   _state = State::BEG;
  Buffer  _buffer;
  uint8_t _rcrc;
  uint8_t _wcrc;
  bool    _escapeXonXoff = true;
};
