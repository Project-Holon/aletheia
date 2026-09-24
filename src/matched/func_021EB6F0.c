/*
 * function: func_021EB6F0
 * address:  0x021EB6F0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EB378  0x021EB378  thumb  ov170
 *
 * Same range call with both tail slots fixed.
 */



extern void func_021EB378(int, int, int, int, int, int);
void func_021EB6F0(int a, int b, int c)
{
    func_021EB378(a, b, c, 0, 0xf6 << 6, 0);
}
