/*
 * function: func_021D9FF0
 * address:  0x021D9FF0
 * packet:   pkt_021D9FF0
 * region:   ov129
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202590C  0x0202590C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef signed short   s16;
struct Grid;
extern void func_0202590C(struct Grid *g, s16 x, s16 y);

void func_021D9FF0(char *p, int a, int b)
{
    if (p != 0)
        func_0202590C((struct Grid *)p, (short)a, (short)b);
}
