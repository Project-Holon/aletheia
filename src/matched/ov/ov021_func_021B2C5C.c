/*
 * function: func_021B2C5C
 * address:  0x021B2C5C
 * packet:   pkt_ov021_021B2C5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021B2BD8  0x021B2BD8  thumb  ov021
 *   func_021B2BEC  0x021B2BEC  thumb  ov021
 *   func_0218C69C  0x0218C69C  thumb  ov021
 * Addresses are Black-image addresses.
 */

extern unsigned int func_02159B10(void *a, void *b);
typedef unsigned int   u32;
extern int func_021B2BD8(u32 a);
extern int func_021B2BEC(int a, int b, int c, int d);
extern void func_0218C69C(int a, int b, int c, int d);

int func_021B2C5C(int a, int b)
{
    int p = (int)func_02159B10((void *)a, (void *)b);
    int q = (int)func_02159B10((void *)a, (void *)b);
    int r = (int)func_02159B10((void *)a, (void *)b);
    int h = func_021B2BD8(b);
    int t = func_021B2BEC(h, p, q, r);

    if (t) {
        func_0218C69C(h, t, 0, 2);
    }
    return 0;
}
