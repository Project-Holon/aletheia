/*
 * function: func_021C1AD0
 * address:  0x021C1AD0
 * packet:   pkt_021C1AD0
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
 *   func_021C1A84  0x021C1A84  thumb  ov021
 *   func_02050ED4  0x02050ED4  arm
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09206.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern u32 func_02050ED4(u32);
extern u32 func_021C1A84(u32, u32, u32, u32);

int func_021C1AD0(u32 a, u32 b, u32 c, u32 d)
{
func_02050ED4(func_021C1A84(a, b, c, d));
func_020307B0(((struct Obj09206 *)((u8 *)(a)))->f8);
return func_020307B0(a);
}

