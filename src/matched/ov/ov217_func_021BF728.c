/*
 * function: func_021BF728
 * address:  0x021BF728
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear both +0x30 and +0x3d4.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BF728(void *p)
{
    ((struct Obj00021 *)p)->f30 = 0;
    ((struct Obj00021 *)p)->f3D4 = 0;
}
