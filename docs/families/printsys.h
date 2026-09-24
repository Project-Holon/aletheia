/*
 * docs/families/printsys.h -- shared declarations for the printsys.c family
 * (0x0201C450..0x0201D7C4 in the ARM9 image).  The file identity is in the
 * image and is not a guess: the module constructor at 0x0201C450 passes
 * 0x020A734C to the debug allocator at 0x02030734 as its __FILE__ argument
 * and the bytes there spell "printsys.c" ("waza_tool.c" ends at 0x020A734B,
 * so the `string` class carries the address).  The __LINE__ argument is 287.
 * src/matched/unit_0201C450.c records both.
 *
 * The tail of the range is already gf_font.c, not printsys.c: the
 * constructor at 0x0201D7EC names 0x020A7358, which spells "gf_font.c", and
 * src/matched/unit_0201D69C.c files 0x0201D69C..0x0201D6D8 under that name.
 * The seam is therefore somewhere in 0x0201D688..0x0201D69C, and the string
 * helpers at 0x0201D26C..0x0201D478 sit on the printsys side of it only by
 * call graph, not by a __FILE__ anchor of their own.  Treat the last
 * quarter of this header as "the string/font helpers printsys.c calls"
 * rather than as printsys.c proper.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration below
 * is derived from a file in src/matched that is EXACT, and the matched
 * function that evidences each field or parameter is named in the comment
 * beside it.  Where two matched sources spell the same thing differently
 * (they were written by different lanes), the spelling recorded here is the
 * one the byte evidence actually constrains.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout.
 */

#ifndef PRINTSYS_H
#define PRINTSYS_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef signed short       s16;
typedef signed int         s32;

/* ------------------------------------------------------------------ *
 * The 64-bit tick field, and why it is a union.
 *
 * unit_0201C450.c had the constructor as a documented two-byte near miss
 * until the field at +8 was written as ONE u64 rather than two u32: as two
 * words the whole function is right except that the pool constant 0x1130
 * arrives in r1 instead of r2.  A 64-bit store leaves the zero-holding
 * register free for the high half and so takes the other scratch register
 * (docs/idioms/a-u64-field-store-picks-a-different-scratch-register.md).
 *
 * sub_0201C4DC then writes the two halves SEPARATELY, which is what makes
 * it a union of the 64-bit value and a two-word struct rather than a plain
 * u64.  +8 is a legal offset for a `long long` at all because this ABI
 * aligns `long long` to four, not eight
 * (docs/idioms/long-long-aligns-to-four.md).
 * ------------------------------------------------------------------ */
union Ticks {
    u64 v;              /* unit_0201C450.c: the constructor's single store */
    struct {
        u32 lo;         /* unit_0201C450.c: sub_0201C4DC writes lo alone   */
        u32 hi;         /*                  and hi alone                   */
    } w;
};

/* ------------------------------------------------------------------ *
 * The print request.  Built on the caller's stack or in the module's
 * static scratch at 0x0214655C, filled by sub_0201C808 (and optionally
 * stamped with a halfword by sub_0201C8A4), then handed to the dispatcher.
 *
 * Evidenced by unit_0201C6B4.c, which is EXACT over the whole
 * 0x0201C6B4..0x0201C6FC run and dereferences unk10 and unk14 as
 * `struct PrintCtx *`.
 * ------------------------------------------------------------------ */
