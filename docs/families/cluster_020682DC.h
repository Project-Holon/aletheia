/*
 * docs/families/cluster_020682DC.h -- shared declarations for the
 * pseudo-family cluster_020682DC (0x020682DC..0x02068E78 in the ARM9 image).
 *
 * PSEUDO-FAMILY.  No __FILE__ anchor reaches this part of the image, so the
 * cluster is formed by address adjacency plus one shared object (the tiled
 * surface below) and a closed callee set.  It is the glyph / fill back end of
 * a 2D text renderer that draws into VRAM-style 8x8 character tiles:
 *
 *   func_020682DC   2-D lookup into the four-word row table at 0x020A1914
 *   func_020682F8   masked fill of a sub-rectangle of ONE tile (4 or 8 bpp)
 *   func_02068430   bit-stream glyph blit into ONE tile
 *   func_02068670   glyph draw on a LINEAR tile grid (drives 0x02068430)
 *   func_02068808   glyph draw on a SWIZZLED tile grid (drives 0x02068430)
 *   func_02068A18   clear a linear surface to one pixel value
 *   func_02068A68   the same, row by row with a row stride
 *   func_02068AE8   fill a rectangle on a linear tile grid (drives 0x020682F8)
 *   func_02068C84   fill a rectangle on a swizzled tile grid (drives 0x020682F8)
 *   (func_02068E78, func_02068EA0 continue the same object one packet up)
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and match.py never sees it.  Every declaration below is
 * taken from an EXACT file in src/matched (named beside it) or, where marked
 * NOT BYTE-ATTESTED, from a DIFF note.  Addresses are Black-image addresses.
 *
 * STATUS (wave 8, 2026-09-22):
 *   EXACT  func_020682DC (1.1p1), func_020682F8 (../2.0/sp2 pin),
 *          func_02068A18 (1.1p1), func_02068A68 (1.1p1),
 *          func_02068EA0 (../2.0/sp2 pin, earlier wave)
 *   DIFF   func_02068430 576/195 (2.0), func_02068670 408/254 (1.1p1),
 *          func_02068AE8 412/245, func_02068C84 500/72 (2.0),
 *          func_02068808 not attempted this wave, func_02068E78 (see note)
 *   Notes: docs/notes/pkt_020682F8.c.txt, docs/notes/pkt_02068808.c.txt.
 * WAVE 9 (2026-09-22): func_02068C84 500/8 under ../2.0/sp2 (was 72), the
 *   last 8 one `stm`/`sub` scheduling pair; func_02068AE8's loop header
 *   now byte-identical (but 416/227, bpp/tile-size spill swapped); 0x430 and
 *   0x670 unchanged (0x670 is one spill choice: the image spills the glyph
 *   pair argument to its own incoming slot, every compile spills base).
 *
 * FRONT END.  Mixed, decided per function by the tells in
 * docs/FRONTEND-PINS.md, never by family.  0x020682F8 is "kept branches" (a
 * real `blo` over each four-instruction >= 32 shift block), 0x02068430 shows
 * the same tell (a `bhs` / `b` if/else inside its 8bpp column loop) and is
 * size-exact only under the pin, 0x02068C84 is closest under the pin; the
 * A18/A68 pair is 1.1p1 and so is 0x020682DC.  Try both on every new row.
 */

#ifndef CLUSTER_020682DC_H
#define CLUSTER_020682DC_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

/* ================================================================== *
 * 1. The surface
 * ================================================================== */

/* The drawing target every function here takes as its first argument.
 * src/matched/func_02068A18.c and func_02068A68.c pin +0x00..+0x10:
 *   +0x00 base   the tile (or pixel) buffer
 *   +0x04 w      width  -- in tiles for the tile-grid functions
 *   +0x08 h      height -- ditto; func_02068A68 re-reads it every row
 *                (the fill call may alias it) and compares it SIGNED
 *   +0x0C bpp    u8, 4 or 8; `(bpp << 6) / 8` is the byte size of one tile
 *                and is always written that way (the image divides with
 *                the asr/add-lsr#29/asr#3 signed-division triple)
 *   +0x10 stride tiles per row on the linear grid.  On the SWIZZLED grid
 *                (0x02068C84, 0x02068808) the same word is a bitfield pair,
 *                NOT BYTE-ATTESTED but measured in docs/notes/pkt_02068808.c.txt:
 *                a whole-struct copy into a local (the image's otherwise dead
 *                `str` of the word) whose bytes 0 and 1 are the two extra
 *                arguments of the swizzle callee func_020681E4.
 * func_02068670 compares w/h UNSIGNED against a tile count, so they are u32
 * there; func_02068A68's row loop compares h signed.  Both files are
 * right for their own code; the field is a plain 32-bit word. */
struct Surface {
    char *base;     /* +0x00 */
    int   w;        /* +0x04 */
    int   h;        /* +0x08 */
    u8    bpp;      /* +0x0C */
    int   stride;   /* +0x10 */
};
struct Swz { u32 x : 8; u32 y : 8; u32 rest : 16; };  /* +0x10, swizzled view */

/* ================================================================== *
 * 2. The pixel expansion -- THE family lever
 * ================================================================== */

