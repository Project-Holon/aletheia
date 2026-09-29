/*
 * function: func_021F8628
 * address:  0x021F8628
 * packet:   pkt_ov094_021F8628
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094  a4
 *   func_021FF3F4  0x021FF3F4  thumb  ov094
 */
typedef unsigned int u32;

extern char *d_0220AF20;
extern void func_021FF3F4(u32 obj, int *p, u32 a);

void func_021F8628(u32 a, int *out, int *p)
{
    func_021FF3F4(*(u32 *)(d_0220AF20 + 0x190), p, a);
    out[0] = p[0] + 0x4B33;
    out[1] = p[1] + 0x2299;
    out[2] = p[2] + 0x99CD;
    p[1] = p[1] + 0x2000;
}
