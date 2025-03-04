/*
All load op function signatures.

Note: [HL] = mem + HL

LD r8,r8        ld_r8_r8 
LD r8,n8        ld_r8_imm8
LD r16,n16      ld_r16_imm16
LD [HL],r8      ld_r8_r8 
LD [HL],n8      ld_r8_imm8
LD r8,[HL]      ld_r8_r8 
LD [r16],A      ld_r16mem_a
LD [n16],A      ld_imm16mem_a
LDH [n16],A     ld_a
LDH [C],A
LD A,[r16]
LD A,[n16]
LDH A,[n16]
LDH A,[C]
LD [HLI],A
LD [HLD],A
LD A,[HLI]
LD A,[HLD]

Added extra HL functions to handle those to make it easier to read.

*/

#ifndef LOAD_H
#define LOAD_H

#include "Registers.h"
#include "Memory.h"

void nop(unsigned char opcode);
void ld_r16_imm16(unsigned char opcode, unsigned short *r16, const unsigned short imm16);
void ld_r16mem_a(unsigned char opcode, const unsigned short r16mem);
void ld_a_r16mem(unsigned char opcode, const unsigned short r16mem);
void ld_imm16mem_sp(unsigned char opcode, const unsigned short imm16mem);
void ld_r8_imm8(unsigned char opcode, unsigned char *r8, const unsigned char imm8);
void ld_r8_r8(unsigned char opcode, unsigned char *r8_1, unsigned char *r8_2);
void ldh_cmem_a(unsigned char opcode);
void ldh_imm8mem_a(unsigned char opcode, const unsigned char imm8mem);
void ld_imm16mem_a(unsigned char opcode, const unsigned short imm16mem);
void ldh_a_cmem(unsigned char opcode);
void ldh_a_imm8mem(unsigned char opcode, const unsigned char imm8mem);
void ld_a_imm16mem(unsigned char opcode, const unsigned short imm16mem);
void ld_hl_sp_plus_imm8mem(unsigned char opcode, const unsigned char imm8mem);
void ld_sp_hl(unsigned char opcode);

// Special HL+ (hli) and HL- (hld) functions
void ld_hlmem_i_a(unsigned char opcode);
void ld_a_hlmem_i(unsigned char opcode);
void ld_hlmem_d_a(unsigned char opcode);
void ld_a_hlmem_d(unsigned char opcode);

// Other [HL] functions, can be combined with ones above
// using memory addressing shenanigans
void ld_hlmem_imm8(unsigned char opcode, unsigned char imm8);
void ld_r8_hlmem(unsigned char opcode, unsigned char* r8);
void ld_hlmem_r8(unsigned char opcode, unsigned char* r8);


#endif