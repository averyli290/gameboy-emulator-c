#include <stdio.h>
#include "CPU.h"
#include "Registers.h"

int main()
{
    struct CPU cpu;
    zeroRegisters(&cpu.registers);
    printf("CPU.a: 0x%02X\n", cpu.registers.a);
    // ld_a_nn(&cpu.registers, 0x1234);
    printf("CPU.a: 0x%02X\n", cpu.registers.a);
}