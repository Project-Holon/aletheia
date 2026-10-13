/*
 * function: FIELDMAP_GetLight
 * address:  0x02188C60
 * packet:   pkt_ov021_02188C60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf getter: the word at +0x14.
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19487.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

u32 FIELDMAP_GetLight(u8 *p)
{
    return ((struct Obj19487 *)p)->f14;
}
