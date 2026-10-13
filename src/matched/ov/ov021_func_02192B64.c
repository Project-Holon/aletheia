/*
 * function: FIELD_MSGBG_ClearSysWindowFrame
 * address:  0x02192B64
 * packet:   pkt_ov021_02192B64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   BMP_WIN_GetHeight  0x02045740  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern u8 BMP_WIN_GetPosX(struct Descriptor *p);
extern u8 BMP_WIN_GetPosY(struct Descriptor *p);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern u8 BMP_WIN_GetHeight(struct Descriptor *p);
extern void func_02041300(u32 layer, u32 tile, u32 x, u32 y, u32 w, u32 h, u32 mode);
extern void func_020409B4(u32 layer);

void FIELD_MSGBG_ClearSysWindowFrame(u32 a)
{
    u32 bg;
    u32 x;
    u32 y;
    u32 w;
    u32 h;

    bg = BMP_WIN_GetBgLayer((struct Descriptor *)a);
    x = BMP_WIN_GetPosX((struct Descriptor *)a);
    y = BMP_WIN_GetPosY((struct Descriptor *)a);
    w = BMP_WIN_GetWidth((struct Descriptor *)a);
    h = BMP_WIN_GetHeight((struct Descriptor *)a);
    func_02041300(bg, 0, (u8)(x - 1), (u8)(y - 1), (u8)(w + 2), (u8)(h + 2), 0);
    func_020409B4(bg);
}
