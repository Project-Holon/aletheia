/*
 * function: FLD_SCENEAREA_LOADER_GetRecCount
 * address:  0x021AB884
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
#include "../include/Obj18078.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FLD_SCENEAREA_LOADER_GetRecCount(u8 *p)
{
    return ((struct Obj18078 *)p)->f4;
}

