/*
 * function: func_022017F0
 * address:  0x022017F0
 * packet:   pkt_022017F0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DPW_TR_TradeFinishAsync  0x021C8D14  arm  ov114
 *

 * State setter: hand over the object, latch the state word at +0x28 and clear the slot.
 */
#include "../include/Obj12234.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void DPW_TR_TradeFinishAsync(u8 *p);

int func_022017F0(u8 *p)
{
    DPW_TR_TradeFinishAsync(p);
    ((struct Obj12234 *)p)->f28 = 0x13;
    ((struct Obj12234 *)p)->fF8C = 0x0;
    return 0x2;
}
