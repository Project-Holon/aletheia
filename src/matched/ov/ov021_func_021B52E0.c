/*
 * function: func_021B52E0
 * address:  0x021B52E0
 * packet:   pkt_ov021_021B52E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_021B52A4  0x021B52A4  thumb  ov021
 */

typedef unsigned int u32;

struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188C58(void *);
extern void func_021B52A4(void *, u32);

int func_021B52E0(void **p)
{
    void *w = func_0201210C(p[0]);

    func_021B52A4(w, func_02188C58(w));
    return 1;
}
