/*
 * docs/families/cluster_02096D10.h -- shared declarations for the
 * pseudo-family at 0x02096D10..0x02097990 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so unlike docs/families/mcss.h this cluster is NOT a
 * recovered original translation unit: it was formed by address adjacency plus
 * shared callees and data objects.  Membership (from the wave's
 * pseudo_families.json, key "pkt_02096D10"):
 *
 *   0x02096D10  matched  func_02096D10  string/record equality
 *   0x02096DF0  matched  func_02096DF0  string/record ordering
 *   0x02096ED0  matched  func_02096ED0  MSL __minus_dec (wave 9)
 *   0x02097170  matched  func_02097170  double -> packed decimal (this wave)
 *   0x020972F0  matched  func_020972F0  digit-text -> packed decimal
 *   0x0209739C  OPEN     1492 B         MSL __dec2num, DIFF 1520/1524 (wave 9)
 *   0x02097990  matched  func_02097990  frexp + ldexp composition
 *
 * THE SUBSYSTEM.  This is the Metrowerks Standard Library's DECIMAL
 * FLOATING-POINT conversion layer -- MSL's `decimal` record and the
 * `num2dec` / `dec2num` / `__dtoa` family that printf's %e/%f/%g and strtod
 * are built on.  Every function here operates on one 38-byte record, the
 * `DB` struct below, and every function reaches the soft-float runtime through
 * the same handful of MSL/runtime.a entries that layout/runtime_arm9.txt
 * already names (__dsub 0x0209AF34, __dcmp_5 0x0209BA3C, _d2u 0x0209C554,
 * _ll_divmod 0x0209C00C/0x0209C018).  The evidence that fixes the reading is
 * func_02097170 (this wave, EXACT): it calls frexp (0x0209A6E8), a 64-bit
 * popcount (0x02092144), ldexp (0x0209A7A8) and _d2u (0x0209C554), then hands
 * two DB records to func_02096774 -- i.e. it builds 2^(e-k) and the exact
 * integer mantissa separately and MULTIPLIES the two decimal records.  That is
 * the textbook exact double-to-decimal conversion, and it is what makes
 * func_02096774 a decimal multiply rather than anything to do with game data.
 *
 * The cluster's two halves, for what it is worth: 0x02096D10..0x0209739C are
 * the record primitives (compare, order, subtract/round, build-from-u64,
 * build-from-text, multiply, scale by a power of ten, format a power of two),
 * and 0x0209739C..0x02097990 is the strtod core plus its frexp/ldexp helper.
 * docs/notes/pkt_02094B8C.c.txt identifies 0x0209739C from the other side, as
 * the routine _msl_scanf_strtod_core at 0x02094B8C calls at 0x020957E0.
 *
 * Derived from the four matched sources found with
 *   grep -l "address:  0x02096[D-F]\|address:  0x02097" src/matched/*.c
 * (func_02096D10, func_02096DF0, func_020972F0, func_02097990), from
 * src/matched/func_02097170.c filed this wave, from the immediate callees'
 * matched sources (func_02092144, func_020921D8, func_020921F4,
 * func_0209A6E8) and from the notes docs/notes/pkt_02096ED0.c.txt,
 * docs/notes/pkt_02096670.c.txt, docs/notes/pkt_02096990.c.txt and
 * docs/notes/pkt_0209739C.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrsh` proves signedness; `strh` at +2 with a
 * `ldrsh` reader proves a signed halfword; `ldrb`/`strb` prove a byte.  Where
 * two matched files disagree, the file whose code actually constrains the
 * field wins and the losing spelling is recorded beside it as `WAS:`.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * There is NO per-file pin in this cluster.  All five byte-exact members are
 * EXACT under the project default `dsi/1.1p1` with `-O4,p -proc arm946e`:
 *
 *   func_02096D10  func_02096DF0  func_02097170  func_020972F0  func_02097990
 *
 * and each of their headers carries `compiler: 1.1p1` explicitly.  The one
 * open row that has been measured against the alternatives, 0x02096ED0, was
 * swept across all seven dsi builds (1.1, 1.1p1, 1.2, 1.2p1, 1.2p2, 1.3,
 * 1.3p1) by an earlier lane: every one of them emits a BYTE-IDENTICAL body, so
 * the residue there is not a front-end tell at all, and ../1.2/sp2 and
 * ../2.0/sp2 both come out at 700/676 bytes with no alignment.  The pin rule
 * in docs/FRONTEND-PINS.md is therefore not met anywhere in this cluster; do
 * NOT reach for `--cc ../2.0/sp2` here the way cluster_020737C0 requires.
 *
 * The recognition rule that cluster_020737C0.h states still applies as a
 * NEGATIVE test: a compile whose instructions and relocations are all correct
 * but whose `push`/`pop` list is ONE REGISTER WIDER than the image's is the
 * 1.1p1 constant-pooling tell and would justify a pin.  In this cluster the
 * width goes the other way -- the IMAGE is the wider push (func_02097170's
 * `push {r3-r8,sb,lr}` against a naive body's `push {r4-r8,lr}`), and the
 * cure was a source-level copy that keeps one more value live in a
 * callee-saved register, not a compiler change.  See the header of
 * src/matched/func_02097170.c.
 *
 * ISA: ARM throughout.  This is unusual for game code (the ARM9 static module
 * is Thumb almost everywhere) and is itself a cluster property worth knowing:
 * always pass `--arm`.  It follows from the subsystem: this is library C
 * compiled into the MSL objects, not game code.
 * ============================================================================
 */

