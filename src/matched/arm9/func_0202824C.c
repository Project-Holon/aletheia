/*
 * function: APP_TASKMENU_WIN_IsTouch
 * address:  0x0202824C
 * packet:   pkt_0202824C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Touch hit test against a window.  TOUCHPANEL_GetPointTrg reports whether the
 * screen is being touched and where; if so the window's origin and
 * extent are read off its descriptor in tile units and scaled to
 * pixels by 8, and the touch point must fall inside that rectangle.
 *
 * The extent accessor BMP_WIN_GetWidth is called twice rather than once
 * with its result reused: it is an external ARM call, so the compiler
 * cannot prove it pure, and both calls survive.
 *
 * symbols:
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 */

typedef unsigned int u32;

extern u32 TOUCHPANEL_GetPointTrg(u32 *x, u32 *y);
typedef unsigned char  u8;
struct Descriptor;
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern u8 BMP_WIN_GetPosX(struct Descriptor *p);
extern u8 BMP_WIN_GetPosY(struct Descriptor *p);

u32 APP_TASKMENU_WIN_IsTouch(void **p)
{
    u32 x;
    u32 y;
    u32 left;
    u32 top;
    u32 right;
    u32 bottom;

    if (TOUCHPANEL_GetPointTrg(&x, &y) == 0) {
        goto fail;
    }

    left = BMP_WIN_GetPosX(p[0]) * 8;
    top = BMP_WIN_GetPosY(p[0]) * 8;
    right = left + BMP_WIN_GetWidth(p[0]) * 8;
    bottom = top + BMP_WIN_GetWidth(p[0]) * 8;

    if (x - left > right - left) {
        goto fail;
    }
    if (y - top > bottom - top) {
        goto fail;
    }
    return 1;
fail:
    return 0;
}
