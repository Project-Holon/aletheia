/*
 * function: func_021F80FC
 * address:  0x021F80FC
 * packet:   pkt_ov094_021F80FC
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
 *   d_0220AF20     0x0220AF20  data   ov094
 *   BTLV_GAUGE_StartHpChangeAnimated  0x02207B4C  thumb  ov094
 */

typedef unsigned int u32;

extern char *d_0220AF20;
extern void BTLV_GAUGE_StartHpChangeAnimated(char *p, int i, int n);

void func_021F80FC(u32 a, u32 b)
{
    BTLV_GAUGE_StartHpChangeAnimated((char *)(*(u32 *)(d_0220AF20 + 0x1a4)), a, b);
}
