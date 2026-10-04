/*
 * function: func_0218BD20
 * address:  0x0218BD20
 * packet:   pkt_0218BB04
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x8 of the object.
 */
#include "../include/Obj17894.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_0218BD20(u8 *p)
{
    return ((struct Obj17894 *)p)->f8;
}

