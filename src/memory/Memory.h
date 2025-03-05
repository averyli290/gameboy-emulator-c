#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>

extern unsigned char mem[];

void setMemByte(unsigned short address, unsigned char value);
unsigned char getMemByte(unsigned short address);

void loadROM(const char* path);

#endif