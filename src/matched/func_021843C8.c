/*
 * function: func_021843C8
 * address:  0x021843C8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call on three fields of the object and the second argument.
 *
 * symbols:

 */

extern void func_0209455C(int a, int b, int c, int d);

void func_021843C8(int *p, int b)
{
    func_0209455C(p[5], p[0], p[2], b);
}

