/*
 * file:     wipe_sub_p09.c
 * unit:     yes
 * function: func_02022790, func_020227CC, func_02022804, func_02022830, func_0202285C, func_02022888, func_020228B4, func_020228E0, func_0202290C, func_0202291C, func_02022940, func_020229A4, func_02022A44, func_02022A88, func_02022AC4, func_02022AD0, func_02022CEC, func_02022D70, func_02022D78, func_02022D88, func_02022D98, func_02022DCC
 * address:  0x02022790
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
 *   func_020222A8  0x020222A8  thumb
 *   func_020238B4  0x020238B4  thumb
 *   func_0202390C  0x0202390C  thumb
 *   d_0209F574     0x0209F574  data
 *   g_020A73D0     0x020A73D0  data
 *   d_0209F568     0x0209F568  data
 *   func_02023464  0x02023464  thumb
 *   func_020234C0  0x020234C0  thumb
 *   func_020235F0  0x020235F0  thumb
 *   func_0202363C  0x0202363C  thumb
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020222CC  0x020222CC  thumb
 *   sub_020056A0   0x020056A0  thumb
 *   sub_02022AC4   0x02022AC4  thumb
 *   func_02022A88  0x02022A88  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_020307B0  0x020307B0  arm
 *   sub_020222CC  0x020222CC  thumb
 *   func_02022D88  0x02022D88  thumb
 *   sub_02022D88  0x02022D88  thumb
 *   MI_CpuCopy8   0x02082D44  arm
 *   func_02023CFC   0x02023CFC  thumb
 *   func_02023D18   0x02023D18  thumb
 *   func_02023D60   0x02023D60  thumb
 *   func_02023D40   0x02023D40  thumb
 */
#include "../../matched/include/Obj11726.h"
#include "../../matched/include/Obj15738.h"

struct Task;
struct S;
struct Rec;
struct AnimStep;
struct Node;
struct Obj;
struct Struct_02023CFC;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct T {
    u8  pad00[0xc];
    u32 f0c;
    u8  pad10[0x14];
    u16 f24;
    u8  pad26[2];
    u32 f28;
    u32 f2c;
};

struct G {
    u32 f00;
    u8  pad04[0xc];
    u32 f10;
    u8  pad14[0xc];
    u32 f20;
    u32 pad24;
    u32 f28;
};

struct Obj_02022804 {
    u8  pad00[0xC];
    u32 unk0C;
    u8  pad10[0x24 - 0x10];
    u16 unk24;
    u8  pad26[2];
    u32 unk28;
    u32 unk2C;
};

struct Obj_02022830 {
    u8  pad00[0xC];
    u32 unk0C;
    u8  pad10[0x24 - 0x10];
    u16 unk24;
    u8  pad26[2];
    u32 unk28;
    u32 unk2C;
};

struct Obj_0202285C {
    u8  pad00[0xC];
    u32 unk0C;
    u8  pad10[0x24 - 0x10];
    u16 unk24;
    u8  pad26[2];
    u32 unk28;
    u32 unk2C;
};

struct Obj_02022888 {
    u8  pad00[0xC];
    u32 unk0C;
    u8  pad10[0x24 - 0x10];
    u16 unk24;
    u8  pad26[2];
    u32 unk28;
    u32 unk2C;
};

struct Obj_020228B4 {
    u8  pad00[0xC];
    u32 unk0C;
    u8  pad10[0x24 - 0x10];
    u16 unk24;
    u8  pad26[2];
    u32 unk28;
    u32 unk2C;
};

struct Obj_020228E0 {
    u8  pad00[0xC];
    u32 unk0C;
    u8  pad10[0x24 - 0x10];
    u16 unk24;
    u8  pad26[2];
    u32 unk28;
    u32 unk2C;
};

typedef int           s32_0202290C;

struct Quad_0202290C {
    u32 a, b, c, d;
};

typedef int           s32_02022940;

struct Quad_02022940 {
    s32_02022940 a, b, c, d;
};

typedef signed int     s32_020229A4;

struct Obj_020229A4 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    void *f20;    /* 0x20 */
};

struct Task_020229A4 {
    u32   f00;
    u32   f04;
    u32   f08;
    u32   phase;  /* 0x0c */
    u32   f10;
    struct Obj_020229A4 *obj;  /* 0x14 */
    u32   f18;
    u32   f1c;
    u32   f20;    /* 0x20 */
    u16   f24;    /* 0x24 */
};

