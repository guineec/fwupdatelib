#include "fwupdate.h"
#include <stdint.h>
#include <stdio.h>
#include <math.h>

uint8_t get_opcode(uint8_t *pkt) {
  // Get the first 4 bits of the first byte and convert to decimal
  uint8_t acc = 0;
  for(uint8_t i = 0; i < 4; i++) {
    uint8_t bit = (pkt[0] >> (4 + i)) & 1;
    acc += (bit * (pow(2, i)));
  }
  return acc;
}

uint8_t get_index(uint8_t *pkt) {
  return pkt[2];
}

unsigned short get_seq_num(uint8_t *pkt) {
  // Extract the last 4 bits of the first byte as decimal
  unsigned short acc = 0;
  for(uint8_t i = 0; i < 4; i++) {
    uint8_t bit = pkt[0] << (4 + i);
    bit = bit >> 7;
    acc += bit * (pow(2, (11 - i)));
  }
  // Add the second byte to it
  acc += pkt[1];
  return acc;
}



