/*
 * function: func_021B8C0C
 * address:  0x021B8C0C
 * packet:   pkt_ov071_021B8C0C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Each window draw is a `static inline` whose `q->f8` local gets its own
 * spill slot per inlined copy (seven slots, 0x24 down to 0xc).
 *
 * symbols:
 *   func_021B6F2C  0x021B6F2C  thumb  ov071
 *   func_021B6F40  0x021B6F40  thumb  ov071
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   _ll_sdiv       0x0209BE5C  arm
 *   func_0216FEAC  0x0216FEAC  thumb  ov010
 *   func_02045808  0x02045808  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;

typedef struct {
    u8 pad[0xc];
    u16 n;
    u16 m;
} Counts;

typedef struct {
    char pad0[0x2c];
    int f2c;
    s64 f30;
    u8 f38[1];
} Save;

typedef struct {
    Save *f0;
} C;

typedef struct {
    char pad0[8];
    void *f8;
    void *fc;
    void *f10;
    char pad14[0x14];
    void *f28;
    char pad2c[8];
    void *f34;
} Q;

typedef struct {
    void *h[6];
    struct {
        void *h;
        u8 on;
    } e[6];
} P;

extern void func_021B6F2C(C *);
extern Counts *func_021B6F40(C *);
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045770(struct Descriptor *p);
struct PrintSys;
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int func_0216FEAC(void *, void *, u8 *);
extern void func_02045808(struct U16Vec *vec);

static inline void Draw(Q *q, void *h, u32 x, u32 y, void *buf)
{
    void *w = q->f8;
    func_0201C6FC(w, (u32)func_02045770(h), x, y, buf, (u32)q->fc);
}

void func_021B8C0C(C *c, Q *q, P *d)
{
    Counts *x;
    s64 v;
    u32 hours;
    u32 min;
    void *s0;
    void *s1;

    func_021B6F2C(c);
    x = func_021B6F40(c);
    s0 = func_020457B0(0x100, 0x61);
    s1 = func_020457B0(0x100, 0x61);

    func_02045CAC(q->f28, 0xd, s0);
    Draw(q, d->e[0].h, 0, 4, s0);
    d->e[0].on = 1;

    func_02045CAC(q->f28, 5, s0);
    func_0201EFA4(q->f10, 0, x->m + x->n, 5, 0, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[1].h, 0, 0, s1);
    d->e[1].on = 1;

    func_02045CAC(q->f28, 9, s0);
    func_0201EFA4(q->f10, 0, x->m, 4, 0, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[2].h, 0, 0, s1);
    d->e[2].on = 1;

    func_02045CAC(q->f28, 8, s0);
    func_0201EFA4(q->f10, 0, x->n, 4, 0, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[2].h, 0x78, 0, s1);
    d->e[2].on = 1;

    v = c->f0->f30;
    hours = v / 60 / 60;
    if (hours > 999) {
        hours = 999;
        min = 59;
    } else {
        v -= hours * 3600;
        min = v / 60;
    }
    func_02045CAC(q->f28, 0xb, s0);
    func_0201EFA4(q->f10, 0, hours, 3, 1, 1);
    func_0201EFA4(q->f10, 1, min, 2, 2, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[3].h, 0, 0, s1);
    d->e[3].on = 1;

    func_02045CAC(q->f28, 0xc, s0);
    func_0201EFA4(q->f10, 0, c->f0->f2c, 5, 0, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[4].h, 0, 0, s1);
    d->e[4].on = 1;

    func_02045CAC(q->f28, 0xa, s0);
    func_0201EFA4(q->f10, 0, func_0216FEAC(q->f34, func_021B6F40(c), c->f0->f38), 4, 0, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[5].h, 0, 0, s1);
    d->e[5].on = 1;

    func_02045808(s0);
    func_02045808(s1);
}
