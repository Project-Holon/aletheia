/*
 * function: func_021AF130
 * address:  0x021AF130
 * packet:   pkt_ov021_021AF130
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02029620  0x02029620  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159168  0x02159168  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern unsigned int func_02159B10(void *a, void *b);
extern u32 func_02029620(void *a, u32 b, u32 c);
extern void func_0215897C(void *a, u32 b);
extern void func_02159168(int n);

int func_021AF130(u32 a, u32 b)
{
    u32 u;
    void *x;
    void *p;

    x = func_0215A5DC((void *)b);
    p = func_0215A5F4((void *)b);
    u = func_02159B10((void *)a, (void *)b);
    func_0215897C(p, func_02029620(x, u, func_02159B10((void *)a, (void *)b)));
    func_02159168(10);
    return 1;
}
