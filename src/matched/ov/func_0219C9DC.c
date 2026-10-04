/*
 * function: func_0219C9DC
 * address:  0x0219C9DC
 * packet:   pkt_0219C9DC
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x4 of the object.
 */
#include "../include/Obj17968.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_0219C9DC(u8 *p)
{
    return ((struct Obj17968 *)p)->f4;
}

