/*
 * function: BTLV_EFFECT_GaugeStartHpChangeInstant
 * address:  0x021F8118
 * packet:   pkt_ov094_021F8118
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
 *   BTLV_GAUGE_StartHpChangeInstant  0x02207B68  thumb  ov094
 */

typedef unsigned int u32;

extern char *gBtlvEff;
extern void BTLV_GAUGE_StartHpChangeInstant(char *p, int i, int n);

void BTLV_EFFECT_GaugeStartHpChangeInstant(u32 a, u32 b)
{
    BTLV_GAUGE_StartHpChangeInstant((char *)(*(u32 *)(gBtlvEff + 0x1a4)), a, b);
}
