/*
 * function: func_021B536C
 * address:  0x021B536C
 * packet:   pkt_ov021_021B536C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_021B52A4  0x021B52A4  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C58(void *p);
extern void func_021B52A4(void *, u32);

int func_021B536C(u32 a, u32 b)
{
    void *w = func_0201210C(func_0215A5DC((void *)b));

    func_021B52A4(w, (u32)func_02188C58(w));
    return 0;
}
