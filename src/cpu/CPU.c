
#include "CPU.h"
#include "Registers.h"
#include "Load.h"
#include "ALU.h"

struct Registers registers;
struct CPU cpu = {&registers};

unsigned char readByte() {
    const unsigned char value = getMemByte(cpu.registers->pc);
    cpu.registers->pc++;
    return value;
}
unsigned short readShort() {
    const unsigned short value = getMemByte(cpu.registers->pc) | (getMemByte(cpu.registers->pc + 1) << 8);
    cpu.registers->pc += 2;
    return value;
}
void fetch() {
    cpu.instruction = readByte();
    printf("0x%02X ", cpu.instruction);
}
void decode() {}
void execute()
{
    // opcode = getopcode...
    unsigned char opcode = cpu.instruction;
    switch (opcode)
    {
        case 0x00: nop(opcode); break;
        case 0x01: ld_r16_imm16(opcode, BC_PTR, readShort()); break;
        case 0x02: ld_r16mem_a(opcode, BC_VAL); break;
        case 0x03: inc_r16(opcode, BC_PTR); break;
        case 0x04: inc_r8(opcode, B_PTR); break;
        case 0x05: dec_r8(opcode, B_PTR); break;
        case 0x06: ld_r8_imm8(opcode, B_PTR, readByte()); break;
        case 0x07: break;
        case 0x08: ld_imm16mem_sp(opcode, readShort()); break;
        case 0x09: add_hl_r16(opcode, BC_PTR); break;
        case 0x0A: ld_a_r16mem(opcode, BC_VAL); break;
        case 0x0B: dec_r16(opcode, BC_PTR); break;
        case 0x0C: inc_r8(opcode, C_PTR); break;
        case 0x0D: dec_r8(opcode, C_PTR); break;
        case 0x0E: ld_r8_imm8(opcode, C_PTR, readByte()); break;
        case 0x0F: break;

        case 0x10: break;
        case 0x11: ld_r16_imm16(opcode, DE_PTR, readShort()); break;
        case 0x12: ld_r16mem_a(opcode, DE_VAL); break;
        case 0x13: inc_r16(opcode, DE_PTR); break;
        case 0x14: inc_r8(opcode, D_PTR); break;
        case 0x15: dec_r8(opcode, D_PTR); break;
        case 0x16: ld_r8_imm8(opcode, D_PTR, readByte()); break;
        case 0x17: break;
        case 0x18: break;
        case 0x19: add_hl_r16(opcode, DE_PTR); break;
        case 0x1A: ld_a_r16mem(opcode, DE_VAL); break;
        case 0x1B: dec_r16(opcode, DE_PTR); break;
        case 0x1C: inc_r8(opcode, E_PTR); break;
        case 0x1D: dec_r8(opcode, E_PTR); break;
        case 0x1E: ld_r8_imm8(opcode, E_PTR, readByte()); break;
        case 0x1F: break;

        case 0x20: break;
        case 0x21: ld_r16_imm16(opcode, HL_PTR, readShort()); break;
        case 0x22: ld_hlmem_i_a(opcode); break;
        case 0x23: inc_r16(opcode, HL_PTR); break;
        case 0x24: inc_r8(opcode, H_PTR); break;
        case 0x25: dec_r8(opcode, H_PTR); break;
        case 0x26: ld_r8_imm8(opcode, H_PTR, readByte()); break;
        case 0x27: daa(opcode); break;
        case 0x28: break;
        case 0x29: add_hl_r16(opcode, HL_PTR); break;
        case 0x2A: ld_a_hlmem_i(opcode); break;
        case 0x2B: dec_r16(opcode, HL_PTR); break;
        case 0x2C: inc_r8(opcode, L_PTR); break;
        case 0x2D: dec_r8(opcode, L_PTR); break;
        case 0x2E: ld_r8_imm8(opcode, L_PTR, readByte()); break;
        case 0x2F: cpl(opcode); break;

        case 0x30: break;
        case 0x31: ld_r16_imm16(opcode, SP_PTR, readShort()); break;
        case 0x32: ld_hlmem_d_a(opcode); break;
        case 0x33: inc_r16(opcode, SP_PTR); break;
        case 0x34: inc_hlmem(opcode); break;
        case 0x35: dec_hlmem(opcode); break;
        case 0x36: ld_hlmem_imm8(opcode, readByte());
        case 0x37: scf(opcode); break;
        case 0x38: break;
        case 0x39: add_hl_r16(opcode, SP_PTR); break;
        case 0x3A: ld_a_hlmem_i(opcode); break;
        case 0x3B: dec_r16(opcode, SP_PTR); break;
        case 0x3C: inc_r8(opcode, A_PTR); break;
        case 0x3D: dec_r8(opcode, A_PTR); break;
        case 0x3E: ld_r8_imm8(opcode, A_PTR, readByte()); break;
        case 0x3F: ccf(opcode); break;

        case 0x40: ld_r8_r8(opcode, B_PTR, B_PTR); break;
        case 0x41: ld_r8_r8(opcode, B_PTR, C_PTR); break;
        case 0x42: ld_r8_r8(opcode, B_PTR, D_PTR); break;
        case 0x43: ld_r8_r8(opcode, B_PTR, E_PTR); break;
        case 0x44: ld_r8_r8(opcode, B_PTR, H_PTR); break;
        case 0x45: ld_r8_r8(opcode, B_PTR, L_PTR); break;
        case 0x46: ld_r8_hlmem(opcode, B_PTR); break;
        case 0x47: ld_r8_r8(opcode, B_PTR, A_PTR); break;
        case 0x48: ld_r8_r8(opcode, C_PTR, B_PTR); break;
        case 0x49: ld_r8_r8(opcode, C_PTR, C_PTR); break;
        case 0x4A: ld_r8_r8(opcode, C_PTR, D_PTR); break;
        case 0x4B: ld_r8_r8(opcode, C_PTR, E_PTR); break;
        case 0x4C: ld_r8_r8(opcode, C_PTR, H_PTR); break;
        case 0x4D: ld_r8_r8(opcode, C_PTR, L_PTR); break;
        case 0x4E: ld_r8_hlmem(opcode, C_PTR); break;
        case 0x4F: ld_r8_r8(opcode, C_PTR, A_PTR); break;

        case 0x50: ld_r8_r8(opcode, D_PTR, B_PTR); break;
        case 0x51: ld_r8_r8(opcode, D_PTR, C_PTR); break;
        case 0x52: ld_r8_r8(opcode, D_PTR, D_PTR); break;
        case 0x53: ld_r8_r8(opcode, D_PTR, E_PTR); break;
        case 0x54: ld_r8_r8(opcode, D_PTR, H_PTR); break;
        case 0x55: ld_r8_r8(opcode, D_PTR, L_PTR); break;
        case 0x56: ld_r8_hlmem(opcode, D_PTR); break;
        case 0x57: ld_r8_r8(opcode, D_PTR, A_PTR); break;
        case 0x58: ld_r8_r8(opcode, E_PTR, B_PTR); break;
        case 0x59: ld_r8_r8(opcode, E_PTR, C_PTR); break;
        case 0x5A: ld_r8_r8(opcode, E_PTR, D_PTR); break;
        case 0x5B: ld_r8_r8(opcode, E_PTR, E_PTR); break;
        case 0x5C: ld_r8_r8(opcode, E_PTR, H_PTR); break;
        case 0x5D: ld_r8_r8(opcode, E_PTR, L_PTR); break;
        case 0x5E: ld_r8_hlmem(opcode, E_PTR); break;
        case 0x5F: ld_r8_r8(opcode, E_PTR, A_PTR); break;

        case 0x60: ld_r8_r8(opcode, H_PTR, B_PTR); break;
        case 0x61: ld_r8_r8(opcode, H_PTR, C_PTR); break;
        case 0x62: ld_r8_r8(opcode, H_PTR, D_PTR); break;
        case 0x63: ld_r8_r8(opcode, H_PTR, E_PTR); break;
        case 0x64: ld_r8_r8(opcode, H_PTR, H_PTR); break;
        case 0x65: ld_r8_r8(opcode, H_PTR, L_PTR); break;
        case 0x66: ld_r8_hlmem(opcode, H_PTR); break;
        case 0x67: ld_r8_r8(opcode, H_PTR, A_PTR); break;
        case 0x68: ld_r8_r8(opcode, L_PTR, B_PTR); break;
        case 0x69: ld_r8_r8(opcode, L_PTR, C_PTR); break;
        case 0x6A: ld_r8_r8(opcode, L_PTR, D_PTR); break;
        case 0x6B: ld_r8_r8(opcode, L_PTR, E_PTR); break;
        case 0x6C: ld_r8_r8(opcode, L_PTR, H_PTR); break;
        case 0x6D: ld_r8_r8(opcode, L_PTR, L_PTR); break;
        case 0x6E: ld_r8_hlmem(opcode, L_PTR); break;
        case 0x6F: ld_r8_r8(opcode, L_PTR, A_PTR); break;

        case 0x70: ld_hlmem_r8(opcode, B_PTR); break;
        case 0x71: ld_hlmem_r8(opcode, C_PTR); break;
        case 0x72: ld_hlmem_r8(opcode, D_PTR); break;
        case 0x73: ld_hlmem_r8(opcode, E_PTR); break;
        case 0x74: ld_hlmem_r8(opcode, H_PTR); break;
        case 0x75: ld_hlmem_r8(opcode, L_PTR); break;
        case 0x76: break;
        case 0x77: ld_hlmem_r8(opcode, A_PTR); break;
        case 0x78: ld_r8_r8(opcode, A_PTR, B_PTR); break;
        case 0x79: ld_r8_r8(opcode, A_PTR, C_PTR); break;
        case 0x7A: ld_r8_r8(opcode, A_PTR, D_PTR); break;
        case 0x7B: ld_r8_r8(opcode, A_PTR, E_PTR); break;
        case 0x7C: ld_r8_r8(opcode, A_PTR, H_PTR); break;
        case 0x7D: ld_r8_r8(opcode, A_PTR, L_PTR); break;
        case 0x7E: ld_r8_hlmem(opcode, A_PTR); break;
        case 0x7F: ld_r8_r8(opcode, A_PTR, A_PTR); break;        

        case 0x80: add_a_r8(opcode, B_PTR); break;
        case 0x81: add_a_r8(opcode, C_PTR); break;
        case 0x82: add_a_r8(opcode, D_PTR); break;
        case 0x83: add_a_r8(opcode, E_PTR); break;
        case 0x84: add_a_r8(opcode, H_PTR); break;
        case 0x85: add_a_r8(opcode, L_PTR); break;
        case 0x86: add_a_hlmem(opcode); break;
        case 0x87: add_a_r8(opcode, A_PTR); break;
        case 0x88: adc_a_r8(opcode, B_PTR); break;
        case 0x89: adc_a_r8(opcode, C_PTR); break;
        case 0x8A: adc_a_r8(opcode, D_PTR); break;
        case 0x8B: adc_a_r8(opcode, E_PTR); break;
        case 0x8C: adc_a_r8(opcode, H_PTR); break;
        case 0x8D: adc_a_r8(opcode, L_PTR); break;
        case 0x8E: adc_a_hlmem(opcode); break;
        case 0x8F: adc_a_r8(opcode, A_PTR); break;

        case 0x90: sub_a_r8(opcode, B_PTR); break;
        case 0x91: sub_a_r8(opcode, C_PTR); break;
        case 0x92: sub_a_r8(opcode, D_PTR); break;
        case 0x93: sub_a_r8(opcode, E_PTR); break;
        case 0x94: sub_a_r8(opcode, H_PTR); break;
        case 0x95: sub_a_r8(opcode, L_PTR); break;
        case 0x96: sub_a_hlmem(opcode); break;
        case 0x97: sub_a_r8(opcode, A_PTR); break;
        case 0x98: sbc_a_r8(opcode, B_PTR); break;
        case 0x99: sbc_a_r8(opcode, C_PTR); break;
        case 0x9A: sbc_a_r8(opcode, D_PTR); break;
        case 0x9B: sbc_a_r8(opcode, E_PTR); break;
        case 0x9C: sbc_a_r8(opcode, H_PTR); break;
        case 0x9D: sbc_a_r8(opcode, L_PTR); break;
        case 0x9E: sbc_a_hlmem(opcode); break;
        case 0x9F: sbc_a_r8(opcode, A_PTR); break;

        case 0xA0: and_a_r8(opcode, B_PTR); break;
        case 0xA1: and_a_r8(opcode, C_PTR); break;
        case 0xA2: and_a_r8(opcode, D_PTR); break;
        case 0xA3: and_a_r8(opcode, E_PTR); break;
        case 0xA4: and_a_r8(opcode, H_PTR); break;
        case 0xA5: and_a_r8(opcode, L_PTR); break;
        case 0xA6: and_a_hlmem(opcode); break;
        case 0xA7: and_a_r8(opcode, A_PTR); break;
        case 0xA8: xor_a_r8(opcode, B_PTR); break;
        case 0xA9: xor_a_r8(opcode, C_PTR); break;
        case 0xAA: xor_a_r8(opcode, D_PTR); break;
        case 0xAB: xor_a_r8(opcode, E_PTR); break;
        case 0xAC: xor_a_r8(opcode, H_PTR); break;
        case 0xAD: xor_a_r8(opcode, L_PTR); break;
        case 0xAE: xor_a_hlmem(opcode); break;
        case 0xAF: xor_a_r8(opcode, A_PTR); break;

        case 0xB0: or_a_r8(opcode, B_PTR); break;
        case 0xB1: or_a_r8(opcode, C_PTR); break;
        case 0xB2: or_a_r8(opcode, D_PTR); break;
        case 0xB3: or_a_r8(opcode, E_PTR); break;
        case 0xB4: or_a_r8(opcode, H_PTR); break;
        case 0xB5: or_a_r8(opcode, L_PTR); break;
        case 0xB6: or_a_hlmem(opcode); break;
        case 0xB7: or_a_r8(opcode, A_PTR); break;
        case 0xB8: cp_a_r8(opcode, B_PTR); break;
        case 0xB9: cp_a_r8(opcode, C_PTR); break;
        case 0xBA: cp_a_r8(opcode, D_PTR); break;
        case 0xBB: cp_a_r8(opcode, E_PTR); break;
        case 0xBC: cp_a_r8(opcode, H_PTR); break;
        case 0xBD: cp_a_r8(opcode, L_PTR); break;
        case 0xBE: cp_a_hlmem(opcode); break;
        case 0xBF: cp_a_r8(opcode, A_PTR); break;

        case 0xC0: break;
        case 0xC1: break;
        case 0xC2: break;
        case 0xC3: break;
        case 0xC4: break;
        case 0xC5: break;
        case 0xC6: add_a_imm8(opcode, readByte()); break;
        case 0xC7: break;
        case 0xC8: break;
        case 0xC9: break;
        case 0xCA: break;
        case 0xCB: break;
        case 0xCC: break;
        case 0xCD: break;
        case 0xCE: adc_a_imm8(opcode, readByte()); break;
        case 0xCF: break;        

        case 0xD0: break;
        case 0xD1: break;
        case 0xD2: break;
        case 0xD3: break;
        case 0xD4: break;
        case 0xD5: break;
        case 0xD6: sub_a_imm8(opcode, readByte()); break;
        case 0xD7: break;
        case 0xD8: break;
        case 0xD9: break;
        case 0xDA: break;
        case 0xDB: break;
        case 0xDC: break;
        case 0xDD: break;
        case 0xDE: sbc_a_imm8(opcode, readByte()); break;
        case 0xDF: break;        

        case 0xE0: ldh_imm8mem_a(opcode, readByte()); break;
        case 0xE1: break;
        case 0xE2: ldh_cmem_a(opcode); break;
        case 0xE3: break;
        case 0xE4: break;
        case 0xE5: break;
        case 0xE6: and_a_imm8(opcode, readByte()); break;
        case 0xE7: break;
        case 0xE8: break;
        case 0xE9: break;
        case 0xEA: ld_imm16mem_a(opcode, readShort()); break;
        case 0xEB: break;
        case 0xEC: break;
        case 0xED: break;
        case 0xEE: xor_a_imm8(opcode, readByte()); break;
        case 0xEF: break;

        case 0xF0: ldh_a_imm8mem(opcode, readByte()); break;
        case 0xF1: break;
        case 0xF2: ldh_a_cmem(opcode); break;
        case 0xF3: break;
        case 0xF4: break;
        case 0xF5: break;
        case 0xF6: or_a_imm8(opcode, readByte()); break;
        case 0xF7: break;
        case 0xF8: break;
        case 0xF9: break;
        case 0xFA: ld_a_imm16mem(opcode, readShort()); break;
        case 0xFB: break;
        case 0xFC: break;
        case 0xFD: break;
        case 0xFE: cp_a_imm8(opcode, readByte()); break;
        case 0xFF: break;        


    default: break;
    }
}