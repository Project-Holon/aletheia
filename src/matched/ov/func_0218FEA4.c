/*
 * function: FIELD_CAMERA_ANIME_Setup
 * address:  0x0218FEA4
 * packet:   pkt_0218FEA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_CAMERA_ANIME_SaveCameraMode  0x0218FFE8  thumb  ov021
 *   FIELD_CAMERA_ANIME_SetAnglesFromPos  0x02190058  thumb  ov021
 *   FIELD_CAMERA_ANIME_SetTargetFromCurrent  0x021900A8  thumb  ov021
 *   FIELD_CAMERA_ANIME_SaveCameraState  0x0218FF78  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02372.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_CAMERA_ANIME_SaveCameraState(u32 *p);
extern void FIELD_CAMERA_ANIME_SaveCameraMode(u8 *a, u32 a1, u32 a2, u32 a3);
extern void FIELD_CAMERA_ANIME_SetAnglesFromPos(u8 *o);
extern void FIELD_CAMERA_ANIME_SetTargetFromCurrent(void *a);

int FIELD_CAMERA_ANIME_Setup(u32 a, u32 b, u32 c, u32 d)
{
FIELD_CAMERA_ANIME_SaveCameraMode((u8 *)a, b, c, d);
FIELD_CAMERA_ANIME_SetAnglesFromPos((u8 *)(*(u32 *)&((struct Obj02372 *)((u8 *)(a)))->f4));
FIELD_CAMERA_ANIME_SetTargetFromCurrent((void *)(*(u32 *)&((struct Obj02372 *)((u8 *)(a)))->f4));
return FIELD_CAMERA_ANIME_SaveCameraState((u32 *)a);
}

