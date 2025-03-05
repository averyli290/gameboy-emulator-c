#ifndef ARITHMETIC_UTILS_H
#define ARITHMETIC_UTILS_H

#include <stdbool.h>

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

struct ShortALUResult overflowingAddShort(const unsigned short s1, const unsigned short s2);
struct ByteALUResult overflowingAddByte(const unsigned char b1, const unsigned char b2);
struct ShortALUResult overflowingSubShort(const unsigned short s1, const unsigned short s2);
struct ByteALUResult overflowingSubByte(const unsigned char b1, const unsigned char b2);
struct ByteALUResult andByte(const unsigned char b1, const unsigned char b2);
struct ByteALUResult orByte(const unsigned char b1, const unsigned char b2);
struct ByteALUResult xorByte(const unsigned char b1, const unsigned char b2);

#endif
