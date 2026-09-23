/*
 * docs/families/bmp.h -- shared declarations for the bmp.c family
 * (0x02043678..0x02044F64 in the ARM9 image; the __FILE__ anchor at
 * 0x020A7E68 reads "bmp.c" and is loaded by func_02043678 line 97/103,
 * func_020436FC line 123, func_02043754 line 148, func_0204384C line 266
 * and func_02043900 line 321).  Edges are fuzzy by a function or two at
 * both ends: 0x0204361C..0x02043668 ahead of it is display-control, and
 * the packet's tail at 0x02044F64 is the last blit worker.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration
 * below is derived from a file in src/matched that is EXACT, and the
 * matched function that evidences each field or parameter is named in the
 * comment beside it.  Where two matched sources spell the same field
 * differently (they were written by different lanes), the spelling
 * recorded here is the one the byte evidence actually constrains.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout.
 */

#ifndef BMP_H
#define BMP_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * The bitmap descriptor.  TWELVE bytes, evidenced three times over as
 * the literal 0xC passed to the allocator by func_02043678 (which uses
 * sizeof), func_020436FC, func_02043754 and unit_0204384C (which spells
 * the 0xC out).  src/matched/func_02043814.c names it struct Bmp.
 *
 * WIDTH AND HEIGHT ARE PIXELS IN THE DESCRIPTOR, TILES AT THE API EDGE.
 * Every constructor multiplies its incoming extent by 8 before the store
 * (func_02043678, func_020436FC, func_02043754: `width * 8`), and
 * unit_02043900 does the same to the two halfword cell counts it reads
 * out of the archive header.  So a caller passes tiles and the field
 * holds pixels.  func_020437EC divides both back down by 8 to recover
 * the tile counts.
 * ------------------------------------------------------------------ */
struct Bmp {
    void *pixels;   /* +0x00  func_02043678 stores the allocated buffer;
                     *        func_020436FC/func_02043754 store the
                     *        caller's; func_020437D4 returns it;
                     *        func_02043814 passes it to MIi_CpuCopy32.
                     *        The blit workers treat it as `u8 *`. */
    u16   width;    /* +0x04  func_020437DC returns it as u16, which is
                     *        what makes it a halfword rather than a word;
                     *        func_020437EC divides it by 8 with an `lsr`
                     *        (not `asr`), so it is UNSIGNED. */
    u16   height;   /* +0x06  func_020437E4 returns it as u16.  In
                     *        func_020437EC the SECOND division is a
                     *        signed `asr` triple, because by then the
                     *        product has become an int. */
    u16   depth;    /* +0x08  bytes per tile, not bits per pixel: 0x20 for
                     *        4bpp and 0x40 for 8bpp (unit_02043900 stores
                     *        exactly those two for archive formats 3 and
                     *        4).  func_02043994 returns it truncated to
                     *        u8 -- the `ldrh` then `and #0xff` is the
                     *        field's width against the return type's, so
                     *        the FIELD is a halfword.  sub_02043B5C tests
                     *        it against 0x20 to decide nibble
                     *        replication. */
    u16   kind;     /* +0x0a  ownership/format tag.  0 = the descriptor
                     *        owns its pixel buffer (func_02043678 and
                     *        unit_02043900 both store 0); 1 =
                     *        func_020436FC's borrowed buffer; 2 =
                     *        func_02043754's.  func_020437AC releases
                     *        the buffer ONLY when this is 0, which is
                     *        what makes it the ownership flag rather
                     *        than a format.  The blit dispatcher
                     *        func_020439A0 and the fill dispatcher
                     *        func_02043AF4 both switch on `!= 2`, so 2
                     *        also selects the second worker family. */
};

/* The blit/fill workers see the same object through a shorter spelling:
 * only +0x00, +0x04 and +0x06 are ever touched inside a worker, so
 * docs/notes/sub_02044CE0.c.txt and docs/notes/pkt_02043B98.c.txt both
 * call it `struct Surface`/`struct Surf` with three members.  It is the
 * same struct Bmp; the workers simply never read +0x08 or +0x0a (their
 * dispatcher already did).  Recorded here so a worker's source and this
 * header do not read as two different objects. */

