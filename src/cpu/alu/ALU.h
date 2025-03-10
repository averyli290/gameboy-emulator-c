
/*
All ALU op function signatures.
*/

#ifndef ALU_H
#define ALU_H

#include "Registers.h"
#include "Memory.h"

// 16 bit arithmetic
void inc_r16(unsigned char opcode, unsigned short* r16);
void dec_r16(unsigned char opcode, unsigned short* r16);
void add_hl_r16(unsigned char opcode, unsigned short* r16);
void add_sp_imm8(unsigned char opcode, unsigned char imm8);

// 8 bit arithmetic
void inc_r8(unsigned char opcode, unsigned char* r8);
void dec_r8(unsigned char opcode, unsigned char* r8);
void add_a_r8(unsigned char opcode, unsigned char* r8);
void adc_a_r8(unsigned char opcode, unsigned char* r8);
void sub_a_r8(unsigned char opcode, unsigned char* r8);
void sbc_a_r8(unsigned char opcode, unsigned char* r8);
void add_a_imm8(unsigned char opcode, unsigned char imm8);
void adc_a_imm8(unsigned char opcode, unsigned char imm8);
void sub_a_imm8(unsigned char opcode, unsigned char imm8);
void sbc_a_imm8(unsigned char opcode, unsigned char imm8);

// 8 bit logic
void and_a_r8(unsigned char opcode, unsigned char* r8);
void xor_a_r8(unsigned char opcode, unsigned char* r8);
void or_a_r8(unsigned char opcode, unsigned char* r8);
void cp_a_r8(unsigned char opcode, unsigned char* r8);
void and_a_imm8(unsigned char opcode, unsigned char imm8);
void xor_a_imm8(unsigned char opcode, unsigned char imm8);
void or_a_imm8(unsigned char opcode, unsigned char imm8);
void cp_a_imm8(unsigned char opcode, unsigned char imm8);


// [HL] specific
void inc_hlmem(unsigned char opcode);
void dec_hlmem(unsigned char opcode);
void add_a_hlmem(unsigned char opcode);
void adc_a_hlmem(unsigned char opcode);
void sub_a_hlmem(unsigned char opcode);
void sbc_a_hlmem(unsigned char opcode);
void and_a_hlmem(unsigned char opcode);
void xor_a_hlmem(unsigned char opcode);
void or_a_hlmem(unsigned char opcode);
void cp_a_hlmem(unsigned char opcode);



// Other
void daa(unsigned char opcode);
void cpl(unsigned char opcode);
void scf(unsigned char opcode);
void ccf(unsigned char opcode);



#endif