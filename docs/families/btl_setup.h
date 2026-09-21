/*
 * docs/families/btl_setup.h -- shared declarations for the btl_setup.c
 * family (0x02013090..0x02013980 in the ARM9 image: the battle-setup
 * object, its four-slot party/trainer arrays, and the family of small
 * "builder" entry points that configure one battle of a given kind).
 *
 * The __FILE__ anchor at 0x020A729C ("zonedata.c" is a DIFFERENT anchor at
 * 0x020A72B0; the two sit six bytes apart with the substitution table
 * between them) is loaded by func_02013090 (line 0x31), func_02013234
 * (line 0xEF) and func_02013980 (line 0x39A), which is the evidence that
 * the allocating functions of this range are one translation unit; the
 * line numbers run 0x31..0x39A in address order.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration
 * below is derived from a file in src/matched that is EXACT or EXACT*, and
 * the matched function that evidences each field or parameter is named in
 * the comment beside it.  Where two matched sources spell the same field
 * differently (different lanes wrote them) the spelling recorded here is
 * the one the byte evidence actually constrains.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout.
 */

#ifndef BTL_SETUP_H
#define BTL_SETUP_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * THE SETUP OBJECT, 0xF0 bytes.
 *
 * Its size is pinned twice over: func_02013090 allocates 0xf0 bytes, and
 * func_020130C4 / sub_020130DC / sub_020138C4 each memset the same object
 * for 0xf0.  The constructor pair is
 *
 *   func_02013090(heap)   allocate 0xf0, then func_020130C4
 *   func_020130C4(p)      memset 0, then func_02013220(p + 8)
 *   sub_020130DC(p)       destructor: free every slot, then memset 0xf0
 *   sub_020138C4(p,a1,a2) the full builder: fills all three slot arrays
 *
 * The layout below is every offset any EXACT file in the range touches;
 * the gaps are genuinely unread by this family.
 * ------------------------------------------------------------------ */
struct BtlSetup {
    u32   mode;         /* +0x00  the battle-kind word.  func_020134F4 stores
                         *        1, sub_020135C0 stores 4, func_0201320C's
                         *        sub-block writer stores 9, sub_02013810
                         *        stores 1.  A full word: every one of those
                         *        is `str`, never `strb`/`strh`. */
    u32   f04;          /* +0x04  the second setup word, written beside mode
                         *        in the same pairs (func_020134F4 stores its
                         *        a2 here, sub_020135C0 stores 0). */
    u8    sub08[0x18];  /* +0x08  the 0x18-byte sub-block func_020130C4 hands
                         *        to func_02013220 as `p + 8`.  Its own layout
                         *        is struct BtlSetupSub below. */
    u16   f1a_unused;   /* +0x1A  NOT part of sub08: func_020134F4 stores the
                         *        constant 0x47D here and func_02013284's
                         *        switch stores 0x47D/0x47E/0x47F/0x480/0x491.
                         *        It overlaps sub08's declared extent, i.e.
                         *        the real file writes `p + 0x1a` through the
                         *        outer pointer, not through the sub-block. */
    u8    pad1c[0x22 - 0x1C];
    u8    slot_count;   /* +0x22  the number of sub-blocks the builder filled:
                         *        func_020136E0 stores 4, func_02013734
                         *        stores 3. */
    u8    active;       /* +0x23  sub_020138C4 stores 1 at the end. */
    void *party[4];     /* +0x24  four slots, filled by sub_0201A920(a2) in
                         *        sub_020138C4, freed with sub_020307B0 in
                         *        sub_020130DC.  func_0201347C and
                         *        sub_020135C0 read party[0] (+0x24) as the
                         *        second argument of func_0201AC2C. */
    void *trainer[4];   /* +0x34  four slots, sub_0200846C(a2).  Slot 0 is
                         *        deliberately NOT freed: sub_020130DC's loop
                         *        guards the free with `i != 0`. */
    u8    pad44[4];     /* +0x44  unread by the family. */
    void *pokedata[4];  /* +0x48  four slots, func_02013234(a2), freed with
                         *        func_02013270.  func_02013284 indexes this
                         *        array as `a0 + 0x48 + a2 * 4` and lazily
                         *        fills a null entry with func_02013234. */
    u32   f58;          /* +0x58  sub_020138C4 stores its a1 (the battle id
                         *        it also hands to sub_0200CA1C). */
    u32   f5c;          /* +0x5C  sub_020082EC(a2)'s result in sub_020138C4;
                         *        func_02013930 frees it with func_020307B0
                         *        and clears it INSIDE the guard. */
    u8    pad60[8];
    u32   f68;          /* +0x68  sub_0200CA1C(a1) in sub_020138C4. */
    u8    pad6c[0x74 - 0x6C];
    u16   time_hi;      /* +0x74  sub_02013160: sub_0200AE54(a1, 0xF) * 0x3C.
                         *        A halfword: the store is `strh`. */
    u16   time_lo;      /* +0x76  sub_02013160: sub_0200AE54(a1, 0x10) * 0x3C. */
    u8    name78[10];   /* +0x78  sub_02013160 passes `p + 0x78` to
                         *        sub_0200B040 as a destination buffer. */
    u16   flags82;      /* +0x82  the flag word.  func_02013144 is the only
                         *        setter, `*(u16 *)(p + 0x82) |= (u16)v`, and
                         *        sub_02013160 ORs 0x10<<6 / 0x10<<7 through
                         *        it.  func_0201347C passes 0x40. */
    u8    pad84[0x94 - 0x84];
    u8   *zonebuf;      /* +0x94  func_02013980's lazy 0xC00 allocation.
                         *        sub_020130DC frees it (its `a94`). */
    u8    pad98[0xF0 - 0x98];
};