/* ------------------------------------------------------------------ *
 * The tiled pixel layout, evidenced by the pool constants of every
 * worker in the family.  Pixels are 8x8 tiles, tile rows contiguous
 * left to right.  The row stride in tiles is the SAME expression in
 * every worker, confirmed byte for byte in docs/notes/sub_02044CE0.c.txt:
 *
 *     tilesWide = (bmp->width + (bmp->width & 7)) >> 3;
 *
 * A signed divide by 8 would carry a rounding correction and a `+ 7`
 * would be an `add #7`; neither appears in any worker, so the `and #7`
 * plus `add` pair is the source shape.
 *
 * The offset arithmetic is written MULTIPLY-THEN-MASK, never
 * shift-then-mask: `(v * 8) & 0x38` gives the original's `lsl #3` /
 * `and #0x38` pair, while the equivalent `(v & 7) * 8` compiles to
 * `lsl #0x1d` / `lsr #26` instead.  Both spellings were compiled and
 * compared (docs/notes/sub_02044CE0.c.txt).  The constants:
 *
 *   4bpp (depth 0x20, four bytes per tile row, two pixels per byte):
 *       (v * 4) & 0x3fe0   tile index scaled to bytes, = (v >> 3) * 32
 *       (v * 4) & 0x1c     row inside the tile,        = (v & 7) * 4
 *       (x >> 1) & 3       byte within the tile row
 *       (x & 1) * 4        nibble shift, compiled as lsl #31 / lsr #29
 *   8bpp (depth 0x40, eight bytes per tile row, one byte per pixel):
 *       (v * 8) & 0x7fc0   tile index scaled to bytes, = (v >> 3) * 64
 *       (v * 8) & 0x38     row inside the tile,        = (v & 7) * 8
 *       (x & 7)            byte within the tile row
 *
 * The 8bpp pool word 0x00007FC0 is referenced eight times from a single
 * literal in func_02044954, which is what confirms the mask is 0x7fc0
 * and not a shifted 0x3fe0.
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * Constructors and lifetime.  All four allocate the 0xC descriptor from
 * the same heap allocator; the heap id is the LAST argument, and in
 * func_020436FC/func_02043754 it arrives on the stack as a halfword
 * (both were EXACT only with `u16 heap`; a u32 parameter changes the
 * incoming load).
 * ------------------------------------------------------------------ */

/* 0x02043678  EXACT, src/matched/func_02043678.c.  Allocates BOTH the
 * descriptor (uncleared, line 97) and the pixel buffer (cleared, line
 * 103).  The buffer size is depth * (width * height) in TILE units --
 * the extents are still tiles at this point.  kind is left 0. */
struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u32 heap);

/* 0x020436FC  EXACT, src/matched/func_020436FC.c.  Wraps a caller-owned
 * buffer; kind = 1. */
struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 depth,
                          u16 heap);

/* 0x02043754  EXACT, src/matched/func_02043754.c.  Identical to
 * func_020436FC except kind = 2 and the line number. */
struct Bmp *func_02043754(void *pixels, u32 width, u32 height, u32 depth,
                          u16 heap);

/* 0x0204384C  EXACT, src/matched/unit_0204384C.c.  Archive entry point:
 * allocates the descriptor (line 266), opens the member, and hands the
 * decoded header to func_02043900.  The archive tag is
 * `(heap & 0x7FFF) | 0x8000` narrowed to a halfword. */
struct Bmp *func_0204384C(u32 arc, u32 member, u32 heap2, u32 heap);

/* 0x02043900  EXACT, src/matched/unit_02043900.c.  Fills a descriptor
 * from an archive header record.  NOTE the crossed assignment, which is
 * byte-evidenced and not a typo: width comes from cellsY and height from
 * cellsX. */
