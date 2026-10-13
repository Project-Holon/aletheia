/*
 * function: FLD_SCENEAREA_GetCamera
 * address:  0x021AB760
 * packet:   pkt_021AB760
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
#include "../include/Obj18075.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FLD_SCENEAREA_GetCamera(u8 *p)
{
    return ((struct Obj18075 *)p)->f0;
}
