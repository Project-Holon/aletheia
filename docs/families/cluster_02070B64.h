/*
 * docs/families/cluster_02070B64.h -- shared declarations for the
 * pseudo-family at 0x02070B64..0x020712A8 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so this cluster is NOT a recovered original translation
 * unit.  It was formed by address adjacency plus shared callees and data
 * objects, and it is in fact TWO interleaved subsystems:
 *
 *   A. A GRAPHICS-OBJECT UPLOAD LAYER.  0x02070B64 (an animation-record
 *      reader through the func_0206EAxx handle accessors), 0x02070BD8 (an
 *      OAM/slot-table initialiser), 0x02070C24 (a bitmap-bit reader),
 *      0x02070C5C / 0x02070D18 (two flag-driven fan-outs of
 *      func_0206DDA4(reg, ptr, count) register-block uploads over one object)
 *      and 0x02070DDC (the flags+vector writer that feeds them, through the
 *      two globals g_02148DB0 and g_02149BC0).
 *
 *   B. THE (DST, SRC) MATRIX-CONSTRUCTOR FAMILY.  0x02070F2C, 0x02071034,
 *      0x02071104, 0x02071180, 0x020711C8, 0x020712A8 (and, continuing past
 *      this cluster's end, 0x02071360, 0x020713A4 and the whole
 *      0x02071CDC..0x02072548 run of docs/notes/pkt_02071DD4.c.txt and of
 *      docs/families/cluster_02071EAC.h).  EVERY member has the SAME
 *      signature `void f(struct DST *d, struct SRC *s)` and writes exactly
 *      the same six destination words -- f00, f04, f10, f14, f30, f34 -- from
 *      the same source record.  They differ only in WHICH terms are non-zero
 *      and in whether the reduction is 32-bit (`mul`) or 64-bit
 *      (`smull`/`smlal` with the family's `>> 12`, which folds to
 *      `lsr #0xc` + `orr ..., lsl #20`).  The full variant table is in
 *      section 3 below.
 *
 * Derived from the 8 matched sources found with
 *   grep -l "address:  0x02070[B-F]\|address:  0x020710\|address:  0x020711" src/matched/*.c
 * (func_02070B64, func_02070BD8, func_02070C24, func_02070D18, func_02070DDC,
 * func_02070F2C, func_02071034, func_02071180) and from the notes
 * docs/notes/pkt_02070C5C.c.txt, docs/notes/pkt_02070DDC.c.txt,
 * docs/notes/pkt_02071104.c.txt and docs/notes/pkt_02071DD4.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrsh` proves signedness (there is no
 * immediate-offset unsigned halfword-sign-extend); `ldrh` proves unsigned
 * halfword; a plain `ldr` feeding an `smull` proves the field is a 32-bit
 * signed word.  Where two matched files disagree, the file whose code actually
 * constrains the field wins and the losing spelling is recorded beside it as
 * `WAS:`.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * The cluster is SPLIT, and the split is per function, not per subsystem.
 * SIX of the eight matched sources are byte-exact only under `--cc ../2.0/sp2`:
 *
 *   func_02070B64  func_02070BD8  func_02070D18  func_02070DDC
 *   func_02070F2C  func_02071180
 *
 * and TWO are byte-exact under the project default dsi/1.1p1:
 *
 *   func_02070C24  func_02071034
 *
 * So: TRY ../2.0/sp2 FIRST in this range, but never assume it.  The recognition
 * rule is the one docs/FRONTEND-PINS.md states, and in this cluster it appears
 * in exactly two forms:
 *
 *   * "KEPT CONSTANTS" (func_02071180, and func_02072320 / func_020713A4 /
 *     func_02071EFC in the sibling cluster).  The image materialises a small
 *     constant -- nearly always the zero -- LATE, AFTER a store that would
 *     otherwise have been merged with it.  1.1p1 -O4,p hoists the zero above
 *     that store and merges the pair into one `stm rD, {rA, rB}`, losing four
 *     bytes and shifting the whole body.  SYMPTOM TO RECOGNISE INSTANTLY: a
 *     compile that is exactly four bytes SHORT of the image and contains an
 *     `stm` the image does not have.  Change the compiler, not the source.
 *
 *   * "KEPT BRANCHES" (func_02070D18, func_02070DDC).  The image writes two
 *     arms of a fan-out out SEPARATELY, each closing with its own `bl` and its
 *     own unconditional `b` to a shared join; or it keeps a `beq` over a
 *     three-instruction guard body that re-reads a word just stored.  1.1p1
 *     -O4,p cross-jumps the pair into ONE call site, or predicates the guard
 *     and forwards the still-live value, losing eight bytes each time.
 *     SYMPTOM: a compile eight bytes short whose first half is byte-identical
 *     and whose shortfall is entirely inside an if/else over two calls to the
 *     SAME function differing only in their immediates.  This is the wall
 *     docs/notes/pkt_02070C5C.c.txt and the 0x02071510 section of
 *     docs/notes/pkt_02071104.c.txt both hit.  Change the compiler.
 *
 * A third tell, NOT a pin, appears throughout subsystem B and is fixed in the
 * C instead: the image KEEPS a shifted angle value live in a callee-saved
 * register across two calls, while the naive C rematerialises it.  See L4 in
 * section 4.
 *
 * ISA: ARM throughout.  Always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_02070B64_H
#define CLUSTER_02070B64_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;
typedef signed   long long s64;

/* ================================================================== *
 * 0.  Externals and data objects
 * ================================================================== */