struct BmpInfo {
    u16   cellsX;   /* +0x00  -> b->height * 8 */
    u16   cellsY;   /* +0x02  -> b->width  * 8 */
    u32   format;   /* +0x04  3 => depth 0x20, 4 => depth 0x40, anything
                     *        else leaves depth untouched.  A two-case
                     *        `switch`, NOT an if/else chain: the chain
                     *        predicates the first arm in place and is
                     *        four bytes short (unit_02043900's header). */
    u8    pad08[8]; /* +0x08  untouched by unit_02043900 */
    u32   size;     /* +0x10  byte size of the pixel buffer */
    void *src;      /* +0x14  packed source, copied with MIi_CpuCopy32 */
};
void func_02043900(struct Bmp *b, struct BmpInfo *info, u32 heap);

/* 0x020437AC  EXACT, src/matched/func_020437AC.c.  Destructor.  Releases
 * the pixel buffer only when kind == 0, then the descriptor.  The guard
 * is inverted in the image (`bne` over the first release), which is the
 * source order of a plain `if (kind == 0)` with no else. */
void func_020437AC(struct Bmp *bmp);

/* ------------------------------------------------------------------ *
 * Accessors.  All four save no lr, so disasm.py does not label them and
 * they print inside runs of `.word`s (see the unlabelled-leaf idiom).
 * Each is kept in its own file so its callers get a `matched` witness.
 * ------------------------------------------------------------------ */
void *func_020437D4(const struct Bmp *bmp);   /* EXACT, pixels          */
u16   func_020437DC(const struct Bmp *bmp);   /* EXACT, width  (pixels) */
u16   func_020437E4(const struct Bmp *bmp);   /* EXACT, height (pixels) */
u8    func_02043994(struct Bmp *bmp);         /* EXACT, depth as a byte */

/* 0x020437EC  EXACT, src/matched/func_020437EC.c.  Byte size of the
 * pixel buffer.  The exact spelling matters: the first division is an
 * `lsr` because width is an unsigned halfword field, the second an
 * `asr` triple because by then it is dividing an int product. */
u32 func_020437EC(const struct Bmp *bmp);
/*  return bmp->depth * ((bmp->width / 8) * bmp->height / 8);  */

/* 0x02043814  EXACT, src/matched/func_02043814.c.  Copies one bitmap's
 * pixels over another's, clipped to the smaller of the two sizes.  The
 * comparison is `movlo`, so both sizes are u32. */
void func_02043814(struct Bmp *dst, const struct Bmp *src);

/* ------------------------------------------------------------------ *
 * The two dispatchers.  Both are EXACT and both switch the same way:
 * first on the source's kind (+0x0a) `!= 2`, then on the depth (+0x08)
 * `== 0x20`.  The fall-through arm is the source order in both tests.
 * Between them they name all eight workers, and those eight are exactly
 * this family's remaining open functions.
 * ------------------------------------------------------------------ */

/* 0x020439A0  EXACT, src/matched/sub_020439A0.c.  Nine-argument blit
 * dispatcher.  Source and destination must agree on depth before
 * anything happens.
 *
 * THE TWO WORKER FAMILIES HAVE DIFFERENT PROTOTYPES, and that is what
 * the shift pairs in the dispatcher's second arm are.  This is the
 * single most load-bearing declaration in the header, because it fixes
 * the signature of four open functions from EXACT evidence:
 *
 *   the 0x02043B98 family takes all nine arguments WIDE (u32/int) and
 *   needs no re-extension at the call;
 *
 *   the 0x020445F4 family takes the two destination coordinates and the
 *   last two extents as `u16` and the two source coordinates as `s16`,
 *   so all six are re-extended at the call with equal-amount shift
 *   pairs (plain narrowing casts).
 *
 * The dispatcher's OWN parameters must therefore be the wide types: a
 * u16 parameter would arrive already extended and the call would not
 * re-extend it. */
void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y,
                   int sx, int sy, u32 w, u32 h, u32 key);

