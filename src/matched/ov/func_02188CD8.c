/*
 * function: FIELDMAP_GetG3dObjCtrl
 * address:  0x02188CD8
 * packet:   pkt_02188CD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf getter at +0x130.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17872.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELDMAP_GetG3dObjCtrl(u8 *p)
{
    return ((struct Obj17872 *)p)->f130;
}
