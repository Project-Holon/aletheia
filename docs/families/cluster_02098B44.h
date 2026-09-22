/*
 * docs/families/cluster_02098B44.h -- shared declarations for the
 * pseudo-family at 0x02098B44..0x0209C308 in the ARM9 image.
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
 * pseudo_families.json, key "pkt_02098B44"):
 *
 *   0x02098B44  OPEN     4 B       NOT A FUNCTION -- home-area push of 02098B48
 *   0x02099224  OPEN     4 B       NOT A FUNCTION -- home-area push of 02099228
 *   0x0209A0EC  matched  unit      __kernel_sin(double, double, int)
 *   0x0209A0F0  matched  (body)    body label of the above
 *   0x0209A368  matched  func      copysign(double, double)
 *   0x0209A390  matched  unit      cos(double)
 *   0x0209A504  matched  func      fabs(double)
 *   0x0209A524  matched  func      floor(double)           <- filed this wave
 *   0x0209A6E8  matched  func      frexp(double, int *)
 *   0x0209A7A8  matched  func      ldexp(double, int)      <- filed this wave
 *   0x0209AA0C  matched  unit      sin(double)
 *   0x0209AB80  OPEN     8 B       NOT A FUNCTION -- ARM linker veneer
 *   0x0209AB8C  matched  func      case-insensitive strcmp
 *   0x0209C2B8  OPEN     80 B      NOT A FUNCTION -- unsigned-divide body
 *
 * THE SUBSYSTEM.  This is the Metrowerks Standard Library's DOUBLE-PRECISION
 * MATH layer: fdlibm's trig kernels and IEEE-754 bit-twiddling primitives
 * (fabs, copysign, frexp, ldexp, rint, sin, cos, __kernel_sin, __kernel_cos,
 * __ieee754_rem_pio2), sitting immediately above the soft-float runtime that
 * occupies the rest of the window (__dadd/__dsub/__dmul/__dcmp/_d2s, see
 * docs/notes/pkt_0209AF34_soft_float_library.c.txt and
 * docs/notes/pkt_0209BDBC_runtime_library.c.txt).  There is no game data here
 * at all; this is library C compiled into the image, and the adjacent cluster
 * docs/families/cluster_02096D10.h is MSL's decimal conversion layer built on
 * top of it (func_02097170 calls ldexp at 0x0209A7A8 by name).
 *
 * The evidence that fixes the reading: unit_0209A390.c and unit_0209AA08.c are
 * byte-exact transcriptions of fdlibm sin()/cos() verbatim, including the
 * `n & 3` kernel selection and the |x| <= 0x3fe921fb short circuit; there is no
 * other code that has that shape.  Everything else in the cluster is the set of
 * helpers those two need, plus the soft-float they lower to.
 *
 * Derived from the seven matched sources found with
 *   grep -l "address:  0x02098\|address:  0x02099\|address:  0x0209A\|\
 *            address:  0x0209B\|address:  0x0209C[0-2]" src/matched/*.c
 * (func_0209A368, func_0209A504, func_0209A6E8, func_0209AB8C, unit_0209A0EC,
 * unit_0209A390, unit_0209AA08) and from the notes docs/notes/pkt_02098B44.c.txt,
 * docs/notes/pkt_0209AB80.c.txt, docs/notes/pkt_0209C2B8.c.txt and
 * docs/notes/unsigned-divide-entry-is-0209c2b0.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  For this cluster the rule specialises: the ONLY
 * thing the code reads is the two 32-bit halves of a double, always through
 * `&x`, so every "field" here is a word index into a double.  Word 1 is the
 * high half (sign+exponent+top mantissa), word 0 the low half; `-char signed`
 * and little-endian are both assumed by the existing exact sources.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * NO PIN.  Every byte-exact source in this cluster is `compiler: 1.1p1`,
 * `flags: -O4,p`, the project default.  There is no --cc ../2.0/sp2 evidence
 * anywhere in the window, and none was needed this wave: both functions worked
 * at 0x0209A524 and 0x0209A7A8 reached their best result under 1.1p1.  If a
 * function here comes out size-exact with a push list one register wider than
 * the image, that is the sp2 tell from docs/FRONTEND-PINS.md and would be the
 * first pin in this cluster -- but nothing has shown it yet, so do not start by
 * changing the compiler.
 *
 * THE ONE CODEGEN TELL THIS WAVE PAID FOR.  func_0209A7A8 came out size-exact
 * with two bytes wrong at +0x006C: the image has `orrs r0, r1, r0` where the
 * obvious fdlibm transcription `((hx & 0x7fffffff) | lx) == 0` emits
 * `orrs r0, r0, r1`.  That is
 * docs/idioms/commutative-operand-order-names-the-temporary.md exactly: the
 * accumulator is the SECOND operand, so the source order is
 * `(lx | (hx & 0x7fffffff)) == 0`.  Upstream fdlibm writes it the other way
 * round, so every transcription from the public source will land on this and
 * only this byte pair; swap the operands rather than looking for a pin.
 *
 * A second, cheaper one: an early guard that is written as
 * `if (ok) { body } return x;` shares one epilogue and comes out 4 bytes
 * short, while the image duplicates the `return x` epilogue.  Writing it as
 * `if (!ok) return x;` up front reproduces the duplicate.  See
 * docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md.
 *
 * ISA: ARM throughout, and this one IS a hard cluster property: the whole
 * MSL/fdlibm library region is ARM even though the ARM9 static module is Thumb
 * almost everywhere.  Always pass `--arm`.
 *
 * THE HOME-AREA PUSH, and why four of the six "open" rows are not C.
 * ----------------------------------------------------------------------------
 * mwccarm passes a `double` in a register pair and, whenever the body takes the
 * address of that parameter (which every fdlibm function does, to read its
 * words), emits a bare `push {r0, r1, r2, r3}` as a four-byte HOME AREA ahead
 * of the real prologue -- see docs/idioms/address-of-a-register-parameter-is-a-
 * push-of-all-four.md.  disasm.py only auto-labels a prologue that saves `lr`,
 * so it labels the SECOND push and leaves the home area as an unlabelled
 * four-byte run, which the worklist then lists as a 4-byte "function".
 *
 *   A 4-byte ARM row that is exactly `push {r0, r1, r2, r3}` is never a
 *   function.  It is the real entry of the function labelled 4 bytes later,
 *   and the correct filing is a `unit:` file anchored at the push, exactly as
 *   unit_0209A0EC.c / unit_0209A390.c / unit_0209AA08.c already do.
 *
 * That disposes of 0x02098B44 (home area of the 1684-byte __ieee754_rem_pio2
 * at 0x02098B48) and 0x02099224 (home area of the 724-byte __kernel_cos at
 * 0x02099228).  The other two:
 *
 *   0x0209AB80  8 B   `ldr ip,[pc]; bx ip; .word 0x020979BC` -- an ARM linker
 *                     long-branch veneer, emitted by the linker, not the
 *                     compiler; no C spelling reproduces it.  See
 *                     docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-
 *                     is-a-long-branch-veneer.md.
 *   0x0209C2B8  80 B  the head of the 476-byte unsigned-divide routine whose
 *                     entry is 0x0209C2B0 (`_u32_div_f`); the 80 bytes stop at
 *                     the `add pc, pc, r2, lsl #2` jump table's alignment word.
 *                     A 29-deep unrolled restoring division reached through a
 *                     PC-relative table is not a shape any C front end emits.
 * ============================================================================
 */

