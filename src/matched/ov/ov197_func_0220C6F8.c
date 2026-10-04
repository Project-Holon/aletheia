/*
 * function: func_0220C6F8
 * address:  0x0220C6F8
 * packet:   pkt_0220C6F8
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02209B60  0x02209B60  thumb  ov094
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25046.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_02209B60(u32, u32, u32, u32, u32, u32);

void func_0220C6F8(u8 *p, u32 a, u32 b)
{
    func_02209B60(((struct Obj25046 *)p)->f14C, a, b, 2, 6, 0x14);
}

