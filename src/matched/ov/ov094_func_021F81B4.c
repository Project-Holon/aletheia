/*
 * function: BTLV_EFFECT_GaugeSetSlotVisible
 * address:  0x021F81B4
 * packet:   pkt_ov094_021F81B4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094  a4
 *   BTLV_GAUGE_SetSlotVisible  0x02207D04  thumb  ov094
 */
typedef unsigned int u32;

extern char *gBtlvEff;
struct O;
extern void BTLV_GAUGE_SetSlotVisible(struct O *obj, int a, int idx);

void BTLV_EFFECT_GaugeSetSlotVisible(u32 a, u32 b)
{
    BTLV_GAUGE_SetSlotVisible((struct O *)(*(u32 *)(gBtlvEff + 0x1A4)), a, b);
}