/* The register-block upload primitive.  THE most-called callee of subsystem A
   (`label x385` image-wide, so both its call sites in any one function resolve
   without help).  Argument 1 is a small command/register immediate -- the
   image only ever uses 0x19, 0x1a, 0x1b and 0x1c in this cluster -- argument 2
   a pointer INTO the object, argument 3 a word count.
   Evidenced by func_02070C5C, func_02070D18, func_02071510, func_02071F20. */
extern void func_0206DDA4(u32 cmd, void *p, u32 n);

/* The animation-handle accessors func_02070B64 reads a record through.
   func_0206EA58 returns a u8 * record; its result's [2] and [3] bytes are
   indices into the two lookup accessors, and 0xff at [3] is the terminator. */
extern void *func_0206EA58(void *h, u32 a, u32 b);
extern u32   func_0206EA00(void *h, u32 i);
extern u32   func_0206EA2C(void *h, u32 i);
extern void  func_02070A24(void *p, u32 v, void *ctx);
extern void  func_02070AFC(void *p, u32 v, void *ctx);

/* The hardware fixed-point divider, SDK FX_DivAsync / FX_GetDivResult.  BOTH
   SPELLINGS ARE IN THE TREE AND BOTH ARE EXACT: func_02070F2C and
   func_02071034 declare them by their SDK names, func_020721BC and
   func_02072374 by address.  The name is free; the prototype is not.
   The protocol is always: start the division, do unrelated work, read the
   quotient back.  A member that needs two quotients starts the SECOND
   division before reading the FIRST back is NOT the shape -- the image always
   reads a result before starting the next divide.  */
extern void FX_DivAsync(s32 num, s32 den);      /* 0x0207C930 arm */
extern s32  FX_GetDivResult(void);              /* 0x0207C86C arm */

/* func_02070BD8's slot-table seed word.  ABS32 through a pool word at
   0x02070C20; resolves `data_table x8`. */
extern u32 data_020A8220;                       /* 0x020A8220  data */

/* The two globals func_02070DDC drives.  g_02148DB0 is a POINTER to a bank
   whose bitmap starts at +0xc4; g_02149BC0 is an ARRAY of 0x18-byte rows
   indexed by the same bit number.  Both are pool ABS32 sites. */
extern struct Bank *g_02148DB0;                 /* 0x02148DB0  data */
extern struct Row   g_02149BC0[];               /* 0x02149BC0  data */

