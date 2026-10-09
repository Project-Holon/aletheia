/*
 * file:     wipe_sub_p06.c
 * unit:     yes
 * function: func_02022E20, func_02022E88, func_02022EA0, func_02022EF4, func_02022F0C, func_02022F24, func_02022F34, func_02022F60, func_02023464, func_020234C0, func_0202350C, func_02023568, func_020235F0, func_0202363C, func_0202368C, func_02023768, func_020237B8, func_0202384C, func_020238B4, func_0202390C
 * address:  0x02022E20
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02023B74  0x02023B74  thumb
 *   func_02023BFC  0x02023BFC  thumb
 *   func_02023C3C  0x02023C3C  thumb
 *   func_02023D18  0x02023D18  thumb
 *   func_02023D40  0x02023D40  thumb
 *   func_02023D60  0x02023D60  thumb
 *   MI_CpuFill8   0x02082BCC  arm
 *   sub_020056A0  0x020056A0  thumb
 *   func_02022518  0x02022518  thumb
 *   MI_CpuCopy8   0x02082D44  arm
 *   func_02030EAC 0x02030EAC  arm
 *   func_02023464_File  0x020A7450  data
 *   func_02030734       0x02030734  arm
 *   func_02022DCC  0x02022DCC  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02022940  0x02022940  thumb
 *   func_0202291C  0x0202291C  thumb
 *   g_dat          0x020A7450  data
 *   func_02022D70   0x02022D70  thumb
 *   func_02022D98  0x02022D98  thumb
 *   func_02022AD0  0x02022AD0  thumb
 *   func_02022568  0x02022568  thumb
 *   _ll_mul   0x0209C054  arm
 *   FX_Sqrt   0x0207C7B4  arm
 *   sub_02022D88   0x02022D88  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02023964  0x02023964  thumb
 *   func_02023A50  0x02023A50  thumb
 *   func_02023AAC  0x02023AAC  thumb
 */
#include "../../matched/include/Obj04050.h"
#include "../../matched/include/Obj00862.h"

#define REG_VCOUNT    (*(volatile u16 *)0x04000006)
#define REG_DISPSTAT  (*(volatile u16 *)0x04000004)
#define REG_WININ     (*(volatile u16 *)0x04000048)
#define REG_WINOUT    (*(volatile u16 *)0x0400004A)
#define REG_DB_WININ  (*(volatile u16 *)0x04001048)
#define REG_DB_WINOUT (*(volatile u16 *)0x0400104A)
#define LEAF(REG, MASK, VAL, EFF)            \
    if (REG_DISPSTAT & 2) {                  \
        v = (REG & MASK) | (VAL);            \
        REG = v | EFF;                       \
    }
#define SET_OUT(eng, wnd)                                        \
    if ((eng) == 0) { LEAF(REG_WINOUT, ~0x3F, wnd, 0x20) }       \
    else { LEAF(REG_DB_WINOUT, ~0x3F, wnd, 0x20) }
#define SET_IN(eng, which, wnd)                                          \
    e = (eng);                                                           \
    if ((which) == 0) {                                                  \
        if (e == 0) { LEAF(REG_WININ, ~0x3F, wnd, 0x20) }            \
        else { LEAF(REG_DB_WININ, ~0x3F, wnd, 0x20) }                    \
    } else {                                                             \
        if (e == 0) { LEAF(REG_WININ, ~0x3F00, (wnd) << 8, 0x2000) }  \
        else { LEAF(REG_DB_WININ, ~0x3F00, (wnd) << 8, 0x2000) }          \
    }
struct WipeSubElem;
struct S_02022E20;
struct Node;
struct Obj_02022E20;
struct Quad;
struct Ctx;
struct Par;
struct Wipe_02022E20;
struct Container;
struct ctl;
struct Desc;
typedef unsigned int  u32;

typedef unsigned char  u8;

typedef unsigned short u16;

struct WipeSubElem {
    u8 buf1[0xC0];
    u8 buf2[0xC0];
    u32 unk;
};

struct Half {
    u8  pad[0xC0];
    u8  rows[0xC0];
    u32 wnd;
};

struct S_02022E20 {
    struct Half h[2];
    u8 mode;
    u8 eng;
};

struct Task_0 {
    u32   f00;
    u32   f04;
    u32   f08;
    u32   phase;  /* 0x0c */
    u32   f10;
    void *obj;    /* 0x14 */
    u32   f18;
    u32   f1c;
    u32   heap;   /* 0x20 */
};

struct Obj_02022E20 {
    u8  pad00[0x30];
    u32 f30;      /* 0x30 */
    u8  pad34[0x10];
    u32 f44;      /* 0x44 */
};

struct Task_020234C0 {
    u32   f00;
    u32   f04;
    u32   f08;
    u32   phase;   /* 0x0c */
    u32   f10;     /* 0x10 */
    void *obj;     /* 0x14 */
    u32   f18;     /* 0x18 */
};

