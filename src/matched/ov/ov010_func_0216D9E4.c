/*
 * function: func_0216D9E4
 * address:  0x0216D9E4
 * packet:   pkt_ov010_0216D9E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Releases every record func_0216DD1C yields, then func_0216D4E4(c, 0x20).
 *
 * symbols:
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216DB04  0x0216DB04  thumb  ov010
 *   func_0216D4E4  0x0216D4E4  thumb  ov010
 */

typedef unsigned int u32;

struct Ctx;
struct Rec;
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern void func_0216DB04(void *r);
extern void func_0216D4E4(u32 *p, u32 v);

void func_0216D9E4(void *c)
{
    u32 iter;
    void *r;

    iter = 0;
    while (func_0216DD1C(c, (struct Rec **)(&r), &iter) == 1)
        func_0216DB04(r);
    func_0216D4E4(c, 0x20);
}
