/*
 * function: FIELD_G3D_MAPPER_GetCellGridIndex
 * address:  0x0218DD98
 * packet:   pkt_0218DD98
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
#include "../include/Obj17904.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_G3D_MAPPER_GetCellGridIndex(u8 *p)
{
    return ((struct Obj17904 *)p)->f0;
}
