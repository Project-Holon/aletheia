/*
 * function: func_021A1C1C
 * address:  0x021A1C1C
 * packet:   pkt_ov021_021A1C1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A1670  0x021A1670  thumb  ov021
 */

typedef unsigned int u32;

void func_021A1670(u32 x);

void func_021A1C1C(int a, u32 *p)
{
    int i;

    for (i = 0; i < 2; i++)
        func_021A1670(p[i]);
}
