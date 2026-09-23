/*
 * docs/families/bmp_menu.h -- the bmp_menu.c family (grid menu in a bitmap
 * window, with cursor), 0x0201F93C..0x0201FF30.  __FILE__ anchor 0x020A7384
 * "bmp_menu.c", loaded by func_0201F93C (line 0x61) and func_0201FDA0
 * (line 0x263).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file.  Written 2026-09-23
 * (wave 14).  EXACT: func_0201F93C, func_0201F9D0, func_0201F9E8,
 * func_0201FA04, func_0201FAD0, func_0201FB30, func_0201FC1C,
 * unit_0201FC5C (func_0201FC5C, func_0201FD18, func_0201FD54),
 * func_0201FEBC, func_0201FEF4.  Open: func_0201FDA0 (DIFF, 2 bytes of
 * prologue scheduling, docs/notes/pkt_0201FC5C.c.txt).
 */

#ifndef BMP_MENU_H
#define BMP_MENU_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct BmpMenuWork BmpMenuWork;     /* bmp_menuwork.h */

/* The print-util handle (same shape as func_02020D5C's Handle). */
typedef struct {
    void *cell;         /* +0x00  BmpWin */
    u8    drawn;        /* +0x04  set after every print */
} PrintUtil;

/* The caller's template, 0x24 bytes, copied into the menu by struct
 * assignment (four ldm/stm pairs plus one word). */
typedef struct {
    BmpMenuWork *items; /* +0x00 */
    void *win;          /* +0x04  BmpWin */
    u8   font;          /* +0x08 */
    u8   xmax;          /* +0x09  columns */
    u8   ymax;          /* +0x0A  rows; item index = col * ymax + row */
    u8   lineSpc : 4;   /* +0x0B  extra row pitch */
    u8   cDisp   : 2;   /*        1 = no cursor (func_0201FD18) */
    u8   bf0b6   : 2;
    u16  unk0c;         /* +0x0C  x spacing, copied to BmpMenu.xspc */
    u16  unk0e;         /* +0x0E  y spacing (font height) -> yspc */
    u32  unk10;         /* +0x10 */
    PrintUtil *util;    /* +0x14 */
    void *que;          /* +0x18  print queue (func_0201C440) */
    void *fontH;        /* +0x1C  font (func_0201D7EC) */
    u32  unk20;         /* +0x20 */
} BmpMenuHeader;

/* The menu, 0x38 bytes (func_0201F93C). */
typedef struct {
    BmpMenuHeader hdr;  /* +0x00 */
    void *cursor;       /* +0x24  func_02020D18(heap) */
    u32 cancel;         /* +0x28  key mask that cancels */
    u8  pad2c;
    u8  pos;            /* +0x2D  current item */
    u8  width;          /* +0x2E  widest item (func_0201FC1C) */
    u8  px;             /* +0x2F */
    u8  py;             /* +0x30 */
    u8  xspc;           /* +0x31 */
    u8  yspc;           /* +0x32 */
    u8  lastDir;        /* +0x33 */
    u16 heap;           /* +0x34 */
    u16 pad36;
} BmpMenu;

/* The allocator's heap parameter is a signed int: with u32 the
 * constructor's stack-passed u16 heap is cached once and 92 bytes differ. */
extern void *func_02030734(int heap, u32 size, u32 clear, const char *file,
                           u32 line);
extern void *func_02045770(void *win);       /* bmp_win.h: the bitmap */
extern void  func_02043B5C(void *bmp, u32 value);
extern void  func_0201C6FC(void *que, void *bmp, s32 x, s32 y,
                           const void *str, void *font);
extern void  func_02020D5C(void *cursor, u32 x, u32 y, PrintUtil *util,
                           void *que, void *font);
/* 0x0209C0A4 _s32_div_f: quotient r0, remainder r1. */

BmpMenu *func_0201F93C(const BmpMenuHeader *hdr, u8 px, u8 py, u8 pos,
                       u16 heap, u32 cancel);
void func_0201FC5C(BmpMenu *m);                          /* draw items   */
void func_0201FD18(BmpMenu *m);                          /* place cursor */
void func_0201FD54(BmpMenu *m, u8 *x, u8 *y, u8 pos);    /* item -> px   */

#endif
