/*
 * function: TALKMSGWIN_ClearFrame
 * address:  0x02195E90
 * packet:   pkt_ov021_02195E90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the one-tile frame around a window (tile 0 on all eight edges),
 * skipping any edge that touches the 32x24 screen border. The erase
 * counterpart of TALKMSGWIN_DrawCorneredFrame.
 *
 * symbols:
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045748  0x02045748  arm
 *   func_02045750  0x02045750  arm
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct FrameStyle {
    char pad_00[0x10];
    u32 bgLayer;
};

struct Descriptor;
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045748(struct Descriptor *p);
extern u8 func_02045750(struct Descriptor *p);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_02041300(u8 layer, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 mode);
extern void func_020409B4(u32 index);

void TALKMSGWIN_ClearFrame(struct FrameStyle *style, void *win)
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

    BMP_WIN_ClearScreen(win);

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
