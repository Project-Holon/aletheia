/*
 * file:     field_wfbc_p25.c
 * unit:     yes
 * function: func_02195588, func_021955EC, func_02195938, func_02195E54, func_02195E70
 * address:  0x02195588
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020414EC  0x020414EC  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02049624  0x02049624  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02041300  0x02041300  arm
 *   func_02045374  0x02045374  arm
 *   func_02045748  0x02045748  arm
 *   func_02045750  0x02045750  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 */
#include "../../matched/include/Obj04219.h"

struct Cfg;
struct Descriptor;
struct FrameStyle;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct FrameStyle {
    char pad_00[0x0C];
    u16 baseTile;
    char pad_0E[0x02];
    u32 bgLayer;
    u8 palette;
};

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u8 x0; u8 x1; u8 x2; u8 x3; u32 x4; u32 x8; u32 xc; } Obj;

extern void func_020414EC(u32 a);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045748(struct Descriptor *p);
extern u8 func_02045750(struct Descriptor *p);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041300(u8 layer, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 mode);
extern void func_020409B4(u32 index);
void func_02195588(u8 *p);
void func_021955EC(struct FrameStyle *style, void *win, int deco);
void func_02195938(struct FrameStyle *style, void *win, int deco);
void func_02195E54(u32 a, u32 b, u8 c, u32 d);
void func_02195E70(u32 a, Obj *b);


void func_02195588(u8 *p)
{
    u32 r;
    u32 v;

    func_020414EC(((struct Obj04219 *)p)->f10 & 0xFF);
    v = ((struct Obj04219 *)p)->f10;
    r = 0;
    switch (v) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        r = 4;
        break;
    }
    func_02049B40(5, 0, r, (u32)p[0x14] << 5, 0x20, ((struct Obj04219 *)p)->f0);
    func_02049624((void *)5, (void *)5, (void *)(((struct Obj04219 *)p)->f10), (void *)(((struct Obj04219 *)p)->fC), 0, 0, ((struct Obj04219 *)p)->f0);
}


/*
 * Draws a simple window frame (corners and edges, one tile each) around a
 * window on its BG layer, plus an optional decoration tile pair selected by
 * `deco`. Sibling of func_02195938, which draws the double-corner frame. Edges that touch the
 * screen border (x == 0, x + w == 32, y == 0, y + h == 24) are skipped.
 *
 * Addresses are Black-image addresses.
 */
void func_021955EC(struct FrameStyle *style, void *win, int deco)
{
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    int topClip;
    int bottomClip;
    int leftClip;
    int rightClip;
    u8 bg;
    int pal;
    u16 tile;
    int top;
    int right;
    int bottom;
    u16 t2;

    x = func_02045758(win);
    y = func_02045760(win);
    w = func_02045748(win);
    h = func_02045750(win);
    topClip = 0;
    bottomClip = 0;
    leftClip = 0;
    rightClip = 0;
    bg = style->bgLayer;
    pal = (style->palette & 0xF) << 12;
    tile = style->baseTile;

    if (x == 0)
        leftClip = 1;
    right = x + w;
    if (right == 0x20)
        rightClip = 1;
    if (y == 0)
        topClip = 1;
    bottom = y + h;
    if (bottom == 0x18)
        bottomClip = 1;

    func_02045374(win);

    if (!topClip) {
        if (!leftClip)
            func_02041300(bg, (tile + 1) | pal, x - 1, y - 1, 1, 1, 0x11);
        top = y - 1;
        func_02041300(bg, (tile + 3) | pal, x, top, w, 1, 0x11);
        if (!rightClip)
            func_02041300(bg, (tile + 0x401) | pal, right, top, 1, 1, 0x11);
    }
    if (!leftClip)
        func_02041300(bg, (tile + 4) | pal, x - 1, y, 1, h, 0x11);
    if (!rightClip)
        func_02041300(bg, (tile + 0x404) | pal, right, y, 1, h, 0x11);
    if (!bottomClip) {
        if (!leftClip)
            func_02041300(bg, (tile + 0x801) | pal, x - 1, bottom, 1, 1, 0x11);
        func_02041300(bg, (tile + 0x803) | pal, x, bottom, w, 1, 0x11);
        if (!rightClip)
            func_02041300(bg, (tile + 0xC01) | pal, right, bottom, 1, 1, 0x11);
    }

    t2 = (tile + 2) | pal;
    switch (deco) {
    case 1:
        if (!topClip)
            func_02041300(bg, t2, x + ((u32)w >> 1) - 1, y - 1, 2, 1, 0x11);
        break;
    case 2:
        if (!bottomClip)
            func_02041300(bg, t2 | 0x800, x + ((u32)w >> 1) - 1, bottom, 2, 1, 0x11);
        break;
    case 3:
        if (!leftClip)
            func_02041300(bg, (tile + 5) | pal, x - 1, y + ((u32)h >> 1) - 1, 1, 2, 0x11);
        break;
    case 4:
        if (!rightClip)
            func_02041300(bg, (tile + 5) | pal, right, y + ((u32)h >> 1) - 1, 1, 2, 0x11);
        break;
    case 5:
        if (!topClip)
            func_02041300(bg, t2, x + 7, y - 1, 2, 1, 0x11);
        break;
    case 7:
        if (!topClip)
            func_02041300(bg, t2 | 0x800, x + 7, bottom, 2, 1, 0x11);
        break;
    case 6:
        if (!bottomClip) {
            right -= 9;
            func_02041300(bg, t2, right, y - 1, 2, 1, 0x11);
        }
        break;
    case 8:
        if (!bottomClip) {
            right -= 9;
            func_02041300(bg, t2 | 0x800, right, bottom, 2, 1, 0x11);
        }
        break;
    }
    func_020409B4(bg);
}


