/*
 * docs/families/cluster_02071EAC.h -- shared declarations for the
 * pseudo-family at 0x02071EAC..0x02072440 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  This cluster is the DENSE CORE of the
 * (DST, SRC) matrix-constructor family whose outer members live in
 * docs/families/cluster_02070B64.h.  Unlike its neighbour it is NOT two
 * subsystems: every one of its nine members but the caller at 0x02071F20 has
 * the identical signature
 *
 *     void f(struct DST *d, struct SRC *s);
 *
 * and writes exactly the same six destination words -- f00, f04, f10, f14,
 * f30 and f34 -- out of the same source record.  They differ ONLY in which
 * terms are non-zero and in whether the reduction is 32-bit or 64-bit.  The
 * variant table in section 2 is therefore the whole cluster: the member you
 * are working on is almost always one already-solved member plus or minus a
 * term, and the right first move is to copy the nearest solved sibling and
 * edit it, not to write C from the disassembly.
 *
 * The two functions that are NOT constructors are the two CALLERS, and they
 * are what the family exists for: 0x02071F20 (filed EXACT) and 0x02072548
 * build a 0x4c-byte command record on the stack, fill its 2x3 matrix block by
 * dispatching on the low three bits of the object's flag word through the
 * pointer table whose window starts at data_020A8458, apply the object's
 * f30/f34 scales to the two rows, and hand the record to func_0206DDA4.  SO:
 * the constructors ARE the entries of that table, and the `struct DST *`
 * every one of them takes is `&r.f08`, a slice of that stack record -- which
 * is why the record's f08..f3c region and the DST's f00..f34 region are the
 * same six offsets shifted by eight.  The table is verified in section 0
 * below and it is ONE 22-entry object spanning BOTH clusters, not an
 * eight-entry one; each caller reaches a different eight-entry window of it.
 *
 * Derived from the 6 matched sources found with
 *   grep -l "address:  0x02071[EF]\|address:  0x020720\|address:  0x02072[1-4]" src/matched/*.c
 * (func_02071EFC, func_02071F20, func_020721BC, func_0207229C, func_02072320,
 * unit_02072440) and from the notes docs/notes/func_02071EFC.c.txt,
 * docs/notes/pkt_02071DD4.c.txt, docs/notes/pkt_02071F20.c.txt and
 * docs/notes/pkt_02072374.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrsh` proves signedness, `ldrh` proves unsigned
 * halfword, a plain `ldr` feeding an `smull` proves a signed 32-bit word, and
 * an `asr rD, rS, #0x1f` beside a `umull`/`mla` triple proves a SIXTY-FOUR-BIT
 * operand (see L-A in section 3, which is what closed 0x02072068).
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * The cluster is SPLIT, and it is split the same way its neighbour is: per
 * function, not per subsystem.  TWO of the six matched sources are byte-exact
 * only under `--cc ../2.0/sp2`:
 *
 *   func_02071EFC   func_02072320
 *
 * and FOUR are byte-exact under the project default dsi/1.1p1:
 *
 *   func_02071F20   func_020721BC   func_0207229C   unit_02072440
 *
 * and the two closed this wave, func_02072068 and func_02072374, are BOTH
 * default-1.1p1.  So in THIS cluster the default is the majority and
 * ../2.0/sp2 is the exception -- the reverse of cluster_02070B64.h, where the
 * pin is the majority.  DO NOT CARRY A PIN ACROSS THE BOUNDARY.
 *
 * The recognition rule is the "KEPT CONSTANTS" tell of docs/FRONTEND-PINS.md,
 * and in this cluster it appears in exactly one form: WHERE THE ZERO IS
 * MATERIALISED.  Both pinned members are constant-only writers.  The image
 * materialises the unit scale 0x1000 FIRST and the zero LATE, AFTER the store
 * that would otherwise have been merged with it:
 *
 *   func_02071EFC  `mov r2, #0x1000` (01 2a a0 e3) at 0x02071EFC, `str r2,
 *                  [r0]`, and only then `mov r1, #0` (00 10 a0 e3) at
 *                  0x02071F04.  1.1p1 -O4,p schedules the zero FIRST -- same
 *                  36 bytes, 9 concrete out, under all ten spellings
 *                  docs/notes/func_02071EFC.c.txt measures.
 *   func_02072320  `str r2, [r0]` at 0x02072328 and `str r2, [r0, #0x14]` at
 *                  0x0207232C, then `mov lr, #0` (00 e0 a0 e3) at 0x02072330.
 *                  1.1p1 hoists the zero and MERGES the first two stores into
 *                  one `stm r0, {r2, lr}`: 80 bytes against the image's 84.
 *
 * SYMPTOM TO RECOGNISE INSTANTLY: a compile that is exactly four bytes SHORT
 * of the image and contains an `stm rD, {rA, rB}` the image does not have, or
 * that is the right size but has the `mov rD, #0` above the first store
 * instead of below it.  Change the compiler, not the source; store order (all
 * six permutations), a `z` local, `d->f14 = d->f00` and hoisting all three
 * constants were each measured against this wall and the merge survives every
 * one.  Note also func_02072320's `push {r3, lr}` / `pop {r3, pc}` with NO
 * call in the body -- lr spent as a scratch, which is exactly what the merge
 * denies.
 *
 * AND THE CONVERSE, WHICH COST THIS CLUSTER THREE PASSES.  A member that is
 * size-exact and differs only in REGISTER FIELDS is NOT a pin candidate, no
 * matter how much better one front end scores than the other.  Rule 2 of
 * docs/FRONTEND-PINS.md requires the pinned front end to produce the BYTES.
 * docs/notes/pkt_02072374.c.txt spent three lanes measuring ../2.0/sp2 at 7-8
 * against 1.1p1's 14 on 0x02072374 and rightly declined the pin; the residue
 * turned out to be one statement reorder in the C, and once it was made BOTH
 * front ends give 0.  See L-E.
 *
 * ISA: ARM throughout.  Always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_02071EAC_H
#define CLUSTER_02071EAC_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   short     s16;
typedef signed   int       s32;
typedef signed   long long s64;

/* ================================================================== *
 * 0.  Externals and data objects
 * ================================================================== */

