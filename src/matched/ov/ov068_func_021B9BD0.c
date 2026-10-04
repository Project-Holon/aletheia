/*
 * function: func_021B9BD0
 * address: 0x021B9BD0
 * packet: pkt_ov068_021B9BD0
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9D68 0x021B9D68 thumb ov068
 */
#include "../include/Obj13138.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B9D68(u16 *, u16 *, int, u32, u8, u16, u16);
void func_021B9BD0(u8 *p)
{
    func_021B9D68((u16 *)(p + 0x50), (u16 *)(p + 0x4c), 0x400, 7, 1,
                 ((struct Obj13138 *)p)->f72, ((struct Obj13138 *)p)->f74);
}
