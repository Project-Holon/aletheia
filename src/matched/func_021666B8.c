/*
 * function: func_021666B8
 * address:  0x021666B8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call that supplies the constant third argument 6.
 *
 * symbols:
 *   func_02166680  0x02166680  arm  ov009
 */

extern void func_02166680(int a, int b, int c);

void func_021666B8(int a, int b)
{
    func_02166680(a, b, 6);
}

