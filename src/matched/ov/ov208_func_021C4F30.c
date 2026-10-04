/*
 * function: ov208_func_021C4F30
 * address:  0x021C4F30
 * packet:   pkt_ov208_021C4F30
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02041EE4  0x02041EE4  arm
 */
#include "../include/Obj14663.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02041EE4(u32 index, u32 a, u32 b);

void ov208_func_021C4F30(void *unused, u8 *p)
{
    switch (((struct Obj14663 *)p)->f6B8) {
    case 0:
        func_02041EE4(2, 0, -0x40);
        break;
    case 4:
        if (((struct Obj14663 *)p)->f548 >= 2)
            func_02041EE4(2, 0, 0);
        else
            func_02041EE4(2, 0, -0x40);
        break;
    }
}
