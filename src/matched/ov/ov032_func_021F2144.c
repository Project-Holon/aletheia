/*
 * function: func_021F2144
 * address:  0x021F2144
 * packet:   pkt_ov032_021F2144
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F2144 0x021F2144 thumb
 *   func_021F21B0 0x021F21B0 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_020257D0 0x020257D0 thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021F21B0(char *p, char *q, u32 a);
extern void func_02043B5C(u32 a, u32 b);
extern void func_0201C7D0(u32 bmp, u32 x, u32 y, const void *text, u32 f, u16 color);
extern void func_0201C724(u32 a, u32 bmp, u32 x, u32 y, const void *text, u32 f, u16 color);
extern void func_020257D0(u32 a);

void func_021F2144(char *p, char *q, void *text, u16 col, u32 a4)
{
    u32 *t;

    t = (u32 *)(q + 0x18);
    func_02043B5C(t[1], 0);
    if (*(u8 *)(p + 0x7a) != 0) {
        func_0201C7D0(t[1], 0, 0, text, *(u32 *)(p + 0xb0), col);
        func_020257D0(t[0]);
        return;
    }
    func_0201C724(*(u32 *)(p + 0xb4), t[1], 0, 0, text, *(u32 *)(p + 0xb0), col);
    func_021F21B0(p, q, a4);
}
