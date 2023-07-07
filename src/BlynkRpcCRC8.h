#ifndef BLYNK_RPC_CRC8_H
#define BLYNK_RPC_CRC8_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline
void crcReset(uint8_t* crc) {
  *crc = 0;
}

static inline
void crcUpdate(uint8_t* crc, uint8_t data) {
#if defined(RPC_ENABLE_SMALL_CRC8)
  uint8_t b = *crc ^ data;
  for (int i = 0; i < 8; i++) {
    b = (b << 1) ^ ((b & 0x80) ? 0x07 : 0);
  }
  *crc = b;
#else
  extern const uint8_t RPC_CRC8_TABLE[256];
  *crc = RPC_CRC8_TABLE[*crc ^ data];
#endif
}

#ifdef __cplusplus
}
#endif

#endif
