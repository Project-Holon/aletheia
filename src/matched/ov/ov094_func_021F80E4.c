/*
 * function: func_021F80E4
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
 *   d_0220AF20     0x0220AF20  data   ov094
 *   func_02207960  0x02207960  thumb  ov094
 */

typedef unsigned int u32;

extern char *d_0220AF20;
extern void func_02207960(char *p, int i);

void func_021F80E4(u32 a)
{
    func_02207960((char *)(*(u32 *)(d_0220AF20 + 0x1a4)), a);
}
