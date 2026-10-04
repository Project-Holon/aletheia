/*
 * function: func_02201554
 * address:  0x02201554
 * packet:   pkt_02201554
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220251C  0x0220251C  thumb  ov135

 * State 0xc, slot cleared, then publish the 0xd/0xf pair.
 */
#include "../include/Obj12232.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021C87FC(u8 *p);
extern void func_0220251C(u8 *p, u16 a, u16 b);

int func_02201554(u8 *p)
{
    func_021C87FC(p + 0xe4);
    ((struct Obj12232 *)p)->f28 = 0xc;
    ((struct Obj12232 *)p)->fF8C = 0;
    func_0220251C(p, 0xd, 0xf);
    return 2;
}