/* Every fill in this cluster expands a pixel value to a whole word first:
 * 4bpp doubles the nibble, both double the byte, both double the halfword.
 * The ONLY spelling that reproduces the image (orreq/orreq/orrne into one
 * temporary, then `orr <param reg>, t, t, lsl #16`) is the <<16 step written
 * in BOTH arms, which the compiler tail-merges back out:
 *
 *     if (bpp == 4) { t = arg | (arg << 4); t = t | (t << 8); arg = t | (t << 16); }
 *     else          { t = arg | (arg << 8); arg = t | (t << 16); }
 *
 * src/matched/func_02068A18.c and func_02068A68.c.  Written once after the
 * join, the shared `| (x << 8)` is tail-merged instead (4 bytes short); the
 * default-then-override form an earlier pass found is 4 bytes short too. */

/* ================================================================== *
 * 3. Callees
 * ================================================================== */

/* 0x02082AC0 is MIi_CpuClearFast(data, dest, size) in the SDK symbol map
 * (layout/symbols_sdk.json).  Called with the expanded word first. */
extern void func_02082AC0(u32 data, void *dst, int size);   /* func_02068A18 */

/* Single-tile masked fill.  dst = the tile, (x, y) the sub-rectangle's
 * offset inside it, (w, h) its extent, val the expanded word, bpp 4 or 8.
 * A whole tile (w == 8 && h == 8) goes to func_02082AC0 in one call.
 * src/matched/func_020682F8.c (../2.0/sp2). */
extern void func_020682F8(u32 *dst, int x, int y, int w, int h,
                          u32 val, int bpp);

/* The MSB-first bit reader of docs/notes/func_02069BA0.c.txt (DIFF there,
 * not in src/matched): a 6-byte cursor {u8 *cur; s8 have; u8 acc;} and
 * func_02069BA0(b, n) returns the next n bits.  func_02068430 opens one per
 * row at `src + ((u32)bit >> 3)` with have = acc = 0 and discards `bit % 8`
 * bits first.  NOT BYTE-ATTESTED. */
typedef struct Bits { u8 *cur; signed char have; unsigned char acc; } Bits;
extern u32 func_02069BA0(Bits *b, int n);

/* The ten-word parameter block func_02068670 / func_02068808 build on their
 * stack and hand to func_02068430 by pointer.  NOT BYTE-ATTESTED (both ends
 * are DIFF), but the two sides' offsets agree field for field. */
struct Blit {
    u32 *dst;      /* +0x00  the tile */
    u8  *src;      /* +0x04  glyph bits, the out[1] of func_02068EA0 */
    int  x;        /* +0x08  glyph column offset relative to the tile */
    int  y;        /* +0x0C  glyph row offset relative to the tile */
    int  w;        /* +0x10  glyph width  (out[0][1]) */
    int  h;        /* +0x14  glyph height (font header byte 1) */
    int  stride;   /* +0x18  source row in bits: header bpp * cell width */
    int  sbpp;     /* +0x1C  source bits per pixel (font header byte 6) */
    int  bpp;      /* +0x20  destination bpp (surface +0x0C) */
    int  base;     /* +0x24  palette base, the caller's colour - 1 */
};
extern void func_02068430(struct Blit *p);

/* Row lookup, EXACT (1.1p1): `return g_020A1914[p[1]][p[0]];` with a
 * four-word row.  src/matched/func_020682DC.c. */
extern u32 func_020682DC(u8 *p);

/* The two fillers, EXACT (1.1p1).  A68 also needs `dst = s->base` AFTER the
 * two products and a signed `for (i = 0; i < s->h; i++)`. */
extern void func_02068A18(struct Surface *s, u32 arg);
extern void func_02068A68(struct Surface *s, u32 arg);

/* Rectangle fills (DIFF).  (s, pixel, x, y, w, h): the rectangle is rounded
 * out to whole tiles and each covered tile gets func_020682F8 with its own
 * sub-rectangle.  The linear one walks `row += stride * tilesz`; the swizzled
 * one asks func_020681E4(tx, ty, s->w, s->h, swz.x, swz.y) for each tile's
 * index.  Both want `yo = (cy < y) ? y - cy : 0`, and both images keep that
 * as a real branch the compilers here predicate. */
extern void func_02068AE8(struct Surface *s, u32 arg, int x, int y, int w, int h);
extern void func_02068C84(struct Surface *s, u32 arg, int x, int y, int w, int h);

/* ================================================================== *
 * 4. The tile-walk loop (wave 9, measured on func_02068C84, carries to
 *    func_02068AE8's loop header)
 * ================================================================== */

/* Per row, in this order:
 *     yo = (cy < y) ? y - cy : 0;      -- cy LEFT of the compare; this is
 *                                         what keeps the image's real
 *                                         `movge rY, #0 / bge` branch
 *     tx = tx0;   (or p = row;)        -- AFTER yo, not in a declaration
 *     t = y1 - cy; if (t > 8) t = 8;   -- clamp in a temporary ...
 *     th = t - yo;                     -- ... then a separate th
 * and the loop registers are colored in DECLARATION ORDER at function
 * scope: C84 `int cx, th, tx, xe, ty;` gives r4..r8 exactly (the only one
 * of all 120 orders that does); AE8's `cx, th, xe, p, yo` does the same. */

#endif /* CLUSTER_020682DC_H */
