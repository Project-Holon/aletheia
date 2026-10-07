/*
 * file:     monolith_tool_p14.c
 * unit:     yes
 * function: func_021B8A70, func_021B8ABC, func_021B8ADC, func_021B8B08, func_021B8BF4, func_021B8C0C, func_021B8EC4, func_021B8ED0, func_021B8EDC
 * address:  0x021B8A70
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
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02041300  0x02041300  arm
 *   d_021BAAB8     0x021BAAB8  data  ov071  a4
 *   d_021BAAD8     0x021BAAD8  data  ov071  a4
 *   func_02040588 0x02040588 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_020452E8 0x020452E8 arm
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
 *   func_021B7070  0x021B7070  thumb  ov071
 *   func_021B70B8  0x021B70B8  thumb  ov071
 *   func_021B70C4  0x021B70C4  thumb  ov071
 */
#include "../../matched/include/Obj20741.h"
#include "../../matched/include/Obj06188.h"

struct BgTemplate;
struct Descriptor;
struct Cfg;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PrintSys;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {
    int h[6];
    struct {
        int h;
        unsigned char on;
    } e[6];
} P_021B8B08;

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
} P_021B8C0C;

extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02041300(u32 a, u32 b, u32 c, u32 d, u8 e, u8 f, u8 g);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(unsigned int);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(unsigned int);
extern u32 func_020452E8(struct Descriptor *d);
extern void *func_021B6F2C(u8 **p);
extern void *func_021B6F40(u8 **p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int func_0216FEAC(void *, void *, u8 *);
extern void func_02045808(struct U16Vec *vec);
void func_021B8A70(void);
void func_021B8ABC(void);
void func_021B8ADC(char *p);
void func_021B8B08(int unused, P_021B8B08 *p);
void func_021B8BF4(void **p);
void func_021B8C0C(C *c, Q *q, P_021B8C0C *d);
void func_021B8EC4(void *p, int a);
void func_021B8ED0(void *p);
void func_021B8EDC(void *p);
extern char d_021BAAB8[];
extern char d_021BAAD8[];


void func_021B8A70(void)
{
    func_0203FCA0(4, (const struct BgTemplate *)d_021BAAB8, 0);
    func_0203FCA0(6, (const struct BgTemplate *)d_021BAAD8, 0);
    func_02041300(4, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
}

void func_021B8ABC(void) { func_02040588(4,0); func_02040588(6,0); func_020403F4(4); func_020403F4(6); }

void func_021B8ADC(char *p) { func_020498F4((void *)(((struct Obj20741 *)p)->f30),5,6,0,0,1,0x61); func_020409B4(6); func_020409B4(4); }

/*
 * Six-window twin of func_021B86E8.
 */
void func_021B8B08(int unused, P_021B8B08 *p)
{
    extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
    extern void func_02045334(struct Descriptor *);
    extern void func_02045374(struct Cfg *cfg);
    extern void func_020409B4(u32 index);
    int i;

    p->h[0] = func_020450F0(4, 2, 0, 0x1e, 3, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[0]);
    func_02045374((struct Cfg *)p->h[0]);
    p->h[1] = func_020450F0(4, 2, 5, 0x1e, 2, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[1]);
    func_02045374((struct Cfg *)p->h[1]);
    p->h[2] = func_020450F0(4, 2, 8, 0x1e, 2, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[2]);
    func_02045374((struct Cfg *)p->h[2]);
    p->h[3] = func_020450F0(4, 2, 0xe, 0x1e, 4, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[3]);
    func_02045374((struct Cfg *)p->h[3]);
    p->h[4] = func_020450F0(4, 2, 0x10, 0x1e, 2, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[4]);
    func_02045374((struct Cfg *)p->h[4]);
    p->h[5] = func_020450F0(4, 2, 0x12, 0x1e, 2, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[5]);
    func_02045374((struct Cfg *)p->h[5]);
    for (i = 0; i < 6; i++) {
        p->e[i].h = p->h[i];
        p->e[i].on = 0;
    }
    func_020409B4(4);
}

void func_021B8BF4(void **p) { int i; for (i=0;i<6;i++) func_020452E8(p[i]); }


static inline void Draw(Q *q, void *h, u32 x, u32 y, void *buf)
{
    void *w = q->f8;
    func_0201C6FC(w, (u32)func_02045770(h), x, y, buf, (u32)q->fc);
}


/*
 * Each window draw is a `static inline` whose `q->f8` local gets its own
 * spill slot per inlined copy (seven slots, 0x24 down to 0xc).
 */
void func_021B8C0C(C *c, Q *q, P_021B8C0C *d)
{
    Counts *x;
    s64 v;
    u32 hours;
    u32 min;
    void *s0;
    void *s1;

    func_021B6F2C((u8 **)c);
    x = func_021B6F40((u8 **)c);
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
    func_0201EFA4(q->f10, 0, func_0216FEAC(q->f34, func_021B6F40((u8 **)c), c->f0->f38), 4, 0, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[5].h, 0, 0, s1);
    d->e[5].on = 1;

    func_02045808(s0);
    func_02045808(s1);
}


/*
 * Tail call to func_021B7070(word at 0x4, a + 0x48).
 */
void func_021B8EC4(void *p, int a)
{
    void func_021B7070(int *p, int *out);
    func_021B7070(((struct Obj06188 *)p)->f4, (int *)(a + 0x48));
}

/*
 * Tail call to func_021B70B8 with the pointer advanced by 0x48.  The callee
 * is an unlabelled leaf in this overlay; it is reproduced in
 * src/matched/ov071_func_021B70B8.c, whose EXACT entry attests this pool-word
 * site (`matched`).
 */
void func_021B8ED0(void *p)
{
    void func_021B70B8(void **p);
    func_021B70B8((void **)((char *)p + 0x48));
}

/*
 * Tail call to func_021B70C4((char *)p + 0x48).
 */
void func_021B8EDC(void *p)
{
    void func_021B70C4(void *);
    func_021B70C4((char *)p + 0x48);
}
