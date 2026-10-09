/*
 * file:     clact_p02.c
 * unit:     yes
 * function: func_0204BE38, func_0204BE84, func_0204BF28, func_0204BF40, func_0204BFC4, func_0204BFF4, func_0204C024, func_0204C040, func_0204C060, func_0204C214, func_0204C2C8, func_0204C3CC, func_0204C660, func_0204C6E4, func_0204C718, func_0204C788, func_0204C7A4, func_0204C804
 * address:  0x0204BE38
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02065B74  0x02065B74  arm
 *   g_020A1418     0x020A1418  data
 *   g_020A13F4     0x020A13F4  data
 *   g_020A1388     0x020A1388  data
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02063294  0x02063294  arm
 *   g_02146A74     0x02146A74  data
 *   func_02063378  0x02063378  arm
 *   tbl_020A17D8   0x020A17D8  data
 *   tbl_020A17F0   0x020A17F0  data
 *   s_clact_c      0x020A7F74  data
 *   sub_02030734   0x02030734  arm
 *   func_02066934  0x02066934  arm
 *   func_0204C83C  0x0204C83C  arm
 *   sub_020307B0   0x020307B0  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204C8B8  0x0204C8B8  arm
 *   MI_CpuFill8    0x02082BCC  arm
 */
#include "../../matched/include/Obj16091.h"

struct Box;
struct Pair;
struct Obj;
struct Win;
struct OamEntry;
struct C_0204C214;
struct M_0204C214;
struct Xfer;
typedef unsigned char u8;

typedef unsigned int u32;

typedef void (*CullFn)(void);

struct Elem_0204BE38 {
    u8 pad_00[0x40];
    CullFn fn;
    u8 pad_44[4];
};

struct Obj {
    u8 pad_00[0x30];
    u32 f30;
    u8 pad_34[0x64];
    struct Elem_0204BE38 *f98;
    u32 f9c;
};

typedef signed int     s32_0204BE38;

typedef signed short s16_0204BE38;

typedef struct { u32 w0, w1, w2; } S12;

typedef struct {
    s16_0204BE38 f0;
    s16_0204BE38 f2;
    s16_0204BE38 f4;
    s16_0204BE38 f6;
    u32 f8;
    u32 fC;
} T;

typedef struct {
    int f00;
    int f04;
    int f08;
    int f0c;
    u8  pad_10[0x28 - 0x10];
    int f28;
    int f2c;
    int f30;
    int f34;
} D;

typedef unsigned short u16;

struct OamEntry {
    u16 attr[4];
};

struct Mgr_0204BE38 {
    u8  pad_000[0xf0];
    u16 unk_f0;
    u16 unk_f2;
    u32 unk_f4;
};

struct Mgr_0204C040 {
    u8 pad_000[0x20];
};

typedef short          s16_0204C060;

typedef int            s32_0204C060;

typedef long long      s64;

struct A_0204BE38 { u16 f00; u16 f02; u16 f04; u16 f06; s16_0204C060 f08; s16_0204C060 f0a; s16_0204C060 f0c; s16_0204C060 f0e; };

struct M_0204BE38 { s32_0204C060 f00; s32_0204C060 f04; s32_0204C060 f08; s32_0204C060 f0c; s32_0204C060 f10; s32_0204C060 f14; };

struct C_0204BE38 { s32_0204C060 f00; s32_0204C060 f04; s32_0204C060 f08; s32_0204C060 f0c; };

typedef short          s16_0204C214;

typedef int            s32_0204C214;

struct A_0204C214 { u16 f00; u16 f02; u16 f04; u16 f06; s16_0204C214 f08; s16_0204C214 f0a; s16_0204C214 f0c; s16_0204C214 f0e; };

struct B { u8 pad_00[0x10]; s32_0204C214 f10; s32_0204C214 f14; };

struct C_0204C214 { s32_0204C214 f00; s32_0204C214 f04; s32_0204C214 f08; s32_0204C214 f0c; };

typedef signed short s16_0204C2C8;

typedef signed int s32_0204C2C8;

typedef union {
    u32 attr01;
    struct {
        u32 y : 8;
        u32 rsMode : 2;
        u32 objMode : 2;
        u32 mosaic : 1;
        u32 colorMode : 1;
        u32 shape : 2;
        u32 x : 9;
        u32 rsParam : 5;
        u32 size : 2;
    };
} OamAttr;

