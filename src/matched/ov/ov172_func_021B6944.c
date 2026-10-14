/*
 * function: CTVT_CAMERA_GetHeight
 * address:  0x021B6944
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Width of the u16 pair at +0x38/+0x3a, zero extended.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01264.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u16 CTVT_CAMERA_GetHeight(void *p)
{
    return (u16)(((struct Obj01264 *)p)->f3A - ((struct Obj01264 *)p)->f38);
}
