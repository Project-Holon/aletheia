/*
 * file:     clact_p12.c
 * unit:     yes
 * function: func_0204D768, func_0204D7C4, func_0204D7E0, func_0204D8AC, func_0204D9B4, func_0204D9D4, func_0204DA5C, func_0204DACC, func_0204DC64, func_0204DC70, func_0204DCA8, func_0204DD08, func_0204DEE8, func_0204E010, func_0204E01C, func_0204E074, func_0204E0C4, func_0204E0D0, func_0204E130
 * address:  0x0204D768
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
 *   func_0204D410  0x0204D410  arm
 *   func_02063000  0x02063000  arm
 *   func_02063018  0x02063018  arm
 *   func_02034558  0x02034558  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_020345DC  0x020345DC  arm
 *   s_clact_c      0x020A7F74  data
 *   func_02049250  0x02049250  arm
 *   func_020834C0  0x020834C0  arm
 *   sub_02030734   0x02030734  arm
 *   sub_020307B0   0x020307B0  arm
 *   sub_02034630  0x02034630  arm
 *   func_02063790    0x02063790  arm
 *   func_02034660    0x02034660  arm
 *   func_020346D8    0x020346D8  arm
 *   func_02063828    0x02063828  arm
 *   func_02063A54    0x02063A54  arm
 *   func_02063C80    0x02063C80  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02062AD4  0x02062AD4  arm
 *   func_02062A98  0x02062A98  arm
 *   func_020637D4  0x020637D4  arm
 *   func_02063F4C  0x02063F4C  arm
 *   func_02080C34  0x02080C34  arm
 *   func_02080C74  0x02080C74  arm
 *   func_0208068C  0x0208068C  arm
 *   func_020801F8  0x020801F8  arm
 *   func_0208083C  0x0208083C  arm
 *   func_02030734     0x02030734  arm
 *   func_0204E01C_File 0x020A7F74 data
 *   func_02062820  0x02062820  arm
 *   func_02062670  0x02062670  arm
 *   func_02062A00  0x02062A00  arm
 *   g_02146A78         0x02146A78  data
 *   func_020461F4      0x020461F4  arm
 *   func_0204E130_File 0x020A7F80  data
 */
#include "../../matched/include/Obj08865.h"

struct Obj;
struct Rec_0204D768;
struct CellAnim;
struct Bank;
struct Entry;
struct Struct020345DC;
struct ArcFile;
struct Cell;
struct Item020346D8;
struct Out;
struct TargetStruct;
struct NitroFileHeader;
struct List02063F4C;
struct Out02063F4C;
struct Self02063F4C;
struct Ovr;
struct Res;
struct Sink;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Ctl {
    u8 pad_00[4];
};

struct Cmd {
    u16 op;     /* 0x00 */
    u16 arg0;   /* 0x02 */
    u32 arg1;   /* 0x04 */
    u32 arg2;   /* 0x08 */
};

struct Caps {
    u16 cell;      /* 0x00 */
    u16 anim;      /* 0x02 */
    u16 pattern;   /* 0x04 */
    u16 unk_06;    /* 0x06 */
    u16 tiles;     /* 0x08 */
    u16 palettes;  /* 0x0a */
};

struct Cfg {
    u8  pad_00[0x10];
    u32 unk_10;    /* 0x10 */
    u8  pad_14[4];
    u32 unk_18;    /* 0x18 */
    u8  pad_1c[0x0c];
    u32 unk_28;    /* 0x28 */
    u32 unk_2c;    /* 0x2c */
};

struct Res_0204D7E0 {
    void *tiles;      /* 0x00 */
    void *palettes;   /* 0x04 */
    void *cell;       /* 0x08 */
    void *anim;       /* 0x0c */
    void *pattern;    /* 0x10 */
    u16   n_cell;     /* 0x14 */
    u16   n_anim;     /* 0x16 */
    u16   n_pattern;  /* 0x18 */
    u16   n_unk_06;   /* 0x1a */
    u16   n_tiles;    /* 0x1c */
    u16   n_palettes; /* 0x1e */
};

struct RecC {
    u8  pad_00[0x3c];
    u32 unk_3c_0  : 1;
    u32 unk_3c_1  : 30;
    u32 unk_3c_31 : 1;
};

struct RecA {
    u8  pad_00[0x14];
    u32 unk_14_0  : 31;
    u32 unk_14_31 : 1;
};

struct RecB {
    u8  pad_00[0x10];
    u32 unk_10;
};

struct Res_0204D8AC {
    void        *tiles;      /* 0x00 */
    void        *palettes;   /* 0x04 */
    struct RecC *cell;       /* 0x08 */
    struct RecA *anim;       /* 0x0c */
    struct RecB *pattern;    /* 0x10 */
    u16          n_cell;     /* 0x14 */
    u16          n_anim;     /* 0x16 */
    u16          n_pattern;  /* 0x18 */
};

