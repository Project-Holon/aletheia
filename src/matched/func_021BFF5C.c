/*
 * function: func_021BFF5C
 * address:  0x021BFF5C
 * packet:   pkt_021BFF5C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C270C  0x021C270C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

extern void func_021C270C(int);

void func_021BFF5C(int *p)
{
    int i;
    for (i = 0; i < 10; i++)
        func_021C270C(p[i + 0xB5]);
}
