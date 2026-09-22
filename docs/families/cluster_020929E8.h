/*
 * docs/families/cluster_020929E8.h -- shared declarations for the
 * pseudo-family at 0x020929E8..0x02094534 in the ARM9 image.
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
 * WHAT THE SUBSYSTEM IS.  This is not game code at all: it is the MSL C
 * STANDARD LIBRARY, specifically the `printf` family and the string/memory
 * primitives around it.  The evidence is direct and does not depend on any
 * guess about names:
 *
 *   - the neighbourhood immediately below the cluster is unmistakably MSL:
 *     src/matched/unit_02092344.c is byte-wise memcpy + memmove,
 *     src/matched/unit_020923B0.c is memset-wrapper + memchr + memcmp,
 *     src/matched/func_02092430.c is the word-unrolled memset,
 *     src/matched/func_02092144.c is a 64-bit popcount and
 *     src/matched/func_020921F4.c is an IEEE-754 double classifier
 *     (the 0x7FF00000 exponent mask, returning 1/2/3/4/5 = the
 *     __fpclassify ladder);
 *   - src/matched/func_02094530.c is `sprintf`: a varargs trampoline whose
 *     first instruction is the argument home area `push {r0,r1,r2,r3}`,
 *     which walks the home area with `&n & ~3` and forwards to
 *     func_020944CC with a length of 0xFFFFFFFF;
 *   - src/matched/func_020944CC.c is `vsnprintf`: it builds a four-word
 *     writer state {0, dst, n, 0} and calls func_02093BDC with
 *     func_02094488 (the buffer-writer callback) as its first argument,
 *     then NUL-terminates;
 *   - src/matched/func_02094488.c is that callback: a bounded memcpy into
 *     {base, cap, pos} at [p+0], [p+4], [p+8];
 *   - func_02093BE0 is the FORMAT DRIVER itself: it scans the format for
 *     '%' with func_02094A28 (memchr-of-char), measures the literal run
 *     with func_0209477C (strlen), and emits through `blx sb`, i.e. the
 *     writer callback the state carries.  That indirect call through a
 *     register argument is the whole architecture of the family.
 *
 * So, in the ordinary library names: this cluster holds MSL's __utoa /
 * __ltoa integer conversion (0x020929E8, 32-bit; 0x02092C3C, its 64-bit
 * twin), the float formatter (0x02092F10), the decimal-rounding odometer
 * (0x020933B8), the `%`-scanning format driver (0x02093BE0) and `qsort`
 * (0x0209455C, inside the 0x02094534 row).
 *
 * Derived from the fourteen matched sources found with
 *   grep -l "address:  0x02092\|address:  0x02093\|address:  0x02094[0-5]" \
 *        src/matched/*.c
 * and from the notes docs/notes/pkt_020924DC.c.txt,
 * docs/notes/pkt_02092C3C.c.txt, docs/notes/pkt_020933B8.c.txt,
 * docs/notes/pkt_02094488.c.txt and docs/notes/pkt_020944CC.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains
 * a field; a name does not.  `ldrsb`/`ldrsh` prove signedness; a shift pair
 * of unequal amounts proves a bitfield's width and position; a plain `ldr`
 * followed by a shift pair proves the FIELD is 32-bit and the narrowing
 * happens at the use.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * THERE IS NO PIN HERE.  Unlike docs/families/cluster_020737C0.h, every
 * byte-exact file in this cluster is EXACT under the project default
 * `dsi/1.1p1` with `-O4,p -proc arm946e`, and the alternatives are measurably
 * WORSE, not better.  Measured on func_020933B8 (276-byte body) on
 * 2026-09-22 against the note's own best source:
 *
 *     dsi/1.1p1     264 bytes,  65 concrete bytes out
 *     ../2.0/sp2    272 bytes, 162 concrete bytes out
 *     ../1.2/sp2    292 bytes, 253 concrete bytes out
 *
 * Do not spend a slot re-running that sweep.  If a function here is size-
 * exact but a push-list wide, the cause is a missing stack slot in the C
 * (see "THE HOME AREA" below), not the front end.
 *
 * ISA: ARM throughout, with no exceptions.  This is unusual for the ARM9
 * static module (which is Thumb almost everywhere) and is itself a cluster
 * property worth knowing: ALWAYS pass `--arm`.  It follows from what the
 * cluster is -- MSL is compiled ARM, as `layout/runtime_arm9.txt` records
 * for the runtime helpers this code calls.
 *
 * ============================================================================
 * THE HOME AREA.  THE OTHER THING TO READ BEFORE WRITING ANY C.
 * ============================================================================
 *
 * Three of this cluster's twelve rows are FOUR BYTES LONG, and all three
 * decode to exactly one instruction:
 *
 *     0x02092C38   0f 00 2d e9   push {r0, r1, r2, r3}
 *     0x02092F0C   0f 00 2d e9   push {r0, r1, r2, r3}
 *     0x02093BDC   0f 00 2d e9   push {r0, r1, r2, r3}
 *
 * They are NOT stubs and they are NOT single-instruction functions.  They are
 * MIS-SEEDED LABELS: each is the argument home area that mwcc emits as the
 * FIRST instruction of the function whose label disasm.py then placed four
 * bytes too late, because `disasm.py` only auto-labels a prologue that saves
 * `lr` and a home-area push saves none.  The real function entries are
 * 0x02092C38, 0x02092F0C and 0x02093BDC; the labels at 0x02092C3C,
 * 0x02092F10 and 0x02093BE0 are four bytes into their own bodies.  The same
 * mis-seed is already documented for 0x02094534 in
 * src/matched/func_02094530.c and for 0x020934CC in
 * src/matched/func_020933B8.c, which is what makes the reading certain
 * rather than inferred: in both of those cases a source compiled at the
 * EARLIER address reproduces the push and comes out EXACT.
 *
 * CONSEQUENCES, all of them load-bearing:
 *
 *   1. None of the three can ever be filed on its own.  Four bytes of home
 *      area are not a translation unit and no C produces them alone; this is
 *      the blocker src/matched/func_020944CC.c already records for
 *      0x02093BDC.  Each wants a seed at its own address in
 *      layout/function_starts.txt and the LATER label removed.
 *   2. A source for one of the three big functions must be compiled at the
 *      EARLIER address (`--addr 0x02092C38`, not 0x02092C3C), or the whole
 *      comparison is shifted by one instruction and every later byte reads
 *      as a difference.
 *   3. The home area exists because the function is VARIADIC or takes an
 *      aggregate by value.  Its presence is the proof of the signature: a
 *      parameter read as `ldrb [sp,#0x4x]` out of the home area is a byte of
 *      a by-value struct, never a separate `u8` parameter (a separate `u8`
 *      parameter arrives in a register and is read with shifts).
 *   4. Every return in such a function unwinds TWICE:
 *      `add sp,#<scalars>; pop {r3,r4..lr}; add sp, sp, #0x10; bx lr`.
 *      The trailing `add sp, sp, #0x10` is the home area being popped, and
 *      seeing it in a listing is by itself enough to know the row is
 *      mid-prologue.
 *
 * Addresses are Black-image addresses throughout.
 */

