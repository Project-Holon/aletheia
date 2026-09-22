/*
 * docs/families/cluster_02066740.h -- shared declarations for the
 * pseudo-family cluster_02066740 (0x02066740..0x02067998 in the ARM9 image).
 *
 * PSEUDO-FAMILY.  The upper half of the ARM9 image carries no __FILE__
 * anchors, so this cluster was formed by address adjacency plus shared
 * callees and data objects, NOT by a string anchor.  Two objects hold it
 * together and are the whole basis of the grouping:
 *
 *   g_02148B20  the "cell bank": a three-word control block
 *               { callback, count, array } whose array is a run of
 *               0x30-byte cells.  Every function from 0x02066740 to
 *               0x02066AE0 touches it.
 *   g_02148B48  the "OAM rig": the composer's own context pointer, read by
 *               everything from 0x02066E30 to 0x02067998.
 *
 * WHAT THE SUBSYSTEM IS.  Two cooperating halves of the same 2D sprite /
 * cell-animation renderer:
 *
 *   PART 1, 0x02066740..0x02066B84 -- the CELL BANK.  A fixed array of
 *     0x30-byte animation cells with a published control block, a
 *     stride-0x30 accessor (func_02066878), per-cell init / release /
 *     allocate helpers, and a per-frame sweep (func_02066998) that drives
 *     each live cell's three channels through the bank's callback.  The
 *     per-cell worker routines live OUTSIDE the cluster, in
 *     src/matched/unit_020640B0.c (func_020640B0 clear, func_020640CC
 *     channel set, func_020640D4 channel query) -- that shared callee set
 *     is the second half of the clustering evidence.
 *
 *   PART 2, 0x02066B84..0x02067998 -- the OAM / G2D COMPOSER.  Decodes an
 *     OAM attribute word's shape/size pair against the two 3x4 u16 tables
 *     at 0x020A17F0 (objWidth) and 0x020A17D8 (objHeight), applies the rig's
 *     flip mask and affine matrix, and emits the geometry-engine command
 *     stream (MTX_SCALE / MTX_TRANSLATE / BEGIN_VTXS / TEXCOORD / VTX_10 /
 *     END_VTXS).  func_02067998 is its list driver and is the one function
 *     of this half that is EXACT.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration is
 * derived from an EXACT/EXACT* file in src/matched, and the evidencing
 * function is named in the comment beside it.  Where the matched sources
 * disagree on a spelling (different lanes wrote them), the spelling kept
 * here is the one the byte evidence constrains; the looser one is noted.
 *
 * Addresses are Black-image addresses throughout.
 */

#ifndef CLUSTER_02066740_H
#define CLUSTER_02066740_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   short s16;
typedef signed   int   s32;

/* ================================================================== *
 * PART 1: the cell bank, 0x02066740..0x02066B84
 * ================================================================== */

/* One 0x30-byte cell.  The field set below is the UNION of what the three
 * matched files pin; nothing in src/matched names +0x00..+0x0b, which is
 * why they are still padding.
 *
 * +0x0c..+0x2c: nine consecutive u32 words.  Both func_02066934 and
 * sub_02066B38 clear exactly these nine, field by field, which is what
 * fixes them as nine separate u32 members rather than one object -- a
 * MI_CpuFill8 over the sub-range would be one call, not nine `str`.
 *
 * +0x1c is the occupancy flag: func_02066AE0 scans for the first cell whose
 * +0x1c is not 1 and claims it by storing 1.  It is spelled u32 there (a
 * plain `ldr`/`cmp #1`), so the nine-word view and the flag view are the
 * same word and agree.
 *
 * +0x0c..+0x18 are also the four caller-supplied words func_02066890
 * stores from its stacked arguments, so those four are payload rather than
 * scratch; +0x1c..+0x2c is the part only the bank itself writes. */
struct Cell {
    u8  pad_00[0x0c];
    u32 unk_0c;     /* +0x0c  func_02066890: stacked argument 5 */
    u32 unk_10;     /* +0x10  func_02066890: stacked argument 6 */
    u32 unk_14;     /* +0x14  func_02066890: stacked argument 7 */
    u32 unk_18;     /* +0x18  func_02066890: stacked argument 8 */
    u32 used;       /* +0x1c  func_02066AE0: occupancy, 1 == taken.
                     *        func_02066998 reads it as the "live" gate. */
    u32 unk_20;     /* +0x20  func_02066998: the per-frame "changed" mask,
                     *        zeroed at the end of every sweep of a cell */
    u32 unk_24;     /* +0x24  func_02066998: the per-channel request mask,
                     *        bits 0..2; a serviced channel's bit is cleared */
    u32 unk_28;     /* +0x28  func_02066998: a base added to +0x14 / +0x10 */
    u32 unk_2c;     /* +0x2c  func_02066998: the callback's 4th argument */
};

