#ifndef INSTRUCTION_H
#define INSTRUCTION_H

enum InstructionType {
    ADD
};

struct Instruction
{
    InstructionType type;
    unsigned char operandLength;
    void *execute;
};

#endif