/*
 * function: func_021A5340
 * address:  0x021A5340
 * packet:   pkt_ov021_021A5340
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A5318  0x021A5318  thumb  ov021
 */

typedef unsigned int u32;

int func_021A5318(u32 *p, u32 m);

int func_021A5340(u32 *p)
{
    int r = 1;

    if (func_021A5318(p, 1) == 0)
        r = 0;
    return r;
}
