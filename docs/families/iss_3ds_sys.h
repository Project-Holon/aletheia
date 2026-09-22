/*
 * docs/families/iss_3ds_sys.h -- shared declarations for the iss_3ds_sys.c
 * family, 0x0202B894..0x0202BE54 in the ARM9 image.  Edges are fuzzy by a
 * function or two at both ends.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  It is the adjudicated
 * union of the declarations the family's byte-exact sources already carry,
 * written down once so a new attempt on an open function starts from the
 * settled shape instead of re-deriving it.
 *
 * Derived from the 21 matched sources found with
 *   grep -l "address:  0x0202B[89A-E]" src/matched/*.c
 * Each declaration names the matched function that evidences it.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load instruction constrains a field
 * and a name does not.  A `muls` by a constant fixes an array stride; a
 * `movs #N; lsls #2` pair fixes a far array's base offset exactly.
 */

#ifndef ISS_3DS_SYS_H
#define ISS_3DS_SYS_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * THE FAMILY OBJECT.  Every function in the family takes it as its first
 * parameter, and the matched set spells it as a flat `u8 *o` with explicit
 * offsets rather than as a struct.  That spelling is kept here because it
 * is what the byte-exact files use; the offsets below are the adjudicated
 * union of what they actually touch.
 *
 * THE THREE ARRAYS ARE FIXED BY ARITHMETIC, NOT BY GUESSWORK:
 *
 *   entries[]  base +0x24, stride 0x1c, 0x10 of them
 *              stride from `movs r0,#0x1c; muls r1,r0,r1` in func_0202BB68,
 *              func_0202BBB0 and func_0202BAF4; base from the `adds r2,#0x24`
 *              that precedes every indexed load; the count 0x10 from
 *              func_0202BAF4's loop bound.
 *              0x24 + 0x10 * 0x1c = 0x1e4, which is EXACTLY where the next
 *              array starts -- the two abut with no padding, and that
 *              closure is the strongest evidence the layout is right.
 *
 *   a_1e4[]    base +0x1e4, stride 4, s32
 *              base materialised as `movs r0,#0x79; lsls r0,#2` (0x79*4)
 *              in func_0202BB68, indexed `o + i * 4`.
 *
 *   a_224[]    base +0x224, stride 4, s32
 *              base materialised as `movs r0,#0x89; lsls r0,#2` (0x89*4)
 *              in func_0202BBB0, indexed the same way.
 *              0x1e4 + 0x10 * 4 = 0x224: the two parallel arrays abut too,
 *              so both are 0x10 entries, one per entries[] slot.
 *
 * The far field at +0x264 that several matched files reach is then
 * 0x224 + 0x10 * 4 = 0x264, immediately after a_224[] -- consistent, and
 * the reason a pool word is needed to reach it
 * (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md).
 * ------------------------------------------------------------------ */

/*
 *   +0x04   u32   an "armed"/"running" flag.  func_0202BABC returns early
 *                 when it is NON-zero and then sets it to 1;
 *                 func_0202BAF4 returns early when it is ZERO.  The two
 *                 polarities are not a contradiction: BABC is the arm and
 *                 BAF4 is the per-frame step, so each guards on the state
 *                 the other establishes.  Getting this polarity backwards
 *                 is a whole-function diff
 *                 (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *   +0x0c   .     a sub-object passed BY ADDRESS (`o + 0xc`) to the
 *                 comparators func_0202BBFC and func_0202BCA0.
 *   +0x18   .     a second sub-object passed by address (`o + 0x18`), and
 *                 ONLY func_0202BCA0 takes it -- this is what makes
 *                 func_0202BCA0 a 3-argument function where the otherwise
 *                 identical func_0202BBFC takes 2.  See
 *                 docs/notes/pkt_0202BB68.c.txt.
 *   +0x10, +0x14, +0x1c, +0x20   u32, read by several matched files; no
 *                 matched reader constrains them beyond u32.
 *   +0x24   entries[0x10], stride 0x1c.  Word 0 of each entry is a
 *                 liveness flag: every consumer tests it against zero and
 *                 skips the entry when it is zero.
 *   +0x1e4  s32 a_1e4[0x10]      see above
 *   +0x224  s32 a_224[0x10]      see above
 *   +0x264  u32                  the far field; reached via a pool word
 */

