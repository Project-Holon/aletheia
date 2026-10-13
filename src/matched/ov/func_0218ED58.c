/*
 * function: FIELD_CAMERA_SetDistance
 * address:  0x0218ED58
 * packet:   pkt_0218ED58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter at +0x7c.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17914.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FIELD_CAMERA_SetDistance(u8 *p, u32 v)
{
    ((struct Obj17914 *)p)->f7C = v;
}
