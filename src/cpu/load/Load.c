#include "Load.h"
#include "Registers.h"
#include "Memory.h"

void nop(unsigned char opcode) {}
void ld_r16_imm16(unsigned char opcode, unsigned short *r16, const unsigned short imm16) { *r16 = imm16; }
void ld__r16mem__a(unsigned char opcode, const unsigned short _r16_mem_) { mem[_r16_mem_] = registers.a; }
void ld_a__r16mem_(unsigned char opcode, const unsigned short _r16_mem_) { registers.a = mem[_r16_mem_]; }
void ld__imm16__sp(unsigned char opcode, const unsigned short _imm16_) { mem[_imm16_] = registers.sp; }
void ld_r8_imm8(unsigned char opcode, unsigned char *r8, const unsigned char imm8) { *r8 = imm8; }
void ld_r8_r8(unsigned char opcode, unsigned char *r8_1, unsigned char *r8_2)
{
    if (r8_1 == r8_2)
        return;
    *r8_1 = *r8_2;
}
void ldh__c__a(unsigned char opcode) { mem[0xFF00 + registers.c] = registers.a; }
void ldh__imm8__a(unsigned char opcode, const unsigned char _imm8_) { mem[0xFF00 + _imm8_] = registers.a; }
void ld__imm16__a(unsigned char opcode, const unsigned short _imm16_) { mem[_imm16_] = registers.a; }
void ldh_a__c_(unsigned char opcode) { registers.a = mem[0xFF00 + registers.c]; }
void ldh_a__imm8_(unsigned char opcode, const unsigned char _imm8_) { registers.a = mem[0xFF00 + _imm8_]; }
void ld_a__imm16_(unsigned char opcode, const unsigned short _imm16_) { registers.a = mem[_imm16_]; }
void ld_hl_spplimm8(unsigned char opcode, const unsigned char _imm8_)
{
    setZFlag(0);
    setNFlag(0);
    setHFlag(((registers.sp) & 0x000F) + (_imm8_ & 0x000F) > 0x000F);
    setCFlag(((registers.sp) & 0x00FF) + (_imm8_ & 0x00FF) > 0x00FF);
    registers.hl = mem[registers.sp + _imm8_];
}
void ld_sp_hl(unsigned char opcode) { registers.sp = registers.hl; }