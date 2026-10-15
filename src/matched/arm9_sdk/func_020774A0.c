/*
 * function: CARD_SetPulledOutCallback
 * address:  0x020774A0
 * packet:   pkt_020774A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARD_SetPulledOutCallback (libcard.TWL.HYB.a card_pullout.o)
 *
 * symbols:
 *   CARDiSlotResetCount  0x02150B00  data
 */

#include "../include/G_CARDPulledOutState.h"

extern struct CARDPulledOutState CARDiSlotResetCount;

void CARD_SetPulledOutCallback(int (*callback)(void))
{
    CARDiSlotResetCount.callback = callback;
}
