/*
 * function: func_02201AF8
 * address:  0x02201AF8
 * packet:   pkt_ov094_02201AF8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02201B20  0x02201B20  thumb  ov094
 */
extern void func_02201B20(int a, int b, int c, int c1, int c2, int c3, int d, short e, int f, int g);

void func_02201AF8(int a, int b, int c, int d, short e, int f, int g)
{
    func_02201B20(a, b, c, c + 1, c + 2, c + 3, d, e, f, g);
}
