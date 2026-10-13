/*
 * function: HEIGHT_EX_IsPointInAreaAt
 * address:  0x021C068C
 * packet:   pkt_021C068C
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
 *   HEIGHT_EX_IsPointInArea  0x021C0598  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18268.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 HEIGHT_EX_IsPointInArea(u32, u32, u32, u32);

int HEIGHT_EX_IsPointInAreaAt(int a, int b, int c, u8 d)
{
if (HEIGHT_EX_IsPointInArea(a, b, (((struct Obj18268 *)((u8 *)(c)))->f4 + (d * 28)), d) != 0) {
    return 1;
}
return 0;
}

