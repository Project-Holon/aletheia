/*
 * function: FIELD_CAMERA_ANIME_SetData
 * address:  0x0218FEA0
 * packet:   pkt_0218FEA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter at +0x8.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17917.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FIELD_CAMERA_ANIME_SetData(u8 *p, u32 v)
{
    ((struct Obj17917 *)p)->f8 = v;
}