struct Obj_02022A44 {
    u32 pad00[8];
    u32 f20;      /* 0x20 */
};

struct Task_02022A44 {
    u32   f00;
    u32   f04;
    u32   f08;
    u32   phase;  /* 0x0c */
    u32   f10;
    struct Obj_02022A44 *obj;  /* 0x14 */
};

typedef int s32_02022A88;

struct AnimStep {
    s32_02022A88 steps;
    s32_02022A88 limit;
    s32_02022A88 counter;
    s32_02022A88 val;
    s32_02022A88 target_val;
    s32_02022A88 step_delta;
    s32_02022A88 pad18;
    s32_02022A88 scaled_val;
};

typedef signed short   s16;

typedef signed int     s32_02022AD0;

struct ctl {
    u32 pad0;
    u32 mode;
    u32 sel;
};

struct sched {
    s16 x[0xc0];
    s16 y[0xc0];
    u8  pad[0x300];
    u32 flag;
};

struct Obj {
    u8 *base;
};

typedef int            s32;

struct Container {
    void *base;
    s32 count;
};

extern void func_020222A8(u32 v);
extern void func_020238B4(struct Task *t, u32 a1);
extern u32 func_0202390C(struct Task *t);
extern void func_02023464(struct Task *t, u8 *cfg);
extern u32 func_020234C0(struct Task *t);
extern void func_020235F0(struct S *p, u32 a1);
extern u32 func_0202363C(struct Rec *r);
extern s32_0202290C func_0209C0A4(s32_0202290C shifted, s32_0202290C c);
extern void *func_02030734(u32 a0, u32 a1, int a2, const char *a3, u16 a4);
extern void  func_02082BCC(void *p, u32 v, u32 n);
extern void func_020222CC(u32 which, int brightness);
extern void *sub_020056A0(void *fn, void *arg, u32 prio);
extern void sub_02022AC4(void *unused, u8 *o);
extern int func_02022A88(struct AnimStep *p);
extern void func_02030EAC(struct Node *n);
extern u32 func_020307B0(void *p);
s32_0202290C func_0202290C(s32_0202290C a, s32_0202290C b, s32_0202290C c);
extern void sub_020222CC(u32 which, int brightness);
extern void *func_02022D88(struct Obj *obj, u32 idx);
void func_02022CEC(u32 *a0, u32 a1, u32 a2, u32 a3);
void func_02022D70(void *a0);
void func_02022D78(u8 *p);
extern void *sub_02022D88(struct Obj *obj, u32 idx);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void func_02023CFC(struct Struct_02023CFC *table, void *val, u32 idx);
extern void func_02023D18(void *obj, void *val, u32 f4, u32 f8, u32 fC);
extern void func_02023D60(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_02023D40(void *obj, void *val, u32 f4, u32 f8);
void func_02022DCC(u32 a0, void *a1, u32 a2);
extern const u32 d_0209F574[];
extern struct G g_020A73D0;
extern const u32 d_0209F568[];




/*
 * wipe.c (docs/families/wipe.h): one of the four setup steps
 * 0x0202271C/0x02022758/0x02022790/0x020227CC.  Each installs a rodata
 * word table (0x0209F568..0x0209F574, four u32 words, NOT ARM code: the
 * old headers declared them as arm functions, which is why they had no
 * witness) into one slot of the wipe state at 0x020A73D0, then hands that
 * slot to func_020238B4.  Declared as data, the table address is attested
 * sole-ref/self.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022790.c  *       --func func_02022790 --addr 0x02022790 --thumb --cc 1.1p1
 */
void func_02022790(struct T *p)
{
    if (p->f0c == 0) {
        g_020A73D0.f20 = (u32)d_0209F574;
        func_020222A8(p->f24);
        func_020238B4((struct Task *)p, (u32)(&g_020A73D0.f20));
        p->f28 = 1;
        p->f2c = 0;
    } else {
        func_0202390C((struct Task *)p);
    }
}


/*
 * wipe.c (docs/families/wipe.h): one of the four setup steps
 * 0x0202271C/0x02022758/0x02022790/0x020227CC.  Each installs a rodata
 * word table (0x0209F568..0x0209F574, four u32 words, NOT ARM code: the
 * old headers declared them as arm functions, which is why they had no
 * witness) into one slot of the wipe state at 0x020A73D0, then hands that
 * slot to func_020238B4.  Declared as data, the table address is attested
 * sole-ref/self.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020227CC.c  *       --func func_020227CC --addr 0x020227CC --thumb --cc 1.1p1
 */
void func_020227CC(struct T *p)
{
    if (p->f0c == 0) {
        g_020A73D0.f28 = (u32)d_0209F568;
        func_020222A8(p->f24);
        func_020238B4((struct Task *)p, (u32)(&g_020A73D0.f28));
        p->f28 = 0;
        p->f2c = 0;
    } else {
        func_0202390C((struct Task *)p);
    }
}


/*
 * One of a run of near-identical setup functions on one object
 * (func_02022804, func_02022830, func_0202285C, func_02022888,
 * func_020228B4, func_020228E0, each its own file so that the sibling
 * calls to the shared helpers stay outside the compared range and keep
 * attesting them; see docs/MATCHING.md, "the label class").
 *
 * Checks a delegate pointer at +0xc: when set, the whole call forwards to
 * func_020234C0 and returns.  That arm has to be written as the
 * fall-through (the guard on the complement, `== 0`, with the delegate
 * call left unconditional after it): the mirror phrasing, guarding
 * `!= 0` with the delegate inside the guarded block, lays the blocks out
 * in the opposite order and does not reproduce.  The fall-through calls
 * func_020222A8 with the object's id field at +0x24, then func_02023464
 * with the object pointer and a second, unattested pool constant
 * (0x0209F61C, written as a plain integer literal since nothing in this
 * function's own range names it as a symbol), and finally sets the pair
 * of flag words at +0x28 (to 1) and +0x2c (to 0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022804.c \
 *       --func func_02022804 --addr 0x02022804 --cc 1.1p1 --thumb
 */
void func_02022804(struct Obj_02022804 *p)
{
    if (p->unk0C == 0) {
        func_020222A8(p->unk24);
        func_02023464((struct Task *)p, (u8 *)0x0209F61C);
        p->unk28 = 1;
        p->unk2C = 0;
        return;
    }
    func_020234C0((struct Task *)p);
}


/*
 * Same shape as src/matched/func_02022804.c; kept in its own file for the
 * same reason (the sibling calls to the shared helpers have to stay
 * outside the compared range to attest them).  Sets the flag pair to
 * (0, 0) instead of (1, 0), and stashes the constant 0x0209F628.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022830.c \
 *       --func func_02022830 --addr 0x02022830 --cc 1.1p1 --thumb
 */
void func_02022830(struct Obj_02022830 *p)
{
    if (p->unk0C == 0) {
        func_020222A8(p->unk24);
        func_02023464((struct Task *)p, (u8 *)0x0209F628);
        p->unk28 = 0;
        p->unk2C = 0;
        return;
    }
    func_020234C0((struct Task *)p);
}


/*
 * Same shape as src/matched/func_02022804.c, but the helper pair is
 * func_020235F0 / func_0202363C instead of func_02023464 / func_020234C0;
 * kept in its own file for the same reason (the sibling calls to the
 * shared helpers have to stay outside the compared range to attest them).
 * Sets the flag pair to (1, 0) and stashes the constant 0x0209F6B8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202285C.c \
 *       --func func_0202285C --addr 0x0202285C --cc 1.1p1 --thumb
 */
void func_0202285C(struct Obj_0202285C *p)
{
    if (p->unk0C == 0) {
        func_020222A8(p->unk24);
        func_020235F0((struct S *)p, 0x0209F6B8);
        p->unk28 = 1;
        p->unk2C = 0;
        return;
    }
    func_0202363C((struct Rec *)p);
}


/*
 * Same shape as src/matched/func_0202285C.c; kept in its own file for the
 * same reason (the sibling calls to the shared helpers have to stay
 * outside the compared range to attest them).  Sets the flag pair to
 * (0, 0) instead of (1, 0), and stashes the constant 0x0209F6C4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022888.c \
 *       --func func_02022888 --addr 0x02022888 --cc 1.1p1 --thumb
 */
void func_02022888(struct Obj_02022888 *p)
{
    if (p->unk0C == 0) {
        func_020222A8(p->unk24);
        func_020235F0((struct S *)p, 0x0209F6C4);
        p->unk28 = 0;
        p->unk2C = 0;
        return;
    }
    func_0202363C((struct Rec *)p);
}


/*
 * Same shape as src/matched/func_02022804.c; kept in its own file for the
 * same reason (the sibling calls to the shared helpers have to stay
 * outside the compared range to attest them).  Sets the flag pair to
 * (1, 0) and stashes the constant 0x0209F5EC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020228B4.c \
 *       --func func_020228B4 --addr 0x020228B4 --cc 1.1p1 --thumb
 */
void func_020228B4(struct Obj_020228B4 *p)
{
    if (p->unk0C == 0) {
        func_020222A8(p->unk24);
        func_02023464((struct Task *)p, (u8 *)0x0209F5EC);
        p->unk28 = 1;
        p->unk2C = 0;
        return;
    }
    func_020234C0((struct Task *)p);
}


/*
 * Same shape as src/matched/func_020228B4.c; kept in its own file for the
 * same reason (the sibling calls to the shared helpers have to stay
 * outside the compared range to attest them).  Sets the flag pair to
 * (0, 0) instead of (1, 0), and stashes the constant 0x0209F640.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020228E0.c \
 *       --func func_020228E0 --addr 0x020228E0 --cc 1.1p1 --thumb
 */
void func_020228E0(struct Obj_020228E0 *p)
{
    if (p->unk0C == 0) {
        func_020222A8(p->unk24);
        func_02023464((struct Task *)p, (u8 *)0x0209F640);
        p->unk28 = 0;
        p->unk2C = 0;
        return;
    }
    func_020234C0((struct Task *)p);
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * func_0202290C is a 16-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md): it computes
 * (b - a) << 7 and forwards it with the third argument straight to
 * func_0209C0A4.  The pool word carries no Thumb bit and the branch is a
 * plain `bx` rather than `blx`, so the callee is declared `arm`; the image
 * labels it as a real function reached from 161 other call sites.
 *
 * func_0202291C is a plain four-word running-sum accumulator.  It does not
 * fold into an ldm/stm pair the way a whole-object assignment would
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md), because each field is
 * added rather than copied.
 *
 * Compiling func_0202291C on its own comes out EXACT* against `one`: its
 * own extent runs to the 2-byte linker fill in front of func_02022940,
 * which is a real function and not an unlabelled follower.  Pairing it
 * with func_0202290C in one translation unit lets `tu` lay out both
 * sections with that fill in between, which reproduces cleanly.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202290C.c \
 *       --addr 0x0202290C --thumb
 */
