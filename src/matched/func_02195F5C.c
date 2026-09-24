/*
 * function: func_02195F5C
 * address:  0x02195F5C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call with the constant argument pair (7, 2).
 *
 * symbols:
 *   func_02195EC4  0x02195EC4  arm  ov009
 */

extern void func_02195EC4(int a, int b, int c);

void func_02195F5C(int a)
{
    func_02195EC4(a, 7, 2);
}

