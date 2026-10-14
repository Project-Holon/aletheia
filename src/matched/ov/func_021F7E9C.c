/*
 * function: WORLDTRADE_DEPOSIT_StateOpenConfirmYesNo
 * address:  0x021F7E9C
 * packet:   pkt_021F7E9C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_OpenTaskMenuYesNoDefault  0x021F4BE0  thumb  ov135

 * State setter: build with the fixed 0x14/0x126/0x3/0x0 argument pair and latch state 0xf.
 */
#include "../include/Obj18563.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void WORLDTRADE_OpenTaskMenuYesNoDefault(u32 a, u32 b, u32 c, u32 d, u8 e);

int WORLDTRADE_DEPOSIT_StateOpenConfirmYesNo(u8 *p)
{
    WORLDTRADE_OpenTaskMenuYesNoDefault((u32)p, 0x14, 0x126, 0x3, 0x0);
    ((struct Obj18563 *)p)->f28 = 0xf;
    return 2;
}