#ifndef CLUSTER_02096D10_H
#define CLUSTER_02096D10_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;

/* ================================================================== *
 * 0.  struct DB -- THE decimal record.  38 bytes.  Every function in the
 *     cluster takes one or more of these and nothing else.
 *
 * Field evidence, one function per line:
 *   +0x00  sign flag.  func_02097170 stores the __dsign result there with
 *          `strb r5,[r7]` on all three of its exits; func_020966B0 and
 *          func_020968F4 zero it with `strb r0,[r7]` / `strb ip,[r0]` before
 *          filling the digits.  A BYTE.
 *   +0x01  pad.  Nothing in the cluster touches it.  Its existence is forced
 *          by +0x02 being a HALFWORD: func_020966B0 writes it with
 *          `strh r0,[r7,#2]` and func_02096774 reads it with
 *          `ldrsh r3,[r1,#2]`, so it is 2-aligned and +0x00 is a byte.
 *   +0x02  the decimal exponent.  SIGNED HALFWORD, and the signedness is
 *          nailed by the `ldrsh r3,[r1,#2]` / `ldrsh r1,[r2,#2]` pair at
 *          0x0209683C in func_02096774, which then ADDS the two -- the
 *          exponents of a product add, and they must be able to go negative.
 *          func_020972F0 decrements it (`p->f2 -= (s16)(p->f4 - 1)`).
 *   +0x04  the digit COUNT.  A BYTE: `ldrb r0,[r7,#4]` / `strb r0,[r7,#4]`
 *          everywhere (func_020966B0 at 0x02096734, func_02096774 at
 *          0x0209677C/0x02096890, func_020968F4 at 0x02096934,
 *          func_02096670 at 0x02096684).
 *   +0x05  the DIGIT ARRAY, one decimal digit (value 0..9, NOT ASCII) per
 *          byte.  `add r2,r7,#5` in func_020966B0 and `add r3,r0,#5` in
 *          func_02096ED0/func_020965B4/func_02096620 fix the offset.
 *          func_020972F0 converts the array to ASCII in place as its LAST
 *          step (`p->buf[i] += 0x30`) and func_020968F4 converts the other
 *          way on the way in (`sub r3,r3,#0x30`), which is what proves the
 *          stored form is the raw digit.
 *
 * SIZE: 38 bytes, and this is measured twice over.  func_02096ED0's opening
 * struct copy is `mov r5,#9` then a 9-iteration 4-byte `ldrh/ldrh/strh/strh`
 * loop plus one trailing `ldrh/strh`, i.e. 9*4 + 2 = 38.  func_02097170 gives
 * two of them stack homes at sp+0x0c and sp+0x32 inside a 0x58-byte frame,
 * 0x32 - 0x0c = 0x26 = 38.  The array is therefore 33 bytes, and 0x20 (32) is
 * the working digit limit every function clamps to (`cmp ip,#0x20` in
 * func_020968F4, `cmp r3,#0x20` in func_02096774, `if (n > 0x20) n = 0x20` in
 * func_020972F0 and func_02096ED0), leaving one guard digit.
 * ================================================================== */
