/*
 * function: func_021BA8E0
 * address:  0x021BA8E0
 * packet:   pkt_021BA8E0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C0F48  0x021C0F48  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

extern void func_021C0F48(int);

void func_021BA8E0(int *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        func_021C0F48(p[i + 0x13]);
        p[i + 0x13] = 0;
    }
}
