/*
Registers does not have a global; they should never be accessible outside of the CPU.
*/

#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdbool.h>

struct Registers
{
    union
    {
        struct
        {
            unsigned char f;
            unsigned char a;
        };
        unsigned short af;
    };
    union
    {
        struct
        {
            unsigned char c;
            unsigned char b;
        };
        unsigned short bc;
    };
    union
    {
        struct
        {
            unsigned char e;
            unsigned char d;
        };
        unsigned short de;
    };
    union
    {
        struct
        {
            unsigned char l;
            unsigned char h;
        };
        unsigned short hl;
    };
    unsigned short sp;
    unsigned short pc;
};

// extern struct Registers registers;

void zeroRegisters(struct Registers* registers);
void setZFlag(struct Registers* registers, bool value);
void setNFlag(struct Registers* registers, bool value);
void setHFlag(struct Registers* registers, bool value);
void setCFlag(struct Registers* registers, bool value);

void printRegisters(struct Registers* registers);

// unsigned char *getPointer_r8(unsigned char placeholder);
// unsigned char *getPointer_r16(unsigned char placeholder);
// unsigned char *getPointer_r16stk(unsigned char placeholder);
// unsigned char *getPointer_r16mem(unsigned char placeholder);
// unsigned char *getPointer_cond(unsigned char placeholder);



#endif