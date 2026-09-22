/*
 * docs/families/cluster_02070360.h -- shared declarations for the
 * pseudo-family at 0x02070360..0x02070B64 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so this cluster is NOT a recovered original translation
 * unit; it was formed by address adjacency plus shared callees.  Unlike its
 * neighbour docs/families/cluster_02070B64.h, which turned out to be two
 * interleaved subsystems, this one is a SINGLE subsystem and a very coherent
 * one:
 *
 *   THE SKELETAL-ANIMATION SAMPLING LAYER of the 3D model renderer.  An
 *   animation resource is a header plus a per-node table of TRACK DESCRIPTORS;
 *   playing it means, once per frame per node, sampling each track at the
 *   current frame index and writing the results into the node's output block.
 *   The cluster holds the three layers of that:
 *
 *     - THE SAMPLERS (0x02070524, 0x02070624).  Two leaf functions, both
 *       `(base, flags, off, idx)`, that decode one track descriptor and return
 *       one interpolated value.  These are the bottom of the whole subsystem
 *       and both are now EXACT.
 *     - THE PER-NODE SAMPLING DRIVERS (0x02070434, 0x02070730 [in the
 *       adjacent packet, EXACT], 0x02070904 [EXACT]).  These walk one node's
 *       descriptor record, call the samplers once per track, and maintain the
 *       "track unchanged" bits of the output block's flags word.
 *     - THE CHANNEL BINDERS AND WALKERS (0x02070360, 0x02070830, 0x02070948,
 *       0x02070A24, 0x02070AFC).  These bind an animation resource to a model
 *       by NAME -- resolving each node/material/slot name through the
 *       0x0206Exxx resource accessors and filling a halfword slot table -- and
 *       then drive the bound channel each frame.
 *
 * Derived from the matched sources found with
 *   grep -l "address:  0x02070[3-9A]" src/matched/*.c
 * (func_02070524, func_02070624 -- both filed by this lane -- plus the
 * immediate neighbours func_02070730 and func_02070904 from pkt_0207010C,
 * and func_02070B64 from the next cluster, which is the caller of
 * func_02070A24 and func_02070AFC) and from the notes
 * docs/notes/func_02070360.c.txt, docs/notes/func_02070524.c.txt,
 * docs/notes/func_02070624.c.txt, docs/notes/func_02070A24.c.txt and
 * docs/notes/func_02070AFC.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrsh` proves signedness (there is no
 * immediate-offset unsigned halfword-sign-extend); `ldrh` proves unsigned
 * halfword; a plain `ldr` followed by a shift pair proves the FIELD is a
 * 32-bit word and the narrowing happens at the use.  Where two sources
 * disagree, the one whose code actually constrains the field wins.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * The cluster is SPLIT per function, as cluster_02070B64 is.  Measured so far:
 *
 *   `../2.0/sp2`:  func_02070524  func_02070624  func_02070730  func_02070AFC
 *                  func_02070360  func_02070830  func_02070948   (wave 10)
 *   dsi/1.1p1:     func_02070904
 *   either:        func_02070434  (byte-identical under both; filed 1.1p1)
 *
 * WAVE 10 CORRECTION: func_02070360 was listed as 1.1p1 on the strength of
 * its flat-body compile.  Written with the L3 inline helpers below it is
 * EXACT under ../2.0/sp2 and 204 bytes under 1.1p1: the pin question was
 * downstream of the source's inline structure.
 *
 * So: TRY ../2.0/sp2 FIRST in this range, but never assume it, and settle it
 * by SIZE before spending any spelling effort -- in this cluster the wrong
 * front end is always the wrong NUMBER of bytes, never merely the wrong bytes.
 *
 * THE RECOGNITION RULE, in the form this cluster shows it.  docs/FRONTEND-PINS.md
 * states the tell as "the image KEEPS a structure that the default front end
 * folds".  In this cluster it appears in a form that has already fooled one
 * lane, and it is worth stating explicitly:
 *
 *   THE SIGN OF THE SIZE GAP IS NOT PART OF THE TELL.  On func_02070524 the
 *   image PREDICATES a four-instruction guard body (`addeq` / `ldreq` /
 *   `ldreq` / `beq` at 0x020705F8) and dsi/1.1p1 keeps it as a branch, so the
 *   1.1p1 compile is four bytes LONG, not short.  docs/notes/func_02070524.c.txt
 *   read that inversion as evidence AGAINST the pin ("the image predicates, so
 *   this is 1.1p1 behaviour") and refused it; the refusal cost that note two
 *   whole passes and some twenty rejected spellings, and it was wrong.  Ask
 *   only "which front end gives the image's size", never "which direction is
 *   the gap".
 *
 *   The 2.0/sp2 rows here are all of the predication kind.  The one measured
 *   1.1p1 row that is NOT a spelling question, func_02070360, is the opposite:
 *   its four-byte hole is a MISSING RE-READ, and it is closed in the C by a
 *   `volatile` field, not by changing the compiler (see section 3).
 *
 * TWO ALLOCATION LEVERS, not front-end matters, that recur across the cluster
 * and are the difference between size-exact and byte-exact here:
 *
 *   L1.  A SUM SPELLED AS A COMPOUND ASSIGNMENT KEEPS ITS TARGET LIVE.
 *        `a += b;` leaves `a` live past its last read and lands the sum in the
 *        wrong register; `s32 s = a + b;` lets `a` die at the sum and
 *        reproduces the image.  This is what took func_02070624 from four
 *        differing instructions to zero, and the same shape is the untried
 *        lever named at the end of docs/notes/func_02070AFC.c.txt (there in
 *        the opposite direction: a value that must stay live).
 *   L2.  WHICH ARM OF A TWO-ARM TAIL IS WRITTEN FIRST DECIDES THE OPERAND
 *        ORDER OF THE OTHER.  On func_02070524 writing the s16 arm first and
 *        the u32 arm as the `else` emits the s16 arm's two address
 *        computations in the image's order (`add` then `lsl`); writing them
 *        the other way round emits `lsl` then `add`, and no respelling of the
 *        arm itself reaches it.  Check this before assuming a tail residue is
 *        a spelling question inside the arm you are looking at.
 *
 * ISA: ARM throughout.  Always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_02070360_H
#define CLUSTER_02070360_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;

/* ================================================================== *
 * 0.  Externals and data objects
 * ================================================================== */

