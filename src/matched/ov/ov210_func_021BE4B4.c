/*
 * function: func_021BE4B4
 * address:  0x021BE4B4
 * packet:   pkt_021BE4B4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE44C  0x021BE44C  thumb ov210
 */
#include "../include/Obj00222.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;
extern void func_021BE44C(u8 *p, int slot, u32 message, int x, int y, u16 color, u32 mode);

void func_021BE4B4(u8 *p)
{
    if (*(u8 *)(*(u32 *)(*(u32 *)&((struct Obj00222 *)p)->f0 + 8)) == 0)
        func_021BE44C(p, 0, 0x12, 0, 4, 0x3C40, 0);
    else
        func_021BE44C(p, 0, 0x11, 0, 4, 0x3C40, 0);
    func_021BE44C(p, 2, 0xC, 0x28, 4, 0x3C40, 2);
    func_021BE44C(p, 3, 0xD, 0x28, 4, 0x3C40, 2);
    func_021BE44C(p, 4, 0xE, 0x28, 4, 0x3C40, 2);
    func_021BE44C(p, 5, 0xF, 0x28, 4, 0x3C40, 2);
    func_021BE44C(p, 6, 0x10, 0x28, 4, 0x3C40, 2);
    func_021BE44C(p, 0xB, 0x14, 0x28, 4, 0x3C40, 2);
}
