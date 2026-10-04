/*
 * function: func_02201A48
 * address:  0x02201A48
 * packet:   pkt_02201A48
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * State setter: hand over the object, latch the state word at +0x28 and clear the slot.
 */
#include "../include/Obj12237.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021C87FC(u8 *p);

int func_02201A48(u8 *p)
{
    func_021C87FC(p + 0xe4);
    ((struct Obj12237 *)p)->f28 = 0x1f;
    ((struct Obj12237 *)p)->fF8C = 0x0;
    return 0x2;
}