/* The published control block at 0x02148B20.  Three words.  func_02066934
 * writes all three; func_02066878 and sub_02066B38 read only +0x08;
 * func_02066AE0 reads +0x04 and +0x08; func_02066998 calls through +0x00.
 *
 * SPELLING NOTE.  src/matched/func_02066878.c declares +0x08 as a `u32
 * base` it casts to u8* and scales by 0x30; src/matched/sub_02066B38.c
 * declares it `struct Cell *cells` and subscripts it.  Both are EXACT, so
 * the byte evidence does not choose.  The `struct Cell *` form is kept here
 * because it is the one that makes the 0x30 stride implicit; the `u8 *`
 * form is what you want when reproducing the `mla rN, i, #0x30, base`
 * shape, which is how EVERY indexed access in this half is emitted (0x30 is
 * not a power of two, so it is always one multiply-accumulate, never a
 * shift and an add -- see sub_02066B38's header). */
struct Bank {
    void       *cb;      /* +0x00  func_02066934 stores it; func_02066998
                          *        calls it as
                          *        u32 (*)(s32 tblval, u32 chan, u32 base,
                          *                u32 arg) through `blx` */
    u32         count;   /* +0x04  func_02066934: the cell count.  Every
                          *        loop that reads it compares UNSIGNED
                          *        (`bls`/`blo`), so it is u32, not s32. */
    struct Cell *cells;  /* +0x08  func_02066934: the array base */
};

extern struct Bank g_02148B20;          /* 0x02148B20, func_02066934 */

/* The per-cell worker trio, defined OUTSIDE this cluster in
 * src/matched/unit_020640B0.c.  They are the shared callees that made this
 * an address cluster in the first place. */
extern void func_020640B0(struct Cell *c);              /* 0x020640B0, clear */
extern void func_020640CC(struct Cell *c, u32 chan, u32 val);  /* 0x020640CC */
extern s32  func_020640D4(const s32 *tbl, u32 i);       /* 0x020640D4 */

/* Read the bank's 0x1e'th word.  src/matched/func_02066740.c spells it
 * `int *p` / `p[0x1e]`, i.e. byte offset 0x78 of whatever it is handed;
 * with no caller decompiled the parameter's real type is unconstrained. */
extern int func_02066740(int *p);

/* A pure forwarder: four parameters declared, NONE passed on.  The `bl` is
 * the first instruction and r0..r3 are left as they arrive
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * The declared arity is what makes the compiler emit no argument moves. */
extern void func_02066748(int a0, int a1, int a2, int a3);

/* THE STRIDE ACCESSOR.  `(u8 *)g_02148B20.cells + i * 0x30`.  This is the
 * shape every other function in PART 1 inlines by hand: func_02066890,
 * func_02066AE0 and sub_02066B38 each emit `mov rN, #0x30` / `mla rM, i,
 * rN, base` rather than calling it, so it is almost certainly a `static
 * inline` (or a macro) in the original translation unit that also has this
 * one out-of-line copy. */
extern u8 *func_02066878(u32 i);

/* Initialise cell `idx`: clear it, then set each of the three channels whose
 * value is not the -1 sentinel, then store the four stacked words at
 * +0x0c..+0x18.  STILL DIFF; see docs/notes/pkt_02066890.c.txt.  The residue
 * is the sentinel: the image materialises `mvn r0, #0` fresh at each of the
 * three guards and compares register-to-register, while 1.1p1 folds
 * `v != 0xffffffff` into `cmn v, #1` (and CSEs the constant off the 0x30 it
 * already holds, `sub r0, r4, #0x31`). */
extern void func_02066890(u32 idx, u32 a, u32 b, u32 c,
                          u32 d, u32 e, u32 f, u32 g);

/* Publish the pool (callback, array, count -- IN THAT WRITE ORDER, which is
 * what fuses the three stores into one `stm`) and then clear every cell's
 * nine words to ZERO.  Two scheduling points are load-bearing and are
 * spelled out in src/matched/func_02066934.c's header: `i = 0` before the
 * three bank stores, and the nine stores written as plain `0` literals. */
extern void func_02066934(struct Cell *cells, u32 n, void *cb);

/* The per-frame sweep: for every cell whose `used` is set, service its three
 * channels through the bank callback and clear the serviced bits.  STILL
 * DIFF; see docs/notes/pkt_02066998.c.txt.  Its own loop index and byte
 * offset are BOTH stack-spilled (sp+4 and sp+0) across the whole body, which
 * a pair of `volatile u32` locals reproduces. */
