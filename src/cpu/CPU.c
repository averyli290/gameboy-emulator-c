
#include "CPU.h"
#include "Registers.h"
#include "Load.h"

struct Registers registers;
struct CPU cpu = {&registers};

unsigned char nextToken() {
    return 0x10;
}
unsigned short nextTwoToken() {
    return 0x0100;
}
void fetch() {
    // Fetch instruction using program counter...
}
void decode() {}
void execute(unsigned char opcode)
{
    // opcode = getopcode...
    switch (opcode)
    {
        case 0x00: nop(opcode); break;
        case 0x01: ld_r16_imm16(opcode, BC_PTR, nextTwoToken()); break;
        case 0x02: ld_r16mem_a(opcode, BC_VAL); break;
        case 0x03: break;
        case 0x04: break;
        case 0x05: break;
        case 0x06: ld_r8_imm8(opcode, B_PTR, nextToken()); break;
        case 0x07: break;
        case 0x08: ld_imm16mem_sp(opcode, nextTwoToken()); break;
        case 0x09: break;
        case 0x0A: ld_a_r16mem(opcode, BC_VAL); break;
        case 0x0B: break;
        case 0x0C: break;
        case 0x0D: break;
        case 0x0E: ld_r8_imm8(opcode, C_PTR, nextToken()); break;
        case 0x0F: break;

        case 0x10: break;
        case 0x11: ld_r16_imm16(opcode, DE_PTR, nextTwoToken()); break;
        case 0x12: ld_r16mem_a(opcode, DE_VAL); break;
        case 0x13: break;
        case 0x14: break;
        case 0x15: break;
        case 0x16: ld_r8_imm8(opcode, D_PTR, nextToken()); break;
        case 0x17: break;
        case 0x18: break;
        case 0x19: break;
        case 0x1A: ld_a_r16mem(opcode, DE_VAL); break;
        case 0x1B: break;
        case 0x1C: break;
        case 0x1D: break;
        case 0x1E: ld_r8_imm8(opcode, E_PTR, nextToken()); break;
        case 0x1F: break;

        case 0x20: break;
        case 0x21: ld_r16_imm16(opcode, HL_PTR, nextTwoToken()); break;
        case 0x22: ld_hlmem_i_a(opcode); break;
        case 0x23: break;
        case 0x24: break;
        case 0x25: break;
        case 0x26: ld_r8_imm8(opcode, H_PTR, nextToken()); break;
        case 0x27: break;
        case 0x28: break;
        case 0x29: break;
        case 0x2A: ld_a_hlmem_i(opcode); break;
        case 0x2B: break;
        case 0x2C: break;
        case 0x2D: break;
        case 0x2E: ld_r8_imm8(opcode, L_PTR, nextToken()); break;
        case 0x2F: break;

        case 0x30: break;
        case 0x31: ld_r16_imm16(opcode, SP_PTR, nextTwoToken()); break;
        case 0x32: ld_hlmem_d_a(opcode); break;
        case 0x33: break;
        case 0x34: break;
        case 0x35: break;
        case 0x36: ld_hlmem_imm8(opcode, nextToken());
        case 0x37: break;
        case 0x38: break;
        case 0x39: break;
        case 0x3A: ld_a_hlmem_i(opcode); break;
        case 0x3B: break;
        case 0x3C: break;
        case 0x3D: break;
        case 0x3E: ld_r8_imm8(opcode, A_PTR, nextToken()); break;
        case 0x3F: break;

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

        case 0x80: break;
        case 0x81: break;
        case 0x82: break;
        case 0x83: break;
        case 0x84: break;
        case 0x85: break;
        case 0x86: break;
        case 0x87: break;
        case 0x88: break;
        case 0x89: break;
        case 0x8A: break;
        case 0x8B: break;
        case 0x8C: break;
        case 0x8D: break;
        case 0x8E: break;
        case 0x8F: break;        

        case 0x90: break;
        case 0x91: break;
        case 0x92: break;
        case 0x93: break;
        case 0x94: break;
        case 0x95: break;
        case 0x96: break;
        case 0x97: break;
        case 0x98: break;
        case 0x99: break;
        case 0x9A: break;
        case 0x9B: break;
        case 0x9C: break;
        case 0x9D: break;
        case 0x9E: break;
        case 0x9F: break;        

        case 0xA0: break;
        case 0xA1: break;
        case 0xA2: break;
        case 0xA3: break;
        case 0xA4: break;
        case 0xA5: break;
        case 0xA6: break;
        case 0xA7: break;
        case 0xA8: break;
        case 0xA9: break;
        case 0xAA: break;
        case 0xAB: break;
        case 0xAC: break;
        case 0xAD: break;
        case 0xAE: break;
        case 0xAF: break;        

        case 0xB0: break;
        case 0xB1: break;
        case 0xB2: break;
        case 0xB3: break;
        case 0xB4: break;
        case 0xB5: break;
        case 0xB6: break;
        case 0xB7: break;
        case 0xB8: break;
        case 0xB9: break;
        case 0xBA: break;
        case 0xBB: break;
        case 0xBC: break;
        case 0xBD: break;
        case 0xBE: break;
        case 0xBF: break;        

        case 0xC0: break;
        case 0xC1: break;
        case 0xC2: break;
        case 0xC3: break;
        case 0xC4: break;
        case 0xC5: break;
        case 0xC6: break;
        case 0xC7: break;
        case 0xC8: break;
        case 0xC9: break;
        case 0xCA: break;
        case 0xCB: break;
        case 0xCC: break;
        case 0xCD: break;
        case 0xCE: break;
        case 0xCF: break;        

        case 0xD0: break;
        case 0xD1: break;
        case 0xD2: break;
        case 0xD3: break;
        case 0xD4: break;
        case 0xD5: break;
        case 0xD6: break;
        case 0xD7: break;
        case 0xD8: break;
        case 0xD9: break;
        case 0xDA: break;
        case 0xDB: break;
        case 0xDC: break;
        case 0xDD: break;
        case 0xDE: break;
        case 0xDF: break;        

        case 0xE0: ldh_imm8mem_a(opcode, nextToken()); break;
        case 0xE1: break;
        case 0xE2: ldh_cmem_a(opcode); break;
        case 0xE3: break;
        case 0xE4: break;
        case 0xE5: break;
        case 0xE6: break;
        case 0xE7: break;
        case 0xE8: break;
        case 0xE9: break;
        case 0xEA: ld_imm16mem_a(opcode, nextTwoToken()); break;
        case 0xEB: break;
        case 0xEC: break;
        case 0xED: break;
        case 0xEE: break;
        case 0xEF: break;        

        case 0xF0: ldh_a_imm8mem(opcode, nextToken()); break;
        case 0xF1: break;
        case 0xF2: ldh_a_cmem(opcode); break;
        case 0xF3: break;
        case 0xF4: break;
        case 0xF5: break;
        case 0xF6: break;
        case 0xF7: break;
        case 0xF8: break;
        case 0xF9: break;
        case 0xFA: ld_a_imm16mem(opcode, nextTwoToken()); break;
        case 0xFB: break;
        case 0xFC: break;
        case 0xFD: break;
        case 0xFE: break;
        case 0xFF: break;        


    default: break;
    }
}