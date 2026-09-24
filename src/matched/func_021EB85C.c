/*
 * function: func_021EB85C
 * address:  0x021EB85C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EB7E8  0x021EB7E8  thumb  ov170
 *
 * Wrap the 0x19 counter and forward it with p.
 */



extern void func_021EB7E8(unsigned char *, unsigned, int);
void func_021EB85C(unsigned char *p, unsigned i)
{
    unsigned v = i + p[0x19];
    if (v >= p[0x15])
        v -= p[0x15];
    func_021EB7E8(p, v, 0);
}
