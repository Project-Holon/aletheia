/*
 * function: WORLDTRADE_DETAIL_StateOpenConfirm
 * address:  0x021FC638
 * packet:   pkt_021FC638
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_OpenTaskMenuYesNo  0x021F4BF8  thumb  ov135
 *   WORLDTRADE_ClearBlendRegs  0x021F5060  thumb  ov135
 *   WORLDTRADE_SetBrightnessOut  0x021F5034  thumb  ov135

 * Build, kick the two fixed helpers and latch state 6.
 */
#include "../include/Obj02489.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void WORLDTRADE_OpenTaskMenuYesNo(u8 *p, int b, int unused, int a, int c, u8 flag);
extern void WORLDTRADE_ClearBlendRegs(void);
extern void WORLDTRADE_SetBrightnessOut(u32 v);

int WORLDTRADE_DETAIL_StateOpenConfirm(u8 *p)
{
    WORLDTRADE_OpenTaskMenuYesNo(p, 0x14, 0x16a, 8, 2, 1);
    WORLDTRADE_ClearBlendRegs();
    WORLDTRADE_SetBrightnessOut(1);
    ((struct Obj02489 *)p)->f28 = 6;
    return 2;
}