struct CompHeader {
    u32 header;
};

struct Sentinel {
    u32 lo;
    u32 hi;
};

struct Rec_0204D768 {
    u8  pad_00[0x2c];
    struct Sentinel a;      /* 0x2c */
    struct Sentinel b;      /* 0x34 */
    u32 unk_3c_0  : 31;     /* 0x3c */
    u32 unk_3c_31 : 1;
};

struct Res {
    u32 f00;
    u32 f04;
    u32 f08;
};

struct Sink {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  pad0C[4];
    u32 f10;
};

struct Ovr {
    u8  pad00[0xc];
    u32 *f0C;
};

typedef volatile u32 vu32;

struct TargetStruct {
    char pad[8];
    u32 dispcnt;
};

struct Rec_0204DCA8 {
    u8  pad_00[0x14];
    u32 unk_14_0  : 31;     /* 0x14 */
    u32 unk_14_31 : 1;
};

struct Ent    { u8 pad_00[0x14]; u32 unk_14; };          /* 0x18 */

struct Surf   { u8 pad_00[8]; u32 unk_08; u32 unk_0c; };

struct Holder { u8 pad_00[0xc]; struct Ent *ents; };

typedef signed int     s32;

struct Entry_0204E01C {
    u8  pad_00[0x10];
    u32 unk_10;
};

struct Entry_0204E074 {
    u8    pad_00[8];
    void *unk_08;
    void *unk_0c;
    u32   unk_10;
};

struct Pool {
    u8            pad_00[0x10];
    struct Entry_0204E074 *entries;
};

struct Slot {
    u8  pad_00[0x3c];
    u32 unk_3c;
};

struct Owner {
    u8           pad_00[8];
    struct Slot *slots;
};

extern struct Rec_0204D768 *func_0204D410(struct Obj *o);
extern void func_02063000(int p0, int p1, int p2, int p3);
extern void func_02063018(struct CellAnim *anim, u32 a, u32 b, u16 tag);
extern struct Bank *func_02034558(u32 heapId, u32 kind, u32 flags, u32 base, u32 b);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_020345DC(struct Struct020345DC *obj);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern u32 sub_020307B0(void *p);
extern void func_020834C0(const void *src, void *dest);
extern void  sub_02034630(struct Sentinel *p);
extern void func_02063790(u32 *p);
extern int func_02034660(u8 *p, u32 a, void **out);
extern u32 func_020346D8(struct Item020346D8 *a, u32 *b);
extern void func_02063828(struct Res *r, u32 dst, int mode, struct Out *out);
extern void func_02063A54(struct Res *r, u32 dst, int mode, struct Out *out);
extern void func_02063C80(struct Res *r, u32 dst, int mode, struct Out *out);
extern u32 func_020307B0(void *p);
extern s32 func_02062AD4(struct NitroFileHeader *file, void **out);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void func_020637D4(u32 *p);
extern void func_02063E54(struct Surf *s, u32 size, int mode,
                         struct Ent *ent);
extern u16 func_02080C34(void);
extern u16 func_02080C74(void);
extern void func_0208068C(void);
extern void func_020801F8(int objExtPltt);
extern void func_0208083C(int sub_objExtPltt);
extern void func_02063F4C(struct Self02063F4C *self, struct List02063F4C *list, u32 base, int sel, struct Out02063F4C *out);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02062820(int a, int *out);
extern s32 func_02062670(void *handle, void **slot);
extern s32 func_02062A00(struct NitroFileHeader *file, void **out);
extern void  func_020461F4(u32 a);
void func_0204D768(struct Ctl *c, const struct Cmd *cmd);
void func_0204D7C4(struct Ctl *c);
void func_0204D7E0(struct Res_0204D7E0 *res, u32 heapId, const struct Cfg *cfg, const struct Caps *caps);
void func_0204D8AC(struct Res_0204D8AC *res);
u32 func_0204D9B4(u32 a, u32 b);
void *func_0204D9D4(void *owner, u32 which, u32 compressed, u32 heapId);
void *func_0204DA5C(u32 heapId, u32 count);
void func_0204DACC(struct Res *r, u32 idx, struct Sink *s, struct Ovr *ovr, u32 mode);
void func_0204DC64(void *ptr);
void func_0204DC70(struct TargetStruct *obj, int which);
void *func_0204DCA8(u32 heapId, u32 count);
void func_0204DD08(struct Holder *h, int idx, void *src, void *sel, u32 size, u16 head, u16 tail);
void func_0204DEE8(struct Holder *h, int idx, void *src, void *sel, u32 size);
void func_0204E010(void *ptr);
struct Entry_0204E01C *func_0204E01C(u32 heap, u32 count);
s32 func_0204E074(struct Pool *pool, s32 idx, void *a, void *b);
void func_0204E0C4(void *ptr);
void func_0204E0D0(struct Owner *owner, s32 idx, u32 handle, u32 a3, u32 a4);
void func_0204E130(u32 a);
extern char s_clact_c[];
extern const char func_0204E01C_File[];
extern const char func_0204E130_File[];
extern void *g_02146A78;









