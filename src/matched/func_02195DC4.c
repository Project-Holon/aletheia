/*
 * function: func_02195DC4
 * address:  0x02195DC4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call that supplies the second argument 1.
 *
 * symbols:
 *   func_02195980  0x02195980  arm  ov009
 */

extern void func_02195980(int a, int b);

void func_02195DC4(int a)
{
    func_02195980(a, 1);
}

