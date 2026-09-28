/*
 * function: func_020774A0
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

struct CARDPulledOutState {
    unsigned long slot_reset_count;
    int is_pulled_out;
    int (*callback)(void);
};

extern struct CARDPulledOutState CARDiSlotResetCount;

void func_020774A0(int (*callback)(void))
{
    CARDiSlotResetCount.callback = callback;
}
