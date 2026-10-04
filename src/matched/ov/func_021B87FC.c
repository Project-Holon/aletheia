/*
 * function: func_021B87FC
 * address:  0x021B87FC
 * packet:   pkt_021B87FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02659.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 *func_021B87FC(u8 *p, u32 idx)
{
    if (((struct Obj02659 *)p)->f2 > idx)
        return *(u8 * *)&((struct Obj02659 *)p)->f14 + idx * 0x48;
    if (idx == 0xFFFF)
        return 0;
    return *(u8 * *)&((struct Obj02659 *)p)->f14;
}
