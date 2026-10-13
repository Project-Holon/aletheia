/*
 * function: FIELDMAP_GetFog
 * address:  0x02188C64
 * packet:   pkt_ov021_02188C64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor: returns the +0x18 member.
 *
 * symbols:
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19488.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

u32 FIELDMAP_GetFog(u8 *p)
{
    return ((struct Obj19488 *)p)->f18;
}