/* 0x02043AF4  EXACT, src/matched/sub_02043AF4.c.  Six-argument fill
 * dispatcher, the single-bitmap sibling.  Nothing is narrowed here, so
 * the two outgoing stack words are one `stm sp, {r4, lr}` written out
 * in each arm rather than a tail-merged run of `str`s -- which is the
 * evidence that all six parameters, and all four workers', are wide. */
void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);

/* 0x02043AAC  EXACT, src/matched/sub_02043AAC.c.  Ten-argument
 * forwarder onto 0x0204427C.  Its last two arguments are re-read narrow
 * off the home slots: the ninth with a plain `ldrh` (both sides are
 * halfwords) and the tenth with `ldrh` plus `and #0xff` (a halfword
 * parameter narrowed to the callee's byte one).  A word parameter
 * narrowed to a byte would have been a single `ldrb`, so the `ldrh` is
 * what names the incoming width -- this fixes 0x0204427C's last two
 * parameter types from outside. */
void func_02043AAC(struct Bmp *dst, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                   u32 a7, u32 a8, u16 a9, u16 a10);

/* ------------------------------------------------------------------ *
 * THE WORKERS.  As of 2026-09-23 (wave 10) eight of them are EXACT in
 * src/matched, and the prototypes below are the ones those sources compile
 * with.  They supersede the dispatcher-derived guesses this block held
 * before, in three places:
 *
 *   1. THE FIRST SURFACE IS THE ONE READ AND THE SECOND THE ONE WRITTEN.
 *      Every blit loads pixels from r0 and stores through r1; the clip
 *      clamps w/h to r0's extent and tests dx/dy against r1's.  The
 *      dispatcher's (dst, src) names were never evidenced, so they are
 *      called (src, dst) here.
 *   2. THE KEY IS u16 ON THE WORKER SIDE in all five keyed workers: it is
 *      ldrh'd off the stack even where func_020439A0 passes it wide.
 *   3. The fill workers' parameter types differ from worker to worker; each
 *      one is fixed by its own stack loads (ldrh/ldrb/ldr).
 * ------------------------------------------------------------------ */

/* kind != 2 arm of func_020439A0.  Clipped up front by the inlined helper
 * ClipRect (below); u32 extents (movhi/subhi/blo), s32 origins (bge/bgt). */
void func_02043B98(struct Bmp *src, struct Bmp *dst, s32 x, s32 y,
                   s32 dx, s32 dy, u32 w, u32 h, u16 key); /* 4bpp  EXACT */
void func_02043F4C(struct Bmp *src, struct Bmp *dst, s32 x, s32 y,
                   s32 dx, s32 dy, u32 w, u32 h, u16 key); /* 8bpp  EXACT */

/* kind == 2 arm.  Narrow parameters, exactly as the dispatcher's shift
 * pairs spell them (u16 x/y are load-bearing: see the clip temporary
 * below).  The destination is written a HALFWORD at a time. */
void func_020445F4(struct Bmp *src, struct Bmp *dst, u16 x, u16 y,
                   s16 dx, s16 dy, u16 w, u16 h, u16 key); /* 4bpp  EXACT */
void func_02044954(struct Bmp *src, struct Bmp *dst, u16 x, u16 y,
                   s16 dx, s16 dy, u16 w, u16 h, u16 key); /* 8bpp  EXACT */

/* The fill workers, from func_02043AF4.  x, y, w are s32 in all four (the
 * per-pixel `cmp/cmpge/blt` guard is signed); the stack loads fix h and
 * the value. */
void func_02044BF0(struct Bmp *b, s32 x, s32 y, s32 w, u16 h, u32 value);
                                           /* 4bpp nibble, ldr   EXACT */
void func_02044CE0(struct Bmp *b, s32 x, s32 y, s32 w, u16 h, u8 value);
                                           /* 8bpp byte          EXACT */
void func_02044D88(struct Bmp *b, s32 x, s32 y, s32 w, u16 h, u8 value);
                                           /* 4bpp via halfword  EXACT */
void func_02044EBC(struct Bmp *b, s32 x, s32 y, s32 w, u16 h, u8 value);
                                           /* twin of CE0        EXACT */

