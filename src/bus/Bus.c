/*
8-bit bus used for decoupling components reading and writing.
*/

#include "Bus.h"

void setAddress(struct Bus* bus, unsigned short address)
{
    bus->currentAddress = address;
}

void writeByte(struct Bus* bus, char value)
{
    bus->memory[bus->currentAddress] = value;
}

unsigned char readByte(struct Bus* bus)
{
    return bus->memory[bus->currentAddress];
}