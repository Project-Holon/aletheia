/*
 * function: func_021B8040
 * address:  0x021B8040
 * packet:   pkt_021B8038
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the byte at byte +0x2c of the object.
 */
#include "../include/Obj18103.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 func_021B8040(u8 *p)
{
    return ((struct Obj18103 *)p)->f2C;
}

