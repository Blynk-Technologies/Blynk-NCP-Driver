#pragma once

#include <stddef.h>
#include <stdint.h>

class BlynkStream
{
public:
  // Returns >=1 if data can be read from stream, 0 otherwise
  virtual int     available()       = 0;
  // Reads the next byte from stream, returns -1 if no data available
  virtual int     read()            = 0;
  // Writes a single byte to the stream
  virtual size_t  write(uint8_t c)  = 0;
  // Waits until all bytes are actually transmitted
  virtual void    flush()           = 0;
};

int rpc_uart_available();
int rpc_uart_read();
size_t rpc_uart_write(uint8_t c);
void rpc_uart_flush();

class StreamExternImpl: public BlynkStream
{
public:
  virtual int available()         { return rpc_uart_available();  }
  virtual int read()              { return rpc_uart_read();       }
  virtual size_t write(uint8_t c) { return rpc_uart_write(c);     }
  virtual void flush()            { return rpc_uart_flush();      }
};