/* ------------------------------------------------------------------ *
 * THE SUB-BLOCK at +0x08, 0x18 bytes, initialised by func_02013220 and
 * by func_0201320C (the same fields, different constants: 0xA vs 0, and
 * 9 vs 0 in the lead word).  The two writers disagree only in values, so
 * the field widths below are the intersection both agree on, and every
 * one of them is pinned by the store width in both functions.
 * ------------------------------------------------------------------ */
struct BtlSetupSub {
    u32   kind;         /* +0x00  func_02013220 writes 0, func_0201320C 9. */
    u32   f04;          /* +0x04  both write 0. */
    u8    f08;          /* +0x08 */
    u8    f09;          /* +0x09  NOTE the store order is the evidence of
                         *        source order and differs between the two:
                         *        func_02013220 writes f09 before f08,
                         *        func_0201320C writes f08 first and f09
                         *        LAST, after f0d. */
    u16   f0a;          /* +0x0A  a halfword in both. */
    u8    f0c;          /* +0x0C  func_02013220 writes 0xA, func_0201320C 0. */
    u8    f0d;          /* +0x0D  both write 0. */
    u8    pad0e[0x18 - 0x0E];
};

/* ------------------------------------------------------------------ *
 * THE BUILDER FAMILY.  Every public entry point of the file has the same
 * shape: configure the object with the shared writers, then fill one or
 * more sub-block slots.  Two shared writers do all the work.
 *
 *   func_020134F4(o, a1, id, c, h)          the 5-argument writer
 *   func_02013284(o, a1, n, dst, v, h)      the sub-block filler
 *   func_02013528(p0,p1,id,b,c,d,e,f)       the 8-argument writer
 *
 * The id-keyed families below are byte-for-byte identical apart from one
 * immediate, which is why they are the cheapest evidence in the range:
 *
 *   func_020134F4 id:   func_02013610 (0), func_02013644 (1),
 *                       func_02013678 (2), func_020136AC (3)
 *   func_02013528 id:   func_02013790 (0), func_020137C0 (1),
 *                       func_02013864 (2), func_02013894 (3)
 *
 * func_020137F0 is the short member: no func_0203D1A4 pre-call, and its
 * fourth argument to func_02013528 is 1 rather than 0.
 * ------------------------------------------------------------------ */

