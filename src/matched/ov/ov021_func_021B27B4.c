/*
 * function: func_021B27B4
 * address:  0x021B27B4
 * packet:   pkt_ov021_021B27B4
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
 *   func_021F3AD0  0x021F3AD0  thumb  ov046
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern int func_02159B10(int a, int b);
extern int func_021F3AD0(void *a, int b, int c);
extern void func_0215897C(void *a, int b);

int func_021B27B4(int a, int b)
{
    void *x = func_0215A5F4((void *)b);
    void *y = func_0215A5DC((void *)b);
    int p = func_02159B10(a, b);
    int q = func_02159B10(a, b);
    int r = func_021F3AD0(y, p, q);

    if (r == 0) {
        return 1;
    }
    func_0215897C(x, r);
    return 1;
}
