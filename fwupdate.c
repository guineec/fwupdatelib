#include "fwupdate.h"
#include <stdint.h>
#include <math.h>
#include <stdio.h>

// Functions for extracting from downlink packets
uint8_t get_opcode(uint8_t *pkt)
{
  // Opcode is the first 4 bits
  return pkt[0] >> 4;
}

uint8_t get_index(uint8_t *pkt)
{
  // Index is easy, just the 3rd byte of the DL packet
  return pkt[2];
}

unsigned short get_seq_num(uint8_t *pkt)
{
  // Extract the last 4 bits of the first byte as decimal
  unsigned short ret = pkt[0] & 0x0F;
  // Add the second byte to it
  ret += pkt[1];
  return ret;
}

// Functions for creating uplink packets
void put_opcode(uint8_t *tx_buff, uint8_t code)
{
  code = code << 4;
  tx_buff[0] |= code;
}

void put_seq_num(uint8_t *tx_buff, unsigned short seq_num)
{
  uint8_t first_part = seq_num >> 8;
  tx_buff[0] |= first_part;
  // AND out the opcode
  uint8_t second_part = seq_num & 255;
  tx_buff[1] = second_part;
}

void make_uplink_packet(uint8_t *tx_buff, uint8_t opcode,
                        unsigned short sequence_number, uint8_t *data, uint8_t data_size)
{
  put_opcode(tx_buff, opcode);
  put_seq_num(tx_buff, sequence_number);
  for (uint8_t i = 0; i < data_size; i++) {
			tx_buff[2 + i] = data[i];
	}
}