/* 0x0204427C  4bpp -> 8bpp expanding blit, reached only through
 * func_02043AAC, whose narrowing loads fix the last two types.  The key is
 * only a mode switch (0xFFFF = store every pixel, else skip nibble 0), and
 * pal is added to every non-zero nibble.  EXACT wave 14
 * (src/matched/func_0204427C.c): source pointer before destination in the
 * keyed loop, `v += pal; *p = v;` braced, `xx * 4` in a named temporary,
 * and the keyed source pointer as plain `src->pixels + ...` arithmetic. */
void func_0204427C(struct Bmp *src, struct Bmp *dst, s32 x, s32 y,
                   s32 dx, s32 dy, u32 w, u32 h, u16 key, u8 pal);

/* 0x02044F64  the de-tile entry point.  NOT reached from either
 * dispatcher: docs/notes/pkt_020445F4.c.txt records that it calls
 * func_02043678 with FOUR arguments, func_02043814 and func_020437AC,
 * and returns the new descriptor (or NULL when its second argument is
 * 0, having copied and freed).  The descriptor's extents are recovered
 * as `(u32)(f * 8192) >> 16`, the multiply-then-truncate-to-u16 form,
 * NOT `(u16)(f * 8)` -- the `lsr` rather than `asr` is what forces the
 * cast through u32. */
struct Bmp *func_02044F64(struct Bmp *src, u32 keep, u32 heap);
/* EXACT since wave 12 (src/matched/func_02044F64.c).  SUPERSEDES the
 * `(u32)(f * 8192) >> 16` reading above and the "u32 h" block below: the
 * lsl #13 / lsr #16 pair is just the u16 truncation of an unsigned
 * `/ 8`.  The four extents are u16 LOCALS,
 *     u16 w, h, d, dep;
 *     h = src->height / 8;  w = src->width / 8;
 *     dep = src->depth;     d = dep / 8;
 * assigned in exactly that order (h before w is what colours f04 into r3
 * and f06 into r4; declaration order is inert).  All-u16 with w first
 * leaves 13 bytes; the old s32/u32 mix was capped at 6. */

/* ------------------------------------------------------------------ *
 * The clear helper, src/matched/sub_02043B5C.c (EXACT).  Fills a whole
 * bitmap with one pixel value.  The byte count is the tile count times
 * the per-tile size at +8; in the 4bpp case the value is a nibble and
 * is replicated into both halves of the byte first.  This is the one
 * matched function that reads the depth field arithmetically rather
 * than as a two-way switch, which is what evidences depth being a byte
 * COUNT and not an enum. */
void sub_02043B5C(struct Bmp *bmp, u8 value);

/* ------------------------------------------------------------------ *
 * Externals the family depends on, with the evidence for each.
 * ------------------------------------------------------------------ */
extern const char bmp_File[];   /* 0x020A7E68 data, "bmp.c"; every
                                 * constructor's __FILE__ argument */

/* 0x02030734 arm -- the heap allocator.  (heap, size, clear, file, line);
 * the third argument is 0 for the descriptor and 1 for the pixel buffer
 * in func_02043678, so it is a clear-on-allocate flag. */
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file,
                           u32 line);
extern void  func_020307B0(void *p);          /* 0x020307B0 arm, free   */
extern void  MIi_CpuCopy32(const void *src, void *dst, u32 size);
                                              /* 0x02082A90 arm.  NOTE
                                               * func_02043814 calls the
                                               * same address with
                                               * (dst, src, size) -- the
                                               * two matched sources
                                               * disagree on argument
                                               * order and only
                                               * unit_02043900's spelling
                                               * is SDK-named. */
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);  /* 0x02082BCC */
extern void  OS_Terminate(void);                          /* 0x02088234 */

