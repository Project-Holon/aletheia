/*
 * function: FIELD_CAMERA_GetMode
 * address:  0x0218E138
 * packet:   pkt_0218DC6C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x14 of the object.
 */
#include "../include/Obj17905.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_CAMERA_GetMode(u8 *p)
{
    return ((struct Obj17905 *)p)->f14;
}

