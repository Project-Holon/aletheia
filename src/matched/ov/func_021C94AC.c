/*
 * function: func_021C94AC
 * address:  0x021C94AC
 * packet:   pkt_021C94AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12137.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021C94AC(u32 a)
{
return (((struct Obj12137 *)((u8 *)(a)))->f0 + *(u16 *)((u8 *)(((struct Obj12137 *)((u8 *)(a)))->f0)));
}

