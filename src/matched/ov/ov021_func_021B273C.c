/*
 * function: func_021B273C
 * address:  0x021B273C
 * packet:   pkt_ov021_021B273C
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
 *   func_02011330  0x02011330  thumb
 *   func_021F3A88  0x021F3A88  thumb  ov038
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern int func_02011330(int a);
extern int func_021F3A88(int a, int b, int c);
extern void func_0215897C(int a, int b);

int func_021B273C(int a, int b)
{
    void *x = func_0215A5F4((void *)b);
    void *y = func_0215A5DC((void *)b);
    int p = func_02011330(a);
    int q = func_02011330(a);
    int r = func_021F3A88(y, p, q);

    if (r == 0) {
        return 1;
    }
    func_0215897C(x, r);
    return 1;
}
