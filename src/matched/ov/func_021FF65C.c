/*
 * function: WORLDTRADE_STATUS_WaitIdle
 * address:  0x021FF65C
 * packet:   pkt_021FF65C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb  ov135

 * Answer 2, or set the 5/mode pair and answer 3 when the +0x12f4 word is clear.
 */
#include "../include/Obj12221.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);

u32 WORLDTRADE_STATUS_WaitIdle(u8 *p)
{
    u32 r = 2;

    if (((struct Obj12221 *)p)->f12F4 == 0) {
        WORLDTRADE_SetStateAndReturn(p, 5, ((struct Obj12221 *)p)->f20);
        r = 3;
    }
    return r;
}
