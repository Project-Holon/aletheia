/*
 * file:     pokeparty_p05.c
 * unit:     yes
 * function: func_0201CD10, func_0201CDF4, func_0201CE0C, func_0201CE20, func_0201CE30, func_0201CE34, func_0201CE38, func_0201CE48, func_0201CE5C, func_0201CE8C, func_0201CEB8
 * address:  0x0201CD10
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
 *   func_02045770  0x02045770  arm
 *   func_020311B8  0x020311B8  arm
 *   func_02031290  0x02031290  arm
 *   func_02045A90  0x02045A90  arm
 *   func_0201CEE0  0x0201CEE0  thumb
 *   func_0201C808  0x0201C808  thumb
 */
#include "../../matched/include/Obj17219.h"
#include "../../matched/include/Obj17220.h"

struct Descriptor;
struct S02030FB4;
struct U16Vec;
struct TcblNode;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32_0201CD10;

struct PrintCtx {
    s16   unk00;
    s16   unk02;
    s32_0201CD10   unk04 : 10;
    u32   unk04b : 22;
    u16   unk08;
    u16   unk0A;
    u16   unk0C;
    u16   unk0E;
    void *unk10;
    void *unk14;
    void *unk18;
};

struct Rec_0201CD10 {
    u32  state;        /* 0x00 */
    u32  mode;         /* 0x04 */
    u32  f08;          /* 0x08 */
    u32  win;          /* 0x0c */
    void *task;        /* 0x10 */
    u16 *cur;          /* 0x14 */
    u8   f18;
    u8   f19;
    u8   f1a;
    u8   f1b;
    u8   f1c;
    u8   f1d;
    u8   wait;         /* 0x1e */
    u8   scroll;       /* 0x1f */
    u8   color;        /* 0x20 */
    u8   cbres;        /* 0x21 */
    struct {
        u8 b0 : 1;
        u8 b1 : 1;
        u8 b2 : 1;
        u8 b3 : 1;
        u8 b4 : 1;
        u8 rest : 3;
    } flags;           /* 0x22 */
    u8   pad23;
    u8 (*cb)(u32);     /* 0x24 */
    u32  f28;
    u32  f2c;
    u32  cbarg;        /* 0x30 */
    struct PrintCtx ctx; /* 0x34 */
};

struct Rec3 {
    u32 pad[4];
    void *unk10;
};

typedef int           s32_0201CE5C;

struct Rec_0201CE5C {
    u8 pad00[0x18];
    u8 unk18;
    u8 unk19;
    u8 pad1A[2];
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 pad1F[3];
    u8 unk22;
};

