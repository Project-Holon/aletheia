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
 *   func_02045730  0x02045730  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045738  0x02045738  arm
 *   func_02045740  0x02045740  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
extern u8 func_02045730(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern void func_02041300(u32 layer, u32 tile, u32 x, u32 y, u32 w, u32 h, u32 mode);
extern void func_020409B4(u32 layer);

void FIELD_MSGBG_ClearSysWindowFrame(u32 a)
{
    u32 bg;
    u32 x;
    u32 y;
    u32 w;
    u32 h;

    bg = func_02045730((struct Descriptor *)a);
    x = func_02045758((struct Descriptor *)a);
    y = func_02045760((struct Descriptor *)a);
    w = func_02045738((struct Descriptor *)a);
    h = func_02045740((struct Descriptor *)a);
    func_02041300(bg, 0, (u8)(x - 1), (u8)(y - 1), (u8)(w + 2), (u8)(h + 2), 0);
    func_020409B4(bg);
}
