/*
 * function: func_02188CB4
 * address:  0x02188CB4
 * packet:   pkt_02188C54
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x8c of the object.
 */
#include "../include/Obj00020.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void *func_02188CB4(u8 *p)
{
    return ((struct Obj00020 *)p)->f8C;
}

