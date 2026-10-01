/*
 * function: func_021C0BD8
 * address:  0x021C0BD8
 * packet:   pkt_ov021_021C0BD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Releases the optional handle at +0x38.
 *
 * symbols:
 *   func_0218C860  0x0218C860  thumb  ov021
 */

extern void func_0218C860(int);

void func_021C0BD8(int *p)
{
    if (p[13] != 0)
        func_0218C860(p[14]);
}
