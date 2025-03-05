/*
Only one CPU exists (extern), perhaps abstract to more later?
*/

#ifndef CPU_H
#define CPU_H

#include "Registers.h"
#include "Load.h"
#include "Bus.h"

struct CPU
{
    struct Registers *registers;
    unsigned char instruction;
};

extern struct CPU cpu;

// Helper macros
#define CPU_REGS cpu.registers

// X_REG used to assigning values to registers
#define A_REG cpu.registers->a
#define B_REG cpu.registers->b
#define C_REG cpu.registers->c
#define D_REG cpu.registers->d
#define E_REG cpu.registers->e
#define F_REG cpu.registers->f
#define H_REG cpu.registers->h
#define L_REG cpu.registers->l
#define AF_REG cpu.registers->af
#define BC_REG cpu.registers->bc
#define DE_REG cpu.registers->de
#define HL_REG cpu.registers->hl
#define SP_REG cpu.registers->sp
#define PC_REG cpu.registers->pc

// X_VAL used for accessing values of registers
#define A_PTR &(cpu.registers->a)
#define A_VAL cpu.registers->a
#define B_PTR &(cpu.registers->b)
#define B_VAL cpu.registers->b
#define C_PTR &(cpu.registers->c)
#define C_VAL cpu.registers->c
#define D_PTR &(cpu.registers->d)
#define D_VAL cpu.registers->d
#define E_PTR &(cpu.registers->e)
#define E_VAL cpu.registers->e
#define F_PTR &(cpu.registers->f)
#define F_VAL cpu.registers->f
#define H_PTR &(cpu.registers->h)
#define H_VAL cpu.registers->h
#define L_PTR &(cpu.registers->l)
#define L_VAL cpu.registers->l

#define AF_PTR &(cpu.registers->af)
#define AF_VAL cpu.registers->af
#define BC_PTR &(cpu.registers->bc)
#define BC_VAL cpu.registers->bc
#define DE_PTR &(cpu.registers->de)
#define DE_VAL cpu.registers->de
#define HL_PTR &(cpu.registers->hl)
#define HL_VAL cpu.registers->hl
#define SP_PTR &(cpu.registers->sp)
#define SP_VAL cpu.registers->sp
#define PC_PTR &(cpu.registers->pc)
#define PC_VAL cpu.registers->pc

unsigned char readByte();
unsigned short readShort();
void fetch();
void decode();
void execute();


#endif