/*
 * function: func_021BC250
 * address:  0x021BC250
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Accumulate +0x50 into +0x4c, zeroing the total when the product is not positive.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00025.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BC250(void *p)
{
    s32 a = *(u32 *)&((struct Obj00025 *)p)->f4C;
    s32 b = ((struct Obj00025 *)p)->f50;
    s32 t = a + b;
    if (a * t <= 0) {
        t = 0;
    }
    *(u32 *)&((struct Obj00025 *)p)->f4C = t;
}
