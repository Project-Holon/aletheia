/*
 * function: func_0215CFA8
 * address:  0x0215CFA8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Passes the second argument on to both calls.
 *
 * symbols:
 *   func_0215CE9C  0x0215CE9C  arm  ov009
 *   func_0215CF14  0x0215CF14  arm  ov009
 */

extern int func_0215CE9C(int a, int b);
extern void func_0215CF14(int v, int b);

void func_0215CFA8(int a, int b)
{
    int v = func_0215CE9C(a, b);

    func_0215CF14(v, b);
}

