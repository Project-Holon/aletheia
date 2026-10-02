/*
 * function: func_021AF324
 * address:  0x021AF324
 * packet:   pkt_ov021_021AF324
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
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_020289B8  0x020289B8  thumb
 *   func_02029620  0x02029620  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern u32 func_020120F4(u32 a);
extern u32 func_02012A30(u32 a);
extern int func_02005F38(void);
extern int func_020289B8(u32 a);
extern u32 func_02029620(u32 a, u32 b, u32 c);
extern void func_0215897C(u32 a, u32 b);

int func_021AF324(u32 a, u32 b)
{
    u32 y;
    void *x;
    void *p;

    x = func_0215A5DC((void *)b);
    p = func_0215A5F4((void *)b);
    y = func_02012A30(func_020120F4(x));
    if (func_02005F38() == 0 && func_020289B8(y) == 0) {
        func_0215897C(p, func_02029620(x, 0, 6));
        return 1;
    }
    return 0;
}
