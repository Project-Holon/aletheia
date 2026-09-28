/*
 * function: func_021BD370
 * address:  0x021BD370
 * packet:   pkt_021BD370
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020437AC  0x020437AC  arm
 *
 * Addresses are Black-image addresses.
 */

extern void func_020437AC(int);

void func_021BD370(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        func_020437AC(p[i + 0x50]);
}
