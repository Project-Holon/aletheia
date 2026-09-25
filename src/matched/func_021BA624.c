/*
 * function: func_021BA624
 * address:  0x021BA624
 * packet:   pkt_021BA624
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045C04  0x02045C04  arm
 *
 * Addresses are Black-image addresses.
 */

extern void func_02045C04(int);

void func_021BA624(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        func_02045C04(p[i + 3]);
}
