/*
 * function: func_021B9C1C
 * address:  0x021B9C1C
 * packet:   pkt_ov091_021B9C1C
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
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045770(u32 p);
extern void func_0201C724(u32 a, u32 bmp, s16 x, s16 y, const void *text, u32 f, u16 color);
extern void func_02045808(struct U16Vec *vec);

#define W(o) (*(int *)(p + (o)))

void func_021B9C1C(u8 *p, u32 win, u32 id, int x, s16 y, u16 color)
{
    void *text;

    text = func_02045EC0((void *)W(0x134), id);
    func_0201C724(W(0x140), func_02045770(win), x, y, text, W(0x138), color);
    func_02045808(text);
}
