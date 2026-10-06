/*
 * function: func_021C06A8
 * address:  0x021C06A8
 * packet:   pkt_021C06A8
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
#include "../include/Obj18269.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021C06A8(u8 a, int b)
{
return *(u32 *)((u8 *)((((struct Obj18269 *)((u8 *)(b)))->f4 + (a * 28))) + 16);
}

