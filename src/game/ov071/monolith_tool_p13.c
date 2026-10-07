/*
 * file:     monolith_tool_p13.c
 * unit:     yes
 * function: func_021B86BC, func_021B86E8, func_021B8750, func_021B8764, func_021B878C, func_021B8798, func_021B889C, func_021B8968, func_021B8A38
 * address:  0x021B86BC
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020498F4 0x020498F4 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_020452E8 0x020452E8 arm
 *   func_021B6E1C 0x021B6E1C thumb ov071
 *   func_021B6EEC  0x021B6EEC  thumb  ov071
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
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B8A70  0x021B8A70  thumb  ov071
 *   func_021B8ADC  0x021B8ADC  thumb  ov071
 *   func_021B8B08  0x021B8B08  thumb  ov071
 *   func_021B8EC4  0x021B8EC4  thumb  ov071
 *   func_021B8C0C  0x021B8C0C  thumb  ov071
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02040588  0x02040588  arm
 *   func_02043598  0x02043598  arm
 *   func_021B8EDC  0x021B8EDC  thumb  ov071
 *   func_020362DC  0x020362DC  arm
 *   func_02035C08  0x02035C08  arm
 *   func_021B7108  0x021B7108  thumb  ov071
 *   func_020355D8  0x020355D8  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021B7114  0x021B7114  thumb  ov071
 *   d_021BAAA4     0x021BAAA4  data  a4
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_020435F4 0x020435F4 arm
 *   func_020315D4 0x020315D4 arm
 *   func_021B8ED0 0x021B8ED0 thumb ov071
 *   func_021B8BF4 0x021B8BF4 thumb ov071
 *   func_021B8ABC 0x021B8ABC thumb ov071
 */
#include "../../matched/include/Obj20735.h"
#include "../../matched/include/Obj06189.h"
#include "../../matched/include/Obj07702.h"
#include "../../matched/include/Obj20739.h"
#include "../../matched/include/Obj20740.h"

struct Descriptor;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PrintSys;
struct Obj0203159C;
struct S020315D4;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int h[2];
    struct {
        int h;
        unsigned char on;
    } e[2];
} P_021B86E8;

typedef unsigned char  u8;

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
} Q_021B8798;

typedef struct {
    void *h[2];
    struct {
        void *h;
        u8 on;
    } e[2];
} P_021B8798;

typedef struct {
    char pad0[8];
    void *f8;
} Q_021B889C;

typedef struct {
    void **f0;
    Q_021B889C *f4;
} C_021B889C;

typedef struct {
    char pad0[8];
    void *f8;
} Q_021B8968;

typedef struct {
    void **f0;
    Q_021B8968 *f4;
    char pad8[0x24];
    u8 f2c;
    u8 f2d;
    u8 f2e;
} C_021B8968;

extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(unsigned int);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_021B6E1C(void *,void *,int,int,int,int,int,int,int);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_020435F4(unsigned int);
extern void func_020315D4(struct S020315D4 *p);
extern void func_021B8ED0(void *);
extern void func_021B8BF4(void **);
extern void func_021B8ABC(void);
void func_021B86BC(char *p);
void func_021B86E8(int unused, P_021B86E8 *p);
void func_021B8750(void **p);
void func_021B8764(void *p,char *q);
void func_021B878C(void *p);
void func_021B8798(u8 **c, Q_021B8798 *q, P_021B8798 *d, u8 *r, unsigned v);
int func_021B889C(struct Obj0203159C *a, int *b, C_021B889C *c, u8 *d);
int func_021B8968(int a, int *b, C_021B8968 *c, u8 *d);
int func_021B8A38(void *a, void *b, char *c, void **d);
extern int d_021BAA4C[];
extern char d_021BAAA4[];

void func_021B86BC(char *p) { func_020498F4((void *)(((struct Obj20735 *)p)->f30),12,2,0,0,1,0x61); func_020409B4(0); func_020409B4(2); }

void func_021B86E8(int unused, P_021B86E8 *p)
{
    extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
    extern void func_02045334(struct Descriptor *d);
    extern void func_02045374(struct Cfg *cfg);
    extern void func_020409B4(unsigned int index);
    int i;

    p->h[0] = func_020450F0(0, 2, 0, 0x1c, 3, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[0]);
    func_02045374((struct Cfg *)p->h[0]);
    p->h[1] = func_020450F0(0, 2, 5, 0x1c, 0x10, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[1]);
    func_02045374((struct Cfg *)p->h[1]);
    for (i = 0; i < 2; i++) {
        p->e[i].h = p->h[i];
        p->e[i].on = 0;
    }
    func_020409B4(0);
}

void func_021B8750(void **p) { func_020452E8(p[0]); func_020452E8(p[1]); }

void func_021B8764(void *p,char *q) { func_021B6E1C(p,q+0x18,1,0x80,0xb4,0x1c,2,0x13,0); }

/*
 * Tail call to func_021B6EEC((char *)p + 0x18).
 */
void func_021B878C(void *p)
{
    void func_021B6EEC(void **p);
    func_021B6EEC((void **)((char *)p + 0x18));
}

/*
 * The `src + 0x18` is written in each arm (the compiler tail-merges the
 * adds at the join), the bitfield `y` is read into a local before the
 * first call, and `q->f8` goes through a local reassigned before each
 * draw call so it loads ahead of the nested call.
 */
