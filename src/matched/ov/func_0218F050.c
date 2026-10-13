/*
 * function: FIELD_CAMERA_StopDelayLog
 * address:  0x0218F050
 * packet:   pkt_0218F050
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00612.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int FIELD_CAMERA_StopDelayLog(u32 a)
{
((struct Obj00612 *)((u8 *)(a)))->f2C = 0;
((struct Obj00612 *)((u8 *)(a)))->f28 = 0;
((struct Obj00612 *)((u8 *)(a)))->f10 = 0;
return a;
}

