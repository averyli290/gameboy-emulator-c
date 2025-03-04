#ifndef CPU_H
#define CPU_H

#include "Registers.h"
#include "Load.h"

struct CPU
{
    struct Registers *registers;
};

extern struct CPU cpu;

unsigned char nextToken();
unsigned char nextNextToken();
void fetch();
void decode();
void execute(unsigned char opcode);

#endif