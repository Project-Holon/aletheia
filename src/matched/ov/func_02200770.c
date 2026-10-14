/*
 * function: WORLDTRADE_TITLE_StateRequestExit
 * address:  0x02200770
 * packet:   pkt_02200770
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORLDTRADE_SUBLCD_StartAnimTaskB  0x021FF9E0  thumb  ov135

 * Reset, latch state 8 and clear the u16 slot at +0xe18.
 */
#include "../include/Obj04530.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void WORLDTRADE_SUBLCD_StartAnimTaskB(u8 *p);

int WORLDTRADE_TITLE_StateRequestExit(u8 *p)
{
    WORLDTRADE_SUBLCD_StartAnimTaskB(p);
    ((struct Obj04530 *)p)->f28 = 8;
    ((struct Obj04530 *)p)->fE18 = 0;
    return 2;
}
