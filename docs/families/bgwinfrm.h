/*
 * docs/families/bgwinfrm.h -- shared declarations for the bgwinfrm.c family
 * (background window / frame records), 0x0202C9B4..0x0202D1E0 in the ARM9
 * image.  Edges are fuzzy by a function or two at both ends.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  It is the adjudicated
 * union of the declarations the family's byte-exact sources already carry,
 * written down once so a new attempt on an open function starts from the
 * settled shape instead of re-deriving it.
 *
 * Derived from the 30 matched sources found with
 *   grep -l "address:  0x0202C[9A-F]\|address:  0x0202D[01]" src/matched/*.c
 * Each declaration names the matched function that evidences it.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load instruction constrains a field
 * and a name does not.  `ldrb [r,#N]` fixes a byte at exactly +N; `ldrsb`
 * at a REGISTER offset proves s8 (there is no immediate-offset ldrsb --
 * docs/idioms/ldrsh-register-offset-is-signedness.md, same tell for bytes);
 * an unequal shift pair proves a bitfield's width
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 */

#ifndef BGWINFRM_H
#define BGWINFRM_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * THE WINDOW RECORD, 0x10 bytes.  The stride is not inferred: it is
 * `lsls r1, r1, #4` in func_0202CFEC, func_0202CD64 and func_0202CDD4,
 * i.e. index * 0x10 with no multiply at all.
 *
 * THE +0x04 HALFWORD IS FOUR BITFIELDS, NOT TWO BYTES.  func_0202CD64
 * writes unk04_13 alone and leaves the rest, and func_0202CEBC reads `w`
 * and `h` as independent 6-bit values off the same halfword; a byte pair
 * at +0x04/+0x05 cannot produce either access.  w and h are 6 bits each
 * because the masks are 0x3f, which caps a window at 63x63 tiles.
 *
 * THE FOUR SIGNED BYTES AT +0x08..+0x0b.  func_0202CFEC is the file that
 * fixes their signedness: it reads the two stacked arguments with
 * `ldrsb r4,[r3,r2]` at a REGISTER offset, which only exists for signed
 * bytes.  x/y are the window's origin, dx/dy the per-frame scroll delta
 * that func_0202CD64 arms.
 * ------------------------------------------------------------------ */
struct Win {
    u16 *tiles;                 /* +0x00  the tilemap entry buffer.
                                 *        func_0202CEBC indexes it by
                                 *        stride * y + col as u16, which is
                                 *        what proves the element width;
                                 *        func_0202CD64 spells the same
                                 *        field u32 where it only stores
                                 *        through it                      */
    u16 w:6;                    /* +0x04  bits 0-5   func_0202CEBC bounds
                                 *        the column loop with it         */
    u16 h:6;                    /* +0x04  bits 6-11  func_0202CEBC bounds
                                 *        the row loop with it            */
    u16 dirty:1;                /* +0x04  bit 12                          */
    u16 unk04_13:3;             /* +0x04  bits 13-15  func_0202CD64 sets
                                 *        it to 1 when it arms the scroll */
    s8  x;                      /* +0x06                                  */
    s8  y;                      /* +0x07                                  */
    s8  dx;                     /* +0x08  func_0202CD64, func_0202CFEC    */
    s8  dy;                     /* +0x09  func_0202CD64, func_0202CFEC    */
    u8  bg;                     /* +0x0a  the layer this window draws to;
                                 *        handed to func_02041300         */
    u8  frames;                 /* +0x0b  func_0202CD64's frame count      */
    s8  xmin;                   /* +0x0c                                  */
    s8  xmax;                   /* +0x0d                                  */
    s8  ymin;                   /* +0x0e  func_0202CFEC writes +0x0e/+0x0f */
    s8  ymax;                   /* +0x0f  as the two stacked s8 arguments  */
};

/*
 * CAUTION, TWO SPELLINGS OF +0x0c..+0x0f IN THE MATCHED SET.  func_0202CD64
 * and func_0202CEBC name them xmin/xmax/ymin/ymax; func_0202CFEC writes the
 * same four bytes as a/b/c/d with no clipping reading attached.  They are
 * the same four bytes and the same signedness; only the naming differs, and
 * no matched file yet proves the clip-rectangle reading.  Treat the names
 * as provisional and the offsets and widths as settled.
 */