/* The resource-accessor layer this cluster binds through.  All ARM.
   func_0206E7EC compares a name record against a table entry and returns the
   matching slot index, or a negative value for "no match" -- the sign test is
   what func_02070360's `if (slot >= 0)` guard is.
   Evidenced by func_02070360 (0x02070404).                                  */
extern s32   func_0206E7EC(void *name, void *ent);

/* Returns the entry record for a bound slot; its [0] halfword is the slot's
   own base index and its [1] halfword carries the "already absolute" flag in
   bit 0.  Evidenced by func_02070AFC (0x02070B1C) and func_02070A24.        */
extern void *func_0206E62C(void *p);

/* The animation-handle accessors, shared with cluster_02070B64: func_0206EA58
   returns a u8 * descriptor record, func_0206EA00 / func_0206EA2C map an index
   byte out of it to a value.  func_02070B64 is the caller that feeds
   func_02070A24 and func_02070AFC from them.                                */
extern void *func_0206EA58(void *h, u32 a, u32 b);
extern u32   func_0206EA00(void *h, u32 i);
extern u32   func_0206EA2C(void *h, u32 i);

/* SDK, ARM.  func_02070360 clears the slot table with it.                   */
extern void  MIi_CpuClear16(u16 value, void *dest, u32 size);   /* 0x02082A48 */

/* Two rodata words, both ABS32 through a pool word at the end of their own
   function.  data_020A8230 is func_02070360's channel-kind seed, stored to
   ctx->f0c; data_020A8220 is func_02070BD8's, one cluster along.            */
extern u32 data_020A8230;                       /* 0x020A8230  data */

/* The cluster's own functions, as the neighbours declare them.              */
extern s32  func_02070524(u32 *base, u32 flags, u32 off, u32 idx);
extern u32  func_02070624(u32 *base, u32 flags, u32 off, u32 idx);
extern void func_02070A24(void *p, u32 v, void *ctx);
extern void func_02070AFC(void *p, u32 v, void *ctx);

/* ================================================================== *
 * 1.  The track descriptor, and the FLAGS word that decodes it
 *
 * This is the one structure the whole cluster turns on, and it is fully
 * constrained by func_02070524 and func_02070624, which are byte-exact.
 *
 * A track is a (flags, off) PAIR of words in the node's descriptor record.
 * `off` is a byte offset from the animation resource base to the key array,
 * EXCEPT when the inline bit is set, in which case `off` IS the value and
 * there is no array at all.  `flags` decodes as:
 *
 *   bit 29  (0x20000000)  INLINE.  Return `off` unchanged; the track is a
 *                         constant and has no keys.  Tested first, before
 *                         the base is even formed.
 *   bits 31:30            KEY STRIDE.  00 = one key per frame (index the
 *                         array directly); 01 (0x40000000) = one key per two
 *                         frames, an odd index averages its two neighbours;
 *                         10/11 = one key per four frames, and the low two
 *                         bits of the index select between the direct read,
 *                         the midpoint average and the 3:1 weighted average.
 *   bit 28  (0x10000000)  KEY WIDTH, func_02070524 ONLY.  Set = s16 keys,
 *                         clear = u32 keys.  func_02070624 has no width
 *                         selector: its keys are ALWAYS a pair of s16 packed
 *                         into one word, which is why it is a separate
 *                         function rather than a mode of the first.
 *   bits 15:0             KEY COUNT.  An index past it is clamped to the
 *                         last whole key, which is what the `idx > n` arms
 *                         compute.
 *
 * NOTE the clamp arms read `idx > n` on the RAW index while the in-range arms
 * shift it first; that asymmetry is real and is what the two `bhi` at
 * 0x02070560 and 0x02070584 encode.
 * ================================================================== */
