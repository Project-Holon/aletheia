/*
 * function: WORLDTRADE_BOX_StateOpenDepositConfirm
 * address:  0x021F6418
 * packet:   pkt_021F6418
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_OpenTaskMenuYesNoDefault  0x021F4BE0  thumb  ov135

 * State setter: build with the fixed 0x12/0x1ad/0x8/0x1 argument pair and latch state 0xd.
 */
#include "../include/Obj18541.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void WORLDTRADE_OpenTaskMenuYesNoDefault(u32 a, u32 b, u32 c, u32 d, u8 e);

int WORLDTRADE_BOX_StateOpenDepositConfirm(u8 *p)
{
    WORLDTRADE_OpenTaskMenuYesNoDefault((u32)p, 0x12, 0x1ad, 0x8, 0x1);
    ((struct Obj18541 *)p)->f28 = 0xd;
    return 2;
}
