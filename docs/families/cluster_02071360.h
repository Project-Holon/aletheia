/*
 * docs/families/cluster_02071360.h -- shared declarations for the
 * pseudo-family at 0x02071360..0x02071DD4 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations this cluster's byte-exact sources already carry.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so like docs/families/cluster_020737C0.h and unlike
 * docs/families/mcss.h this cluster is NOT a recovered translation unit: it
 * was formed by address adjacency plus shared callees and data objects.
 *
 * THE SUBSYSTEM IS THE 2D CELL/SPRITE AFFINE TRANSFORM STAGE.  Every function
 * in the range takes a source object (call it Cel) carrying a 3x2 fixed-point
 * matrix and an angle pair, and either
 *
 *   (a) builds a 0x38-byte DESTINATION matrix out of it -- the constructor
 *       family, twelve near-identical variants of which this cluster holds
 *       six and the neighbouring pkt_02071B2C / pkt_02071DD4 hold the rest;
 *       or
 *   (b) marshals a display descriptor onto the stack and hands it to
 *       func_0206DDA4, the geometry-command sink -- func_020713C8 (EXACT,
 *       dsi/1.1p1), func_02071510 (EXACT, ../2.0/sp2) and func_02071858
 *       (EXACT, ../2.0/sp2, filed this wave).
 *
 * The 1.12 fixed-point convention is used throughout: a unit scale is 0x1000,
 * a product of two 1.12 values is `(s64)a * b >> 12`, and the angle halfwords
 * at +0x2c / +0x2e are 1.16 sines/cosines that reach the matrix as
 * `<< 11` / `<< 15` biases with a `>> 8` on the 64-bit product.
 *
 * Derived from the matched sources found with
 *   grep -l "address:  0x02071[3-D]" src/matched/*.c
 * namely func_020713A4.c, func_020713C8.c, func_02071510.c, func_02071858.c,
 * func_02071B2C.c, func_02071C94.c, func_02071CDC.c and unit_02071DD4.c,
 * and from the notes docs/notes/pkt_02071B2C.c.txt,
 * docs/notes/pkt_02071DD4.c.txt and docs/notes/func_02071EFC.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrsh` proves signedness; a plain `ldrh` feeding a
 * `mul` proves the field is unsigned 16-bit and the widening happens at the
 * use.  Where two matched files disagree, the file whose code actually
 * constrains the field wins.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * THIS CLUSTER IS MIXED, and that is itself the finding: unlike
 * cluster_020737C0, which pins wholesale, here the two halves of the
 * subsystem pin OPPOSITE WAYS and each function must be measured.
 *
 *   ../2.0/sp2   func_020713A4  func_02071510  func_02071858  func_02071C94
 *                func_0207163C  func_02071C14                 (wave 10)
 *   dsi/1.1p1    func_020713C8  func_02071B2C  func_02071CDC  unit_02071DD4
 *   EITHER       func_02071360  func_02071A24                 (wave 10: same
 *                C byte-exact under both; filed under the default)
 *
 * Wave-10 additions to the tells.  func_0207163C is "kept constants" on a
 * CALL ARGUMENT: the image rematerialises `mov r2, #0x18` before each of
 * its four MIi_CpuCopy32 calls, 1.1p1 keeps 0x18 in a callee-saved
 * register (536 vs 540 bytes).  func_02071C14 shows a THIRD, smaller tell:
 * with everything else identical, 1.1p1 schedules the final
 * `ldrh r1, [r1, #0x2e]` one slot earlier than the image (6 bytes, one
 * swapped pair); 2.0 is exact.
 *
 * Both of this cluster's 2.0 tells are documented in docs/FRONTEND-PINS.md:
 *
 *   "KEPT CONSTANTS" -- func_020713A4 and func_02071C94.  The image
 *   materialises the 0x1000 unit scale FIRST and the zero LATE; 1.1p1 -O4,p
 *   schedules the zero first and, in func_02071C94's case, then MERGES the
 *   f00/f04 store pair into one `stm`, four bytes short.
 *
 *   "KEPT BRANCHES" -- func_02071510 and func_02071858.  The image keeps a
 *   guard's `beq` plus its unconditional join branch over a short arm; 1.1p1
 *   -O4,p if-converts the arm to predicated instructions and drops both
 *   branches.  Symptom: size-exact minus 4, 8 or 12 with everything after the
 *   guard shifted.
 *
 * The 1.1p1 half is the half whose bodies are pure 64-bit arithmetic with no
 * short guarded arm and no live small constant, i.e. nothing for either tell
 * to bite on.  So the practical rule for a new function here is:
 *   a guarded short arm, or a 0 / 0x1000 live at more than one point  -> 2.0
 *   a straight-line smull/smlal chain                                 -> 1.1p1
 * and when in doubt, measure both -- three of this wave's six open functions
 * came out size-exact under BOTH front ends with the SAME residue, which
 * proves the residue is in the C and not in the pin.
 *
 * ISA: ARM throughout, unusual for game code (the ARM9 static module is Thumb
 * almost everywhere) and a cluster property in its own right: always pass
 * `--arm`.  It is shared with cluster_020737C0, whose range abuts this one.
 * ============================================================================
 */

