/*
 * function: func_021BAA28
 * address:  0x021BAA28
 * packet:   pkt_021BAA28
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B1CC  0x0204B1CC  arm
 *
 * Addresses are Black-image addresses.
 */

extern void func_0204B1CC(int);

void func_021BAA28(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        func_0204B1CC(p[i + 0x1D]);
}