/* The hardware fixed-point divider, SDK FX_DivAsync / FX_GetDivResult.  BOTH
   SPELLINGS ARE IN THE TREE AND BOTH ARE EXACT: func_02070F2C and
   func_02071034 (the neighbouring cluster) declare them by their SDK names,
   func_020721BC, func_02072068, func_02072374 and unit_02072440 by address.
   The name is free; the prototype is not.  The protocol is always: start the
   division, do unrelated work, read the quotient back -- and a member that
   needs two quotients always reads the first BEFORE starting the second. */
extern void func_0207C930(s32 num, s32 den);    /* 0x0207C930 arm, FX_DivAsync     */
extern s32  func_0207C86C(void);                /* 0x0207C86C arm, FX_GetDivResult */

/* The register-block upload primitive the two callers finish with.
   `label x380` image-wide, so its call sites resolve without help. */
extern void func_0206DDA4(u32 hdr, s32 *body, s32 n);   /* 0x0206DDA4 arm */

/* THE DISPATCH TABLE, and the reason this cluster is one family.  VERIFIED
   THIS WAVE against asm/arm9/src/030_02092120.s:27090ff, and the reading is
   NOT what func_02071F20's header implies: 0x020A8458 is not the start of an
   eight-entry table, it is an OFFSET INTO ONE CONTIGUOUS 22-ENTRY TABLE that
   begins at 0x020A8438 and runs to 0x020A8494, listing EVERY member of the
   family in strict address order:

     020A8438 02070F2C   020A8464 02071C94
     020A843C 02071034   020A8468 02071CDC
     020A8440 02071104   020A846C 02071DD4
     020A8444 02071180   020A8470 02071EAC
     020A8448 020711C8   020A8474 02071EFC
     020A844C 020712A8   020A8478 02072068
     020A8450 02071360   020A847C 020721BC
     020A8454 020713A4   020A8480 0207229C
     020A8458 02071A24   020A8484 02072320
     020A845C 02071B2C   020A8488 02072374
     020A8460 02071C14   020A848C 02072440
                         020A8490 020724E4
                         020A8494 02072524

   So `data_020A8458[o->f00 & 7]` is a WINDOW of eight starting at
   func_02071A24, and the second caller at 0x02072548 uses a different
   window of the same table -- which is precisely
   docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md:
   reading the separate pool words as separate objects splits one symbol into
   several and loses every relocation.  Declare the window at the address the
   pool word actually holds, as func_02071F20 does, and it is EXACT; but DO
   NOT conclude from it that only eight constructors exist.  The table is the
   family's membership list, and it is what makes this cluster and
   cluster_02070B64.h one subsystem rather than two.

   Declaring it `Fill[]` rather than a `void *` array is what makes the
   `ldr r2, [r0, r1, lsl #2]` / `blx r2` pair come out right. */
