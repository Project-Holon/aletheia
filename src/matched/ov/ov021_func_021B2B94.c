/*
 * function: func_021B2B94
 * address:  0x021B2B94
 * packet:   pkt_ov021_021B2B94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_021C98F4  0x021C98F4  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern int func_0215A5F4(int a);
extern int func_0215A5DC(int a);
extern int func_02159B10(int a, int b);
extern int func_0201210C(int a);
extern int func_02158F50(int a);
extern int func_021C98F4(int a, int b, int c, int d);
extern void func_0215897C(int a, int b);

int func_021B2B94(int a, int b)
{
    int y = func_0215A5DC(b);
    int x = func_0215A5F4(b);
    int t = func_0201210C(y);
    int p = func_02159B10(a, b);

    func_0215897C(x, func_021C98F4(func_02158F50(x), y, t, p));
    return 1;
}
