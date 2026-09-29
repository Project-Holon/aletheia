/*
 * function: func_021F81D0
 * address:  0x021F81D0
 * packet:   pkt_ov094_021F81D0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, filed as the blocker of ov093 func_021D2234 (lane S15).
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094
 *   func_02208814  0x02208814  thumb  ov094
 */

typedef unsigned int u32;

extern char *d_0220AF20;
extern void func_02208814(u32 obj, u32 a, u32 b);

void func_021F81D0(u32 a, u32 b)
{
    func_02208814(*(u32 *)(d_0220AF20 + 0x1A4), a, b);
}
