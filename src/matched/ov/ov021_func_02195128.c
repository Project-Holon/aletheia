/*
 * function: func_02195128
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
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045748  0x02045748  arm
 *   func_02045750  0x02045750  arm
 *   func_0206E0C4  0x0206E0C4  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07457.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045748(struct Descriptor *p);
extern u8 func_02045750(struct Descriptor *p);
extern void func_0206E0C4(int x, int y, u32 c, int z);

void func_02195128(u8 *p, u32 c0, u32 c1, u32 c2, u32 c3)
{
    int x;
    int y;
    int w;
    int h;

    x = func_02045758((struct Descriptor *)(((struct Obj07457 *)p)->fC)) << 3;
    y = (func_02045760((struct Descriptor *)(((struct Obj07457 *)p)->fC)) - 1) << 3;
    w = func_02045748((struct Descriptor *)(((struct Obj07457 *)p)->fC)) << 3;
    h = (func_02045750((struct Descriptor *)(((struct Obj07457 *)p)->fC)) + 2) << 3;
    func_0206E0C4(x, y, c0, 0);
    func_0206E0C4(x + w, y, c1, 0);
    func_0206E0C4(x, y + h, c2, 0);
    func_0206E0C4(x + w, y + h, c3, 0);
}
