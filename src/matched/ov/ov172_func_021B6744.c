/*
 * function: CTVT_CAMERA_SetFrameCallback
 * address:  0x021B6744
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Store both u32 words at +0x3c and +0x40.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14293.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void CTVT_CAMERA_SetFrameCallback(void *p, u32 a, u32 b)
{
    ((struct Obj14293 *)p)->f3C = a;
    ((struct Obj14293 *)p)->f40 = b;
}