/* ================================================================== *
 * 1.  Subsystem A -- the upload object
 *
 * Field evidence, one function per line:
 *   +0x00   the FLAG word.  RE-READ before every test in func_02070C5C /
 *           func_02070D18 (`ldr r0, [r4]` at 0x02070C64 and again at
 *           0x02070CB8): the flags are NOT cached across the calls, so the C
 *           must re-read `*(u32 *)a` after each fan-out block.  Bits used:
 *           0 (guard on the +0x04 upload), 1 (selects 0x19 vs 0x1a), 2
 *           (selects the first-latch arm), 3 and 5 (the leading block of
 *           func_02070D18 only).  func_02070DDC SETS bits 0, 3, 0x10 and 0x20
 *           in the same word.
 *   +0x04   a 3-word vector uploaded with command 0x1b, count 3.
 *   +0x10   a 3-word vector uploaded with command 0x1b, count 3
 *           (func_02070D18's bit-5 arm), and the destination of
 *           func_02070DDC's `o->v10 = g_02149BC0[j].v` struct assignment.
 *   +0x28   the 0xc-word / 9-word block uploaded with command 0x19 or 0x1a.
 *   +0x4c   the 3-word block uploaded with command 0x1c.
 * ================================================================== */
struct UpObj {
    u32 flags;          /* 0x00 */
    s32 f04, f08, f0c;  /* 0x04  the 0x1b/3 vector                        */
    s32 f10, f14, f18;  /* 0x10  the second 0x1b/3 vector                 */
    u8  pad_1c[0x0c];
    u8  f28[0x24];      /* 0x28  the 0x19 (0xc words) / 0x1a (9 words) blk */
    u8  f4c[0x0c];      /* 0x4c  the 0x1c/3 block                          */
};

/* func_02070DDC's own narrower view of the head of the same object.  Recorded
   separately per the adjudication rule -- only the loads constrain it. */
struct Owner {
    u32 flags;          /* 0x00 */
    s32 f04, f08, f0c;  /* 0x04  written from src[0..2]                    */
    struct Vec v10;     /* 0x10  written whole, ldm/stm, from g_02149BC0   */
};

struct Vec  { s32 a, b, c; };
struct Row  { struct Vec v; s32 pad[3]; };      /* 0x18 bytes              */
struct Bank { u8 pad_00[0xc4]; u32 bits[1]; };  /* bitmap at +0xc4         */

/* The 4-byte descriptor func_02070DDC's third argument points at. */
struct Desc { u8 f00; u8 idx; u8 slot; u8 mode; };

/* func_02070BD8's slot table.  +0x19 is the COUNT byte, copied from
   src[0x17]; +0x1a is the halfword slot array, filled `i | 0x100`. */
struct SlotTab {
    u8  pad_00[8];
    u32 f8;             /* 0x08  the caller's word                        */
    u32 fc;             /* 0x0c  data_020A8220                            */
    u8  pad_10[9];
    u8  f19;            /* 0x19  count, from src[0x17]                    */
    u16 f1a[1];         /* 0x1a  i | 0x100, f19 of them                   */
};

/* func_02070C24's bitmap owner.  f0 is SIGNED (`asr ip, r3, #0xc`) but the
   bit number built from it is UNSIGNED (`lsr r1, r2, #5`) -- making the local
   signed too is one byte wrong.  The bitmap starts at +0xc of the Bmp. */
struct Bmp  { u8 pad_00[6]; u16 h6; };
struct BmpOwner { s32 f0; u32 f4; struct Bmp *p8; };

/* ================================================================== *
 * 2.  Subsystem B -- the (DST, SRC) matrix-constructor family
 *
 * ONE source record and ONE destination record, shared by every member of
 * the family in this cluster AND in cluster_02071EAC.h.  Every matched
 * source in both clusters declares these two, byte for byte the same.
 *
 * SRC field evidence:
 *   +0x18  s32.  Plain `ldr`, fed straight to an `smull` (0x020711F4 /
 *          0x02072094).  A 32-bit SIGNED word.
 *   +0x1c  s32.  Likewise (0x020711FC / 0x020720A4).  NOTE: several members
 *          READ IT TWICE, once for the f14 store and again for the scale
 *          chain; 1.1p1 -O4,p forwards the live value and drops the second
 *          load, costing four bytes.  See L5.
 *   +0x20  s16.  `ldrsh r0, [sb, #0x20]` (0x020711F8) -- signed halfword,
 *          and `ldrsh` with an immediate offset is the only encoding that
 *          exists, so this is decisive.
 *   +0x22  s16.  `ldrsh r5, [sb, #0x22]` (0x020711F0).  Likewise.
 *   +0x24  s32.  The first CROSS term.  Present only in the members that
 *          carry shear (0x02071104, 0x020711C8's f30/f34 via f18/f1c,
 *          0x02072068, 0x020721BC, 0x02072320).
 *   +0x28  s32.  The second cross term.
 *   +0x2c  u16.  `ldrh r2, [r5, #0x2c]` (0x020712B0) -- UNSIGNED halfword.
 *          Always widened to s32 at the use; `<< 12` in the members that feed
 *          the divider, a plain multiplicand in those that do not.
 *   +0x2e  u16.  `ldrh r1, [r5, #0x2e]` (0x020712B4).  Likewise.
 *
 * DST field evidence: six stored words at +0x00, +0x04, +0x10, +0x14, +0x30
 * and +0x34, all s32, all plain `str`.  NOTHING else in the record is ever
 * written by this family, and the gaps (+0x08..+0x0c and +0x18..+0x2c) are
 * never touched, so they stay padding.
 * ================================================================== */
