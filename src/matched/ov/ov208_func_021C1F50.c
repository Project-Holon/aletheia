/*
 * function: func_021C1F50
 * address:  0x021C1F50
 * packet:   pkt_ov208_021C1F50
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_02045770  0x02045770  arm
 *   func_020437DC  0x020437DC  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_021C0740  0x021C0740  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern void *func_02045EC0(u32 bank, u32 index);
struct Bmp;
struct StrObj;
struct U16Vec;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045770(u32 p);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_0201C724(u32 a, void *b, s16 x, s16 y, void *e, u32 f, u16 g);
extern void func_02045808(struct U16Vec *vec);
extern void func_021C0740(u16 *heap, u8 *p, int key, u8 i);

#define W(o) (*(u32 *)(p + (o)))

void func_021C1F50(u16 *heap, u8 *p, int key)
{
    void *str;
    u16 tw;
    u32 w;

    str = func_02045EC0(W(0xc), p[0x78] + 0xbe);
    tw = func_0201D304(str, W(4), 0);
    w = func_020437DC(func_02045770(W(0x1c)));
    func_0201C724(W(0x3c), func_02045770(W(0x1c)), (u16)((int)(w - tw) / 2), 1, str, W(4), 0x3c40);
    func_02045808(str);
    W(0x2c) = 1;
    func_021C0740(heap, p, key, 2);
}
