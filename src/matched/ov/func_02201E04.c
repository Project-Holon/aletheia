/*
 * function: WORLDTRADE_SERVER_StatePrintMessage10
 * address:  0x02201E04
 * packet:   pkt_02201E04
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
 * Enter the 201E04 sub-state: flag the u16 at +0x32, set the two work values and stamp the state.
 */
#include "../include/Obj12242.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);

int WORLDTRADE_SERVER_StatePrintMessage10(u8 *p)
{
    ((struct Obj12242 *)p)->f32 = 0;
    WORLDTRADE_SetStateAndReturn(p, 9, 10);
    ((struct Obj12242 *)p)->f28 = 0x22;
    return 2;
}
