/*
 * function: func_021BFF30
 * address:  0x021BFF30
 * packet:   pkt_ov210_021BFF30
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     func_0202616C takes (record, a); passing a as the second argument keeps r1 live,
 *           so the 0x2B0 offset lands in r2.
 *
 * symbols:
 */

typedef unsigned char u8;

extern int func_0202616C(int a, int b);
extern void func_020413B0(int a, int b, int c, int d, int e, int f);
extern void func_02041B6C(int a);

void func_021BFF30(int p, unsigned int a, unsigned int b)
{
    u8 *t;
    int *q = (int *)p;

    if (a > 6)
        return;
    t = (u8 *)func_0202616C(q[0xac], a);
    func_020413B0(0, t[0], t[1], t[2], t[3], (u8)b);
    func_02041B6C(0);
}
