/*
 * function: func_021ABE24
 * address:  0x021ABE24
 * packet:   pkt_021AB764
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0xc of the object.
 */
#include "../include/Obj18081.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_021ABE24(u8 *p)
{
    return ((struct Obj18081 *)p)->fC;
}

