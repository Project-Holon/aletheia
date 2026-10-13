/*
 * function: FIELD_G3D_MAPPER_SetCellGridIndex
 * address:  0x0218DD80
 * packet:   pkt_0218DD80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter at +0x0.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17902.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FIELD_G3D_MAPPER_SetCellGridIndex(u8 *p, u32 v)
{
    ((struct Obj17902 *)p)->f0 = v;
}