typedef void (*Fill)(s32 *out, struct Obj *o);
extern Fill data_020A8458[];                    /* 0x020A8458  data */

/* ================================================================== *
 * 1.  The two records
 *
 * SRC field evidence (identical to cluster_02070B64.h -- the two clusters
 * share ONE source record, and every matched source in both declares it the
 * same way, byte for byte):
 *   +0x18  s32.  Plain `ldr` fed straight to an `smull` (0x02072094).
 *   +0x1c  s32.  Likewise (0x020720A4).  SEVERAL MEMBERS READ IT TWICE, once
 *          for the f14 store and again for the scale chain; 1.1p1 -O4,p
 *          forwards the live value and drops the second load, costing four
 *          bytes.  See L-D.
 *   +0x20  s16.  `ldrsh r2, [r6, #0x20]` (0x020720F8).  `ldrsh` with an
 *          immediate offset is the only encoding that exists, so this is
 *          decisive.
 *   +0x22  s16.  `ldrsh ip, [r6, #0x22]` (0x02072110).  Likewise.
 *   +0x24  s32.  The first CROSS term.  Present in the shear members only.
 *   +0x28  s32.  The second cross term.
 *   +0x2c  u16.  `ldrh r1, [r6, #0x2c]` (0x02072108) -- UNSIGNED halfword,
 *          always widened to s32 at the use.
 *   +0x2e  u16.  `ldrh r0, [r6, #0x2e]` (0x02072190).  Likewise.
 *
 * DST field evidence: six stored words at +0x00, +0x04, +0x10, +0x14, +0x30
 * and +0x34, all s32, all plain `str`.  Nothing else in the record is ever
 * written by this family, so the gaps stay padding.
 * ================================================================== */
