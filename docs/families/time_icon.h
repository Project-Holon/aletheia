/*
 * docs/families/time_icon.h -- shared declarations for the time_icon.c family
 * (0x0202EE30..0x02030FC8 in the ARM9 image, inferred from the __FILE__
 * anchors at g_020A7814 "time_icon.c").
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration below
 * is derived from a file in src/matched that is EXACT, and the matched
 * function that evidences each field is named in the comment beside it.
 * Where the matched sources disagree on the spelling of a parameter type
 * (they were written by different lanes), the spelling recorded here is the
 * one the byte evidence actually constrains; a parameter that is only ever
 * passed a register-width value and never dereferenced is left u32.
 *
 * NOTE ON EXTENT.  The span holds at least TWO distinct subsystems, not one
 * original file:
 *   - 0x0202EE30..0x0202F9F8  the icon/sprite record below (struct IconRec),
 *     built on the func_02030734 heap allocator and the 0x0204xxxx cell/
 *     surface API.  This is the part the "time_icon.c" anchor names.
 *   - 0x0202FB34..0x02030FC8  a general runtime tail: RC4 (sub_0202FB34),
 *     then the heap/allocator bookkeeping itself (func_02030734,
 *     func_020308B8, func_02030A7C, func_02030DA8 and their neighbours),
 *     which carries its own __FILE__ anchor and its own "SYSTEM ALLOC"
 *     string at 0x020A7824.
 * The edges are therefore soft at BOTH ends, and the 0x0202FB34 boundary is
 * a real subsystem seam rather than a function-or-two rounding error.
 */

#ifndef TIME_ICON_H
#define TIME_ICON_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * The icon record: 0x1c bytes, allocated by every constructor in the
 * family.  Size is evidenced three times over as the literal 0x1c passed
 * to the allocator by func_0202EE30, func_0202EE8C and func_0202EF60.
 * ------------------------------------------------------------------ */
struct IconRec {
    u32 owner;      /* +0x00  func_0202EE30: result of func_02030DA8 when an
                     *        owner was passed, else 0; func_0202EF98 tests
                     *        (+0x00 == 0 && +0x04 == 0) together */
    u32 node;       /* +0x04  func_0202EE30 zeroes it; func_0202EE8C stores
                     *        the func_020311B8 node here; func_0202EF98
                     *        tests it separately before releasing */
    u32 cell;       /* +0x08  func_0202EECC: result of func_020450F0, the
                     *        surface/cell handle.  Consumed by
                     *        func_02045770/func_02045334/func_020452E8 */
    u32 anim;       /* +0x0C  func_0202EECC: result of func_0204384C(0xC6,
                     *        0, 1, +0x10); func_0202F0B0 passes it to
                     *        func_020439A0 as the animation handle */
    u16 id;         /* +0x10  func_0202EECC stores the u16 tail parameter;
                     *        func_0202EF60 stores (u16)heap.  Halfword:
                     *        both write it with strh */
    /* +0x12 .. +0x15 are four separate bytes, all written with strb by
     * func_0202EECC and read back individually by func_0202F0B0 */
    u8  pal;        /* +0x12  func_0202EECC = a2; func_0202F0B0 passes it to
                     *        func_02043B5C as the second argument */
    u8  timer;      /* +0x13  func_0202EECC zeroes it; func_0202F0B0 uses it
                     *        as the countdown: reloads from +0x14 when it
                     *        reaches 0, else decrements */
    u8  period;     /* +0x14  func_0202EECC = a3; func_0202F0B0 reloads
                     *        +0x13 from it */
    u8  frame;      /* +0x15  func_0202EECC = func_020056EC(8);
                     *        func_0202F0B0 increments it, wraps at 8, and
                     *        shifts it left 4 for func_020439A0's argument,
                     *        so it is an unsigned 4-bit-scaled counter */
    u8  pad16[2];   /* +0x16  no matched function touches these two bytes */
    u32 active;     /* +0x18  func_0202EE30/func_0202EE8C set it to 1 at the
                     *        end of construction; func_0202EF98 clears it;
                     *        func_0202F0B0 returns early when it is 0 */
};

/* ------------------------------------------------------------------ *
 * RC4 state, evidenced by sub_0202FB34 (docs/notes/sub_0202FB34.c.txt).
 * The two byte indices are at +0 and +1 and the 256-byte S box at +4:
 * the function does ldrb from [r0] and [r0,#1], then adds 4 to the base
 * before every S-box access.
 * ------------------------------------------------------------------ */
struct Rc4 {
    u8 i;           /* +0x00  ldrb r7, [r0]      */
    u8 j;           /* +0x01  ldrb r6, [r0, #1]  */
    u8 pad[2];      /* +0x02  add r0, r0, #4 skips these */
    u8 s[256];      /* +0x04  the S box */
};

