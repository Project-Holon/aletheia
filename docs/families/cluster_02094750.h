/*
 * docs/families/cluster_02094750.h -- shared declarations for the
 * pseudo-family at 0x02094750..0x020949EC in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  Formed by address adjacency plus shared
 * callees; unlike the other clusters in this document set it is NOT game code
 * at all.  0x0209477C..0x020949EC is the METROWERKS STANDARD LIBRARY (MSL)
 * STRING SECTION, linked into the ARM9 static module: `strlen`, `strcpy`,
 * `strncpy`, `strcat` and `strcmp`, in that order and in their published
 * 4-byte-at-a-time forms.  Two consequences follow and both matter:
 *
 *   - THERE IS NO GAME SEMANTICS TO RECOVER.  A function here is right when it
 *     is the library's algorithm; do not look for a struct, a global or a
 *     caller to constrain a field, because there are none.  This whole range
 *     carries ZERO relocations.
 *   - THE ALGORITHM IS PUBLISHED AND PINS ITSELF.  Every word-at-a-time
 *     routine uses the Alan Mycroft null-byte test with the two pool constants
 *     0xFEFEFEFF and 0x80808080, which sit at 0x02094858/0x0209485C (strcpy)
 *     and 0x020949EC/0x020949F0 (strcmp) as PLAIN LITERALS.
 *
 * The one member that is not MSL is the head of the range: func_02094750, a
 * dispatch hook that calls whatever three-argument function pointer sits in
 * g_02153FB0 and otherwise falls through to the empty default func_02094778.
 *
 * Derived from the matched sources found with
 *   grep -l "address:  0x02094[7-8]" src/matched/*.c
 * (func_02094750, func_02094778, func_0209477C, unit_02094860) and from
 * docs/notes/pkt_02094798.c.txt and docs/notes/func_020948E0.c.txt.
 *
 * ============================================================================
 * THE COMPILER PIN.  There ISN'T one.
 * ============================================================================
 *
 * Every matched source in the range carries `compiler: 1.1p1`, the project
 * default, and func_020948E0 closed byte-exact under it in wave 7.  This is
 * worth stating because the range LOOKS like it should need the SDK's own
 * build: it is library code, it is ARM, and it sits next to the SDK.  It does
 * not.  Compile it exactly like game code, with `--arm`.
 *
 * ISA: ARM throughout.  Always pass `--arm`.
 *
 * ============================================================================
 * THE LEVER THIS CLUSTER IS ABOUT: ONE VARIABLE, TWO WIDTHS.
 * ============================================================================
 *
 * Both word-at-a-time routines here were recorded as register-allocation walls
 * before wave 7 (strcmp 28 of 276 bytes, strcpy 2 of 200).  strcmp's turned
 * out not to be a register-allocation wall at all, and the tell is worth
 * carrying to any other MSL routine in this image:
 *
 *   THE SAME `u32` LOCAL HOLDS BOTH THE 32-BIT WORD AND THE SINGLE BYTE.
 *
 * func_020948E0 leaves its word loop with `b #0x20949bc`, landing on
 * `cmp r2, #0` where r2 still holds the WORD just loaded by `ldr r2,[r0,#4]!`.
 * That is sound -- the haszero test has already proved no byte of that word is
 * zero -- and it is only expressible if one variable names both.  Declaring a
 * separate `unsigned char` for the byte adds a third value live across the
 * word loop and widens the prologue from `push {r4, lr}` to
 * `push {r3, r4, r5, lr}`, which is the entire 28-byte residue.  Corollary:
 * in this range a push list one or two registers WIDER than the image is a
 * live-value count, never a compiler tell.
 *
 * Two further shapes, both measured on func_020948E0 and both in the image:
 *
 *   - THE TWO HASZERO TESTS ARE NOT THE SAME EXPRESSION.  The test BEFORE the
 *     word loop is the full `(w + 0xFEFEFEFF) & ~w & 0x80808080` (`mvn`,
 *     `add`, `and`, `tst`); the test INSIDE the loop drops the `~w` and is
 *     only `(w + 0xFEFEFEFF) & 0x80808080` (`add`, `tst`).  Writing the full
 *     expression in both places compiles the loop body two instructions long.
 *     func_02094798 is the OPPOSITE case -- both of its tests are the full
 *     form -- so this is per-routine evidence, not a rule.
 *   - A BLOCK THAT FALLS THROUGH INTO THE EPILOGUE.  strcmp's "resolve inside
 *     the word" block ends `popne {r4, pc}` and falls into the byte epilogue's
 *     `cmp`; the two `goto`s into the epilogue target that `cmp`, not the
 *     block.  Re-testing the byte at the top of the epilogue costs four bytes.
 *
 * WHAT IS STILL OPEN.  func_02094798 (strcpy) is a 198-of-200 near miss whose
 * residue is one instruction's destination register -- `and lr, r4, lr` where
 * the compile writes `and r4, r4, lr` -- in the LAST of the function's four
 * haszero tests.  The accumulator is the register holding `~w` in the image,
 * both times; the identical text in the pre-loop test does land in the right
 * register.  Measured against it, all failing: the expression inline in a
 * `while`, in a `for(;;)/break`, with `~w` and the sum each bound to their own
 * named local (in both orders), every parenthesisation, the mask written
 * first, and the `u32`-holds-the-byte trick above.  tools/permuter.py exhausts
 * every single mutation (hill, 280 sites) and 2000 anneal candidates without
 * moving it.  See docs/notes/pkt_02094798.c.txt.
 * ============================================================================
 */

