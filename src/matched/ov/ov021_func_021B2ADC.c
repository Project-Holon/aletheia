/*
 * function: func_021B2ADC
 * address:  0x021B2ADC
 * packet:   pkt_ov021_021B2ADC
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
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_021C0820  0x021C0820  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern int func_02159B10(int a, int b);
extern void *func_0201210C(void *p);
extern void *func_02188CB4(unsigned char *p);
extern void *func_02158F50(void *p);
extern int func_021C0820(int a, int b, int c);
extern void func_0215897C(int a, int b);

int func_021B2ADC(int a, int b)
{
    void *y = func_0215A5DC((void *)b);
    void *x = func_0215A5F4((void *)b);
    int p = func_02159B10(a, b);

    func_02188CB4(func_0201210C((void *)y));
    func_0215897C(x, func_021C0820(y, func_02158F50((void *)x), (unsigned char)p));
    return 1;
}
