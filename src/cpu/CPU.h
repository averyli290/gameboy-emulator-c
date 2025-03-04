#ifndef CPU_H
#define CPU_H

#include "Registers.h"
#include "Load.h"

struct CPU
{
    struct Registers *registers;
};

extern struct CPU cpu;

void fetch(struct CPU *cpu);
void decode(struct CPU *cpu);
void execute(struct CPU *cpu);

#endif