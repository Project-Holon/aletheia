/*
 * docs/families/cluster_020949F4.h -- shared declarations for the
 * pseudo-family at 0x020949F4..0x02096990 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so unlike docs/families/mcss.h this cluster is NOT a
 * recovered original translation unit.  It was formed by address adjacency
 * plus shared callees and data objects.
 *
 * THE SUBSYSTEM: this is the METROWERKS STANDARD LIBRARY (MSL) C runtime that
 * mwccarm links into the ARM9 static module -- not game code at all.  It is
 * three neighbouring MSL compilation units:
 *
 *   A. 0x020949F4..0x02094B20 -- <string.h>.  func_020949F4 is strncmp,
 *      func_02094A28 is strchr, func_02094A60 is strcspn (a 32-byte stack
 *      bitmap of the reject set, then a scan), func_02094B20 is strstr.
 *      Pure leaves: no relocations at all, no globals, no callees.
 *
 *   B. 0x02095AA4..0x020964F8 -- <stdlib.h> string-to-number.  Three cores
 *      (func_02094B8C = _msl_scanf_strtod_core per layout/runtime_arm9.txt,
 *      func_02095B3C and func_02096004, both ~900-byte dense-switch scanners)
 *      and four thin clamping wrappers over them -- func_02095AA4 (strtod),
 *      func_02095EAC (strtol), func_02095F40 (the s32 form) and
 *      func_020963F8 (the s64 form).  Every wrapper has the SAME shape, and
 *      it is the shape to copy for a new one:
 *
 *        buf[0] = a0; buf[1] = 0;                 /* IN THIS ORDER */
 *        r = core(mode, 0x7FFFFFFFu, (u32)func_020946D8, buf,
 *                 &len, &sign, &err);
 *        if (a1 != 0) *a1 = a0 + len;
 *        <range test as ONE disjunction>          /* never if/else */
 *        if (sign != 0) r = -r;
 *        return r;
 *
 *      All four share the one-character getter func_020946D8 (passed as an
 *      integer-cast function pointer, never as a typed one) and the errno
 *      word g_02153FAC, which every error path sets to 0x22 (EINVAL/ERANGE).
 *      func_020946D8 is OUTSIDE this cluster but is the strongest shared
 *      callee it has; g_02153FAC is its one shared data object.
 *
 *   C. 0x02096508..0x02096990 -- a PACKED DECIMAL (BCD) arithmetic unit,
 *      almost certainly MSL's decimal support for printf's %f family.  Every
 *      function here operates on one struct Bcd (below): a flag byte at +0,
 *      a signed decimal exponent at +2, a digit count at +4 and up to 32
 *      one-digit-per-byte values from +5.  func_020965B4 compares a digit run
 *      against the rounding midpoint, func_02096620 increments the run with
 *      carry (bumping the exponent on overflow), func_02096670 truncates to a
 *      new length and rounds, func_020966B0 converts a u64 to the record,
 *      func_02096774 multiplies two records, func_020968F4 parses a decimal
 *      string into one, and func_02096990 (oversized, out of scope -- see
 *      docs/notes/pkt_02096990.c.txt) formats one.  func_02096578 (u16
 *      strlen) and func_02096594 (u16 strcpy) are two unlabelled leaves that
 *      happen to sit in the same word run.
 *
 * Derived from the 12 matched sources found with
 *   grep -l "address:  0x02094[9A-F]\|address:  0x02095\|address:  0x02096[0-9]" \
 *        src/matched/*.c
 * and from the notes docs/notes/func_02094A60.c.txt,
 * docs/notes/pkt_02094A60.c.txt, docs/notes/pkt_02095AA4.c.txt,
 * docs/notes/pkt_02095B3C.c.txt, docs/notes/pkt_02096670.c.txt,
 * docs/notes/pkt_020966B0.c.txt and docs/notes/pkt_02096990.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrsh` proves the exponent at +2 is signed;
 * `ldrb`/`strb` prove the count at +4 and the digits from +5 are unsigned
 * bytes; `and rN, rM, #0xff` followed by an ARITHMETIC `asr` proves the value
 * being masked was a SIGNED WIDE type, not a u8 (see the compiler note below).
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * THERE IS NO PIN.  Every byte-exact source in this cluster is EXACT under the
 * project default `--cc 1.1p1` with `-O4,p`, and no function here carries a
 * row in docs/FRONTEND-PINS.md.  The ../2.0/sp2 probe was taken once on
 * func_02095EAC by an earlier lane (docs/notes/pkt_02095B3C.c.txt) and is
 * strictly worse: 9 instructions out against 1.  Do not re-take it.
 *
 * ISA: ARM throughout, all 18 members.  This is unusual for the ARM9 static
 * module (which is Thumb almost everywhere) and is itself the tell that this
 * range is linked-in library code rather than game code: always pass `--arm`.
 *
 * THE TWO LEVERS THAT ACTUALLY CLOSE FUNCTIONS HERE, both found by closing
 * func_02094A60 on 2026-09-22 after two earlier lanes left it at 124 concrete
 * bytes out:
 *
 *   1. A CHARACTER HELD IN A LOOP IS `int`, NOT `u8`.  MSL's string code
 *      keeps the current character in an `int` (the <ctype.h>/getc
 *      convention) and narrows at each use.  The image tell is a standalone
 *      `and rN, rM, #0xff` whose result is then used as an index with an
 *      ARITHMETIC shift (`ldrb r3, [lr, ip, asr #3]`): a `u8` local makes
 *      that cast a no-op, the mask vanishes, the index folds into the load,
 *      and the function loses four bytes and a callee-saved register.  On
 *      func_02094A60 this single change went from 124 concrete bytes out to
 *      TEN, size-exact, with every byte past the first loop identical.
 *
 *   2. DECLARATION ORDER PICKS THE REGISTER for two locals live across the
 *      same loop (docs/idioms/declaration-order-decides-which-register-a-
 *      local-gets.md).  func_02094A60's residual ten bytes were exactly the
 *      clear loop's cursor and counter in each other's registers; declaring
 *      the COUNTER first (`u32 i = 8;` then `u8 *p = map;`) closed it to
 *      EXACT.  A signed counter (`int i`) is 160 bytes out, because `--i` on
 *      an unsigned counter is `subs`/`bne` and on a signed one costs a
 *      separate `cmp`/`bgt`.
 *
 * THE WALL THAT IS NOT A SOURCE PROBLEM.  Three functions in section C and
 * the strtol wrapper are size-exact with every instruction reproduced and
 * only the callee-saved register NUMBERS rotated by one (func_020966B0,
 * func_02096774) or one back-end constant fold out (func_02095EAC).  Between
 * them they have absorbed some forty hand spellings and about six thousand
 * permuter compiles across four lanes.  If a function in this range is
 * size-exact and differs only in which register holds which value, stop:
 * that is the allocation-tie class, not the C.
 * ============================================================================
 */

