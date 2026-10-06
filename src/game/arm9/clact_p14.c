/*
 * file:     clact_p14.c
 * unit:     yes
 * function: func_0204D7E0, func_0204D8AC, func_0204D9B4, func_0204D9D4, func_0204DA5C
 * address:  0x0204D7E0
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
 *   func_02034558  0x02034558  arm
 *   func_0204DCA8  0x0204DCA8  arm
 *   func_0204E01C  0x0204E01C  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204DC64  0x0204DC64  arm
 *   func_0204E010  0x0204E010  arm
 *   func_0204E0C4  0x0204E0C4  arm
 *   func_020345DC  0x020345DC  arm
 *   s_clact_c      0x020A7F74  data
 *   func_02049250  0x02049250  arm
 *   func_020834C0  0x020834C0  arm
 *   sub_02030734   0x02030734  arm
 *   sub_020307B0   0x020307B0  arm
 *   sub_02034630  0x02034630  arm
 */
struct Bank;
struct Entry;
struct Struct020345DC;
struct ArcFile;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

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

struct Rec {
    u8  pad_00[0x2c];
    struct Sentinel a;      /* 0x2c */
    struct Sentinel b;      /* 0x34 */
    u32 unk_3c_0  : 31;     /* 0x3c */
    u32 unk_3c_31 : 1;
};

extern struct Bank *func_02034558(u32 heapId, u32 kind, u32 flags, u32 base, u32 b);
extern void *func_0204DCA8(u32 heapId, u32 count);
extern struct Entry *func_0204E01C(u32 heap, u32 count);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204DC64(void *ptr);
extern void func_0204E010(void *ptr);
extern void func_0204E0C4(void *ptr);
extern void func_020345DC(struct Struct020345DC *obj);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern u32 sub_020307B0(void *p);
extern void func_020834C0(const void *src, void *dest);
extern void  sub_02034630(struct Sentinel *p);
u32 func_0204D9B4(u32 a, u32 b);
void *func_0204D9D4(void *owner, u32 which, u32 compressed, u32 heapId);
void *func_0204DA5C(u32 heapId, u32 count);
extern char s_clact_c[];


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
    struct Rec *arr;

    arr = sub_02030734(heapId, count << 6, 0, s_clact_c, 0x1bbe);

    for (i = 0; i < count; i++) {
        struct Rec *r = &arr[i];
        r->unk_3c_31 = 1;
        sub_02034630(&r->a);
        sub_02034630(&r->b);
    }

    return arr;
}
