/*
All load op function implmentations.
*/

#include "Load.h"
#include "Registers.h"
#include "Memory.h"

void nop(unsigned char opcode) {}
void ld_r16_imm16(unsigned char opcode, unsigned short *r16, const unsigned short imm16) { *r16 = imm16; }
void ld_r16mem_a(unsigned char opcode, const unsigned short r16mem) { mem[r16mem] = registers.a; }
void ld_a_r16mem(unsigned char opcode, const unsigned short r16mem) { registers.a = mem[r16mem]; }
void ld_imm16mem_sp(unsigned char opcode, const unsigned short imm16mem)
{
    mem[imm16mem] = registers.sp;
    mem[imm16mem + 1] = registers.sp >> 8;
}
void ld_r8_imm8(unsigned char opcode, unsigned char *r8, const unsigned char imm8) { *r8 = imm8; }
void ld_r8_r8(unsigned char opcode, unsigned char *r8_1, unsigned char *r8_2)
{
    if (r8_1 == r8_2)
        return;
    *r8_1 = *r8_2;
}
void ldh_cmem_a(unsigned char opcode) { mem[0xFF00 + registers.c] = registers.a; }
void ldh_imm8mem_a(unsigned char opcode, const unsigned char imm8mem) { mem[0xFF00 + imm8mem] = registers.a; }
void ld_imm16mem_a(unsigned char opcode, const unsigned short imm16mem) { mem[imm16mem] = registers.a; }
void ldh_a_cmem(unsigned char opcode) { registers.a = mem[0xFF00 + registers.c]; }
void ldh_a_imm8mem(unsigned char opcode, const unsigned char imm8mem) { registers.a = mem[0xFF00 + imm8mem]; }
void ld_a_imm16mem(unsigned char opcode, const unsigned short imm16mem) { registers.a = mem[imm16mem]; }
void ld_hl_sp_plus_imm8mem(unsigned char opcode, const unsigned char imm8mem)
{
    setZFlag(0);
    setNFlag(0);
    setHFlag(((registers.sp) & 0x000F) + (imm8mem & 0x000F) > 0x000F);
    setCFlag(((registers.sp) & 0x00FF) + (imm8mem & 0x00FF) > 0x00FF);
    registers.hl = mem[registers.sp + imm8mem];
}
void ld_sp_hl(unsigned char opcode) { registers.sp = registers.hl; }


// Special HL+ (hli) and HL- (hld) functions
void ld_a_hlmem_i(unsigned char opcode) { registers.a = getMemByte(registers.hl); registers.hl++; }
void ld_a_hlmem_d(unsigned char opcode) { registers.a = getMemByte(registers.hl); registers.hl--; }
void ld_hlmem_i_a(unsigned char opcode) { setMemByte(registers.hl, registers.a); registers.hl++; }
void ld_hlmem_d_a(unsigned char opcode) { setMemByte(registers.hl, registers.a); registers.hl--; }

// Other [HL] functions, can be combined with ones above
// using memory addressing shenanigans
void ld_hlmem_imm8(unsigned char opcode, unsigned char imm8) { setMemByte(registers.hl, imm8); }
void ld_r8_hlmem(unsigned char opcode, unsigned char* r8) { *r8 = getMemByte(registers.hl); }
void ld_hlmem_r8(unsigned char opcode, unsigned char* r8) { setMemByte(registers.hl, *r8); }