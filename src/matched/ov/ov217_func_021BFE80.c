/*
 * function: func_021BFE80
 * address:  0x021BFE80
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear the u32 at +0x2d0.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25955.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BFE80(void *p)
{
    ((struct Obj25955 *)p)->f2D0 = 0;
}