struct PrintCtx {
    s16   unk00;    /* +0x00  unit_0201C6B4.c.  SIGNED: the pen x is read
                     *        with `ldrsh` off a register offset, which is
                     *        the only spelling that produces that encoding
                     *        (docs/idioms/ldrsh-register-offset-is-signedness.md);
                     *        unit_0201CA2C.c adds a signed bias to it. */
    s16   unk02;    /* +0x02  the pen y, signed for the same reason; read
                     *        by unit_0201CA2C.c's blitter as `ldrsh r2`. */
    s32   unk04 : 10;   /* +0x04  A SIGNED 10-BIT BITFIELD, not the u32 flag
                     *        word this header claimed before 2026-09-22.
                     *        src/matched/func_0201C974.c reads it with
                     *        `lsls #0x16 / asrs #0x16` in the 0xFFFE arm and
                     *        src/matched/func_0201CAC8.c does the same in
                     *        both measuring arms; only `s32 :10` produces an
                     *        equal-width 22-bit pair with a signed right half
                     *        (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
                     *        The rest of the word is still the flag field
                     *        func_0201C8BC tests at bit 20 and rewrites,
                     *        masking with 0xFFFF0FFF and or-ing 0x200000, so
                     *        unk04b below is not "unused", only unnamed. */
    u32   unk04b : 22;  /* +0x04 bits 10..31 */
    u16   unk08;    /* +0x08  unit_0201C6B4.c */
    u16   unk0A;    /* +0x0A */
    u16   unk0C;    /* +0x0C */
    u16   unk0E;    /* +0x0E  the packed 5/5/5 triple func_0201C8BC splits
                     *        into hi=(v>>10)&0x1F, mid=(v>>5)&0x1F,
                     *        lo=v&0x1F and passes in that order. */
    void *unk10;    /* +0x10 */
    void *unk14;    /* +0x14  sub_0201C6C4 compares it against the caller's
                     *        `void *v`, which is what types it a pointer. */
    void *unk18;    /* +0x18  the RENDERER HOOK, called through by
                     *        src/matched/func_0201C974.c as
                     *        `c->unk18(c->unk14, c->unk00, c->unk02,
                     *        c->unk10, glyph, pen)` -- six arguments, the
                     *        last two on the stack, `pen` a 4-byte scratch
                     *        whose byte at +2 is the advance added back to
                     *        unk00.  Do NOT confuse it with unk14: the
                     *        measuring arms of func_0201CAC8 hand
                     *        func_020437DC the handle at +0x14, not +0x18. */
};

/* ------------------------------------------------------------------ *
 * The module object.  Allocated by the constructor at 0x0201C450 with size
 * (u16)(n + 0x1C) rounded up to a multiple of four and then + 0x18; the
 * rounding is a `while (v % 4)` loop over a u16 local, whose signed
 * lsrs#31 / lsls#30 / subs / rors#30 quartet is `% 4` on the promoted int
 * (the same shape src/matched/sub_0200A6BC.c records for `% 8`).
 *
 * unk10 and unk14 are the head and tail of the pending-request list:
 * sub_0201C6EC clears both, sub_0201C6B4 reports "idle" as `unk10 == 0`,
 * and sub_0201C6C4 walks the chain with func_0201D7C4 as the successor
 * function.  The tail past unk14 is the byte ring the queueing path uses
 * (func_0201D6C4 reports its free space, func_0201D6D8 appends to it);
 * unit_0201D7C4.c spells that tail `u8 buf[4]` as a flexible head.
 * ------------------------------------------------------------------ */
struct PrintSys {
    u16   unk00;            /* +0x00  unit_0201C450.c; sub_0201C6EC zeroes it */
    u16   unk02;            /* +0x02  sub_0201C6EC copies unk04 into it      */
    u16   unk04;            /* +0x04  the capacity unk02 is reset from       */
    u8    unk06;            /* +0x06 */
    u8    unk07;            /* +0x07  the flags byte.  sub_0201C758 reads the
                             *        TOP FOUR BITS as an unsigned bitfield,
                             *        `((u32)((u8 *)p)[7] << 24) >> 28`; the
                             *        cast to u32 before the shift pair is
                             *        load-bearing, on the promoted int the
                             *        right shift is an `asrs` and the byte
                             *        is wrong (unit_0201CE5C.c records the
                             *        same trap for a one-bit field). */
    union Ticks unk08;      /* +0x08  see above */
    struct PrintCtx *unk10; /* +0x10  request list head */
    struct PrintCtx *unk14; /* +0x14  request list tail */
    /* +0x18 onward: the byte ring.  unit_0201D7C4.c: `u8 buf[4]`. */
};

