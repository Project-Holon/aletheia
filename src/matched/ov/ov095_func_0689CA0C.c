/*
 * function: func_0689CA0C
 * address:  0x0689CA0C
 * packet:   pkt_ov095_0689CA0C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0689C888  0x0689C888  thumb
 *   d_0689E330     0x0689E330  data  ov095  a2
 */

extern unsigned short d_0689E330[];

int func_0689C888(unsigned a, unsigned short *b, unsigned n);

int func_0689CA0C(unsigned a)
{
    return func_0689C888(a, d_0689E330, 0xb);
}
