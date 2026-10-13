/*
 * function: FIELD_MSGBG_AnimateCursorOnFrame
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
 *   BMP_GetWidth  0x020437DC  arm
 *   BMP_GetHeight  0x020437E4  arm
 *   BMP_Blit  0x020439A0  arm
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
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern u16 BMP_GetHeight(const struct Bmp *bmp);
extern void BMP_Blit(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);

void FIELD_MSGBG_AnimateCursorOnFrame(u8 *a, u32 b, u32 c)
{
    struct T3 t;
    s16 x;
    s16 y;
    s16 m;

    t = d_021D3E58;
    x = BMP_GetWidth((const struct Bmp *)b) - 8;
    y = BMP_GetHeight((const struct Bmp *)b) - 8 - t.v[a[1]];
    m = y & 7;
    if (m != 0)
        BMP_Blit((struct Bmp *)c, (struct Bmp *)b, 0, 8 - m, x, y, 8, m, 0xFFFF);
    BMP_Blit((struct Bmp *)c, (struct Bmp *)b, 0, 0, x, y + m, 8, 8 - m, 0xFFFF);
    a[2]++;
    if (a[2] >= 4) {
        a[2] = 0;
        a[1]++;
        a[1] = a[1] % 3;
    }
    x = BMP_GetWidth((const struct Bmp *)b) - 8;
    y = BMP_GetHeight((const struct Bmp *)b) - 8 - t.v[a[1]];
    BMP_Blit((struct Bmp *)(((struct Obj02692 *)a)->f4), (struct Bmp *)b, 0, 0, x, y, 8, 8, 0);
    a[0] = 1;
}