struct Elem_0204C214 {
    u8 pad_00[0x30];
    u32 visible;
    u8 pad_34[4];
    OamAttr oam;
};

struct Pair {
    s32_0204C2C8 x;
    s32_0204C2C8 y;
};

struct Box {
    u8 pad[0x10];
    s32_0204C2C8 f10;
    s32_0204C2C8 f14;
};

typedef int s32_0204C3CC;

struct M_0204C214 { s32_0204C3CC f00; s32_0204C3CC f04; s32_0204C3CC f08; s32_0204C3CC f0c; s32_0204C3CC f10; s32_0204C3CC f14; };

struct Rec {
    u8 pad_00[0x30];
};

struct Entry_0204BE38 {
    u8 pad_00[0x10];
};

struct Pool {
    struct Rec   *recs;    /* 0x00 */
    struct Entry_0204BE38 *ents;    /* 0x04 */
    u32           count;   /* 0x08 */
    u32           ready;   /* 0x0c */
};

struct Pool_0204C6E4 {
    void *recs;      /* 0x00 */
    u8    pad_04[8];
    u32   ready;     /* 0x0c */
};

struct Pool_0204C718 {
    u8            pad_00[4];
    struct Entry_0204BE38 *ents;    /* 0x04 */
    u32           count;   /* 0x08 */
};

struct Pool_0204C788 {
    u8    pad_00[4];
    void *ents;   /* 0x04 */
};

struct Entry_0204C788 {
    u32 unk_00;
    u8  pad_04[0x0c];
};

struct Table {
    u8            pad_00[4];
    struct Entry_0204C788 *ents;
    u32           count;
};

struct Pool_0204C804 {
    u8            pad_00[4];
    struct Entry_0204C788 *ents;    /* 0x04 */
    u32           count;   /* 0x08 */
};

extern void func_02065B74(struct Obj *p);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32  func_02063294(struct Win *win, struct OamEntry *entry, u32 mode);
extern void func_02063378(u32 a0, u32 a1);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern void  func_02066934(struct Rec *recs, u32 n, void *cb);
extern u32 func_0204C83C(u32 kind, u32 a, u32 b, u32 c);
extern u32 sub_020307B0(void *p);
extern void  func_02082BCC(void *dst, int fill, u32 size);
extern void func_0204C8B8(struct Xfer *x);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);
void func_0204BE38(struct Obj *obj, int on);
void func_0204BE84(D *a0, const T *a1);
void func_0204BF28(u8 *p, u32 idx);
void func_0204BF40(struct Win *win, struct OamEntry *src, u32 mode, u32 pal, u32 op);
void func_0204BFC4(u32 a0, u32 a1);
void func_0204BFF4(u32 a0, u32 a1);
void func_0204C024(u32 v);
void func_0204C040(u32 arg);
int func_0204C060(struct A_0204BE38 *a, struct M_0204BE38 *m, struct C_0204BE38 *c);
int func_0204C214(struct A_0204C214 *a, struct B *b, struct C_0204C214 *c);
void func_0204C2C8(struct Elem_0204C214 *e, struct Pair *p, s32_0204C2C8 u2, s32_0204C2C8 u3, struct Box *box);
int func_0204C3CC(s32_0204C3CC dx, s32_0204C3CC dy, s32_0204C3CC x0, s32_0204C3CC x1, s32_0204C3CC y0, s32_0204C3CC y1, const struct M_0204C214 *m, const struct C_0204C214 *c);
void func_0204C660(struct Pool *p, u8 n, u32 heapId);
void func_0204C6E4(struct Pool_0204C6E4 *p);
void func_0204C718(struct Pool_0204C718 *p, u32 n, u32 heapId);
void func_0204C788(struct Pool_0204C788 *p);
void func_0204C7A4(struct Table *t);
struct Entry_0204C788 *func_0204C804(struct Pool_0204C804 *p);
extern S12  g_020A1418[];
extern u32  g_020A13F4[];
extern u16 g_020A1388[];
extern struct Mgr_0204BE38 *g_02146A74;
extern const u16 tbl_020A17D8[4][4];
extern const u16 tbl_020A17F0[4][4];
extern char s_clact_c[];





#define fxmul(a, b) ((s32_0204C060)((((s64)(a) * (s64)(b)) + 0x800) >> 12))










