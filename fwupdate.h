#include <stdint.h>
#include <stdlib.h>
#include <math.h>

uint8_t get_opcode(uint8_t *);
unsigned short get_seq_num(uint8_t *);
uint8_t get_index(uint8_t *);

void put_opcode(uint8_t *, uint8_t);
void put_seq_num(uint8_t *, unsigned short);
void make_uplink_packet(uint8_t *, uint8_t, unsigned short, uint8_t *, uint8_t);
