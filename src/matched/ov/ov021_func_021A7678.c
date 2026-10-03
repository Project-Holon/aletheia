/*
 * function: func_021A7678
 * address:  0x021A7678
 * packet:   pkt_ov021_021A7678
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Initialiser for the animation object func_021A7818 steps: allocates the
 * per-track arrays and seeds each track's frame Pair and minimum key.
 * The heap id is u16 in both this signature and func_02030734's: with u32
 * the stack-argument load drops from the first instruction to after the
 * register copies (docs/idioms/a-narrow-parameter-pins-its-home-store-to-
 * the-front-of-the-prologue.md, here for a load).
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
 */

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

extern char d_021DDF7C;
extern int func_021A7A28(u32 a, u32 b);
extern void func_021A7AB0(u32 src, void *t);
extern int func_02046C94(void);
extern void *func_02030734(u16 heap, u32 size, u32 one, char *file, u32 line);
extern int func_021A7A34(u32 a, u32 b);
extern void func_02046CE0(void *dst, u32 src);
extern u32 func_021A7A88(u8 *p);
extern Pair func_021A7A40(void *t, u32 idx, u32 key);
extern u16 func_021A7A90(void *t, u32 idx);
extern s32 func_021A78EC(u32 a, void *b, u32 idx);
extern u32 func_021A797C(void *a, u32 idx);

void func_021A7678(Obj *o, u32 a, u32 b, u32 c, u16 heap)
{
    u32 i;
    s32 j;
    s32 n;
    u8 m;
    Pair t;

    o->f18 = c;
    o->f1C = func_021A7A28(a, b);
    func_021A7AB0(o->f1C, o->f20);
    o->f3C = func_02030734(heap, func_02046C94(), 1, &d_021DDF7C, 0x2c9);
    func_02046CE0(o->f3C, func_021A7A34(a, b));
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
        o->f08[i] = func_021A78EC(c, o->f3C, m);
        o->f0C[i] = func_021A797C(o->f3C, m);
    }
    o->f00 = 1;
}
