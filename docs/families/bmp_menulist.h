/*
 * docs/families/bmp_menulist.h -- shared declarations for the bmp_menulist.c
 * family (the scrolling text menu list drawn into a bitmap window),
 * 0x0201FF30..0x02020CF8 in the ARM9 image.  The __FILE__ anchor is
 * 0x020A7390 "bmp_menulist.c", loaded by func_0201FF30 (line 0x69) through
 * the pool word at 0x020200C8 (layout/file_anchors.txt line 71).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Written 2026-09-23
 * (wave 13) from the family's EXACT sources:
 *
 *   func_0201FF30   func_020200CC   func_0202020C   func_02020234
 *   unit_02020268 (eight functions 0x02020268..0x02020406)
 *   func_02020408   func_0202055C   unit_020206C0 (func_020206C0,
 *   func_0202071C)  func_02020780   func_020208B8   func_02020970
 *   func_02020A34   func_02020A58   func_02020B5C   func_02020CA0
 *
 * As of wave 13 the family has NO open function.  The worklist row
 * 0x020202CC was never a function start: it is the middle of func_02020298
 * (see unit_02020268.c's header), seeded from a pending header that
 * misnamed a tail-call target.
 *
 * ADJUDICATION RULE, as in bmp.h and bmp_win.h: a load or store
 * instruction constrains a field and a name does not.  Where two matched
 * files spell a field differently, the byte evidence below says which
 * reading wins.
 */

#ifndef BMP_MENULIST_H
#define BMP_MENULIST_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct BmpWin;                       /* docs/families/bmp_win.h */
struct MenuList;

/* ------------------------------------------------------------------ *
 * THE ITEM ARRAY, eight bytes per item (every reader scales the index
 * with `lsls #3`).  +0 is the text handed to the print routine
 * (func_0202055C loads it with a register-offset `ldr [arr, off]`), +4 the
 * item's value, returned on A by func_020200CC and handed to the
 * per-item hook.  The value -3 marks a SEPARATOR row: the cursor skips it
 * (func_0201FF30, func_02020780, func_02020970) and it is printed at the
 * separator indent f14 instead of f15 (func_0202055C).
 * ------------------------------------------------------------------ */
struct MenuItem {
    const void *text;    /* +0x00 */
    u32         value;   /* +0x04  -3 = separator; s32 in func_020200CC,
                          *        which returns it as the key result */
};

typedef void (*MenuCursorCb)(struct MenuList *m, u32 value, u32 arg);
typedef void (*MenuItemCb)(struct MenuList *m, u32 value, u8 y);

/* ------------------------------------------------------------------ *
 * THE LIST OBJECT, 0x50 bytes (func_0201FF30 allocates 0x50, cleared,
 * and copies a 0x34-byte header record over its start with one struct
 * assignment).  +0x00..+0x33 is the caller's template, +0x34.. is state.
 * ------------------------------------------------------------------ */
struct MenuList {
    struct MenuItem *arr;     /* +0x00 */
    MenuCursorCb     cursorCb;/* +0x04  called by func_02020A34 with the
                               *        current item's value */
    MenuItemCb       itemCb;  /* +0x08  called by func_0202055C before
                               *        each item is printed */
    struct BmpWin   *win;     /* +0x0C  the window; func_02045770 gives its
                               *        bitmap, func_02045738 its width */
    u16 count;                /* +0x10  items in arr */
    u16 rows;                 /* +0x12  visible rows; clamped to count by
                               *        func_0201FF30 */
    u8  f14;                  /* +0x14  x of a separator row          */
    u8  f15;                  /* +0x15  x of an ordinary row           */
    u8  f16;                  /* +0x16  x of the cursor                */
    u8  f17lo : 4;            /* +0x17  y of the first row             */
    u8  f17hi : 4;            /*        letter colour                  */
    u8  f18lo : 4;            /* +0x18  background colour (the clear
                               *        value func_02043B5C fills with) */
    u8  f18hi : 4;            /*        shadow colour                  */
    u8  f19;                  /* +0x19 */
    u16 f1Alo   : 3;          /* +0x1A  seeds f36                      */
    u16 f1Amid  : 4;          /*        extra row spacing: row pitch is
                               *        (u8)(f22 + f1Amid)             */
    u16 f1Apad  : 2;          /*        the paging-key mode read by
                               *        func_020200CC (0 none, 1 left/
                               *        right, 2 L/R)                  */
    u16 f1Amid2 : 6;          /*        seeds f38                      */
    u16 f1Atop  : 1;          /*        cursor style; the redraw
                               *        switches have one live arm (0) */
    u32 f1C;                  /* +0x1C  attribute 19 of func_02020350  */
    u16 f20;                  /* +0x20  cursor width in pixels         */
    u16 f22;                  /* +0x22  glyph height                   */
    u8  pad24[4];
    struct { u32 win; u8 dirty; } *f28;  /* +0x28  print target;
                               *        func_02020408 sets dirty = 1   */
    u32 f2C;                  /* +0x2C  print context (font/queue)     */
    u32 f30;                  /* +0x30  print flags                    */
    u8  f34lo : 4;            /* +0x34  override letter colour         */
    u8  f34hi : 4;            /*        override background colour     */
    u8  f35lo : 4;            /* +0x35  override shadow colour         */
    u8  f35hi : 4;
    u8  f36 : 6;              /* +0x36 */
    u8  f36top : 2;
    u8  f37;
    u8  f38 : 7;              /* +0x38 */
    u8  f38top : 1;           /*        1 = print with the override
                               *        colours (func_02020298 sets it) */
    u8  pad39[3];
    u32 f3C;                  /* +0x3C  cursor object, func_02020D18 /
                               *        func_02020D3C                  */
    u16 f40;                  /* +0x40  first visible item (scroll)    */
    u16 f42;                  /* +0x42  cursor row inside the window;
                               *        f40 + f42 is the current item  */
    u8  f44, f45, f46;        /* +0x44  f46 seeded 0xFF                */
    u8  f47;                  /* +0x47  last move: 1 up, 2 down, 3 page
                               *        back, 4 page forward, 0 none   */
    u16 heap;                 /* +0x48 */
    u8  f4A;                  /* +0x4A  nonzero = B does not cancel    */
};

