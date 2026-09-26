/*
 * function: func_021B94C0
 * address:  0x021B94C0
 * packet:   pkt_021B94C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

int func_021B94C0(u16 *p, u16 v)
{
    int i;
    for (i = 0; i < 0x12; i++)
        if (p[i] == v)
            return 1;
    return 0;
}
