/*
 * function: func_0215D468
 * address:  0x0215D468
 * packet:   pkt_ov010_0215D468
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02012F44  0x02012F44  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021F675C  0x021F675C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215DEF0  0x0215DEF0  thumb  ov010
 *   d_02172914     0x02172914  data
 */

typedef unsigned int u32;

typedef struct { u32 f0; u32 f4; u32 f8; } S;
typedef struct { S *p; } Ctx;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
typedef unsigned short u16;
struct BigObj;
struct Ctx;
struct Desc;
struct Obj;
extern void *func_0201210C(const struct Ctx *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u32 func_02012F44(void *);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_021F675C(void *, int);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *, int, int);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0215897C(void *, void *);
extern int func_0215DEF0(void *a, u32 *st, u32 *c);
extern const char d_02172914[];

int func_0215D468(void *a, void *b)
{
    void *t = func_0215A5F4(b);
    void *h = func_0215A5DC(b);
    void *q = func_0215A5E4(b);
    int f;
    u32 g, k;
    void *r;
    Ctx *c;
    func_0201210C(h);
    f = func_02159B10(a, b);
    g = func_02012F44(q);
    k = func_021F675C(func_0201AB28(func_02012934(q), f), 4);
    r = func_020122C0(h, 0, (void *)func_0215DEF0, 4);
    c = func_020124E8(r);
    func_02082BCC(c, 0, 4);
    c->p = func_02030734(4, 0xc, 1, d_02172914, 0xd7);
    c->p->f4 = k;
    c->p->f8 = g;
    c->p->f0 = 0;
    func_0215897C(t, r);
    return 1;
}
