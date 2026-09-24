/*
 * function: func_021EF31C
 * address:  0x021EF31C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Forward the three arguments with a literal third argument, in place of the fourth.
 */

extern void func_0202CAE4(int, int, int, int, int);

void func_021EF31C(int a0, int a1, int a2)
{
    func_0202CAE4(a0, a1, 0x74, a2, 1);
}

