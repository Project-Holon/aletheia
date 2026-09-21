/*
 * docs/families/wordset.h -- shared declarations for the wordset.c family
 * (message word substitution), 0x0201EC64..0x0201F7A8 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the family's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled
 * shape instead of re-deriving it.
 *
 * Derived from the matched sources found with
 *   grep -l "address:  0x0201E[C-F]\|address:  0x0201F[0-7]" src/matched/*.c
 * Each declaration names the matched function that evidences it.
 *
 * ADJUDICATION RULE.  A load or a store instruction constrains a field; a
 * name does not.  A `lsls`/`lsrs` pair of equal width proves a bitfield's
 * width; an unequal pair is a narrowing cast folded with a shift.  Where two
 * matched files spell the same object differently, the file whose code
 * actually constrains it wins.
 *
 * FILE IDENTITY.  The constructor func_0201EC74 passes 0x020A7364 to the
 * debug allocator, and the bytes there spell "wordset.c".  The string before
 * it is "gf_font.c", whose terminator at 0x020A7360 plus three bytes of
 * padding fixes 0x020A7364 by construction, so the `string` class carries the
 * address.  Evidenced by src/matched/unit_0201EC64.c and
 * src/matched/func_0201EC74.c.
 *
 * ------------------------------------------------------------------------
 * THE ONE BIG IDEA: A TABLE OF SUBSTITUTION SLOTS, ONE SETTER PER MESSAGE ID
 * ------------------------------------------------------------------------
 * The object is `struct WordSet`: a count, a heap id, an array of `count`
 * 12-byte `Entry` records, and one scratch string.  Each Entry is a five-byte
 * `Tag` plus a pointer to the slot's own rendered string.
 *
 * Roughly thirty of the family's functions are the SAME THREE-LINE SHAPE:
 * range-check or clamp the caller's value, then render one message id into
 * the slot through func_0201EDD0(p, i, <id>, v).  The ids are plain integers,
 * not relocations -- the ones above 255 (0x116, 0x117, 0x118, 0x119, 0x11B,
 * 0x1CD) arrive from the function's own literal pool only because Thumb's
 * `movs` immediate stops at 255, which is the NEGATIVE case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 * Evidenced by src/matched/unit_0201ED04.c, unit_0201F020.c, unit_0201F0F8.c.
 *
 * A new setter in this family is almost certainly one of:
 *     void f(struct WordSet *p, u32 i, u32 v) { func_0201EDD0(p, i, ID, v); }
 *     ... with a leading `if (v > K) { func_0201ED64(p, i); return; }`
 *     ... or a leading clamp, `if (v >= K) v = 0;`
 * and the clamp's signedness is the only thing to read off the bytes: a
 * signed `blt` means the value parameter is `s32` (func_0201F184), an
 * unsigned `bls`/`bhi` means `u32` (every other clamp in the file).
 */

#ifndef WORDSET_H
#define WORDSET_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed char        s8;
typedef signed short       s16;
typedef signed int         s32;

/* ===================================================================== *
 * Externs used across the family
 * ===================================================================== */

/* debug allocator: (heap, size, flag, __FILE__, __LINE__) -- func_0201EC74 */
extern void *func_02030734(u32 heap, u32 size, u32 flag, const char *file,
                           u32 line);
/* heap free -- func_0201ED04 */
extern void  func_020307B0(void *p);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);

/* The string object (gf_font.c / printsys.c side).  NOTE THE ISA COLUMN:
 * func_020457B0 and func_02045A90 are ARM, not Thumb -- the harness refuses
 * the call otherwise, and getting it wrong is a silent whole-function diff.
 * func_0201EC74 and sub_0201F4A0 are the witnesses. */
extern void *func_020457B0(u32 size, u32 heap);          /* 0x020457B0 arm  */
extern void  func_02045808(void *s);                     /* destroy         */
extern void  func_0204581C(void *s);                     /* clear           */
extern void  func_02045838(void *dst, const void *src);  /* copy            */
extern u32   func_020458F8(void *s);                     /* length          */
extern u16  *func_02045A90(void *s);                     /* 0x02045A90 arm  */
extern u16   func_02045A98(void);                        /* the terminator  */
extern void  func_02045AA8(void *dst, void *src);
extern void  func_02045AFC(void *s, u16 c);              /* append one glyph */
extern void *func_02045B38(u32 a, u32 b, u16 id, u16 heap);  /* load message */
extern void  func_02045C04(void *s);                     /* release message  */
extern void  func_02045CAC(void *s, u32 v, void *buf);   /* render into buf  */
extern u32   func_02045F50(void *s);                     /* message count    */

