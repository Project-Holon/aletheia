/*
 * function: FIELDMAP_GetGroundBbdAct
 * address:  0x02188C90
 * packet:   pkt_02188C54
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Loads the 32-bit word at byte +0xb8 of the object.
 */
#include "../include/Obj17864.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELDMAP_GetGroundBbdAct(u8 *p)
{
    return ((struct Obj17864 *)p)->fB8;
}

