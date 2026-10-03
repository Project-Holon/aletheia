/*
 * function: func_021B5498
 * address:  0x021B5498
 * packet:   pkt_ov021_021B5498
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02011330  0x02011330  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218F9C4  0x0218F9C4  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C58(void *);
extern u32 func_02011330(u32);
extern void func_0218F9C4(void *, u32 *, u32);

int func_021B5498(u32 a, u32 b)
{
    u32 v[6];
    void *x = func_02188C58(func_0201210C(func_0215A5DC((void *)b)));
    u32 k = func_02011330(a);

    v[0] = 1;
    v[1] = 1;
    v[2] = 1;
    v[3] = 1;
    v[4] = 1;
    v[5] = 1;
    func_0218F9C4(x, v, k);
    return 0;
}