extern void *func_02045770(struct Descriptor *p);
extern void *func_020311B8(u32 a0, void *fn, u32 sz, u32 a3);
extern void *func_02031290(struct S02030FB4 *p);
extern u16 *func_02045A90(struct U16Vec *vec);
extern void  func_0201CEE0(void *task, struct Rec_0201CD10 *p);
extern void func_0201C808(struct PrintCtx *p, void *w, void *x, u32 y, s16 z);
extern void func_02031194(struct TcblNode *n);
extern signed char func_02013080(u32 idx);
void sub_0201CE8C(struct Rec_0201CE5C *p, s32_0201CE5C v);
struct Rec_0201CD10 *func_0201CD10(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32_0201CD10 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
void sub_0201CDF4(int v, u8 *out);
void sub_0201CE0C(void *p);
void sub_0201CE20(void *p);
u32 sub_0201CE30(void *p);
u32 sub_0201CE34(void *p);
void sub_0201CE38(void *p);


/*
 * The printsys text-record constructor: registers func_0201CEE0 as a
 * task with a 0x50-byte work area, builds the PrintCtx at +0x34 through
 * func_0201C808, splits the signed speed argument into the sign/magnitude
 * pairs at +0x18..+0x1D, and initialises every other field of struct Rec
 * (the same layout src/matched/func_0201CEE0.c consumes).  Returns the
 * record.
 *
 * The two-load swap the notes carried at +0x28/+0x30 (a4 read before a1)
 * was a declaration fact, not a scheduling one:
 *  - func_0201C808's real prototype (src/matched/sub_0201C808.c) is
 *    (struct PrintCtx *, void *, void *, s16, s16), so a1 and a2 are s16
 *    parameters here;
 *  - the byte stored to +0x20 is the tenth argument declared `u16 a9`.
 *    Thumb ldrh cannot use sp as a base, which is where the notes'
 *    `*(u16 *)((u8 *)&a4 + 0x14)` came from; taking a4's address to fake
 *    it pinned the a4 load late.  With a9 a real u16 parameter nothing
 *    takes an address and the loads schedule as in the image.
 */
struct Rec_0201CD10 *func_0201CD10(u32 a0, s16 a1, s16 a2, u32 a3,
                          u32 a4, s32_0201CD10 a5, u32 a6, u32 a7, u32 a8, u16 a9,
                          u32 a10)
{
    struct Rec_0201CD10 *o;
    void *r;
    u32 h;
    u8 pair[2];

    h = (u32)func_02045770((struct Descriptor *)a0);
    r = func_020311B8(a6, (void *)func_0201CEE0, 0x50, a7);
    o = func_02031290(r);

    o->task = r;
    func_0201C808(&o->ctx, (void *)a4, (void *)h, a1, a2);
    sub_0201CDF4(a5, pair);
    o->f19 = pair[1];
    {
        u8 lo = pair[0];
        o->f18 = lo;
        o->f1c = lo;
        o->f1a = lo;
    }
    {
        u8 hi = o->f19;
        o->f1d = hi;
        o->f1b = hi;
    }
    o->cur = func_02045A90((struct U16Vec *)a3);
    o->wait = 0;
    o->cb = (u8 (*)(u32))a10;
    o->f28 = 0;
    o->f2c = 0;
    o->cbarg = 0;
    o->f08 = a0;
    o->win = h;
    o->state = 0;
    o->color = a9;
    o->mode = 1;
    o->scroll = 0;
    o->flags.b2 = 0;
    o->flags.b0 = 0;
    o->flags.b1 = 0;
    o->cbres = 0;
    o->flags.b3 = 0;
    o->flags.b4 = 0;
    return o;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0201CE34, sub_0201CE38, sub_0201CE48
 *
 * sub_0201CDF4 splits a signed delta into a sign-magnitude pair of output
 * bytes: byte[1]=1 and byte[0]=the value when it is non-negative, byte[1]=
 * the absolute value and byte[0]=0 when it is negative.  The two branches
 * store to the two bytes in opposite order from each other, which is what
 * the original does and is not an artefact of how it is written.
 *
 * sub_0201CE0C, sub_0201CE20 and sub_0201CE38 are three single-bit
 * operations on a byte at offset 0x22 of an object: set bit 0 (written
 * through a redundant clear-then-set, `(x & ~1) | 1`, rather than a plain
 * `x |= 1`, which is what the bytes show), clear bit 0, and set bit 2 with
 * a plain OR.  All three read and write the field through two separate
 * `((u8 *)p)[0x22]` expressions rather than a named pointer local, which is
 * what keeps the load address and the store address computed independently
 * the way the original does it.
 *
 * sub_0201CE30 and sub_0201CE34 are the two four-byte word getters this
 * neighbourhood keeps reusing (the same shape as
 * src/matched/unit_0201AA14.c's pair); disasm.py's prologue sweep does not
 * label either of them, since a two-instruction leaf saves nothing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), so both were
 * read directly out of the `.word` run the listing prints between
 * sub_0201CE20 and sub_0201CE38.
 *
 * sub_0201CE48 frees and clears an owned pointer at offset 0x10 if it is
 * non-null.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201CDF4.c \
 *       --addr 0x0201CDF4 --thumb
 */
void sub_0201CDF4(int v, u8 *out)
{
    if (v >= 0) {
        out[1] = 1;
        out[0] = (u8)v;
    } else {
        out[1] = (u8)(-v);
        out[0] = 0;
    }
}


void sub_0201CE0C(void *p)
{
    ((u8 *)p)[0x22] = (((u8 *)p)[0x22] & ~1u) | 1u;
}


void sub_0201CE20(void *p)
{
    ((u8 *)p)[0x22] = ((u8 *)p)[0x22] & ~1u;
}


u32 sub_0201CE30(void *p)
{
    return ((struct Obj17219 *)p)->f0;
}


u32 sub_0201CE34(void *p)
{
    return ((struct Obj17220 *)p)->f4;
}


void sub_0201CE38(void *p)
{
    ((u8 *)p)[0x22] = ((u8 *)p)[0x22] | 4u;
}


void sub_0201CE48(struct Rec3 *p)
{
    if (p->unk10 != 0) {
        func_02031194(p->unk10);
        p->unk10 = 0;
    }
}


/*
 * Four more operations on the object src/matched/unit_0201CDF4.c works on,
 * continuing its run of single-bit edits of the flag byte at +0x22: this
 * range sets bit 4 and bit 3, clears bit 3, and reads bit 3 back.
 *
 * sub_0201CE5C lowers a level-like byte at +0x1E and, when the new value is
 * zero, replaces the pair at +0x1C/+0x1D through sub_0201CE8C with whatever
 * func_02013080(2) returns.  sub_0201CEB8 is the undo: it clears the bit and
 * restores the pair from the backup at +0x18/+0x19.
 *
 * sub_0201CED4 is an unlabelled follower, eight bytes with no prologue.  It
 * reads bit 3 as a `lsls #0x1C` / `lsrs #0x1F` pair, which is the bitfield
 * extraction shape of
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md rather than
 * the `lsrs #3` / `ands #1` a shift and mask would give.
 *
 * The bit read has to be cast to u32 before the shift pair: on the promoted
 * `int` the right shift is an `asrs` and the one byte is wrong.
 *
 * Every one of the four reaches the flag byte through two independent
 * `((u8 *)p)[0x22]` expressions, the same spelling unit_0201CDF4.c needs, so
 * the load address and the store address are computed separately.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201CE5C.c \
 *       --addr 0x0201CE5C --thumb
 */
void sub_0201CE5C(struct Rec_0201CE5C *p, s32_0201CE5C v)
{
    if (v < p->unk1E) {
        p->unk1E = (u8)v;
        if (v == 0) {
            sub_0201CE8C(p, func_02013080(2));
            ((u8 *)p)[0x22] = 0x10u | ((u8 *)p)[0x22];
        }
    }
}

void sub_0201CE8C(struct Rec_0201CE5C *p, s32_0201CE5C v)
{
    u8 tmp[2];

    sub_0201CDF4(v, tmp);
    p->unk1D = tmp[1];
    p->unk1C = tmp[0];
    ((u8 *)p)[0x22] = 8u | ((u8 *)p)[0x22];
}

void sub_0201CEB8(struct Rec_0201CE5C *p)
{
    ((u8 *)p)[0x22] = ((u8 *)p)[0x22] & ~8u;
    p->unk1D = p->unk19;
    p->unk1C = p->unk18;
}

u32 sub_0201CED4(struct Rec_0201CE5C *p)
{
    return ((u32)((u8 *)p)[0x22] << 28) >> 31;
}