/* ------------------------------------------------------------------ *
 * The wrap-around byte ring the queueing path writes into, as
 * unit_0201D69C.c names it.  func_0201D6C4 is its used-byte count and its
 * FALL-THROUGH arm is the non-wrapped case, so the source wrote
 * `if (head < tail)` first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 * ------------------------------------------------------------------ */
struct Ring {
    u16 head;   /* +0x00  unit_0201D69C.c */
    u16 tail;   /* +0x02 */
    u16 size;   /* +0x04  func_0201D768 wraps head back to 0 at this bound */
};

/* ------------------------------------------------------------------ *
 * The per-request record the 0x0201CDF4..0x0201CED4 run edits.  Only the
 * touched offsets are known; everything between them is padding here, not
 * an assertion that nothing lives there.
 *
 * Every access to the flag byte at +0x22 is written as TWO independent
 * `((u8 *)p)[0x22]` expressions, one for the load and one for the store,
 * which is what keeps the two addresses computed separately: 0x22 is past
 * `ldrb`'s +31 immediate reach
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).  unit_0201CDF4.c
 * and unit_0201CE5C.c both depend on this spelling.
 * ------------------------------------------------------------------ */
struct Rec {
    u8 pad00[0x18];
    u8 unk18;       /* +0x18  unit_0201CD10's backup of the sign/magnitude
                     *        pair; unit_0201CE5C.c's sub_0201CEB8 restores
                     *        +0x1C/+0x1D from +0x18/+0x19. */
    u8 unk19;       /* +0x19 */
    u8 pad1A[2];
    u8 unk1C;       /* +0x1C  the live pair, replaced via sub_0201CE8C */
    u8 unk1D;       /* +0x1D */
    u8 unk1E;       /* +0x1E  the level-like byte sub_0201CE5C lowers */
    u8 pad1F[3];
    u8 unk22;       /* +0x22  the flag byte: unit_0201CDF4.c clears bits
                     *        4,1,2,8,0x10; unit_0201CE5C.c sets bit 4 and
                     *        bit 3, clears bit 3, and reads bit 3 back as a
                     *        `lsls #0x1C` / `lsrs #0x1F` bitfield pair
                     *        (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md),
                     *        not a `lsrs #3` / `ands #1`. */
};

/* ------------------------------------------------------------------ *
 * The string object the 0x0201D26C..0x0201D478 helpers walk.  A halfword
 * run terminated by 0xFFFF, with 0xFFFE as a line break and 0xF000 opening
 * an embedded block whose length halfword sits at +4 (so the block spans
 * `p + 3 + p[2]` halfwords from its start).  sub_0201D37C is the evidence
 * for all three sentinels at once.
 * ------------------------------------------------------------------ */
struct StrObj {
    u16 capacity;   /* +0x00  sub_0201D2C8.c / sub_0201D37C.c */
    u16 used;       /* +0x02 */
    u32 magic;      /* +0x04 */
    u16 slots[1];   /* +0x08  the halfword run; sub_02045A90 returns a
                     *        `u16 *` into it rather than the object. */
};

/* ------------------------------------------------------------------ *
 * The module's static print scratch.
 *
 * DECLARE IT AS A STRUCT AND PASS `&g_0214655C`, NOT AS AN ARRAY.  Spelled
 * `extern u8 g_0214655C[]` the decayed pointer is ONE value, which the
 * allocator parks in a callee-saved register and copies into r0 at each
 * call; spelled as a struct object, `&g_0214655C` is a fresh address
 * expression per site and the compiler rematerialises the pool load.  The
 * two shapes differ by four bytes and a `mov r8, r8`.  src/matched/
 * sub_0201C724.c and unit_0201C6FC.c both depend on the struct spelling.
 * The one-byte member is a placeholder: nothing in this family ever
 * dereferences the object, it is only ever passed by address.
 * ------------------------------------------------------------------ */
struct Scratch {
    u8 unk_00[1];       /* sub_0201C724.c */
};

extern struct Scratch g_0214655C;   /* 0x0214655C, data */
extern void          *g_02146558;   /* 0x02146558, data: the renderer hook
                                     * unit_0201CA2C.c reaches the blitter
                                     * through. */