#ifndef CLUSTER_020929E8_H
#define CLUSTER_020929E8_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;
typedef signed   long long s64;

/* ================================================================== *
 * 0.  Runtime helpers this cluster calls
 *
 * All four are hand-written ARM assembly from MSL/runtime.a, listed in
 * layout/runtime_arm9.txt, so they are attested by the `runtime` evidence
 * class and declared `arm` in a symbols: block.  Note the divmod pair: the
 * 64-bit conversion loop does NOT spell `value % base` / `value / base` in
 * C -- that emits _ull_mod / _ll_udiv, which are different symbols and do
 * not resolve.  It calls the two divmod entry points directly, which is why
 * both take the same (value, base) pair and differ only in which half they
 * return.  Evidenced by func_02092C3C's two `bl` at +0x14C and +0x164.
 * ================================================================== */

extern u32 _u32_div_f(u32 value, u32 base);              /* 0x0209C2B0 */
extern u32 _ll_divmod_entry_flag1(u64 value, u64 base);  /* 0x0209C018, remainder */
extern u64 _ll_divmod_entry_flag0(u64 value, u64 base);  /* 0x0209C00C, quotient  */

/* ================================================================== *
 * 1.  The format descriptor, passed BY VALUE
 *
 * Eight bytes, so it crosses the register/stack boundary: bytes 0..3 in r3,
 * bytes 4..7 in the first caller stack word.  That split is exactly why the
 * callee emits the home-area push and reads its fields as `ldrb [sp,#0x4x]`.
 * Every field below is constrained by a compare in func_020929E8 or
 * func_02092C3C; the two functions agree field for field, which is the
 * strongest evidence in the cluster (they are the 32-bit and 64-bit twins of
 * one source template).
 * ================================================================== */