s32_0202290C func_0202290C(s32_0202290C a, s32_0202290C b, s32_0202290C c)
{
    return func_0209C0A4((b - a) << 7, c);
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * func_0202290C is a 16-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md): it computes
 * (b - a) << 7 and forwards it with the third argument straight to
 * func_0209C0A4.  The pool word carries no Thumb bit and the branch is a
 * plain `bx` rather than `blx`, so the callee is declared `arm`; the image
 * labels it as a real function reached from 161 other call sites.
 *
 * func_0202291C is a plain four-word running-sum accumulator.  It does not
 * fold into an ldm/stm pair the way a whole-object assignment would
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md), because each field is
 * added rather than copied.
 *
 * Compiling func_0202291C on its own comes out EXACT* against `one`: its
 * own extent runs to the 2-byte linker fill in front of func_02022940,
 * which is a real function and not an unlabelled follower.  Pairing it
 * with func_0202290C in one translation unit lets `tu` lay out both
 * sections with that fill in between, which reproduces cleanly.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202290C.c \
 *       --addr 0x0202290C --thumb
 */
void func_0202291C(struct Quad_0202290C *dst, struct Quad_0202290C *src)
{
    dst->a += src->a;
    dst->b += src->b;
    dst->c += src->c;
    dst->d += src->d;
}


