/*
 * function: func_0689CA3C
 * address: 0x0689CA3C
 * packet: pkt_ov095_0689CA3C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0689CA0C 0x0689CA0C thumb ov095
 *   func_0689C888 0x0689C888 thumb ov095
 *   d_0689E3D4 0x0689E3D4 data a2
 */
extern int func_0689CA0C(unsigned a);
extern int func_0689C888(unsigned a, unsigned short *b, unsigned n);
extern unsigned short d_0689E3D4[];
int func_0689CA3C(unsigned a)
{
    if (func_0689CA0C(a))
        return 1;
    return func_0689C888(a, d_0689E3D4, 20);
}
