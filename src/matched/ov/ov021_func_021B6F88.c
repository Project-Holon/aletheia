/*
 * function: func_021B6F88
 * address:  0x021B6F88
 * packet:   pkt_ov021_021B6F88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012944  0x02012944  thumb
 *   func_021B6EE0  0x021B6EE0  thumb  ov021
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EEC4  0x0201EEC4  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201EED4  0x0201EED4  thumb
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

extern void *func_0215A5E4(void *a0);
extern int func_02012944(void *p);
extern void *func_021B6EE0(int a, int b);
extern void func_0201F02C(int a, int b, int c);
extern void func_0201EEC4(int a, int b, int c);
extern int func_02017E1C(void *p, int a, int b);
extern void func_0201EED4(int a, int b, void *c);
extern void func_020307B0(void *p);

int func_021B6F88(int a, int b, int c)
{
    void *m;
    int h;
    int r;

    h = func_02012944(func_0215A5E4((void *)c));
    m = func_021B6EE0(c, b);
    r = 5;
    func_0201F02C(a, 0, h);
    if (m == 0) {
        func_0201EEC4(a, 1, 0);
    } else {
        if (func_02017E1C(m, 0x4c, 0) == 1)
            r = 0xb;
        else
            func_0201EED4(a, 1, m);
        func_020307B0(m);
    }
    return r;
}
