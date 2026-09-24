/*
 * function: func_0217D188
 * address:  0x0217D188
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call that drops the middle arguments and keeps the last two.
 *
 * symbols:
 *   func_0218402C  0x0218402C  arm
 */

extern void func_0218402C(int d, int e);

void func_0217D188(int a, int b, int c, int d, int e)
{
    func_0218402C(d, e);
}

