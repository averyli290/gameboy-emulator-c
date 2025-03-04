#include "Registers.h"

#include <stdbool.h>
#include <stdio.h>

void zeroRegisters()
{
    registers.af = 0x0000;
    registers.bc = 0x0000;
    registers.de = 0x0000;
    registers.hl = 0x0000;
    registers.sp = 0x0000;
    registers.pc = 0x0000;
}

void setZFlag(bool value)
{
    registers.f &= value << 7;
}

void setNFlag(bool value)
{
    registers.f &= value << 6;
}

void setHFlag(bool value)
{
    registers.f &= value << 5;
}

void setCFlag(bool value)
{
    registers.f &= value << 4;
}

void printRegisters() {
    printf("A: 0x%02X, F: 0x%02X\n", registers.a, registers.f);
    printf("B: 0x%02X, C: 0x%02X\n", registers.b, registers.c);
    printf("D: 0x%02X, E: 0x%02X\n", registers.d, registers.e);
    printf("H: 0x%02X, L: 0x%02X\n", registers.h, registers.l);
}