/* the mwccarm integer-division helper -- func_0201F35C
 * (docs/idioms/runtime-helper-reloc.md) */
extern u32   _u32_div_f(u32 a, u32 b);                   /* 0x0209C2B0 arm  */

/* species-keyed name getters -- unit_0201ED04.c.  Nothing in this family
 * reads a version flag or an exclusive-species table directly, but any
 * renaming of these two should be checked against Pokemon White. */
extern u32   func_02017E1C(void *mon, u32 id, void *v);
extern u32   func_02017E88(void *mon, u32 id, void *v);

/* the file-scope template string, 0x020A7370.  Exactly two literal pools in
 * the image hold that address (func_0201EE60's and func_0201F344's), so each
 * file is the other's `literal` witness and the two may NOT be merged into
 * one compared range.  unit_0201ED04.c, unit_0201F31C.c. */
extern void *unk_020A7370;                               /* 0x020A7370 data */

/* the "wordset.c" __FILE__ anchor -- func_0201EC74 */
extern char sFile_020A7364[];                            /* 0x020A7364 data a1 */

/* ===================================================================== *
 * THE OBJECT
 * ===================================================================== */

/* The five-byte tag.  The byte at +3 is TWO BITFIELDS, a seven-bit value and
 * a one-bit flag: that is what the `ldrb`/`bics #0x7F`/`orrs` and
 * `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in func_0201EE0C are.  Writing that
 * byte as a plain u8 with masks costs a pool word and an `ands` for each of
 * the two fields.  Evidenced by unit_0201ED04.c (func_0201EE0C). */
struct Tag {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03  : 7;
    u8 unk03b : 1;
    u8 unk04;            /* the one-byte flag sub_0201EFFC writes */
};

struct Entry {           /* 12 bytes; stride 0xc is in the image at
                          * func_0201EC74's `muls r1, r7, #0xc` */
    struct Tag tag;
    void *str;
};

struct WordSet {
    u32 count;                   /* +0x0 */
    u32 heap;                    /* +0x4 */
    struct Entry *entries;       /* +0x8 */
    void *buf;                   /* +0xc, the shared render scratch */
};

/* Several matched files spell the tag as a bare `u8 tag[5]` instead
 * (unit_0201F020.c, unit_0201F0F8.c, unit_0201F31C.c).  Both reach EXACT:
 * those files never touch the bitfields, so the spelling is free THERE.  Use
 * `struct Tag` in anything that writes +3. */

/* ===================================================================== *
 * Lifecycle
 * ===================================================================== */

struct WordSet *func_0201EC64(u32 heap);             /* defaults: 8, 0x20 */
struct WordSet *func_0201EC74(u32 n, u32 size, u8 heap);
void            func_0201ED04(struct WordSet *p);    /* destroy           */
void            func_0201F31C(struct WordSet *p);    /* clear every slot  */
void            func_0201F344(u16 heap);             /* fill unk_020A7370 */

/* func_0201EC74's THIRD PARAMETER IS u8.  It is spilled untruncated and read
 * back as a word for `p->heap = heap`, so nothing that runs depends on the
 * width -- but it changes the order mwccarm's value numbering creates the
 * three incoming values in, and the prologue schedule follows that order.
 * u32 there is fourteen wrong bytes.  func_0201F344's heap is u16 for the
 * same class of reason (the 4th argument of func_02045B38 is u16 and the
 * original passes the register straight through with no truncation pair).
 *
 * func_0201EC74's failure path is a `goto fail;` chain with ONE `return 0;`
 * at the end: every failure return in the image lands on the single epilogue
 * at 0x0201ECFA, and four separate `return 0;` statements make the compiler
 * materialise the epilogue inline at the FIRST failure site instead.  See
 * docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md
 * and the RESOLVED section of docs/notes/pkt_0201EC74.c.txt. */

/* ===================================================================== *
 * The slot primitives -- unit_0201ED04.c, the body of the file
 * ===================================================================== */

/* func_0201ED50 takes a `struct Tag *`, NOT a `struct Entry *`: func_0201EE0C
 * calls it on a bare stack local, which is what fixes the parameter type.
 * The two are the same address for an entry, so the distinction is only
 * visible at that one call site. */
void func_0201ED50(struct Tag *t);                   /* clear a tag        */
void func_0201ED64(struct WordSet *p, u32 i);        /* clear a slot       */
void func_0201ED84(struct WordSet *p, u32 i, const void *src,
                   const struct Tag *tag);           /* THE COMMON TAIL    */
void func_0201EDD0(struct WordSet *p, u32 i, u32 id, u32 v);  /* render     */
void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f);
void func_0201EE60(struct WordSet *p, u32 i, u16 v);
void func_0201EFFC(struct WordSet *p, u32 i, u32 v);

