/*
 * function: func_021B9D08
 * address:  0x021B9D08
 * packet:   pkt_ov069_021B9D08
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_02045770  0x02045770  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern void *func_0201D7EC(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void *func_0201C440(u16 heap);
extern void func_0201C724(u32 print, u32 bmp, s16 x, s16 y, u32 str, u32 font, u16 color);
extern int func_02045770(int);

void func_021B9D08(u8 *p)
{
    int i;
    u32 h;

    *(void **)(p + 0xC) = func_0201D7EC(0x17, 0, 0, 0, 0x80);
    *(void **)(p + 0xE8) = func_0201C440(0x80);
    for (i = 0; i < 18; i++) {
        *(int *)(p + i * 8 + 0x58) = *(int *)(p + i * 4 + 0x10);
        p[i * 8 + 0x5C] = 0;
    }
    h = *(u32 *)(p + 0xE8);
    func_0201C724(h, func_02045770(*(int *)(p + 0xA8)), 0, 0,
                  *(u32 *)(p + 0x100), *(u32 *)(p + 0xC), 0x3DC0);
    p[0xAC] = 1;
    h = *(u32 *)(p + 0xE8);
    func_0201C724(h, func_02045770(*(int *)(p + 0xC8)), 0, 0,
                  *(u32 *)(p + 0x10C), *(u32 *)(p + 0xC), 0x3DC0);
    p[0xCC] = 1;
    h = *(u32 *)(p + 0xE8);
    func_0201C724(h, func_02045770(*(int *)(p + 0xD8)), 0, 0,
                  *(u32 *)(p + 0x118), *(u32 *)(p + 0xC), 0x3DC0);
    p[0xDC] = 1;
}
