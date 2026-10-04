/*
 * function: func_021D0FE8
 * address:  0x021D0FE8
 * packet:   pkt_ov021_021D0FE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021D10A8  0x021D10A8  thumb  ov021
 *   func_021D1164  0x021D1164  thumb  ov021
 *   func_021D11B0  0x021D11B0  thumb  ov021
 */

typedef struct Work {
    void *f00;
    int f04;
    int f08;
    int f0C;
} Work;

typedef unsigned int   u32;
struct Ctx;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_021D10A8(u32 a, u32 *b, u32 *c);
extern void *func_021D1164(u32 heap, u32 v);
extern void func_021D11B0(u32 *p);

void *func_021D0FE8(void *a, int unused, int c)
{
    void *task;
    Work *w;
    int v;

    task = func_020122C0(a, 0, func_021D10A8, 0x10);
    w = func_020124E8(task);
    w->f00 = a;
    w->f04 = 0;
    w->f08 = c;
    v = (int)func_021D1164(0x8015, (u32)func_0201210C(a));
    w->f0C = v;
    func_021D11B0((u32 *)v);
    return task;
}
