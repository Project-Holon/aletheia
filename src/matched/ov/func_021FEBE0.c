/*
 * function: WORLDTRADE_SEARCH_StateOpenNameMenu
 * address:  0x021FEBE0
 * packet:   pkt_021FEBE0
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

 * Publish +0xde4, kick helper 9, latch state 6.
 */
#include "../include/Obj12214.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void WORLDTRADE_INPUT_MenuSetMode(u8 *p, int mode);
extern void WORLDTRADE_SEARCH_SetBlendEffect(u32 k);

int WORLDTRADE_SEARCH_StateOpenNameMenu(u8 *p)
{
    WORLDTRADE_INPUT_MenuSetMode((u8 *)(((struct Obj12214 *)p)->fDE4), 0);
    WORLDTRADE_SEARCH_SetBlendEffect(9);
    ((struct Obj12214 *)p)->f28 = 6;
    return 2;
}
