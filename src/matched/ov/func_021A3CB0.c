/*
 * function: func_021A3CB0
 * address:  0x021A3CB0
 * packet:   pkt_021A3CB0
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
#include "../include/Obj05862.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021A3CB0(u32 a, u32 b)
{
((struct Obj05862 *)((u8 *)(a)))->f24 = b;
((struct Obj05862 *)((u8 *)(a)))->f30 = 0;
((struct Obj05862 *)((u8 *)(a)))->f32 = 0;
((struct Obj05862 *)((u8 *)(a)))->f2C = 0;
((struct Obj05862 *)((u8 *)(a)))->f2E = 0;
return a;
}

