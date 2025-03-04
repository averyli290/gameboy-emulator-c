#include "Registers.h"

#include <stdbool.h>
#include <stdio.h>

void zeroRegisters(struct Registers* registers)
{
    registers->af = 0x0000;
    registers->bc = 0x0000;
    registers->de = 0x0000;
    registers->hl = 0x0000;
    registers->sp = 0x0000;
    registers->pc = 0x0000;
}

void setZFlag(struct Registers* registers, bool value)
{
    registers->f &= value << 7;
}

void setNFlag(struct Registers* registers, bool value)
{
    registers->f &= value << 6;
}

void setHFlag(struct Registers* registers, bool value)
{
    registers->f &= value << 5;
}

void setCFlag(struct Registers* registers, bool value)
{
    registers->f &= value << 4;
}

void printRegisters(struct Registers* registers) {
    printf("A: 0x%02X, F: 0x%02X\n", registers->a, registers->f);
    printf("B: 0x%02X, C: 0x%02X\n", registers->b, registers->c);
    printf("D: 0x%02X, E: 0x%02X\n", registers->d, registers->e);
    printf("H: 0x%02X, L: 0x%02X\n", registers->h, registers->l);
}