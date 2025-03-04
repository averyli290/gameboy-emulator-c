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

extern struct Registers registers;

// Helper macros
#define A_PTR (&registers.a)
#define A_VAL registers.a
#define B_PTR (&registers.b)
#define B_VAL registers.b
#define C_PTR (&registers.c)
#define C_VAL registers.c
#define D_PTR (&registers.d)
#define D_VAL registers.d
#define E_PTR (&registers.e)
#define E_VAL registers.e
#define F_PTR (&registers.f)
#define F_VAL registers.f
#define H_PTR (&registers.h)
#define H_VAL registers.h
#define L_PTR (&registers.l)
#define L_VAL registers.l

#define AF_PTR (&registers.af)
#define AF_VAL registers.af
#define BC_PTR (&registers.bc)
#define BC_VAL registers.bc
#define DE_PTR (&registers.de)
#define DE_VAL registers.de
#define HL_PTR (&registers.hl)
#define HL_VAL registers.hl
#define SP_PTR (&registers.sp)
#define SP_VAL registers.sp
#define PC_PTR (&registers.pc)
#define PC_VAL registers.pc



void zeroRegisters();
void setZFlag(bool value);
void setNFlag(bool value);
void setHFlag(bool value);
void setCFlag(bool value);

void printRegisters();

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