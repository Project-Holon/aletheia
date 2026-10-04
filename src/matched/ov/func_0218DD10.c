/*
 * function: func_0218DD10
 * address:  0x0218DD10
 * packet:   pkt_0218DC6C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 16-bit halfword at +0x10 of the object.
 */
#include "../include/Obj17899.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 func_0218DD10(u8 *p)
{
    return ((struct Obj17899 *)p)->f10;
}

