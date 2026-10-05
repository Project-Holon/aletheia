/*
 * function: func_0218ED2C
 * address:  0x0218ED2C
 * packet:   pkt_0218EC2C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Loads the halfword at byte +0x78 of the object.
 */
#include "../include/Obj17909.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 func_0218ED2C(u8 *p)
{
    return ((struct Obj17909 *)p)->f78;
}

