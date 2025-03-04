#ifndef LOAD_H
#define LOAD_H

#include "Registers.h"

void nop(unsigned char opcode);
void ld_r16_imm16(unsigned char opcode, unsigned short *r16, const unsigned short imm16);
void ld__r16mem__a(unsigned char opcode, const unsigned short _r16_mem_);
void ld_a__r16mem_(unsigned char opcode, const unsigned short _r16_mem_);
void ld__imm16__sp(unsigned char opcode, const unsigned short _imm16_);
void ld_r8_imm8(unsigned char opcode, unsigned char *r8, const unsigned char imm8);
void ld_r8_r8(unsigned char opcode, unsigned char *r8_1, unsigned char *r8_2);
void ldh__c__a(unsigned char opcode);
void ldh__imm8__a(unsigned char opcode, const unsigned char _imm8_);
void ld__imm16__a(unsigned char opcode, const unsigned short _imm16_);
void ldh_a__c_(unsigned char opcode);
void ldh_a__imm8_(unsigned char opcode, const unsigned char _imm8_);
void ld_a__imm16_(unsigned char opcode, const unsigned short _imm16_);
void ld_hl_spplimm8(unsigned char opcode, const unsigned char _imm8_);

#endif