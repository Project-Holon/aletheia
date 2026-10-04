/*
 * function: func_021F5CD4
 * address:  0x021F5CD4
 * packet:   pkt_021F5CD4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4EC0  0x021F4EC0  thumb  ov135

 * Two-way mode dispatch on the second argument, each arm latching state 2.
 */
#include "../include/Obj12195.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021F4EC0(u8 *p, u32 a, u32 b);

void func_021F5CD4(u8 *p, u32 k)
{
    if (k == 5) {
        func_021F4EC0(p, 1, 0);
        ((struct Obj12195 *)p)->f28 = 2;
    } else if (k == 6) {
        func_021F4EC0(p, 3, 0x11);
        ((struct Obj12195 *)p)->f28 = 2;
    }
}