extern void func_02066998(void);

/* The three-entry s32 table func_02066998 indexes with the channel number,
 * `ldr sb, [r5, r7, lsl #2]`. */
extern const s32 tbl_020A1808[3];       /* 0x020A1808, func_02066998 */

/* Claim the first cell whose `used` is not 1, return its index, or -1.
 * STILL DIFF (docs/notes/pkt_02066AE0.c.txt): byte-for-byte right except
 * that 1.1p1 IF-CONVERTS the five-instruction claim block into
 * `movne`/`mlane`/`movne`/`strne`/`bxne` where the image branches over it
 * with `beq`.  The entry test must be `count > i` on the ZERO counter, not
 * `count != 0`: the image's `bls` is the loop's own unsigned pre-test
 * hoisted (the same lever func_02067998 needed). */
extern int func_02066AE0(void);

/* Build a cell: take the accessor's pointer, store the -1 sentinel at +0x24
 * and the two arguments at +0x28 and +0x2c, and RETURN the pointer.  Note
 * this is the only function in the cluster that writes +0x24 with the
 * sentinel rather than a bit mask.  src/matched/func_02066ABC.c declares
 * four parameters and uses only a1 and a2. */
extern int func_02066ABC(int a0, int a1, int a2, int a3);

/* Release cell `idx`: hand it to func_020640B0, then clear the same nine
 * words func_02066934 clears.  The neighbouring +0x00..+0x08 are left
 * alone, so this is field-by-field clearing, not a fill over a sub-range. */
extern void sub_02066B38(u32 idx);

/* ================================================================== *
 * PART 2: the OAM / G2D composer, 0x02066B84..0x02067998
 * ================================================================== */

/* The two object-extent tables.  3 shapes x 4 sizes of u16, an 8-byte row
 * stride; func_02066B84, func_02066E30, func_0206775C and func_02067080 all
 * index them out of ONE `and rN, attr, #0xC000C000`, with
 *     shape = (s32)(w & 0x0000c000) >> 14      (an ASR)
 *     size  = (w & 0xc0000000) >> 30           (an LSR)
 * and the element reached as `base + (shape << 3)` plus a REGISTER offset of
 * `size << 1`.  The asymmetry (signed shift for shape, unsigned for size) is
 * pinned by the image's own `asr`/`lsr` pair and is not a free choice. */
extern const u16 tbl_020A17F0[3][4];    /* 0x020A17F0 objWidth,  func_02066E30 */
extern const u16 tbl_020A17D8[3][4];    /* 0x020A17D8 objHeight, func_02066E30 */

/* The composer's rig.  func_02067998 is the one EXACT file that pins any of
 * it: +0x30 is the gate and +0x38..+0x3c the three-halfword scratch row.
 * The other offsets are from the DIFF notes and are NOT byte-attested:
 *   +0x08  a base func_0206775C forwards as `f08 + 0xc`
 *   +0x14, +0x18  two more forwarded words
 *   +0x24  the flip mask func_0206775C tests per axis
 *   +0x40  the argument func_0206775C hands func_0207D8E0, spelled
 *          `(char *)g_02148B48 + 0x40` -- a pointer ADD, not a field load
 *          (a `->f40` costs a second `ldr` and 4 bytes; see the note). */
struct Rig {
    u32 pad_00[0x0c];
    u32 gate;        /* +0x30  func_02067998: re-armed to 1 each row, so a
                      *        hook may clear it to skip exactly one row */
    u32 pad_34;
    u16 row[3];      /* +0x38, +0x3a, +0x3c  the six-byte scratch row */
};

extern struct Rig *g_02148B48;          /* 0x02148B48, func_02067998 */

/* The caller's hook pair.  Both optional (each is tested against 0), both
 * called with (rig, list, index).  Only +0x20 and +0x24 are constrained. */
struct Hooks {
    u32 pad_00[8];
    void (*pre)(struct Rig *, void *, u32);    /* +0x20  func_02067998 */
    void (*post)(struct Rig *, void *, u32);   /* +0x24  func_02067998 */
};

/* The row list: a u16 count and a pointer to a run of SIX-BYTE rows.  The
 * stride is `i * 6` computed by hand in func_02067998, never a subscript. */
struct List {
    u16  count;      /* +0x00 */
    u16  pad_02;
    u16 *rows;       /* +0x04 */
};

/* The descriptor decoder: reads the packed attribute pair, fills a six-word
 * texture-coordinate buffer from the two extent tables and the two tables at
 * 0x020A1844 / 0x020A1874, and writes the geometry ports.  STILL DIFF, 40
 * bytes short; docs/notes/pkt_02066B84.c.txt.  The next lever recorded there
 * is contracting `a[0]`/`a[1]` into ONE `ldm` (bind both in the same
 * declaration) and keeping `v & 0xC000C000` in a named temporary. */
