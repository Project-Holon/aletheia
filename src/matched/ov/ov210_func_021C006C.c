/*
 * function: func_021C006C
 * address:  0x021C006C
 * packet:   pkt_ov210_021C006C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_021BFF30 0x021BFF30 thumb ov210
 *   func_0202EB04 0x0202EB04 thumb
 * Addresses are Black-image addresses.
 */

extern unsigned func_020362DC(void);
extern void func_021BFF30(int p, unsigned a, unsigned b);
extern void func_0202EB04(int h);

void func_021C006C(int p, unsigned b)
{
    unsigned r = func_020362DC();

    if ((r & 2) && !(r & 0xf1))
        return;
    func_021BFF30(p, b, 3);
    func_0202EB04(((int *)p)[0xad]);
}
