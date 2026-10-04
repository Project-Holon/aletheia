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

struct CharBuf;
struct StrObj;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_0201D37C(struct StrObj *src, struct StrObj *dst, u32 n);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern u32 func_0201D42C(struct StrObj *s, void *font);

int func_0219214C(u32 a, u32 b, u32 c, u32 d, u32 *cnt, u8 col)
{
    int y;

    func_02043B5C((struct CharBuf *)a, col);
    if (func_0201D37C((struct StrObj *)c, (struct StrObj *)d, *cnt) == 0)
        return 1;
    func_0201C7A4((void *)a, 1, 1, (void *)d, (void *)b);
    y = 1;
    y += func_0201D42C((struct StrObj *)d, (void *)b) + 1;
    if (func_0201D37C((struct StrObj *)c, (struct StrObj *)d, ++*cnt) == 0)
        return 1;
    func_0201C7A4((void *)a, 1, y, (void *)d, (void *)b);
    ++*cnt;
    return 0;
}
