/*
 * function: func_02192860
 * address:  0x02192860
 * packet:   pkt_ov021_02192860
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
 *   d_021D3E60     0x021D3E60  data  a2
 */
#include "../include/Obj03575.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct T3 {
    u16 v[3];
};

extern struct T3 d_021D3E60;

struct Bmp;
extern u16 func_020437DC(const struct Bmp *bmp);
extern u32 func_020437E4(const struct Bmp *bmp);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);

void func_02192860(u8 *a, u32 b, u32 col)
{
    struct T3 t;
    u16 x;
    u16 y;

    t = d_021D3E60;
    x = func_020437DC((const struct Bmp *)b) - 8;
    y = func_020437E4((const struct Bmp *)b) - 8 - t.v[a[1]];
    func_020439A0((struct Bmp *)(((struct Obj03575 *)a)->f4), (struct Bmp *)b, 0, 0, x, y, 8, 8, 0);
    a[0] = 1;
}
