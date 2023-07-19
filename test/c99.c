
#include "BlynkRpcClient.h"
#include "BlynkRpcUartFraming.h"

int rpc_uart_available() {
  return 0;
}
int rpc_uart_read() {
  return -1;
}
size_t rpc_uart_write(uint8_t data) {
  return 0;
}
void rpc_uart_flush() {
}
uint32_t rpc_system_millis() {
  return 0;
}

int main() {
  return 0;
}

