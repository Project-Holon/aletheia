/*
 * function: func_021BA390
 * address: 0x021BA390
 * packet: pkt_ov181_021BA390
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021BA4AA, then labelled 021BA4AC.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_GetPixels 0x020437D4 arm
 *   func_021BA354 0x021BA354 thumb ov181
 *   func_021B9DCC 0x021B9DCC thumb ov181
 */
#include "../include/Obj04570.h"
typedef unsigned short u16;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct Bmp { void *pixels; u16 width, height, depth, kind; };
extern void *BMP_GetPixels(const struct Bmp *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021BA354(u8 *p, u8 *out, u32 n);
extern void func_021B9DCC(char *, unsigned);
void func_021BA390(char *p)
{
    char *a, *b;
    unsigned n;
    u16 i, j, k, l, m, o;
    unsigned x, y;
    if (((struct Obj04570 *)p)->f2E0 == 0) return;
    ((struct Obj04570 *)p)->f2DC += 0x1000;
    if (((struct Obj04570 *)p)->f2DC < 0x1000) return;
    ((struct Obj04570 *)p)->f2DC -= 0x1000;
    n = 1;
    if (((struct Obj04570 *)p)->f2D2) n = 4;
    a = BMP_GetPixels(BMP_WIN_GetBmp(((struct Obj04570 *)p)->f2BC));
    b = BMP_GetPixels(BMP_WIN_GetBmp(((struct Obj04570 *)p)->f2C4));
    x = 0;
    for (i = 0; i < 32; i++, x += 32) func_021BA354((u8 *)(a + x), 0, n);
    for (j = 1; j < 25; j++) {
        x = j * 1024;
        y = (j - 1) * 1024;
        for (k = 0; k < 32; k++, x += 32, y += 32) func_021BA354((u8 *)(a + x), (u8 *)(a + y), n);
    }
    x = 0;
    y = 0x6000;
    for (l = 0; l < 32; l++, x += 32, y += 32) func_021BA354((u8 *)(b + x), (u8 *)(a + y), n);
    for (m = 1; m < 28; m++) {
        x = m * 1024;
        y = (m - 1) * 1024;
        for (o = 0; o < 32; o++, x += 32, y += 32) func_021BA354((u8 *)(b + x), (u8 *)(b + y), n);
    }
    func_021B9DCC(p, 3);
}
