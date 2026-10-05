/*
 * function: func_021C7E70
 * address:  0x021C7E70
 * packet:   pkt_021C7E70
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
#include "../include/Obj03529.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021C7E70(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1)
{
((struct Obj03529 *)((u8 *)(a)))->f0 = b;
((struct Obj03529 *)((u8 *)(a)))->fC = b;
((struct Obj03529 *)((u8 *)(a)))->f10 = (c - b);
((struct Obj03529 *)((u8 *)(a)))->f4 = d;
((struct Obj03529 *)((u8 *)(a)))->f14 = d;
((struct Obj03529 *)((u8 *)(a)))->f16 = (*(u8 *)((u8 *)((u8 *)&e0)) - d);
((struct Obj03529 *)((u8 *)(a)))->f6 = 0;
((struct Obj03529 *)((u8 *)(a)))->f8 = e1;
return a;
}

