/*
 * function: func_021902AC
 * address:  0x021902AC
 * packet:   pkt_ov021_021902AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02192FEC  0x02192FEC  thumb  ov021
 *
 * Unlabelled tail-call forwarder, called from func_021BEF8C.
 */

typedef unsigned short u16;

extern void func_02192FEC(int a, int b, int c);

void func_021902AC(u16 *p, int v)
{
    func_02192FEC(p[1], p[0], v);
}
