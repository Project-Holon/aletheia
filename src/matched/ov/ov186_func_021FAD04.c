/*
 * function: func_021FAD04
 * address:  0x021FAD04
 * packet:   pkt_021FAD04
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021FB4CC reads r0, r1, r2 (obj, x, y); this function forwards its
 * incoming r1 and r2 untouched.  Naming them keeps r1 and r2 live, which is
 * why the original tests p[0] in r3 (the old one-parameter spelling put it
 * in r1 and missed by 2 bytes).
 *
 * symbols:
 *   func_021FB4CC  0x021FB4CC  thumb  ov186
 */

typedef unsigned int   u32;
extern int func_021FB4CC(u32 *p, int a1, int a2);

int func_021FAD04(int *p, int x, int y)
{
    if (p[0] != 0)
        return func_021FB4CC((u32 *)p[2], x, y);
    return 0;
}