/*
 * Apply one animation command record to the handle behind the cell actor's
 * +0x68 sub-object.  The opcode is the u16 at +0 of the record; 0 and 2 both
 * call func_02063000 with a different mode, 1 calls func_02063018 with the
 * record's own u16 at +2 as its last argument.
 *
 * Three cases dense from zero, yet no halfword table: the compiler emits a
 * compare chain because the arms are all tail calls with no shared code, so
 * the table would cost more than the three compares
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md is the case
 * where it does build one).  The compare chain runs 0, 1, 2 in case-label
 * order whatever the source does, but the arm *blocks* are laid out in source
 * order, so the cases have to be written 0, 2, 1 to put case 1's block last.
 * That is the only thing separating this from the image: with the arms in
 * numeric order the two `beq` displacements swap and fourteen bytes differ.
 *
 * `ldmib r4, {r2, r3}` is not a struct copy, it is the compiler merging the
 * two consecutive word loads at +4 and +8 that feed argument registers three
 * and four.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D768.c \
 *       --func func_0204D768 --addr 0x0204D768 --cc 1.1p1 --arm
 */
void func_0204D768(struct Ctl *c, const struct Cmd *cmd)
{
    void *h = func_0204D410((struct Obj *)c);

    switch (cmd->op) {
    case 0:
        func_02063000((int)h, 1, cmd->arg1, cmd->arg2);
        break;
    case 2:
        func_02063000((int)h, 3, cmd->arg1, cmd->arg2);
        break;
    case 1:
        func_02063018(h, cmd->arg1, cmd->arg2, cmd->arg0);
        break;
    }
}









/*
 * Reset the animation handle behind the cell actor's +0x68 sub-object: the
 * all-zero form of the case-0 arm of func_0204D768 next door.
 *
 * The three zero arguments are one `mov r1, #0` and two register copies, not
 * three `mov`s of an immediate
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D7C4.c \
 *       --func func_0204D7C4 --addr 0x0204D7C4 --cc 1.1p1 --arm
 */
void func_0204D7C4(struct Ctl *c)
{
    func_02063000((int)func_0204D410((struct Obj *)c), 0, 0, 0);
}









/*
 * Blocked at MATCH: all 204 concrete bytes are correct; func_0204DA5C,
 * func_0204DCA8 and func_0204E01C all now resolve `matched` off their own
 * manifest entries (src/matched/func_0204DA5C.c, func_0204DCA8.c). Only
 * func_02034558 (+0x0038 and +0x005C) is left, and it cannot reach EXACT
 * from here: see docs/notes/func_02034558.c.txt. Its only two branch
 * references image wide are the two calls in this function, so no cut
 * frees it, and decompiling it does not help either, since it is itself
 * blocked by sub_02034520's unwitnessed g_FlagTable literal, one level
 * further down.
 *
 * Build the cell-actor system's five resource managers out of the caller's
 * config and capacity records, then keep a copy of the six capacities in the
 * output block at +0x14..+0x1e.
 *
 * The first two managers are the same func_02034558 with a different pair of
 * config words; its fifth argument goes through the four-byte stack slot the
 * prologue reserves, which is the whole reason for the `sub sp, sp, #4`.  The
 * shared constant 1 is hoisted into r8 rather than re-materialised at each
 * call, because both calls want it in r1 and nothing in between clobbers it.
 *
 * The two capacities that reach func_02034558 are scaled by 32 with a plain
 * `lsl` on the zero-extended halfword; the six stores at the end are six
 * separate `strh`, not an aggregate copy, so they are written as six field
 * assignments (docs/idioms/aggregate-assignment-is-ldm-stm.md is the shape
 * that would have collapsed them).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204D7E0.c \
 *       --func func_0204D7E0 --addr 0x0204D7E0 --cc 1.1p1 --arm
 */
void func_0204D7E0(struct Res_0204D7E0 *res, u32 heapId, const struct Cfg *cfg,
                   const struct Caps *caps)
{
    res->tiles    = func_02034558(heapId, 1, cfg->unk_10, caps->tiles << 5,
                                  cfg->unk_28);
    res->palettes = func_02034558(heapId, 1, cfg->unk_18, caps->palettes << 5,
                                  cfg->unk_2c);
    res->cell     = func_0204DA5C(heapId, caps->cell);
    res->anim     = func_0204DCA8(heapId, caps->anim);
    res->pattern  = func_0204E01C(heapId, caps->pattern);

    res->n_cell     = caps->cell;
    res->n_anim     = caps->anim;
    res->n_pattern  = caps->pattern;
    res->n_unk_06   = caps->unk_06;
    res->n_tiles    = caps->tiles;
    res->n_palettes = caps->palettes;
}









