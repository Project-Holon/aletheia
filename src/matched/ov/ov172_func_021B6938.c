/*
 * function: CTVT_CAMERA_GetWidth
 * address:  0x021B6938
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Width of the u16 pair at +0x34/+0x36, zero extended.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01264.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u16 CTVT_CAMERA_GetWidth(void *p)
{
    return (u16)(((struct Obj01264 *)p)->f36 - ((struct Obj01264 *)p)->f34);
}
