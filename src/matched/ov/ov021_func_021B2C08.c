/*
 * function: func_021B2C08
 * address:  0x021B2C08
 * packet:   pkt_ov021_021B2C08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021B2BD8  0x021B2BD8  thumb  ov021
 *   func_021B2BEC  0x021B2BEC  thumb  ov021
 *   func_0218C69C  0x0218C69C  thumb  ov021
 * Addresses are Black-image addresses.
 */

extern int func_02159B10(int a, int b);
extern int func_021B2BD8(int b);
extern int func_021B2BEC(int a, int b, int c, int d);
extern void func_0218C69C(int a, int b, int c, int d);

int func_021B2C08(int a, int b)
{
    int p = func_02159B10(a, b);
    int q = func_02159B10(a, b);
    int r = func_02159B10(a, b);
    int h = func_021B2BD8(b);
    int t = func_021B2BEC(h, p, q, r);

    if (t) {
        func_0218C69C(h, t, 0, 1);
        func_0218C69C(h, t, 0, 3);
    }
    return 0;
}
