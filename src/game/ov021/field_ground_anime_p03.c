/*
 * file:     field_ground_anime_p03.c
 * unit:     yes
 * function: func_021A74F4, func_021A7508, func_021A752C, func_021A753C, func_021A75B0, func_021A75BC, func_021A75DC, func_021A7620, func_021A7654
 * address:  0x021A74F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DDF7C  0x021DDF7C  data  a4
 *   func_020307B0  0x020307B0  arm
 *   func_02046F48  0x02046F48  arm
 *   func_0206E954  0x0206E954  arm
 *   func_02047250  0x02047250  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02069C74  0x02069C74  arm
 *   func_02069E88  0x02069E88  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_021A7678  0x021A7678  thumb  ov021
 *   func_021A78DC  0x021A78DC  thumb
 *   func_021A77E8  0x021A77E8  thumb
 *   func_021A7818  0x021A7818  thumb
 */
#include "../../matched/include/Obj12091.h"

struct Tagged;
struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u32 f0;
    void *f4;
    u32 f8;
} S_021A7508;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Res { u32 x0, x1; u8 a, cnt; u16 b, c, ofs; } Res;

typedef struct Ctx { u32 flags; u32 *buf; u32 v; } Ctx;

typedef struct {
    u32 f0;
    u16 h4;
} R;

typedef struct {
    int f0;
    u32 f4;
    R *f8;
} T_021A75BC;

typedef struct {
    u32 b0 : 1;
    u32 rest : 31;
    T_021A75BC *f4;
} S_021A75BC;

typedef struct T_021A75DC { u32 n; } T_021A75DC;

typedef struct W { u8 a[0x400]; T_021A75DC *tbl; } W;

typedef struct {
    u8 b[0x40];
} E;

typedef struct {
    E e[16];
    void *p;
} S_021A7620;

typedef struct {
    E e[16];
    void *p;
} S_021A7654;

typedef signed int     s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void *func_02046F48(struct Tagged *p);
extern int func_0206E954(int p0);
extern u32 func_02047250(u32 a);
extern void func_02082BCC(u32 *p, u32 v, u32 n);
extern void func_02069C74(u32 *a, u32 b, u32 c, u32 d);
extern void func_02069E88(u32 a, u32 *b);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern void func_021A7678(u8 *a, T_021A75DC *b, u32 c, u32 d, u32 e);
extern int func_021A78DC(u32 a);
extern void func_021A77E8(E *e);
extern void func_021A7818(struct Obj *a, s32 dt);
int func_021A74F4(int *p, int i);
void func_021A7508(S_021A7508 *s, u32 b, int heap);
int func_021A752C(u32 a);
u32 func_021A753C(Ctx *s, u32 b, u32 c, u32 d);
void func_021A75B0(u32 *p);
int func_021A75BC(S_021A75BC *s, int a);
void func_021A75DC(W *w, u32 a, u32 b, u32 c, u32 heap);
void func_021A7620(S_021A7620 *s);
void func_021A7654(S_021A7654 *s, int x);
extern char d_021DDF7C[];


/*
 * Returns 0 when the word at +0x8 is zero, else p[0] + 12 * i.
 *
 * Addresses are Black-image addresses.
 */
int func_021A74F4(int *p, int i)
{
    if (p[2] != 0)
        return p[0] + 12 * i;
    return 0;
}


void func_021A7508(S_021A7508 *s, u32 b, int heap)
{
    s->f4 = func_02030734(heap, 0x80, 1, d_021DDF7C, 0x206);
    s->f8 = b;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A752C(u32 a)
{
func_020307B0((void *)(((struct Obj12091 *)((u8 *)(a)))->f4));
((struct Obj12091 *)((u8 *)(a)))->f4 = 0;
return 0;
}


static inline u32 *ent(Res *x, u32 idx)
{
    u8 *y = (u8 *)x + 8;
    if (y != 0 && idx < x->cnt)
        return (u32 *)(y + x->ofs + 4 + idx * 4);
    return 0;
}


static inline u32 res0(Res *x)
{
    u32 *z;
    if (x != 0) {
        z = ent(x, 0);
        if (z != 0)
            return (u32)x + *z;
    }
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_021A753C(Ctx *s, u32 b, u32 c, u32 d)
{
    u32 r6;
    r6 = res0((Res *)func_0206E954((u32)func_02046F48((struct Tagged *)b)));
    if (c != 0)
        c = func_02047250(c);
    else
        c = 0;
    func_02082BCC(s->buf, 0, 0x80);
    func_02069C74(s->buf, s->v, r6, c);
    func_02069E88(d, s->buf);
    s->flags = (s->flags & ~1) | 1;
    return s->flags;
}


/*
 * Unlabelled leaf: clears bit 0 of the word at +0.
 *
 * Addresses are Black-image addresses.
 */
void func_021A75B0(u32 *p)
{
    p[0] &= ~1;
}


int func_021A75BC(S_021A75BC *s, int a)
{
    T_021A75BC *t;
    if (s->b0) {
        t = s->f4;
        a = a % (t->f8->h4 << 12);
        t->f0 = a;
    }
    return a;
}


void func_021A75DC(W *w, u32 a, u32 b, u32 c, u32 heap)
{
    u32 i;
    w->tbl = (T_021A75DC *)func_0204A1BC(a, b, 0, heap);
    for (i = 0; i < w->tbl->n; i++)
        func_021A7678(&w->a[i * 64], w->tbl, i, c, heap);
}


void func_021A7620(S_021A7620 *s)
{
    int i;
    for (i = 0; i < 16; i++) {
        if (func_021A78DC((u32)(&s->e[i]))) {
            func_021A77E8(&s->e[i]);
        }
    }
    if (s->p != 0) {
        func_020307B0(s->p);
        s->p = 0;
    }
}


void func_021A7654(S_021A7654 *s, int x)
{
    int i;
    for (i = 0; i < 16; i++) {
        if (func_021A78DC((u32)(&s->e[i]))) {
            func_021A7818((struct Obj *)(&s->e[i]), x);
        }
    }
}