/* The 0xF0 object's lifecycle. */
extern void *func_02013090(u32 heap);                     /* func_02013090 */
extern void  func_020130C4(void *p);                      /* func_020130C4 */
extern void  sub_020130DC(struct BtlSetup *p);            /* sub_020130DC */
extern void  func_02013930(struct BtlSetup *p);           /* func_02013930 */

/* Sub-block initialisers. */
extern void  func_02013220(void *sub);                    /* func_02013220 */
extern void  func_0201320C(void *sub, int, int, int);     /* func_0201320C */

/* The flag setter.  The second argument is `int` and is narrowed to u16 at
 * the store, which is what makes the single `orrs` legal. */
extern void  func_02013144(char *p, int v);               /* func_02013144 */

/* The pokedata slot object, 0x28 bytes: +0x00 zeroed, +0x14 a
 * func_020457B0(0x10, heap) allocation, and two func_0202428C-initialised
 * 8-byte blocks at +0x18 and +0x20.  func_02013270 is its destructor
 * (func_02045808 on the +0x14 pointer, then free). */
extern void *func_02013234(u32 heap);                     /* func_02013234 */
extern int   func_02013270(int p, int, int, int);         /* func_02013270 */

/* The two shared writers.  The fifth argument of func_020134F4 arrives on
 * the stack in every caller (the `add r2, sp, #0x20` / `ldrh` pair), which
 * is why each builder pushes six registers and then takes eight more bytes;
 * the last four of func_02013528's eight are stack arguments, hence its
 * sixteen-byte frame. */
extern void  func_020134F4(u8 *p, u32 a1, u32 id, u32 c, u16 h);
                                                          /* func_020134F4 */
extern void  func_02013284(u8 *p, u32 a1, u32 n, u8 *dst, u32 v, u16 h);
                                                          /* func_02013610 */
extern void  func_02013528(u32 p0, u32 p1, u32 id, u32 b, u32 c, u32 d,
                           u32 e, u32 f);                 /* func_02013790 */

