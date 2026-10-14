/*
 * function: POKETRADE_PROC_RecvOfferMon1
 * address:  0x021D913C
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Encoder session getter on the byte pointed at by the third argument.
 *
 * symbols:
 *   POKETRADE_PROC_RecvOfferMonCommon  0x021D90E8  thumb  ov119
 */
#include "../include/Obj22709.h"

extern int POKETRADE_PROC_RecvOfferMonCommon(int a, int b, int c, int d, int e);

int POKETRADE_PROC_RecvOfferMon1(int a, int b, int c, int d, int e)
{
    return POKETRADE_PROC_RecvOfferMonCommon(((struct Obj22709 *)c)->f0, 1, a, d, e);
}