/*
 * Culling on/off for a 0x48-stride element array (the same f98/f9c pair
 * func_0204BD94 allocates): on != 0 installs func_0204C2C8 as each element's
 * +0x40 callback, on == 0 sets obj->f30 = 1 and clears the callbacks.  Reached
 * only through a pool word at 0x0204B0FC; the pool word 0x0204C2C8 resolves
 * sole-ref/code.
 *
 * Two levers, both needed: the non-zero arm first (`if (on != 0)`), and `i`
 * declared before `fn` (tools/permuter.py found the decl-order swap).
 */
void func_0204BE38(struct Obj *obj, int on)
{
    u32 i;
    CullFn fn;

    if (on != 0) {
        fn = (CullFn)func_0204C2C8;
    } else {
        obj->f30 = 1;
        fn = 0;
    }
    for (i = 0; i < obj->f9c; i++) {
        obj->f98[i].fn = fn;
    }
}










/*
 * Wave 15 (register-tie lane).  Three facts closed the 104-byte residue of
 * docs/notes/pkt_0204BE84.c.txt:
 *  - func_0204BF28 takes TWO arguments (a0, a1->f8): its body is
 *    `a0->f14 = tbl_020A1388[idx]`, and the image's `ldr r1, [r4, #8]`
 *    inside the store block is that argument, not an early load of the
 *    table index.  The "missing mov r0, r5" of the older note follows.
 *  - `const T *a1` (the source record is read-only); the volatile +0x04
 *    device of the older note is no longer needed.
 *  - the f2 and f6 halfwords bound to s16_0204BE38 locals at the image's load points
 *    (found by permuter anneal, then reduced by hand): that fixes the
 *    f0, f2, f6, f4 load order and the r2/r3 pair.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BE84.c \
 *       --func func_0204BE84 --addr 0x0204BE84 --cc 1.1p1 --arm
 */
void func_0204BE84(D *a0, const T *a1)
{
    S12 t;
    s16_0204BE38 y;
    s16_0204BE38 x;

    func_02065B74((struct Obj *)a0);
    x = a1->f2;
    a0->f00 = (int)a1->f0 << 12;
    y = a1->f6;
    a0->f04 = (int)x << 12;
    a0->f08 = (int)a1->f4 << 12;
    a0->f0c = (int)y << 12;
    func_0204BF28((u8 *)a0, a1->f8);
    t = g_020A1418[a1->f8];
    t.w2 = g_020A13F4[a1->fC];
    a0->f28 = (int)t.w0;
    a0->f2c = (int)t.w1;
    a0->f34 = (int)t.w2;
}










/*
 * Blocked at MATCH: all 24 concrete bytes are correct (20 code + the pool
 * word), but the ABS32 at +0x0014 has no witness of any class.  0x020A1388
 * is plain data, so only the `literal` class could attest it, and the pool
 * word inside this function is that address's only occurrence image wide.
 * The escape that unblocked 0x0204C83C in this same region (decompile the
 * target to EXACT and cite it as a `matched` witness) does not exist here:
 * nothing compiles a data table.  Same wall as src/matched/func_0204C8B8.c
 * and docs/notes/clact_c_fan_in_1_blockers.c.txt describe for 0x020A138C.
 *
 * Store the u16 entry `idx` of the table at 0x020A1388 into the caller's
 * word at +0x14, zero-extended.
 */
void func_0204BF28(u8 *p, u32 idx)
{
    ((struct Obj16091 *)p)->f14 = g_020A1388[idx];
}










/*
 * Push one OAM entry through the window at `win`, rewriting its palette field
 * on the way.  The caller's 8-byte entry is copied onto the stack first
 * (MI_CpuCopy8, not a struct assignment: the source is only 2-aligned), then
 * the 4-bit palette in bits 12..15 of the attribute halfword at +4 is either
 * BIASED by `pal` (mode 0) or REPLACED with it (mode 1); any other mode leaves
 * the entry alone.  The rewritten copy, not the caller's, is what reaches
 * func_02063294.
 *
 * The bias arm is written as a store through a pointer to the halfword's word
 * (`add r2, sp, #4` then `ldr`/`str` through r2), which is what makes the
 * image reload the base instead of re-using sp; the replace arm is small
 * enough that 1.1p1 predicates it whole
 * (`ldreq`/`lsleq`/`biceq`/`orreq`/`streq`) and needs no such pointer.
 *
 * Signature pinned from src/matched/func_0204BFC4.c, the one filed caller.
 *
 * BYTE-CORRECT, PARKED, NOT FILED.  132 bytes, 0 concrete mismatches; the sole
 * unresolved site is the PC24 to func_02063294 at +0x78.  Blocking evidence
 * class: `label` -- 0x02063294 has no branch anywhere in the image outside
 * 0x0204BF40..0x0204BFC4, and there is no `matched` entry for it
 * (docs/notes/pkt_02063078.c.txt records it as a DIFF, 228 bytes).  Filing
 * func_02063294 unblocks this file with no change to the C_0204BE38.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BF40.c \
 *       --func func_0204BF40 --addr 0x0204BF40 --cc 1.1p1 --arm
 */
