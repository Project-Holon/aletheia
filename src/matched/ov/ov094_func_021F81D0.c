/*
 * function: func_021F81D0
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
 *   d_0220AF20     0x0220AF20  data   ov094
 *   BTLV_GAUGE_SetStatusIcon  0x02208814  thumb  ov094
 */

typedef unsigned int u32;

extern char *d_0220AF20;
struct O;
extern void BTLV_GAUGE_SetStatusIcon(struct O *obj, int k, int idx);

void func_021F81D0(u32 a, u32 b)
{
    BTLV_GAUGE_SetStatusIcon((struct O *)(*(u32 *)(d_0220AF20 + 0x1A4)), a, b);
}
