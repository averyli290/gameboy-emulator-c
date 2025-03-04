#ifndef MEMORY_H
#define MEMORY_H

extern unsigned char mem[];

void setMemByte(unsigned short address, unsigned char value);
char getMemByte(unsigned short address);
// unsigned char* getTrueAddr(unsigned short address);
// unsigned char* getHLAddr();

#endif