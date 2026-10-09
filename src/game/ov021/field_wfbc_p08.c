/*
 * file:     field_wfbc_p08.c
 * unit:     yes
 * function: func_02195E80, func_02195E90, func_02196030
 * address:  0x02195E80
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
 *   func_02195E54  0x02195E54  thumb  ov021
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045748  0x02045748  arm
 *   func_02045750  0x02045750  arm
 *   func_020456F8  0x020456F8  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 */
#include "../../matched/include/Obj09176.h"

struct Descriptor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

struct FrameStyle {
    char pad_00[0x10];
    u32 bgLayer;
};

extern u32 func_02195E54(u32, u32, u32, u32);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045748(struct Descriptor *p);
extern u8 func_02045750(struct Descriptor *p);
extern void func_020456F8(struct Descriptor *d);
extern void func_02041300(u8 layer, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 mode);
extern void func_020409B4(u32 index);
int func_02195E80(u32 a, u32 b);
void func_02195E90(struct FrameStyle *style, void *win);
void func_02196030(u32 *p, u32 v);



/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02195E80(u32 a, u32 b)
{
return func_02195E54(a, ((struct Obj09176 *)((u8 *)(b)))->fC, ((struct Obj09176 *)((u8 *)(b)))->f3, ((struct Obj09176 *)((u8 *)(b)))->f58);
}



/*
 * Clears the one-tile frame around a window (tile 0 on all eight edges),
 * skipping any edge that touches the 32x24 screen border. The erase
 * counterpart of func_02195938.
 */
void func_02195E90(struct FrameStyle *style, void *win)
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
    int top;
    int right;
    int bottom;

    x = func_02045758(win);
    y = func_02045760(win);
    w = func_02045748(win);
    h = func_02045750(win);
    topClip = 0;
    bottomClip = 0;
    leftClip = 0;
    rightClip = 0;
    bg = style->bgLayer;

    func_020456F8(win);

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

    if (!topClip) {
        if (!leftClip)
            func_02041300(bg, 0, x - 1, y - 1, 1, 1, 0x11);
        top = y - 1;
        func_02041300(bg, 0, x, top, w, 1, 0x11);
        if (!rightClip)
            func_02041300(bg, 0, right, top, 1, 1, 0x11);
    }
    if (!leftClip)
        func_02041300(bg, 0, x - 1, y, 1, h, 0x11);
    if (!rightClip)
        func_02041300(bg, 0, right, y, 1, h, 0x11);
    if (!bottomClip) {
        if (!leftClip)
            func_02041300(bg, 0, x - 1, bottom, 1, 1, 0x11);
        func_02041300(bg, 0, x, bottom, w, 1, 0x11);
        if (!rightClip)
            func_02041300(bg, 0, right, bottom, 1, 1, 0x11);
    }
    func_020409B4(bg);
}


/*
 * Unlabelled leaf setter, callee of the thunk at 0x02196034.
 *
 * Addresses are Black-image addresses.
 */
void func_02196030(u32 *p, u32 v)
{
    *p = v;
}
