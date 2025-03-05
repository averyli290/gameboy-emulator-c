/*
Registers does not have a global; they should never be accessible outside of the CPU.
*/

#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdbool.h>

#define Z_FLAG_POS 7
#define N_FLAG_POS 6 
#define H_FLAG_POS 5
#define C_FLAG_POS 4

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
bool getZFlag(struct Registers* registers);
bool getNFlag(struct Registers* registers);
bool getHFlag(struct Registers* registers);
bool getCFlag(struct Registers* registers);
void setZNHCFlags(struct Registers* registers, bool z, bool n, bool h, bool c);

void printRegisters(struct Registers* registers);

// unsigned char *getPointer_r8(unsigned char placeholder);
// unsigned char *getPointer_r16(unsigned char placeholder);
// unsigned char *getPointer_r16stk(unsigned char placeholder);
// unsigned char *getPointer_r16mem(unsigned char placeholder);
// unsigned char *getPointer_cond(unsigned char placeholder);



#endif