/*
 * Was blocked at MATCH: all 264 concrete bytes were correct and the two PC24
 * sites at +0x00E0 and +0x00E8, both calls to func_020345DC, had no witness
 * of any class (those two calls were its only branch references image
 * wide).  Unblocked by src/matched/func_020345DC.c, now a `matched` witness.
 *
 * The inverse of src/pending/func_0204D7E0.c: release every live entry of the
 * three parallel tables, then the tables themselves and the two heaps, and
 * NULL all five pointers.  This block is the tail of the singleton, at
 * +0x104, which is why the three per-entry finalisers take a bare index and
 * find the table through the global themselves (src/matched/sub_0204A8D4.c,
 * sub_0204ADA4.c and sub_0204AFD8.c).
 *
 * The liveness tests are the same three fields those finalisers write: the
 * one-bit field at bit 31 of +0x3c of the 0x40-byte record, the whole word at
 * +0x10 of the 0x14-byte record, and the one-bit field at bit 31 of +0x14 of
 * the 0x18-byte record.  Bit 31 reads as a bare `lsrs #0x1f` with no mask,
 * which is the bitfield tell
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 *
 * Every loop re-reads both its bound and its table base, because the
 * finaliser it calls is opaque and may store to the singleton.  The two
 * non-power-of-two strides become `mla` against a register-held 0x14 and
 * 0x18; only the 0x40 stride folds into `add r0, r0, r4, lsl #6`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204D8AC.c \
 *       --func func_0204D8AC --addr 0x0204D8AC --cc 1.1p1 --arm
 */
void func_0204D8AC(struct Res_0204D8AC *res)
{
    u32 i;

    for (i = 0; i < res->n_cell; i++) {
        if (res->cell[i].unk_3c_31 == 0) {
            func_0204A8D4(i);
        }
    }

    for (i = 0; i < res->n_pattern; i++) {
        if (res->pattern[i].unk_10 == 0) {
            func_0204AFD8(i);
        }
    }

    for (i = 0; i < res->n_anim; i++) {
        if (res->anim[i].unk_14_31 == 0) {
            func_0204ADA4(i);
        }
    }

    func_0204DC64(res->cell);
    func_0204E010(res->anim);
    func_0204E0C4(res->pattern);
    func_020345DC(res->palettes);
    func_020345DC(res->tiles);

    res->tiles    = 0;
    res->palettes = 0;
    res->cell     = 0;
    res->anim     = 0;
    res->pattern  = 0;
}









/*
 * Two-value compatibility test: value 2 is the wildcard, otherwise the two
 * have to be equal.  A leaf, no relocation.
 *
 * The disjunction has to be one expression so that both halves share the
 * `moveq r0, #1` / `bxeq lr` exit
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md); the
 * second test is the predicated `cmpne r1, #2`, which is what a `||` looks
 * like once it is short enough not to branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D9B4.c \
 *       --func func_0204D9B4 --addr 0x0204D9B4 --cc 1.1p1 --arm
 */
u32 func_0204D9B4(u32 a, u32 b)
{
    if (a == 2 || b == 2) {
        return 1;
    }
    return a == b;
}









/*
 * Load an archive member, optionally decompressing it.  Both arms read the
 * member with func_02049250 into a scratch block taken from the far end of
 * the caller's heap, (heapId & 0x7fff) | 0x8000, the same "allocate high"
 * form src/matched/unit_02045C44.c uses.  When the third argument is set the
 * block is treated as a compressed image: its first word carries the
 * uncompressed size in the top 24 bits, a normal-end block of that size is
 * allocated, func_020834C0 expands into it and the scratch is released.
 *
 * The heap id is computed once above the branch, which is why the `lsl #16`
 * sits before the `beq` and only the matching `lsr #16` is duplicated into
 * each arm: the compiler hoists the common subexpression and cross-jumps what
 * is left.  Spelling the cast per arm instead moves the whole pair down twice.
 *
 * The decompressing arm is the fall-through, so the guard is written `!= 0`
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * func_020834C0 takes source first and destination second here, and only two
 * arguments: r2 still holds the allocator's clobbered register at the call and
 * the original never reloads it.  Other files in the tree declare a
 * three-argument (dest, src, size) form of the same address; the declarations
 * live in different translation units and never meet, and this one is what the
 * bytes at this call site say.
 *
 * The fourth argument doubles as the heap id for both allocations, so it is
 * held in a callee-saved register across the whole function rather than
 * recomputed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D9D4.c \
 *       --func func_0204D9D4 --addr 0x0204D9D4 --cc 1.1p1 --arm
 */
