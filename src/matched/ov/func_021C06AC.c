/*
 * function: func_021C06AC
 * address:  0x021C06AC
 * packet:   pkt_021C06AC
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

void func_021C06AC(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        func_020437AC(p[i + 0xEC]);
}
