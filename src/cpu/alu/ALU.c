/*
All ALU op function implmentations.
*/

#include "CPU.h"
#include "ALU.h"
#include "Registers.h"
#include "Memory.h"
#include "ArithmeticUtils.h"

// 16 bit arithmetic
void inc_r16(unsigned char opcode, unsigned short* r16) { *r16 += 1; }
void dec_r16(unsigned char opcode, unsigned short* r16) { *r16 -= 1; }
void add_hl_r16(unsigned char opcode, unsigned short* r16)
{
    struct ShortALUResult res = overflowingAddShort(HL_VAL, *r16);
    HL_REG = res.value;
    setNFlag(CPU_REGS, 0);
    setHFlag(CPU_REGS, res.h);
    setCFlag(CPU_REGS, res.c);
}
void add_sp_imm8(unsigned char opcode, unsigned char imm8)
{
    struct ByteALUResult res = overflowingAddByte(SP_VAL, imm8);
    SP_REG = res.value;
    setZNHCFlags(CPU_REGS, 0, 0, res.h, res.c);
}

// 8 bit arithmetic
void inc_r8(unsigned char opcode, unsigned char* r8)
{
    struct ByteALUResult res = overflowingAddByte(*r8, (char) 0x01);
    setZFlag(CPU_REGS, res.z);
    setNFlag(CPU_REGS, 0);
    setHFlag(CPU_REGS, res.h);
}
void dec_r8(unsigned char opcode, unsigned char* r8)
{
    struct ByteALUResult res = overflowingSubByte(*r8, (char) 0x01);
    setZFlag(CPU_REGS, res.z);
    setNFlag(CPU_REGS, 1);
    setHFlag(CPU_REGS, res.h);
}
void add_a_r8(unsigned char opcode, unsigned char* r8)
{
    struct ByteALUResult res = overflowingAddByte(A_VAL, *r8);
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void adc_a_r8(unsigned char opcode, unsigned char* r8) 
{
    struct ByteALUResult res = overflowingAddByte(A_VAL, *r8 + getCFlag(CPU_REGS));
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void sub_a_r8(unsigned char opcode, unsigned char* r8)
{
    struct ByteALUResult res = overflowingSubByte(A_VAL, *r8);
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void sbc_a_r8(unsigned char opcode, unsigned char* r8)
{
    struct ByteALUResult res = overflowingSubByte(A_VAL, *r8 + getCFlag(CPU_REGS));
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void add_a_imm8(unsigned char opcode, unsigned char imm8)
{
    struct ByteALUResult res = overflowingAddByte(A_VAL, imm8);
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void adc_a_imm8(unsigned char opcode, unsigned char imm8)
{
    struct ByteALUResult res = overflowingAddByte(A_VAL, imm8 + getCFlag(CPU_REGS));
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void sub_a_imm8(unsigned char opcode, unsigned char imm8)
{
    struct ByteALUResult res = overflowingSubByte(A_VAL, imm8);
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void sbc_a_imm8(unsigned char opcode, unsigned char imm8) {
    struct ByteALUResult res = overflowingSubByte(A_VAL, imm8 + getCFlag(CPU_REGS));
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}

// 8 bit logic
void and_a_r8(unsigned char opcode, unsigned char* r8) {
    struct ByteALUResult res = andByte(A_VAL, *r8);
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void xor_a_r8(unsigned char opcode, unsigned char* r8) {
    struct ByteALUResult res = xorByte(A_VAL, *r8);
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void or_a_r8(unsigned char opcode, unsigned char* r8) {
    struct ByteALUResult res = orByte(A_VAL, *r8);
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void cp_a_r8(unsigned char opcode, unsigned char* r8) {
    struct ByteALUResult res = overflowingSubByte(A_VAL, *r8);
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void and_a_imm8(unsigned char opcode, unsigned char imm8) {
    struct ByteALUResult res = andByte(A_VAL, imm8);
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void xor_a_imm8(unsigned char opcode, unsigned char imm8) {
    struct ByteALUResult res = xorByte(A_VAL, imm8);
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void or_a_imm8(unsigned char opcode, unsigned char imm8) {
    struct ByteALUResult res = orByte(A_VAL, imm8);
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void cp_a_imm8(unsigned char opcode, unsigned char imm8) {
    struct ByteALUResult res = overflowingSubByte(A_VAL, imm8);
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}

// [HL] specific
void inc_hlmem(unsigned char opcode) {
    struct ByteALUResult res = overflowingAddByte(getMemByte(HL_VAL), (char) 0x01);
    setMemByte(HL_VAL, res.value);
    setZFlag(CPU_REGS, res.z);
    setNFlag(CPU_REGS, 0);
    setHFlag(CPU_REGS, res.h);
}
void dec_hlmem(unsigned char opcode) {
    struct ByteALUResult res = overflowingSubByte(getMemByte(HL_VAL), (char) 0x01);
    setMemByte(HL_VAL, res.value);
    setZFlag(CPU_REGS, res.z);
    setNFlag(CPU_REGS, 0);
    setHFlag(CPU_REGS, res.h);
}
void add_a_hlmem(unsigned char opcode)
{
    struct ByteALUResult res = overflowingAddByte(A_VAL, getMemByte(HL_VAL));
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void adc_a_hlmem(unsigned char opcode)
{
    struct ByteALUResult res = overflowingAddByte(A_VAL, getMemByte(HL_VAL) + getCFlag(CPU_REGS));
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void sub_a_hlmem(unsigned char opcode)
{
    struct ByteALUResult res = overflowingSubByte(A_VAL, getMemByte(HL_VAL));
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void sbc_a_hlmem(unsigned char opcode)
{
    struct ByteALUResult res = overflowingSubByte(A_VAL, getMemByte(HL_VAL) + getCFlag(CPU_REGS));
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void and_a_hlmem(unsigned char opcode) {
    struct ByteALUResult res = andByte(A_VAL, getMemByte(HL_VAL));
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void xor_a_hlmem(unsigned char opcode) {
    struct ByteALUResult res = xorByte(A_VAL, getMemByte(HL_VAL));
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void or_a_hlmem(unsigned char opcode) {
    struct ByteALUResult res = orByte(A_VAL, getMemByte(HL_VAL));
    A_REG = res.value;
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}
void cp_a_hlmem(unsigned char opcode) {
    struct ByteALUResult res = overflowingSubByte(A_VAL, getMemByte(HL_VAL));
    setZNHCFlags(CPU_REGS, res.z, res.n, res.h, res.c);
}


// Other
void daa(unsigned char opcode) {
    char adjustment = 0x00;
    if (getNFlag(CPU_REGS)) {
        if (getHFlag(CPU_REGS)) { adjustment += 0x06; }
        if (getCFlag(CPU_REGS)) { adjustment += 0x60; }
        A_REG -= adjustment;
    } else {
        if (getHFlag(CPU_REGS) || ((A_VAL & 0x0F) > 0x09)) { adjustment += 0x06; }
        if (getCFlag(CPU_REGS) || (A_VAL > 0x99)) {
            adjustment += 0x60;
            setCFlag(CPU_REGS, 1);
        }
        A_REG += adjustment;
    }
}
void cpl(unsigned char opcode) {
    A_REG = ~A_VAL;
    setNFlag(CPU_REGS, 1);
    setHFlag(CPU_REGS, 1);
}
void scf(unsigned char opcode) {
    setNFlag(CPU_REGS, 0);
    setHFlag(CPU_REGS, 0);
    setCFlag(CPU_REGS, 1);
}
void ccf(unsigned char opcode) {
    setNFlag(CPU_REGS, 0);
    setHFlag(CPU_REGS, 0);
    setCFlag(CPU_REGS, !getCFlag(CPU_REGS));
}