void *func_0204D9D4(void *owner, u32 which, u32 compressed, u32 heapId)
{
    void *out;
    struct CompHeader *raw;

    if (compressed != 0) {
        raw = (struct CompHeader *)func_02049250(owner, which,
                  (u16)((heapId & 0x7fff) | 0x8000));
        out = sub_02030734(heapId, raw->header >> 8, 0, s_clact_c, 0x1ba5);
        func_020834C0(raw, out);
        sub_020307B0(raw);
    } else {
        out = func_02049250(owner, which,
                  (u16)((heapId & 0x7fff) | 0x8000));
    }
    return out;
}









/*
 * Closes one of the two clact.c fan-in-1 blockers of func_0204D7E0
 * documented in docs/notes/clact_c_fan_in_1_blockers.c.txt (the other is
 * func_0204DCA8, the packet's next function).
 *
 * Allocate `count` 0x40-byte records and initialise each: set bit 31 of
 * the word at +0x3c (a one-bit bitfield, unconditional `bic`/`orr` of the
 * same immediate is the bitfield-store tell), then hand the two
 * two-word sentinel pairs at +0x2c and +0x34 to sub_02034630 (already
 * matched, src/matched/unit_02034630.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204DA5C.c \
 *       --func func_0204DA5C --addr 0x0204DA5C --cc 1.1p1 --arm
 */
void *func_0204DA5C(u32 heapId, u32 count)
{
    u32 i;
    struct Rec_0204D768 *arr;

    arr = sub_02030734(heapId, count << 6, 0, s_clact_c, 0x1bbe);

    for (i = 0; i < count; i++) {
        struct Rec_0204D768 *r = &arr[i];
        r->unk_3c_31 = 1;
        sub_02034630(&r->a);
        sub_02034630(&r->b);
    }

    return arr;
}








/*
 * Upload one 0x40-byte cell's two graphics halves to VRAM. The optional
 * fourth argument supplies an override key: when it is null the key comes
 * from the sink's +0x10 field and the "overridden" flag stays clear;
 * otherwise it is the first word of the override's +0x0C block, with the
 * flag set. func_02063790 resets the cell's three-word handle triple, then
 * each half (the +0x2C descriptor against bank +0x00 and kind 1, the +0x34
 * descriptor against bank +0x04 and kind 2) is uploaded only when
 * func_0204D9B4 admits the mode pair and func_02034660 finds the resource:
 * func_020346D8 turns the descriptor into a byte offset, func_0204DC70
 * selects the VRAM window, and one of the three upload entries is chosen by
 * the override flag and, failing that, by the sink's own +0x08 selector.
 * Finally the sink pointer is published at +0x28 (null when not overridden)
 * and the key is packed into the low 31 bits of the word at +0x3C.
 */
void func_0204DACC(struct Res *r, u32 idx, struct Sink *s, struct Ovr *ovr,
                   u32 mode)
{
    u8 *cell;
    u32 ovrd;
    u32 key;
    u32 kind;
    u32 off;

    cell = (u8 *)r->f08 + idx * 0x40;

    if (ovr == 0) {
        key = s->f10;
        ovrd = 0;
    } else {
        ovrd = (ovr->f0C != 0);
        if (ovrd) key = *ovr->f0C;
        else key = 0;
        ovrd = 1;
    }

    func_02063790((u32 *)cell);

    if (func_0204D9B4(mode, 0) != 0) {
        if (func_02034660((u8 *)r->f00, key, (void **)(cell + 0x2c)) != 0) {
            off = func_020346D8((struct Item020346D8 *)r->f00, (u32 *)(cell + 0x2c));
            kind = 1;
            func_0204DC70((struct TargetStruct *)s, (int)kind);
            if (ovrd != 0) {
                func_02063C80((struct Res *)s, off, (int)kind, (struct Out *)cell);
            } else if (s->f08 != 0) {
                func_02063828((struct Res *)s, off, (int)kind, (struct Out *)cell);
            } else {
                func_02063A54((struct Res *)s, off, (int)kind, (struct Out *)cell);
            }
        }
    }

    if (func_0204D9B4(mode, 1) != 0) {
        if (func_02034660((u8 *)r->f04, key, (void **)(cell + 0x34)) != 0) {
            off = func_020346D8((struct Item020346D8 *)r->f04, (u32 *)(cell + 0x34));
            kind = 2;
            func_0204DC70((struct TargetStruct *)s, (int)kind);
            if (ovrd != 0) {
                func_02063C80((struct Res *)s, off, (int)kind, (struct Out *)cell);
            } else if (s->f08 != 0) {
                func_02063828((struct Res *)s, off, (int)kind, (struct Out *)cell);
            } else {
                func_02063A54((struct Res *)s, off, (int)kind, (struct Out *)cell);
            }
        }
    }

    if (ovrd == 0) s = 0;
    ((struct Obj08865 *)cell)->f28 = (u32)s;
    ((struct Obj08865 *)cell)->f3C = (((struct Obj08865 *)cell)->f3C & 0x80000001)
                          | ((key << 2) >> 1);
}








