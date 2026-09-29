/*
 * function: func_0217BC94
 * address:  0x0217BC94
 * packet:   pkt_ov018_0217BC94
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B48  0x02159B48  thumb  ov010
 *   func_02159B94  0x02159B94  thumb  ov010
 *   func_02159BBC  0x02159BBC  thumb
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218CD20  0x0218CD20  thumb  ov021
 */

extern int func_02159B48(int);
extern void func_02159B94(int, int, int, int);
extern void func_02159BBC(int);
extern int func_02188C98(int);
extern void func_0218CD20(int, int, int);

void func_0217BC94(int a, int n)
{
    int r;

    if (n >= 3)
        n = 2;
    r = func_02159B48(0x15);
    func_02159B94(r, 0x76, 0x76 + 0xa1, 0x8015);
    while (n > 0) {
        func_0218CD20(a, func_02188C98(a), r);
        n--;
    }
    func_02159BBC(r);
}
