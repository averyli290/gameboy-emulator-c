#include "Registers.h"
#include <stdbool.h>

void zeroRegisters(struct Registers *registers)
{
    registers->af = 0x0000;
    registers->bc = 0x0000;
    registers->de = 0x0000;
    registers->hl = 0x0000;
    registers->sp = 0x0000;
    registers->pc = 0x0000;
}

void setZFlag(struct Registers *registers, bool value)
{
    registers->f &= value << 7;
}

void setNFlag(struct Registers *registers, bool value)
{
    registers->f &= value << 6;
}

void setHFlag(struct Registers *registers, bool value)
{
    registers->f &= value << 5;
}

void setCFlag(struct Registers *registers, bool value)
{
    registers->f &= value << 4;
}
