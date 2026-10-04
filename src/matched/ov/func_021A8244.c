/*
 * function: func_021A8244
 * address:  0x021A8244
 * packet:   pkt_021A8244
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_021A8268  0x021A8268  thumb  ov021
 *   func_0218C8D8  0x0218C8D8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18069.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_0218C8D8(void *p);
extern u32 func_021A8268(u32, u32, u32, u32);

int func_021A8244(u32 a, u32 b, u32 c, u32 d)
{
if (func_021A8268(a, b, c, d) == 0) {
    return 1;
}
if (func_0218C8D8((void *)(((struct Obj18069 *)((u8 *)(a)))->f28)) != 0) {
    return 1;
}
return 0;
}

