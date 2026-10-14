/*
 * function: WORLDTRADE_DEPOSIT_CheckGenderEvent
 * address:  0x021F7B9C
 * packet:   pkt_021F7B9C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *

 *
 * Map the event code to its state byte: 0, 0xfe and 0xff are accepted.
 */
#include "../include/Obj09230.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
int WORLDTRADE_DEPOSIT_CheckGenderEvent(u8 *p, int event)
{
    switch (event) {
    case 0:
        ((struct Obj09230 *)p)->f2 = 1;
        return 1;
    case 0xfe:
        ((struct Obj09230 *)p)->f2 = 2;
        return 1;
    case 0xff:
        ((struct Obj09230 *)p)->f2 = 3;
        return 1;
    }
    return 0;
}
