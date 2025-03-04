/*
All load op function implmentations.
*/

#include "Load.h"
#include "Registers.h"
#include "Memory.h"
#include "CPU.h"

void nop(unsigned char opcode) {}
void ld_r16_imm16(unsigned char opcode, unsigned short *r16, const unsigned short imm16) { *r16 = imm16; }
void ld_r16mem_a(unsigned char opcode, const unsigned short r16mem) { setMemByte(r16mem, cpu.registers->a); }
void ld_a_r16mem(unsigned char opcode, const unsigned short r16mem) { cpu.registers->a = getMemByte(r16mem); }
void ld_imm16mem_sp(unsigned char opcode, const unsigned short imm16mem)
{
    setMemByte(imm16mem, cpu.registers->sp);
    setMemByte(imm16mem + 1, (cpu.registers->sp) >> 8);
}
void ld_r8_imm8(unsigned char opcode, unsigned char *r8, const unsigned char imm8) { *r8 = imm8; }
void ld_r8_r8(unsigned char opcode, unsigned char *r8_1, unsigned char *r8_2)
{
    if (r8_1 == r8_2)
        return;
    *r8_1 = *r8_2;
}
void ldh_cmem_a(unsigned char opcode) { setMemByte(0xFF00 + cpu.registers->c, cpu.registers->a); }
void ldh_imm8mem_a(unsigned char opcode, const unsigned char imm8mem) { setMemByte(0xFF00 + imm8mem, cpu.registers->a); }
void ld_imm16mem_a(unsigned char opcode, const unsigned short imm16mem) { setMemByte(imm16mem, cpu.registers->a); }
void ldh_a_cmem(unsigned char opcode) { cpu.registers->a = getMemByte(0xFF00 + cpu.registers->c); }
void ldh_a_imm8mem(unsigned char opcode, const unsigned char imm8mem) { cpu.registers->a = getMemByte(0xFF00 + imm8mem); }
void ld_a_imm16mem(unsigned char opcode, const unsigned short imm16mem) { cpu.registers->a = getMemByte(imm16mem); }
void ld_hl_sp_plus_imm8mem(unsigned char opcode, const unsigned char imm8mem)
{
    setZFlag(cpu.registers, 0);
    setNFlag(cpu.registers, 0);
    setHFlag(cpu.registers, ((cpu.registers->sp) & 0x000F) + (imm8mem & 0x000F) > 0x000F);
    setCFlag(cpu.registers, ((cpu.registers->sp) & 0x00FF) + (imm8mem & 0x00FF) > 0x00FF);
    cpu.registers->hl = cpu.registers->sp + imm8mem;
}
void ld_sp_hl(unsigned char opcode) { cpu.registers->sp = cpu.registers->hl; }


// Special HL+ (hli) and HL- (hld) functions
void ld_a_hlmem_i(unsigned char opcode) { cpu.registers->a = getMemByte(cpu.registers->hl); cpu.registers->hl++; }
void ld_a_hlmem_d(unsigned char opcode) { cpu.registers->a = getMemByte(cpu.registers->hl); cpu.registers->hl--; }
void ld_hlmem_i_a(unsigned char opcode) { setMemByte(cpu.registers->hl, cpu.registers->a); cpu.registers->hl++; }
void ld_hlmem_d_a(unsigned char opcode) { setMemByte(cpu.registers->hl, cpu.registers->a); cpu.registers->hl--; }

// Other [HL] functions, can be combined with ones above
// using memory addressing shenanigans
void ld_hlmem_imm8(unsigned char opcode, unsigned char imm8) { setMemByte(cpu.registers->hl, imm8); }
void ld_r8_hlmem(unsigned char opcode, unsigned char* r8) { *r8 = getMemByte(cpu.registers->hl); }
void ld_hlmem_r8(unsigned char opcode, unsigned char* r8) { setMemByte(cpu.registers->hl, *r8); }