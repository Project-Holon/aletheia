/*
 * docs/families/blink_palanm.h -- shared declarations for the blink_palanm.c
 * family (0x0202E940..0x0202EE0C in the ARM9 image).  The family anchor is
 * the __FILE__ pointer at blink_palanm_File (0x020A7804), which
 * src/matched/func_0202E940.c and src/matched/func_0202E9AC.c both pass to
 * the tagged allocator func_02030734 (lines 0x3c, 0x3d, 0x83, 0x84).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration below
 * is derived from a file in src/matched that is EXACT or EXACT*, and the
 * matched function that evidences each field is named in the comment beside
 * it.  Where the matched sources disagree on a spelling (they were written
 * by different lanes), the spelling recorded here is the one the byte
 * evidence actually constrains.
 *
 * NOTE ON EXTENT.  The span holds THREE distinct subsystems:
 *
 *   0x0202E940..0x0202EB0C  the blinking palette-animation context itself
 *     (struct CodeIn below): allocate the 0x1c-byte context and its
 *     halfword buffer, load the two palette rows from an archive, and the
 *     per-frame BGR555 cross-fade (func_0202EA40, still DIFF).  This is the
 *     part the blink_palanm.c anchor actually names.
 *   0x0202EB0C..0x0202ED60  a twenty-entry slot table of 0x28-byte records
 *     (struct Slot below), with its own search, count, insert and compaction
 *     helpers.  It is a separate subsystem that the blink code drives;
 *     func_0202EB9C is its dispatcher.
 *   0x0202ED60..0x0202EE0C+  a small record/surface cluster (func_0202EE30,
 *     func_0202EE8C, func_0202EECC) with its own allocator tags, plus the
 *     two scaled-span arithmetic helpers func_0202EDE4 and func_0202EE0C.
 *
 * Addresses are Black-image addresses throughout.
 */

#ifndef BLINK_PALANM_H
#define BLINK_PALANM_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   short s16;
typedef signed   int   s32;

/* The family's __FILE__ anchor.  func_0202EE30 uses a DIFFERENT anchor,
 * g_020A7814, which is what marks it as a neighbouring original file rather
 * than part of blink_palanm.c proper. */
extern const char blink_palanm_File[];   /* 0x020A7804, func_0202E940 */

/* ================================================================== *
 * PART 1: the blink context, 0x0202E940..0x0202EB0C
 * ================================================================== */

/* The 0x1c-byte context func_0202E940 allocates.  +0x00 and +0x04 are the
 * two palette rows func_0202E9AC fills from an archive; they are `void *`
 * there and `u32` in func_0202E940, which only stores them, so the pointer
 * spelling is the constrained one.  The 0x1c size is not a sizeof in the
 * original: func_0202E940 materialises it as the allocator's size argument
 * directly. */
struct CodeIn {
    void *w00;   /* +0x00  func_0202E9AC: row A, h0e*2 bytes from the heap */
    void *w04;   /* +0x04  func_0202E9AC: row B, same size */
    void *buf;   /* +0x08  func_0202E940: h0e*2 bytes, the output row */
    u16   h0c;   /* +0x0c  func_0202E940: first ctor argument */
    u16   h0e;   /* +0x0e  func_0202E940: the row length in HALFWORDS; every
                  *        allocation and copy in the family scales it by 2 */
    u16   h10;   /* +0x10  func_0202E940: zeroed; the phase word the fade
                  *        advances (func_0202EA40 reads it at +0x10) */
    u16   h12;   /* +0x12  func_0202E940: zeroed */
    u32   w14;   /* +0x14  func_0202E940: the mode mask, one of
                  *        0xe / 0x1e / 0xf / 0x1f; func_0202EA40 passes it
                  *        as the first argument of its tail call */
    u16   h18;   /* +0x18  func_0202E940: the heap id, kept for the later
                  *        allocations in func_0202E9AC */
};

/* Allocate the context and its output row.  The mode chain must write w14 in
 * EVERY arm, not into a local read once at the end
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md). */
extern struct CodeIn *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap);

