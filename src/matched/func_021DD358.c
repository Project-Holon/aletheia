/*
 * function: func_021DD358
 * address:  0x021DD358
 * packet:   pkt_021DD358
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
 * Register the 0x021DE024 callback with func_021DD2D4: forwards the four
 * incoming register arguments and appends (0, callback).
 */

extern void func_021DD2D4(int, int, int, int, int, int);

void func_021DD358(int a, int b, int c, int d)
{
    func_021DD2D4(a, b, c, d, 0, 0x021DE024);
}

