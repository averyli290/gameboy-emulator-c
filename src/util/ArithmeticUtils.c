#include "ArithmeticUtils.h"

struct ShortALUResult overflowingAddShort(unsigned short s1, unsigned short s2) {
    struct ShortALUResult to_ret = {
        .value = s1 + s2,
        .z = (s1 + s2) == 0x0000,
        .n = 0,
        .h = ((s1 & 0x0FFF) + (s2 & 0x0FFF) > 0x0FFF),
        .c = ((unsigned int) s1 + (unsigned int) s2 > 0xFFFF),
    };
    return to_ret;
}

struct ByteALUResult overflowingAddByte(unsigned char b1, unsigned char b2) {
    struct ByteALUResult to_ret = {
        .value = b1 + b2,
        .z = (b1 + b2) == 0x0000,
        .n = 0,
        .h = ((b1 & 0x0F) + (b2 & 0x0F) > 0x0F),
        .c = ((unsigned short) b1 + (unsigned short) b2 > 0xFF),
    };
    return to_ret;
}