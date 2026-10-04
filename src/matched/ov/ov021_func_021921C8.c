/*
 * function: func_021921C8
 * address:  0x021921C8
 * packet:   pkt_ov021_021921C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020437DC  0x020437DC  arm  arm9
 *   func_020437E4  0x020437E4  arm  arm9
 *   func_020439A0  0x020439A0  arm  arm9
 *   func_02043B5C  0x02043B5C  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

struct Bmp;
struct CharBuf;
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020439A0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u16 i);

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
