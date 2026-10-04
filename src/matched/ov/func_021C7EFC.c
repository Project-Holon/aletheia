/*
 * function: func_021C7EFC
 * address:  0x021C7EFC
 * packet:   pkt_021C7EFC
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
 *   func_021C7EF0  0x021C7EF0  thumb  ov021
 *   func_021C7EF8  0x021C7EF8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18330.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021C7EF0(u32, u32, u32, u32);
extern u32 func_021C7EF8(u32, u32);

int func_021C7EFC(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj18330 *)((u8 *)(a)))->f1C = 1;
func_021C7EF0((a + 4), (3 << 12), c, d);
return func_021C7EF8((a + 4), 31);
}