#ifndef CLUSTER_02071360_H
#define CLUSTER_02071360_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;
typedef long long          s64;

/* ================================================================== *
 * 0.  Callees
 * ================================================================== */

/* The geometry-command sink.  Takes a packed command word, the body that
   follows it and a word count.  Evidenced by func_020713C8 (count 0x12),
   func_02071510 (counts 3, 9 and 0xc) and func_02071858 (count 0xe): the
   count is the descriptor's length MINUS its first word, and the body
   pointer is the descriptor's address PLUS four -- both files spell it
   `(char *)buf + 4`, never `&buf[1]`, because the image forms it as
   `add r1, sp, #0` then `add r1, r1, #4`. */
extern void func_0206DDA4(u32 cmd, int *body, int n);

/* The angle-pair mode call.  Evidenced by func_02071B2C, func_02071CDC and
   func_02071A24: both arguments are the two halfwords at +0x2c / +0x2e
   widened by `<< 12`, and the SECOND call passes them in the opposite order
   to the first.  Return value unused. */
extern void func_0207C930(s32 a12, s32 b12);

/* The scale query.  Evidenced by the same three: no arguments, and its s32
   result is multiplied by an s16 field and shifted right 12.  Called TWICE
   per constructor, once for the +0x04 slot and once for the +0x10 slot, and
   the two calls are NOT CSE'd -- writing one call to a local and reusing it
   loses the second `bl`. */
extern s32  func_0207C86C(void);

/* The 0x18-byte block copy of func_0207163C.  It is MIi_CpuCopy32 and it
   takes the SOURCE FIRST (src, dst, size) -- src/matched/func_0207163C.c
   names it that way and the argument order there is the data flow.  Called
   four times with a literal `mov r2, #0x18`, which is what fixes the size. */
extern void MIi_CpuCopy32(const void *src, void *dst, u32 n); /* 0x02082A90 */

/* ================================================================== *
 * 1.  Data objects (func_0207163C's pool; EXACT wave 10, ../2.0/sp2)
 * ================================================================== */

/* The allocator's owner block.  Reached as `ldr r3, [r2]` then
   `ldr r1, [r3, r2, lsl #2]` at +0xc4, i.e. a POINTER at 0x02148DB0 to a
   structure whose bitmask array starts at +0xC4 and is indexed by
   `slot >> 5` with the bit `1u << (slot & 0x1f)`.  The `add r3, r3, #0xc4`
   / `ldr r1, [r3, r2, lsl #2]` pair at 0x02071684 fixes the +0xC4 offset
   as a base the compiler forms once, not a member offset per access. */
extern void *ptr_02148DB0;              /* 0x02148DB0  a4                     */

/* The per-slot matrix table.  PROVEN ONE OBJECT (wave 10): the six
   consecutive pool words 0x02149BB4 .. 0x02149BC8 are ONE `s32 [][6]` table
   whose column k is addressed as symbol + 4k, because the register-offset
   `ldr r, [base, ip]` (ip = slot * 0x18) has no room for a further
   immediate.  Declared as a single 2-D extern, src/matched/func_0207163C.c
   reproduces all six words; six separate externs are not needed.         */
extern s32 g_02149BB4[][6];             /* 0x02149BB4  a4, stride 0x18        */

/* ================================================================== *
 * 2.  struct Cel -- the SOURCE object of every constructor
 *
 * Field evidence, one function per line:
 *   +0x00  flags.  func_020713C8 reads bits 0-2 as a dispatch index and bit 3
 *          as a command selector; func_02071510 reads bits 0,1,2 and the
 *          pair 3/4 (mask 0x18); func_02071858 reads bits 3, 2 and 0.  Plain
 *          u32, never a bitfield -- every read is `tst` or `and #k` on the
 *          whole word, which a bitfield would spell as a shift pair.
 *          VOLATILE in func_02071858: the inner guard re-reads it although
 *          the outer one left it in a register.
 *   +0x18  s32.  func_02071360 and func_02071C14 copy it straight to the
 *          destination's +0x00; func_02071CDC and func_02071A24 feed it to
 *          `smull` against an s16, so it is a 32-bit 1.12 scale.
 *   +0x1c  s32, the +0x18 partner, likewise to the destination's +0x14.
 *   +0x20  s16, +0x22 s16.  PROVEN SIGNED by `ldrsh` (func_02071B2C at
 *          0x02071B54 and 0x02071B68, func_02071A24 at 0x02071A4C/0x02071A54)
 *          -- immediate-offset `ldrsh` exists, so this is direct evidence and
 *          not the register-offset idiom.  Spelling either u16 turns every
 *          `smull` in the function into `umull`.
 *   +0x24  s32, +0x28 s32.  The translation pair.  func_02071858 shifts each
 *          `<< 4` and negates it; func_02071C14 and func_02071A24 multiply it
 *          by the matching angle halfword.
 *   +0x2c  u16, +0x2e u16.  The angle pair.  UNSIGNED: every read is a plain
 *          `ldrh` and every use widens with `(s32)`.  They reach
 *          func_0207C930 as `<< 12`, the matrix as `<< 15`, and the
 *          translation bias as `<< 11`.
 *   +0x30  s32, +0x34 s32.  The two 1.12 scale factors, compared against
 *          0x1000 and skipped when unity.  VOLATILE wherever a function uses
 *          each one twice: func_020713C8 and func_02071858 both need it, and
 *          without it mwcc caches the field and batches the multiplies.
 * ================================================================== */