#ifndef CLUSTER_020949F4_H
#define CLUSTER_020949F4_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;
typedef signed long long   s64;

/* ================================================================== *
 * 0.  Data objects and shared callees
 * ================================================================== */

/* The MSL errno word.  Every error path in section B stores 0x22 into it and
   nothing in this cluster ever reads it.  Evidenced by func_02095AA4,
   func_02095F40 and func_020963F8, which all carry it as an ABS32 pool word
   resolved by the `literal` class (35 witnesses image-wide).                */
extern u32 g_02153FAC;                  /* 0x02153FAC -- errno              */

/* The one-character getter every section-B wrapper hands its core.  It is
   ALWAYS passed as `(u32)func_020946D8`, an integer-cast function pointer:
   declaring the core's third parameter as a typed function pointer changes
   nothing in the bytes but loses the cast the matched sources all carry.
   Its own address is outside this cluster.                                 */
extern u32 func_020946D8(u32 a, u32 b, u32 c);

/* The three scanning cores.  All three are ~900-byte dense-switch state
   machines and all three are OUT OF SCOPE for a normal packet slot (the
   worklist's byte counts for 0x02095B3C and 0x02096004 -- 600 and 732 -- are
   both short of the real listing extents, 880 and 1012).  Declared here only
   so a wrapper can name them.
   func_02094B8C is layout/runtime_arm9.txt's _msl_scanf_strtod_core, so a
   call to it attests by the `runtime` class and needs no other witness.     */