void func_0204BF40(struct Win *win, struct OamEntry *src, u32 mode, u32 pal,
                   u32 op)
{
    struct OamEntry ent;
    u32 *attr2;

    MI_CpuCopy8(src, &ent, sizeof(ent));

    if (op == 0) {
        attr2 = (u32 *)&ent.attr[2];
        *attr2 = (*attr2 & ~0xf000) |
                 ((((u32)(u16)*attr2 >> 12) + pal) << 28 >> 16);
    } else if (op == 1) {
        *(u32 *)&ent.attr[2] = (*(u32 *)&ent.attr[2] & ~0xf000) |
                               (pal << 28 >> 16);
    }

    func_02063294(win, &ent, mode);
}










/*
 * Forward one command at the manager itself: the manager is the command
 * block, its u16 at +0xf0 is the id and the word at +0xf4 the payload.
 */
void func_0204BFC4(u32 a0, u32 a1)
{
    func_0204BF40((struct Win *)g_02146A74, (struct OamEntry *)a0, a1, g_02146A74->unk_f0, g_02146A74->unk_f4);
}









/*
 * Same forward as func_0204BFC4, but aimed at the sub-command block at
 * +0x20 of the manager, whose id and payload sit at +0xf2 / +0xf4.
 */
void func_0204BFF4(u32 a0, u32 a1)
{
    func_0204BF40((struct Win *)((u8 *)g_02146A74 + 0x20), (struct OamEntry *)a0, a1,
                  g_02146A74->unk_f2, g_02146A74->unk_f4);
}








/*
 * Tail call through the singleton pointer: the pool word for the global is
 * loaded, its value passed as the first argument, and the callee reached with
 * the compiler's usual `ldr ip, [pc, #4]` / `bx ip` plus a second pool word.
 */
void func_0204C024(u32 v)
{
    func_02063378((u32)g_02146A74, v);
}







/*
 * Same forward as func_0204C024 but aimed at the sub-block at +0x20.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  The
 * function starts at the computed address and its body ends at 0x0204C060.
 */
void func_0204C040(u32 arg)
{
    func_02063378((u32)((u8 *)g_02146A74 + 0x20), arg);
}






/*
 * The 2x2-matrix sibling of func_0204C214 (see docs/notes/pkt_0204C060.c.txt):
 * transform the sprite's four half-extents through the caller's 2x2 matrix in
 * 20.12 fixed point, translate by the camera delta, take the min/max of each
 * axis and cull against the viewport.
 *
 * Three levers, all measured, that this note's sibling row asked for:
 *  - The fall-through arm is the `flag == 1` field arm and the synthetic arm
 *    is the predicated one (`rsbne`/`lslne`/`movne` + `bne` over the fields),
 *    which only happens when the 6-bit extraction is hoisted ABOVE the `if`.
 *  - `dx` must be computed beside `dy`, before the `if`, not after it: with
 *    `dx` after the branch the whole 64-bit block reallocates (295 bytes out).
 *  - The extraction must go through an explicit u8 narrowing of the MASK,
 *    `(s32)(u8)(f & 0x3f)` then `(m6 << 2) & 0xff`. Every spelling that masks
 *    first and narrows the SHIFTED value -- `((f & 0x3f) << 2) & 0xff`,
 *    `(u8)((f & 0x3f) << 2)`, the u32 and the `* 4` forms -- lets 1.1p1 prove
 *    the field contiguous and fuse it into `lsl #26` + `lsr #24`, where the
 *    image keeps `and #0x3f` + `lsl #2` + `and #0xff`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C060.c \
 *       --func func_0204C060 --addr 0x0204C060 --cc 1.1p1 --arm
 */