void func_021B8798(u8 **c, Q_021B8798 *q, P_021B8798 *d, u8 *r, unsigned v)
{
    extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
    extern void *func_02045770(struct Descriptor *p);
    extern void func_02043B5C(struct CharBuf *buf, u8 value);
    extern int func_02175B14(u8 *);
    extern u8 *func_02175B34(u8 *p);
    extern void *func_02045EC0(struct MsgBank *bank, u32 index);
    extern void func_021762D8(Obj *, void *, void *, int);
    extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
    extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
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
        e = (Obj *)func_02175B34(r + 0x1AC);
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
    func_0201C6FC(w, (u32)func_02045770(d->e[0].h), 0, 4, t0, (u32)q->fc);
    d->e[0].on = 1;
    w = q->f8;
    func_0201C6FC(w, (u32)func_02045770(d->e[1].h), 0, 0, s, (u32)q->fc);
    d->e[1].on = 1;
    func_02045808(t0);
    func_02045808(t1);
    func_02045808(s);
}

/*
 * Twin of func_021B8494 (six handle slots at +0x18 instead of two at +8).
 */
int func_021B889C(struct Obj0203159C *a, int *b, C_021B889C *c, u8 *d)
{
    extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
    extern void func_02082BCC(void *, int, int);
    extern void func_021B8A70(void);
    extern void func_021B8ADC(char *p);
    extern void func_021B8B08(Q_021B889C *, u8 *);
    extern void func_021B8EC4(void *p, int a);
    extern void func_021B8C0C(C_021B889C *, Q_021B889C *, u8 *);
    extern void *func_02045770(struct Descriptor *p);
    extern u32 func_0201C6C4(struct PrintSys *p, void *v);
    extern void func_02045334(struct Descriptor *d);
    extern void func_02040588(unsigned char which, unsigned char enable);
    extern void func_02043598(u32 mask, u32 enable);
    u8 *m;
    int busy;
    int i;

    switch (*b) {
    case 0:
        m = func_0203159C(a, 0x50, 0x61);
        func_02082BCC(m, 0, 0x50);
        func_021B8A70();
        func_021B8ADC((char *)c->f4);
        func_021B8B08(c->f4, m);
        func_021B8EC4(c, (int)m);
        func_021B8C0C(c, c->f4, m);
        *b = *b + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 6; i++) {
            void *q = c->f4->f8;
            u8 *s = d + i * 8;
            if (s[0x1c] != 0) {
                if (func_0201C6C4(q, (void *)((unsigned)func_02045770(((struct Obj06189 *)s)->f18))) == 0) {
                    func_02045334(((struct Obj06189 *)s)->f18);
                    s[0x1c] = 0;
                }
            }
            if ((!s[0x1c]) == 0) {
                busy = 1;
            }
        }
        if (busy == 0) {
            func_02040588(4, 1);
            func_02040588(6, 1);
            func_02043598(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * `func_020355D8(0)`/`func_020355D8(1)` in the arms of `if (t & 2)`: the
 * two calls tail-merge into one `blx` with the then-arm's `movs r0, #0`
 * falling through; every ternary or `!` spelling of the argument emits
 * `bne` to the 1 instead (same size, polarity flipped).
 */
int func_021B8968(int a, int *b, C_021B8968 *c, u8 *d)
{
    extern void *func_02045770(struct Descriptor *p);
    extern u32 func_0201C6C4(struct PrintSys *p, void *v);
    extern void func_02045334(struct Descriptor *d);
    extern void func_021B8EDC(void *);
    extern u32 func_020362DC(void);
    extern int func_02035C08(const void *p);
    extern void func_021B7108(void *);
    extern void func_020355D8(u8 v);
    extern void func_020061E4(unsigned int);
    extern int func_021B7114(void *p);
    int i;
    int t;

    if (c->f2e == 1) {
        return 1;
    }
    for (i = 0; i < 6; i++) {
        void *q = c->f4->f8;
        u8 *s = d + i * 8;
        if (s[0x1c] != 0) {
            if (func_0201C6C4(q, (void *)((unsigned)func_02045770(((struct Obj07702 *)s)->f18))) == 0) {
                func_02045334(((struct Obj07702 *)s)->f18);
                s[0x1c] = 0;
            }
        }
    }
    func_021B8EDC(d);
    switch (*b) {
    case 0:
        t = func_020362DC();
        if (func_02035C08(d_021BAAA4) != -1 || (t & 2) != 0) {
            func_021B7108(d + 0x48);
            if (t & 2) {
                func_020355D8(0);
            } else {
                func_020355D8(1);
            }
            func_020061E4(0x551);
            *b = *b + 1;
        }
        break;
    case 1:
        if (func_021B7114(d + 0x48) == 0) {
            c->f2c = 0;
            return 1;
        }
        break;
    }
    return 0;
}

int func_021B8A38(void *a, void *b, char *c, void **d)
{
    if (func_0201C6B4(((struct Obj20740 *)(*(char * *)&((struct Obj20739 *)c)->f4))->f8) == 0) return 0;
    func_020435F4(8);
    func_021B8ED0(d);
    func_021B8BF4(d);
    func_021B8ABC();
    func_020315D4(a);
    return 1;
}
