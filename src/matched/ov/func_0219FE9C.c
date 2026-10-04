/*
 * function: func_0219FE9C
 * address:  0x0219FE9C
 * packet:   pkt_0219FE9C
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
 *   func_02082BCC  0x02082BCC  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17985.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02082BCC(u32, u32, u32, u32);

int func_0219FE9C(u32 a, u32 b, u32 c, u32 d)
{
func_02082BCC(a, 0, 4, d);
((struct Obj17985 *)((u8 *)(a)))->f0 = 8;
return 8;
}