void func_0204DC64(void *ptr)
{
    func_020307B0(ptr);
}








void func_0204DC70(struct TargetStruct *obj, int which)
{
    u32 val = (which == 1) ? (*(vu32 *)0x04000000 & 0x00300010) : (*(vu32 *)0x04001000 & 0x00300010);
    if (obj->dispcnt != val) {
        obj->dispcnt = val;
    }
}






/*
 * Closes the other of the two clact.c fan-in-1 blockers of func_0204D7E0
 * documented in docs/notes/clact_c_fan_in_1_blockers.c.txt (the other is
 * func_0204DA5C, this packet's previous function).
 *
 * Allocate `count` 0x18-byte records and set bit 31 of the word at +0x14
 * of each (a one-bit bitfield; the unconditional `bic`/`orr` pair of the
 * same immediate is the bitfield-store tell, same shape as
 * func_0204DA5C's +0x3c field).
 *
 * The record size 0x18 is a real `mul` against a register, not a shift
 * pair, because 0x18 is not a power of two; the per-record address inside
 * the loop is then one `mla`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204DCA8.c \
 *       --func func_0204DCA8 --addr 0x0204DCA8 --cc 1.1p1 --arm
 */
void *func_0204DCA8(u32 heapId, u32 count)
{
    u32 i;
    struct Rec_0204DCA8 *arr;

    arr = sub_02030734(heapId, count * sizeof(struct Rec_0204DCA8), 0, s_clact_c, 0x1c58);

    for (i = 0; i < count; i++) {
        arr[i].unk_14_31 = 1;
    }

    return arr;
}





/*
 * Reconfigure one 0x18-byte entry of the holder's table: trim the surface
 * (the +0x08 byte count / +0x0c data word pair, a palette-shaped record) by
 * `head` 32-byte blocks from the front and to `tail` blocks, clamp it to the
 * layer limit, re-upload for one or both engines, then store the surviving
 * byte count into the entry's bits 0..30.  Sole caller: sub_0204AC18.
 *
 * The C body is docs/notes/sub_0204DD08.c.txt's (476 against 480 there),
 * closed in wave 10 by two levers:
 *  - THE MATERIALISED `lsl r0, r3, #5`.  The head block's offset is a named
 *    64-BIT local, `unsigned long long ofs = head * 32;`, used by the add and
 *    the sub, while the compare keeps the plain `head * 32` (which is why the
 *    image re-folds `cmp r1, r3, lsl #5` beside the live r0).  A 32-bit local
 *    of any type (u32, int, long, pointer, enum) is copy-propagated and folded
 *    into both consumers (476 bytes); a u16/s16 local materialises the value
 *    but narrows it (`lsl #21` + `lsr #16` shifter operands, 5 out).  Only
 *    the u64 local keeps the plain shift as a register temporary: its low
 *    word is what the u32 add and sub consume.  tools/permuter.py found the
 *    materialising temp (`temp(tmp1=head * 32)`, as u16); the width was a
 *    hand sweep.
 *  - THE TAIL MASK ORDER.  The entry's bit-31 half is read into its own
 *    local before the OR (`u32 hi = ent->unk_14 & 0x80000000;`), which is what
 *    loads +0x14 before surf->unk_08 (permuter `temp(tmp2=...)`).
 */
void func_0204DD08(struct Holder *h, int idx, void *src, void *sel,
                  u32 size, u16 head, u16 tail)
{
    struct Surf *surf;
    void *tmp;
    u32 off;
    u8 *ents;
    int max;
    int limit;
    int flag;
    u32 saved;

    off  = idx * sizeof(struct Ent);
    ents = (u8 *)h->ents;
    if (size >= 0x200) {
        size  = (u16)(size - 0x200);
        flag  = 1;
        max   = 0x100;
        limit = 0x2000;
    } else {
        flag  = 0;
        max   = 0x10;
        limit = 0x200;
    }

    func_02062AD4(src, &tmp);
    if (!func_02062A98(src, (void **)(&surf))) {
        return;
    }
    func_020637D4((u32 *)(ents + off));

    if (head != 0) {
        unsigned long long ofs = head * 32;
        if (surf->unk_08 > head * 32) {
            surf->unk_0c += ofs;
            surf->unk_08 -= ofs;
        }
    }
    if (tail != 0) {
        if (head + tail <= max) {
            if (surf->unk_08 > tail * 32) {
                surf->unk_08 = tail * 32;
            }
        }
    }
    if (size != 0) {
        if (surf->unk_08 + size > limit) {
            surf->unk_08 = limit - size;
        }
    }

    if (func_0204D9B4((u32)sel, 0)) {
        saved = func_02080C34();
        if (flag) func_0208068C();
        func_02063E54(surf, size, 1, (struct Ent *)(ents + off));
        if (flag) func_020801F8(saved);
    }
    if (func_0204D9B4((u32)sel, 1)) {
        saved = func_02080C74();
        if (flag) func_0208068C();
        func_02063E54(surf, size, 2, (struct Ent *)(ents + off));
        if (flag) func_0208083C(saved);
    }

    ((struct Ent *)((u8 *)h->ents + off))->unk_14 &= ~0x80000000;
    {
        u32 hi = ((struct Ent *)((u8 *)h->ents + off))->unk_14 & 0x80000000;
        ((struct Ent *)((u8 *)h->ents + off))->unk_14 = hi | (surf->unk_08 & ~0x80000000);
    }
}