struct Spec8 {
    u8 b0;   /* +0x00  signed/width mode; compared with 2 at 0x02092B60  */
    u8 b1;   /* +0x01  sign style: 1 = '+', 2 = ' ', 0 = none            */
    u8 b2;   /* +0x02                                                    */
    u8 b3;   /* +0x03  prefix flag: emit '0' for octal, "0x" for hex     */
    u8 b4;   /* +0x04                                                    */
    u8 b5;   /* +0x05  the conversion character ('d' 'i' 'o' 'u' 'x' 'X')*/
    u8 b6;   /* +0x06                                                    */
    u8 b7;   /* +0x07                                                    */
};

/* The 0x1FD cap.  Both twins pool this word (0x02092C34 and 0x02092F08 hold
   0x000001FD) and return 0 when `width + (start - p)` exceeds it: it is the
   formatter's maximum field width, not a relocation. */
#define FMT_MAX_FIELD 0x1FD

/* ================================================================== *
 * 2.  The writer state and its callback
 *
 * The whole printf family is parameterised on a writer: a function pointer
 * plus a state block, passed as the two arguments of the format driver.
 * func_020944CC builds a FOUR-word block and passes &state[1], so the driver
 * receives a pointer to the {base, cap, pos} triple and the word before it
 * (state[0], the running count) belongs to the caller.
 * ================================================================== */

struct SprintfState {            /* what func_02094488 writes through      */
    u8  *base;                   /* +0x00  destination buffer              */
    u32  cap;                    /* +0x04  capacity                        */
    u32  pos;                    /* +0x08  bytes written so far            */
};

/* Evidenced by src/matched/func_02094488.c: the bounded copy is
   `if (pos + n > cap) n = cap - pos;`, then func_02092344 (memcpy) into
   base + pos, then `pos += n`, then `return 1`.  The return value is the
   "keep going" flag the driver tests with `cmp r0, #0` at 0x02093C4C. */
extern u32 func_02094488(u8 *p, const void *src, u32 n);   /* 0x02094488 */

/* The writer's type, as the driver calls it: `blx sb` with r0 = state,
   r1 = source, r2 = length.  Note the ARGUMENT ORDER is (state, src, n),
   i.e. the state is first, which is what makes func_02094488 usable as one
   directly. */
typedef u32 (*FmtWriter)(void *state, const void *src, u32 n);

/* ================================================================== *
 * 3.  The primitives below the cluster (already EXACT; use these
 *     prototypes verbatim, they are the ones the matched files carry)
 * ================================================================== */

extern void *func_02092344(void *dest, const void *src, u32 n);  /* memcpy  */
extern void *func_02092364(void *dest, const void *src, u32 n);  /* memmove */
extern void  func_02092430(u8 *dest, u32 val, u32 count);        /* memset  */
extern void *func_020923B0(void *p);                             /* memset wrapper */
extern u8   *func_020923C4(u8 *s, u32 c, u32 n);                 /* memchr  */
extern int   func_020923F0(const u8 *a, const u8 *b, int n);     /* memcmp  */
extern u32   func_02092144(u64 x);                               /* popcount64 */
extern int   func_020921D8(u64 v);                               /* signbit */
extern int   func_020921F4(u64 v);                               /* fpclassify */
extern u32   func_020922B0(u32 *dst, u32 c);                     /* wctomb  */
extern u32   func_020922CC(u8 *dst, const u16 *src, u32 max);    /* wcstombs */
extern void  func_02094860(u8 *dst, const u8 *src, u32 n);       /* short memcpy */