int func_0204C060(struct A_0204BE38 *a, struct M_0204BE38 *m, struct C_0204BE38 *c)
{
    u16 f = a->f02;
    s32_0204C060 m6 = (s32_0204C060)(u8)(f & 0x3f);
    s32_0204C060 e = (m6 << 2) & 0xff;
    s32_0204C060 dy = m->f10 - c->f00;
    s32_0204C060 dx = m->f14 - c->f04;
    s32_0204C060 v0, v1, v2, v3;
    s32_0204C060 b04, b0c, b08, b00;
    s32_0204C060 p0, p1, p2, p3;
    s32_0204C060 t;

    if (((f >> 11) & 1) == 1) {
        v0 = a->f0e << 12;
        v1 = a->f0a << 12;
        v2 = a->f0c << 12;
        v3 = a->f08 << 12;
    } else {
        v1 = e << 12;
        v0 = (-e) << 12;
        v2 = v0;
        v3 = v1;
    }
    b04 = m->f04;
    b0c = m->f0c;
    b08 = m->f08;
    b00 = m->f00;

    p0 = dx + (fxmul(v0, b04) + fxmul(v0, b0c));
    p1 = dx + (fxmul(v1, b04) + fxmul(v1, b0c));
    p2 = dy + (fxmul(v2, b00) + fxmul(v2, b08));
    p3 = dy + (fxmul(v3, b00) + fxmul(v3, b08));

    t = p1;
    if (p1 < p0) {
        t = p0;
        p0 = p1;
    }
    if (p3 < p2) {
        s32_0204C060 u = p3;
        p3 = p2;
        p2 = u;
    }
    if (t > 0 && p0 < c->f0c && p3 > 0 && p2 < c->f08)
        return 1;
    return 0;
}






/*
 * The axis-aligned sibling of func_0204C060 (clact.c): take the sprite's four
 * half-extents in 20.12 fixed point, translate by the camera delta and cull
 * against the viewport.  Where func_0204C060 runs the extents through a 2x2
 * matrix, this one adds the deltas straight to them.  No relocations.
 *
 * Four levers, all measured against the image (docs/notes/pkt_0204C060.c.txt
 * had this row at 37-148 bytes out before the second pass):
 *  - The fall-through arm is the `flag == 1` field arm and the synthetic arm
 *    is the predicated one (`rsbne`/`lslne`/`movne` + `bne` over the fields).
 *    That only happens when the 6-bit extraction is hoisted ABOVE the `if`.
 *  - `dy` is declared before `dx` (the image's first `sub` is
 *    `b->f10 - c->f00`); swapping them costs 8 bytes.
 *  - The four sums must be computed as named locals in the order
 *    ay, ax, bx, by BEFORE the `&&` chain; computing them inside the chain
 *    makes the compiler interleave the adds with the branches (115 out).
 *  - The extraction must go through an explicit u8 narrowing of the MASK,
 *    `(s32)(u8)(w & 0x3f)` then `(m6 << 2) & 0xff`, exactly as
 *    func_0204C060 documents.  Every spelling that masks first and narrows
 *    the SHIFTED value -- `(u8)((w & 0x3f) << 2)`, `((w & 0x3f) << 2) & 0xff`,
 *    the u32 and the `* 4` forms -- lets 1.1p1 prove the field contiguous and
 *    fuse it into `lsl #26` + `lsr #24`, where the image keeps
 *    `and #0x3f` + `lsl #2` + `and #0xff`.  This was the final 6-byte residue;
 *    tools/permuter.py exhausted 261 single mutations on it without moving it,
 *    which is the "residue is in the reading, not the allocation" signature.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0204C214.c \
 *       --func func_0204C214 --addr 0x0204C214 --cc 1.1p1 --arm
 */
int func_0204C214(struct A_0204C214 *a, struct B *b, struct C_0204C214 *c)
{
    u16 w = a->f02;
    s32_0204C214 m6 = (s32_0204C214)(u8)(w & 0x3f);
    s32_0204C214 v = (m6 << 2) & 0xff;
    s32_0204C214 dy = b->f10 - c->f00;
    s32_0204C214 dx = b->f14 - c->f04;
    s32_0204C214 x0, y0, x1, y1;
    s32_0204C214 ax, ay, bx, by;

    if (((w >> 11) & 1) == 1) {
        x0 = a->f0e << 12;
        y0 = a->f0a << 12;
        x1 = a->f0c << 12;
        y1 = a->f08 << 12;
    } else {
        x0 = -v << 12;
        y0 = v << 12;
        x1 = -v << 12;
        y1 = v << 12;
    }
    ay = y0 + dx;
    ax = x0 + dx;
    bx = x1 + dy;
    by = y1 + dy;
    return ay > 0 && ax < c->f0c && by > 0 && bx < c->f08;
}






