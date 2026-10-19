/*
 * function: WORLDTRADE_ADAPTER_IsStreamBusy
 * address:  0x02202840
 * packet:   pkt_02202840
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *

 * Non-zero unless the +0x10 handle is absent or the query answers 2.
 */
#include "../include/Obj18615.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 PRINTSYS_PrintStreamGetState(void *p);

u32 WORLDTRADE_ADAPTER_IsStreamBusy(u8 *p)
{
    u32 r;
    u32 x;

    r = 0;
    x = ((struct Obj18615 *)p)->f10;
    if (x != 0 && PRINTSYS_PrintStreamGetState((void *)x) != 2) {
        r = 1;
    }
    return r;
}
