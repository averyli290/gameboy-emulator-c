#include <stdio.h>
#include "CPU.h"
#include "Registers.h"
#include "Memory.h"
#include "ALU.h"
#include "ArithmeticUtils.h"

int main()
{
    // struct CPU cpu;
    // zeroRegisters(registers);

    // unsigned short addr = 0x0000;
    // ld_r8_imm8(0b00000110, &registers.b, 0x05);
    // printf("CPU.a: 0x%02X\n", registers.a);
    // printf("CPU.b: 0x%02X\n", registers.b);
    // printf("Memory : 0x%04X\n", mem[addr]);

    // ld_r8_r8(0b00000110, &registers.a, &registers.b);

    // ld_imm16mem_a(0x00, addr);
    // printf("CPU.a: 0x%02X\n", registers.a);
    // printf("CPU.b: 0x%02X\n", registers.b);
    // printf("Memory : 0x%04X\n", mem[addr]);

    // // LD [HL],r8      ld_r8_r8 example
    // //
    // registers.hl = 0x011F;
    // printf("CPU.h: 0x%02X\n", registers.h);
    // printf("CPU.l: 0x%02X\n", registers.l);
    // ld_r8_r8(0x00, mem + registers.hl, &registers.a);
    // printf("Memory.l: 0x%04X\n", mem[registers.hl]);

    // zeroRegisters(registers);
    // execute(0x01);
    // *A_PTR = 0x02;
    // printRegisters();
    // *A_PTR = 0x08;
    // printf("A_VAL: 0x%02X\n", A_VAL);
    // printRegisters();

    
    // unsigned char b1 = 0xCC;
    // unsigned char b2 = 0x43;
    // struct ByteALUResult res = overflowingAddByte(b1, b2);
    // printf("0x%02X + 0x%02X = 0x%02X\n", b1, b2, res.value);
    // printf("Z: %d, N: %d, H: %d, C: %d\n", res.z, res.n, res.h, res.c);

    cpu.registers->a = 0x12;
    cpu.registers->b = 0x02;
    setCFlag(cpu.registers, 1);
    adc_a_r8(0x00, B_PTR);
    printf("cpu.registers->a: 0x%02X\n", cpu.registers->a);



}