/*
 * wipe.c: seeds a four-channel fade.  cur = from << 7 (fixed point), end =
 * to, step = func_0202290C(from, to, frames) per channel; called from
 * func_0202350C with (obj, &obj->f20, &obj->f10, cfg, cfg + 4, frames).
 * func_0202290C returns its tail callee's value here (the unit that
 * matched it declares it void; the caller stores r0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022940.c  *       --func func_02022940 --addr 0x02022940 --thumb --cc 1.1p1
 */
void func_02022940(struct Quad_02022940 *cur, struct Quad_02022940 *end, struct Quad_02022940 *step,
                   const u8 *from, const u8 *to, s32_02022940 frames)
{
    cur->a = from[0] << 7;
    cur->b = from[1] << 7;
    cur->c = from[2] << 7;
    cur->d = from[3] << 7;
    end->a = to[0];
    end->b = to[1];
    end->c = to[2];
    end->d = to[3];
    step->a = func_0202290C(from[0], to[0], frames);
    step->b = func_0202290C(from[1], to[1], frames);
    step->c = func_0202290C(from[2], to[2], frames);
    step->d = func_0202290C(from[3], to[3], frames);
}


/*
 * The constructor of the wipe task whose per-frame step is func_02022A44:
 * it allocates and zeroes the 0x24-byte sub-object, picks the pair of
 * start/end extents from the task's direction flag and the sentinel in
 * +0x24, fills the sub-object's eight words and registers the per-frame
 * callback sub_02022AC4 with sub_020056A0 at priority 0x80.
 *
 * The 0x7FFF in +0x24 is a "no explicit extent" sentinel: when it is
 * present the moving edge starts at 0x10 (or ends there, depending on the
 * direction flag) and the other edge starts at 0; when it is absent both
 * edges start at 0 and the moving one is biased by -0x10.  The four arms
 * are written out separately, which is what gives four `b` to the shared
 * continuation rather than a computed pair
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * Both extents reach the sub-object scaled by 128 (`lsls #7`), i.e. as
 * 24.7 fixed point, while the unscaled values stay in r7/r6 for the
 * func_0202290C call and the +0x1c store.
 *
 * The direction test is written `dir == 0` first: the image's `bne` at
 * +0x2e takes the SECOND arm, so the zero case is the fall-through and
 * therefore the source's first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  Written the
 * other way round every byte from +0x2e to +0x4a is wrong -- the four arm
 * bodies come out in the mirrored order and r6/r7 trade roles -- while
 * everything before and after stays identical, which is exactly the
 * signature that says polarity rather than shape.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020229A4.c \
 *       --func func_020229A4 --addr 0x020229A4 --cc 1.1p1 --thumb
 */
