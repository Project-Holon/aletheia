/*
 * file:     wipe_sub_p10.c
 * unit:     yes
 * function: func_02022E20, func_02022E88, func_02022EA0, func_02022EF4, func_02022F0C, func_02022F24, func_02022F34, func_02022F60, func_02023464, func_020234C0
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
 *   func_02022F34 0x02022F34  thumb
 *   sub_020056A0  0x020056A0  thumb
 *   func_02022518  0x02022518  thumb
 *   func_02022F60  0x02022F60  thumb
 *   MI_CpuCopy8   0x02082D44  arm
 *   func_02030EAC 0x02030EAC  arm
 *   func_02023464_File  0x020A7450  data
 *   func_02030734       0x02030734  arm
 *   func_0202350C       0x0202350C  thumb
 *   func_02023568  0x02023568  thumb
 *   func_02022DCC  0x02022DCC  thumb
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj04050.h"
#include "../../matched/include/Obj00862.h"

struct WipeSubElem;
struct S;
struct Node;
struct Obj;
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

struct S {
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

struct Obj {
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

extern void func_02023B74(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02023BFC(u32 a0, u32 a1, u32 a2);
extern void func_02023C3C(u32 x2, u32 y2, u32 x1, u32 y1, int win, int sub);
extern void func_02023D18(void *obj, void *val, u32 f4, u32 f8, u32 fC);
extern void func_02023D40(void *obj, void *val, u32 f4, u32 f8);
extern void func_02023D60(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);
extern void func_02022F34(void *p, struct WipeSubElem *elems);
extern u32 sub_020056A0(void *callback, void *arg, u32 mask);
extern void func_02022518(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void func_02022F60(struct S *p);
extern void func_02022568(u32 a0, u32 a1, u32 a2);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void func_02030EAC(struct Node *n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0202350C(struct Obj *obj, const u8 *cfg, u32 a2, u32 a3, u32 a4, u32 a5);
extern u32 func_02023568(struct Obj *o);
extern void func_02022DCC(u32 a0, void *a1, u32 a2);
extern u32 func_020307B0(void *p);
void func_02022E20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9);
int func_02022E88(int a0, int a1, int a2, int a3);
void func_02022EA0(u8 *a0, u32 a1, u32 a2, u32 a3, u32 a4);
u32 func_02022EF4(void *arg);
void func_02022F0C(u32 a0, u8 *a1, u32 a2);
void func_02022F24(u32 a0, u8 *a1, u32 a2);
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


static inline void Apply(struct S *p, struct Half *h, int n)
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
void func_02022F60(struct S *p)
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
    struct Obj *o;

    o = func_02030734((u16)t->heap, 0x4c, 0, func_02023464_File, 0xc7c);
    t->obj = o;

    func_0202350C(o, cfg, t->f04, t->f08, t->f10, t->f18);

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
        if (func_02023568(obj) == 1) {
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