/* Allocate the two palette rows and fill them from an archive entry.  The
 * archive handle's +0x0c is the base the two source offsets index, each
 * pre-scaled by 2 (halfword offsets, like the rest of the family). */
extern void func_0202E9AC(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);

/* The per-frame BGR555 cross-fade.  EXACT* since wave 13
 * (src/matched/func_0202EA40.c): the pixels are `u16` locals and the pack
 * is `(r << 10) | (bl | (g << 5))`, the operand ORed last being the one
 * evaluated first.  EXACT* only because the leaf below follows it unlabelled. */
extern void func_0202EA40(void *p);

/* Reset the fade phase: `p->h10 = 0;`.  An unlabelled six-byte leaf after
 * func_0202EA40's pool word (src/matched/func_0202EB04.c, EXACT, wave 13);
 * the listing folds it into func_0202EA40's extent (204 against 196). */
extern void func_0202EB04(struct CodeIn *p);

/* Free the context: three buffers then the context itself, in the order
 * +0x04, +0x00, +0x08, which is what pins the free order as written. */
extern void sub_0202EA20(void *p);

/* ================================================================== *
 * PART 2: the slot table, 0x0202EB0C..0x0202ED60
 * ================================================================== */

/* One table entry, 0x28 bytes, twenty of them.  The 0x28 stride is evidenced
 * by the `movs r0,#0x28 / muls` scaling in func_0202EC24, func_0202EC44,
 * func_0202EC7C, func_0202ECB0, func_0202ED00 and func_0202EB9C alike.
 *
 * The flag byte at +0x26 carries TWO one-bit fields, and which one a given
 * function reads is visible in the shift amount of its `lsls/lsrs` pair:
 *   `lsls #0x1c / lsrs #0x1f`  ->  bit 3, `mark`
 *   `lsls #0x1b / lsrs #0x1f`  ->  bit 4, `flag`
 * func_0202ED90 is the one matched function that writes BOTH, and is
 * therefore the file that fixes their relative positions.  Reading the tell
 * wrong is a silent two-byte diff, not a compile error: it is what
 * func_0202EB9C came out wrong on before the shift was checked.
 *
 * The 4-byte alignment is load-bearing for func_0202ED00's aggregate copy:
 * with only u8 members the front end lowers `p[0] = p[1]` to a 0x28-iteration
 * ldrb/strb loop instead of five ldm/stm pairs. */
struct Slot {
    u8  pad[0x26];
    u8       : 3;
    u8  mark : 1;   /* +0x26 bit 3  func_0202ED90 writes it from its `c` arg */
    u8  flag : 1;   /* +0x26 bit 4  the occupancy bit every scan breaks on */
    u8       : 3;
    u8  pad2;       /* +0x27 */
};

/* The ten-word payload func_0202ED90 copies into a free slot.  It is exactly
 * 0x28 bytes and copies as one aggregate assignment. */
struct SlotBody { u32 w[10]; };

/* Count the occupied prefix: the index of the first entry whose `flag` is
 * clear, or 20.  The loop must break rather than return, which is what
 * leaves `i` live for the shared return. */
extern u32 sub_0202EC24(const struct Slot *p);

/* How many of the occupied entries carry the same key as `a1`, capped at 5.
 * The return is compared UNSIGNED at its one call site (func_0202EB9C's
 * `bhs`), which is what makes the declared return type u32 there even though
 * the definition in src/matched spells it s32. */
extern u32 func_0202EC44(struct Slot *a0, u32 a1);

/* The index of the first occupied entry whose key is `a1`, or 20. */
extern u32 func_0202EC7C(struct Slot *a0, u32 a1);

/* The index of the first occupied entry matching `b` on BOTH keys
 * (func_02008530 and func_0200856C), or 20.  The two queries on `b` are
 * hoisted out of the loop; the two on each entry are not, and the second is
 * only reached when the first matches. */
extern s32 func_0202ECB0(struct Slot *a0, void *b);

/* Remove entry `n`: shift the tail down by one 0x28-byte record until a
 * cleared `mark` is met, then clear `mark` on every remaining entry.  STILL
 * DIFF at six bytes; see docs/notes/pkt_0202ED00.c.txt. */