/* ------------------------------------------------------------------ *
 * Module lifetime and accessors (0x0201C450..0x0201C4E4).
 * ------------------------------------------------------------------ */
void  sub_0201C450(void);       /* unit_0201C450.c: the constructor       */
void  sub_0201C4C0(void);       /* unit_0201C450.c                        */
void  sub_0201C4C8(void);       /* unit_0201C450.c                        */
void  sub_0201C4DC(void);       /* unit_0201C450.c: writes the two halves
                                 * of unk08 separately                    */

/* ------------------------------------------------------------------ *
 * Queue state (0x0201C6B4..0x0201C6FC).  unit_0201C6B4.c.
 * ------------------------------------------------------------------ */
u32   sub_0201C6B4(const struct PrintSys *p);
u32   sub_0201C6C4(struct PrintSys *p, void *v);
void  sub_0201C6EC(struct PrintSys *p);

/* ------------------------------------------------------------------ *
 * The public print entry points and the dispatcher they share
 * (0x0201C6FC..0x0201C7D0).  unit_0201C6FC.c.
 *
 * All three fill the shared scratch and then hand it on.  sub_0201C758
 * decides between drawing straight away (module not busy AND the flags
 * nibble at +7 clear) and queueing into the ring with func_0201D6D8,
 * provided the request fits in the free space func_0201D6C4 reports.  The
 * busy test is NORMALISED to 0 or 1 before use, which is what a `!= 0`
 * assigned to a local gives.
 *
 * func_0201C7A4 and func_0201C7D0 are the same shape with an extra leading
 * func_02045A90(d) and sub_0201C8BC in place of sub_0201C758; both are
 * both EXACT under dsi/1.1p1 as of 2026-09-24 (the scratch address held in a
 * u32 local is reloaded at every call site; docs/idioms/an-address-held-in-a-u32-local-is-reloaded-at-every-site.md).
 * ------------------------------------------------------------------ */
void  sub_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
void  sub_0201C724(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e,
                   u16 f);
void  sub_0201C758(struct PrintSys *p, struct PrintCtx *c, void *s);

/* ------------------------------------------------------------------ *
 * Request construction and the draw path (0x0201C808..0x0201CC34).
 *
 * The fifth argument of sub_0201C808 is the one outgoing stack word the
 * `push {r3, ...}` of every caller reserves; the `str r3, [sp]` that fills
 * it is the original r3 being forwarded, not a spill (sub_0201C724.c).
 *
 * sub_0201C8A4's halfword argument is always reached as `add r1, sp, #N`
 * then `ldrh r1, [r1, #k]`, never a single sp-relative load: Thumb `ldrh`
 * cannot use sp as a base at all.
 * ------------------------------------------------------------------ */
void  sub_0201C808(struct PrintCtx *c, u32 a, u32 b, u32 d, u32 e);
void  sub_0201C8A4(struct PrintCtx *c, u16 v);
void  func_0201C8BC(struct PrintCtx *c, void *s);   /* DIFF, see
                                                     * docs/notes/pkt_0201C8BC.c.txt */
u16  *func_0201C974(struct PrintCtx *c, u16 *p, u32 f);
                    /* src/matched/func_0201C974.c, EXACT 2026-09-22.  The
                     * glyph-run interpreter.  Three facts it pins: unk04 is
                     * the signed 10-bit bitfield above; the control-code
                     * dispatch inside the 0xF000 arm is a SWITCH on the code
                     * byte (three forward `beq`s, not an if/else chain); and
                     * the 0xBE arm's guard is `if (f != 0) { ...; break; }
                     * return p;`, never `if (f == 0) return p;`.  Its glyph
                     * body is reached by an explicit `goto` to a label after
                     * the `while (1)`, which is what places it last.       */
