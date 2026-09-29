/*
 * function: func_021F8118
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
 *   d_0220AF20     0x0220AF20  data   ov094
 *   func_02207B68  0x02207B68  thumb  ov094
 */

typedef unsigned int u32;

extern char *d_0220AF20;
extern void func_02207B68(u32 obj, u32 a, u32 b);

void func_021F8118(u32 a, u32 b)
{
    func_02207B68(*(u32 *)(d_0220AF20 + 0x1a4), a, b);
}