/* The four divisions in func_02044F64 are SIGNED: `_s32_div_f` at
 * 0x0209C0A4 resolves on the `runtime` class via
 * layout/runtime_arm9.txt, while u32 dimensions would emit
 * `_u32_div_f`, which has no address and leaves four sites unresolved.
 * `/` and `%` on the same pair are two separate calls.
 *
 * NOTE (2026-09-22): the `runtime` class only fires on a name the file's
 * own `symbols:` block declares.  A source that calls `/` on s32 without
 * the line
 *     _s32_div_f      0x0209C0A4  arm
 * in its header gets four "unresolved: no address for '_s32_div_f'" sites,
 * which reads like an evidence wall and is only a missing declaration.  All
 * seven of func_02044F64's relocation sites resolve once it is present. */

/* ------------------------------------------------------------------ *
 * THE FOUR-BYTE PIXEL EXTENT, and the one local whose SIGNEDNESS is
 * load-bearing (2026-09-22, docs/notes/pkt_020445F4.c.txt).
 *
 * func_02044F64 recovers both extents with the same expression, but the
 * two recovered values do NOT have the same type.  The tile-grid WIDTH is
 * consumed as a signed int; the tile-grid HEIGHT is consumed UNSIGNED:
 *
 *     s32 i, d, dep, w, n;
 *     u32 h;                            <- this, and only this
 *     w = (u32)(src->f04 * 8192) >> 16;
 *     h = (u32)(src->f06 * 8192) >> 16;
 *
 * Declaring h as s32 costs 8 concrete bytes (14 out instead of 6) and is
 * what makes the compiler colour `dep` and the `w * d` product into each
 * other's registers.  The other three signedness combinations of w and h
 * measure 14, 40 and 40.  Declaration order, which an earlier pass called
 * "the whole register allocation here" after a 720-permutation sweep, is
 * INERT once h is unsigned.
 *
 * The cast through u32 in BOTH expressions is still required for the
 * `lsr` (see the func_02044F64 entry above); the u32 declaration of h is a
 * separate and additional fact about the local, not about the expression.
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * THE SIX BLIT/FILL WORKERS ARE dsi/1.1p1, NOT A PINNED FRONT END
 * (2026-09-22).  The workers push ten registers where a 1.1p1 build of
 * the best known source pushes eight, and "push list one register wider
 * than the image" is a recognised compiler-pin tell elsewhere in the
 * tree.  It is NOT one here; the hypothesis was measured and refused on
 * every worker with a usable source:
 *
 *   function      1.1p1        ../2.0/sp2    ../1.2/sp2
 *   0x02044CE0    168 / 85     188 / 135     204 / 185
 *   0x02044F64    292 /  6     292 /  14     292 / 131
 *   0x02044BF0    208 / 188    260 / 217     --
 *   0x02044D88    312 / 272    356 / 313     384 / 342
 *
 * (compiled size / concrete bytes out; the originals are 168, 292, 240
 * and 308.)  1.1p1 is the only front end that reproduces any of the
 * sizes.  The `mov fp, #0xf0` held across both arms at 0x02044E00 in
 * func_02044D88 looks like the documented "kept constants" 2.0 tell and
 * is not: under ../2.0/sp2 that function is 44 bytes longer and 41 bytes
 * worse.  No pin is taken for this family and none should be sought.
 *
 * The push width is nonetheless REACHABLE from C: 1.1p1 emits the
 * image's ten-register push as soon as the function carries one more live
 * value.  The open problem is getting the tenth register while keeping
 * the other nine coloured correctly, not getting it at all.
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * THE CLIPPING GUARD IS SIGNED IN ALL FOUR FILL WORKERS, which rules out
 * an unsigned inner loop counter however much shorter it compiles
 * (2026-09-22).  Each worker clips right and bottom before the loops but
 * tests left and top PER PIXEL, as the triple
 *
 *     cmp  rX, #0
 *     cmpge rY, #0
 *     blt  <skip>
 *
 * (0x02044D40, 0x02044C70, 0x02044E04 and the 0x02044EBC twin).  A `u32`
 * or otherwise unsigned loop counter folds `x >= 0` away and collapses the
 * triple to a single unsigned `cmp`/`bhs`, which is a different function.
 * On func_02044D88 that change happens to hit the original's size exactly
 * (308 bytes, and 204 out against the signed source's 272), so it is a
 * trap rather than a lever: check for the `cmpge` triple before accepting
 * any signedness change to a loop counter in this family.
 * ------------------------------------------------------------------ */


