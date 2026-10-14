/*
 * function: WORLDTRADE_SERVER_StartDelete
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
 *   DPW_TR_DeleteAsync  0x021C88FC  arm  ov114
 *

 * State setter: hand over the object, latch the state word at +0x28 and clear the slot.
 */
#include "../include/Obj12239.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void DPW_TR_DeleteAsync(u8 *p);

int WORLDTRADE_SERVER_StartDelete(u8 *p)
{
    DPW_TR_DeleteAsync(p);
    ((struct Obj12239 *)p)->f28 = 0x18;
    ((struct Obj12239 *)p)->fF8C = 0x0;
    return 0x2;
}