/*
 * The one-surface sibling of func_0204DD08 (same entry table, same 0x200
 * large-layer split, same bracketed double upload through func_0204D9B4's
 * engine select), uploading through func_02063F4C instead of func_02063E54.
 * Returns nothing: the trailing read-modify-write leaves r0 as garbage.
 *
 * Levers, all measured (wave 10): the two out-locals are declared `b` then
 * `a` (func_02062A98's out first), which puts `a` at sp+4 as the image has
 * it; and the 0x200 test is written small-arm-first
 * (`if (size < 0x200) flag = 0; else {...}`), which is what orders the
 * predicated `movlo sl,#0` before `movhs sl,#1`.  Either alone leaves 4-6
 * bytes out.  `off = idx * sizeof(struct Ent)` as a byte-offset local and
 * the entry re-derived from h->ents at the end are func_0204DD08's pins.
 */
void func_0204DEE8(struct Holder *h, int idx, void *src, void *sel, u32 size)
{
    void *b;
    void *a;
    u32 off;
    struct Ent *ent;
    int flag;
    u32 saved;

    off = idx * sizeof(struct Ent);
    ent = (struct Ent *)((u8 *)h->ents + off);
    if (size < 0x200) {
        flag = 0;
    } else {
        size = (u16)(size - 0x200);
        flag = 1;
    }

    func_02062AD4(src, &a);
    if (!func_02062A98(src, &b)) {
        return;
    }
    func_020637D4((u32 *)ent);

    if (func_0204D9B4((u32)sel, 0)) {
        saved = func_02080C34();
        if (flag) func_0208068C();
        func_02063F4C(b, a, size, 1, (struct Out02063F4C *)ent);
        if (flag) func_020801F8(saved);
    }
    if (func_0204D9B4((u32)sel, 1)) {
        saved = func_02080C74();
        if (flag) func_0208068C();
        func_02063F4C(b, a, size, 2, (struct Out02063F4C *)ent);
        if (flag) func_0208083C(saved);
    }

    ((struct Ent *)((u8 *)h->ents + off))->unk_14 &= ~0x80000000;
}




void func_0204E010(void *ptr)
{
    func_020307B0(ptr);
}




/*
 * Allocate the 0x14-byte entry pool and mark every entry free.  The
 * allocation size is `count * sizeof(struct Entry)`, and the `mvn`-free
 * `mov r2, r4` is the alignment argument sharing the zero the loop counter
 * was just materialised into, so `i` must be spelled before the call, not
 * only in the `for` header.
 *
 * The file string at 0x020A7F74 is "clact.c" and the stacked fifth argument
 * is __LINE__ = 7494; it is declared as an extern array pinned by address,
 * never as a literal __FILE__.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204E01C.c \
 *       --func func_0204E01C --addr 0x0204E01C --cc 1.1p1 --arm
 */
struct Entry_0204E01C *func_0204E01C(u32 heap, u32 count)
{
    struct Entry_0204E01C *entries;
    u32 i;

    i = 0;
    entries = (struct Entry_0204E01C *)func_02030734(heap,
                                            count * sizeof(struct Entry_0204E01C), i,
                                            func_0204E01C_File, 7494);

    for (; i < count; i++) {
        entries[i].unk_10 = 1;
    }

    return entries;
}




/*
 * Publish the two handles of one 0x14-byte pool entry.  The entry is
 * addressed as `pool->entries[idx]` (the `mla` by 0x14 is the subscript,
 * not a byte offset), each handle is registered through its own registrar,
 * and only when both succeed is the entry's +0x10 slot cleared and 1
 * returned.  Either failure leaves the entry alone and returns 0.
 *
 * The two guards must be written nested (`if (ok1) { if (ok2) { ...; return
 * 1; } } return 0;`), not as two early-`return 0` guards and not as one
 * `||`.  Only the nested form leaves the success path as the fall-through
 * of the second `cmp`, which is what lets the store, the constant and the
 * return if-convert into `movne`/`strne`/`movne`/`popne` above a single
 * shared `mov r0, #0` tail.  Two early returns give an if-converted first
 * guard and no shared tail (76 bytes); `||` emits the failure block first
 * and duplicates the return (84 bytes).  Both arguments must be read
 * into locals before the first call: the `mov r5, r3` ahead of the `bl` is
 * the fourth argument being parked in a callee-saved register, which only
 * happens when it is live across the call as a plain value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204E074.c \
 *       --func func_0204E074 --addr 0x0204E074 --cc 1.1p1 --arm
 */
