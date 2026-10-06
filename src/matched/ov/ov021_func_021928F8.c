/*
 * function: func_021928F8
 * address:  0x021928F8
 * packet:   pkt_ov021_021928F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 *   func_020439A0  0x020439A0  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021D3E58     0x021D3E58  data  a2
 */
#include "../include/Obj02692.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct T3 {
    u16 v[3];
};

extern struct T3 d_021D3E58;

struct Bmp;
extern u16 func_020437DC(const struct Bmp *bmp);
extern u32 func_020437E4(const struct Bmp *bmp);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);

void func_021928F8(u8 *a, u32 b, u32 c)
{
    struct T3 t;
    s16 x;
    s16 y;
    s16 m;

    t = d_021D3E58;
    x = func_020437DC((const struct Bmp *)b) - 8;
    y = func_020437E4((const struct Bmp *)b) - 8 - t.v[a[1]];
    m = y & 7;
    if (m != 0)
        func_020439A0((struct Bmp *)c, (struct Bmp *)b, 0, 8 - m, x, y, 8, m, 0xFFFF);
    func_020439A0((struct Bmp *)c, (struct Bmp *)b, 0, 0, x, y + m, 8, 8 - m, 0xFFFF);
    a[2]++;
    if (a[2] >= 4) {
        a[2] = 0;
        a[1]++;
        a[1] = a[1] % 3;
    }
    x = func_020437DC((const struct Bmp *)b) - 8;
    y = func_020437E4((const struct Bmp *)b) - 8 - t.v[a[1]];
    func_020439A0((struct Bmp *)(((struct Obj02692 *)a)->f4), (struct Bmp *)b, 0, 0, x, y, 8, 8, 0);
    a[0] = 1;
}