/*
 * Draws a window frame around a window on its BG layer: corners, edges, and
 * an optional decoration tile pair selected by `deco`. Edges that touch the
 * screen border (x == 0, x + w == 32, y == 0, y + h == 24) are skipped.
 * The window geometry getters are held in u16 locals and the palette nibble
 * is masked and shifted into an int; both are what the truncations and the
 * lsl #28 / lsr #16 fold in the image require.
 *
 * Addresses are Black-image addresses.
 */
void func_02195938(struct FrameStyle *style, void *win, int deco)
{
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    int topClip;
    int bottomClip;
    int leftClip;
    int rightClip;
    u8 bg;
    int pal;
    u16 tile;
    int right;
    int bottom;
    u16 t8;

    x = func_02045758(win);
    y = func_02045760(win);
    w = func_02045748(win);
    h = func_02045750(win);
    topClip = 0;
    bottomClip = 0;
    leftClip = 0;
    rightClip = 0;
    bg = style->bgLayer;
    pal = (style->palette & 0xF) << 12;
    tile = style->baseTile;

    if (x == 0)
        leftClip = 1;
    right = x + w;
    if (right == 0x20)
        rightClip = 1;
    if (y == 0)
        topClip = 1;
    bottom = y + h;
    if (bottom == 0x18)
        bottomClip = 1;

    func_02045374(win);

    if (!topClip) {
        if (!leftClip) {
            func_02041300(bg, (tile + 9) | pal, x - 1, y - 1, 1, 1, 0x11);
            func_02041300(bg, (tile + 10) | pal, x, y - 1, 1, 1, 0x11);
            func_02041300(bg, (tile + 11) | pal, x - 1, y, 1, 1, 0x11);
        }
        func_02041300(bg, (tile + 6) | pal, x + 1, y - 1, w - 1, 1, 0x11);
        if (!rightClip) {
            func_02041300(bg, (tile + 0x409) | pal, x + w, y - 1, 1, 1, 0x11);
            func_02041300(bg, (tile + 0x40A) | pal, x + w - 1, y - 1, 1, 1, 0x11);
            func_02041300(bg, (tile + 0x40B) | pal, x + w, y, 1, 1, 0x11);
        }
    }
    if (!leftClip) {
        if (!topClip)
            func_02041300(bg, (tile + 7) | pal, x - 1, y + 1, 1, h - 1, 0x11);
        else
            func_02041300(bg, (tile + 7) | pal, x - 1, y, 1, h, 0x11);
    }
    if (!rightClip) {
        if (!topClip)
            func_02041300(bg, (tile + 0x407) | pal, right, y + 1, 1, h - 1, 0x11);
        else
            func_02041300(bg, (tile + 0x407) | pal, right, y, 1, h, 0x11);
    }
    if (!bottomClip) {
        if (!leftClip) {
            func_02041300(bg, (tile + 0x809) | pal, x - 1, y + h, 1, 1, 0x11);
            func_02041300(bg, (tile + 0x80A) | pal, x, y + h, 1, 1, 0x11);
            func_02041300(bg, (tile + 0x80B) | pal, x - 1, y + h - 1, 1, 1, 0x11);
        }
        func_02041300(bg, (tile + 0x806) | pal, x + 1, bottom, w - 1, 1, 0x11);
        if (!rightClip) {
            func_02041300(bg, (tile + 0xC09) | pal, x + w, y + h, 1, 1, 0x11);
            func_02041300(bg, (tile + 0xC0A) | pal, x + w - 1, y + h, 1, 1, 0x11);
            func_02041300(bg, (tile + 0xC0B) | pal, x + w, y + h - 1, 1, 1, 0x11);
        }
    }

    t8 = (tile + 8) | pal;
    switch (deco) {
    case 1:
        if (!topClip)
            func_02041300(bg, t8, x + ((u32)w >> 1) - 1, y - 1, 2, 1, 0x11);
        break;
    case 2:
        if (!bottomClip)
            func_02041300(bg, t8 | 0x800, x + ((u32)w >> 1) - 1, bottom, 2, 1, 0x11);
        break;
    case 3:
        if (!leftClip)
            func_02041300(bg, (tile + 5) | pal, x - 1, y + ((u32)h >> 1) - 1, 1, 2, 0x11);
        break;
    case 4:
        if (!rightClip)
            func_02041300(bg, (tile + 5) | pal, right, y + ((u32)h >> 1) - 1, 1, 2, 0x11);
        break;
    case 5:
        if (!topClip)
            func_02041300(bg, t8, x + 7, y - 1, 2, 1, 0x11);
        break;
    case 7:
        if (!topClip)
            func_02041300(bg, t8 | 0x800, x + 7, bottom, 2, 1, 0x11);
        break;
    case 6:
        if (!bottomClip) {
            right -= 9;
            func_02041300(bg, t8, right, y - 1, 2, 1, 0x11);
        }
        break;
    case 8:
        if (!bottomClip) {
            right -= 9;
            func_02041300(bg, t8 | 0x800, right, bottom, 2, 1, 0x11);
        }
        break;
    }
    func_020409B4(bg);
}


/*
 * Addresses are Black-image addresses.
 */
void func_02195E54(u32 a, u32 b, u8 c, u32 d)
{
    switch (c) {
    case 0:
        func_021955EC((struct FrameStyle *)a, (void *)b, d);
        break;
    case 1:
        func_02195938((struct FrameStyle *)a, (void *)b, d);
        break;
    }
}


void func_02195E70(u32 a, Obj *b)
{
    func_02195E54(a, b->xc, b->x3, 0);
}
