/*
 * function: func_021CE78C
 * address:  0x021CE78C
 * packet:   pkt_021CE78C
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
 *   func_02190EF0  0x02190EF0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09217.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02190EF0(u32, u32, u32, u32);

int func_021CE78C(u32 a, u32 b, u32 c, u32 d)
{
if (*(u32 *)((u8 *)(a) + ((1 << 8))) == 0) {
    if (func_02190EF0(((struct Obj09217 *)((u8 *)(a)))->f14, *(u32 *)((u8 *)(a) + ((1 << 8))), c, d) == 1) {
        return 1;
    }
}
return 0;
}