/* The 5:5:5 print colour.  func_02020408 builds it with a masking macro;
 * mwcc turns each mask-then-shift into an `lsl #27 / lsr #17|#22` pair and
 * keeps a bare `ands #0x1f` on the unshifted term.  No bitfield struct. */
#define MENU_COLOR(l, s, b) \
    ((u16)((((l) & 0x1f) << 10) | (((s) & 0x1f) << 5) | ((b) & 0x1f)))

/* ------------------------------------------------------------------ *
 * The functions, in address order, with the prototypes their EXACT
 * sources compile with.
 * ------------------------------------------------------------------ */
struct MenuList *func_0201FF30(const void *tmpl, u16 top, u16 row, u32 heap);
                                         /* create; draws and fires the
                                          * cursor callback once */
s32  func_020200CC(struct MenuList *m); /* per-frame key handler: A returns
                                          * the item value, B -2, else -1 */
void func_0202020C(struct MenuList *m, u16 *top, u16 *row); /* destroy */
void func_02020234(struct MenuList *m);  /* full redraw */
void func_02020268(struct MenuList *m, u8 l, u8 b, u8 s);
void func_02020298(struct MenuList *m, u8 l, u8 b, u8 s);  /* override */
void func_020202EC(struct MenuList *m, u16 *out);          /* f40 + f42 */
void func_020202FC(struct MenuList *m, u16 *top, u16 *row);
u16  func_02020314(struct MenuList *m);          /* y of the cursor row */
u16  func_02020324(struct MenuList *m, u32 n);   /* y of row n          */
u32  func_02020344(struct MenuList *m, u32 i);   /* arr[i].value        */
u32  func_02020350(struct MenuList *m, u32 what);/* attribute getter    */

/* Print one item.  sel != 0 goes through func_0201C724 and marks the
 * target dirty.  The image's (f38top clear, sel == 0) arm reads the
 * OVERRIDE colours, unlike its sibling arm -- reproduced as is. */
void func_02020408(struct MenuList *m, const void *text, u32 x, u32 y,
                   u32 sel);

/* Redraw n + 1 rows from item `item` at window row `row`; flag = scroll
 * the band one row first.  step is an int local holding a (u8) value. */
void func_0202055C(struct MenuList *m, u16 item, u16 row, u16 n, u32 flag);

void func_020206C0(struct MenuList *m);          /* draw cursor       */
void func_0202071C(struct MenuList *m, u32 row); /* erase cursor      */

/* One cursor step: 0 blocked, 1 moved, 2 scrolled.  col is an int local,
 * rows is read inside each arm, declaration order ncol,col,rows,mid,row. */
u8   func_02020780(struct MenuList *m, u8 dir);

void func_020208B8(struct MenuList *m, int n, u32 flag); /* scroll band */

/* Move count steps; ALL scalar parameters narrow (u8), which is what
 * gives the `cmp #0 / bls` guard and the home-slot store order. */
u32  func_02020970(struct MenuList *m, u8 notify, u8 count, u8 dir);

void func_02020A34(struct MenuList *m, void *arg);   /* cursor callback */

/* The window scroll pair and its front end (4bpp / 8bpp). */
void func_02020A58(void *bmp, u32 dir, u32 start, u32 color, u16 size);
void func_02020B5C(void *bmp, u32 dir, u32 start, u32 color, u16 size);
void func_02020CA0(struct BmpWin *w, u32 dir, u32 start, u32 color,
                   u16 tile);

/* ------------------------------------------------------------------ *
 * Externals.
 * ------------------------------------------------------------------ */
extern const char bmp_menulist_File[];   /* 0x020A7390 */
extern u32  func_020362DC(void);         /* keys pressed this frame */
extern u32  func_0203633C(void);         /* keys repeating          */
extern void func_020061E4(u32 se);       /* sound: 0x54C A, 0x551 B,
                                          * 0x548 move              */
extern u32  func_02045770(struct BmpWin *w);   /* bmp_win.h: the bitmap */
extern u8   func_02045738(struct BmpWin *w);   /* bmp_win.h: width      */
extern u8   func_02045730(struct BmpWin *w);   /* bmp_win.h: layer      */
extern void func_02045334(struct BmpWin *w);   /* bmp_win.h: upload     */
extern void func_02043AF4(u32 bmp, u32 a, u32 b, u32 c, u32 d, u32 e);
                                         /* bmp.h fill dispatcher   */
extern void func_02043B5C(u32 bmp, u32 value);  /* bmp.h clear       */
extern u16  func_020437DC(u32 bmp);      /* bmp.h width in pixels   */
extern void func_0201C724(u32 ctx, u32 bmp, u32 x, u32 y, const void *text,
                          u32 flags, u16 color);
extern void func_0201C7D0(u32 bmp, u32 x, u32 y, const void *text,
                          u32 flags, u16 color);

#endif /* BMP_MENULIST_H */