/* Every setter in the file ends the same way, by handing a rendered string to
 * func_0201ED84, which copies the caller's five-byte Tag into the slot (or
 * clears it when the caller passes NULL) and then copies the string itself. */

/* ===================================================================== *
 * The setters.  All take (struct WordSet *p, u32 i, ...).
 * ===================================================================== */

void func_0201EE84(struct WordSet *p, u32 i, void *mon);
void func_0201EEA4(struct WordSet *p, u32 i, void *mon);
void func_0201EEC4(struct WordSet *p, u32 i, u32 v);       /* id 0x119 */
void func_0201EED4(struct WordSet *p, u32 i, void *mon);
void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
void func_0201EF14(struct WordSet *p, u32 i, void *mon);
void func_0201EF34(struct WordSet *p, u32 i, u32 v);       /* id 0xCB  */
void func_0201EF40(struct WordSet *p, u32 i, u32 v);       /* id 0x36  */
void func_0201EF4C(struct WordSet *p, u32 i, u32 v);       /* id 0x117 */
void func_0201EF5C(struct WordSet *p, u32 i, u32 v);       /* id 0x118 */
void func_0201EF6C(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
void func_0201EF8C(struct WordSet *p, u32 i, u32 v);       /* id 0xB6  */
void func_0201EF98(struct WordSet *p, u32 i, u32 v);       /* id 0x18  */
void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
void func_0201EFC8(struct WordSet *p, u32 i, u16 v);

void func_0201F020(struct WordSet *p, u32 i, u32 v);       /* id 0xC7  */
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0201F048(struct WordSet *p, u32 i, u32 n);       /* id 0xE7  */
void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
void func_0201F0F8(struct WordSet *p, u32 i, u32 v);       /* id 0xBF  */
void func_0201F104(struct WordSet *p, u32 i, u32 a);
void func_0201F124(struct WordSet *p, u32 i, u32 v);       /* id 0x11B */
void func_0201F134(struct WordSet *p, u32 i, u32 v);       /* id 0xBE  */
void func_0201F140(struct WordSet *p, u32 i, u32 v);       /* id 0xB4  */
void func_0201F14C(struct WordSet *p, u32 i, u32 v);       /* id 0x37  */
void func_0201F158(struct WordSet *p, u32 i, u32 v);       /* id 0x59  */
void func_0201F164(struct WordSet *p, u32 i, u32 a, u32 b);
void func_0201F184(struct WordSet *p, u32 i, s32 v);       /* id 0xA0, SIGNED */
void func_0201F198(struct WordSet *p, u32 i, u32 v);       /* id 0x2B, v<=8   */
void func_0201F1B0(struct WordSet *p, u32 i, u32 v);       /* id 0,    v<=0x91 */
void func_0201F1C8(struct WordSet *p, u32 i, u32 v);       /* id 0x38, v<=8   */
void func_0201F1E0(struct WordSet *p, u32 i, u32 v);       /* id 0x1CD        */
void func_0201F230(struct WordSet *p, u32 i, u32 v);       /* id 0x116        */

/* func_0201F1E0 clears the slot unconditionally BEFORE the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string.  That is what the bytes say and
 * it is reproduced rather than tidied. */

/* ===================================================================== *
 * The expander and the string helpers
 * ===================================================================== */

/* wordset.c's message expander, 204 bytes: walks the source message a
 * halfword at a time and rewrites it into the destination.  An ordinary
 * character is copied through, a 0xF000 tag that is not a word reference is
 * copied verbatim, and a word reference is replaced by the stored word. */
void func_0201F250(struct WordSet *ws, void *dst, void *src);

/* the tag primitives it calls, from src/matched/unit_0201D5C4.c */
extern u32   func_0201D5C4(void);                  /* the 0xF000 marker    */
extern u32   func_0201D5CC(const u16 *p);          /* is a word reference  */
extern void  func_0201D60C(void *s, u32 b, u32 c, u16 n, const u16 *arr);
extern u32   func_0201D670(const u16 *p, u32 i);   /* read parameter i     */
extern u16  *func_0201D688(u16 *p);                /* step past a tag      */

void func_0201F41C(const u16 *src, u16 *dst, u32 n);   /* bounded copy     */
u32  func_0201F448(const u16 *a, const u16 *b);        /* equality         */
u32  func_0201F47C(void *s);              /* "is a packed nine-bit run"    */
void func_0201F4A0(void *dest, void *src);             /* the unpacker     */

/* the decimal number printer, 0x0201F35C.  `flag` selects one of two glyph
 * tables (0x0209E784 full-width, 0x0209E758 half-width) and the matching
 * minus / space glyphs (0x30FC vs 0x2D, 0x3000 vs 0x20): the full-width /
 * half-width font pair, NOT a version-specific table. */
void func_0201F35C(void *ctx, s32 n, u32 kind, u32 mode, u32 flag);
extern u16 g_0209E784[];
extern u16 g_0209E758[];
extern u32 g_0209E838[];

/* ===================================================================== *
 * The drawing tail, 0x0201F53C..0x0201F7A8
 * ===================================================================== */

/* Two three-instruction byte-table lookups, two bytes apart in rodata. */
u8 func_0201F53C(u32 i);      /* table 0x0209E8C8 */
u8 func_0201F548(u32 i);      /* table 0x0209E8CA */
extern u8 sub_0209E8C8_Map[];                       /* 0x0209E8C8 data a1 */
extern u8 sub_0209E8CA_Map[];                       /* 0x0209E8CA data a1 */

void func_0201F554(u32 a, u32 b, u32 c, u32 d);
void func_0201F57C(u32 a, u32 b, u32 c, u32 d);
void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);

