/*
 * function: func_021BC69C
 * address: 0x021BC69C
 * packet: pkt_ov110_021BC69C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B878 0x0204B878 arm
 */
#include "../include/Obj01393.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
void func_021BC69C(u8 *p, int flag)
{
    if (((struct Obj01393 *)p)->f44 != 0) {
        if (flag != 0) func_0204B878(((struct Obj01393 *)p)->f14, 0);
        else func_0204B878(((struct Obj01393 *)p)->f14, 1);
    } else {
        if (flag != 0) func_0204B878(((struct Obj01393 *)p)->f14, 14);
        else func_0204B878(((struct Obj01393 *)p)->f14, 15);
    }
}
