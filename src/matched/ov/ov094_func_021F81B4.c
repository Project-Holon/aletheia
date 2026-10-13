/*
 * function: func_021F81B4
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
 *   d_0220AF20     0x0220AF20  data   ov094  a4
 *   BTLV_GAUGE_SetSlotVisible  0x02207D04  thumb  ov094
 */
typedef unsigned int u32;

extern char *d_0220AF20;
struct O;
extern void BTLV_GAUGE_SetSlotVisible(struct O *obj, int a, int idx);

void func_021F81B4(u32 a, u32 b)
{
    BTLV_GAUGE_SetSlotVisible((struct O *)(*(u32 *)(d_0220AF20 + 0x1A4)), a, b);
}
