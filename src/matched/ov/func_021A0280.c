/*
 * function: func_021A0280
 * address:  0x021A0280
 * packet:   pkt_021A0280
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07213.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021A0280(u32 a, u32 b, u32 c)
{
if (((struct Obj07213 *)((u8 *)(a)))->f0 < ((struct Obj07213 *)((u8 *)(a)))->f2) {
    ((struct Obj07213 *)((u8 *)(a)))->f0 = (((struct Obj07213 *)((u8 *)(a)))->f0 + 1);
}
return a;
}

