/*
 * docs/families/pokegra.h -- shared declarations for the pokegra.c family
 * (Pokemon graphics / sprite resource selection), 0x0202D214..0x0202DAA4
 * in the ARM9 image.  Edges are fuzzy by a function or two at both ends.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  It is the adjudicated
 * union of the declarations the family's byte-exact sources already carry,
 * written down once so a new attempt on an open function starts from the
 * settled shape instead of re-deriving it.
 *
 * Derived from the 25 matched sources found with
 *   grep -l "address:  0x0202D[2-9A]" src/matched/*.c
 * Each declaration names the matched function that evidences it.
 */

#ifndef POKEGRA_H
#define POKEGRA_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * THE FAMILY'S DEFINING IDIOM: STACKED ARGUMENTS AS A `volatile struct`
 * PASSED BY VALUE.
 *
 * Several of this family's functions take four register arguments and then
 * a long tail of stacked ones.  The matched set spells that tail NOT as a
 * list of scalar parameters but as ONE struct passed by value and
 * qualified `volatile`:
 *
 *     u32 func_0202D898(u32 a0, u32 a1, u32 a2, u32 a3,
 *                       volatile struct Args args);
 *
 * Both halves are load-bearing and neither is cosmetic:
 *   - BY VALUE, as a struct, is what lays the tail out contiguously in the
 *     caller's outgoing-argument area at the right offsets.  Spelled as
 *     separate scalar parameters the same values land in the same places
 *     but the callee's reads are scheduled differently.
 *   - `volatile` is what stops 1.1p1 caching a field across the calls in
 *     the body: without it the compiler proves the callee cannot write the
 *     incoming copy and keeps one load live, which costs the function.
 *     This is the same mechanism as
 *     docs/idioms/a-global-reread-across-a-call-to-a-visible-static-needs-volatile.md,
 *     applied to a by-value parameter rather than a global.
 *
 * TWO TAIL SHAPES EXIST, and they are different objects; do not merge them:
 * ------------------------------------------------------------------ */

struct Args {                   /* func_0202D898's tail                   */
    u32 w0;
    u32 w1;
    u32 w2;
    u32 w3;
    u16 key;                    /* a heap/resource key, u16 -- it is passed
                                 * on to func_0204AF28's u16 parameter,
                                 * which is what fixes the width          */
    u16 pad;
};

struct Tail {                   /* func_0202D81C's tail                   */
    u32 s0;
    u32 s1;
    u32 s2;
    u32 s3;
    u32 s4;
    u16 key;
    u16 pad;
};

/* ------------------------------------------------------------------ *
 * SPECIES, FORM AND THE SELECTION PATH.
 *
 * func_0202D4A8 is the family's adjudicating file for the scalar types,
 * and its full analysis is in docs/notes/func_0202D4A8.c.txt.  What it
 * settles, and what every other file in the family should follow:
 *
 *   - species is u32, NOT u16.  The three func_02019C90 calls each carry
 *     their own `lsls #0x10; lsrs #0x10` pair, i.e. a (u16) cast written
 *     at the CALL SITE.  Declaring the parameter u16 moves those
 *     truncations into the prologue and costs 60+ bytes.
 *   - form is SIGNED (s32): the bound test is `blt`, not `blo`.
 *   - the sprite index is species * 0x14, so the per-species record in the
 *     graphics NARC is 0x14 bytes / 20 entries.
 *   - the egg index is (species == 0x1EA ? 1 : 0) + 0x28A, scaled by 0x14.
 *     0x1EA = 490 and 0x28A = 650 are plain literals, NOT relocations:
 *     both are out of image range and appear in the pool as constants.
 *
 * VERSION NOTE (docs/AGENT-BRIEF.md section 8).  0x1EA and 0x28A are
 * CONTENT constants -- a species number and a table index -- and are
 * exactly the kind of value that may differ between Black and White.  They
 * are recorded here as Black-image values.  Do not propagate them to a
 * White target without re-deriving them from that image.
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * HELPER PROTOTYPES.  Parameter widths matter: a helper's parameter
 * declared u16 instead of u32 changes the CALLER's masking.  Each spelling
 * below is the one its matched caller compiles against.
 * ------------------------------------------------------------------ */