struct Cel {
    u32 flags;              /* 0x00  volatile at the re-read sites            */
    u8  pad_04[0x14];
    s32 f18;                /* 0x18                                          */
    s32 f1c;                /* 0x1c                                          */
    s16 f20;                /* 0x20  ldrsh                                   */
    s16 f22;                /* 0x22  ldrsh                                   */
    s32 f24;                /* 0x24                                          */
    s32 f28;                /* 0x28                                          */
    u16 f2c;                /* 0x2c  ldrh                                    */
    u16 f2e;                /* 0x2e  ldrh                                    */
    s32 f30;                /* 0x30  volatile at the two-use sites           */
    s32 f34;                /* 0x34  volatile at the two-use sites           */
};

/* ================================================================== *
 * 3.  struct Mtx -- the DESTINATION object of every constructor
 *
 * Only six words of it are ever written, and always in the same slots, which
 * is what makes the twelve constructors recognisable as one family:
 *   +0x00, +0x14  the two diagonal scale slots (0x1000 in the identity case)
 *   +0x04, +0x10  the two off-diagonal slots (0 in the identity case)
 *   +0x30, +0x34  the translation pair
 * The padding between them is never touched, so its extent is not evidenced
 * by this cluster and the declaration below is the minimum that reproduces
 * the offsets.
 * ================================================================== */
struct Mtx {
    s32 f00;
    s32 f04;
    u8  pad_08[8];
    s32 f10;
    s32 f14;
    u8  pad_18[0x18];
    s32 f30;
    s32 f34;
};

/* ================================================================== *
 * 4.  The constructor family, by shape
 *
 * Twelve variants, distinguished by WHICH of the source's fields reach the
 * destination.  Sorted by size; the ones in this cluster are marked.
 *
 *   0x020713A4   36 B  identity: 0x1000 / 0 only, no source read at all
 *   0x02071EFC   36 B  identity again (a separate copy, see its note)
 *   0x02071360   68 B  * f18/f1c straight through, f34 from f1c and f2e
 *                         (EXACT wave 10: f34 is spelled with the operand
 *                         doubled OUT, `(0x1000 - f1c + 0x1000 - f1c) * f2e
 *                         * 8`; every factored form folds the negate)
 *   0x02071C94   72 B    f18/f1c through, f30/f34 from f24/f28 and f2c/f2e
 *   0x02071EAC   80 B    the unlabelled leaf folded into unit_02071DD4
 *   0x02071C14  128 B  * f18/f1c through, BOTH translations through smull
 *                         (EXACT wave 10, 2.0: source fields bound to locals
 *                         before the f30 store, f2c local typed u16)
 *   0x02071DD4  216 B    the s16-only variant
 *   0x02071B2C  232 B  * the full rotate, f22/f20 through ldrsh
 *   0x02071A24  264 B  * the full rotate AND the smull quartet
 *                         (EXACT wave 10: func_02071CDC's body with
 *                         func_02071C14's multipliers; closed by the f34
 *                         bias-first rule below and nothing else)
 *   0x02071CDC  268 B    the smull quartet variant
 *
 * The five biggest all share ONE spelling rule that no smaller one exposes,
 * and it is the single most expensive thing to rediscover in this cluster:
 *
 *   IN THE f34 TERM THE `<< 15` BIAS IS WRITTEN FIRST AND THE SHIFTED
 *   PRODUCT SECOND; IN THE f30 TERM IT IS THE OTHER WAY ROUND.
 *
 *     d->f30 = (s32)(m >> 8) + ((s32)s->f2c << 15);
 *     d->f34 = ((s32)s->f2e << 15) + (s32)(m >> 8);
 *
 *   Spelled the same way in both, the instruction sequence is identical but
 *   the allocator names different registers: 9 bytes out on unit_02071DD4,
 *   7 on func_02071B2C.  unit_02071DD4.c found it; func_02071B2C confirmed
 *   it independently this wave.
 * ================================================================== */

/* The three descriptor marshallers, for contrast: these do NOT build a Mtx,
   they build a stack descriptor and call func_0206DDA4.  Their first word is
   a packed command whose value is selected by flag bit 3:
     func_020713C8  0x00101610 / 0x00101810, 0x13 words, count 0x12
     func_02071858  0x00101710 / 0x00101910, 0x0f words, count 0x0e
   func_02071510 carries no descriptor at all and calls func_0206DDA4 five
   times against the object's own fields.  The command words are the clearest
   evidence that the three are one family with three payload widths. */

#endif /* CLUSTER_02071360_H */
