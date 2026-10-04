/*
 * function: func_02190678
 * address:  0x02190678
 * packet:   pkt_0218FE70
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0xc of the object.
 */
#include "../include/Obj17926.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_02190678(u8 *p)
{
    return ((struct Obj17926 *)p)->fC;
}