#ifndef CLUSTER_02098B44_H
#define CLUSTER_02098B44_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;
typedef int                i32;

/* ================================================================== *
 * 0.  The one "struct" in the cluster: a double's two words
 * ================================================================== */

/* Every function here reads a double as two 32-bit words through the address
   of its own register parameter.  The existing exact sources spell it as a
   macro pair and NOT as a union; func_0209A6E8.c, unit_0209A0EC.c,
   unit_0209A390.c and unit_0209AA08.c all carry exactly these two lines, and
   func_0209A504.c / func_0209A368.c use the `u32` form inline.  Keep the
   spelling: `((i32 *)&(x))[1]` as an lvalue is what produces the home-area
   push plus the `[sp, #0x24]` re-read, and a union or a memcpy does not.      */
#define HI(x) (((i32 *)&(x))[1])       /* high word: sign | exp | mant hi     */
#define LO(x) (((i32 *)&(x))[0])       /* low  word: mantissa low             */

/* The u32 spelling of the same access, used where the value is masked rather
   than compared (func_0209A504, func_0209A368).                               */
/* ((u32 *)&x)[1] &= 0x7fffffff;  -- clear sign                                */

/* ================================================================== *
 * 1.  The IEEE-754 constants the cluster tests against
 * ================================================================== */

#define D_EXP_MASK    0x7ff00000       /* exponent field of the high word     */
#define D_ABS_MASK    0x7fffffff       /* high word with the sign cleared     */
#define D_SIGN_MASK   0x80000000u
#define D_MANT_HI     0x000fffff       /* mantissa bits inside the high word  */
#define D_PIO4_HI     0x3fe921fb       /* |x| <= pi/4 test, sin()/cos()       */
#define D_EXP_BIAS    0x3ff
#define D_HALF_HI     0x3fe00000       /* high word of 0.5 <= |x| < 1         */
#define D_SUBNORM_HI  0x00100000       /* smallest normal's high word         */

