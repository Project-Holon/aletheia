/*
 * function: func_021F4F84
 * address:  0x021F4F84
 * packet:   pkt_021F4F84
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 *
 * Decrement the u16 counter at +0x36 when it is non-zero.
 */
#include "../include/Obj12193.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
void func_021F4F84(u8 *p)
{
    u16 v = ((struct Obj12193 *)p)->f36;

    if (v != 0) {
        ((struct Obj12193 *)p)->f36 = v - 1;
    }
}
