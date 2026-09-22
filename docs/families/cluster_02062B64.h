/*
 * docs/families/cluster_02062B64.h -- shared declarations for the pseudo-family
 * at 0x02062B64..0x02062D08 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so this cluster is NOT a recovered original translation
 * unit; it was formed by address adjacency plus shared callees and data
 * objects.  All three members belong to the NNS G2D layer and they form a
 * complete little pipeline over one loaded NITRO file:
 *
 *   func_02062B64  find a block by its four-character signature
 *   func_02062BAC  turn that block's stored offsets into absolute addresses
 *   func_02062BF4  step the animation that block describes
 *
 * The NITRO container shape is fixed by func_02062B64 and is worth stating
 * once: a file header {u32 magic; u32 unk04; u32 fileSize; u16 headerSize;
 * u16 numBlocks}, then `numBlocks` blocks starting at `headerSize`, each
 * {u32 signature; u32 size} where `size` covers the whole block, so the walk
 * is a plain byte advance and not a stride.
 *
 * Derived from src/matched/func_02062B64.c, src/matched/func_02062BAC.c and
 * src/matched/func_02062BF4.c, and from docs/notes/pkt_02062BF4.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrsb`/`ldrsh` prove signedness; a shift pair of
 * unequal amounts proves a bitfield's width and position; a plain `ldr`
 * followed by a shift pair proves the FIELD is 32-bit and the narrowing happens
 * at the use.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * TWO of this cluster's three functions are byte-exact only under
 * `--cc ../2.0/sp2`:
 *
 *   func_02062BAC   func_02062BF4
 *
 * func_02062B64 is dsi/1.1p1, so the pin must be read off the residue and not
 * assumed from the neighbour.  Unusually for this project, the tell here is
 * NOT the "kept constants" / wide push list of docs/FRONTEND-PINS.md.  Both
 * rows are size-exact under 1.1p1 with a small residue, and in both cases the
 * residue is a SCHEDULE:
 *
 *   func_02062BAC   1.1p1 hoists the `ldrh` of the count above the `add`/`str`
 *                   that fixes up the array pointer, and pushes the
 *                   `mov ip, #0` down past the compare.  14 concrete bytes;
 *                   ../1.2/sp2 is 4 bytes out; ../2.0/sp2 is exact.
 *   func_02062BF4   1.1p1 moves an independent `ldr r1, [r4, #0x1c]` up into
 *                   the load-delay slot of `ldr r0, [r4, #8]`, splitting the
 *                   image's `ldr / eor / str / ldr` into `ldr / ldr / eor /
 *                   str`.  Nine mismatched instructions; ../1.2/sp2 is
 *                   forty-seven; ../2.0/sp2 leaves three, and those three are
 *                   a separate, spellable problem (see below).
 *
 * SYMPTOM TO RECOGNISE INSTANTLY: a compile that is size-exact with every
 * instruction present and correct, but with two independent memory operations
 * in the wrong ORDER around an arithmetic op.  Change the compiler, not the
 * source.  The permuter is the right tool to rule allocation out first -- on
 * both rows `--explain` reports NO register substitution at all, which is the
 * signature of a schedule or an instruction-selection residue rather than a
 * colouring one.
 *
 * TWO SPELLING WALLS IN THIS CLUSTER, both worth knowing before writing C:
 *
 *   A. THE RANGE FOLD (func_02062BF4).  mwccarm folds a disjunction over two
 *      CONSECUTIVE integers into a range test: `mode == 3 || mode == 4`
 *      becomes `sub r0, r0, #3 / cmp r0, #1 / bhi`.  The image has the
 *      unfolded `cmp r0, #3 / cmpne r0, #4 / bne`.  No respelling of the
 *      disjunction escapes it, and the permuter cannot either (hill walks 5
 *      bytes down to 2 and then exhausts 275 singles), because no
 *      value-preserving mutation undoes a constant fold.  What works is
 *      forcing the condition to be materialised as a VALUE first:
 *
 *          if (mode == 3 || mode == 4 ? 1 : 0) { ... }
 *
 *      Non-consecutive pairs need nothing: the same function's
 *      `mode == 2 || mode == 4` is written plainly and comes out `cmp` /
 *      `cmpne` on its own.  Consecutive constants fold; others do not.
 *
 *   B. POINTER-FIRST ADDITION (func_02062BAC).  The image relocates an offset
 *      with `add r2, r0, r2` -- the OBJECT POINTER in the left slot.  Every
 *      spelling whose left operand is an integer (`x += (u32)t`,
 *      `x = (u32)t + x`, and the same through a hoisted `u32 *e`) gives
 *      `add r2, r2, r0`.  Declaring the array as `u8 **` and writing
 *      `t->offsets[i] = (u8 *)t + (u32)t->offsets[i]` makes the object the
 *      pointer operand of pointer-plus-integer, which this front end always
 *      issues left-first.  Operand order here names the TYPE, not the
 *      temporary -- the pointer-typed companion to
 *      docs/idioms/commutative-operand-order-names-the-temporary.md.
 *
 * ISA: ARM throughout.  This is unusual for game code (the ARM9 static module
 * is Thumb almost everywhere) and is itself a cluster property worth knowing:
 * always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_02062B64_H
#define CLUSTER_02062B64_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;

/* ================================================================== *
 * 1.  The NITRO container, fixed by func_02062B64
 * ================================================================== */