extern void func_0202ED00(struct Slot *t, u32 n);

/* The table dispatcher: look `b` up, and either remove and re-notify, or
 * insert by key with the count-capped policy.  STILL DIFF; see
 * docs/notes/pkt_0202EB9C.c.txt.  Size-exact only under ../2.0/sp2 (1.1p1
 * cross-jumps the insert arm's two func_0202ED00 calls, the image keeps
 * them apart); 15 out there, a register rotation plus one unthreaded jump. */
extern u32 func_0202EB9C(u32 a, void *b);

/* The guarded entry point: nothing happens for a `b` whose key is zero.
 * Its declaration of func_0202EB9C's second parameter as u32 is what the
 * `void *` above is reconciled against; only the pointer use is constrained. */
extern u32 func_0202EB7C(u32 a0, u32 a1);

/* Notify: hand the table and the record to func_0202ED90, then poll. */
extern void func_0202ED60(u32 a, void *b, u32 c);

/* Insert `b` into the first free slot of `a`, setting `mark` from `c` and
 * `flag` unconditionally; a full table is a no-op. */
extern void func_0202ED90(u8 *a, struct Slot *b, u32 c);

/* ================================================================== *
 * PART 3: the record cluster and the span helpers, 0x0202ED60 onward
 * ================================================================== */

/* Two scaled-span helpers, both dividing with the UNSIGNED runtime entry.
 * The image's call target is 0x0209C2B0, which layout/runtime_arm9.txt names
 * `_div_by_zero_check`; the code there is the unsigned divide entry itself,
 * and `signed / signed` would emit 0x0209C0A4 instead.  Declare it under the
 * front end's own name, `_u32_div_f`, kind `arm`. */
extern u32 _u32_div_f(u32 n, u32 d);   /* 0x0209C2B0, runtime */

/* Clamp-and-scale: 0 below the low edge, a0 above the high edge, and a
 * proportional value between.  Both edges are derived from a4 >> 1. */
extern u32 func_0202EDE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);

/* The inverse: scale the span (a3 - a2 - a4) by a1/a0 and fold it onto a2
 * and a4 >> 1.  Two spellings are load-bearing and neither is reachable by
 * hand reasoning; see src/matched/func_0202EE0C.c for both. */
extern u32 func_0202EE0C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);

/* The 0x1c-byte record.  Only the four words the two constructors write are
 * named; func_0202EECC fills the rest. */
struct Rec1C {
    u32 w00;     /* +0x00  the owner handle, or 0 */
    u32 w04;     /* +0x04  the allocation cookie, or 0 */
    u32 w08;     /* +0x08  func_0202EECC: the surface */
    u32 w0c;     /* +0x0c  func_0202EECC: func_0204384C's result */
    u16 h10;     /* +0x10  func_0202EECC: the caller's a4 */
    u8  b12;     /* +0x12  func_0202EECC: a2 */
    u8  b13;     /* +0x13  func_0202EECC: zeroed */
    u8  b14;     /* +0x14  func_0202EECC: a3 */
    u8  b15;     /* +0x15  func_0202EECC: func_020056EC(8) */
    u8  pad16[2];
    u32 w18;     /* +0x18  both constructors store 1 */
};

/* The two constructors differ only in where the block comes from: the heap
 * (func_0202EE30, anchored on g_020A7814, NOT the blink_palanm anchor) or a
 * pool (func_0202EE8C).  Both then call func_0202EECC and set the same three
 * words.  func_0202EE30's heap parameter must be `volatile u16` or the
 * re-read of it for the func_0202EECC call folds away. */
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3,
                         volatile u16 heap);
extern u8 *func_0202EE8C(u32 a, void *b, u8 c, u8 d, u16 e);

/* Fill a freshly allocated record: the id, then a surface built from six
 * size queries on a1 (width and height are each the sum of two of them minus
 * two, truncated to a byte). */
extern void func_0202EECC(u8 *p, void *a1, u8 a2, u8 a3, u16 a4);

#endif /* BLINK_PALANM_H */