extern void func_02066B84(u32 *a, u32 *b, u32 c, u32 d, u32 *out);

/* Returns the word at 0x020A8218, the per-quad polygon-counter increment
 * func_02066E30 adds to the render context's +0x04.  src/matched spells the
 * address as a cast constant, not a relocation, and declares four unused
 * parameters. */
extern int func_02066E20(int p0, int p1, int p2, int p3);
extern const u32 g_020A8218;            /* 0x020A8218, func_02066E20 */

/* The 3D-geometry emitter: one textured quad per call.  Seven parameters
 * (x, y, z, the OAM row pointer and three descriptor words forwarded
 * untouched) and a 0x1c-byte frame whose sp+4..sp+0x18 is the six-word UV
 * buffer func_02066B84 fills -- passed as the call's FIFTH, STACKED
 * argument.  STILL DIFF, 576/592; docs/notes/pkt_02066E30.c.txt.
 *
 * THE BLOCKER THE BRIEF ASKS ABOUT: the image RELOADS the &g_02148B2C pool
 * word at each of its three uses (0x02066EA0, 0x02066EF4, 0x02067030) from
 * the ONE pool entry at 0x0206706C, and 1.1p1 -O4,p hoists it into a
 * callee-saved register, which costs the extra push and permutes every
 * register.  WHAT THE MATCHED SIBLINGS SAY ABOUT HOW THAT BASE IS HELD:
 * nothing in this cluster holds a pool base in a callee-saved register at
 * all.  The three matched functions that touch a global (func_02066934,
 * sub_02066B38, func_02067998) each load their pool word ONCE and are leaf-
 * or near-leaf; func_02067998, the only one with a loop, RE-READS the
 * `g_02148B48` pool word inside the loop body (`g_02148B48->gate = 1;`
 * written against the global, NOT against the `rig` local it already holds)
 * and that re-read is EXACTLY what makes it EXACT.  So the family's own
 * evidence says the base is NOT held: it is spelled as the global at every
 * use and re-loaded.  func_02066E30's note records `*(volatile Ctx *)&g_...`
 * and a per-store cast constant as already measured at 576/386, i.e. the
 * volatile route does not reproduce it -- but the func_02067998 shape (a
 * plain, non-volatile global re-read where a held local was available) has
 * NOT been tried on this row and is the one sibling-attested lever left. */
extern void func_02066E30(s32 x, s32 y, s32 z, u32 *oam,
                          u32 a4, u32 a5, u32 a6);
extern u32 g_02148B2C;                  /* 0x02148B2C, the render context:
                                         * +0x04 polygon counter, +0x08 gate */

/* The affine placement step: decodes the same shape/size pair, runs the
 * 2x2 fixed-point matrix over the pen with a 64-bit accumulator, and folds
 * the result back into the OAM word.  STILL DIFF, 668/676;
 * docs/notes/pkt_02066E30.c.txt carries the full source.  Two levers that
 * this cluster established and that generalise: the aliasing guard survives
 * only through a POINTER CAST, `if (d == (struct Vec2 *)(void *)&p)`, never
 * through a `volatile`; and the copy-back guard is written against the
 * TEMPORARY (`if (d == &t)`), not against `&p`. */
extern void func_02067080(const void *m, volatile u32 *oam, const void *ofs);

/* The per-row entry: sign-extends the packed 9-bit x and 8-bit y, mirrors
 * each axis about the sprite's own extent when the rig's +0x24 flip mask is
 * live, writes the two flip bits back, and tails into func_02066E30.  STILL
 * DIFF; docs/notes/pkt_02066E30.c.txt.  It is a `../2.0/sp2` PIN row, the
 * only one in this cluster: under the pin the same source is 572 bytes with
 * the whole prologue and every callee-saved assignment byte-exact.  Its
 * `row` parameter must be `volatile u32 *` (the image re-reads the packed
 * word eight times) and each axis is truncated TWICE,
 * `x = (s32)(s16)(u16)x;`, not once. */
extern void func_0206775C(u16 *row);

/* The list driver, EXACT.  Two levers, both in
 * src/matched/func_02067998.c's header: the gate store must PRECEDE the read
 * of `lst->rows`, and the entry test is `lst->count <= i` against the ZERO
 * counter (giving `popls`), not `count == 0` (which gives `popeq`).  That
 * second lever is the same one func_02066AE0 and func_02066998 need and is
 * the most reusable finding in this cluster. */
extern void func_02067998(struct Hooks *h, struct List *lst);

#endif /* CLUSTER_02066740_H */