static inline s32_0204C2C8 RepeatX(s16_0204C2C8 x)
{
    if (x > 0xff)
        x |= ~0xff;
    return x;
}






static inline s32_0204C2C8 RepeatY(s16_0204C2C8 y)
{
    if (y > 0x7f)
        y |= ~0xff;
    return y;
}





static inline u16 SizeX(s32_0204C2C8 shape)
{
    return tbl_020A17F0[(shape & 0xc000) >> 14][(shape & 0xc0000000) >> 30];
}






static inline u16 SizeY(s32_0204C2C8 shape)
{
    return tbl_020A17D8[(shape & 0xc000) >> 14][(shape & 0xc0000000) >> 30];
}






/*
 * The OAM cull callback func_0204BE38 installs at element +0x40: read the
 * element's GXOamAttr attr01 word (+0x38), wrap x (9 bits) and y (8 bits),
 * size the object from the OBJ width/height tables indexed [shape][size],
 * and store func_0204C3CC's verdict into the element's visible flag (+0x30).
 * box is the 2x2 matrix plus translation (f10/f14), p the viewport.
 *
 * Lever (wave 16, declaration facts): the two OBJ size tables are
 * read-only data and are declared `const`.  Without const every register
 * name of the second half shuffled (58 bytes, flat under 120 declaration
 * orders, 80 index casts and two anneals); with it, EXACT.  const on the
 * p parameter is wrong (264 bytes); const on box and on the callee's
 * pointer parameters is neutral.
 */
void func_0204C2C8(struct Elem_0204C214 *e, struct Pair *p, s32_0204C2C8 u2, s32_0204C2C8 u3, struct Box *box)
{
    s32_0204C2C8 shape = e->oam.attr01 & 0xC000C000;
    s32_0204C2C8 x0 = RepeatX(e->oam.x) << 12;
    s32_0204C2C8 x1 = (RepeatX(e->oam.x) + SizeX(shape)) << 12;
    s32_0204C2C8 y0 = RepeatY(e->oam.y) << 12;
    s32_0204C2C8 y1 = (RepeatY(e->oam.y) + SizeY(shape)) << 12;

    e->visible = func_0204C3CC(box->f10 - p->x, box->f14 - p->y,
                               x0, x1, y0, y1, (const struct M_0204C214 *)box, (const struct C_0204C214 *)p) != 0;
}




#undef fxmul



#undef fxmul


#undef fxmul

#undef fxmul


#define fxmul(a, b) ((s32_0204C3CC)((((s64)(a) * (s64)(b)) + 0x800) >> 12))






/*
 * The 2x2-matrix cull test behind func_0204C2C8 (its only caller): transform
 * the four corners (x0,y0) (x0,y1) (x1,y0) (x1,y1) of an OAM rectangle through
 * the matrix m (20.12, rounded +0x800), take min/max per axis, translate by the
 * camera delta (dx, dy) and test against the viewport c->f08 / c->f0c.  Eight
 * arguments: dx, dy, x0, x1 in r0-r3; y0, y1, m, c on the stack.
 *
 * Levers, all measured (wave 10):
 *  - the four translated bounds are added EAGERLY as statements
 *    (`minx += dx; maxx += dx; miny += dy; maxy += dy;`) before the `&&`
 *    chain, same lever as func_0204C214; inline in the chain: 41-66 out.
 *  - declaration order `maxx, minx, maxy, miny` and the seed order
 *    `min = p; max = p;` put the minimum in p's register and the maximum in
 *    the copy (r4/lr, sb/r7), as the image has it; any other order swaps the
 *    pair (25-37 out).  Found by tools/permuter.py (decl-order + reorder),
 *    then closed by sweeping all 240 decl/seed orders.
 *  - the umull/mla (not smull) products from the second use of each
 *    coordinate on are the CSE'd `(s64)` sign halves, not a different macro.
 */
