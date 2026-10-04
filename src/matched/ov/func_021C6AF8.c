/*
 * function: func_021C6AF8
 * address:  0x021C6AF8
 * packet:   pkt_021C6AF8
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
#include "../include/Obj18313.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_021C6AF8(u8 *p, u32 v)
{
    ((struct Obj18313 *)p)->f8 = v;
}
