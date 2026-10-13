/*
 * function: FIELD_CAMERA_ANIME_Start
 * address:  0x0218FF00
 * packet:   pkt_0218FF00
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
 *   FIELD_CAMERA_ANIME_GetData  0x021901E8  thumb  ov021
 *   FIELD_CAMERA_ANIME_ApplyEndParam  0x02190110  thumb  ov021
 *   FIELD_CAMERA_ANIME_StartMoveTasks  0x0219014C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17918.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_CAMERA_ANIME_ApplyEndParam(u32);
extern u32 FIELD_CAMERA_ANIME_StartMoveTasks(u32);
extern u32 FIELD_CAMERA_ANIME_GetData(u8 *p);

int FIELD_CAMERA_ANIME_Start(u32 a)
{
if (((struct Obj17918 *)((u8 *)(FIELD_CAMERA_ANIME_GetData((u8 *)a))))->f0 == 0) {
    return FIELD_CAMERA_ANIME_ApplyEndParam(a);
}
return FIELD_CAMERA_ANIME_StartMoveTasks(a);
}

