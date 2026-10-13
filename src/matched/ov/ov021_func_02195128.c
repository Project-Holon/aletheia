/*
 * function: TALKMSGWIN_GetWindowCornerPoints
 * address:  0x02195128
 * packet:   pkt_ov021_02195128
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   BMP_WIN_GetDispWidth  0x02045748  arm
 *   BMP_WIN_GetDispHeight  0x02045750  arm
 *   func_0206E0C4  0x0206E0C4  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07457.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
extern u8 BMP_WIN_GetPosX(struct Descriptor *p);
extern u8 BMP_WIN_GetPosY(struct Descriptor *p);
extern u8 BMP_WIN_GetDispWidth(struct Descriptor *p);
extern u8 BMP_WIN_GetDispHeight(struct Descriptor *p);
extern void func_0206E0C4(int x, int y, u32 c, int z);

void TALKMSGWIN_GetWindowCornerPoints(u8 *p, u32 c0, u32 c1, u32 c2, u32 c3)
{
    int x;
    int y;
    int w;
    int h;

    x = BMP_WIN_GetPosX((struct Descriptor *)(((struct Obj07457 *)p)->fC)) << 3;
    y = (BMP_WIN_GetPosY((struct Descriptor *)(((struct Obj07457 *)p)->fC)) - 1) << 3;
    w = BMP_WIN_GetDispWidth((struct Descriptor *)(((struct Obj07457 *)p)->fC)) << 3;
    h = (BMP_WIN_GetDispHeight((struct Descriptor *)(((struct Obj07457 *)p)->fC)) + 2) << 3;
    func_0206E0C4(x, y, c0, 0);
    func_0206E0C4(x + w, y, c1, 0);
    func_0206E0C4(x, y + h, c2, 0);
    func_0206E0C4(x + w, y + h, c3, 0);
}