struct Obj_0202350C {
    u32 f00;
    u8  pad04[0x0c];
    u32 f10;       /* 0x10 */
    u8  pad14[0x0c];
    u32 f20;       /* 0x20 */
    u8  pad24[0x0c];
    u32 f30;       /* 0x30 */
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
    u32 f48;
};

typedef signed int     s32_0202350C;

typedef enum { Z0 } E;

typedef int          s32_02023568;

struct Obj_02023568 {
    s32_02023568 x;       /* 0x00 */
    s32_02023568 y;       /* 0x04 */
    s32_02023568 z;       /* 0x08 */
    s32_02023568 w;       /* 0x0c */
    u32 pad10[4];
    u32 f20;     /* 0x20 */
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    s32_02023568 steps;   /* 0x38 */
    s32_02023568 period;  /* 0x3c */
    s32_02023568 tick;    /* 0x40 */
    u32 f44;
    u32 f48;     /* 0x48 */
};

typedef signed char    s8;

struct S_0202350C {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0C;
    u32 f10;
    void *f14;
    u32 f18;
    u32 f1C;
    u32 f20;
};

struct Rec {
    u8  pad0[0xc];
    u32 mode;      /* +0xc */
    u32 f10;       /* +0x10 */
    void *entry;   /* +0x14 */
};

struct Entry {
    u8  pad0[0x2c];
    u32 f2c;       /* +0x2c */
    u32 f30;       /* +0x30 */
};

typedef signed short s16;

typedef int s32_0;

typedef struct Par {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    u8  f8;
    u8  f9;
    u8  fa;
    u8  fb;
} Par;

typedef struct Ctx {
    u32 pad0[3];
    u32 c;
    u32 h10;
    u32 h14;
    u32 h18;
    u32 h1c;
    u32 h20;
    u32 h24;
    u32 h28;
    u32 h2c;
    u32 h30;
    u32 h34;
} Ctx;

typedef signed int   s32_1;

struct Wipe_02022E20 {
    u32 f00;
    u32 f04;
    u32 f08;
    s32_1 f0c;          /* 0x0c  running offset */
    u32 f10;
    u32 f14;
    s32_1 f18;          /* 0x18  stride */
    s32_1 left;         /* 0x1c  countdown */
    s32_1 frame_limit;  /* 0x20 */
    s32_1 frame;        /* 0x24 */
    u32 f28;          /* 0x28 */
    u32 f2c;
    u32 f30;
    u32 f34;          /* 0x34 */
};

typedef signed long long s64;

typedef signed int   s32;

struct Wipe_0202384C {
    u32 f00;
    u32 f04;
    u32 f08;
    s32 f0c;      /* 0x0c */
    s32 f10;      /* 0x10 */
    s32 f14;      /* 0x14  half-height of the mirrored band */
};

struct Buf {
    s16 pad000[0x180];
    s16 left[0xC0];   /* 0x300 */
    s16 right[0xC0];  /* 0x480 */
};

struct Task_020238B4 {
    u32   f00;
    u32   f04;
    u32   f08;
    u32   phase;  /* 0x0c */
    u32   f10;
    void *obj;    /* 0x14 */
    u32   f18;
    u32   f1c;
    u32   f20;    /* 0x20 */
};

struct Obj_0202384C {
    u32 pad000[0xc9];
    u32 f324;     /* 0x324 */
    u32 f328;
    u32 f32c;     /* 0x32c */
};

struct Task_0202390C {
    u32   f00;
    u32   f04;
    u32   f08;
    u32   phase;  /* 0x0c */
    u32   f10;
    struct Obj_0202384C *obj;  /* 0x14 */
};