s32 func_0204E074(struct Pool *pool, s32 idx, void *a, void *b)
{
    struct Entry_0204E074 *entry = &pool->entries[idx];

    if (func_02062820((int)a, (int *)(&entry->unk_08)) != 0) {
        if (func_02062670(b, &entry->unk_0c) != 0) {
            entry->unk_10 = 0;
            return 1;
        }
    }
    return 0;
}




void func_0204E0C4(void *ptr)
{
    func_020307B0(ptr);
}




/*
 * Resolve a handle through func_02062A00 into a stack temporary and, only
 * on success, hand it to func_0204DACC together with the two stacked
 * arguments, then clear bit 31 of +0x3c in the 0x40-byte slot `idx` of the
 * table at `owner->unk_08`.
 *
 * The temporary must be a plain local whose address is taken: the `add r1,
 * sp, #4` before the first call and the `ldr r2, [sp, #4]` after it are the
 * out-parameter, and the `ldr r3, [sp, #0x18]` is the caller's fifth
 * argument being reloaded from the incoming stack area, which fixes the
 * arity at five.  Argument four reaches func_0204DACC's own stack slot and
 * argument five reaches its r3, so the two are swapped relative to this
 * function's own signature; that is the original's order, not a slip.
 *
 * The final read-modify-write must go through a named `struct Slot *`.
 * Written inline as `owner->slots[idx].unk_3c &= ~0x80000000`, the compiler
 * folds the constant 0x3c into the base and leaves the scaled index in both
 * the load and the store (`[r1, r5, lsl #6]`), three instructions wrong;
 * binding the element address to a local first forces `add r1, r0, r5, lsl
 * #6` once with an immediate-offset load and store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204E0D0.c \
 *       --func func_0204E0D0 --addr 0x0204E0D0 --cc 1.1p1 --arm
 */
void func_0204E0D0(struct Owner *owner, s32 idx, u32 handle, u32 a3, u32 a4)
{
    u32 value;
    struct Slot *slot;

    if (func_02062A00((struct NitroFileHeader *)handle, (void **)(&value)) != 0) {
        func_0204DACC((struct Res *)owner, idx, (struct Sink *)value, (struct Ovr *)a4, a3);
        slot = &owner->slots[idx];
        slot->unk_3c &= ~0x80000000;
    }
}


/*
 * Idempotent one-time init of the singleton at 0x02146A78: if it is already
 * live, return; otherwise run func_020461F4 and allocate a 0x26-byte record
 * from heap 0 into the global.
 *
 * The guard's load landing in r1 rather than r0 is the arity tell: the
 * incoming parameter is still live in r0 because it is forwarded unchanged
 * to func_020461F4, so the global's load has to go somewhere else.  Written
 * `void func_0204E130(void)` with `func_020461F4()`, the load takes r0 and
 * two bytes are wrong; an unused parameter does not do it either, since a
 * dead parameter frees its register immediately.  The caller at 0x020055BA
 * sets `movs r0, #0` before the `blx`, confirming the one argument.  The
 * heap id the allocator gets is a freshly materialised 0, not that
 * parameter, which is why the parameter is not saved across the call.
 *
 * The file string at 0x020A7F80 is "textprint.c", __LINE__ = 51.  The
 * alignment argument is `mov r2, r0`, the heap id's zero re-used, so heap
 * and align must both be spelled 0 with heap first.
 *
 * Byte-correct, capped at MATCH: the PC24 at +0x1c (func_020461F4) has no
 * witness outside 0204E130..0204E180.  This function is 0x020461F4's only
 * caller image-wide, so the `label` class is unavailable, the two are far
 * apart so no unit can make the site `local`, and there is no EXACT entry
 * for 0x020461F4 to serve as a `matched` witness.  It unsticks when
 * 0x020461F4 is decompiled to EXACT (it is a seven-register-push function
 * in another packet, not reachable inside this run's territory).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204E130.c \
 *       --func func_0204E130 --addr 0x0204E130 --cc 1.1p1 --arm
 */
void func_0204E130(u32 a)
{
    if (g_02146A78 == 0) {
        func_020461F4(a);
        g_02146A78 = func_02030734(0, 0x26, 0, func_0204E130_File, 51);
    }
}
