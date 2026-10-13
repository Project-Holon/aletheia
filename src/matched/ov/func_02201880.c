/*
 * function: func_02201880
 * address:  0x02201880
 * packet:   pkt_02201880
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DPW_TR_ReturnAsync  0x021C887C  arm  ov114
 *

 * State setter: hand over the object, latch the state word at +0x28 and clear the slot.
 */
#include "../include/Obj12235.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void DPW_TR_ReturnAsync(u8 *p);

int func_02201880(u8 *p)
{
    DPW_TR_ReturnAsync(p + 0xe4);
    ((struct Obj12235 *)p)->f28 = 0x1d;
    ((struct Obj12235 *)p)->fF8C = 0x0;
    return 0x2;
}
