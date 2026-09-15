/*
 * function: func_0204D7E0
 * address:  0x0204D7E0
 * packet:   pkt_0204D768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
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
 * symbols:
 *   func_02034558  0x02034558  arm
 *   func_0204DA5C  0x0204DA5C  arm
 *   func_0204DCA8  0x0204DCA8  arm
 *   func_0204E01C  0x0204E01C  arm
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

struct Res {
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

extern void *func_02034558(u32 heapId, u32 kind, u32 a, u32 size, u32 b);
extern void *func_0204DA5C(u32 heapId, u32 count);
extern void *func_0204DCA8(u32 heapId, u32 count);
extern void *func_0204E01C(u32 heapId, u32 count);

void func_0204D7E0(struct Res *res, u32 heapId, const struct Cfg *cfg,
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
