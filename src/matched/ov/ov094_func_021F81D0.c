/*
 * function: BTLV_EFFECT_GaugeSetStatusIcon
 * address:  0x021F81D0
 * packet:   pkt_ov094_021F81D0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf, filed as the blocker of ov093 BTL_CLIENT_StepStartEffectForMon (lane S15).
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094
 *   BTLV_GAUGE_SetStatusIcon  0x02208814  thumb  ov094
 */

typedef unsigned int u32;

extern char *gBtlvEff;
struct O;
extern void BTLV_GAUGE_SetStatusIcon(struct O *obj, int k, int idx);

void BTLV_EFFECT_GaugeSetStatusIcon(u32 a, u32 b)
{
    BTLV_GAUGE_SetStatusIcon((struct O *)(*(u32 *)(gBtlvEff + 0x1A4)), a, b);
}
