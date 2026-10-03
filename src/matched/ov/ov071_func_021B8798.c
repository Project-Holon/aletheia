/*
 * function: func_021B8798
 * address:  0x021B8798
 * packet:   pkt_ov071_021B8798
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The `src + 0x18` is written in each arm (the compiler tail-merges the
 * adds at the join), the bitfield `y` is read into a local before the
 * first call, and `q->f8` goes through a local reassigned before each
 * draw call so it loads ahead of the nested call.
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02175B14  0x02175B14  thumb  ov011
 *   func_02175B34  0x02175B34  thumb  ov011
 *   func_02045EC0  0x02045EC0  arm
 *   func_021762D8  0x021762D8  thumb  ov011
 *   func_0201F250  0x0201F250  thumb
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_02045808  0x02045808  arm
 *   d_021BAA4C     0x021BAA4C  data  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 kind : 4;
    u32 b4 : 14;
    u32 b18 : 11;
    u32 b29 : 3;
    u32 pad8[4];
} Obj;

typedef struct {
    char pad0[8];
    void *f8;
    void *fc;
    void *f10;
    char pad14[8];
    void *f1c;
    char pad20[0x40];
    Obj ent[1];
} Q;

typedef struct {
    void *h[2];
    struct {
        void *h;
        u8 on;
    } e[2];
} P;

extern int d_021BAA4C[];

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
void func_021B8798(u8 **c, Q *q, P *d, u8 *r, unsigned v)
{
    extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
    extern void *func_02045770(struct Descriptor *p);
    extern void func_02043B5C(struct CharBuf *buf, u8 value);
    extern int func_02175B14(u8 *);
    extern Obj *func_02175B34(u8 *);
    extern void *func_02045EC0(struct MsgBank *bank, u32 index);
    extern void func_021762D8(Obj *, void *, void *, int);
    extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
    extern void func_0201C6FC(void *, void *, u32, u32, void *, void *);
    extern void func_02045808(struct U16Vec *vec);
    void *s;
    u8 *src;
    Obj *e;
    u32 y;
    void *t0;
    void *t1;
    void *w;

    s = func_020457B0(0x100, 0x61);
    func_02043B5C(func_02045770(d->h[0]), 0);
    func_02043B5C(func_02045770(d->h[1]), 0);
    if (v == 6 && r != 0 && func_02175B14(r + 0x1AC) == 1) {
        e = func_02175B34(r + 0x1AC);
        src = (u8 *)e + 0x18;
    } else {
        if (v > 6) {
            v = 0;
        }
        e = &q->ent[d_021BAA4C[v]];
        src = *c + 0x18;
    }
    y = e->b18;
    t0 = func_02045EC0(q->f1c, e->kind);
    t1 = func_02045EC0(q->f1c, y);
    func_021762D8(e, src, q->f10, 0x61);
    func_0201F250(q->f10, s, t1);
    w = q->f8;
    func_0201C6FC(w, func_02045770(d->e[0].h), 0, 4, t0, q->fc);
    d->e[0].on = 1;
    w = q->f8;
    func_0201C6FC(w, func_02045770(d->e[1].h), 0, 0, s, q->fc);
    d->e[1].on = 1;
    func_02045808(t0);
    func_02045808(t1);
    func_02045808(s);
}
