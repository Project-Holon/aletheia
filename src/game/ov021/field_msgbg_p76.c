/*
 * file:     field_msgbg_p76.c
 * unit:     yes
 * function: func_02191D88, func_02191DC8, func_02191FA0, func_02192138, func_0219214C, func_021921C8, func_02192244
 * address:  0x02191D88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02049624  0x02049624  arm
 *   func_02049B90  0x02049B90  arm
 *   func_02041300  0x02041300  arm
 *   func_0201D37C  0x0201D37C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb  arm9
 *   func_0201D42C  0x0201D42C  thumb  arm9
 *   func_02043B5C  0x02043B5C  arm  arm9
 *   func_020437DC  0x020437DC  arm  arm9
 *   func_020437E4  0x020437E4  arm  arm9
 *   func_020439A0  0x020439A0  arm  arm9
 */
struct StrObj;
struct CharBuf;
struct Bmp;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16_02192138;

typedef signed char    s8;

typedef short          s16_0219214C;

typedef short          s16_021921C8;

typedef short          s16_02192244;

extern void func_02049624(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02049B90(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02041300(u8 layer, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 pal);
extern u32 func_0201D37C(struct StrObj *src, struct StrObj *dst, u32 n);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7A4(void *x, s16_0219214C y, s16_0219214C z, void *s, void *w);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern void func_020439A0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u16 i);
void func_02191D88(u32 a, u32 b, u32 c, u32 d);
void func_02191DC8(u8 layer, u8 x, u8 y, u8 w, u8 h, u16 tile, u8 pal);
void func_02191FA0(u8 layer, u8 x, u8 y, u8 w, u8 h, u16 tile, u8 pal);
int func_02192138(u32 a, u32 b, u32 c);
int func_0219214C(u32 a, u32 b, u32 c, u32 d, u32 *cnt, u8 col);
int func_021921C8(u32 a, u32 b, u32 c, int n, u16 col);
void func_02192244(u32 unused, u32 a, u32 b);


void func_02191D88(u32 a, u32 b, u32 c, u32 d)
{
    if (c >= 4)
        c = 0;
    func_02049624(5, 6, a, 0x33, 0, 0, d);
    func_02049B90(5, 1, 0, c << 5, b << 5, 0x20, d);
}


/*
 * Addresses are Black-image addresses.
 */
void func_02191DC8(u8 layer, u8 x, u8 y, u8 w, u8 h, u16 tile, u8 pal)
{
    func_02041300(layer, tile, x - 2, y - 1, 1, 1, pal);
    func_02041300(layer, tile + 1, x - 1, y - 1, 1, 1, pal);
    func_02041300(layer, tile + 2, x, y - 1, w, 1, pal);
    func_02041300(layer, tile + 4, x + w, y - 1, 1, 1, pal);
    func_02041300(layer, tile + 5, x + w + 1, y - 1, 1, 1, pal);
    func_02041300(layer, tile + 6, x - 2, y, 1, h, pal);
    func_02041300(layer, tile + 7, x - 1, y, 1, h, pal);
    func_02041300(layer, tile + 10, x + w, y, 1, h, pal);
    func_02041300(layer, tile + 11, x + w + 1, y, 1, h, pal);
    func_02041300(layer, tile + 12, x - 2, y + h, 1, 1, pal);
    func_02041300(layer, tile + 13, x - 1, y + h, 1, 1, pal);
    func_02041300(layer, tile + 14, x, y + h, w, 1, pal);
    func_02041300(layer, tile + 16, x + w, y + h, 1, 1, pal);
    func_02041300(layer, tile + 17, x + w + 1, y + h, 1, 1, pal);
}


void func_02191FA0(u8 layer, u8 x, u8 y, u8 w, u8 h, u16 tile, u8 pal)
{
    func_02041300(layer, tile, x - 2, y - 1, 1, 1, pal);
    func_02041300(layer, tile, x - 1, y - 1, 1, 1, pal);
    func_02041300(layer, tile, x, y - 1, w, 1, pal);
    func_02041300(layer, tile, x + w, y - 1, 1, 1, pal);
    func_02041300(layer, tile, x + w + 1, y - 1, 1, 1, pal);
    func_02041300(layer, tile, x - 2, y, 1, h, pal);
    func_02041300(layer, tile, x - 1, y, 1, h, pal);
    func_02041300(layer, tile, x + w, y, 1, h, pal);
    func_02041300(layer, tile, x + w + 1, y, 1, h, pal);
    func_02041300(layer, tile, x - 2, y + h, 1, 1, pal);
    func_02041300(layer, tile, x - 1, y + h, 1, 1, pal);
    func_02041300(layer, tile, x, y + h, w, 1, pal);
    func_02041300(layer, tile, x + w, y + h, 1, 1, pal);
    func_02041300(layer, tile, x + w + 1, y + h, 1, 1, pal);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02192138(u32 a, u32 b, u32 c)
{
if (func_0201D37C((struct StrObj *)a, (struct StrObj *)b, c) == 0) {
    return 1;
}
return 0;
}


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


int func_021921C8(u32 a, u32 b, u32 c, int n, u16 col)
{
    int w;
    int h;
    int rest;

    w = func_020437DC((const struct Bmp *)a);
    h = func_020437E4((const struct Bmp *)a);
    func_02043B5C((struct CharBuf *)a, col);
    if (n > h)
        n = h;
    rest = h - n;
    func_020439A0(b, a, 0, n, 0, 0, w, rest, col);
    func_020439A0(c, a, 0, 0, 0, rest, w, n, col);
    if (n >= h) return 1;
    return 0;
}


void func_02192244(u32 unused, u32 a, u32 b)
{
    func_02049B90(5, 2, 0, 0, a * 32, 0x20, b);
}
