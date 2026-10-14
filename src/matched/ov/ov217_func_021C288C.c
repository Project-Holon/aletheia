/*
 * function: PERCENTAGE_StorePosition
 * address:  0x021C288C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Store two u32 arguments at +4 and +8.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03957.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void PERCENTAGE_StorePosition(void *p, u32 a, u32 b)
{
    ((struct Obj03957 *)p)->f4 = a;
    ((struct Obj03957 *)p)->f8 = b;
}