extern void func_02023B74(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02023BFC(u32 a0, u32 a1, u32 a2);
extern void func_02023C3C(u32 x2, u32 y2, u32 x1, u32 y1, int win, int sub);
extern void func_02023D18(void *obj, void *val, u32 f4, u32 f8, u32 fC);
extern void func_02023D40(void *obj, void *val, u32 f4, u32 f8);
extern void func_02023D60(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);
extern u32 sub_020056A0(void *callback, void *arg, u32 mask);
extern void func_02022518(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void func_02022568(u32 a0, u32 a1, u32 a2);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern u32 func_02030EAC(struct Node *n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02022DCC(u32 a0, void *a1, u32 a2);
extern u32 func_020307B0(void *p);
extern void func_02022940(struct Quad *cur, struct Quad *end, struct Quad *step, const u8 *from, const u8 *to, s32_0202350C frames);
extern void func_0202291C(struct Quad *dst, struct Quad *src);
extern void func_02022D70(void *a0);
extern s32_0 func_0202290C(s32_0 a, s32_0 b, s32_0 c);
extern void func_02022CEC(u32 *a0, u32 a1, u32 a2, u32 a3);
extern void * func_020056A0(void *cb, Ctx *ctx, u32 v);
extern void *func_02022D88(struct Obj_02022E20 *obj, u32 idx);
extern void func_02022D98(void *p, struct Container *c);
extern void func_02022AD0(struct ctl *ctl);
extern s32_1 FX_Sqrt(s32_1 x);
extern void *sub_02022D88(struct Obj_0202384C *obj, u32 idx);
extern void  func_02082BCC(void *p, u32 v, u32 n);
extern void func_02023964(u8 *w, struct Desc *d, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern u32 func_02023A50(struct Wipe_0202384C *w);
extern void func_02023AAC(struct Obj_0202384C *obj);
void func_02022E20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9);
int func_02022E88(int a0, int a1, int a2, int a3);
void func_02022EA0(u8 *a0, u32 a1, u32 a2, u32 a3, u32 a4);
u32 func_02022EF4(void *arg);
void func_02022F0C(u32 a0, u8 *a1, u32 a2);
void func_02022F24(u32 a0, u8 *a1, u32 a2);
void func_02022F34(void *p, struct WipeSubElem *elems);
void func_02022F60(struct S_02022E20 *p);
void func_02023464(struct Task_0 *t, u8 *cfg);
u32 func_020234C0(struct Task_020234C0 *t);
void func_0202350C(struct Obj_0202350C *obj, const u8 *cfg, u32 a2, u32 a3, u32 a4, u32 a5);
u32 func_02023568(struct Obj_02023568 *o);
void func_020235F0(struct S_0202350C *p, u32 a1);
u32 func_0202363C(struct Rec *r);
void func_0202368C(Ctx *ctx, const Par *par, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7, u32 s8);
u32 func_02023768(struct Wipe_02022E20 *w);
void func_020237B8(s32_1 a0, s32_1 a1, s32_1 a2, s32_1 a3, s32_1 *out0, s32_1 *out1);
void func_0202384C(struct Wipe_0202384C *w);
void func_020238B4(struct Task_020238B4 *t, u32 a1);
u32 func_0202390C(struct Task_0202390C *t);
extern const char func_02023464_File[];






/*
 * The family's ten-argument setup dispatcher, called from func_0202350C
 * with a wipe's configuration block already unpacked into registers and
 * stack.  The last argument selects the shape: zero takes the window
 * path (func_02023B74 / func_02023BFC / func_02023C3C) and anything else
 * takes the blend path (func_02023D18 / func_02023D40 / func_02023D60).
 *
 * The two arms are written out in full rather than factored, which is
 * what keeps them as two separate three-call sequences with their own
 * epilogues rather than one tail-merged tail
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022E20.c \
 *       --func func_02022E20 --addr 0x02022E20 --cc 1.1p1 --thumb
 */
void func_02022E20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                   u32 a7, u32 a8, u32 a9)
{
    if (a9 == 0) {
        func_02023B74(a1, 0, a3, a4);
        func_02023BFC(a2, 0, a4);
        func_02023C3C(a5, a6, a7, a8, a3, a4);
    } else {
        func_02023D18((void *)a0, (void *)a1, 0, a3, a4);
        func_02023D40((void *)a0, (void *)a2, 0, a4);
        func_02023D60((u8 *)a0, a5, a6, a7, a8, a3, a4);
    }
}





int func_02022E88(int a0, int a1, int a2, int a3){ int t0, t1; if ((unsigned int)(a3) == (unsigned int)(0)) { t0 = func_02023B48((int)(a1 + 0), (int)(a2 + 0)); return t0; } else { t1 = func_02023CFC(a0, a1, a2); return t1; } }






/*
 * Clear 0x30c bytes of an OBJ record, stamp the two attribute words a3/a4
 * and the mode bytes a1/a2.  a2 == 1 is the "no second slot" spelling: the
 * word at +0x304 is left alone and the two bytes sit at +0x308/+0x309.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022EA0.c \
 *       --func func_02022EA0 --addr 0x02022EA0 --cc 1.1p1 --thumb
 */
void func_02022EA0(u8 *a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    MI_CpuFill8(a0, 0, 0x30c);
    if (a2 == 1) {
        ((struct Obj04050 *)a0)->f180 = a3;
        ((struct Obj04050 *)a0)->f308 = a2;
        ((struct Obj04050 *)a0)->f309 = a1;
        return;
    }
    ((struct Obj04050 *)a0)->f180 = a3;
    ((struct Obj04050 *)a0)->f304 = a4;
    ((struct Obj04050 *)a0)->f308 = a2;
    ((struct Obj04050 *)a0)->f309 = a1;
}






u32 func_02022EF4(void *arg)
{
    return sub_020056A0(func_02022F34, arg, 0x3FF);
}






void func_02022F0C(u32 a0, u8 *a1, u32 a2)
{
    func_02022518(a0, (u32)a1, (u32)func_02022F60, a1[0x309], a2);
}






void func_02022F24(u32 a0, u8 *a1, u32 a2)
{
    func_02022568(a0, a1[0x309], a2);
}






void func_02022F34(void *p, struct WipeSubElem *elems)
{
    int i;

    for (i = 0; i < 2; i++) {
        MI_CpuCopy8(elems[i].buf2, elems[i].buf1, 0xC0);
    }
    func_02030EAC(p);
}




static inline void Apply(struct S_02022E20 *p, struct Half *h, int n)
{
    int v;
    int e;

    if (h->rows[n] == 0) {
        SET_OUT(p->eng, 0x3F)
        SET_IN(p->eng, h->wnd, 0x20)
    } else {
        SET_OUT(p->eng, 0x20)
        SET_IN(p->eng, h->wnd, 0x3F)
    }
}



/*
 * The per-scanline window programmer of the wipe family (1284 bytes with
 * both literal pools; no relocations at all, every pool word is a
 * hardware register address or a mask).  It reads VCOUNT, steps to the
 * next line (wrapping at 0xC0) and, for one or both of the two 0x184-byte
 * halves of the object, sets the outside-window plane mask (0x3F on a
 * clear row, 0x20 on a set one) and then the window-0 or window-1 inside
 * mask (chosen by the half's +0x180 word) on the MAIN engine when the
 * byte at +0x309 is 0 and on the SUB engine otherwise.
 *
 * Four facts closed it (the 2026-09-21 note was 140 bytes short):
 *  - The +0x309 arms are NOT identical: the zero arm writes the main
 *    engine's WININ/WINOUT at 0x04000048/0x0400004A, reached as
 *    0x04000004 + 0x44/0x46 off the already-loaded DISPSTAT address, and
 *    the other arm the sub engine's 0x04001048/0x0400104A.  With both
 *    arms spelled the same mwcc cross-jumps them, which was the whole
 *    deficit.
 *  - The +0x309 byte is read BEFORE the +0x180 word at every WININ
 *    leaf, so the engine is bound to a local ahead of the window test.
 *  - The second half's base is a NAMED local `h = &p->h[1]`: passed
 *    inline, mwcc folds p + 0x184 + n + 0xC0 into one offset and the
 *    +0x180 word into p + 0x304; the image materialises p + 0x184 once.
 *  - The body is wrapped in `if (n < 0xC0)`, which lets the exit branch
 *    reuse a leaf's branch island (`bge` to 0x02022FE6) instead of a
 *    blt/b pair; and the window-1 mask is `~0x3F00` (pool word
 *    0xFFFFC0FF), not 0xC0FF.
 */
void func_02022F60(struct S_02022E20 *p)
{
    int n;
    struct Half *h;

    n = REG_VCOUNT;
    if (n < 0xC0) {
        n = n + 1;
        if (n > 0xBF)
            n -= 0xC0;

        if (p->mode == 1) {
            Apply(p, &p->h[0], n);
        } else {
            Apply(p, &p->h[0], n);
            h = &p->h[1];
            Apply(p, h, n);
        }
    }
}




/*
 * Starts one countdown wipe: allocates the 0x4c-byte object on the heap
 * named by the low half of the task's +0x20 word, parks it at +0x14, hands
 * the task's saved parameters to func_0202350C, opens the display side
 * through func_02022E88 with mode 1 or 2 by the caller's cfg[8], and
 * advances the task's phase.  __FILE__ is "wipe_sub.c" at 0x020A7450,
 * __LINE__ 0xc7c.
 *
 * The notes carried an r4/r6 tie (o against cfg) that 3800 permuter
 * compiles never moved.  It was not an allocation tie: the func_02022E88
 * call is written out in BOTH arms of the cfg[8] test, with 1 and 2 as
 * literals, and mwcc cross-jumps the two calls, leaving `movs r1,#1 / b /
 * movs r1,#2` in front of one shared call.  A `mode` local assigned in
 * the if/else puts the test value in r1 and swaps r4/r6 for the whole
 * function (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 */
void func_02023464(struct Task_0 *t, u8 *cfg)
{
    struct Obj_02022E20 *o;

    o = func_02030734((u16)t->heap, 0x4c, 0, func_02023464_File, 0xc7c);
    t->obj = o;

    func_0202350C((struct Obj_0202350C *)o, cfg, t->f04, t->f08, t->f10, t->f18);

    if (cfg[8] == 0) {
        func_02022E88(t->f18, 1, o->f30, o->f44);
    } else {
        func_02022E88(t->f18, 2, o->f30, o->f44);
    }

    t->phase = t->phase + 1;
}




/*
 * The per-frame step of the wipe/transition task set up at 0x02023464.
 * The task block keeps its phase at +0x0c and the sub-object it allocated
 * at +0x14.  Phase 1 polls func_02023568 and, once that answers 1, hands
 * the sub-object's +0x44 field to func_02022DCC and advances; phase 2
 * frees the sub-object (func_020307B0), clears the slot and advances;
 * phase 3 is the terminal phase and is the only one that answers 1, which
 * is how the caller learns the transition has finished.  Phase 0 and any
 * other value answer 0 and do nothing.
 *
 * THE LEVER, and it is shared with func_02022A44, func_0202390C and
 * func_020234C0 (all three sat at exactly two bytes out until it was
 * found; func_0202363C in src/matched had it right all along and is where
 * it was read from).  Phase 2 assigns the result variable 1 as well,
 * immediately before its `break`:
 *
 *     case 2:  ... t->obj = 0; ret = 1; break;
 *     case 3:  ret = 1; break;
 *
 * The assignment is semantically dead -- the caller re-polls and phase 3
 * answers 1 on the next frame anyway -- but it is what makes phase 2's
 * `break` compile to a branch onto phase 3's own `movs r4, #1` instead of
 * onto the shared tail: the compiler cross-jumps the two identical
 * assignments and phase 2's exit lands on the surviving copy.  Written
 * without it the function is right in every other byte and the one branch
 * displacement is two too large.  Nothing else reaches it: 131 single
 * mutations and 3000 annealing compiles of tools/permuter.py left the
 * residue untouched (it is a cross-jumping decision, not an allocation
 * one), and every other switch spelling tried -- goto into phase 3, a
 * reordered case set, default before case 3, an if/else-if chain, an
 * added empty case -- is the same two bytes out or worse.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020234C0.c \
 *       --func func_020234C0 --addr 0x020234C0 --cc 1.1p1 --thumb
 */
u32 func_020234C0(struct Task_020234C0 *t)
{
    void *obj;
    u32   ret;

    ret = 0;
    obj = t->obj;

    switch (t->phase) {
    case 1:
        if (func_02023568((struct Obj_02023568 *)obj) == 1) {
            func_02022DCC(((struct Obj00862 *)obj)->f44, (void *)t->f18, t->f10);
            t->phase = t->phase + 1;
        }
        break;
    case 2:
        func_020307B0(obj);
        t->phase = t->phase + 1;
        t->obj = 0;
        ret = 1;
        break;
    case 3:
        ret = 1;
        break;
    default:
        break;
    }

    return ret;
}





/*
 * wipe_sub.  Closed 2026-09-24 (wave 21, lane E2) from the DIFF 2 recorded
 * in docs/notes/func_0202350C.c.txt.  Two matching levers carry it:
 *   - the zero is an enum-typed local (docs/idioms/an-enum-typed-zero-keeps-
 *     its-own-web-where-a-u32-zero-is-folded.md), read in image order k8, z,
 *     kb;
 *   - a5 is read through a volatile access placed after the f40 store and
 *     before the f44 store.  That puts a5's load (r0, the call's first
 *     argument) inside kb's live range, so kb can no longer take r0 and the
 *     zero does, while the f48 store stays last.  A plain copy of a5 is
 *     propagated back to the f48 store and does nothing (12 out).
 */
void func_0202350C(struct Obj_0202350C *obj, const u8 *cfg, u32 a2, u32 a3, u32 a4, u32 a5)
{
    u32 k8;
    u32 kb;
    E z;
    u32 v5;
    func_02022940((struct Quad *)obj, (struct Quad *)(&obj->f20), (struct Quad *)(&obj->f10), cfg, cfg + 4, a2);
    k8 = cfg[8];
    z = Z0;
    kb = cfg[0x0b];
    obj->f30 = a4;
    obj->f40 = z;
    v5 = *(volatile u32 *)&a5;
    obj->f44 = kb;
    obj->f34 = k8;
    obj->f38 = a2;
    obj->f3c = a3;
    obj->f48 = v5;
    func_02022E20(v5, cfg[9], cfg[0x0a], cfg[8], a4, cfg[0], cfg[1],
                  cfg[2], cfg[3], obj->f44);
}




/*
 * One tick of the wipe object.  +0x40 is a frame counter compared against
 * the step length at +0x3c: until it reaches the step, nothing happens
 * and the answer is 0.  On a step boundary the counter resets and the
 * remaining-step count at +0x38 is decremented; while steps remain the
 * interpolator at +0x10 is advanced (func_0202291C) and the current
 * position is pushed to func_02023D60 with each of the three 1/128
 * fixed-point coordinates at +0x00, +0x04, +0x08 rounded toward zero
 * (`(v + (v >> 6 >> 25)) >> 7`, the compiler's signed /128), plus the
 * 1/128 scalar at +0x0c.  When the last step is used up the object jumps
 * straight to its final values (+0x2c, +0x20, +0x24, +0x28) and answers
 * 1, which is what func_020234C0 waits for.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02023568.c \
 *       --func func_02023568 --addr 0x02023568 --cc 1.1p1 --thumb
 */
u32 func_02023568(struct Obj_02023568 *o)
{
    s32_02023568 n;

    n = o->tick + 1;
    o->tick = n;
    if (n >= o->period) {
        o->tick = 0;
        n = o->steps - 1;
        if (n > 0) {
            o->steps = n;
            func_0202291C((struct Quad *)o, (struct Quad *)((char *)o + 0x10));
            goto step;
        }

        func_02023D60((u8 *)o->f48, o->f20, o->f24, o->f28, o->f2c, o->f34,
                      o->f30);
        return 1;

    step:
        func_02023D60((u8 *)o->f48, o->x / 128, o->y / 128, o->z / 128,
                      o->w / 128, o->f34, o->f30);
    }

    return 0;
}





/*
 * cap: the call at +0036 to func_0202368C (0x0202368C) is the only reference
 *      to that address outside its own body, and it is inside this range, so
 *      the `label` class refuses it.  All 76 bytes and the other relocation
 *      site (func_02030734) reproduce exactly.  Promotes to EXACT the moment
 *      func_0202368C has its own manifest entry.
 */
void func_020235F0(struct S_0202350C *p, u32 a1)
{
    p->f14 = func_02030734((u16)p->f20, 0x38, 0, (const char *)0x020A7450, 0x0D63);
    func_0202368C(p->f14, (const struct Par *)a1, p->f04, p->f08, p->f10, p->f18, p->f1C, p->f20);
    p->f0C = p->f0C + 1;
}




/*
 *           reproduces (verified with match.py one), the sole unresolved
 *           relocation is the THM_CALL to func_02023768 ((struct Wipe_02022E20 *)(0202363C..0202368C
 *           has no outside witness for it)). func_02023768 itself is a real
 *           DIFF near miss (see docs/notes/func_02023768.c.txt), not an
 *           EXACT/MATCH file, so it cannot supply a "matched" witness and
 *           the two cannot be folded into one tu unit yet.
 *
 * Dispatch on the +0xc mode word of a record: mode 1 closes the record's
 * +0x14 entry (via func_02023768) and, once it reports the entry now empty,
 * frees the pair at entry+0x2c/entry+0x30 through func_02022DCC (with the
 * record's own +0x10 as the third argument) and bumps +0xc, returning 0;
 * mode 2 tears the +0x14 entry down through func_02022D70/func_020307B0,
 * clears +0x14, bumps +0xc and falls into the same "return 1" tail as mode
 * 3 (mode 3 alone has no other side effect); anything else, and mode 1
 * without the entry becoming empty, returns 0.
 */
u32 func_0202363C(struct Rec *r)
{
    void *entry = r->entry;
    u32 result = 0;

    switch (r->mode) {
    case 1:
        if (func_02023768((struct Wipe_02022E20 *)entry) == 1) {
            struct Entry *e = (struct Entry *)entry;
            func_02022DCC(e->f2c, (void *)e->f30, r->f10);
            r->mode = r->mode + 1;
        }
        break;
    case 2:
        func_02022D70(entry);
        func_020307B0(r->entry);
        r->mode = r->mode + 1;
        r->entry = 0;
        result = 1;
        break;
    case 3:
        result = 1;
        break;
    default:
        break;
    }

    return result;
}




void func_0202368C(Ctx *ctx, const Par *par, u32 a2, u32 a3,
                   u32 s5, u32 s6, u32 s7, u32 s8)
{
    u32 t;
    s16 *base;
    u32 off;
    s32_0 w;
    s32_0 h;

    t = func_0202290C(par->f0, par->f2, a2);
    func_02022CEC((u32 *)ctx, par->f8, s5, s8);
    ctx->c = par->f0 << 7;
    ctx->h30 = s6;
    ctx->h10 = par->f4;
    ctx->h14 = par->f6;
    ctx->h18 = t;
    ctx->h1c = a2;
    ctx->h20 = a3;
    ctx->h24 = 0;
    ctx->h34 = s7;
    ctx->h28 = s8;
    ctx->h2c = par->fb;
    func_0202384C((struct Wipe_0202384C *)((struct Wipe_02022E20 *)ctx));
    off = 0x3ff;
    func_020056A0(func_02022D98, ctx, off);
    base = func_02022D88((struct Obj_02022E20 *)ctx, 0);
    w = *(s16 *)((char *)base + (off - 0xff));
    off += 0x81;
    h = *(s16 *)((char *)base + off);
    func_02022E20(s6, par->f9, par->fa, par->f8,
                  s5, w, 0, h, 0xc0, ctx->h2c);
    if (par->f8 == 0) {
        func_02022E88(s6, 1, s5, ctx->h2c);
    } else {
        func_02022E88(s6, 2, s5, ctx->h2c);
    }
    func_02022518(ctx->h34, (u32)ctx, (u32)func_02022AD0, s5, s8);
}





/*
 * The per-frame poll of the wipe object built at 0x02023464, and the near
 * twin of func_02023A50 at the other end of the family: tick the frame
 * counter at +0x24 against the limit at +0x20, and on expiry step the
 * countdown at +0x1c.  A countdown still above zero advances the running
 * offset at +0x0c by the stride at +0x18, redraws through func_0202384C
 * and re-arms the callback func_02022D98 at priority 0x3FF; a countdown
 * that has reached zero finishes through func_02022568 and is the only
 * path that answers 1.
 *
 * The countdown is decremented into a LOCAL and only stored back on the
 * arm that keeps going: `n = w->left - 1; if (n > 0) { w->left = n; ... }`.
 * Written as a compound `w->left -= 1` followed by a test of the field the
 * store lands before the branch and the `ldr`/`subs`/`cmp` triple at
 * +0x1c..+0x22 becomes four instructions
 * (docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md).
 *
 * Like func_02023A50 this has exactly two exits sharing one `movs r0, #0;
 * pop {r4, pc}` tail, which is what the single trailing `return 0` after
 * the whole nest buys; a `return 0` in each arm duplicates the epilogue
 * (docs/idioms/initialise-the-result-before-the-input-or-every-arm-duplicates-the-return.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02023768.c \
 *       --func func_02023768 --addr 0x02023768 --cc 1.1p1 --thumb
 */
u32 func_02023768(struct Wipe_02022E20 *w)
{
    s32_1 f;
    s32_1 n;

    f = w->frame + 1;
    w->frame = f;
    if (f >= w->frame_limit) {
        w->frame = 0;
        n = w->left - 1;
        if (n > 0) {
            w->left = n;
            w->f0c = w->f0c + w->f18;
            func_0202384C((struct Wipe_0202384C *)w);
            sub_020056A0((void *)func_02022D98, w, 0x3FF);
        } else {
            func_02022568(w->f34, w->f08, w->f28);
            return 1;
        }
    }

    return 0;
}




/*
 * Compiled to 146 bytes; the listing's inferred 148-byte extent (to
 * 0x0202384C, the next labelled function) runs 2 bytes past what the
 * compiler actually emits here, never a byte difference: EXACT*.
 *
 * Fixed-point vertical-band test: a0/128 (signed division, the classic
 * sign-spread rounding-toward-zero idiom) is a limit compared against the
 * absolute difference of two row indices a2/a3. If the row distance
 * reaches or exceeds the limit, both outputs are zeroed and the function
 * returns immediately (void; the original never sets a return value on
 * either path). If the row distance is inside the limit, the function
 * computes
 * sqrt(round(limit'^2) - round(dist'^2)) where limit' = limit<<12 and
 * dist' = |a3-a2|<<12, each square taken in 64 bit through the compiler's
 * signed multiply helper _ll_mul (contract r0:r1 * r2:r3 -> r0:r1, see
 * docs/idioms/consecutive-ll-udiv-calls-are-one-chained-64-bit-expression.md)
 * and each rounded by +0x800 before its own >>12 splice. FX_Sqrt of the
 * difference gives a radius r (already >>12'd back to a plain s32 by the
 * asrs after the call); *out0 = a1 - r (clamped to 0) and
 * *out1 = *out0 + 2*r (clamped to 0xff).
 */
void func_020237B8(s32_1 a0, s32_1 a1, s32_1 a2, s32_1 a3, s32_1 *out0, s32_1 *out1)
{
    s32_1 limit = a0 / 128;
    s32_1 dist = a3 - a2;
    s32_1 r;

    if (dist < 0) {
        dist = -dist;
    }

    if (dist >= limit) {
        *out0 = 0;
        *out1 = 0;
        return;
    }

    {
        s64 sq_limit = (s64)(limit << 12) * (s64)(limit << 12);
        s64 sq_dist  = (s64)(dist  << 12) * (s64)(dist  << 12);
        s32_1 t0 = (s32_1)((sq_limit + 0x800) >> 12);
        s32_1 t1 = (s32_1)((sq_dist  + 0x800) >> 12);

        r = FX_Sqrt(t0 - t1) >> 12;
    }

    *out0 = a1 - r;
    if (*out0 < 0) {
        *out0 = 0;
    }
    *out1 = *out0 + r * 2;
    if (*out1 > 0xff) {
        *out1 = 0xff;
    }
}



/*
 * Rebuilds the wipe's per-scanline window table, one row for each of the
 * screen's 0xC0 lines.  sub_02022D88 hands back the buffer whose two s16
 * arrays live at +0x300 (left edge) and +0x480 (right edge).  Inside the
 * band (f14, 2*f14] the pair is mirrored from row 2*f14 - y; everywhere
 * else it is computed through func_020237B8.
 *
 * Two facts closed it (the notes stood at 98 bytes against 104):
 *  - func_020237B8's THIRD argument is w->f14, the value still live in r2
 *    from the band test, not 0.  That was the "re-load" the notes chased.
 *  - The guard is an if / else-if / else chain with the call written out
 *    in BOTH outer arms; mwcc cross-jumps the two copies, leaving the
 *    `bgt` over a `b` at +0x16 and hoisting &l into r7
 *    (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * EXACT* only because the 102-byte body is followed by two bytes of
 * alignment padding before func_020238B4.
 */
void func_0202384C(struct Wipe_0202384C *w)
{
    struct Buf *b;
    s32 y;
    s32 l;
    s32 r;

    y = 0;
    b = sub_02022D88((struct Obj_0202384C *)w, 0);

    do {
        if (y <= w->f14) {
            func_020237B8(w->f0c, w->f10, w->f14, y, (s32_1 *)&l, (s32_1 *)&r);
        } else if (y <= w->f14 * 2) {
            l = b->left[w->f14 * 2 - y];
            r = b->right[w->f14 * 2 - y];
        } else {
            func_020237B8(w->f0c, w->f10, w->f14, y, (s32_1 *)&l, (s32_1 *)&r);
        }
        b->left[y] = (s16)l;
        b->right[y] = (s16)r;
        y = y + 1;
    } while (y < 0xC0);
}



/*
 * The constructor of the wipe task whose per-frame step is func_0202390C:
 * it allocates the 0x334-byte sub-object from the task's own heap id,
 * zeroes it, hands the task's five parameter words to func_02023964 and
 * advances the phase.  The sibling of func_02023464 (which builds the
 * 0x4c-byte object at the other end of the family) and of func_020235F0.
 *
 * 0x334 is past every Thumb immediate, and it is needed TWICE (the
 * allocation size and the memset length), so it is materialised once into
 * a callee-saved register (movs #0xcd / lsls #2) and reused rather than
 * spelled at each site; writing it as a literal at both sites costs a pool
 * word.  That is what makes r6 live across the first call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020238B4.c \
 *       --func func_020238B4 --addr 0x020238B4 --cc 1.1p1 --thumb
 */
void func_020238B4(struct Task_020238B4 *t, u32 a1)
{
    t->obj = func_02030734((u16)t->f20, 0x334, 0, (const char *)0x020A7450, 0x1354);
    func_02082BCC(t->obj, 0, 0x334);
    func_02023964(t->obj, (struct Desc *)a1, t->f04, t->f08, t->f10, t->f18, t->f1c,
                  t->f20);
    t->phase = t->phase + 1;
}



/*
 * The per-frame step of a wipe task, the third of the family's four
 * identical phase machines (func_02022A44, func_020234C0, this one and
 * func_020238B4): the same switch over the task's +0x0c, the same
 * sub-object slot at +0x14, the same terminal phase 3.
 *
 * The two far fields at +0x324 and +0x32c are past every Thumb immediate
 * reach, so both are addressed with a register offset built once
 * (movs #0xc9 / lsls #2 = 0x324) and then bumped by 8 for the second
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md); reading them as
 * two separate far offsets would cost a second pool word.
 *
 * THE LEVER, and it is shared with func_02022A44, func_0202390C and
 * func_020234C0 (all three sat at exactly two bytes out until it was
 * found; func_0202363C in src/matched had it right all along and is where
 * it was read from).  Phase 2 assigns the result variable 1 as well,
 * immediately before its `break`:
 *
 *     case 2:  ... t->obj = 0; ret = 1; break;
 *     case 3:  ret = 1; break;
 *
 * The assignment is semantically dead -- the caller re-polls and phase 3
 * answers 1 on the next frame anyway -- but it is what makes phase 2's
 * `break` compile to a branch onto phase 3's own `movs r4, #1` instead of
 * onto the shared tail: the compiler cross-jumps the two identical
 * assignments and phase 2's exit lands on the surviving copy.  Written
 * without it the function is right in every other byte and the one branch
 * displacement is two too large.  Nothing else reaches it: 131 single
 * mutations and 3000 annealing compiles of tools/permuter.py left the
 * residue untouched (it is a cross-jumping decision, not an allocation
 * one), and every other switch spelling tried -- goto into phase 3, a
 * reordered case set, default before case 3, an if/else-if chain, an
 * added empty case -- is the same two bytes out or worse.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202390C.c \
 *       --func func_0202390C --addr 0x0202390C --cc 1.1p1 --thumb
 */
u32 func_0202390C(struct Task_0202390C *t)
{
    struct Obj_0202384C *obj;
    u32         ret;

    ret = 0;
    obj = t->obj;

    switch (t->phase) {
    case 1:
        if (func_02023A50((struct Wipe_0202384C *)obj) == 1) {
            func_02022DCC(obj->f324, (void *)obj->f32c, t->f10);
            t->phase = t->phase + 1;
        }
        break;
    case 2:
        func_02023AAC((struct Obj_0202384C *)obj);
        func_020307B0(t->obj);
        t->phase = t->phase + 1;
        t->obj = 0;
        ret = 1;
        break;
    case 3:
        ret = 1;
        break;
    default:
        break;
    }

    return ret;
}