typedef struct DB {
    u8  sign;               /* 0x00  nonzero = negative                       */
    u8  pad01;              /* 0x01  alignment only                           */
    s16 exp10;              /* 0x02  decimal exponent, SIGNED (ldrsh)         */
    u8  ndigits;            /* 0x04  digits in use, <= 0x20 by every clamp    */
    u8  digits[33];         /* 0x05  raw decimal digits 0..9, not ASCII       */
} DB;                       /* 38 bytes total                                 */

/* func_02096D10 and func_02096DF0 read a DIFFERENT, overlapping view of the
   same record: they guard on digits[0] as a terminator flag and compare
   exp10 as the sort key, and BOTH of them need `volatile` on ndigits or the
   tail loop hoists the re-read and comes out short.  Recorded as its own view
   rather than merged, per the adjudication rule -- only the loads constrain
   it, and the volatile is a codegen requirement, not a type fact. */
typedef struct DBv {
    u8  pad00[2];
    s16 exp10;              /* 0x02  the sort key                             */
    volatile u8 ndigits;    /* 0x04  MUST be volatile in 02096D10 / 02096DF0  */
    u8  digits[];           /* 0x05                                           */
} DBv;

/* ================================================================== *
 * 1.  Prototypes, with the parameter types the matched sources fixed
 * ================================================================== */

/* --- the cluster's own record primitives --------------------------------- */

/* Equality.  Returns 1 when the two records are equivalent.  EXACT in
   src/matched/func_02096D10.c; needs `volatile u8 ndigits`, int copies of the
   two lengths for the `movgt` bound, and `p = a; if (n == la) p = b;` as two
   statements rather than a ternary. */
extern int  func_02096D10(DBv *a, DBv *b);

/* Ordering.  Returns 1 when a sorts before b.  EXACT in
   src/matched/func_02096DF0.c; the s16 tie-break sits OUT OF LINE after the
   final `return 0` (`goto keycmp`), and the declaration order is `int lb, la`
   -- `la, lb` swaps r4/r5 and costs seven bytes. */
extern int  func_02096DF0(DBv *a, DBv *b);

/* Truncate/round the record to n digits.  0x02096620 does the rounding carry
   and 0x020965B4 decides whether to round at all; func_02096670 is the guard
   wrapper (`if (n <= 0 || n >= p->ndigits) return;`).  Parked at MATCH in
   src/pending/func_02096670.c, capped on 0x020965B4 having no shard entry. */
extern void func_020965B4(DB *p, int n);       /* 108 B, open                 */
extern void func_02096620(DB *p, int n);       /*  80 B, open  -- carry       */
extern void func_02096670(DB *p, int n);       /*  64 B, MATCH in src/pending */

/* Build a record from an unsigned 64-bit integer: repeated divmod by 10
   through the two MSL runtime entries, digits stored forward, then the array
   reversed in place and ndigits-1 stored as the exponent.  DIFF, one-register
   shift of the callee-saved set; the body is in docs/notes/pkt_02096670.c.txt.
   The second parameter really is a u64 -- it arrives in r0:r1 and both halves
   are tested (`cmp r5,#0 / cmpeq r6,#0`). */
extern void func_020966B0(DB *p, u64 v);       /* 196 B, EXACT (wave 9)       */

/* MULTIPLY two records into a third.  The long-multiplication kernel is the
   `mla r4, ip, r3, r4` loop at 0x020967F0 over the two digit arrays, the
   carry is extracted with the reciprocal-of-10 `umull` pair (the pool word
   0xCCCCCCCD at 0x020968F0, `>> 3` after the high half), and the exponents
   are ADDED as signed halfwords at 0x0209683C.  Result digits are capped at
   0x20 and the tail is handed to func_02096620 to round.  r is written, a and
   b are read only. */
extern void func_02096774(DB *r, DB *a, DB *b);/* 384 B, EXACT (wave 9)       */

