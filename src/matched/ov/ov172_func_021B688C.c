/*
 * function: CTVT_CAMERA_IsShutterSoundIdle
 * address:  0x021B688C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 1 when the byte at +0x44 is 6 or 0.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24060.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

int CTVT_CAMERA_IsShutterSoundIdle(void *p)
{
    u8 v = ((struct Obj24060 *)p)->f44;
    return v == 6 || v == 0;
}
