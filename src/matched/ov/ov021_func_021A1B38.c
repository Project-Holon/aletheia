/*
 * function: func_021A1B38
 * address:  0x021A1B38
 * packet:   pkt_ov021_021A1B38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A15F4  0x021A15F4  thumb  ov021
 */

typedef unsigned int u32;

void func_021A15F4(u32 x);

void func_021A1B38(u32 *p)
{
    int i;

    if (p != 0) {
        for (i = 0; i < 2; i++)
            func_021A15F4(p[i]);
    }
}