struct SRC {
    u8  pad_00[0x18];
    s32 f18;            /* 0x18 */
    s32 f1c;            /* 0x1c */
    s16 f20;            /* 0x20 */
    s16 f22;            /* 0x22 */
    s32 f24;            /* 0x24  cross term (WAS: u32 in func_02071034)    */
    s32 f28;            /* 0x28  cross term (WAS: u32 in func_02071034)    */
    u16 f2c;            /* 0x2c */
    u16 f2e;            /* 0x2e */
};

struct DST {
    s32 f00;            /* 0x00 */
    s32 f04;            /* 0x04 */
    u8  pad_08[8];
    s32 f10;            /* 0x10 */
    s32 f14;            /* 0x14 */
    u8  pad_18[0x18];
    s32 f30;            /* 0x30 */
    s32 f34;            /* 0x34 */
};

/* ================================================================== *
 * 3.  The family variant table
 *
 * Every member is `void f(struct DST *d, struct SRC *s)`.  Read this before
 * writing any of them: the member you are on is almost always one already-
 * solved member plus or minus one term.
 *
 *  addr        B   cc          2x2 block source        f30/f34 shape
 *  ----------  --- ----------  ----------------------  --------------------
 *  02070F2C    264 ../2.0/sp2  f18/f1c x f20/f22, s64  s64 cross, FX both
 *  02071034    212 1.1p1       f20/f22 direct, FX      32-bit, f24/f28 <<4
 *  02071104    124 ?OPEN       f18/f1c direct copy     s64 cross, NO FX
 *  02071180     72 ../2.0/sp2  unit 0x1000, zeroes     32-bit, f24/f28 <<4
 *  020711C8    224 ?OPEN       f18/f1c x f20/f22, s64  32-bit, f18/f1c sums
 *  020712A8    184 ?OPEN       f22 direct, FX          32-bit, f20+-f22 <<3
 *  02071360     68 DIFF 4      f18/f1c direct copy     32-bit, f24/f28 <<4
 *  020713A4     36 ../2.0/sp2  unit 0x1000, zeroes     zero
 *  ----------  --- ----------  (cluster_02071EAC.h continues the table)
 *
 * TWO REDUCTIONS, and which one a member uses is visible at a glance:
 *   32-bit: `mul rD, rA, rB` then `lsl rD, rD, #3` or `#4`.  The C is a plain
 *           `(s32)s->f2c * n` with the shift written on the PRODUCT.
 *   64-bit: `smull r2, r1, rA, rB` then `lsr rX, r2, #0xc` then
 *           `orr rX, rX, r1, lsl #20`.  The C is `(s32)(((s64)a * b) >> 12)`.
 *           A `>> 8` reduction instead folds to `lsr #8` + `lsl #24`
 *           (0x02071130/0x02071134), and that says the shift is 8, not 12.
 * ================================================================== */

/* ================================================================== *
 * 4.  The levers, adjudicated.  Every one of these is a MEASURED finding
 *     from a matched source or a note in this family; none is a guess.
 * ================================================================== */

