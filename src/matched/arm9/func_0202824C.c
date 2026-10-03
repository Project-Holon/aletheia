/*
 * function: func_0202824C
 * address:  0x0202824C
 * packet:   pkt_0202824C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Touch hit test against a window.  func_02035D20 reports whether the
 * screen is being touched and where; if so the window's origin and
 * extent are read off its descriptor in tile units and scaled to
 * pixels by 8, and the touch point must fall inside that rectangle.
 *
 * The extent accessor func_02045738 is called twice rather than once
 * with its result reused: it is an external ARM call, so the compiler
 * cannot prove it pure, and both calls survive.
 *
 * symbols:
 *   func_02035D20  0x02035D20  arm
 *   func_02045738  0x02045738  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 */

typedef unsigned int u32;

extern u32 func_02035D20(u32 *x, u32 *y);
typedef unsigned char  u8;
struct Descriptor;
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);

u32 func_0202824C(void **p)
{
    u32 x;
    u32 y;
    u32 left;
    u32 top;
    u32 right;
    u32 bottom;

    if (func_02035D20(&x, &y) == 0) {
        goto fail;
    }

    left = func_02045758(p[0]) * 8;
    top = func_02045760(p[0]) * 8;
    right = left + func_02045738(p[0]) * 8;
    bottom = top + func_02045738(p[0]) * 8;

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
