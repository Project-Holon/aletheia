/*
 * function: FIELDMAP_SetInfoWindow
 * address:  0x02188D4C
 * packet:   pkt_02188D4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter at +0x2c.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17882.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FIELDMAP_SetInfoWindow(u8 *p, u32 v)
{
    ((struct Obj17882 *)p)->f2C = v;
}
