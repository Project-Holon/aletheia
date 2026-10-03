/*
 * function: func_021C5AAC
 * address:  0x021C5AAC
 * packet:   pkt_ov021_021C5AAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0216BFD4  0x0216BFD4  thumb  ov010
 *   func_021C5B58  0x021C5B58  thumb  ov021
 */

typedef unsigned int u32;

struct Big;
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *a);
extern int func_020122C0(void *a, int b, void *cb, int c);
struct Work {
    void *a;
    void *f04;
    int *f08;
    int f0C;
    int f10;
    int f14;
};

extern struct Work *func_020124E8(int a);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *a);
extern u32 func_02017E1C(void *a, u32 b, u32 c);
extern int *func_0216BFD4(int a, int b, int c, int d, int e, int f, void *g);
extern int func_021C5B58(int a, int *b, int *c);

int func_021C5AAC(void *a, int b, int c, int d)
{
    int h;
    struct Work *p;
    int e;
    void *r6;
    int x;
    int y;

    if ((int)func_0201AA18(func_02012934(func_020120F4(a))) <= c) {
        c = 0;
    }
    h = func_020122C0(a, 0, (void *)func_021C5B58, 0x18);
    p = func_020124E8(h);
    p->a = a;
    p->f04 = func_0201210C(a);
    p->f10 = b;
    p->f14 = d;
    r6 = func_020120F4(p->a);
    e = (int)func_0201AB28(func_02012934(r6), c);
    r6 = func_0200C0F0(func_02012EBC(r6));
    x = func_02017E1C((void *)e, 5, 0);
    y = func_02017E1C((void *)e, 0x6f, 0) | (func_02017E1C((void *)e, 0x6e, 0) << 8);
    p->f08 = func_0216BFD4(4, 1, x, y, 0xa, 0, r6);
    p->f0C = e;
    return h;
}
