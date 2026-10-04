/*
 * function: func_021A530C
 * address:  0x021A530C
 * packet:   pkt_021A530C
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
#include "../include/Obj07218.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021A530C(u32 a, u32 b, u32 c)
{
((struct Obj07218 *)((u8 *)(a)))->f8 = ((~b) & ((struct Obj07218 *)((u8 *)(a)))->f8);
return a;
}

