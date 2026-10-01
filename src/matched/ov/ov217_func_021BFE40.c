/*
 * function: func_021BFE40
 * address: 0x021BFE40
 * packet: pkt_ov217_021BFE40
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C3758 0x021C3758 data a1
 */
typedef unsigned char u8;
struct Entry { u8 a, b, c, d; };
extern const struct Entry d_021C3758[];
void func_021BFE40(u8 *p)
{
    int i;
    for (i = 0; i < 9; i++) {
        p[i * 4 + 0x300] = d_021C3758[i].a;
        p[i * 4 + 0x301] = d_021C3758[i].b;
        p[i * 4 + 0x2fe] = d_021C3758[i].c;
        p[i * 4 + 0x2ff] = d_021C3758[i].d;
    }
}
