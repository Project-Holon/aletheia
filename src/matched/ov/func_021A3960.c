/*
 * function: func_021A3960
 * address:  0x021A3960
 * packet:   pkt_021A36E0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x1c of the object.
 */
#include "../include/Obj18036.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void *func_021A3960(u8 *p)
{
    return ((struct Obj18036 *)p)->f1C;
}

