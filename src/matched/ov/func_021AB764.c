/*
 * function: FLD_SCENEAREA_GetFieldMap
 * address:  0x021AB764
 * packet:   pkt_021AB764
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x4 of the object.
 */
#include "../include/Obj18076.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FLD_SCENEAREA_GetFieldMap(u8 *p)
{
    return ((struct Obj18076 *)p)->f4;
}

