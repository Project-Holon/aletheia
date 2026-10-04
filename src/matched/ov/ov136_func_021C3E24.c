/*
 * function: func_021C3E24
 * address:  0x021C3E24
 * packet:   pkt_021C3E24
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14181.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_020307B0(void *);

void func_021C3E24(u8 *p)
{
    if (((struct Obj14181 *)p)->f14)
        func_020307B0(((struct Obj14181 *)p)->f14);
    func_020307B0(p);
}
