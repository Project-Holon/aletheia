/*
 * function: FIELD_CAMERA_GetAreasEnabled
 * address:  0x0218F1B4
 * packet:   pkt_0218EC2C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Loads the byte at byte +0xe9 of the object.
 */
#include "../include/Obj17916.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 FIELD_CAMERA_GetAreasEnabled(u8 *p)
{
    return ((struct Obj17916 *)p)->fE9;
}

