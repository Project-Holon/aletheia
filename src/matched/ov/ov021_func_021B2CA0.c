/*
 * function: func_021B2CA0
 * address:  0x021B2CA0
 * packet:   pkt_ov021_021B2CA0
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
 *   func_0218C54C  0x0218C54C  thumb  ov021
 * Addresses are Black-image addresses.
 */

extern unsigned int func_02159B10(void *a, void *b);
typedef unsigned int   u32;
extern int func_021B2BD8(u32 a);
extern int func_021B2BEC(int a, int b, int c, int d);
extern void func_0218C54C(int a, int b);

int func_021B2CA0(int a, int b)
{
    int p = (int)func_02159B10((void *)a, (void *)b);
    int q = (int)func_02159B10((void *)a, (void *)b);
    int r = (int)func_02159B10((void *)a, (void *)b);
    int s = (int)func_02159B10((void *)a, (void *)b);
    int t = func_021B2BEC(func_021B2BD8(b), p, q, r);

    if (t) {
        func_0218C54C(t, s);
    }
    return 0;
}
