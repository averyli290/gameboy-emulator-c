#include "Memory.h"
#include "Registers.h"

unsigned char mem[0x10000];

void setMemByte(unsigned short address, unsigned char value) { mem[address] = value; }
unsigned char getMemByte(unsigned short address) { return mem[address]; }

void loadROM(const char* path) {

    FILE *fileptr = fopen(path, "rb");
    fseek(fileptr, 0, SEEK_END);
    long filelen = ftell(fileptr);
    rewind(fileptr);

    if (filelen != 0x8000) {
        printf("File is not of size 0x8000 bytes, cannot read.\n");
        return;
    }
    fread(mem, sizeof(unsigned char), filelen / sizeof(unsigned char), fileptr);

}
