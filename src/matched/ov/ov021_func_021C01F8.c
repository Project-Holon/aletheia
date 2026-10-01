/*
 * function: func_021C01F8
 * address:  0x021C01F8
 * packet:   pkt_ov021_021C01F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_021BE8D4 with mode 0 or 1 by the flag at +0x78.
 *
 * symbols:
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_021BE8D4(u32 a0, u32 a1, int a2, int a3);

void func_021C01F8(u32 *p)
{
    u32 a = p[0];
    u32 b = p[1];

    if (p[30] != 0)
        func_021BE8D4(a, b, 0, 0);
    else
        func_021BE8D4(a, b, 1, 0);
}
