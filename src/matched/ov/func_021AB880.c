/*
 * function: FLD_SCENEAREA_LOADER_GetRecs
 * address:  0x021AB880
 * packet:   pkt_021AB880
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter at +0x0.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18077.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FLD_SCENEAREA_LOADER_GetRecs(u8 *p)
{
    return ((struct Obj18077 *)p)->f0;
}