u16  *func_0201CAC8(struct PrintCtx *c, u16 *p);
                    /* src/matched/func_0201CAC8.c, EXACT 2026-09-22.
                     * Applies one 0xF000 control block whose code byte is
                     * 0xBD.  Its only branch image-wide is at 0x0201C9D0
                     * inside func_0201C974, so before this file existed that
                     * call resolved `sole-ref/code`; it is `matched` now.
                     * A DENSE 7-entry halfword switch: `case 6:` is EMPTY
                     * and must still be written, or the bound check is
                     * `cmp #5` and the table loses an entry.  Its selector
                     * is `((u32)(u8)p[1] << 16) >> 16` -- TWO stacked
                     * narrowings, u8 then u16; one alone is four bytes
                     * short.  Its case-0 pack is
                     * `(b & 0x1F) | (((r << 27) >> 17) | ((g << 27) >> 22))`,
                     * red to bit 10 and green to bit 5.                    */
void *func_0201CC34(void *a0, void *a1);            /* src/matched/func_0201CC34.c */

/* ------------------------------------------------------------------ *
 * The glyph blitters (0x0201CA2C, 0x0201CA78).  Cut into two files on
 * purpose: func_0201DB04 is reached from exactly two places image-wide,
 * 0x0201CA4C and 0x0201CA98, one in each function, so matched together
 * neither site has a witness and matched apart each is the other's `label`
 * witness (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * `f` is a four-byte pen record: f[0] is an x bias added to the caller's x,
 * f[1] and f[3] are passed straight through.
 * ------------------------------------------------------------------ */
void  sub_0201CA2C(void *a, s32 b, u32 c, u32 d, u16 e, const u8 *f);
void  sub_0201CA78(void *a, s32 b, u32 c, u32 d, u16 e, const u8 *f);

/* ------------------------------------------------------------------ *
 * Record construction and the single-bit flag edits
 * (0x0201CD10..0x0201CED4).
 *
 * func_0201CD10 is a two-byte near miss AND caps at MATCH even at zero
 * bytes: its ABS32 site needs 0x0201CEE0, whose only pool word image-wide
 * is its own, inside the compared range.  See docs/notes/pkt_0201CD10.c.txt.
 * Its argument order for func_020311B8 is (a6, fn, 0x50, a7) and it RETURNS
 * the allocated object, so `void *`, not `void`.
 * ------------------------------------------------------------------ */
void *func_0201CD10(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, s32 a5,
                    u32 a6, u32 a7, u32 a8, u32 a9, u32 a10);
void  sub_0201CDF4(int v, u8 *out);     /* writes a 2-byte sign/magnitude
                                         * pair; callers read out[1] FIRST */
void  sub_0201CE0C(void *p);
void  sub_0201CE20(void *p);
u32   sub_0201CE30(void *p);
u32   sub_0201CE34(void *p);
void  sub_0201CE38(void *p);
void  sub_0201CE48(struct Rec *p);
void  sub_0201CE5C(struct Rec *p);
void  sub_0201CEB8(struct Rec *p);
u32   sub_0201CED4(const struct Rec *p);    /* unlabelled follower, eight
                                             * bytes, no prologue          */
void  func_0201CEE0(void);      /* the callback func_0201CD10 installs; a
                                 * real Thumb function, and the pool word
                                 * carries the Thumb bit.  Open.           */

/* ------------------------------------------------------------------ *
 * Control-code application and the string helpers
 * (0x0201D110..0x0201D478).
 *
 * sub_0201D110 applies the control code the cursor is parked on and steps
 * the cursor past it; open, and the struct offsets past +0x14 in the
 * inherited source are still wrong (docs/notes/sub_0201D110.c.txt).
 *
 * sub_0201D37C copies line `n` of one string object into a second, freshly
 * cleared one.  Phase one skips n line breaks, phase two appends the line a
 * halfword at a time and closes it with 0xFFFF; embedded 0xF000 blocks are
 * skipped in phase one and copied verbatim in phase two.  It is EXACT only
 * with the block-end computed in TWO statements, `end = p + 3;` then
 * `end = end + p[2];`: the fused `end = p + 3 + p[2]` swaps r4 and r5
 * between the cursor and the counter for 24 bytes.
 * ------------------------------------------------------------------ */
