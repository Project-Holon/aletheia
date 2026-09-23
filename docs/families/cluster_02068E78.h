/*
 * docs/families/cluster_02068E78.h -- shared declarations for the pseudo-family
 * at 0x02068E78..0x02069078 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so this cluster is NOT a recovered original translation
 * unit; it was formed by address adjacency plus shared callees and data
 * objects.  It is the TEXT / TILE DRAW-CONTEXT layer:
 *
 *   func_02068E78  the raw initialiser -- eight arguments into six fields of
 *                  a 0x18-byte draw context, no computation at all
 *   func_02068EA0  draw one glyph: range-table lookup, default-glyph fallback,
 *                  bearing adjustment by layout kind, then the context's hook
 *   func_02068FC4  a fixed-configuration wrapper over func_02068E78
 *   func_02068FF0  a size-driven wrapper over func_02068E78: derive a tile
 *                  size code per dimension and look the configuration byte
 *                  pair up in g_020A18F4
 *
 * Derived from src/matched/func_02068E78.c, src/matched/func_02068EA0.c and
 * src/matched/func_02068FC4.c, and from docs/notes/pkt_02068FF0.c.txt (whose
 * 2026-09-22 appendix corrects three earlier claims and is the current
 * reading of func_02068FF0).
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrsb`/`ldrsh` prove signedness; a shift pair of
 * unequal amounts proves a bitfield's width and position; a plain `ldr`
 * followed by a shift pair proves the FIELD is 32-bit and the narrowing happens
 * at the use.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * Measured, per row:
 *
 *   func_02068E78   ../2.0/sp2 and ../1.2/sp2 both byte-exact; 1.1p1 is NOT
 *   func_02068EA0   ../2.0/sp2, and ONLY 2.0 -- a real pin with its own row
 *   func_02068FC4   dsi/1.1p1
 *
 * So the cluster is mixed and the pin must be read off the residue, never
 * assumed from the neighbour.
 *
 * func_02068EA0's pin is the re-read form of the "kept constants" family
 * (docs/FRONTEND-PINS.md, the func_02070BD8 row): the image RE-READS the
 * font's header chain a second time before the switch dispatch, and 1.1p1
 * forwards the register it still has live and collapses the pair, giving 284
 * bytes against the image's 292.  A volatile qualifier, struct-typed field
 * chains, and a chain spelled out in every switch arm all CSE identically.
 *
 * func_02068E78's tell is different and is the one to recognise here: A LEAF
 * THAT GROWS A PROLOGUE.  The image never pushes and returns with a bare
 * `bx lr`; 1.1p1 spends `r4` and `lr` on the three stack arguments, opens
 * `push {r4, lr}`, returns through `pop {r4, pc}`, shifts every stack-argument
 * displacement by 8, and fuses two of the stores into an `stm`.  Nine of ten
 * instructions differ.  Two front ends reproduce the image here, so the row is
 * not evidence for either pin on its own and is not offered as one in
 * docs/FRONTEND-PINS.md.
 *
 * ============================================================================
 * THE WALL: `clz` IS NOT REACHABLE FROM THIS PROJECT'S C.
 * ============================================================================
 *
 * func_02068FF0 opens with two copies of
 *
 *     cmp rX, #8 / movlt r4, rX / movge rY, #3 / clzlt r4, r4
 *     rsblt rY, r4, #0x1f
 *
 * i.e. `(v < 8) ? 31 - clz(v) : 3`, the log2 of a tile dimension saturated at
 * 3.  There is no way to make mwccarm emit `clz`.  Verified this pass:
 * `strings mwccarm.exe | grep -i clz` finds only the assembler mnemonic;
 * the binary carries no bit intrinsics at all (its `__builtin_*` list is
 * align/type/constant_p/expect and the C++ trait queries).  `__cntlz`,
 * `__clz`, `__CLZ32` and `__builtin_clz` all compile -- as implicit function
 * declarations, i.e. as an unresolvable `bl`, which is what made an earlier
 * pass believe `__cntlz` was real.  Five shift-loop spellings and the
 * canonical five-step binary search were all compiled at -O4,p and none was
 * peepholed to `clz`; the binary search comes out as its five literal
 * `cmp`/`lsrhs`/`addhs` steps.
 *
 * THE SAME WALL HOLDS THREE FUNCTIONS, and they should be closed together or
 * not at all: func_02068FF0 here, func_02068204 in
 * docs/notes/pkt_02067FE4.c.txt (which recomputes the SAME two shift amounts
 * with the SAME `cmp #8` guard against the SAME table g_020A18F4), and the two
 * int-to-double conversions in
 * docs/notes/pkt_0209AF34_soft_float_library.c.txt.  Do not spend another pass
 * looking for a spelling.
 *
 * ISA: ARM throughout.  This is unusual for game code (the ARM9 static module
 * is Thumb almost everywhere) and is itself a cluster property worth knowing:
 * always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_02068E78_H
#define CLUSTER_02068E78_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;

/* ================================================================== *
 * 1.  struct Pen -- the 0x18-byte draw context func_02068E78 fills
 *
 * The store ORDER in func_02068E78 is the source order and is deliberately
 * not the field order (+0x04, +0x08, +0x0c, +0x00, +0x14, +0x10): this
 * compiler never reorders independent stores to one object, so the image's
 * order IS the original statement order.  Writing the fields ascending lets
 * the front end fuse the first two into `stm r0, {r1, r2}` and changes shape.
 * ================================================================== */
