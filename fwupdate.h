#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

uint8_t get_opcode(uint8_t *);
unsigned short get_seq_num(uint8_t *);
uint8_t get_index(uint8_t *pkt);