u32   sub_0201D26C(u16 *p, void *font, u32 spacing, u16 **next);
u32   sub_0201D2C8(struct StrObj *s);
u32   sub_0201D304(struct StrObj *s, u32 a, u32 b);
u32   sub_0201D33C(struct StrObj *s, u32 a, u32 b, u32 *out, u32 max);
u32   sub_0201D37C(struct StrObj *src, struct StrObj *dst, u32 n);
u32   sub_0201D42C(struct StrObj *s, void *font);
u32   func_0201D478(void *s);
u32   func_0201D4BC(void *s, u32 v);
u32   func_0201D528(void *s, u32 b, void *c, u32 d);

/* ------------------------------------------------------------------ *
 * The measuring helpers (0x0201D5C4..0x0201D688).  unit_0201D5C4.c.
 * func_0201D688 is the "step one element" primitive the others share.
 * ------------------------------------------------------------------ */
u32   func_0201D5C4(void);
u32   func_0201D5CC(const u16 *p);
u32   func_0201D5F4(const u16 *p);
void  func_0201D60C(void *s, u32 b, u32 c, u16 n, const u16 *arr);
u32   func_0201D658(const u16 *p);
u32   func_0201D670(const u16 *p, u32 i);
u16  *func_0201D688(u16 *p);

/* ------------------------------------------------------------------ *
 * The ring tail (0x0201D69C..0x0201D7C4).  unit_0201D69C.c files the first
 * three; the last two are the family's standing wall.
 *
 * func_0201D69C sizes a string's storage: two bytes per character plus the
 * terminator, rounded up to a multiple of four.  The rounding really is a
 * `while` loop over `n & 3` and not an `& ~3`: this front end has no
 * immediate `bic`, so a mask would be materialised and the function four
 * bytes shorter with no loop at all.
 *
 * func_0201D6D8 and func_0201D768 reproduce the right size and the right
 * instruction multiset but allocate the frame the other way round: the
 * original spills the byte counter and keeps the ring cursor in a
 * callee-saved register.  func_0201D768's `total` really is a volatile-like
 * spilled local (a plain u32 gives 90 bytes against 92; `volatile u32
 * total` gives 92 exactly), but the slot assignment for `total` and `start`
 * is still mirrored.  Closing func_0201D768 makes func_0201D6D8 EXACT,
 * which in turn unsticks sub_0201C758 (unit_0201C6FC.c) through the
 * `matched` class -- the one lever in this family that promotes another
 * file.
 * ------------------------------------------------------------------ */
u32   func_0201D69C(u32 n);
u32   func_0201D6B8(void *s);
u32   func_0201D6C4(const struct PrintSys *p);
void  func_0201D6D8(struct PrintSys *p, void *a, void *b);
u8   *func_0201D768(u16 *p, u8 *dst, u32 len, u32 n);
struct PrintCtx *func_0201D7C4(struct PrintSys *p, struct PrintCtx *q);

