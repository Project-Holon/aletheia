/*
 * function: func_0216D9A0
 * address:  0x0216D9A0
 * packet:   pkt_ov010_0216D9A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216DC80  0x0216DC80  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 *   func_0216D4DC  0x0216D4DC  thumb  ov010
 */

typedef unsigned int u32;

struct Ctx;
struct Rec;
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_0216DC80(void *it);
extern void func_0216DAF8(void *it);
extern void func_0216D4DC(void *map, u32 flag);

void func_0216D9A0(void *map)
{
    u32 pos = 0;
    void *it;

    while (func_0216DD1C(map, (struct Rec **)(&it), &pos) == 1) {
        if (func_0216DC80(it) == 0)
            func_0216DAF8(it);
    }
    func_0216D4DC(map, 0x20);
}