/* ------------------------------------------------------------------ *
 * THE ADDRESS LEVER THAT CLOSED SIX WORKERS (2026-09-23, wave 10).
 *
 * Every worker addresses a pixel as ONE INTEGER SUM over the pixel
 * pointer cast to u32, evaluated inside the guarded inner body.  Only the
 * tile-row mask is lifted into a function-scope local:
 *
 *     tileY = (i * 8) & 0x7fc0;                     (4bpp: *4, 0x3fe0)
 *     *(u8 *)((u32)s->pixels + (j & 7) + ((j * 8) & 0x7fc0)
 *             + tileY * tilesWide + ((i * 8) & 0x38)) = value;
 *
 * LICM then hoists the tile-row product and the in-tile row into the
 * inner loop's preheader, after the entry test, which is where the image
 * computes them.  It does NOT fold the two into one mla there.  Every
 * pointer-arithmetic, subscript or per-row-local spelling lets it fold
 * them (func_02044CE0: 79-81 out) or computes them before the entry test.
 * The ten-register push and the fp use follow once the fold is gone.
 * Both spellings were compiled and compared; see the func_02044CE0 source.
 *
 * Refinements, each measured on the function named:
 *   - where the image addresses [p, row] (base = pointer, index = the
 *     in-tile row), the row is added to the pointer as a second statement
 *     `p += row` (func_02044BF0, 6 -> 0).  A fifth term of the sum gives
 *     [row, p], which is the func_02044CE0/func_02043F4C store shape;
 *   - ONE TILE-ROW LOCAL PER ADDRESS PER LOOP.  The two-loop workers
 *     (plain and keyed copies) need four: sharing a pair across the two
 *     loops costs about 150 bytes of allocation (func_02044954: 149 vs 4);
 *   - where both a source and a destination address exist, the SOURCE
 *     tile-row local is assigned first so the preheader computes the
 *     source row/product first (func_02043B98, 100 -> 0).
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * THE CLIP HELPER of the kind != 2 blits and func_0204427C (EXACT in
 * func_02043B98 and func_02043F4C).  Inlined: the image's `mov r4,#0` /
 * `mov r4,#1` / `cmp r4,#0` is its return value.  The spelling that
 * matches:
 *
 *   static inline s32 ClipRect(struct Surf *src, const struct Surf *dst,
 *                              s32 *x, s32 *y, s32 *dx, s32 *dy,
 *                              u32 *w, u32 *h)
 *   {
 *       u32 ch = *h;            <- *h BEFORE *w (88 out the other way)
 *       u32 cw = *w;
 *       if (cw > src->width) cw = src->width;
 *       if (*dx >= dst->width || *dx <= -(s32)cw) return 0;
 *       ...same for y...
 *       if (*dx < 0) { cw += *dx; *x -= *dx; *dx = 0; }
 *       else if (*dx + cw > dst->width) cw -= *dx + cw - dst->width;
 *       ...same for y...
 *       *w = cw; *h = ch; return 1;
 *   }
 *
 * The `const` on dst is load-bearing and counter-intuitive: without it
 * the compiler keeps dst->width live across the clip and does not re-read
 * it for the row stride (812 bytes against 816).
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * THE CONDITIONAL-ADD OPERAND ORDER of the kind == 2 blits (func_020445F4,
 * func_02044954; 4 bytes each).  The image computes
 *
 *     t = dst->width - dx;  xend = (t < w) ? x + t : w + x;
 *
 * as `add fp, r2, r5` / `addge fp, r6, r2`.  Writing the difference into
 * xend itself and then `xend = x + xend` makes the compiler put the reused
 * variable first (`add fp, r5, r2`) whatever the source operand order.
 * The fix is a fresh temporary t, and on func_02044954 ONLY together with
 * u16 x/y parameters (fresh t with s32 x/y: 167 out).
 * ------------------------------------------------------------------ */

#endif /* BMP_H */