/* ------------------------------------------------------------------ *
 * THE PER-FRAME STEP, and the shape of the family's inner loop.
 *
 * func_0202BAF4 is the driver: for each of the 0x10 entries whose first
 * word is non-zero it calls FOUR in-family functions in this fixed order,
 * each taking (o, i):
 *
 *     func_0202BB68(o, i);      compares against a_1e4[i]
 *     func_0202BBB0(o, i);      compares against a_224[i]
 *     func_0202BC78(o, i);
 *     func_0202BE00(o, i);
 *
 * func_0202BB68 and func_0202BBB0 are STRUCTURAL TWINS -- same guard, same
 * comparator call, same two-armed signed dispatch -- differing only in
 * which parallel array they read and in their comparator's arity.  Work
 * them as a pair; docs/notes/pkt_0202BB68.c.txt has the full write-up and
 * the one four-byte residue they share.
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * HELPER PROTOTYPES.  Parameter widths matter: a helper's parameter
 * declared u8 instead of int changes the CALLER's masking.  Each spelling
 * below is the one its matched caller compiles against.
 * ------------------------------------------------------------------ */

/* The two comparators.  Both return a SIGNED value: their results feed
 * `bge` against an s32 array element in both twins.  The arity difference
 * is real and load-bearing -- see the +0x18 note above. */
extern s32  func_0202BBFC(void *entry, void *sub_0c);
extern s32  func_0202BCA0(void *entry, void *sub_0c, void *sub_18);

/* The four dispatch targets of the twins, two per twin, selected on the
 * sign of (comparator result - array element). */
extern void func_0202BC48(u8 *o, int i);   /* 0202BB68, array value < v */
extern void sub_0202BC60(u8 *o, int i);    /* 0202BB68, v < array value */
extern void sub_0202BDD0(u8 *o, int i);    /* 0202BBB0 */
extern void sub_0202BDE8(u8 *o, int i);    /* 0202BBB0 */

/* The rest of the per-frame chain. */
extern void sub_0202BE24(u8 *o);           /* func_0202BAF4 calls it once,
                                            * before the entry loop        */
extern void func_0202BC78(u8 *o, int i);
extern void func_0202BE00(u8 *o, int i);
extern void func_0202BAF4(u8 *o);          /* the per-frame step            */
extern void func_0202BABC(u8 *o);          /* the arm                       */
extern void func_0202BB48(u8 *o);
extern void func_0202B944(u8 *o);
extern void func_0202B958(u8 *o);
extern void func_0202B9C8(u8 *o);
extern void func_0202B9E0(void *o, u32 v);
extern u32  func_0202B9F0(void *o, u32 v);
extern u32  func_0202B810(void);
extern void func_0202BA24(u8 *o);
extern void func_0202BEEC(u8 *o, u32 heapId);
extern void func_0202BF90(u8 *o, u32 key);
extern void func_0202BFF0(u8 *o);

/* Outside the family. */
extern u32   func_02005C44(u32 v);
extern u32   func_020127A4(u32 v);
extern u32   func_0201295C(u32 v);
extern void  func_02012AC8(u32 v);
extern void *func_02030734(u32 heapId, u32 size, u32 zero, const char *file,
                           u16 line);
extern void  func_020307B0(void *p);

/* The g3d/geometry helpers this family leans on.  struct Vec is the SDK's
 * fixed-point 3-vector; it is declared here only so the prototypes are
 * readable, and its layout belongs to the SDK, not to this family. */
struct Vec;
extern void VEC_Subtract(const struct Vec *a, const struct Vec *b,
                         struct Vec *out);
extern void VEC_CrossProduct(const struct Vec *a, const struct Vec *b,
                             struct Vec *out);
extern void VEC_Normalize(const struct Vec *v, struct Vec *out);
extern s32  VEC_DotProduct(const struct Vec *a, const struct Vec *b);
extern s32  VEC_Mag(const struct Vec *v);
extern s32  sub_0207C768(s32 num, s32 den);

#endif /* ISS_3DS_SYS_H */
