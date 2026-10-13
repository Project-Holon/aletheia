/*
 * function: FIELD_MSGBG_DrawSysWindowFrame
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
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   BMP_WIN_GetHeight  0x02045740  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
extern u8 BMP_WIN_GetPosX(struct Descriptor *p);
extern u8 BMP_WIN_GetPosY(struct Descriptor *p);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern u8 BMP_WIN_GetHeight(struct Descriptor *p);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041300(u32 layer, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 layer);

void FIELD_MSGBG_DrawSysWindowFrame(u32 win)
{
    u8 x;
    u8 y;
    u8 w;
    u8 h;
    u32 bg;

    x = BMP_WIN_GetPosX((struct Descriptor *)win);
    y = BMP_WIN_GetPosY((struct Descriptor *)win);
    w = BMP_WIN_GetWidth((struct Descriptor *)win);
    h = BMP_WIN_GetHeight((struct Descriptor *)win);
    bg = BMP_WIN_GetBgLayer((struct Descriptor *)win);
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
