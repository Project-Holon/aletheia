#ifndef GAME_SDK_MATH_H
#define GAME_SDK_MATH_H

#include "types.h"

/*
 * Math library of the SDK: checksum tables, random generator state
 * and the digest contexts.
 */

typedef struct MATHCRC16Table
{
    u16 table[256];
} MATHCRC16Table;

typedef struct MATHCRC32Table
{
    u32 table[256];
} MATHCRC32Table;

typedef struct MATHCRC8Table
{
    u8 table[256];
} MATHCRC8Table;

typedef struct MATHMD5Context {
    union {
        struct {
            u32 a;
            u32 b;
            u32 c;
            u32 d;
        };
        u32 state[4];
    };
    unsigned long long length;
    union {
        u32 buffer32[16];
        u8 buffer8[64];
    };
} MATHMD5Context;

typedef struct MATHRandContext32 {
    unsigned long long x;
    unsigned long long mul;
    unsigned long long add;
} MATHRandContext32;

typedef struct MATHiHMACFuncs {
    u32 dlength;
    u32 blength;
    void *context;
    u8 *hash_buf;
    void (*HashReset)(void *context);
    void (*HashSetSource)(void *context, const void *input, u32 length);
    void (*HashGetDigest)(void *context, void *digest);
} MATHiHMACFuncs;

#endif
