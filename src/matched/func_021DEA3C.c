/*
 * function: func_021DEA3C
 * address:  0x021DEA3C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DE8B4  0x021DE8B4  thumb  ov170
 *
 * Same call with the fifth argument fixed to 1.
 */



extern void func_021DE8B4(int, int, int, int, int);
void func_021DEA3C(int a, int b, int c, int d)
{
    func_021DE8B4(a, b, c, d, 1);
}
