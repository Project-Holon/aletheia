/*
 * function: func_02194AC8
 * address:  0x02194AC8
 * packet:   pkt_ov021_02194AC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02194B3C  0x02194B3C  thumb  ov021
 *   func_02194A94  0x02194A94  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02194B3C(u8 *p, u8 *e);
extern u32 func_02194A94(u8 *p, u8 x, u8 y, int w, int h);

void func_02194AC8(u8 *p, u8 *e, u32 a, u32 b, u8 *s)
{
    int w;
    int h;
    int y;
    u8 x;

    func_02194B3C(p, e);
    *(u32 *)(e + 0x10) = a;
    *(u32 *)(e + 0x14) = b;
    *(u16 *)(e + 0x18) = *(u16 *)(s + 0xC);
    *(u16 *)(e + 0x1A) = 0;
    *(u32 *)(e + 4) = *(u32 *)s;
    *(u8 *)(e + 3) = *(u16 *)(s + 0xE);
    *(u32 *)(e + 0x60) = *(u32 *)(s + 0x10);
    w = s[0xA];
    x = s[8];
    x = (x + w > 0x20) ? 0x20 - w : x;
    h = s[0xB];
    y = s[9];
    if (y + h > 0x18)
        y = 0x18 - h;
    *(u32 *)(e + 0xC) = func_02194A94(p, x, y, w, h);
    *(u32 *)(e + 0x58) = *(u32 *)(s + 4);
    *(u8 *)(e + 0x5C) = 8;
    *(u8 *)(e + 0x5D) = 0;
    *(u16 *)e = 1;
}
