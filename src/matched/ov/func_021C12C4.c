/*
 * function: func_021C12C4
 * address:  0x021C12C4
 * packet:   pkt_021C12C4
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
 *   func_02030EE8  0x02030EE8  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18276.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02030EE8(u32, u32, u32, u32);

int func_021C12C4(u32 a, u32 b, u32 c, u32 d)
{
return ((struct Obj18276 *)((u8 *)(func_02030EE8(a, b, c, d))))->f6;
}

