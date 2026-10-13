/*
 * function: FIELD_CAMERA_SetFov
 * address:  0x0218ED64
 * packet:   pkt_ov021_0218ED64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FX_SinCosTable_  0x020A1B38  data
 *   G3D_CAMERA_SetNearClip  0x02048B80  arm  arm9
 *   G3D_CAMERA_SetFarClip  0x02048B94  arm  arm9
 */
#include "../include/Obj05979.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern s16 FX_SinCosTable_[];
struct Light;
extern void G3D_CAMERA_SetNearClip(struct Light *l, u32 v);
extern void G3D_CAMERA_SetFarClip(struct Light *l, u32 v);

void FIELD_CAMERA_SetFov(u8 *a, u16 angle)
{
    ((struct Obj05979 *)a)->f80 = angle;
    G3D_CAMERA_SetNearClip((struct Light *)(((struct Obj05979 *)a)->fC), FX_SinCosTable_[(((struct Obj05979 *)a)->f80 >> 4) * 2]);
    G3D_CAMERA_SetFarClip((struct Light *)(((struct Obj05979 *)a)->fC), FX_SinCosTable_[(((struct Obj05979 *)a)->f80 >> 4) * 2 + 1]);
}
