/*
 * function: func_021694FC
 * address:  0x021694FC
 * packet:   pkt_021694FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the halfword at p.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */
#include "../include/Obj17743.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


u16 func_021694FC(u8 *p)
{
    return ((struct Obj17743 *)p)->f0;
}

