/*
 * function: func_021DD3A8
 * address:  0x021DD3A8
 * packet:   pkt_021DD3A8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021DD2D4  0x021DD2D4  arm
 *
 * Register the 0x021DEBE0 callback with func_021DD2D4: forwards the four
 * incoming register arguments and appends (4, callback).
 */

extern void func_021DD2D4(int, int, int, int, int, int);

void func_021DD3A8(int a, int b, int c, int d)
{
    func_021DD2D4(a, b, c, d, 4, 0x021DEBE0);
}

