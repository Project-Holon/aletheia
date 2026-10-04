/*
 * function: func_021A2A84
 * address:  0x021A2A84
 * packet:   pkt_021A2A84
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
#include "../include/Obj02344.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021A2A84(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u32 e2, u32 e3, u32 e4, u32 e5)
{
((struct Obj02344 *)((u8 *)(a)))->f0 = b;
((struct Obj02344 *)((u8 *)(a)))->f6 = 0;
((struct Obj02344 *)((u8 *)(a)))->fA = 0;
((struct Obj02344 *)((u8 *)(a)))->f4 = d;
((struct Obj02344 *)((u8 *)(a)))->fC = e0;
((struct Obj02344 *)((u8 *)(a)))->f8 = c;
((struct Obj02344 *)((u8 *)(a)))->fE = e1;
((struct Obj02344 *)((u8 *)(a)))->f10 = e2;
((struct Obj02344 *)((u8 *)(a)))->f12 = e3;
((struct Obj02344 *)((u8 *)(a)))->f14 = e4;
((struct Obj02344 *)((u8 *)(a)))->f18 = e5;
return a;
}

