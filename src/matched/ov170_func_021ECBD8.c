/*
 * function: func_021ECBD8
 * address:  0x021ECBD8
 * packet:   pkt_ov170_021ECBD8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC08C 0x021EC08C thumb
 */

extern void func_021EC0B0(unsigned char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC08C(unsigned char *p, int i, short a, short b, short c);

void func_021ECBD8(unsigned char *p, int i)
{
    short xy[2];
    unsigned char t;
    func_021EC0B0(p, p[0x3DF6], &xy[1], &xy[0], 0);
    t = (p + 0x3DD2)[i];
    (p + 0x3DD2)[i] = p[0x3DF6];
    p[0x3DF6] = t;
    func_021EC08C(p, p[0x3DF6], xy[1], xy[0], 0);
}
