/*
 * function: func_021BFE84
 * address:  0x021BFE84
 * packet:   pkt_ov210_021BFE84
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BEDF0 0x021BEDF0 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 * Addresses are Black-image addresses.
 */

extern void func_021BEDF0(int p, int i, int v);
extern void func_021BEE38(char *p, int idx, int a, short b, unsigned short c);

void func_021BFE84(int p, int n)
{
    func_021BEDF0(p, 8, 1);
    func_021BEE38((char *)p, 8, (short)(n * 2 + 8), 0xa8, (int)0);
}