int func_0204C3CC(s32_0204C3CC dx, s32_0204C3CC dy, s32_0204C3CC x0, s32_0204C3CC x1, s32_0204C3CC y0, s32_0204C3CC y1,
                  const struct M_0204C214 *m, const struct C_0204C214 *c)
{
    s32_0204C3CC maxx, minx, maxy, miny;
    s32_0204C3CC p;

    p = fxmul(x0, m->f00) + fxmul(y0, m->f08);
    minx = p;
    maxx = p;
    p = fxmul(x0, m->f00) + fxmul(y1, m->f08);
    if (p < minx) minx = p; else if (p > maxx) maxx = p;
    p = fxmul(x1, m->f00) + fxmul(y0, m->f08);
    if (p < minx) minx = p; else if (p > maxx) maxx = p;
    p = fxmul(x1, m->f00) + fxmul(y1, m->f08);
    if (p < minx) minx = p; else if (p > maxx) maxx = p;

    p = fxmul(x0, m->f04) + fxmul(y0, m->f0c);
    miny = p;
    maxy = p;
    p = fxmul(x0, m->f04) + fxmul(y1, m->f0c);
    if (p < miny) miny = p; else if (p > maxy) maxy = p;
    p = fxmul(x1, m->f04) + fxmul(y0, m->f0c);
    if (p < miny) miny = p; else if (p > maxy) maxy = p;
    p = fxmul(x1, m->f04) + fxmul(y1, m->f0c);
    if (p < miny) miny = p; else if (p > maxy) maxy = p;

    minx += dx; maxx += dx; miny += dy; maxy += dy;
    if (maxy > 0 && miny < c->f0c && maxx > 0 && minx < c->f08)
        return 1;
    return 0;
}




/*
 * promoted: from src/pending 2026-09-19, no C change: blocker 0x02066934 is filed in layout/matched/arm9/pkt_02066890.json and every site resolves (gate: manifest --verify --shard layout/matched/arm9/pkt_0204C060.json, then 0 rewritten).
 *
 * Blocked at MATCH: all 132 concrete bytes are correct and four of the five
 * relocation sites resolve, but the PC24 at +0x0054 (the call to
 * func_02066934) has no witness of any class.  0x02066934 has exactly one
 * branch reference image wide and it is that call, so no cut frees it; the
 * only unblock is a `matched` entry at 0x02066934, far outside clact.c.
 *
 * Construct a pool of `n` 0x30-byte records: allocate the array, hand it to
 * func_02066934 with func_0204C83C as the per-record callback, build the
 * parallel 0x10-byte entry array through func_0204C718, and mark the object
 * constructed.  A zero capacity leaves the object unconstructed and is the
 * predicated early return off the `movs` that loads the count.
 *
 * The record size 0x30 is a real `mul` against a register, not a shift pair:
 * mwccarm only strength-reduces the multiply when the constant is a power of
 * two, and 0x30 is not.
 *
 * The allocation result is bound to a local, stored, and then passed on: the
 * call to func_02066934 reuses the value in r0 instead of reloading +0x00,
 * which is what the named temporary produces
 * (docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md).
 *
 * func_0204C83C is passed as data, so the relocation is an ABS32 into the
 * code section; it is an ordinary extern declared at its own address, not a
 * veneer.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204C660.c \
 *       --func func_0204C660 --addr 0x0204C660 --cc 1.1p1 --arm
 */
void func_0204C660(struct Pool *p, u8 n, u32 heapId)
{
    struct Rec *recs;

    if (n == 0) {
        p->ready = 0;
        return;
    }

    p->count = n;
    recs = sub_02030734(heapId, n * sizeof(struct Rec), 0, s_clact_c, 0x1337);
    p->recs = recs;

    func_02066934(recs, n, func_0204C83C);
    func_0204C718((struct Pool_0204C718 *)p, n, heapId);

    p->ready = 1;
}




/*
 * The inverse of src/matched/func_0204C660.c: release the 0x30-byte record
 * array, drop the free-list built over it, and clear the constructed flag at
 * +0x0c.  An unconstructed object is an early return predicated onto the
 * entry compare.
 *
 * The zero is materialised once into a callee-saved register and used for
 * both stores, because the second store lands after the call to
 * func_0204C788; that is also what forces the store to +0x00 to be written
 * before the call rather than after
 * (docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C6E4.c \
 *       --func func_0204C6E4 --addr 0x0204C6E4 --cc 1.1p1 --arm
 */