/* The id-keyed builder families. */
extern void  func_02013610(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void  func_02013644(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void  func_02013678(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void  func_020136AC(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void  func_020136E0(struct BtlSetup *o, u32 a1, u32 a2, u32 a3,
                           u32 a4, u16 a5);               /* func_020136E0 */
extern void  func_02013734(struct BtlSetup *o, u32 a1, u32 a2, u32 a3,
                           u32 a4, u32 a5, u32 a6);       /* func_02013734 */
extern void  func_02013790(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void  func_020137C0(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void  func_020137F0(u32 p0, u32 p1, u32 p2, u32 p3, u8 p4, u16 p5);
extern void  func_02013864(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void  func_02013894(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);

/* The whole-object builder and the lazy zone buffer. */
extern void  sub_020138C4(struct BtlSetup *p, int a1, void *a2);
extern void  func_02013980(struct BtlSetup *o, u32 heap);

/* ------------------------------------------------------------------ *
 * EXTERNALS the family calls, with the prototypes the byte evidence in
 * this range actually constrains.
 * ------------------------------------------------------------------ */
extern void *func_02030734(u32 heap, u32 size, u32 flags, const char *file,
                           u32 line);    /* func_02013090, _02013234, _02013980 */
extern void  func_020307B0(void *p);                      /* sub_020130DC */
extern void  func_02082BCC(void *dst, int c, u32 n);      /* func_020130C4 */
extern void *func_020457B0(u32 size, u32 heap);           /* func_02013234 */
extern void  func_0202428C(void *p);                      /* func_02013234 */
extern int   func_02045808(int p);                        /* func_02013270 */
extern u32   func_0202A3FC(u32 v);                        /* func_0201394C */
extern u32   func_0203D1A4(u32 v);                        /* func_02013790 */

/* sub_0200AE54(a1, key) returns a per-key setting; sub_02013160 multiplies
 * two of them (keys 0xF and 0x10) by 0x3C and stores the halfword results. */
extern int   sub_0200AE54(void *a, int key);              /* sub_02013160 */
extern void  sub_0200B040(void *a, u8 *dst);              /* sub_02013160 */

/* The four-slot array fillers used by sub_020138C4. */
extern int   sub_0201A920(void *a2);                      /* sub_020138C4 */
extern int   sub_0200846C(void *a2);                      /* sub_020138C4 */
extern int   sub_020082EC(void *a2);                      /* sub_020138C4 */
extern int   sub_0200873C(void);                          /* sub_020138C4 */
extern void  sub_02008314(int a, int b);                  /* sub_020138C4 */
extern int   sub_0200CA1C(int battle_id);                 /* sub_020138C4 */
extern void  sub_02012EBC(void);                          /* sub_020138C4 */

/* ------------------------------------------------------------------ *
 * KNOWN BLOCKERS in this range, so the next reader does not re-derive
 * them.  Recorded from docs/notes/pkt_*.c.txt, re-verified 2026-09-21.
 *
 * func_0201AC2C cannot carry a fixed prototype across its two call sites
 * in sub_020135C0: the first passes r0 and r1, the second passes only r0
 * and leaves r1 holding the previous call's result.  A two-parameter
 * declaration emits `movs r1, #0` at the second site; only a variadic
 * declaration, `void func_0201AC2C(u32 a, ...)`, reproduces both.  See
 * docs/notes/pkt_02013528.c.txt.
 *
 * WAVE 4 (2026-09-21) RESULT: five of the seven open functions closed.
 * func_02013160 EXACT*, func_02013284 EXACT, func_0201347C EXACT*,
 * func_020135C0 EXACT, func_02013810 EXACT*.  func_02013360 and
 * func_02013528 remain DIFF and are documented in their notes.
 *
 * THE FAMILY'S SIGNATURE IDIOM: leftover registers are real arguments.
 * Three separate functions in this range were stuck on the same thing - an
 * instruction that reads as a gratuitous register copy, or a call that sets
 * only some of r0-r2, is in fact an argument being passed.  func_0201AC2C
 * must be declared variadic, `void func_0201AC2C(u32 a, ...)`, because its
 * call sites differ in arity (func_020135C0 and func_0201347C, both EXACT);
 * the `adds r1, r0, #0` before a +0x28 store is that call's SECOND argument,
 * not a copy.  func_020076D0 takes three arguments and its first is the
 * return value of the func_0201293C call above it (func_0201347C).  Assume
 * an unexplained live register at a call site is an argument before
 * assuming it is an allocator artefact.
 *
 * SECOND FAMILY IDIOM: the +0x48 slot array is register-offset addressed.
 * func_02013284 indexes it as `*(u32 *)(base + off)` with `u8 *base` and a
 * separate byte offset, NOT as `slot = (u32 *)(o + 0x48 + n * 4)`.  The
 * single-pointer form folds base and index into one value and rotates the
 * allocation of r5/r6/r7.
 *
 * THIRD: func_02013160's switch needs an explicit empty `case 0:` for its
 * jump table to exist at all, and its four-slot loop counter is `int`, not
 * `u32` (blt, not blo).  The four-slot loops in this family are not all the
 * same: sub_020130DC and func_02013528 guard the body with `i != 0`,
 * func_02013160 and func_02013360 do not.
 *
 * func_020139B0 and sub_02013A94 are capped at MATCH for lack of any
 * witness for the "zonedata.c" anchor at 0x020A72B0 and the substitution
 * table at 0x020A72A8/0x020A72AA: the table sits between the two anchors,
 * so attest_string's terminator-of-the-previous-string condition fails.
 * See docs/idioms/a-string-after-a-data-table-has-no-witness.md.
 * ------------------------------------------------------------------ */

#endif /* BTL_SETUP_H */
