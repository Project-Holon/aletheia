/*
 * function: func_021F81B4
 * address:  0x021F81B4
 * packet:   pkt_ov094_021F81B4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094  a4
 *   func_02207D04  0x02207D04  thumb  ov094
 */
typedef unsigned int u32;

extern char *d_0220AF20;
extern void func_02207D04(u32 obj, u32 a, u32 b);

void func_021F81B4(u32 a, u32 b)
{
    func_02207D04(*(u32 *)(d_0220AF20 + 0x1A4), a, b);
}