extern u64 func_02094B8C(u32 a0, u32 cb, u32 *buf, u32 *end, u32 *flag);
extern u64 func_02095B3C(u32 mode, u32 lim, u32 cb, u32 *buf,
                         u32 *len, u32 *sign, u32 *err);
extern u64 func_02096004(u32 mode, u32 lim, u32 cb, u32 *buf,
                         u32 *len, u32 *sign, u32 *err);

/* The 64-bit divmod pair func_020966B0 drives.  Both are MSL runtime entries:
   func_0209C018 returns the REMAINDER in r0 and func_0209C00C the QUOTIENT in
   r0:r1, and the image calls them back to back on the same operands -- this
   is docs/idioms/div-and-mod-are-two-calls.md in its 64-bit form.           */
extern u32 func_0209C018(u64 v, u32 d, u32 flag);   /* _ll_divmod_entry_flag1 */
extern u64 func_0209C00C(u64 v, u32 d, u32 flag);   /* _ll_divmod_entry_flag0 */

/* The narrowing helper func_02095AA4 tail-calls with the two halves of its
   own u64 result.  Evidenced by that file's +0x58 PC24 (label x15).         */
extern void func_0209A504(u32 lo, u32 hi);

/* ================================================================== *
 * 1.  struct Bcd -- the packed-decimal record, section C
 *
 * Field evidence, one function per line:
 *   +0x00  func_020968F4 `p->f00 = 0` and func_02096774 `strb r4, [r0]`:
 *          a flag byte, cleared on every construction, never read here.
 *   +0x02  func_02096620 `*(short *)(p + 2) += 1` on carry-out, and
 *          func_02096774 `ldrsh r3, [r1, #2]` / `ldrsh r1, [r2, #2]` /
 *          `strh r1, [r0, #2]` adding the two inputs' values: a SIGNED
 *          halfword, and the `ldrsh` is the whole signedness evidence
 *          (docs/idioms/ldrsh-register-offset-is-signedness.md).  It is the
 *          decimal exponent.  func_020968F4 takes it as a u16 PARAMETER and
 *          stores it unconverted, which is why that file spells it u16 --
 *          the load instructions win, so it is s16 here and that file's
 *          spelling is recorded as WAS:.
 *   +0x04  `ldrb`/`strb` in all six functions: the digit COUNT, u8.
 *   +0x05  `ldrb`/`strb` at a byte stride throughout: the digit run, one
 *          decimal digit (0..9) per byte, most significant first.  Bounded
 *          at 32 by func_020968F4's `i < 32` and func_02096774's
 *          `cmp r3, #0x20`.
 * The record is therefore 37 bytes; func_02096774 gives itself a 64-byte
 * stack scratch of the same digit shape, which is what its `sub sp, sp, #0x40`
 * is.
 * ================================================================== */

struct Bcd {
    u8  f00;            /* +0x00  flag, cleared on construction          */
    u8  f01;            /* +0x01  padding; nothing in the cluster touches it */
    s16 f02;            /* +0x02  decimal exponent (WAS: u16 in 020968F4) */
    u8  f04;            /* +0x04  number of digits held at f05           */
    u8  f05[32];        /* +0x05  digits, one per byte, MSD first        */
};

/* Compare the digit run from index `i` against the rounding midpoint: +1 if
   the tail is above half, -1 if below.  Note the tail's own tell, recorded in
   docs/notes/pkt_02095AA4.c.txt: the original lets the base pointer DIE and
   folds the +5 into the final load's displacement.                          */
extern int  sub_020965B4(struct Bcd *p, int i);

/* Increment the digit at index `i - 1` with carry propagation toward the most
   significant end; on carry out of the leading digit it writes a 1 there and
   bumps the exponent at +2.                                                 */
extern void func_02096620(struct Bcd *p, int idx);

/* Truncate to `v` digits and round.  Guards `v <= 0` and `v >= p->f04`, calls
   sub_020965B4 for the direction, stores the new count and, on a non-negative
   direction, calls func_02096620.  Section C's own composition point.       */
