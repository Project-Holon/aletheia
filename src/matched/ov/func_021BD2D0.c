/*
 * function: func_021BD2D0
 * address:  0x021BD2D0
 * packet:   pkt_021BD2D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Field setter at +0x48 through a displaced pointer.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18222.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_021BD2D0(u8 *p, u16 v)
{
    ((struct Obj18222 *)p)->f48 = v;
}
