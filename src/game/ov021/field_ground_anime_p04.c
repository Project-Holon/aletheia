/*
 * file:     field_ground_anime_p04.c
 * unit:     yes
 * function: func_021A7678, func_021A77E8, func_021A7818, func_021A78DC
 * address:  0x021A7678
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
 *   func_021A7A28  0x021A7A28  thumb  ov021
 *   func_021A7AB0  0x021A7AB0  thumb  ov021
 *   func_02046C94  0x02046C94  arm
 *   func_02030734  0x02030734  arm
 *   func_021A7A34  0x021A7A34  thumb  ov021
 *   func_02046CE0  0x02046CE0  arm
 *   func_021A7A88  0x021A7A88  thumb  ov021
 *   func_021A7A40  0x021A7A40  thumb  ov021
 *   func_021A7A90  0x021A7A90  thumb  ov021
 *   func_021A78EC  0x021A78EC  thumb  ov021
 *   func_021A797C  0x021A797C  thumb  ov021
 *   d_021DDF7C     0x021DDF7C  data  ov021  a1
 *   func_020307B0  0x020307B0  arm
 *   func_021A7A8C  0x021A7A8C  thumb  ov021
 *   func_021A79E4  0x021A79E4  thumb  ov021
 *   func_02061CA4  0x02061CA4  arm
 *   _s32_div_f     0x0209C0A4  arm
 */
#include "../../matched/include/Obj18065.h"

struct Out;
struct S02046CE0;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct Pair { u8 lo; u8 hi; } Pair;

typedef struct Obj {
    u32 f00;
    Pair *f04;
    s32 *f08;
    u32 *f0C;
    s32 *f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u8 f20[0x1C];
    void *f3C;
} Obj;

typedef struct {
    int f0;
    void *f4;
    void *f8;
    void *fc;
    void *f10;
    int pad14[2];
    int f1c;
    int pad20[7];
    void *f3c;
} E;

typedef signed short   s16;

typedef signed char    s8;

extern int func_021A7A28(u32 a, u32 b);
extern void func_021A7AB0(u32 *src, struct Out *o);
extern int func_02046C94(void);
extern void *func_02030734(u16 heap, u32 size, u32 one, char *file, u32 line);
extern int func_021A7A34(u32 a, u32 b);
extern void func_02046CE0(struct S02046CE0 *out, u32 *tag);
extern u32 func_021A7A88(u8 *p);
extern Pair func_021A7A40(void *t, u32 idx, u32 key);
extern u16 func_021A7A90(void *t, u32 idx);
extern int func_021A78EC(void *a, void *b, u32 idx);
extern u32 func_021A797C(void *a, u32 idx);
extern u32 func_020307B0(void *p);
extern u32 func_021A7A8C(u8 *p);
extern u8 *func_021A79E4(void *a, u32 idx);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
void func_021A7678(Obj *o, u32 a, u32 b, u32 c, u16 heap);
void func_021A77E8(E *e);
void func_021A7818(Obj *a, s32 dt);
int func_021A78DC(u32 a);
extern char d_021DDF7C;


/*
 * Initialiser for the animation object func_021A7818 steps: allocates the
 * per-track arrays and seeds each track's frame Pair and minimum key.
 * The heap id is u16 in both this signature and func_02030734's: with u32
 * the stack-argument load drops from the first instruction to after the
 * register copies (docs/idioms/a-narrow-parameter-pins-its-home-store-to-
 * the-front-of-the-prologue.md, here for a load).
 */
void func_021A7678(Obj *o, u32 a, u32 b, u32 c, u16 heap)
{
    u32 i;
    s32 j;
    s32 n;
    u8 m;
    Pair t;

    o->f18 = c;
    o->f1C = func_021A7A28(a, b);
    func_021A7AB0((u32 *)o->f1C, (struct Out *)o->f20);
    o->f3C = func_02030734(heap, func_02046C94(), 1, &d_021DDF7C, 0x2c9);
    func_02046CE0(o->f3C, (u32 *)func_021A7A34(a, b));
    o->f14 = func_021A7A88(o->f20);
    o->f04 = func_02030734(heap, o->f14 * 2, 1, &d_021DDF7C, 0x2d4);
    o->f08 = func_02030734(heap, o->f14 * 4, 1, &d_021DDF7C, 0x2d5);
    o->f0C = func_02030734(heap, o->f14 * 4, 1, &d_021DDF7C, 0x2d6);
    o->f10 = func_02030734(heap, o->f14 * 4, 1, &d_021DDF7C, 0x2d7);
    for (i = 0; i < o->f14; i++) {
        o->f04[i] = func_021A7A40(o->f20, i, 0);
        n = func_021A7A90(o->f20, i);
        m = o->f04[i].lo;
        for (j = 0; j < n; j++) {
            t = func_021A7A40(o->f20, i, j);
            if (m > t.lo) {
                m = t.lo;
            }
        }
        o->f08[i] = func_021A78EC((void *)c, o->f3C, m);
        o->f0C[i] = func_021A797C(o->f3C, m);
    }
    o->f00 = 1;
}


void func_021A77E8(E *e)
{
    if (e->f1c != 0) {
        func_020307B0(e->f4);
        func_020307B0(e->f8);
        func_020307B0(e->fc);
        func_020307B0(e->f10);
        func_020307B0(e->f3c);
        e->f1c = 0;
        e->f3c = 0;
    }
}


/*
 * Addresses are Black-image addresses.
 * func_021A7A40 returns its two-byte Pair by value in r0 (see its matched
 * file): the call result is spilled to a compiler temporary at sp+0x14 and
 * copied into t at sp+0x16, and every later use reads t. An inline unpack
 * of a u16 return forwards the copy and reads the temporary instead.
 */
void func_021A7818(Obj *a, s32 dt)
{
    s32 lim;
    u32 i;
    Pair t;

    if (a->f1C == 0)
        return;
    lim = func_021A7A8C(a->f20) << 12;
    for (i = 0; i < a->f14; i++) {
        a->f10[i] += dt;
        if (a->f10[i] >= lim) {
            a->f10[i] %= lim;
        } else if (a->f08[i] != -1) {
            t = func_021A7A40(a->f20, i, a->f10[i] >> 12);
            if (t.lo != a->f04[i].lo || a->f00)
                func_02061CA4(0, a->f08[i], (u32)func_021A79E4(a->f3C, t.lo), a->f0C[i]);
            a->f04[i] = t;
        }
    }
    a->f00 = 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A78DC(u32 a)
{
if (((struct Obj18065 *)((u8 *)(a)))->f1C != 0) {
    return 1;
}
return 0;
}
