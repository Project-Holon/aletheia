/*
 * function: func_021AEE28
 * address:  0x021AEE28
 * packet:   pkt_ov021_021AEE28
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
 *   func_02011330  0x02011330  thumb
 *   func_02029A04  0x02029A04  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02028BA0  0x02028BA0  thumb
 *   func_02159144  0x02159144  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern u32 func_02011330(u32 a);
extern u32 func_02029A04(void *a, u32 b, u32 c);
extern void func_0215897C(void *a, u32 b);
extern u32 func_020120F4(void *a);
extern u32 func_02012A30(u32 a);
extern void func_02028BA0(u32 a, u32 b);
extern void func_02159144(int n);

int func_021AEE28(u32 a, u32 b)
{
    void *x;
    void *y;
    u32 z;

    x = func_0215A5DC((void *)b);
    y = func_0215A5F4((void *)b);
    z = func_02029A04(x, func_02011330(a), func_02011330(a));
    func_0215897C(y, z);
    func_02028BA0(func_02012A30(func_020120F4(x)), 2);
    func_02159144(13);
    return 1;
}
