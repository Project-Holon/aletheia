/*
 * function: WORLDTRADE_DEPOSIT_StoreOfferInWork
 * address: 0x021F8668
 * packet: pkt_ov135_021F8668
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_DEPOSIT_BuildOffer 0x021F8554 thumb ov135
 */
#include "../include/Obj06510.h"
#include "../include/Obj06511.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void WORLDTRADE_DEPOSIT_BuildOffer(u8 *dst, void *p);
void WORLDTRADE_DEPOSIT_StoreOfferInWork(u8 *dst, u8 *p)
{
    WORLDTRADE_DEPOSIT_BuildOffer(dst, p);
    ((struct Obj06510 *)dst)->fEC = ((struct Obj06511 *)p)->fB4C;
    ((struct Obj06510 *)dst)->fEE = ((struct Obj06511 *)p)->fB4E;
    ((struct Obj06510 *)dst)->fF0 = ((struct Obj06511 *)p)->fB50;
    ((struct Obj06510 *)dst)->fF2 = ((struct Obj06511 *)p)->fB52;
    ((struct Obj06510 *)dst)->fF4 = ((struct Obj06511 *)p)->fB54;
}
