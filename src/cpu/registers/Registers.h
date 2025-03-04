#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdbool.h>

struct Registers
{
    union
    {
        struct
        {
            unsigned char a;
            unsigned char f;
        };
        unsigned short af;
    };
    union
    {
        struct
        {
            unsigned char b;
            unsigned char c;
        };
        unsigned short bc;
    };
    union
    {
        struct
        {
            unsigned char d;
            unsigned char e;
        };
        unsigned short de;
    };
    union
    {
        struct
        {
            unsigned char h;
            unsigned char l;
        };
        unsigned short hl;
    };
    unsigned short sp;
    unsigned short pc;
};

extern struct Registers registers;

void zeroRegisters();
void setZFlag(bool value);
void setNFlag(bool value);
void setHFlag(bool value);
void setCFlag(bool value);

unsigned char *getPointer_r8(unsigned char placeholder);
unsigned char *getPointer_r16(unsigned char placeholder);
unsigned char *getPointer_r16stk(unsigned char placeholder);
unsigned char *getPointer_r16mem(unsigned char placeholder);
unsigned char *getPointer_cond(unsigned char placeholder);

// char getA(struct Registers *registers);
// char getB(struct Registers *registers);
// char getC(struct Registers *registers);
// char getD(struct Registers *registers);
// char getE(struct Registers *registers);
// char getF(struct Registers *registers);
// char getH(struct Registers *registers);
// char getL(struct Registers *registers);
// short getAF(struct Registers *registers);
// short getBC(struct Registers *registers);
// short getDE(struct Registers *registers);
// short getHL(struct Registers *registers);

#endif