struct NitroBlock {
    u32 signature;              /* 0x00  four ASCII characters               */
    u32 size;                   /* 0x04  the WHOLE block, header included    */
};

struct NitroFileHeader {
    u32 magic;                  /* 0x00                                      */
    u32 unk04;                  /* 0x04                                      */
    u32 fileSize;               /* 0x08                                      */
    u16 headerSize;             /* 0x0c  where the first block starts        */
    u16 numBlocks;              /* 0x0e                                      */
};

/* ================================================================== *
 * 2.  The offset-fixup header, fixed by func_02062BAC
 *
 * A block that has just been read off the card stores its interior pointers
 * as offsets from the block's own start.  This header is (count, array), and
 * the ARRAY POINTER IS ITSELF AN OFFSET -- it is relocated first, before the
 * loop that relocates the entries it points at.
 *
 * Declared `u8 **` and not `u32 *` on purpose; see wall B in the pin section.
 * ================================================================== */
struct Tbl {
    u16   count;                /* 0x00  read with ldrh, unsigned            */
    u16   pad02;
    u8  **offsets;              /* 0x04  an offset until fixed up            */
};

/* ================================================================== *
 * 3.  struct Sub -- the frame table func_02062BF4 clamps against
 *
 * Reached through Slider.sub (+0x1C).  Two halfword counts and a base:
 *   +0x00  h0, the FULL frame count.  The end-of-table bound is
 *          ptr_0C + (h0 << 3) - 8, i.e. the last record of a stride-8 table.
 *   +0x02  h2, a SECOND count used for the same bound computation on the
 *          mode 3/4 path.  Two different counts over one table is what makes
 *          the two bound computations in the function distinct rather than a
 *          CSE the compiler lost.
 *   +0x08  the playback mode, consulted whenever Slider.field_18 is zero.
 *   +0x0c  the base of the stride-8 frame table.
 * ================================================================== */
struct Sub {
    u16 h0;                     /* 0x00  frame count (tail clamp)            */
    u16 h2;                     /* 0x02  frame count (mode 3/4 guard)        */
    u32 pad04;
    u32 field_08;               /* 0x08  playback mode                       */
    u32 ptr_0C;                 /* 0x0c  stride-8 frame table base           */
};

/* ================================================================== *
 * 4.  struct Slider -- the player state
 *
 *   +0x00  the playback CURSOR, an absolute address into the frame table.
 *          Clamped into [sub->ptr_0C, sub->ptr_0C + (sub->h0 << 3) - 8] at
 *          the end of every step.
 *   +0x08  a one-bit flag toggled with `^= 1` on the mode 3/4 path only.
 *   +0x0c  cleared to 0 when the mode is neither 2 nor 4.
 *   +0x10  callback argument 2.
 *   +0x18  the playback mode OVERRIDE; 0 means "ask sub->field_08".  The
 *          `m = s->field_18; if (m == 0) m = s->sub->field_08;` pair is read
 *          TWICE per step, because the callback between the two reads may
 *          have written either field -- this is why getMode is `static
 *          inline` and called twice rather than hoisted to a local.
 *   +0x1c  the frame table (struct Sub *).
 *   +0x20  == 1 arms the callback.
 *   +0x24  callback argument 1.
 *   +0x28  the callback itself, invoked with `blx`.
 * ================================================================== */
typedef void (*SliderCb)(u32 arg1, u32 arg2);

struct Slider {
    u32         pos;            /* 0x00  playback cursor                     */
    u32         pad04;
    u32         field_08;       /* 0x08  toggled flag                        */
    u32         field_0C;       /* 0x0c                                      */
    u32         field_10;       /* 0x10  callback argument 2                 */
    u32         pad14;
    u32         field_18;       /* 0x18  mode override, 0 = use sub          */
    struct Sub *sub;            /* 0x1c                                      */
    u32         field_20;       /* 0x20  == 1 arms the callback              */
    u32         field_24;       /* 0x24  callback argument 1                 */
    SliderCb    cb_28;          /* 0x28                                      */
};

/* The mode read, spelled once.  Written `static inline` and CALLED TWICE in
   func_02062BF4 rather than hoisted: the callback in between may write either
   field, and a single hoisted local loses the second pair of loads. */
/* static inline u32 getMode(struct Slider *s) {
       u32 m = s->field_18;
       if (m == 0) m = s->sub->field_08;
       return m;
   }                                                                          */

/* ================================================================== *
 * 5.  Prototypes
 * ================================================================== */
extern void *func_02062B64(struct NitroFileHeader *file, u32 signature);
extern void  func_02062BAC(struct Tbl *t);
extern void  func_02062BF4(struct Slider *s);
extern void  func_02062F90(struct Slider *s);   /* the mode 2/4 hand-off     */

/* ================================================================== *
 * 6.  Constants
 * ================================================================== */
#define G2D_FRAME_STRIDE   8    /* `add r0, r1, r0, lsl #3` then `sub #8`    */
#define G2D_MODE_FLIP_LO   3    /* the CONSECUTIVE pair -- see wall A        */
#define G2D_MODE_FLIP_HI   4
#define G2D_MODE_STEP_A    2    /* the non-consecutive pair, no fold         */
#define G2D_MODE_STEP_B    4

#endif /* CLUSTER_02062B64_H */