/* Build a record from a NUL-terminated ASCII digit string, with the exponent
   passed in.  `sub r3,r3,#0x30` per digit, stop at 0x20 digits, then the
   round-to-even tail (`tst r1,#1` on the last kept digit) through
   func_02096620.  The third parameter is stored with `strh r2,[r0,#2]`, so it
   is the exponent and it is a halfword. */
extern void func_020968F4(DB *p, const char *s, int exp10);  /* 156 B, open   */

/* Format a POWER OF TWO as a record: the recursive 2^n builder.  Dense
   dispatch `add r1,r4,#0x20 / cmp r1,#0x28 / addls pc,pc,r1,lsl #2` over
   n in -32..+8 with seventeen tabulated arms, each a (string pointer, length
   bias) pair handed to func_020968F4, and a default at 0x02096C1C that halves
   n, RECURSES, and multiplies the two halves with func_02096774.  Oversized
   and evidence-starved: the seventeen ABS32 pool words into the packed string
   area at 0x020A8ABC have no `string`-class witness (a data table precedes
   the run), so even a byte-perfect body caps at MATCH.  See
   docs/notes/pkt_02096990.c.txt. */
extern void func_02096990(DB *p, long n);      /* 896 B, EXACT (wave 9)       */

/* MSL __minus_dec: z = x - y, rounding the digits of y past z's precision.
   EXACT since wave 9 (src/matched/func_02096ED0.c), from the Metrowerks
   source verbatim -- the "allocator tie between base and the b->ndigits
   temporary" of docs/notes/pkt_02096ED0.c.txt was the declaration list
   `int zlen, dexp; u8 *ib, *i, *ie; const u8 *jb, *j, *jn;` and the
   borrow loops `while (*k == 0) --k; while (k != i) { --*k; *++k += 10; }`.
   Argument order is (dest, minuend, subtrahend): the opening copy is *z = *x. */
extern void func_02096ED0(DB *z, const DB *x, const DB *y);  /* 672 B, EXACT  */

/* Convert a double to a record.  EXACT in src/matched/func_02097170.c.        */
extern void func_02097170(DB *r, double x);    /* 384 B, EXACT                */

/* Scale a record by a power of ten given as the s16 at (char *)a0 + 2, clamp
   to 0x20 digits, zero-fill, fix the exponent, and convert the digit array to
   ASCII.  EXACT in src/matched/func_020972F0.c.  NOTE the parameter list: the
   record is the FOURTH argument and the first three are (void *, int, int)
   with only the first used -- a forwarding shape, not a mistake. */
extern void func_020972F0(void *a0, int a1, int a2, DB *p); /* EXACT          */

/* MSL __dec2num: decimal record -> double.  1492 bytes.  Wave 9 wrote the
   whole Metrowerks body (docs/notes/pkt_0209739C.c.txt, best source there):
   1520 bytes against 1524, 721 concrete bytes out, every instruction in
   order.  Two field facts it pinned: the record's sign byte is UNSIGNED
   (`ldrb`, so `u8 sign`, not MSL's `char`), and `dec.exp += (s16)(len - 1)`
   carries an explicit short cast (the lsl/asr pair).  The residue is WHERE
   1.1p1 POOLS ADDRESS CONSTANTS: it materialises &feval, &dec, &x64 and a
   zero together right after the digit loop and shares the zero with pow's
   5.0 low word (4 bytes); the image pools &x64 / &dec / 0 again at the
   refinement loop's preheader.  About twelve loop/scope/goto structures and
   the inline-helper form all leave the pool point unchanged.  0x02096ED0 is
   no longer a cap (it resolves by sole-ref/code and is EXACT); the one open
   witness is the pow_10 table at 0x020A8A7C.  Signature: (const DB *d).
   Wave 10 (unchanged, 1520/721): the image materialises &feval/&dec at the
   block after the chunk loop for the NON-loop uses and, separately, &dec
   again, &x64 and the zero of the 64-bit `& 1` test at the refinement
   loop's own preheader; 1.1p1 merges all of them at the earlier block.  2.0
   and 1.2 are wrong from +0x1C (`ldreq/ldrne` sign select), so no pin.
   Wave 11 (unchanged, 1520/721): wrappers (do/while(0), for/break) around
   the pre-loop sections, a label before the loop and the loop + found block
   as a static inline helper all leave the constants at +0x2A0 -- 1.1p1
   inlines before it places constants, so a helper function does not
   reproduce the image's second (preheader) group.  Permuter hill/anneal
   bests are u8-counter or volatile size compensations only. */
