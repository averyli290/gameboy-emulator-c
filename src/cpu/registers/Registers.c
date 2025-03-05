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
    registers->f |= value << Z_FLAG_POS;
}

void setNFlag(struct Registers* registers, bool value)
{
    registers->f |= value << N_FLAG_POS;
}

void setHFlag(struct Registers* registers, bool value)
{
    registers->f |= value << H_FLAG_POS;
}

void setCFlag(struct Registers* registers, bool value)
{
    registers->f |= value << C_FLAG_POS;
}

bool getZFlag(struct Registers* registers)
{
    return (registers->f >> Z_FLAG_POS) & 0b1;
}

bool getNFlag(struct Registers* registers)
{
    return (registers->f >> N_FLAG_POS) & 0b1;
}

bool getHFlag(struct Registers* registers)
{
    return (registers->f >> H_FLAG_POS) & 0b1;
}

bool getCFlag(struct Registers* registers)
{
    return (registers->f >> C_FLAG_POS) & 0b1;
}

void printRegisters(struct Registers* registers) {
    printf("A: 0x%02X, F: 0x%02X\n", registers->a, registers->f);
    printf("B: 0x%02X, C: 0x%02X\n", registers->b, registers->c);
    printf("D: 0x%02X, E: 0x%02X\n", registers->d, registers->e);
    printf("H: 0x%02X, L: 0x%02X\n", registers->h, registers->l);
}

void setZNHCFlags(struct Registers* registers, bool z, bool n, bool h, bool c) {
    registers->f |= z << Z_FLAG_POS;
    registers->f |= n << N_FLAG_POS;
    registers->f |= h << H_FLAG_POS;
    registers->f |= c << C_FLAG_POS;
}