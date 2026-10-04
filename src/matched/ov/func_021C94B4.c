/*
 * function: func_021C94B4
 * address:  0x021C94B4
 * packet:   pkt_021C94B4
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
#include "../include/Obj12138.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021C94B4(u32 a, u32 b)
{
return (((struct Obj12138 *)((u8 *)(a)))->f0 + *(u16 *)((u8 *)(((struct Obj12138 *)((u8 *)(a)))->f0) + 2));
}