void func_0204C6E4(struct Pool_0204C6E4 *p)
{
    if (p->ready == 0) {
        return;
    }

    sub_020307B0(p->recs);
    p->recs = 0;
    func_0204C788((struct Pool_0204C788 *)p);
    p->ready = 0;
}




/*
 * Allocate the pool's parallel array of 0x10-byte entries and zero each one.
 * The __FILE__ pointer is the same s_clact_c the rest of clact.c uses; the
 * line number 0x137b is a plain pooled constant here, not derived from a
 * neighbouring one, because this is the only allocation in the function.
 *
 * The entry count for the loop is read back out of the object at +0x08 rather
 * than reused from the `n` that sized the allocation: the load right after the
 * call is the loop's rotated entry test, and the same field is re-read at the
 * bottom of every iteration because func_02082BCC may alias it.
 *
 * The clear is a per-element call, not one call over the whole array, so the
 * zero and the 0x10 are hoisted into callee-saved registers for the loop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C718.c \
 *       --func func_0204C718 --addr 0x0204C718 --cc 1.1p1 --arm
 */
void func_0204C718(struct Pool_0204C718 *p, u32 n, u32 heapId)
{
    u32 i;

    p->ents = sub_02030734(heapId, n * sizeof(struct Entry_0204BE38), 0, s_clact_c,
                           0x137b);

    for (i = 0; i < p->count; i++) {
        func_02082BCC(&p->ents[i], 0, sizeof(struct Entry_0204BE38));
    }
}



/*
 * Release the 0x10-byte entry array func_0204C718 allocates at +0x04 and NULL
 * the pointer.  The pointer has to survive the free call, so the object is
 * kept in r4 and the store is written after it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C788.c \
 *       --func func_0204C788 --addr 0x0204C788 --cc 1.1p1 --arm
 */
void func_0204C788(struct Pool_0204C788 *p)
{
    sub_020307B0(p->ents);
    p->ents = 0;
}



/*
 * Blocked at MATCH: all 96 concrete bytes are correct, but the PC24 at
 * +0x0034 (the call to func_0204C8B8) has no witness of any class.
 * 0x0204C8B8 has exactly one branch reference image wide and it is that
 * call, so no cut frees it; the unblock is a `matched` entry at 0x0204C8B8,
 * which src/pending/func_0204C8B8.c cannot supply, being itself byte-correct
 * but capped at MATCH by the handler table at 0x020A138C having no second
 * pool word anywhere in the image.
 *
 * Tear down every live entry of a 16-byte-record table: the record count is
 * at +0x08 and the array base at +0x04, and a record is live when its first
 * word is non-null.  Each live record is handed to func_0204C8B8 and then
 * zeroed.
 *
 * The array base is re-read from +0x04 on both sides of the func_0204C8B8
 * call, which is what fixes it as a field load rather than a cached local:
 * the callee may move the table.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204C7A4.c \
 *       --func func_0204C7A4 --addr 0x0204C7A4 --cc 1.1p1 --arm
 */
void func_0204C7A4(struct Table *t)
{
    u32 i;

    for (i = 0; i < t->count; i++) {
        if (t->ents[i].unk_00 != 0) {
            func_0204C8B8((struct Xfer *)(&t->ents[i]));
            MI_CpuFill8(&t->ents[i], 0, sizeof(struct Entry_0204C788));
        }
    }
}



/*
 * Find the first free 0x10-byte entry of a pool, free meaning a zero word at
 * +0x00.  Returns NULL when the pool is full.  A leaf: nothing here calls
 * anything, so both the entry array and the count are hoisted out of the loop
 * and the element address is only materialised on the arm that returns it
 * (`addeq r0, r2, r1, lsl #4`).
 *
 * The scaled register offset `ldr r0, [r2, r1, lsl #4]` is the subscript form
 * `p->ents[i].unk_00`; a walking cursor would have produced a post-indexed
 * load and an extra add
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C804.c \
 *       --func func_0204C804 --addr 0x0204C804 --cc 1.1p1 --arm
 */
struct Entry_0204C788 *func_0204C804(struct Pool_0204C804 *p)
{
    u32 i;

    for (i = 0; i < p->count; i++) {
        if (p->ents[i].unk_00 == 0) {
            return &p->ents[i];
        }
    }

    return 0;
}
