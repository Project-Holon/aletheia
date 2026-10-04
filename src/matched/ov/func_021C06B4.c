/*
 * function: func_021C06B4
 * address:  0x021C06B4
 * packet:   pkt_021C06B4
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
#include "../include/Obj18270.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021C06B4(u32 a, u32 b, u32 c)
{
return *(u32 *)((u8 *)((((struct Obj18270 *)((u8 *)(b)))->f4 + (a * 28))) + 24);
}

