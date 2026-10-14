/*
 * function: BTLV_EFFECT_GaugeDeleteSlot
 * address:  0x021F80E4
 * packet:   pkt_ov094_021F80E4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, filed as the blocker of ov093 callers (lane S17).
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094
 *   BTLV_GAUGE_DeleteSlotTask  0x02207960  thumb  ov094
 */

typedef unsigned int u32;

extern char *gBtlvEff;
extern void BTLV_GAUGE_DeleteSlotTask(char *p, int i);

void BTLV_EFFECT_GaugeDeleteSlot(u32 a)
{
    BTLV_GAUGE_DeleteSlotTask((char *)(*(u32 *)(gBtlvEff + 0x1a4)), a);
}