struct Pen {
    int f00;                    /* 0x00  written FOURTH                      */
    int f04;                    /* 0x04  written FIRST                       */
    int f08;                    /* 0x08  written SECOND                      */
    u8  f0c;                    /* 0x0c  written THIRD, `strb` from an int   */
    u8  pad0d[3];
    int f10;                    /* 0x10  written SIXTH                       */
    int f14;                    /* 0x14  written FIFTH                       */
};

/* ================================================================== *
 * 2.  The font objects func_02068EA0 walks
 *
 * `Hdr.stride` is the glyph record stride; `Hdr.kind` is the layout code the
 * bearing switch dispatches on (0/7, 1/2, 3/4, 5/6 -- four arms over eight
 * values).  `Fnt2.dflt` is the fallback glyph index used when the range-table
 * lookup returns its 0xFFFF sentinel (the pool word at 0x02068FC0).
 * `Ctx.vt[0]` is the draw hook, invoked with six arguments, the last being
 * the two-pointer `out` array built on the stack.
 * ================================================================== */
struct Hdr  { u16 f0; u16 stride; u8 pad[3]; u8 kind; };
struct Fnt  { struct Hdr *hdr; };
struct Fnt2 { u16 f0; u16 dflt; u8 p[4]; struct Hdr *hdr; };
struct Ctx  { u8 pad[0x14]; void **vt; };

#define FONT_NOT_FOUND  0xFFFF  /* the pool word at 0x02068FC0               */

/* ================================================================== *
 * 3.  The configuration table g_020A18F4
 *
 * An 8-BYTE-ROW TABLE OF BYTE PAIRS, indexed [j][i] where i and j are the
 * saturated log2 of the two tile dimensions: the element is
 * g_020A18F4[j * 8 + i * 2] and its successor.  Two independent readings
 * agree on this shape -- func_02068FF0 here and func_02068204 in
 * docs/notes/pkt_02067FE4.c.txt ("an 8 x N table of PAIRS", row stride 8).
 *
 * g_020A18DC and g_020A18E8 are two further objects in the same rodata run,
 * passed straight through as func_02068E78's SIXTH argument:
 * func_02068FC4 passes 0x020A18DC, func_02068FF0 passes 0x020A18E8.
 * ================================================================== */
extern const u8 g_020A18DC[];   /* 0x020A18DC  func_02068FC4's config        */
extern const u8 g_020A18E8[];   /* 0x020A18E8  func_02068FF0's config        */
extern const u8 g_020A18F4[];   /* 0x020A18F4  8-byte rows of byte pairs     */

/* ================================================================== *
 * 4.  Prototypes, with the parameter types the matched sources fixed
 * ================================================================== */

/* EIGHT arguments, not seven.  func_02068E78's own body only reads the stack
   words at [sp+0], [sp+4] and [sp+8], so the eighth is dead in the callee and
   is invisible from that side -- but func_02068FF0 stores the same packed word
   into BOTH [sp+8] and [sp+0xc] before its `bl` (0x02069060 and 0x0206905C),
   which is what fixes the arity.  Declaring only seven leaves that caller's
   frame `sub sp, sp, #0xc` where the image has #0x10 and costs it a pushed
   register.  See the 2026-09-22 appendix of docs/notes/pkt_02068FF0.c.txt. */
extern void func_02068E78(void *p, int a1, int a2, int a3, int a5,
                          const void *a6, u32 a7, u32 a8);

extern s8   func_02068EA0(struct Ctx *ctx, struct Fnt2 **font, int x, int y,
                          int a6, u16 code);
extern void func_02068FC4(int a, int b, int c, int d, int e);
extern void func_02068FF0(void *p, int a1, int w, int h, int a5);

/* --- func_02068EA0's two callees ---------------------------------------- */
extern u32  func_02067F9C(void *font, u32 code);   /* 0x02067F9C  lookup     */
extern s8  *func_02067FE4(void *font, u32 idx);    /* 0x02067FE4  glyph      */

/* ================================================================== *
 * 5.  Constants
 * ================================================================== */
#define TILECFG_ROW_STRIDE   8      /* g_020A18F4 row stride, in bytes       */
#define TILECFG_MAX_CODE     3      /* the `cmp #8` / `movge #3` saturation  */

#endif /* CLUSTER_02068E78_H */

/* CORRECTION 2026-09-23 (wave 13).  The clz wall is gone (the SDK's inline
 * asm MATH_CountLeadingZeros; see docs/notes/pkt_02067FE4.c.txt) and
 * func_02068FF0 is EXACT under ../2.0/sp2.  func_02068E78 takes SEVEN
 * arguments, not eight: the seventh is a 4-byte bitfield struct passed BY
 * VALUE whose own home is [sp, #0xc], which is why the caller stores the same
 * register to [sp, #8] and [sp, #0xc].  The cluster is NitroSystem
 * g2d_CharCanvas.c.  See src/matched/func_02068FF0.c. */
