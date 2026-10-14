/*
 * function: WORLDTRADE_SERVER_StartDataTransfer
 * address:  0x022013E4
 * packet:   pkt_022013E4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_ADAPTER_SetPair  0x0220251C  thumb  ov135

 * Move 0x80 bytes between the +0xe4 and +0x10ec sub-objects, latch state 7 and publish the 8/0xa pair.
 */
#include "../include/Obj12231.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021C86B8(u8 *dst, u8 *src, u32 n);
extern void WORLDTRADE_ADAPTER_SetPair(u8 *p, u16 a, u16 b);

int WORLDTRADE_SERVER_StartDataTransfer(u8 *p)
{
    func_021C86B8(p + 0xe4, p + 0x10ec, 0x80);
    ((struct Obj12231 *)p)->f28 = 7;
    ((struct Obj12231 *)p)->fF8C = 0;
    WORLDTRADE_ADAPTER_SetPair(p, 8, 0xa);
    return 2;
}
