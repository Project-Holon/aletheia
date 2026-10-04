/*
 * function: func_021AE5A8
 * address:  0x021AE5A8
 * packet:   pkt_021AE5A8
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
 *   func_0216D410  0x0216D410  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12099.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D410(u32, u32, u32, u32);

int func_021AE5A8(u32 a, u32 b, u32 c, u32 d)
{
func_0216D410(((struct Obj12099 *)((u8 *)(a)))->f8, 101, c, d);
((struct Obj12099 *)((u8 *)(a)))->f0 = 8;
return 0;
}

