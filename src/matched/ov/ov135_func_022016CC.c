/*
 * function: WORLDTRADE_SERVER_StartTrade
 * address: 0x022016CC
 * packet: pkt_ov135_022016CC
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DPW_TR_TradeAsync 0x021C8C68 arm ov114
 *   WORLDTRADE_ADAPTER_SetPair 0x0220251C thumb ov135
 */
#include "../include/Obj10595.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void DPW_TR_TradeAsync(u32, const void *, u32, const void *, u32);
typedef unsigned short u16;
extern void WORLDTRADE_ADAPTER_SetPair(u8 *p, u16 a, u16 b);
int WORLDTRADE_SERVER_StartTrade(u8 *p)
{
    DPW_TR_TradeAsync(*(u32 *)(p + ((struct Obj10595 *)p)->fD4 * 0x128 + 0x314), p + 0xe4, (u32)(p + 0xa24), p + 0x10ec, 0x80);
    WORLDTRADE_ADAPTER_SetPair(p, 0x12, 0x14);
    ((struct Obj10595 *)p)->f28 = 0x11;
    ((struct Obj10595 *)p)->fF8C = 0;
    return 2;
}
