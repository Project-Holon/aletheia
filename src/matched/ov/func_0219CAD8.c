/*
 * function: func_0219CAD8
 * address:  0x0219CAD8
 * packet:   pkt_0219CAD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D4F8 (0x0216D4F8) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0216D4F8  0x0216D4F8  thumb
 *   func_0219CA00  0x0219CA00  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17970.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D4F8(u32, u32, u32, u32);
extern u32 func_0219CA00(u32, u32, u32);

int func_0219CAD8(u32 a, u32 b, u32 c, u32 d)
{
return func_0219CA00((a + 20), b, func_0216D4F8(((struct Obj17970 *)((u8 *)(a)))->f10, b, c, d));
}