struct SRC {
    u8  pad_00[0x18];
    s32 f18;            /* 0x18 */
    s32 f1c;            /* 0x1c */
    s16 f20;            /* 0x20 */
    s16 f22;            /* 0x22 */
    s32 f24;            /* 0x24  cross term                               */
    s32 f28;            /* 0x28  cross term                               */
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

/* The CALLERS' view of the same object.  func_02071F20 declares f30 and f34
   `volatile` -- see L-D; that is a per-caller decision, not a property of the
   record, and no constructor needs it. */
struct Obj {
    u32 f00;            /* 0x00  flag word; bit 3 picks the header word,
                                 bits 0-2 index data_020A8458              */
    u8  pad_04[0x2c];
    volatile s32 f30;   /* 0x30  row scale, skipped outright when 0x1000   */
    volatile s32 f34;   /* 0x34  row scale, likewise                       */
};

/* The 0x4c-byte command record the callers build on the stack.  `&r.f08` is
   what is handed to the constructor as its `struct DST *`. */
struct Rec {
    u32 hdr;                                    /* 0x00 0x00101610/0x00101810 */
    s32 f04, f08, f0c, f10, f14, f18, f1c;
    s32 f20, f24, f28, f2c, f30, f34, f38, f3c;
    s32 f40, f44, f48;
};

/* ================================================================== *
 * 2.  The family variant table -- THE WHOLE CLUSTER
 *
 * Every constructor is `void f(struct DST *d, struct SRC *s)`.
 *
 *  addr        B   cc          2x2 block source        f30/f34 shape
 *  ----------  --- ----------  ----------------------  --------------------
 *  02071EAC     80 (matched in unit_02071DD4)
 *  02071EFC     36 ../2.0/sp2  unit 0x1000, zeroes     zero
 *  02071F20    288 1.1p1       -- THE CALLER, not a constructor --
 *  02072068    340 1.1p1       f18/f1c x f20/f22, s64  s64 cross, FX both
 *  020721BC    224 1.1p1       f20/f22 direct, FX      s64 cross, f24/f28 <<4
 *  0207229C    132 1.1p1       f18/f1c direct copy     32-bit, f24/f28
 *  02072320     84 ../2.0/sp2  unit 0x1000, zeroes     32-bit, -f24/-f28 <<4
 *  02072374    204 1.1p1       f18/f1c x f20/f22, s64  32-bit, f2c/f2e <<4
 *  02072440    164 1.1p1       all-s16, no smull       32-bit
 *  020724E4     64 1.1p1       (unlabelled leaf, in unit_02072440)
 *  02072524     36 --          (identical body to 02071EFC; NOT in the unit,
 *                               1.1p1 swaps the two constant movs)
 *  ----------  --- ----------  (cluster_02070B64.h holds the rest)
 *
 * TWO REDUCTIONS, visible at a glance:
 *   32-bit: `mul rD, rA, rB` then `lsl rD, rD, #3` or `#4`.  The C is a plain
 *           `(s32)s->f2c * n` with the shift written on the PRODUCT.
 *   64-bit: `smull r2, r1, rA, rB` then `lsr rX, r2, #0xc` then
 *           `orr rX, rX, r1, lsl #20`.  The C is `(s32)(((s64)a * b) >> 12)`.
 *           A `>> 8` reduction instead folds to `lsr #8` + `lsl #24`, and a
 *           `umull` + two `mla` + an `asr #0x1f` is a SIXTY-FOUR by
 *           THIRTY-TWO multiply, not two 32-bit ones -- see L-A.
 * ================================================================== */

/* ================================================================== *
 * 3.  The levers, adjudicated.  Every one is a MEASURED finding from a
 *     matched source or a note in this family.  L-A, L-C, L-E and L-F are
 *     new with the 2026-09-22 wave and are what closed 0x02072068 and
 *     0x02072374; the rest are carried forward.
 * ================================================================== */

/* L-A  A `umull` + `mla` + `mla` TRIPLE BESIDE AN `asr rD, rS, #0x1f` MEANS A
 *      64-BIT OPERAND, NOT TWO 32-BIT ONES.  This is the single fact that
 *      closed 0x02072068's 40-byte size gap.  The cross terms h1 and h2 are
 *      NOT narrowed to s32 before they multiply f1c/f18: the image shows
 *      `asr fp, lr, #0x1f` sign-extending f1c to a pair, then
 *      `umull sl, r2, sb, lr` / `mla r2, sb, fp, r2` / `mla r2, r8, lr, r2`
 *      at 0x02072140..0x0207214C, which only appears when BOTH operands are
 *      64-bit.  Declare them `s64` and defer the `(s32)` cast to the point of
 *      use.  Declared `s32`, each product collapses to a single `smull` and
 *      the function is 300 bytes against the image's 340.
 *
 * L-B  SMULL/SMLAL OPERAND ORDER NAMES THE ADDITIVE TERM.  In a two-product
 *      64-bit sum, mwcc gives the `smull` to the SECOND operand of the `+`
 *      and the `smlal` to the first.  func_020721BC: `f24*f22 + f28*f20` is
 *      exact; the other order reverses all four loads, 12 bytes.
 *      func_02072068 needs the same spelling on h2.  A SUBTRACTION has no
 *      such freedom.
 *
 * L-C  A VALUE COMPUTED FOR A LATER STORE MAY BE COMPUTED FIRST.  Store order
 *      and value order are independent, and the image routinely interleaves
 *      them.  func_02072068: the f34 value is built BEFORE the f30 value even
 *      though f30 is stored first -- `add r2, r4, r8` (the f34 sum) at
 *      0x0207215C, then the whole f30 umull/mla block, then
 *      `sub r2, r2, #0x1000` at 0x02072180 and the f30 store at 0x0207218C,
 *      and only then the f34 store at 0x020721A0.  Writing the two arms in
 *      STORE order leaves eight bytes on the table; binding the f34 value
 *      first, with its `- 0x1000` deferred past the f30 multiply, closes them.
 *
 * L-D  A FIELD THE IMAGE READS TWICE NEEDS A VOLATILE RE-READ -- BUT NOT ON
 *      THE GUARD.  1.1p1 -O4,p forwards a value it still holds live and drops
 *      the second load, exactly four bytes.  func_02071F20's L1 is the
 *      canonical shape and the canonical trap: plain `volatile` on f30/f34
 *      also re-reads for the GUARD compare and comes out four bytes LONG, so
 *      the guard's own load is bound to a local `s`, the FIRST multiply uses
 *      that local, and only the other two re-read.
 *
 * L-E  THE STORE THAT SITS BETWEEN TWO VALUES RE-NUMBERS EVERYTHING AFTER IT.
 *      This is the lever that closed 0x02072374 after three previous lanes
 *      and thirty-odd hand spellings had declared its residue "not
 *      source-addressable".  The note's best source wrote
 *          d->f00 = (s32)(((s64)e * a) >> 12);
 *          q = ...;  r = ...;  d->f14 = r;
 *      -- the image's STORE order, but not its VALUE order.  Moving the f00
 *      store DOWN, so the three narrowings are computed as an uninterrupted
 *      run and only then stored, takes it from 8 concrete bytes to 0 under
 *      BOTH front ends.  A value's colour follows its first-definition order;
 *      an intervening store inserts a definition and shifts every number
 *      after it.  WHENEVER a member is size-exact with a stable two-register
 *      exchange over its multiply-class instructions, try moving each store
 *      in the block one statement at a time before concluding anything.
 *
 * L-F  A LIVE RANGE IS SPLIT BY A FRESH TEMPORARY, AND THAT IS WHAT REACHES
 *      THE MULTIPLY-CLASS SWAP.  `t = <expr>;` computed BEFORE a neighbour,
 *      then `x = t;` after it, gives the value its own definition point so it
 *      is numbered on the far side of the neighbour.  func_02072068's last
 *      16 bytes -- x4 and x5 exchanging r4 and r5 over twelve instructions --
 *      fall to exactly this and to nothing else; statement order, operand
 *      order and binding f2c were all measured at 16.  tools/permuter.py
 *      names the mutation `temp(...)` and found it in one hill pass.
 *      func_020711C8 takes the same mutation from 35 concrete bytes to 12.
 *
 * L-G  THE TWO `<< 12` SHIFTED ANGLE VALUES ARE NAMED LOCALS LIVE ACROSS THE
 *      WHOLE BODY.  Every member that calls the divider TWICE computes both
 *      shifts ONCE near the top and re-feeds the same two registers to the
 *      second call with the arguments swapped (0x02072084/0x020720E8,
 *      0x02072390/0x020723F4).  Spelling the calls inline makes the compiler
 *      re-read f2c/f2e and re-shift, which frees two callee-saved registers,
 *      NARROWS THE PUSH LIST and is a 40-byte residue.  Bind them:
 *          f12 = (s32)s->f2c << 12;  e12 = (s32)s->f2e << 12;
 *          func_0207C930(e12, f12);  ...  func_0207C930(f12, e12);
 *
 * L-H  THE NEGATED SUM MUST BE SEPARATE STATEMENTS.  `n = a + b; n = 0 - n;
 *      n = n + 0x1000;` is the image; the folded
 *      `(0 - (a + b)) + 0x1000` becomes one `rsb rD, rD, #0x1000` and is four
 *      bytes short.  A `rsb rD, rD, #0` FOLLOWED BY a separate
 *      `add rD, rD, #0x1000` in the image means the C is spelled out.
 *      func_02072320 needs the double-negation form of the same rule: `(0 -
 *      f2e) * (0 - f28)` only survives as two named locals assigned before
 *      the f30 store.
 *
 * L-I  DECLARATION ORDER IS INSENSITIVE IN THIS FAMILY.  Six groupings
 *      measured on 0x02072374, five on 0x020712A8, four on 0x020711C8 -- all
 *      identical.  Do not spend a probe on it.  Spend it on STATEMENT order
 *      (L-C, L-E) and on live-range splits (L-F), which is what actually sets
 *      the IR's value-creation order.
 *
 * L-J  THE RESIDUE FLOOR, AND WHAT IT IS NOT.  Three rows in this family
 *      still sit at a small stable register exchange over their multiply-class
 *      instructions: 0x02071360 at 4, 0x020712A8 at 4, 0x020711C8 at 12 and
 *      0x02071104 at 6 (the last two are 2026-09-22 measurements, in
 *      docs/notes/pkt_02071104.c.txt).  Until this wave the family's standing
 *      conclusion was that this class is chosen after linearisation and is not
 *      addressable from the source.  THAT CONCLUSION IS NOW KNOWN TO BE TOO
 *      STRONG: 0x02072374 sat in it at 7-8 across three lanes and fell to one
 *      `reorder` (L-E), and 0x02072068 sat in it at 16 and fell to one `temp`
 *      (L-F).  Treat a member in this class as OPEN, run tools/permuter.py
 *      (`--mode hill` first, it is deterministic and exhausts the singles;
 *      `--mode anneal --budget 2000` after), and only then record a floor.
 */

#endif /* CLUSTER_02071EAC_H */