/* Called by the format driver at 0x02093BE0; both sit just above the
   cluster and are open at the time of writing.  The prototypes are read off
   the call sites, not guessed: func_02094A28 is called with (fmt, '%') and
   its result tested against 0, i.e. memchr-of-char returning a pointer;
   func_0209477C is called with (fmt) alone and its result added to a running
   total, i.e. strlen. */
extern u8 *func_02094A28(const u8 *s, u32 c);   /* 0x02094A28, strchr('%') */
extern u32 func_0209477C(const u8 *s);          /* 0x0209477C, strlen      */

/* ================================================================== *
 * 4.  The cluster's own functions
 * ================================================================== */

/* 0x020929E8 (588 B body, ARM) -- __utoa/__ltoa, 32 bit.
   Converts `value` to text BACKWARDS from `buf` (the NUL is written first
   with `strb r0, [r5, #-1]!`) and returns a pointer to the first character.
   Returns 0 when the field would exceed FMT_MAX_FIELD.
   The conversion character dispatch is a real `switch`, not an if/else
   chain: the image's signed binary tree (`cmp r8,#0x69; bgt; bge; cmp
   r8,#0x58; bgt; beq`) is 44 bytes larger than the chain and is the single
   most valuable spelling in this cluster.  See "OPEN RESIDUE" below. */
extern u32 func_020929E8(u32 value, u8 *buf, struct Spec8 spec,
                         u32 width_alt, u32 width);

/* 0x02092C3C (716 B body, ARM; real entry 0x02092C38) -- the same function
   over a 64-bit value.  Field for field identical to the twin above, with
   `value` arriving as the lo:hi pair and the digit loop calling the divmod
   entry points.  Signature measured in docs/notes/pkt_02092C3C.c.txt. */
extern u32 func_02092C3C(u32 lo, u32 hi, u8 *buf, struct Spec8 spec,
                         u32 width_alt, u32 width);

/* 0x02092F10 (1152 B body, ARM; real entry 0x02092F0C) -- the FLOAT
   formatter.  Triaged in docs/notes/pkt_020924DC.c.txt: a 0x4c-byte frame,
   a three-way switch on the conversion character ('0', 'I', 'N') that
   handles the infinity and NaN spellings out of the eight five-byte records
   at 0x020A8A40/48/50/54/58/60/68/6C ("inf"/"INF"/"nan"/"NAN" and their
   signed forms), and a general path that calls func_020972F0 (the
   decimal-digit generator), func_020929E8 (the integer twin above, for the
   exponent) and func_0209A504 / func_0209BAC8.  1152 bytes is 2.9x the
   largest ARM function this project has taken to EXACT; it is correctly
   triaged as out of budget. */

/* 0x020933B8 (276 B body, ARM) -- the decimal ROUNDING ODOMETER.  EXACT as
   src/matched/func_020933B8.c.  Operates on the digit-buffer control block:

       +0x00  u16 unk0
       +0x02  s16 num     decimal exponent (ldrsh 0x020934A0, strh reset)
       +0x04  u8  len     significant-digit count
       +0x05  u8  str[]   '0'..'9' ASCII digits

   Rounds str[] at position idx, propagating the carry leftwards, and on
   overflow renormalises to a single '1' with num incremented. */
struct DecBuf {
    u16 unk0;
    s16 num;
    u8  len;
    u8  str[1];
};
extern void func_020933B8(struct DecBuf *b, s32 idx);

/* 0x020934D0 (1760 B body, ARM) -- the largest row in the cluster and the
   float-to-decimal-digits engine that 0x02092F10 drives.  Not attempted. */

/* 0x02093BE0 (1276 B body, ARM; real entry 0x02093BDC) -- the FORMAT
   DRIVER, i.e. the core of vfprintf.  Signature read off the call site in
   src/matched/func_020944CC.c plus the prologue:

       u32 func_02093BDC(FmtWriter w, void *state, const u8 *fmt, ...)

   with `w` in r0 (moved to sb and reached with `blx sb`), `state` in r1
   (moved to r8), `fmt` in r2 (moved to fp) and the variadic tail in the home
   area.  Note the argument order is (writer, state, fmt), which is why
   func_020944CC passes `(u32)func_02094488` first and `&state[1]` second.
   The scan loop is: strchr(fmt,'%') -> if none, strlen(fmt) and emit the
   whole remainder through the writer -> else emit the literal run, parse the
   specifier into a struct Spec8, and dispatch. */
