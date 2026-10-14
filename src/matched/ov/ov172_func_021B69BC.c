/*
 * function: CTVT_CAMERA_SelectCamera
 * address:  0x021B69BC
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Record the new value and raise the pending flag when it changes.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08254.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void CTVT_CAMERA_SelectCamera(void *p, u32 v)
{
    if (((struct Obj08254 *)p)->f2C == v) {
        return;
    }
    if (((struct Obj08254 *)p)->f20 != 0) {
        return;
    }
    ((struct Obj08254 *)p)->f2C = v;
    ((struct Obj08254 *)p)->f20 = 1;
}
