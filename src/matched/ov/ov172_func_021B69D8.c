/*
 * function: CTVT_CAMERA_RequestShutterSound1
 * address:  0x021B69D8
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Set the byte at +0x44 to 4.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24064.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void CTVT_CAMERA_RequestShutterSound1(void *p)
{
    ((struct Obj24064 *)p)->f44 = 4;
}
