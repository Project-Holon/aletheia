/*
 * function: WORLDTRADE_DEPOSIT_StateWaitCancel
 * address:  0x021F7A4C
 * packet:   pkt_021F7A4C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb  ov135
 *   KEY_GetTrg  0x020362DC  arm  arm9

 * Test bit 1 of the callee result; the odd branch re-latches state 2 before state 3.
 */
#include "../include/Obj12199.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 KEY_GetTrg(void);
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);

int WORLDTRADE_DEPOSIT_StateWaitCancel(u8 *p)
{
    u32 v = KEY_GetTrg();

    if (v & 2) {
        WORLDTRADE_SetStateAndReturn(p, 5, 5);
        ((struct Obj12199 *)p)->f28 = 2;
    }
    ((struct Obj12199 *)p)->f28 = 3;
    return 2;
}
