/*
 * function: func_021B5650
 * address:  0x021B5650
 * packet:   pkt_ov021_021B5650
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * func_021F36C8 is the ov056 slot-table lookup (src/matched/ov/ov056_func_021F36C8.c).
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218E17C  0x0218E17C  thumb  ov021
 *   func_021F36C8  0x021F36C8  thumb  ov056
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;

extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_02188C58(void *o);
extern u32 func_021F36C8(u32 idx);
extern void func_0218E17C(u32 *p, u32 v);

int func_021B5650(void *a, void *b)
{
    void *w = func_0201210C(func_0215A5DC(b));
    unsigned int k = func_02159B10(a, b);
    u32 *x = func_02188C58(w);

    func_0218E17C(x, func_021F36C8((u16)(k - 1)));
    return 0;
}
