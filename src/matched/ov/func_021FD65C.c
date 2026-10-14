/*
 * function: WORLDTRADE_LIST_StateRedrawRecord
 * address:  0x021FD65C
 * packet:   pkt_021FD65C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_LIST_DrawSelectedRecord  0x021FD5F0  thumb  ov135

 *
 * Reset the sub-state and report 2.
 */
#include "../include/Obj02860.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WORLDTRADE_LIST_DrawSelectedRecord(u8 *p);

int WORLDTRADE_LIST_StateRedrawRecord(u8 *p)
{
    WORLDTRADE_LIST_DrawSelectedRecord(p);
    ((struct Obj02860 *)p)->f28 = 1;
    return 2;
}