/* ------------------------------------------------------------------ *
 * THE MANAGER.  func_0202CFEC's `ldr r4,[r0]` before every store is what
 * proves `wins` is a POINTER held in the manager, re-read per access, and
 * not an array embedded in it: writing the four stores through a cached
 * base costs six bytes and loses the function.
 * ------------------------------------------------------------------ */
struct WinMgr {
    struct Win *wins;           /* +0x00  func_0202CFEC, func_0202CD64,
                                 *        func_0202CEBC                   */
    u16 pad_04;                 /* +0x04                                  */
    u16 mode:15;                /* +0x06  bits 0-14                       */
    u16 unk06_15:1;             /* +0x06  bit 15   func_0202CD64 raises it
                                 *        after arming a scroll: a "the
                                 *        manager has work" flag          */
};

/*
 * Three matched files (func_0202CEBC among them) declare struct WinMgr with
 * the `wins` pointer ALONE and no +0x04/+0x06 members, because they never
 * touch them.  That is not a second object: it is the same manager seen by
 * a file that only needs the first word.  The four-member spelling above is
 * preferred because func_0202CD64 constrains bit 15 of +0x06 directly.
 */

/* ------------------------------------------------------------------ *
 * A GLYPH / SPRITE SOURCE, read only through accessors.  func_0202CEBC is
 * the constraining file: it never dereferences the pointer itself, it asks
 * the six func_020457xx accessors below for every value.  So the struct is
 * genuinely opaque to this family and must NOT be given a layout here.
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * HELPER PROTOTYPES.  Parameter widths matter: a helper's parameter
 * declared u8 instead of int changes the CALLER's masking.  Each spelling
 * below is the one its matched caller compiles against.
 * ------------------------------------------------------------------ */

/* In-family. */
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
extern void sub_0202CC58(struct WinMgr *mgr, u32 idx);
extern u32  func_0202CDD4(struct WinMgr *mgr, u32 idx);

/* Arms the scroll on one window: delta pair plus a frame count.  The two
 * s8 parameters and the u8 count are what force the caller's sign- and
 * zero-extension at the call site. */
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy,
                          u8 frames);

/* Writes the four clip/extent bytes at +0x0c..+0x0f.  Arguments 5 and 6 are
 * STACKED and signed; see the struct note above. */
extern void func_0202CFEC(struct WinMgr *mgr, u32 idx, u8 a, u8 b,
                          s8 c, s8 d);

/* The six glyph-source accessors, all ARM, all taking the opaque source.
 * func_0202CEBC calls all six in this order, and the order is load-bearing:
 * it is what fixes the register assignment across the whole loop nest. */
extern u32 func_02045768(void *a);   /* base tile number                  */
extern u32 func_02045778(void *a);   /* palette/attribute bits; the caller
                                      * folds them with << 0x1c >> 0x10   */
extern s32 func_02045738(void *a);   /* width  in tiles, SIGNED (loop bound,
                                      * tested > 0 then used as a limit)  */
extern s32 func_02045740(void *a);   /* height in tiles, SIGNED, same tell */
extern u32 func_02045758(void *a);   /* origin x                          */
extern u32 func_02045760(void *a);   /* origin y                          */

/* Allocator and the bg_sys bridge, outside the family but used throughout. */
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file,
                           u16 line);
extern void  func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5,
                           u32 a6);
extern void  func_02041300(u32 bg, int a1, u8 sx, u8 sy, u8 ow, u8 oh,
                           u32 mode);

/* ------------------------------------------------------------------ *
 * GLOBALS
 * ------------------------------------------------------------------ */
extern void (*g_020A0058[])(u32);   /* a small dispatch table indexed by the
                                     * manager's mode; func_0202CC70's note
                                     * in docs/notes/func_0202CC70.c.txt
                                     * calls through it as the last
                                     * statement of the redraw path        */
extern const char bgwinfrm_File[];  /* the "bgwinfrm.c" __FILE__ anchor
                                     * passed to func_02030734             */

#endif /* BGWINFRM_H */
