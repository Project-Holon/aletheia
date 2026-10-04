/*
 * function: func_021FD6D8
 * address:  0x021FD6D8
 * packet:   pkt_021FD6D8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02202840  0x02202840  thumb  ov135
 *
 * When the sub-object at +0xfa0 is idle, re-arm the state word from +0x2c.
 */
#include "../include/Obj12211.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02202840(u8 *p);

int func_021FD6D8(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        ((struct Obj12211 *)p)->f28 = ((struct Obj12211 *)p)->f2C;
    }
    return 2;
}