#ifndef CLUSTER_02094750_H
#define CLUSTER_02094750_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   int       s32;

/* ================================================================== *
 * 0.  The one data object, and the one non-library function
 *
 * func_02094750's `ldr r3` / `blx r3` is what pins the hook's arity: with a
 * zero- or one-argument callee the compiler puts the target in r0 or r1 and
 * the head of the function shifts.  The three arguments are passed straight
 * through, so nothing in the bytes fixes their meaning.
 * ================================================================== */

typedef void (*Hook02153FB0)(u32, u32, u32);
extern Hook02153FB0 g_02153FB0;         /* 0x02153FB0  data                    */

extern void func_02094750(u32 a, u32 b, u32 c);   /* hook, else func_02094778  */
extern void func_02094778(void);                  /* the empty default         */

/* ================================================================== *
 * 1.  The MSL string routines
 *
 * Signatures are the C library's.  func_0209477C is NOT the library's strlen
 * helper but a plain open-coded byte counter (count up to and including the
 * NUL, return the count minus one); it is byte-exact from exactly that.
 * ================================================================== */

extern s32  func_0209477C(const u8 *s);                       /* strlen        */
extern u8  *func_02094798(u8 *dst, const u8 *src);            /* strcpy, open  */
extern u8  *func_02094860(u8 *dst, const u8 *src, u32 n);     /* strncpy       */
extern u8  *func_020948B0(u8 *dst, const u8 *src);            /* strcat        */
extern s32  func_020948E0(const char *s1, const char *s2);    /* strcmp        */

/* ================================================================== *
 * 2.  Constants
 * ================================================================== */

/* The Mycroft null-byte test.  Both words are plain literals in the pools at
   0x02094858/0x0209485C and 0x020949EC/0x020949F0 -- no relocation anywhere in
   this range.  A word contains a zero byte iff
   ((w + MSL_HASZERO_ADD) & ~w & MSL_HASZERO_MASK) != 0.                       */
#define MSL_HASZERO_ADD     0xFEFEFEFFu
#define MSL_HASZERO_MASK    0x80808080u

/* Both word loops align by copying (3 - (p & 3)) leading bytes after the
   first, i.e. the pre-loop count is written `rsbs r4, r4, #3` in the image
   and `3 - align` in the C.                                                   */
#define MSL_ALIGN_MASK      3

#endif /* CLUSTER_02094750_H */
