/*
 * function: func_021C1AA8
 * address:  0x021C1AA8
 * packet:   pkt_021C1AA8
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
 *   func_02051230  0x02051230  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18282.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02051230(u32, u32, u32, u32);

int func_021C1AA8(u32 a, u32 b, u32 c, u32 d)
{
return func_02051230(((struct Obj18282 *)((u8 *)(a)))->fC, b, c, d);
}

