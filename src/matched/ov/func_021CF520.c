/*
 * function: func_021CF520
 * address:  0x021CF520
 * packet:   pkt_021CF520
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
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12140.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

void func_021CF520(u32 a, u32 b, u32 c, u32 d)
{
if (((struct Obj12140 *)((u8 *)(a)))->f4 != 0) {
    ((void (*)(u32, u32, u32, u32))*(u32 *)((u8 *)(a) + 4))(a, ((struct Obj12140 *)((u8 *)(a)))->f4, c, d);
}
}