extern u32 func_02093BDC(FmtWriter w, void *state, const u8 *fmt, ...);

/* 0x02094534 -- a mis-seeded row, not a function: the 36 bytes at
   0x02094530 are already EXACT as src/matched/func_02094530.c (sprintf), and
   the real open function in this row starts at 0x0209455C.  That one is
   `qsort`: `push {r3,r4..lr}`, an early `cmp r1,#2 / poplo` (nothing to sort
   below two elements), then `mla r0, r8, r1, sl` twice to form element
   addresses from base + index * size -- the r8 = element size, sb = count,
   sl = base assignment is unambiguous. */

/* ================================================================== *
 * 5.  OPEN RESIDUE -- what is measured but not closed
 *
 * func_020929E8 stands at SIZE-EXACT with 112 concrete bytes out under
 * dsi/1.1p1 (592/592), after the switch respelling and 9800 permuter
 * candidates across hill and anneal.  The permuter's register-substitution
 * map is a clean cyclic rotation r4->r5->r6->r7->r4, i.e. a pure allocation
 * tie, and it will not move.  Two concrete leads for the next lane, both
 * read off the diff:
 *
 *   a. The frame is one scalar slot short: the image is
 *      `push {r3,r4..lr}` + `sub sp, sp, #0x10` (four slots: [sp]=start,
 *      [sp+4]=prefix, [sp+8]=width_alt, [sp+0xc]=neg), the compile is
 *      `push {r4..lr}` + `sub sp, sp, #0xc` (three: width_alt stays in a
 *      register).  Every attempt to force width_alt into memory by giving it
 *      a second read was coalesced away.  The `push {r3}` in the image is
 *      the alignment pad that the FOURTH slot pulls in, so recovering the
 *      slot recovers the push list too -- one fix, not two.
 *
 *   b. The INT_MIN guard is spelled 64-bit in the image even though the
 *      value and the division are 32-bit:
 *
 *          asr r0, sl, #0x1f        ; sign extension into a high word
 *          cmp r0, #0x80000000
 *          mov r0, #1
 *          cmpeq sl, #0
 *          rsbne sl, sl, #0
 *
 *      This is the 64-bit twin's `hi == 0x80000000 && lo == 0` test with
 *      `hi` supplied by sign-extending the 32-bit value -- and it is dead
 *      code, since `value >> 31` is only ever 0 or -1 and never 0x80000000.
 *      That is the fingerprint of ONE source template compiled twice, once
 *      with a 32-bit value type and once with a 64-bit one.  Spelling the
 *      guard as `(s64)(s32)value != INT64_MIN`, as the sign-extended pair,
 *      and as an explicit hi/lo pair all came out WORSE (319, 326 and 312
 *      bytes out against 112), so the 64-bit form is not reachable by
 *      writing 64 bits in this file; the likely shape is a shared macro or
 *      inline whose argument is widened at the call, which this project's
 *      single-function compilation model cannot express directly.
 *
 * The full measurement is in docs/notes/pkt_020929E8.c.txt.
 * ================================================================== */