extern double func_0209739C(const DB *d);                    /* 1492 B, open  */

/* frexp/ldexp composition: `t = 0; v = frexp(a0, &t); t += a2;
   return ldexp(v, t);`, i.e. multiply a double by 2^a2 through the two
   library calls rather than by arithmetic.  EXACT in
   src/matched/func_02097990.c, where the double is spelled as a u32 pair --
   the body does not care which, since nothing arithmetic happens to it. */
extern u32  func_02097990(u32 a0, u32 a1, u32 a2);          /* EXACT          */

/* ================================================================== *
 * 2.  The library the cluster calls out to
 *
 * Every one of these is either a matched source elsewhere in the tree or a
 * row of layout/runtime_arm9.txt; none is game code.  The `runtime` rows are
 * the hand-written MSL assembly, declared `arm` in a symbols: block and
 * attested by the table, never by a branch.
 * ================================================================== */

/* --- MSL soft-float classification (matched sources) --------------------- */
extern int    func_020921D8(double v);   /* __dsign: 1 if the sign bit is set */
extern int    func_020921F4(double v);   /* fpclassify: 1 NaN, 2 Inf, 3 zero,
                                            4 normal, 5 subnormal             */
extern u32    func_02092144(u64 x);      /* 64-bit popcount, SWAR             */

/* --- fdlibm (matched sources) -------------------------------------------- */
extern double func_0209A6E8(double x, int *eptr);       /* frexp              */
extern double func_0209A7A8(double x, int n);           /* ldexp / scalbn     */

/* --- MSL/runtime.a soft float (layout/runtime_arm9.txt) ------------------- */
extern double func_0209AF34(double a, double b);        /* __dadd_dsub: SUB   */
extern double func_0209B2E8(double a, double b);        /* __dmul             */
extern u64    func_0209C554(double x);                  /* _d2u               */
extern u64    func_0209C00C(u64 v, u64 d, int f);       /* _ll_divmod, quot   */
extern u32    func_0209C018(u64 v, u64 d, int f);       /* _ll_divmod, rem    */

/* THE COMPARISON HELPERS ARE NOT ORDINARY EXTERNS, and this cost a pass.
   Write a double comparison as a double comparison -- `if (x == 0.0)` -- and
   mwcc lowers it to `bl _deq` followed IMMEDIATELY by the conditional branch,
   because the helper returns CONDITION FLAGS, not a value in r0.  Declaring
   `extern int func_0209BA3C(double, double)` and testing its result compiles
   an extra `cmp r0, #0` and is four bytes out.  The names mwcc emits are the
   `_dXX` ones below; pin them in the symbols: block AT the runtime address,
   spelled the way mwcc spelled them:

     _deq   0x0209BA3C   (__dcmp_5 in layout/runtime_arm9.txt)

   func_02097170's symbols: block is the worked example. */

/* ================================================================== *
 * 3.  Constants
 * ================================================================== */
#define DB_SIZE          38     /* func_02096ED0's 9x4+2 copy; 0x32-0x0c      */
#define DB_DIGITS_OFF    5      /* `add r3, r0, #5` in five functions         */
#define DB_MAX_DIGITS    0x20   /* every clamp in the cluster                 */
#define DB_DIGIT_ASCII   0x30   /* func_020972F0 adds it, func_020968F4 subs  */
#define DB_NAN_CHAR      0x4E   /* 'N', func_02097170's NaN digit             */
#define DB_INF_CHAR      0x49   /* 'I', func_02097170's infinity digit        */
#define DBL_MANT_BITS    0x35   /* 53, func_02097170's `rsb sb, r0, #0x35`    */
#define DBL_HIDDEN_BIT   0x0010000000000000ULL  /* func_02097170's `orr #0x100000` */
#define RECIP10_MAGIC    0xCCCCCCCD  /* func_02096774's pool word at 0x020968F0 */

#endif /* CLUSTER_02096D10_H */
