/*
 * function: func_021A2C2C
 * address:  0x021A2C2C
 * packet:   pkt_021A2C2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter at +0x8.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18006.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_021A2C2C(u8 *p, u32 v)
{
    ((struct Obj18006 *)p)->f8 = v;
}
