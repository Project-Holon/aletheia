/*
 * function: func_021BD458
 * address:  0x021BD458
 * packet:   pkt_021BD458
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202570C  0x0202570C  thumb
 *
 * Addresses are Black-image addresses.
 */

extern void func_0202570C(int);

void func_021BD458(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        func_0202570C(p[i + 0x4C]);
}
