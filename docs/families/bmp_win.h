/*
 * docs/families/bmp_win.h -- shared declarations for the bmp_win.c family
 * (bitmap windows over a BG layer), 0x02045088..0x020457A0 in the ARM9
 * image.  The __FILE__ anchor is str_020A7E70 "bmp_win.c", loaded by
 * sub_02045088 (line 0x4f), sub_02045210 (line 0xd5) and sub_02045374
 * (lines 0x133 / 0x13e).  It sits between bmp.c (ends at 0x02045088 with
 * the de-tile entry func_02044F64) and whatever follows 0x020457A0.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Written 2026-09-23
 * (wave 12) from the family's EXACT sources:
 *
 *   sub_02045088  sub_020450C8  sub_020450F0  sub_02045180  sub_02045210
 *   sub_020452E8  sub_02045334  sub_02045374  sub_020456F8
 *   unit_02045730 (fourteen 8-byte accessors 0x02045730..0x020457A0)
 *
 * Open in the range: func_020454E0 (the frame drawer, 536 bytes, DIFF at
 * 2 bytes, docs/notes/pkt_020454E0.c.txt).
 *
 * ADJUDICATION RULE, as in bg_sys.h and bmp.h: a load or store instruction
 * constrains a field and a name does not.  Where two matched files name a
 * field differently, the byte evidence below says which reading wins.
 */

#ifndef BMP_WIN_H
#define BMP_WIN_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Bmp;                     /* docs/families/bmp.h, 12 bytes */

/* ------------------------------------------------------------------ *
 * THE HEAP RECORD at 0x02146A50.
 *
 * sub_02045088 allocates four bytes on the caller's heap, publishes the
 * pointer in g_02146A50 and writes the heap id into its first halfword;
 * sub_020450C8 frees it and NULLs the pointer.  Every later allocation in
 * the family reads the halfword back: sub_02045210 passes `*g_02146A50`
 * as is (u16 heap parameter), sub_02045374 passes
 * `(u16)((*g_02146A50 & 0x7fff) | 0x8000)` (allocate from the heap's
 * far end).
 * ------------------------------------------------------------------ */
extern u16 *g_02146A50;                 /* 0x02146A50 data */
extern const char str_020A7E70[];       /* 0x020A7E70 "bmp_win.c" */

/* ------------------------------------------------------------------ *
 * THE WINDOW DESCRIPTOR, sixteen bytes (sub_02045210 allocates 0x10).
 *
 *   +0x00  u16  tag : 15 = 0x7fb2 (one 15-bit field: two narrower fields
 *               give two read-modify-writes, sub_02045210);
 *               is8bpp : 1 (sub_020452E8 extracts it with lsl #16 /
 *               lsrs #31, which only a 1-bit bitfield produces)
 *   +0x02  u8   layer        BG layer 0..7.  Every file: sub_02045334,
 *                            sub_02045374, sub_020456F8, func_020454E0
 *                            pass it as the first argument of a bg_sys.c
 *                            call; sub_02045730 returns it.
 *   +0x03  u8   x            tilemap X of the window.  sub_02045210 names
 *   +0x04  u8   y            these screenBase/charBase after its caller's
 *                            argument slots, but every reader uses them as
 *                            coordinates: sub_02045374 hands them to
 *                            func_020410D0 as the destination x/y, and
 *                            func_020454E0 draws its frame at x-1 / y-1.
 *                            The coordinate reading wins.  Setters
 *                            sub_02045780 / sub_02045788.
 *   +0x05  u8   width        the BITMAP's width and height in tiles:
 *   +0x06  u8   height       sub_02045210 passes them to func_02043678,
 *                            sub_020452E8 / sub_02045334 size the VRAM
 *                            reservation as width * height * 32 (x2 for
 *                            8bpp).  u8 PARAMETERS in sub_02045210: a u32
 *                            parameter narrowed into both +5 and +7 costs
 *                            an `and #0xff` the image does not have.
 *   +0x07  u8   dispWidth    the on-screen extent, initialised to +5/+6
 *   +0x08  u8   dispHeight   by sub_02045210; sub_02045374 passes +7/+8
 *                            to func_020410D0 as the rectangle and
 *                            func_020454E0 draws the frame around them.
 *                            Setter sub_02045790 on +8.
 *   +0x09  u8   palette      sub_02045374: (pal & 0xf) << 12 into every
 *                            16-colour cell.  Setter sub_02045798.
 *   +0x0a  u16  charOffset   first tile number of the window's character
 *                            run (sub_02045374 counts up from it;
 *                            sub_02045334 / sub_020452E8 pass it back to
 *                            the bg_sys.c VRAM arena).
 *   +0x0c  struct Bmp *bmp   THE BITMAP, not a heap handle.  sub_02045210
 *                            stores func_02043678's result here,
 *                            sub_020452E8 releases it with func_020437AC
 *                            (bmp.c's destructor) and sub_02045334 reads
 *                            its pixels with func_020437D4 (bmp.c's
 *                            pixels getter).  unit_02045730's comment
 *                            calling it a "heap handle" predates bmp.h.
 * ------------------------------------------------------------------ */
struct BmpWin {
    u16         tag    : 15;
    u16         is8bpp : 1;
    u8          layer;
    u8          x;
    u8          y;
    u8          width;
    u8          height;
    u8          dispWidth;
    u8          dispHeight;
    u8          palette;
    u16         charOffset;
    struct Bmp *bmp;
};

/* ------------------------------------------------------------------ *
 * Lifetime.
 * ------------------------------------------------------------------ */
void sub_02045088(u16 heapId);                          /* EXACT */
void sub_020450C8(void);                                /* EXACT */

/* The shared constructor.  The allocator's tile size is 0x20 for 4bpp,
 * 0x40 for 8bpp (`is8bpp == 0 ? 0x20 : 0x40`). */