/* ------------------------------------------------------------------ *
 * ADDED 2026-09-23 (wave 11).  THE TEXT RECORD, the 0x50-byte work area
 * func_0201CD10 allocates for the task func_0201CEE0.  struct Rec above
 * only named the offsets the flag helpers touch; the full layout, as
 * src/matched/func_0201CEE0.c, func_0201CD10.c and sub_0201D110.c (all
 * EXACT) declare it:
 *
 *   +0x00 u32 state      0 print, 1 wait for key, 2 finished
 *   +0x04 u32 mode       key-wait flavour (0 scroll, 1 clear)
 *   +0x08 u32 f08        func_02045334's argument (the window to flush)
 *   +0x0C u32 win        the bitmap window handle
 *   +0x10 void *task     func_020311B8's return
 *   +0x14 u16 *cur       the glyph cursor
 *   +0x18..+0x1D u8      speed pairs (18/19 backup, 1a/1b, 1c/1d)
 *   +0x1E u8 wait        per-glyph countdown
 *   +0x1F u8 scroll      lines scrolled so far (0..0x10)
 *   +0x20 u8 color       fill colour
 *   +0x21 u8 cbres       last callback result
 *   +0x22 flags          a struct of 1-bit fields b0..b4: READ them through
 *                        the bitfield (lsls/lsrs pairs off one cached ldrb),
 *                        WRITE them through the bitfield in func_0201CEE0
 *                        and func_0201CD10 (each write reloads the byte);
 *                        sub_0201D110 writes bit 2 through
 *                        `((u8 *)p)[0x22]` -- both spellings give the
 *                        two-address-computation store
 *   +0x24 u8 (*cb)(u32)  the per-glyph callback
 *   +0x28 u32, +0x2C u32, +0x30 u32 cbarg
 *   +0x34 struct PrintCtx ctx   (0x1C bytes, to +0x50)
 *
 * func_0201C808 is (struct PrintCtx *, void *w, void *x, s16 y, s16 z)
 * (src/matched/sub_0201C808.c): its callers' y/z are s16 PARAMETERS, and
 * that is what closed func_0201CD10's two-load swap together with its
 * tenth argument being `u16 a9` (the `add r1, sp, #N / ldrh [r1, #k]` form
 * is a stacked u16 parameter, not an address taken of a4).
 *
 * COMPILER PIN WITHDRAWN 2026-09-24.  func_0201C7A4 and func_0201C7D0 are both
 * EXACT under dsi/1.1p1 once the scratch address g_0214655C is held in a u32
 * local and cast at each call: 1.1p1 then reloads the pool word at every site
 * as the image does.  The earlier reading below is kept for the record.
 * COMPILER PIN.  func_0201C7A4 is EXACT only under ../2.0/sp2: dsi/1.1p1
 * caches the scratch address g_0214655C in a callee-saved register across
 * its two uses, 2.0/sp2 reloads it from the pool at each site as the image
 * does.  func_0201C7D0 (the same body plus sub_0201C8A4) is two bytes out
 * under 2.0/sp2 -- only the base of its stacked u16 read (`add r1, sp,
 * #0x18 / ldrh [r1, #4]`, which 1.1p1 forms right and sp2 forms as sp+8 /
 * #0x14).  func_0201CEE0, func_0201CD10 and sub_0201D110 are 1.1p1.
 *
 * INLINE HELPERS this file uses (all proven by EXACT bytes):
 *  - the control-code kind as a u16 of `(u8)p[1]` computed in a helper
 *    returning u32 (sub_0201D110: the (u8) then (u16) pair in the header
 *    arm only), and the code byte `(u8)(p[1] >> 8)` taking the ALREADY
 *    LOADED halfword (func_0201CEE0: the dead `bne` reuses the switch's
 *    compare);
 *  - the ring wrap, twice in func_0201C4E4, which is EXACT since wave 13
 *    (src/matched/func_0201C4E4.c) ONLY in the named-local form
 *        static inline u16 Wrap(struct PrintSys *ps, u16 o)
 *        { u16 r = o; if (r >= ps->unk04) r = 0; return r; }
 *    The early-return form (`if (o >= ps->unk04) return 0; return o;`)
 *    truncates in place and lets the size load float: 5 bytes out.
 *
 * ADDED 2026-09-23 (wave 13).
 *  - func_0201D768's third parameter is `u16 len`: its only caller,
 *    func_0201D6D8, narrows the value it passes (lsls/lsrs #0x10), and
 *    with u16 the plain source is size-exact (92) with no volatile and the
 *    image's `ldr [sp] / cmp #0 / bls` guard.  Still DIFF (66): the
 *    head/counter spill choice.  docs/notes/func_0201D768.diff.c.txt.
 *  - func_0201C7D0 (2 out under sp2) mixes a 1.1p1 trait (the stacked u16
 *    read based at the incoming-argument block, `add r1, sp, #0x18`; sp2
 *    ALWAYS bases such reads at sp+8) with an sp2 trait (the outgoing
 *    `str` scheduled last, the scratch address reloaded per call).  Neither
 *    pinned compiler can produce both; see docs/notes/pkt_0201C7D0.c.txt.
 * ------------------------------------------------------------------ */

#endif /* PRINTSYS_H */
