/*
 * function: func_02200770
 * address:  0x02200770
 * packet:   pkt_02200770
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FF9E0  0x021FF9E0  thumb  ov135

 * Reset, latch state 8 and clear the u16 slot at +0xe18.
 */
#include "../include/Obj04530.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021FF9E0(u8 *p);

int func_02200770(u8 *p)
{
    func_021FF9E0(p);
    ((struct Obj04530 *)p)->f28 = 8;
    ((struct Obj04530 *)p)->fE18 = 0;
    return 2;
}