struct BmpWin *sub_02045210(u32 layer, u32 x, u32 y, u8 width, u8 height,
                            u8 palette, u32 charOffset, u8 is8bpp);

/* The two front doors onto it, differing only in how the VRAM run is
 * reserved: sub_020450F0 asks func_0203FA08 for room (byte size, failure
 * -1), sub_02045180 reserves a caller-chosen offset with func_0203FAF0
 * (unit count, failure 0).  Both ask func_0204169C whether the layer is
 * 8bpp and double the unit count if so. */
u32 sub_020450F0(u32 layer, u32 x, u32 y, u32 width, u8 height, u8 palette,
                 u8 slot);                              /* EXACT */
u32 sub_02045180(u32 layer, u32 x, u32 y, u32 width, u8 height, u8 palette,
                 u32 offset);                           /* EXACT */

/* Destructor: release the VRAM run, the bitmap, then the descriptor.  The
 * undoubled size is the `if` arm and the doubled one the `else` (both arms
 * compute the u8 * u8 product, hence the two predicated smulbb). */
void sub_020452E8(struct BmpWin *w);                    /* EXACT */

/* Upload the bitmap's pixels to the layer's character run:
 * sub_02040B1C(layer, func_020437D4(w->bmp), width * height *
 * sub_020416B8(layer), charOffset).  The product is taken before the
 * getter call, which is what buys the callee-saved register. */
void sub_02045334(struct BmpWin *w);                    /* EXACT */

/* Write the window's tilemap: a scratch run of consecutive tile numbers
 * starting at charOffset (u16 cells with the palette nibble for 4bpp
 * layers, u8 cells when func_02041680 answers 1), blitted with
 * func_020410D0 at (x, y, dispWidth, dispHeight).  The two allocation
 * sites carry different __LINE__ values (0x133 / 0x13e); giving them the
 * same one hoists the pool load. */
void sub_02045374(struct BmpWin *w);                    /* EXACT */

/* The eight-piece frame around the window, base tile + 0..7 skipping the
 * centre, each one func_02041300 fill with mode 0x11.  func_02041680 == 1
 * (8bpp) means no palette bits.  DIFF at 2 bytes: see the note. */
void func_020454E0(struct BmpWin *w, u32 base, u32 pal);

/* Clear the window's tilemap rectangle: func_02041300(layer, 0, x, y,
 * width, height, 0). */
void sub_020456F8(struct BmpWin *w);                    /* EXACT */

/* ------------------------------------------------------------------ *
 * The accessor bank, unit_02045730 (EXACT as one tu).  Each is 8 bytes
 * and saves nothing, so disasm.py only labels some of them; the three
 * setters sub_02045780/88/90 are unlabelled followers already reported
 * for layout/function_starts.txt.
 * ------------------------------------------------------------------ */
u8          sub_02045730(struct BmpWin *w);   /* layer      */
u8          sub_02045738(struct BmpWin *w);   /* width      */
u8          sub_02045740(struct BmpWin *w);   /* height     */
u8          sub_02045748(struct BmpWin *w);   /* dispWidth  */
u8          sub_02045750(struct BmpWin *w);   /* dispHeight */
u8          sub_02045758(struct BmpWin *w);   /* x          */
u8          sub_02045760(struct BmpWin *w);   /* y          */
u16         sub_02045768(struct BmpWin *w);   /* charOffset */
struct Bmp *sub_02045770(struct BmpWin *w);   /* bmp        */
u8          sub_02045778(struct BmpWin *w);   /* palette    */
void        sub_02045780(struct BmpWin *w, u8 v);   /* x          */
void        sub_02045788(struct BmpWin *w, u8 v);   /* y          */
void        sub_02045790(struct BmpWin *w, u8 v);   /* dispHeight */
void        sub_02045798(struct BmpWin *w, u8 v);   /* palette    */

/* ------------------------------------------------------------------ *
 * bg_sys.c / bmp.c entry points the family calls, with the prototypes
 * its EXACT sources compile against.
 * ------------------------------------------------------------------ */
extern void *func_02030734(u16 heap, u32 size, u32 clear, const char *file,
                           u32 line);                   /* allocator */
extern void  func_020307B0(void *p);                    /* free      */
extern u32   func_02041680(u32 layer);   /* 1 = 8bpp layer (sub_02045374) */
extern u32   func_0204169C(u32 layer);   /* != 0 = 8bpp (sub_020450F0)    */
extern u32   sub_020416B8(u8 layer);     /* tile stride, bg_sys.h         */
extern s32   func_0203FA08(u32 layer, u32 size, u8 slot);
extern u32   func_0203FAF0(u32 layer, u32 offset, u32 units);
extern void  sub_0203FB44(u8 layer, u16 offset, u32 size);
extern void  sub_02040B1C(u8 layer, void *src, u32 size, u16 offset);
extern void  func_020410D0(u32 layer, u32 x, u32 y, u32 w, u32 h,
                           void *cells, u32 sx, u32 sy, u32 sw, u32 sh);
/* The rectangle fill.  func_020454E0 and func_0201F7A8 narrow x/y/w/h/mode
 * to u8 at the call; sub_020456F8 compiles against an all-int spelling
 * because it passes only ldrb'd fields and constants. */
extern void  func_02041300(u32 layer, u16 tile, u8 x, u8 y, u8 w, u8 h,
                           u8 mode);
extern struct Bmp *func_02043678(u8 width, u8 height, u32 tileSize,
                                 u16 heap);             /* bmp.h */
extern void       *func_020437D4(struct Bmp *b);        /* bmp.h */
extern void        func_020437AC(struct Bmp *b);        /* bmp.h */

#endif /* BMP_WIN_H */
