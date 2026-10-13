/*
 * function: FLD_SCENEAREA_HasCheck
 * address:  0x021AB768
 * packet:   pkt_021AB768
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12093.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int FLD_SCENEAREA_HasCheck(u32 a, u32 b)
{
if (((struct Obj12093 *)((u8 *)(a)))->f8 > b) {
    if (*(u32 *)((u8 *)(((struct Obj12093 *)((u8 *)(a)))->f0) + ((b << 2))) != 0) {
        return 1;
    }
}
return 0;
}

