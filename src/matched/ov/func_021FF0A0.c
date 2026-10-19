/*
 * function: WORLDTRADE_SEARCH_StateWaitMessage
 * address:  0x021FF0A0
 * packet:   pkt_021FF0A0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORLDTRADE_ADAPTER_IsStreamBusy  0x02202840  thumb  ov135
 *
 * When the sub-object at +0xfa0 is idle, re-arm the state word from +0x2c.
 */
#include "../include/Obj12216.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 WORLDTRADE_ADAPTER_IsStreamBusy(u8 *p);

int WORLDTRADE_SEARCH_StateWaitMessage(u8 *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamBusy(p + 0xfa0) == 0) {
        ((struct Obj12216 *)p)->f28 = ((struct Obj12216 *)p)->f2C;
    }
    return 2;
}