/* The scaling and inexact-raising constants.  Every one of these was read off
   a literal pool in this cluster, so the set is complete for the window:
     two54   0x43500000_00000000   func_0209A6E8 (frexp), func_0209A7A8 (ldexp)
     twom54  0x3C900000_00000000   func_0209A7A8
     huge    0x7E37E43C_8800759C   func_0209A524 (floor), func_0209A7A8
     tiny    0x01A56E1F_C2F8F359   func_0209A7A8
   `huge + x > 0.0` in floor() and the +-50000 exponent clamps in ldexp()
   (0x0000C350 / 0xFFFF3CB0) are the fdlibm signatures that name both bodies.  */
static const double two54  = 1.80143985094819840000e+16;
static const double twom54 = 5.55111512312578270212e-17;
static const double dhuge  = 1.0e+300;
static const double dtiny  = 1.0e-300;

/* ================================================================== *
 * 2.  The fdlibm layer -- prototypes with exact parameter types
 * ================================================================== */

/* All of these are ARM.  Declare them in a `symbols:` block as
 *   func_XXXXXXXX  0xXXXXXXXX  arm
 * (or let the naming convention carry them, which it does for func_ names).  */

extern int    func_02098B44(double x, double *y);   /* __ieee754_rem_pio2     */
extern double func_02099224(double x, double y);    /* __kernel_cos           */
extern double func_0209A0EC(double x, double y, int iy); /* __kernel_sin      */
extern double func_0209A368(double x, double y);    /* copysign(x, y)         */
extern double func_0209A394(double x);              /* cos(x), entry 0209A390 */
extern double func_0209A504(double x);              /* fabs(x)                */
extern double func_0209A524(double x);              /* floor(x)               */
extern double func_0209A6E8(double x, int *eptr);   /* frexp(x, eptr)         */
extern double func_0209A7A8(double x, int n);       /* ldexp(x, n)            */
extern double func_0209AA0C(double x);              /* sin(x), entry 0209AA08 */
extern int    func_0209AB8C(const u8 *s1, const u8 *s2); /* stricmp          */

/* The classification helper ldexp() calls first.  Returns a small int class
   code; `cmp r0, #2; ble` at 0x0209A7C0 is "not finite -> return x", so the
   codes rank NaN/Inf above the finite ones, i.e. an fpclassify, not an
   isfinite.  Takes the double by value (register pair) and homes it itself.   */
extern int    func_020921F4(double x);              /* __fpclassify(double)   */

/* ================================================================== *
 * 3.  The soft-float runtime this cluster lowers to
 * ================================================================== */

/* These are MSL/runtime.a, hand-written ARM.  layout/runtime_arm9.txt names
   them, so a call site resolves as evidence class `runtime`; declare them
   `arm` in `symbols:`.  Note _dadd is at the veneer-looking 0x0209AC04 and is
   an ordinary extern there, not at any inner address.                         */
extern double func_0209AC04(double x, double y);    /* __dadd  / _dadd        */
extern double func_0209AF34(double x, double y);    /* __dsub  / _dsub        */
extern double func_0209B2E8(double x, double y);    /* __dmul  / _dmul        */
extern double func_0209B750(double x);              /* _s32_to_double         */
extern int    func_0209B864(double x, double y);    /* __dcmp_2 (ordered <=)  */
extern int    func_0209BA3C(double x, double y);    /* __dcmp_5 (equality)    */
extern int    func_0209C508(double x);              /* _d2s, double -> int    */
extern u32    func_0209C554(double x);              /* _d2u, double -> u32    */

/* The division entries, for completeness: the *unsigned* one is 0x0209C2B0,
   NOT the 0x0209C2B8 the worklist lists, and runtime_arm9.txt misnames it
   `_div_by_zero_check`.  See docs/notes/unsigned-divide-entry-is-0209c2b0.c.txt.
     _s32_div_f  0x0209C0A4  arm
     _u32_div_f  0x0209C2B0  arm                                              */

/* ================================================================== *
 * 4.  Data objects
 * ================================================================== */

/* The only data object any matched source in this cluster names.  A 256-byte
   byte table indexed by a character below 0x80; func_0209AB8C's `ldrblt`
   through it is what fixes both the element type and the 0x80 bound.          */
extern const u8 g_020A60DC[];           /* 0x020A60DC -- tolower/collate map  */

/* __ieee754_rem_pio2's two tables, from the pool-word census in
   docs/notes/pkt_02098B44.c.txt (not yet transcribed; recorded so the next
   lane does not re-derive the addresses).                                     */
/* extern const int  g_020A6320[];  0x020A6320 -- two_over_pi / npio2_hw       */
/* extern const int  g_020A63A0[];  0x020A63A0                                 */

#endif /* CLUSTER_02098B44_H */
