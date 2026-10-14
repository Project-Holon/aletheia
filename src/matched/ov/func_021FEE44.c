/*
 * function: WORLDTRADE_SEARCH_StateOpenLevelMenu
 * address:  0x021FEE44
 * packet:   pkt_021FEE44
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_INPUT_MenuSetMode  0x021F9968  thumb  ov135
 *   WORLDTRADE_SEARCH_SetBlendEffect  0x021FF570  thumb  ov135

 * Sentinel at +0xbc, publish +0xde4, kick helper 9, latch state 0xc.
 */
#include "../include/Obj09239.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void WORLDTRADE_INPUT_MenuSetMode(u8 *p, int mode);
extern void WORLDTRADE_SEARCH_SetBlendEffect(u32 k);

int WORLDTRADE_SEARCH_StateOpenLevelMenu(u8 *p)
{
    ((struct Obj09239 *)p)->fBC = 0xffff;
    WORLDTRADE_INPUT_MenuSetMode((u8 *)(((struct Obj09239 *)p)->fDE4), 2);
    WORLDTRADE_SEARCH_SetBlendEffect(9);
    ((struct Obj09239 *)p)->f28 = 0xc;
    return 2;
}