struct Track { u32 flags; u32 off; };

/* The six-track record func_02070730 samples one node through.  Field order
   is fixed by that function's call order: scale pair, rotation, translation
   pair.  All three sampler call sites pass (node, r->fXX, r->fYY, t).       */
struct NodeTracks {
    struct Track scale_x;       /* 0x00 -> func_02070524 */
    struct Track scale_y;       /* 0x08 -> func_02070524 */
    struct Track rotate;        /* 0x10 -> func_02070624 */
    struct Track trans_x;       /* 0x18 -> func_02070524 */
    struct Track trans_y;       /* 0x20 -> func_02070524 */
};

/* The per-node output block the drivers write.  The flags word at +0x00
   carries three "unchanged since last frame" bits, one per track group, and
   the renderer skips the corresponding matrix rebuild when the bit is set.
   The SENTINELS that set them are themselves evidence of the fixed-point
   format: 0x1000 is 1.0 in 20.12 (an unchanged SCALE), and 0x10000000 is the
   rotation sampler's "no rotation" return.                                  */
struct NodeOut {
    u32 flags;                  /* 0x00  bit 0 scale, bit 1 rotation,
                                         bit 2 translation                   */
    u32 pad04[5];
    s32 scale_x, scale_y;       /* 0x18, 0x1c   sentinel 0x1000 each         */
    u32 rotate;                 /* 0x20  two s16 packed, sentinel 0x10000000 */
    s32 trans_x, trans_y;       /* 0x24, 0x28   no sentinel; zero/zero       */
};

/* ================================================================== *
 * 2.  The node descriptor table
 *
 * Every walker in the cluster reaches a node's record the same way, and the
 * idiom is worth writing down once because it is re-derived in four places:
 *
 *     tbl = (u8 *)node + 8;                   -- the table always at +8
 *     if (tbl != 0 && idx < node->b09) {      -- b09 is the node COUNT
 *         u8 *p = tbl + node->h0e;            -- h0e the table's own offset
 *         rec = p + *(u16 *)p * idx + 4;      -- *(u16 *)p is the STRIDE
 *     } else rec = 0;
 *
 * The `tbl != 0` test is against a value the compiler can see is `node + 8`
 * and therefore never null; it is emitted anyway (`cmp r5, #0` at 0x020703C4
 * in func_02070360), so it is in the original source and must be written.
 * Do not simplify it away.
 * ================================================================== */
struct NodeTable {
    u8  pad00[8];
    u8  b08;
    u8  b09;            /* 0x09  node count.  SEE SECTION 3 -- volatile      */
    u8  pad0a[4];
    u16 h0e;            /* 0x0e  byte offset from +8 to the table proper     */
};

/* The bound-channel context the binders fill.  +0x1a is the halfword slot
   table, +0x19 its count; a bound slot is stored as `i | 0x100`, the 0x100
   bit marking the entry as used.  Same `| 0x100` convention as
   func_02070BD8's SlotTab in the adjacent cluster.                          */
struct Channel {
    u8  pad00[8];
    u32 f08;
    u32 f0c;            /* 0x0c  seeded from data_020A8230                   */
    u8  pad10[9];
    u8  b19;            /* 0x19  slot count, copied from the resource        */
    u16 h1a[1];         /* 0x1a  the slot table, b19 halfwords               */
};

/* ================================================================== *
 * 3.  THE `volatile` RULE FOR THIS CLUSTER
 *
 * Two independent functions here need a field spelled `volatile` to reproduce,
 * and in both cases the reason is the same and is NOT a hardware register:
 *
 *   - `struct NodeTable.b09` in func_02070360.  The image reads `[sb,#9]`
 *     THREE times -- at entry, at the loop top and at the loop bottom -- across
 *     a `bl func_0206E7EC` in the loop body.  Without `volatile` the compiler
 *     proves the callee cannot write it, keeps the count live in a register
 *     and drops two of the three reads, which is exactly the four-byte hole
 *     docs/notes/func_02070360.c.txt spent two passes attributing to the front
 *     end.  With it the function is size-exact.
 *   - both fields of the state word pair in func_02070904 (already EXACT, and
 *     its header records the same finding): without `volatile` on BOTH, mwcc
 *     hoists the +0x00 load above the +0x10 store and reallocates.
 *
 * This is docs/idioms/a-global-reread-across-a-call-to-a-visible-static-needs-volatile.md
 * applied to a STRUCT FIELD rather than a global, and in this cluster it is
 * the first thing to try whenever a compile is short by exactly the size of
 * the loads it is missing.  It does not mean the field is hardware; it means
 * the original translation unit could not prove the callee left it alone.
 * ================================================================== */

