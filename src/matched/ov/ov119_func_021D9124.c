/*
 * function: POKETRADE_PROC_RecvOfferMon0
 * address:  0x021D9124
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
#include "../include/Obj22708.h"

extern int POKETRADE_PROC_RecvOfferMonCommon(int a, int b, int c, int d, int e);

int POKETRADE_PROC_RecvOfferMon0(int a, int b, int c, int d, int e)
{
    return POKETRADE_PROC_RecvOfferMonCommon(((struct Obj22708 *)c)->f0, 0, a, d, e);
}

