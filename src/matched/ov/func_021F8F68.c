/*
 * function: WORLDTRADE_ENTER_StateExit
 * address:  0x021F8F68
 * packet:   pkt_021F8F68
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_DeleteTimeIcon  0x021F4FC4  thumb  ov135

 * Reset the object, latch state 0 and set the +0xeb4 slot to 1.
 */
#include "../include/Obj12205.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void WORLDTRADE_DeleteTimeIcon(u8 *p);

int WORLDTRADE_ENTER_StateExit(u8 *p)
{
    WORLDTRADE_DeleteTimeIcon(p);
    ((struct Obj12205 *)p)->f28 = 0;
    ((struct Obj12205 *)p)->fEB4 = 1;
    return 3;
}