/* ================================================================== *
 * 4.  Status of the cluster's ten functions (2026-09-22, wave 7)
 *
 *   0x02070360  212  EXACT  ../2.0/sp2 (wave 10).  GetName/Lookup inline
 *                          helpers; see below.
 *   0x02070434  240  EXACT  1.1p1 == ../2.0/sp2 (wave 10).  GetRec inline
 *                          helper called with (u16)idx; u32 frame local.
 *   0x02070524  256  EXACT  the scalar sampler.  ../2.0/sp2.
 *   0x02070624  268  EXACT  the s16-pair sampler.  ../2.0/sp2.
 *   0x02070730  256  EXACT  the per-node driver (packet pkt_0207010C).
 *   0x02070830  212  EXACT  ../2.0/sp2 (wave 10), 0x02070360's twin.
 *   0x02070904  216  EXACT  forwards to 0x02070730 (packet pkt_0207010C).
 *   0x02070948  220  EXACT  ../2.0/sp2 (wave 10), dictionary at src+0xc,
 *                          also stores src into ctx->f08.
 *   0x02070A24  216  MATCH  src/pending/ (not this lane).
 *   0x02070AFC  104  EXACT  ../2.0/sp2 (wave 10).  u16 locals, `>>= 1`.
 *
 * WAVE 10 LEVERS (2026-09-22), which closed all five open rows:
 *
 *   L3.  THE BINDERS ARE TWO INLINE HELPERS.  GetName(src, i) -- the +8 (or
 *        +0xc) dictionary idiom returning `q + *(u16 *)(q + 2) + i * 0x10`
 *        or 0 -- and Lookup(names, ent) returning func_0206E7EC(names + 4,
 *        ent) or -1.  Written as helpers, ../2.0/sp2 produces the image's
 *        prologue window (separate `mov r0,#0` fill and `mov r6,#0` counter:
 *        the pin's kept-constants tell) where the flat body at 1.1p1 was
 *        stuck at 10 instructions.  The loop is a plain `for (i = 0; i <
 *        src->b09; i++)`; `u32 i;` is declared BEFORE `u8 *names;`.  The
 *        volatile count byte is still required.
 *   L4.  A SHIFT PAIR (<<15, >>16) ON A u16 IS `v >>= 1` ON A u16 LOCAL.
 *        0x02070AFC's two "15-bit truncations" are `ofs >>= 1; base >>= 1;`
 *        on u16 locals (the NitroSystem 4-colour palette-offset rule); the
 *        explicit shift spelling leaves an r0/r1 exchange.
 *   L5.  AN UNSIGNED INDEX COMPARE ON A NARROWED VALUE IS A u32 HELPER
 *        PARAMETER.  0x02070434's `cmp b09, idx, lsr #16` / `bls` comes from
 *        GetRec(node, u32 idx) called as GetRec(node, (u16)idx); a u16
 *        parameter compares signed.
 *
 * THE HANDLER TABLE.  data_020A8230/8228/822C are not scalars: 0x020A8220..
 * holds driver pointers (0x020A8228 = &func_02070904, 0x020A822C =
 * &func_02070B64, 0x020A8230 = &func_02070434) and, from 0x020A8240, pairs of
 * a 4-character kind tag and a binder (0x020A8244 = func_02070360,
 * 0x020A824C = func_02070948, 0x020A8254 = func_02070830).  Each binder
 * installs its driver into ctx->f0c.
 *
 * THE SHAPE, ONCE, for the three unattempted 212/220-byte binders
 * (0x02070830, 0x02070948, and 0x02070360 which is measured): all three open
 * `push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}` / `mov sl, r0` / `cmp r2,
 * #0` / `ldrne r0, [r2, #8]`, i.e. ten saved registers, the context in sl and
 * the same `if (arg != 0 && arg->f08 != 0) p = (u8 *)arg + arg->f08; else p =
 * 0;` optional-pointer preamble.  Deriving one derives the others; start from
 * the func_02070360 body in docs/notes/func_02070360.c.txt, which is correct C
 * at the right size, and expect the same `volatile` count field.
 * ================================================================== */

#endif /* CLUSTER_02070360_H */
