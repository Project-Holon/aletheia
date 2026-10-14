/*
 * function: WORLDTRADE_DEPOSIT_StateOpenCategoryMenu
 * address:  0x021F7A70
 * packet:   pkt_021F7A70
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_INPUT_MenuSetMode  0x021F9968  thumb  ov135

 *
 * Hand the buffer at +0xde4 to the writer and stamp state 6.
 */
#include "../include/Obj12200.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef void (*Fn)(void);
extern void WORLDTRADE_INPUT_MenuSetMode(u8 *p, int mode);

int WORLDTRADE_DEPOSIT_StateOpenCategoryMenu(u8 *p)
{
    WORLDTRADE_INPUT_MenuSetMode((u8 *)(((struct Obj12200 *)p)->fDE4), 0);
    ((struct Obj12200 *)p)->f28 = 6;
    return 2;
}
