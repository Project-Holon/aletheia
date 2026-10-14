/*
 * function: WORLDTRADE_SEARCH_StateOpenGenderMenu
 * address:  0x021FED4C
 * packet:   pkt_021FED4C
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

 * Publish the +0xde4 slot, kick helper 9 and latch state 9.
 */
#include "../include/Obj12215.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern void WORLDTRADE_INPUT_MenuSetMode(u8 *p, int mode);
extern void WORLDTRADE_SEARCH_SetBlendEffect(u32 k);

int WORLDTRADE_SEARCH_StateOpenGenderMenu(u8 *p)
{
    WORLDTRADE_INPUT_MenuSetMode((u8 *)(((struct Obj12215 *)p)->fDE4), 1);
    WORLDTRADE_SEARCH_SetBlendEffect(9);
    ((struct Obj12215 *)p)->f28 = 9;
    return 2;
}
