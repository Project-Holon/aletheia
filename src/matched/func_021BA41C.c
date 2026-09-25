/*
 * function: func_021BA41C
 * address:  0x021BA41C
 * packet:   pkt_021BA41C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C29F0  0x021C29F0  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

extern void func_021C29F0(int);

void func_021BA41C(int *p)
{
    int i;
    for (i = 0; i < 5; i++)
        func_021C29F0(p[i + 0x0E]);
}
