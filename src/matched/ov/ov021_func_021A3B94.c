/*
 * function: func_021A3B94
 * address:  0x021A3B94
 * packet:   pkt_ov021_021A3B94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_0216D7A8(u32 h, int i);

int func_021A3B94(u32 *p)
{
    int r = 0;

    if ((u16)func_0216D7A8(p[7], 0) != 0xFFFF)
        r = 1;
    return r;
}
