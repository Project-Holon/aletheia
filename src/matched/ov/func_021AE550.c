/*
 * function: func_021AE550
 * address:  0x021AE550
 * packet:   pkt_021AE550
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
 *   func_0216D454  0x0216D454  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12098.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D454(u32, u32, u32, u32);

int func_021AE550(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216D454(((struct Obj12098 *)((u8 *)(a)))->f8, b, c, d) == 0) {
    return 0;
}
((struct Obj12098 *)((u8 *)(a)))->f0 = 5;
return 1;
}

