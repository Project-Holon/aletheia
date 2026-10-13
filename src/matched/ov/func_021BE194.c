/*
 * function: ENTRANCE_CAMERA_GetEntranceType
 * address:  0x021BE194
 * packet:   pkt_021BE194
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
 *   ENTRANCE_CAMERA_GetRequest  0x021BE180  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18254.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u8 *ENTRANCE_CAMERA_GetRequest(u8 *p);

int ENTRANCE_CAMERA_GetEntranceType(u32 a)
{
return ((struct Obj18254 *)((u8 *)(ENTRANCE_CAMERA_GetRequest((u8 *)a))))->f0;
}

