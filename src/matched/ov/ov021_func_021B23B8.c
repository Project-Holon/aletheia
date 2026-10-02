/*
 * function: func_021B23B8
 * address:  0x021B23B8
 * packet:   pkt_ov021_021B23B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011330  0x02011330  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021F4134  0x021F4134  thumb  ov039
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern u32 func_02011330(u32);
extern void func_021F4134(u32, u8);

int func_021B23B8(u32 a, u32 b)
{
    void *d;
    u8 k;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    k = func_02011330(a);
    func_021F4134(d, k);
    return 0;
}
