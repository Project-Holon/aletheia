/*
 * function: func_021BA63C
 * address:  0x021BA63C
 * packet:   pkt_ov217_021BA63C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C2EE0  0x021C2EE0  data  a4
 */

typedef unsigned char u8;

extern u8 d_021C2EE0[];

void func_021BA63C(u8 *self)
{
    int i = 0;
    do {
        int o = i * 4;
        u8 *t = d_021C2EE0 + o;
        self[o + 0x2e] = t[0];
        self[o + 0x2f] = t[1];
        self[o + 0x2c] = t[2];
        self[o + 0x2d] = t[3];
        i++;
    } while (i < 3);
}
