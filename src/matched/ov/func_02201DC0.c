/*
 * function: WORLDTRADE_SERVER_StateSetBusyMessage
 * address:  0x02201DC0
 * packet:   pkt_02201DC0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb  ov135
 *

 *
 * Enter the 201DC0 sub-state: flag the u16 at +0x32, set the two work values and stamp the state.
 */
#include "../include/Obj12240.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);

int WORLDTRADE_SERVER_StateSetBusyMessage(u8 *p)
{
    ((struct Obj12240 *)p)->f32 = 1;
    WORLDTRADE_SetStateAndReturn(p, 9, 7);
    ((struct Obj12240 *)p)->f28 = 0x28;
    return 2;
}
