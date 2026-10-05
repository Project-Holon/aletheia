/*
 * function: func_0219D49C
 * address:  0x0219D49C
 * packet:   pkt_0219D49C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D528 (0x0216D528) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D528  0x0216D528  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17972.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D528(u32);
extern u32 func_0216D67C(u32, u32, u32, u32);

int func_0219D49C(u32 a, u32 b, u32 c, u32 d)
{
return ((struct Obj17972 *)((u8 *)(func_0216D528(func_0216D67C(a, b, c, d)))))->f4;
}

