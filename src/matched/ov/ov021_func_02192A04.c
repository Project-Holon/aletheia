/*
 * function: func_02192A04
 * address:  0x02192A04
 * packet:   pkt_ov021_02192A04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Draws a one-tile frame around a window (tiles 0x1F..0x30, palette 13).
 *
 * symbols:
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045738  0x02045738  arm
 *   func_02045740  0x02045740  arm
 *   func_02045730  0x02045730  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 func_02045758(u32 w);
extern u8 func_02045760(u32 w);
extern u8 func_02045738(u32 w);
extern u8 func_02045740(u32 w);
extern u32 func_02045730(u32 w);
extern void func_02041300(u32 layer, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 layer);

void func_02192A04(u32 win)
{
    u8 x;
    u8 y;
    u8 w;
    u8 h;
    u32 bg;

    x = func_02045758(win);
    y = func_02045760(win);
    w = func_02045738(win);
    h = func_02045740(win);
    bg = func_02045730(win);
    func_02041300(bg, 0x1f, x - 1, y - 1, 1, 1, 13);
    func_02041300(bg, 0x20, x, y - 1, w, 1, 13);
    func_02041300(bg, 0x24, x + w, y - 1, 1, 1, 13);
    func_02041300(bg, 0x25, x - 1, y, 1, h, 13);
    func_02041300(bg, 0x2a, x + w, y, 1, h, 13);
    func_02041300(bg, 0x2b, x - 1, y + h, 1, 1, 13);
    func_02041300(bg, 0x2d, x, y + h, w, 1, 13);
    func_02041300(bg, 0x30, x + w, y + h, 1, 1, 13);
    func_020409B4(bg);
}