/* ------------------------------------------------------------------ *
 * Heap / allocator API.  These live in the tail of the span and are
 * called from all over the image, so their prototypes are constrained by
 * many matched call sites, not just this family's.
 * ------------------------------------------------------------------ */

/* The tagged allocator.  Five arguments, the last two being the __FILE__
 * anchor and the __LINE__ of the call site (func_0202EE30 passes 0x49,
 * func_0202EF60 passes 0xa6, both with g_020A7814).  The fifth argument
 * goes on the stack.  The heap id is a u16 and is re-read from its stack
 * slot by func_0202EE30, which is why that file spells it volatile u16. */
extern void *func_02030734(u16 heap, u32 size, u32 flags,
                           const char *file, u32 line);

/* The untagged/node allocator used by func_0202EE8C: (heap, tag, size,
 * flags), with the tag a pinned data address rather than an integer. */
extern void *func_020311B8(u32 heap, const u8 *tag, u32 size, u32 flags);

/* Paired with func_020311B8; takes no argument and returns the record the
 * node was allocated for (func_0202EE8C uses the result as the IconRec). */
extern void *func_02031290(void);

/* Registers a record against an owner and a tag; func_0202EE30 stores the
 * result at IconRec +0x00. */
extern u32 func_02030DA8(void *owner, const u8 *tag, void *p, u32 a3);

/* ------------------------------------------------------------------ *
 * Construction / teardown helper, shared by every constructor in the
 * family.  EXACT in src/matched/func_0202EECC.c, which is what fixes the
 * parameter widths: a2 and a3 are bytes (strb to +0x12/+0x14) and a4 is a
 * halfword (strh to +0x10).
 * ------------------------------------------------------------------ */
extern void func_0202EECC(u8 *p, void *surface, u8 pal, u8 period, u16 id);

/* ------------------------------------------------------------------ *
 * Cell / surface API (0x0204xxxx), all ARM, all reached by bl from Thumb.
 * Each prototype is fixed by the argument registers the matched callers
 * set up; a1 is a surface descriptor pointer in every case where the
 * matched code dereferences it.
 * ------------------------------------------------------------------ */
extern u8   func_020056EC(u32 a);                       /* func_0202EECC: returns a byte, stored to +0x15 */
extern u32  func_0204384C(u32 a, u32 b, u32 c, u32 d);  /* func_0202EECC, func_0202EF60: (0xC6, 0, 1, id) */
extern u32  func_02045730(u32 handle);                  /* func_0202EECC: called on a surface and on +0x08 */
extern u32  func_02045758(void *a);                     /* func_0202EECC: width term */
extern u32  func_02045738(void *a);                     /* func_0202EECC: width term */
extern u32  func_02045760(void *a);                     /* func_0202EECC: height term */
extern u32  func_02045740(void *a);                     /* func_0202EECC: height term */
extern u32  func_02045778(void *a);                     /* func_0202EECC: passed through to func_020450F0 */
extern u32  func_020450F0(u32 a, u32 b, u32 c, u32 d,
                          u32 e, u32 f, u32 g);         /* func_0202EECC: 7 args, result to +0x08 */
extern void func_02045374(void);                        /* func_0202EECC */
extern void func_02041B6C(u32 a);                       /* func_0202EECC */
extern u32  func_02045770(u32 cell);                    /* func_0202EF98, func_0202F0B0: on +0x08 */
extern void func_02045334(u32 cell);                    /* func_0202EF98, func_0202F0B0 */
extern void func_020452E8(u32 cell);                    /* func_0202EF98 */
extern void func_02043B5C(u32 a, u8 pal);               /* func_0202EF98, func_0202F0B0 */
extern void func_020439A0(u32 anim, u32 a, u32 b, u32 c,
                          u32 d, u32 e, u32 f, u32 g,
                          u32 h);                       /* func_0202F0B0: 9 args, the frame<<4 in c */

/* ------------------------------------------------------------------ *
 * Pinned data objects.  Both are __FILE__-class anchors: declare them as
 * arrays pinned by address in the symbols: block, never as a literal
 * __FILE__ (docs/idioms/file-string-is-an-abs32-into-the-string-area.md).
 * ------------------------------------------------------------------ */
extern const char g_020A7814[];   /* "time_icon.c", the family's anchor */
extern const u8   unk_0202F099[]; /* func_0202EE30's tag for func_02030DA8 */
extern const u8   unk_0202F0A5[]; /* func_0202EE8C's tag for func_020311B8 */

#endif /* TIME_ICON_H */
