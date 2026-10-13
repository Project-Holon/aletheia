/*
 * function: FIELD_CAMERA_ANIME_SaveCameraMode
 * address:  0x0218FFE8
 * packet:   pkt_ov021_0218FFE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_CAMERA_GetMode  0x0218E138  thumb
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb
 */
#include "../include/Obj02372.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 FIELD_CAMERA_GetMode(u8 *p);
extern void FIELD_CAMERA_SetMode(u8 *a, u32 s);

void FIELD_CAMERA_ANIME_SaveCameraMode(u8 *a, u32 a1, u32 a2, u32 a3)
{
    void *x = ((struct Obj02372 *)a)->f4;
    ((struct Obj02372 *)a)->f10 = FIELD_CAMERA_GetMode(x);
    FIELD_CAMERA_SetMode(x, 0);
}