void func_020229A4(struct Task_020229A4 *t, u32 dir)
{
    struct Obj_020229A4 *o;
    s32_020229A4         a;
    s32_020229A4         b;

    t->obj = (struct Obj_020229A4 *)func_02030734((u16)t->f20, 0x24, 0, (const char *)0x020A7450,
                                         0x09AC);
    func_02082BCC(t->obj, 0, 0x24);
    o = t->obj;

    b = 0;
    if (dir == 0) {
        if (t->f24 == 0x7FFF) {
            a = 0x10;
        } else {
            a = b;
            a = a - 0x10;
        }
    } else {
        if (t->f24 == 0x7FFF) {
            a = b;
            b = 0x10;
        } else {
            a = b;
            b = b - 0x10;
        }
    }

    func_020222CC(t->f10, a);

    o->f00 = t->f04;
    o->f04 = t->f08;
    o->f08 = 0;
    o->f0c = a << 7;
    o->f10 = b << 7;
    o->f14 = func_0202290C(a, b, t->f04);
    o->f18 = t->f10;
    o->f1c = a;
    t->phase = t->phase + 1;
    o->f20 = sub_020056A0((void *)sub_02022AC4, o, 0x80);
}


/*
 * The per-frame step of a wipe task, the sibling of func_020234C0 at the
 * other end of the family: the same four-phase switch over the task's
 * +0x0c, the same sub-object slot at +0x14, and the same terminal phase 3
 * that is the only one to answer 1.  Phase 1 polls func_02022A88 and
 * advances when it answers 1; phase 2 releases the sub-object's +0x20
 * handle through func_02030EAC, frees the object itself, clears the slot
 * and advances.
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
 *   python tools/match.py one --src src/matched/func_02022A44.c \
 *       --func func_02022A44 --addr 0x02022A44 --cc 1.1p1 --thumb
 */