extern void func_02096670(struct Bcd *p, int v);

/* u64 -> Bcd.  Digits are produced least-significant first by the divmod pair
   above, stored FORWARD from f05, then the run is reversed in place and the
   count minus one lands in the exponent.                                     */
extern void func_020966B0(struct Bcd *p, u64 v);

/* Bcd * Bcd -> Bcd.  A schoolbook convolution: `mla` accumulates one column
   of partial products into a u32, the column digit is the accumulator mod 10
   and the carry is the accumulator / 10 (the image spells the /10 as the
   usual reciprocal `umull` by 0xCCCCCCCD then `lsr #3`).  Result digits are
   written BACKWARD into a 64-byte stack scratch and copied out, bounded at 32,
   with the same below-5 / above-5 / exactly-5 rounding tail func_020968F4
   has.                                                                       */
extern void func_02096774(struct Bcd *r, struct Bcd *x, struct Bcd *y);

/* Decimal string -> Bcd, with the exponent supplied by the caller.  See
   src/matched/func_020968F4.c for the two pinned spellings (one shared `tail`
   label for all three rejection paths; the trailing-zero scan entered as
   `c = s[1]; s++;` and not `s++; c = *s;`).                                  */
extern void func_020968F4(struct Bcd *p, const u8 *s, u16 v);

/* Bcd -> text.  OVERSIZED and confirmed out of scope: 812 bytes of body, a
   41-entry dense dispatch, seventeen near-identical arms each needing its own
   ABS32 into the packed string area, several of which have no witness at all,
   so even a byte-perfect body caps at MATCH.  See docs/notes/pkt_02096990.c.txt. */
extern void func_02096990(struct Bcd *p, int n /* , ... */);

/* ================================================================== *
 * 2.  Section A -- <string.h>, all pure leaves
 *
 * Every one of these has ZERO relocation sites and touches no global, which
 * is why each is EXACT on its own with no witness of any kind.  The character
 * held across a loop is `int` in all of them (lever 1 above): func_02094A28
 * spells it `u8 m` only because that one narrows ONCE in the preheader rather
 * than at each use, which its own header explains.
 * ================================================================== */

extern int  func_020949F4(const u8 *s1, const u8 *s2, u32 n);  /* strncmp  */
extern u8  *func_02094A28(const u8 *s, int c);                 /* strchr   */
extern u32  func_02094A60(const u8 *s, const u8 *reject);      /* strcspn  */
extern u8  *func_02094B20(const u8 *s1, const u8 *s2);         /* strstr   */

/* Two u16 leaves that sit inside section C's word run rather than with the
   u8 string functions.  func_02096578's `int n = -1` pre-decrement shape is
   what gives the original its single `do`/`while` with no separate guard.   */
extern int  func_02096578(const u16 *s);                       /* u16 strlen */

/* ================================================================== *
 * 3.  Section B -- the strtoX wrappers
 *
 * All four take (start pointer, optional end-pointer out, mode) and return a
 * width-clamped value.  The THREE range conditions must be written as ONE
 * disjunction: as an if/else chain the shared error block is laid out after
 * the final return and the whole tail shifts (66 bytes on func_020963F8).
 * ================================================================== */

extern u64 func_02095AA4(u32 a0, u32 *a1);              /* strtod           */
extern int func_02095EAC(u32 a0, u32 *a1, u32 mode);    /* strtol -> int    */
extern s32 func_02095F40(u32 a0, u32 *a1, u32 a2);      /* strtol -> s32    */
extern s64 func_020963F8(u32 a0, u32 *a1, u32 a2);      /* strtoll -> s64   */

/* The sign/flag inspector at 0x02096508 is the odd one out: it reads a 32-bit
   word at +4 of a DIFFERENT object and picks bits out of it with unequal
   shift pairs (`(f << 22) >> 29` and `(f << 20) >> 30`), i.e. two bitfields,
   per docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md.  It is
   not a Bcd.                                                                */
extern int func_02096508(u8 *p, int v);

#endif /* CLUSTER_020949F4_H */
