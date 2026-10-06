/*
 * function: func_0219EA94
 * address:  0x0219EA94
 * packet:   pkt_0219EA94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D530 (0x0216D530) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D530  0x0216D530  thumb
 *   func_021BB3A0  0x021BB3A0  thumb  ov021
 *   func_0216D550  0x0216D550  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17976.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D530(u32);
extern u32 func_0216D550(u32, u32);
extern void *func_0216D67C(void *a0);
extern u32 func_021BB3A0(u32, u32);

int func_0219EA94(u32 a, u32 b, u32 c, u32 d)
{
func_021BB3A0(func_0216D530((u32)func_0216D67C((void *)b)), ((struct Obj17976 *)((u8 *)(a)))->f0);
return func_0216D550(b, (2 << 12));
}

