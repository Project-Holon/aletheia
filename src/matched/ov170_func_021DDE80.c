/*
 * function: func_021DDE80
 * address:  0x021DDE80
 * packet:   pkt_ov170_021DDE80
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DD25C 0x021DD25C thumb
 *   func_0202136C 0x0202136C thumb
 */

extern unsigned func_0202136C(unsigned short v);
extern unsigned func_021DD25C(unsigned char *p, unsigned short a, int box, unsigned id, unsigned v);

int func_021DDE80(unsigned char *p, unsigned a, unsigned b)
{
    if (func_021DD25C(p, b, p[0x14], 0xA9, 0) == 0)
        return 0;
    if (func_021DD25C(p, b, p[0x14], 0x4C, 0) != 0)
        return 0;
    if (func_0202136C(func_021DD25C(p, a, p[0x14], 6, 0)) == 1)
        return 0;
    if (func_0202136C(func_021DD25C(p, b, p[0x14], 6, 0)) == 1)
        return 0;
    return 1;
}
