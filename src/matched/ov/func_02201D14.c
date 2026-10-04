/*
 * function: func_02201D14
 * address:  0x02201D14
 * packet:   pkt_02201D14
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
#include "../include/Obj12239.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021C88FC(u8 *p);

int func_02201D14(u8 *p)
{
    func_021C88FC(p);
    ((struct Obj12239 *)p)->f28 = 0x18;
    ((struct Obj12239 *)p)->fF8C = 0x0;
    return 0x2;
}
