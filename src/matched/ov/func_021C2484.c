/*
 * function: func_021C2484
 * address:  0x021C2484
 * packet:   pkt_021C2484
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
 *   func_021C2734  0x021C2734  thumb  ov021
 *   func_020480E4  0x020480E4  arm
 *   func_021C1A84  0x021C1A84  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07228.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Ctx;
extern void func_020480E4(struct Ctx *c, u32 i);
extern u32 func_021C1A84(u32);
extern void func_021C2734(void **p);

int func_021C2484(u8 *a, u8 *b)
{
func_021C2734((void **)b);
func_020480E4((struct Ctx *)(((struct Obj07228 *)((u8 *)(a)))->f14), ((((struct Obj07228 *)((u8 *)(a)))->f18 << 16) >> 16));
((struct Obj07228 *)((u8 *)(a)))->f18 = (~0);
return func_021C1A84(((struct Obj07228 *)((u8 *)(a)))->f0);
}

