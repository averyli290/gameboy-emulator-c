#include "ArithmeticUtils.h"

struct ShortALUResult overflowingAddShort(const unsigned short s1, const unsigned short s2) {
    struct ShortALUResult to_ret = {
        .value = s1 + s2,
        .z = (s1 + s2) == 0x0000,
        .n = 0,
        .h = ((s1 & 0x0FFF) + (s2 & 0x0FFF) > 0x0FFF),
        .c = ((unsigned int) s1 + (unsigned int) s2 > 0xFFFF),
    };
    return to_ret;
}

struct ByteALUResult overflowingAddByte(const unsigned char b1, const unsigned char b2) {
    struct ByteALUResult to_ret = {
        .value = b1 + b2,
        .z = (b1 + b2) == 0x00,
        .n = 0,
        .h = ((b1 & 0x0F) + (b2 & 0x0F) > 0x0F),
        .c = ((unsigned short) b1 + (unsigned short) b2 > 0xFF),
    };
    return to_ret;
}

struct ShortALUResult overflowingSubShort(const unsigned short s1, const unsigned short s2)
{
    struct ShortALUResult to_ret = {
        .value = s1 - s2,
        .z = (s1 - s2) == 0x0000,
        .n = 1,
        .h = ((s1 & 0x00FF) < (s2 & 0x00FF)),
        .c = s1 < s2,
    };
    return to_ret;
}
struct ByteALUResult overflowingSubByte(const unsigned char b1, const unsigned char b2)
{
    struct ByteALUResult to_ret = {
        .value = b1 - b2,
        .z = (b1 - b2) == 0x00,
        .n = 1,
        .h = ((b1 & 0x0F) < (b2 & 0x0F)),
        .c = b1 < b2,
    };
    return to_ret;
}

struct ByteALUResult andByte(const unsigned char b1, const unsigned char b2) {
    struct ByteALUResult to_ret = {
        .value = b1 & b2,
        .z = (b1 & b2) == 0x0000,
        .n = 0,
        .h = 1,
        .c = 0,
    };
    return to_ret;
}

struct ByteALUResult orByte(const unsigned char b1, const unsigned char b2)
{
    struct ByteALUResult to_ret = {
        .value = b1 | b2,
        .z = (b1 | b2) == 0x0000,
        .n = 0,
        .h = 0,
        .c = 0,
    };
    return to_ret;
}

struct ByteALUResult xorByte(const unsigned char b1, const unsigned char b2)
{
    struct ByteALUResult to_ret = {
        .value = b1 ^ b2,
        .z = (b1 ^ b2) == 0x0000,
        .n = 0,
        .h = 0,
        .c = 0,
    };
    return to_ret;
}