/* ================================================================== *
 * 6.  WAVE 9 (2026-09-22): THE CLUSTER IS MSL printf.c, TRANSCRIBED
 *
 * Proven by five byte-exact transcriptions of MSL printf.c under dsi/1.1p1:
 *   0x020929E8  long2str      EXACT   src/matched/func_020929E8.c
 *   0x02092C38  longlong2str  EXACT*  src/matched/func_02092C38.c
 *   0x02092F0C  double2hex    EXACT*  src/matched/func_02092F0C.c
 *   0x020933B8  round_decimal EXACT*  (wave 7)
 *   0x020934CC  float2str     EXACT   src/matched/func_020934CC.c
 *   0x02093BDC  __pformatter  MATCH*  src/pending/func_02093BDC.c
 * SUPERSEDES sections 1 and 5 above:
 *   - struct Spec8 + (width_alt, width) is WRONG.  The descriptor is MSL's
 *     16-byte print_format passed by value:
 *         typedef struct {
 *             unsigned char justification_options;  +0  0 left,1 right,2 zero_fill
 *             unsigned char sign_options;           +1  0 only_minus,1 '+',2 ' '
 *             unsigned char precision_specified;    +2
 *             unsigned char alternate_form;         +3
 *             unsigned char argument_options;       +4  1 hh,2 h,3 l,4 ll,5 wide,
 *                                                       6 intmax,7 size_t,
 *                                                       8 ptrdiff,9 long double
 *             unsigned char conversion_char;        +5
 *             int field_width;                      +8
 *             int precision;                        +C
 *         } print_format;
 *     The "missing slot" and "dead 64-bit guard" residues of section 5 were
 *     both this declaration plus `num != 0x8000000000000000LL`.
 *   - All text pointers are UNSIGNED char (ldrb everywhere); MSL was built
 *     char-unsigned, the project flags are -char signed, so spell uchar.
 *   - The 0x02092F10 / 0x020934D0 / 0x02093BE0 rows are four bytes late:
 *     the entries are 0x02092F0C, 0x020934CC and 0x02093BDC (home push),
 *     exactly as section "THE HOME AREA" predicted, and all compile at the
 *     earlier address.  0x02094534 is already covered by
 *     src/matched/func_02094530.c (sprintf, EXACT, pkt_02094488).
 *   - strcpy(p, "-INF") etc. is mwcc's `__memcpy` INTRINSIC:
 *     `__memcpy(p, s_020A8A40, 5)` with the strings declared as NON-const
 *     `extern char s_[N]`.  A struct copy, or a const source, gives the
 *     same bytes with the wrong registers (src r1 instead of r3).
 *   - isupper() is a static INLINE FUNCTION over __ctype_map (bit 0x200),
 *     not a macro (macro form CSE's its 0 with a live 0.0 argument).
 *   - Runtime compares: `!=` on double is 0x0209BAC8 (_dneq, __dcmp_6),
 *     `<` is 0x0209B9A0 (_dls, __dcmp_4); 64-bit `%` / `/` are _ull_mod
 *     0x0209C018 / _ll_udiv 0x0209C00C (the section-0 note about divmod
 *     entry points is only about naming: plain `%` and `/` are right).
 *   - Callees: func_020972F0 = __num2dec(const decform*, double, decimal*),
 *     decform {char style; short digits;}, decimal {u8 sgn; char unused;
 *     short exp; {u8 length; u8 text[34]; u8 unused;} sig;} (40 bytes);
 *     func_020924DC = parse_format(fmt, &arg, &format); func_02094750 = the
 *     secure-printf constraint handler; func_020922CC = wcstombs.
 * ================================================================== */

/* ================================================================== *
 * 7.  WAVE 10 LANE 3 (2026-09-22): qsort, AND THE LAST BLOCKER
 *
 *   0x0209455C  qsort  EXACT  src/matched/func_0209455C.c (312 B, ARM)
 *     MSL stdlib qsort.c heapsort, verbatim structure (l/r/j, lp/rp/ip/jp/kp,
 *     table_ptr(i) = base + size*(i-1)).  Two levers: the byte-swap macro
 *     assigns its COUNT before its two pointers (mov r2,r8 precedes the two
 *     ldr/mov of the pointers), and the swapped bytes are unsigned char.
 *     disasm.py has no label at 0x0209455C, so worklist row pkt_02094534
 *     (code_end 0x0209455C) counts it as extent: it wants a seed.  With it
 *     the 0x02094530..0x02094750 span is closed end to end (sprintf,
 *     qsort, rand 0x02094694, srand 0x020946C8, __StringRead 0x020946D8).
 *
 *   0x02093BDC  __pformatter  still MATCH* in src/pending, NO C CHANGE CAN
 *     CLOSE IT.  Confirmed 2026-09-22: memchr compiled ALONE at 0x020923C4
 *     (the unit's own body, nothing else) is EXACT, 44 bytes, so either
 *     integrator fix works: (a) header of src/matched/unit_020923B0.c ->
 *     `function: func_020923B0, func_020923C4, func_020923F0` and re-verify
 *     pkt_020923B0 (entry_from_source() takes unit members from that line,
 *     matched_index() then indexes 0x020923C4), or (b) seed 0x020923C4 in
 *     layout/function_starts.txt (sole-ref/code).
 * ================================================================== */

#endif /* CLUSTER_020929E8_H */
