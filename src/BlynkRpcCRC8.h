#ifndef BLYNK_RPC_CRC8_H
#define BLYNK_RPC_CRC8_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const uint8_t RPC_CRC8_TABLE[256];

static inline
void crcReset(uint8_t* crc) {
  *crc = 0;
}

static inline
void crcUpdate(uint8_t* crc, uint8_t data) {
  *crc = RPC_CRC8_TABLE[*crc ^ data];
}

#ifdef __cplusplus
}
#endif

#endif
