#include "Memory.h"
#include "Registers.h"

unsigned char mem[0x10000];

void setMemByte(unsigned short address, unsigned char value) { mem[address] = value; }
char getMemByte(unsigned short address) { return mem[address]; }
// unsigned char* getTrueAddr(unsigned short address) { return mem + address; }
// unsigned char* getHLAddr() { return mem + registers.hl; }