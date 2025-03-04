#include <stdbool.h>

#ifndef ARITHMETIC_UTILS_H
#define ARITHMETIC_UTILS_H

// Custom return types for ALU operations
struct ShortALUResult
{
    unsigned short value;
    bool z;
    bool h;
    bool n;
    bool c;
};

struct ByteALUResult
{
    unsigned char value;
    bool z;
    bool h;
    bool n;
    bool c;
};

struct ShortALUResult overflowingAddShort(unsigned short s1, unsigned short s2);
struct ByteALUResult overflowingAddByte(unsigned char b1, unsigned char b2);

#endif
