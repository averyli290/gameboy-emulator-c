#include <stdio.h>
#include "CPU.h"
#include "Registers.h"

int main()
{
    // struct CPU cpu;
    zeroRegisters(registers);
    printf("CPU.a: 0x%02X\n", cpu.registers->a);
    // ld_a_nn(&cpu.registers, 0x1234);

    ld_r8_imm8(0x00, &registers.a, 0x1F);

    printf("CPU.a: 0x%02X\n", cpu.registers->a);
    ld_r8_imm8(0x00, &registers.a, 0xFF);
    printf("CPU.a: 0x%02X\n", cpu.registers->a);
}