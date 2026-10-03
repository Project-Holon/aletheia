/*
 * function: func_021A231C
 * address:  0x021A231C
 * packet:   pkt_ov021_021A231C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A01A4  0x021A01A4  thumb  ov021
 */

typedef unsigned int u32;

int func_021A01A4(u32 a, u32 b);

void func_021A231C(u32 *p, int x)
{
    if (x == 1)
        func_021A01A4(p[1], 0);
}
