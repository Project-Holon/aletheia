/*
 * function: func_021BF38C
 * address:  0x021BF38C
 * packet:   pkt_021BF38C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BEDF0  0x021BEDF0  thumb ov210
 */

typedef unsigned char u8;

extern void func_021BEDF0(int p, int i, int v);

void func_021BF38C(u8 *p)
{
    unsigned int i;

    func_021BEDF0((int)p, 0, 0);
    func_021BEDF0((int)p, 1, 0);
    func_021BEDF0((int)p, 9, 0);
    func_021BEDF0((int)p, 0xA, 0);
    func_021BEDF0((int)p, 0xB, 0);
    func_021BEDF0((int)p, 0xC, 0);
    func_021BEDF0((int)p, 0xD, 0);
    func_021BEDF0((int)p, 0xE, 0);
    for (i = 0; i < 0xE; i++) {
        func_021BEDF0((int)p, i + 0xF, 0);
        func_021BEDF0((int)p, i + 0x1D, 0);
        func_021BEDF0((int)p, i + 0x2B, 0);
    }
    func_021BEDF0((int)p, 7, 0);
}
