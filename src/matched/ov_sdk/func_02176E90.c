/*
 * function: func_02176E90
 * address:  0x02176E90
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Passes one and the three arguments on.
 *
 * symbols:
 *   func_02176EB0  0x02176EB0  arm  ov009
 */

extern void func_02176EB0(int a, int b, int c, int d);

void func_02176E90(int a, int b, int c)
{
    func_02176EB0(1, a, b, c);
}

