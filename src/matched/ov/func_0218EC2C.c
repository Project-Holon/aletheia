/*
 * function: FIELD_CAMERA_GetG3dCamera
 * address:  0x0218EC2C
 * packet:   pkt_0218EC2C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0xc of the object.
 */
#include "../include/Obj17906.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_CAMERA_GetG3dCamera(u8 *p)
{
    return ((struct Obj17906 *)p)->fC;
}

