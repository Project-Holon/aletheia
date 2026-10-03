/*
 * function: func_021B9C64
 * address:  0x021B9C64
 * packet:   pkt_ov091_021B9C64
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_02045808  0x02045808  arm
 *   func_0201C724  0x0201C724  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *func_02045EC0(u32 h, u32 idx);
extern u32   func_02045770(u32 p);
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void  func_0201C724(u32 a, u32 bmp, s16 x, s16 y, void *text, u32 f, u16 color);

void func_021B9C64(u8 *p, u32 win, u32 idx, u32 x, s16 y, u16 color)
{
    void *text = func_02045EC0(*(u32 *)(p + 0x134), idx);
    func_0201C724(*(u32 *)(p + 0x140), func_02045770(win), x, y, text,
                  *(u32 *)(p + 0x13c), color);
    func_02045808(text);
}
