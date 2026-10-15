/*
 * function: CARD_IsPulledOut
 * address:  0x020774B0
 * packet:   pkt_020774B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CARDiSlotResetCount  0x02150B00  data
 */

struct Data02150B00 {
    void *unk00;
    void *unk04;
};

extern struct Data02150B00 CARDiSlotResetCount;

void *CARD_IsPulledOut(void)
{
    return CARDiSlotResetCount.unk04;
}
