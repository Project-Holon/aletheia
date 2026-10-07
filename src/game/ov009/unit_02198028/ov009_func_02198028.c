/*
 * function: func_02198028
 * address:  0x02198028
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call with a constant 0xa0 argument.
 *
 * symbols:
 *   func_0217EAB0  0x0217EAB0  arm
 */

extern void func_0217EAB0(int v);

void func_02198028(void)
{
    func_0217EAB0(0xa0);
}

