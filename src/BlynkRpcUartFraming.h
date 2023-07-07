#ifndef BLYNK_RPC_UART_FRAMING_H
#define BLYNK_RPC_UART_FRAMING_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void    RpcUartFraming_init();

void    RpcUartFraming_beginPacket();
size_t  RpcUartFraming_write(const uint8_t *buffer, size_t size);
void    RpcUartFraming_endPacket();

int     RpcUartFraming_available();
int     RpcUartFraming_read();
bool    RpcUartFraming_finishedPacket();
bool    RpcUartFraming_checkPacketCRC();

#ifdef __cplusplus
}
#endif

#endif
