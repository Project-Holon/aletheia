/*
 * function: func_0215CEFC
 * address:  0x0215CEFC
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
 *   func_0215CEB0  0x0215CEB0  arm  ov009
 */

extern int func_0215CE9C(const int *p, int b);
extern int func_0215CEB0(int a0, char *a1);

void func_0215CEFC(int a, int b)
{
    int v = func_0215CE9C((const int *)a, b);

    func_0215CEB0(v, (char *)b);
}

