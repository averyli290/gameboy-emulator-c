#include "Registers.h"
#include <stdbool.h>

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
