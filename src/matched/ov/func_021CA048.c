/*
 * function: func_021CA048
 * address:  0x021CA048
 * packet:   pkt_021CA048
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
#include "../include/Obj07233.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021CA048(u32 a, u32 b, u32 c)
{
((struct Obj07233 *)((u8 *)(a)))->fC = (((struct Obj07233 *)((u8 *)(a)))->fC & ~1);
((struct Obj07233 *)((u8 *)(a)))->fC = (((struct Obj07233 *)((u8 *)(a)))->fC & ~6);
return a;
}