u32 func_02022A44(struct Task_02022A44 *t)
{
    struct Obj_02022A44 *obj;
    u32         ret;

    ret = 0;
    obj = t->obj;

    switch (t->phase) {
    case 1:
        if (func_02022A88((struct AnimStep *)obj) == 1) {
            t->phase = t->phase + 1;
        }
        break;
    case 2:
        func_02030EAC((struct Node *)obj->f20);
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



int func_02022A88(struct AnimStep *p)
{
    int ret = 0;

    p->counter++;
    if (p->counter >= p->limit) {
        p->counter = 0;
        if (p->steps - 1 > 0) {
            p->steps--;
            p->val += p->step_delta;
        } else {
            p->val = p->target_val;
            ret = 1;
        }

        p->scaled_val = p->val / 128;
    }

    return ret;
}


/*
 * Re-verified 2026-09-23: the MATCH park had turned DIFF (one byte) under
 * the new extents because its header named the callee 0x020202CC.  The
 * pool word at 0x02022ACC is 0x020222CD: the callee is 0x020222CC
 * (src/matched/func_020222CC.c, labelled with sixteen outside branches),
 * so the old "unlabelled leaf, sole reference" blocker was a digit slip.
 * With the address corrected the site resolves `label` and the file is
 * EXACT.
 *
 * An unlabelled leaf forwarder: it drops its own first argument and calls
 * sub_020222CC with the two pointer fields at +0x18 and +0x1c of its
 * second.  The ordinary tail-call form, a pool word and a `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02022AC4.c \
 *       --func sub_02022AC4 --addr 0x02022AC4 --cc 1.1p1 --thumb
 */
void sub_02022AC4(void *unused, u8 *o)
{
    sub_020222CC((u32)(((struct Obj11726 *)o)->f18), (int)(((struct Obj11726 *)o)->f1C));
}


#define REG_VCOUNT  (*(volatile u16 *)0x04000006)

#define REG_A       ((volatile u16 *)0x04000004)

#define REG_B       ((volatile u16 *)0x04001040)

#define REG_C       ((volatile u16 *)0x04001042)


/*
 * The four pool words at 0x02022CDC are 0x04000006, 0x04000004,
 * 0x04001040 and 0x04001042: I/O register addresses, written as cast
 * constants, not relocations.
 *
 * The 8-byte residue docs/notes/func_02022AD0.c.txt records at +0x00CC
 * is closed by ONE statement order: block two must read ctl->sel BEFORE
 * its three array reads, exactly as blocks one and three do.  With
 * sel read last (the note's C) the 0x180 constant is hoisted one slot
 * early and the y[] address lands in r0 instead of r1; with sel first
 * the block is byte-identical to its two neighbours.
 */
void func_02022AD0(struct ctl *ctl)
{
    struct sched *p;
    s32_02022AD0 line;
    s32_02022AD0 next;
    s32_02022AD0 x;
    s32_02022AD0 y;
    u32 flag;
    u32 sel;

    line = REG_VCOUNT;
    if (line >= 0xc0) {
        return;
    }
    next = line + 1;
    if (next > 0xbf) {
        next -= 0xc0;
    }

    if (ctl->mode == 1) {
        p = func_02022D88((struct Obj *)ctl, 0);
        sel = ctl->sel;
        y = p->y[next];
        x = p->x[next];
        flag = p->flag;
        if (flag == 0) {
            if (sel == 0) {
                if ((REG_A[0] & 2) != 0) {
                    REG_A[0x1e] = ((x << 8) & 0xff00) | (u32)(u8)y;
                    REG_A[0x20] = 0xc0;
                }
            } else {
                if ((REG_A[0] & 2) != 0) {
                    REG_B[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                    REG_B[2] = 0xc0;
                }
            }
        } else {
            if (sel == 0) {
                if ((REG_A[0] & 2) != 0) {
                    REG_A[0x1f] = ((x << 8) & 0xff00) | (u32)(u8)y;
                    REG_A[0x21] = 0xc0;
                }
            } else {
                if ((REG_A[0] & 2) != 0) {
                    REG_C[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                    REG_C[2] = 0xc0;
                }
            }
        }
        return;
    }

    p = func_02022D88((struct Obj *)ctl, 0);
    sel = ctl->sel;
    y = p->y[next];
    x = p->x[next];
    flag = p->flag;
    if (flag == 0) {
        if (sel == 0) {
            if ((REG_A[0] & 2) != 0) {
                REG_A[0x1e] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_A[0x20] = 0xc0;
            }
        } else {
            if ((REG_A[0] & 2) != 0) {
                REG_B[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_B[2] = 0xc0;
            }
        }
    } else {
        if (sel == 0) {
            if ((REG_A[0] & 2) != 0) {
                REG_A[0x1f] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_A[0x21] = 0xc0;
            }
        } else {
            if ((REG_A[0] & 2) != 0) {
                REG_C[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_C[2] = 0xc0;
            }
        }
    }

    p = func_02022D88((struct Obj *)ctl, 1);
    sel = ctl->sel;
    y = p->y[next];
    x = p->x[next];
    flag = p->flag;
    if (flag == 0) {
        if (sel == 0) {
            if ((REG_A[0] & 2) != 0) {
                REG_A[0x1e] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_A[0x20] = 0xc0;
            }
        } else {
            if ((REG_A[0] & 2) != 0) {
                REG_B[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_B[2] = 0xc0;
            }
        }
    } else {
        if (sel == 0) {
            if ((REG_A[0] & 2) != 0) {
                REG_A[0x1f] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_A[0x21] = 0xc0;
            }
        } else {
            if ((REG_A[0] & 2) != 0) {
                REG_C[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_C[2] = 0xc0;
            }
        }
    }
}


/*
 * Allocate the working buffer for one of the three background planes and
 * stamp its descriptor word: the two small planes share the 0x604-byte
 * buffer (tag 0xa9b, mode word 1, the plane's row limit written at +0x600)
 * while the third takes the 0xc08-byte buffer (tag 0xaa3, mode word 2) and
 * zeroes +0x600 at a 0x604 stride.  a1 outside 0..2 does nothing.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022CEC.c \
 *       --func func_02022CEC --addr 0x02022CEC --cc 1.1p1 --thumb
 */
void func_02022CEC(u32 *a0, u32 a1, u32 a2, u32 a3)
{
    int i;
    u8 *p;

    switch (a1) {
    case 0:
    case 1:
        p = func_02030734((u16)a3, 0x604, 0, (const char *)0x020A7450, 0xA9B);
        a0[1] = 1;
        a0[0] = (u32)p;
        a0[2] = a2;
        ((struct Obj15738 *)p)->f600 = a1;
        break;
    case 2:
        p = func_02030734((u16)a3, 0xC08, 0, (const char *)0x020A7450, 0xAA3);
        a0[0] = (u32)p;
        a0[1] = 2;
        a0[2] = a2;
        for (i = 0; i < 2; i++) {
            *(u32 *)(a0[0] + 0x600 + i * 0x604) = i;
        }
        break;
    }
}


/*
 * Blocked: 02022D78 (thumb, from header) has no witness outside 02022D70..02022D78. Every concrete byte reproduces.
 * closed:   blocker func_020294C0.c is now a manifest entry (matched class)
 */
void func_02022D70(void *a0)
{
    func_02022D78(a0);
}


/*
 * closed:   blocker func_02029488.c is now a manifest entry (matched class)
 *
 * Releases the object the node's first word points at and clears the slot.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02022D78.c \
 *       --func func_02022D78 --addr 0x02022D78 --thumb --cc 1.1p1
 */
void func_02022D78(u8 *p)
{
    func_020307B0(*(void **)p);
    *(u32 *)p = 0;
}



/*
 * Index into a flat array whose base pointer is the first field of
 * `obj`, with a fixed 0x604-byte stride.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02022D88.c \
 *       --func sub_02022D88 --addr 0x02022D88 --cc 1.1p1 --thumb
 */
void *sub_02022D88(struct Obj *obj, u32 idx)
{
    return obj->base + idx * 0x604;
}


void func_02022D98(void *p, struct Container *c)
{
    s32 i;

    for (i = 0; i < c->count; i++) {
        u8 *ptr = (u8 *)sub_02022D88((struct Obj *)c, i);
        MI_CpuCopy8(ptr + 0x300, ptr, 0x300);
    }
    func_02030EAC(p);
}


/*
 * Open one sprite/OBJ descriptor: a0 == 0 is the "close" spelling (one call
 * with mode 0 and no attribute writes), anything else opens with mode 1, sets
 * the 0x3f field, clears two zero slots through the six-argument entry and
 * finally stamps the 0x20 field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022DCC.c \
 *       --func func_02022DCC --addr 0x02022DCC --cc 1.1p1 --thumb
 */
void func_02022DCC(u32 a0, void *a1, u32 a2)
{
    if (a0 == 0) {
        func_02023CFC(a1, (void *)0, a2);
        return;
    }
    func_02023CFC(a1, (void *)1, a2);
    func_02023D18(a1, (void *)0x3f, 0, 0, a2);
    func_02023D60(a1, 0, 0, 0, 0, 0, a2);
    func_02023D40(a1, (void *)0x20, 0, a2);
}
