/*
 * function: TALKMSGWIN_SaveCamera
 * address:  0x0219545C
 * packet:   pkt_0219545C
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
 *   G3D_CAMERA_GetEye  0x02048AE8  arm
 *   G3D_CAMERA_GetCamUp  0x02048B0C  arm
 *   G3D_CAMERA_GetCamTarget  0x02048B30  arm
 *   G3D_CAMERA_GetNear  0x02048B54  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07211.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 G3D_CAMERA_GetEye(u32, u32, u32, u32);
extern u32 G3D_CAMERA_GetCamUp(u32, u32);
extern u32 G3D_CAMERA_GetCamTarget(u32, u32);
extern u32 G3D_CAMERA_GetNear(u32, u32);

int TALKMSGWIN_SaveCamera(u32 a, u32 b, u32 c, u32 d)
{
G3D_CAMERA_GetEye(((struct Obj07211 *)((u8 *)(a)))->f4, (a + (202 << 4)), c, d);
G3D_CAMERA_GetCamUp(((struct Obj07211 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 12)));
G3D_CAMERA_GetCamTarget(((struct Obj07211 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 24)));
return G3D_CAMERA_GetNear(((struct Obj07211 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 36)));
}

