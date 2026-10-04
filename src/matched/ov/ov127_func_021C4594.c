/*
 * function: func_021C4594
 * address:  0x021C4594
 * packet:   pkt_021C4594
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204ADA4  0x0204ADA4  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14020.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0204ADA4(u32 i);

void func_021C4594(u8 *p)
{
    func_0204ADA4((u32)(((struct Obj14020 *)p)->f2F4));
    *(u32 *)&((struct Obj14020 *)p)->f2F4 = (u32)-1;
}
