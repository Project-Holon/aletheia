/*
 * function: FIELD_G3D_MAPPER_SlotResGetBuildModel
 * address:  0x0218DD04
 * packet:   pkt_0218DC6C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Loads the 32-bit word at byte +0x4 of the object.
 */
#include "../include/Obj17898.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int FIELD_G3D_MAPPER_SlotResGetBuildModel(u8 *p)
{
    return ((struct Obj17898 *)p)->f4;
}