/* The species/form attribute reader.  Takes the species as u16 -- the cast
 * is written at the call site, see the note above.  `attr` selects which
 * value comes back: 0x1f = first form index, 0x20 = form count,
 * 0x23 = a "has hidden forms" flag (all three from func_0202D4A8). */
extern u32 func_02019C90(u16 species, u32 form, u32 attr);

/* In-family selection and lookup. */
extern u32 func_0202D5D8(u32 id, u32 sel);
extern u32 func_0202D61C(u32 id, u32 sel);
extern u32 func_0202D060(void);
extern u32 func_0202D064(u32 ctx, u32 a1, u32 a2, u32 a3,
                         u32 s0, u32 s1, u32 s2);
extern u32 func_0202D760(void *out, u32 a1, u32 a2, u32 a3,
                         u32 s0, u32 s1, u32 s2, u32 s3, u32 s4);
extern u32 func_0202D81C(u32 a0, u32 a1, u32 a2, u32 a3,
                         volatile struct Tail t);
extern u32 func_0202D898(u32 a0, u32 a1, u32 a2, u32 a3,
                         volatile struct Args args);

/* The 13-parameter resource selector.  Its full parameter mapping is in
 * docs/notes/func_0202D4A8.c.txt; the shape is settled and only a
 * four-byte frame-slot residue keeps it from being filed. */
extern void func_0202D4A8(void *narc, u32 species, s32 form, s32 mode,
                          u32 base, u32 shiny, u32 egg,
                          u32 *out_index, u32 *out_pal, u32 *out_mode,
                          u32 *out_base, u32 **out_ptr, u32 female);

/* Mon accessors, outside the family. */
extern u32 func_02017E88(void *mon, u32 id, u32 v);
extern u32 func_02017EB4(void *mon);

/* NARC / resource layer, ARM. */
extern int   func_020490A8(void *narc, u32 index);
extern void *func_020490F4(u32 mode, u16 key);
extern u32   func_0204AF28(void *h, u32 p, u32 q, u16 key);
extern u32   func_0204A6C8(u32 a0, u32 a1, u32 a2, u32 a3, u32 s0);
extern void  func_0204A9D0(u32 a0, u32 a1);
extern void  func_02049238(void *h);
extern int   ENV_SetResourceSet(int a0, int a1, int a2, int a3, int a4,
                                int a5, int a6);

/* Misc. */
extern u32  func_020275E4(void);
extern u32  func_02027710(u32 x);
extern u32  func_02027714(u32 x);
extern void func_020307B0(void *p);

/* ------------------------------------------------------------------ *
 * GLOBALS
 * ------------------------------------------------------------------ */
extern const u8 sub_0202D5D8_Table[];  /* the selector table func_0202D5D8
                                        * indexes; a rodata run, attested
                                        * as data, never as code          */
extern const char str_020A77AC[];      /* the "pokegra.c" __FILE__ anchor  */

/* ------------------------------------------------------------------ *
 * WAVE 13 (2026-09-23).
 * func_0202D3D0 is EXACT (pkt_0202D2EC).  The lever was the nibble arms:
 * no hoisted byte local; each arm reads `blob[idx]` itself and updates it
 * with a compound `+=` (`n = blob[idx] & 0xf0; if (n >= 0x10 && n <= 0x30)
 * blob[idx] += 0x50;`).  The compiler merges the two identical loads after
 * the `x & 1` test, which is the image's allocation.
 *   extern const u8 *const tile_tables[4];   0x020A779C
 *   extern void func_0202D3D0(struct { u8 pad[0x14]; u8 *blob; } *obj,
 *                             u32 packed_offsets);
 * func_0202D4A8 stays open: a 4-byte frame-slot tie with every lever
 * tried (docs/notes/func_0202D4A8.c.txt), skipped this wave by rule.
 * ------------------------------------------------------------------ */
#endif /* POKEGRA_H */