/* L1  SMULL/SMLAL OPERAND ORDER NAMES THE ADDITIVE TERM.  In a two-product
 *     64-bit sum, mwcc gives the `smull` to the SECOND operand of the `+` and
 *     the `smlal` to the first.  func_020721BC: writing `f24*f22 + f28*f20`
 *     is exact; the other order reverses all four loads, 12 bytes.
 *
 * L2  A NAMED LOCAL BEFORE THE STORE, NOT A FOLDED EXPRESSION.  func_0207229C:
 *     the high half of an smull must be bound to a local computed BEFORE the
 *     store it feeds, or the compiler CSEs two field reads and the function
 *     comes out four bytes short.
 *
 * L3  THE NEGATED SUM MUST BE TWO OR THREE SEPARATE STATEMENTS.
 *     `n = a + b; n = 0 - n; n = n + 0x1000;` is 184 bytes; the folded
 *     `(0 - (a + b)) + 0x1000` becomes one `rsb rD, rD, #0x1000` and is 180.
 *     func_02071034 and the 0x020712A8 section of docs/notes/pkt_02071104.c.txt
 *     both measure this.  Whenever the image shows a `rsb rD, rD, #0`
 *     FOLLOWED BY a separate `add rD, rD, #0x1000` (0x02071314/0x02071318),
 *     the C is spelled out; a single `rsb rD, rD, #0x1000` means it is folded.
 *
 * L4  THE TWO `<< 12` SHIFTED ANGLE VALUES ARE NAMED LOCALS LIVE ACROSS THE
 *     WHOLE BODY.  Every member that calls the divider TWICE shows
 *     `lsl rA, r2, #0xc` / `lsl rB, r1, #0xc` ONCE near the top and then
 *     `mov r0, rB / mov r1, rA` at the first call and `mov r0, rA / mov r1, rB`
 *     at the second (0x020712C4/0x020712F8, 0x020711E4/0x02071250,
 *     0x02072084/0x020720E8).  Spelling the two calls inline makes the
 *     compiler re-read f2c/f2e and re-shift at the second call, freeing two
 *     callee-saved registers and NARROWING THE PUSH LIST, which is a 40-byte
 *     residue.  Bind them:
 *         f12 = (s32)s->f2c << 12;
 *         e12 = (s32)s->f2e << 12;
 *         FX_DivAsync(e12, f12);   ...   FX_DivAsync(f12, e12);
 *     docs/notes/pkt_02072374.c.txt measures 43 -> 13 from this one lever.
 *
 * L5  A FIELD THE IMAGE READS TWICE NEEDS A VOLATILE RE-READ.  1.1p1 -O4,p
 *     forwards a value it still holds live and drops the second load, which
 *     is exactly four bytes.  `*(volatile s32 *)&s->f1c` at the second use
 *     restores it (0x02071360, measured 64 -> 68).  Do NOT declare the FIELD
 *     volatile when a GUARD also reads it -- that re-reads for the guard too
 *     and comes out four bytes long (func_02071F20's L1).
 *
 * L6  THE ACCUMULATOR OF A COMMUTATIVE CHAIN IS ITS SECOND OPERAND.
 *     func_02071034: the `<< 4` product must be the SECOND operand of the `+`
 *     at f34; first, and the `<< 3` product takes the accumulator and every
 *     register in the block swaps.
 *
 * L7  DECLARATION ORDER IS INSENSITIVE IN THIS FAMILY.  Six groupings measured
 *     on 0x02072374 and five on 0x020712A8, all identical.  Do not spend a
 *     probe on it; spend it on STATEMENT order instead, which is what actually
 *     sets the IR's value-creation order.
 *
 * L8  THE RESIDUE FLOOR OF THIS FAMILY IS A MULTIPLY-CLASS REGISTER SWAP.
 *     Three rows (0x02071360 at 4, 0x02072374 at 7, 0x02071C14 at 13) sit on
 *     the same wall: which of two just-freed registers receives a multiply's
 *     result versus holds its operand, decided after linearisation and not
 *     source-addressable.  If a member is size-exact and the only differing
 *     bytes are the register fields of `smull`/`mul`/`lsr`/`orr`/`rsb`, it is
 *     this class; the permuter is the tool, not another hand spelling.
 */

#endif /* CLUSTER_02070B64_H */
