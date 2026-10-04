/*
 * function: func_0216D7D4
 * address:  0x0216D7D4
 * packet:   pkt_0216D7D4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the halfword field at +0x28.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */
#include "../include/Obj17827.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


u16 func_0216D7D4(u8 *p)
{
    return ((struct Obj17827 *)p)->f28;
}

