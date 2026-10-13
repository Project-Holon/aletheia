/*
 * function: FIELDMAP_GetFld3dCi
 * address:  0x02189A00
 * packet:   pkt_02189A00
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x124 of the object.
 */
#include "../include/Obj00020.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void *FIELDMAP_GetFld3dCi(u8 *p)
{
    return ((struct Obj00020 *)p)->f124;
}

