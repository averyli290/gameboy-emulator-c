/*
8-bit bus used for decoupling components reading and writing.
*/

#ifndef BUS_H
#define BUS_H

struct Bus {
    unsigned short currentAddress;
    unsigned char memory[];
};

void setAddress(struct Bus* bus, unsigned short address);
void writeByte(struct Bus* bus, char value);
unsigned char readByte();

#endif