/*
 * function: WORLDTRADE_SERVER_StatePrintMessage9
 * address:  0x02201DF0
 * packet:   pkt_02201DF0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb  ov135

 * Set the mode pair and latch state 0x28.
 */
#include "../include/Obj18613.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);

int WORLDTRADE_SERVER_StatePrintMessage9(u8 *p)
{
    WORLDTRADE_SetStateAndReturn(p, 0x9, 0x9);
    ((struct Obj18613 *)p)->f28 = 0x28;
    return 2;
}
