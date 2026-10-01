/*
 * function: func_0219214C
 * address:  0x0219214C
 * packet:   pkt_ov021_0219214C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C7A4  0x0201C7A4  thumb  arm9
 *   func_0201D37C  0x0201D37C  thumb  arm9
 *   func_0201D42C  0x0201D42C  thumb  arm9
 *   func_02043B5C  0x02043B5C  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern void func_02043B5C(u32 a, u8 b);
extern int func_0201D37C(u32 a, u32 b, u32 c);
extern void func_0201C7A4(u32 a, u32 b, s16 c, u32 d, u32 e);
extern int func_0201D42C(u32 a, u32 b);

int func_0219214C(u32 a, u32 b, u32 c, u32 d, u32 *cnt, u8 col)
{
    int y;

    func_02043B5C(a, col);
    if (func_0201D37C(c, d, *cnt) == 0)
        return 1;
    func_0201C7A4(a, 1, 1, d, b);
    y = 1;
    y += func_0201D42C(d, b) + 1;
    if (func_0201D37C(c, d, ++*cnt) == 0)
        return 1;
    func_0201C7A4(a, 1, y, d, b);
    ++*cnt;
    return 0;
}