/* the nine-slice window frame draw and its two wrappers */
void func_0201F628(u16 id, u8 x, u8 y, u8 w, u8 h, u32 pal, u16 base);
void func_0201F73C(void *desc, u32 kind, u16 base, u32 pal);
void func_0201F79C(void *desc, u32 kind, u32 base, u32 pal);
void func_0201F7A8(void *desc, u32 kind);

/* the five ARM byte accessors on the descriptor, shared by F73C and F7A8 */
extern u8   func_02045730(void *d);
extern u8   func_02045748(void *d);
extern u8   func_02045750(void *d);
extern u8   func_02045758(void *d);
extern u8   func_02045760(void *d);
extern void func_020409B4(u8 id);
extern void func_02041B6C(u8 id);
/* NOTE THE WIDTHS.  a2/a3/a4/a5 are u8 HERE even though
 * src/pending/func_02041300.c declares them u32: with u32 the truncation of
 * `x - 1` becomes a source-level expression, mwccarm CSEs the whole
 * `(u8)(x - 1)` and spills the truncated byte, where the image keeps the
 * untruncated value in a register and re-runs the `lsls #24 / lsrs #24` pair
 * at each use.  That one change moves func_0201F628's residue from 228 bytes
 * to 86.  See
 * docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md */
extern void func_02041300(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5,
                          u32 a6);

/* ---- the levers that cost time in this family ------------------------
 * 1. PARAMETER WIDTH IS A SCHEDULING LEVER, not just a semantic one.  It
 *    closed BOTH of this family's long-standing DIFFs, and in both cases
 *    nothing that runs depends on the width:
 *      func_0201EC74  heap  u32 -> u8   (14 bytes)
 *      func_0201F628  id    u32 -> u16  (86 bytes)
 *    A `--explain` residue of one or two swapped register pairs that no
 *    statement-level mutation moves lives in the DECLARATIONS.  Run
 *    tools/permuter.py --mode hill --types before concluding a residue is
 *    the scheduler; docs/notes/func_0201F628.c.txt carried a
 *    "do not re-attempt" verdict on exactly this shape for a whole wave.
 * 2. `goto fail;` is the only way to share an exit across statements
 *    (func_0201EC74).
 * 3. Declaration order decides register assignment for locals live across a
 *    loop: func_0201F250 declares `q` before `p`, and swapping them swaps r4
 *    and r5 throughout.
 * 4. `*p++` as a call argument, not `p[0]` then `p++` (func_0201F250).
 * 5. The bit cursor in func_0201F4A0 is SIGNED: `cmp r5,#0x10 / blt` is a
 *    signed compare even though the value is never negative.
 * 6. `*(dst + n - 1)`, not `dst[n - 1]` (func_0201F41C): seven bytes.
 */

/* ===================================================================== *
 * Known walls in this family (do not re-derive)
 * ===================================================================== */
/* NONE REMAIN as of 2026-09-22.  The family is closed:
 *   func_0201EC74  closed by `goto fail` + u8 heap   (was DIFF/SIZE, 152/144)
 *   func_0201F628  closed by u16 id                  (was DIFF, 86 bytes out)
 *   func_0201F548  closed by `sole-ref/self`         (was MATCH, no witness)
 * Two entries carry a `blocker:` line that is now historical rather than
 * live: src/matched/func_0201F35C.c and src/matched/sub_0201F4A0.c both
 * reached EXACT through sole-ref after their notes were written, and the
 * prose in them predates that.  Read the status line, not the blocker line.
 */

#endif /* WORDSET_H */
