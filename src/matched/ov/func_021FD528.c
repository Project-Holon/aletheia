/*
 * function: WORLDTRADE_LIST_StatePrintPrompt
 * address:  0x021FD528
 * packet:   pkt_021FD528
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_OpenTaskMenuYesNo  0x021F4BF8  thumb  ov135

 * Build with the fixed 0x12/0x12e/3/4/1 argument pair and latch state 5.
 */
#include "../include/Obj02489.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void WORLDTRADE_OpenTaskMenuYesNo(u8 *p, int b, int unused, int a, int c, u8 flag);

int WORLDTRADE_LIST_StatePrintPrompt(u8 *p)
{
    WORLDTRADE_OpenTaskMenuYesNo(p, 0x12, 0x12e, 3, 4, 1);
    ((struct Obj02489 *)p)->f28 = 5;
    return 2;
}
