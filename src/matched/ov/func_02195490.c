/*
 * function: TALKMSGWIN_RestoreCamera
 * address:  0x02195490
 * packet:   pkt_02195490
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
 *   G3D_CAMERA_SetEye  0x02048AFC  arm
 *   G3D_CAMERA_SetTarget  0x02048B20  arm
 *   G3D_CAMERA_SetUp  0x02048B44  arm
 *   G3D_CAMERA_SetScale  0x02048B60  arm
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05860.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 G3D_CAMERA_Reset(u32);
extern u32 G3D_CAMERA_SetEye(u32, u32, u32, u32);
extern u32 G3D_CAMERA_SetTarget(u32, u32);
extern u32 G3D_CAMERA_SetUp(u32, u32);
struct Light;
extern void G3D_CAMERA_SetScale(struct Light *l, const u32 *in);

int TALKMSGWIN_RestoreCamera(u32 a, u32 b, u32 c, u32 d)
{
G3D_CAMERA_SetEye(((struct Obj05860 *)((u8 *)(a)))->f4, (a + (202 << 4)), c, d);
G3D_CAMERA_SetTarget(((struct Obj05860 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 12)));
G3D_CAMERA_SetUp(((struct Obj05860 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 24)));
G3D_CAMERA_SetScale((struct Light *)(((struct Obj05860 *)((u8 *)(a)))->f4), (const u32 *)(a + ((202 << 4) + 36)));
return G3D_CAMERA_Reset(((struct Obj05860 *)((u8 *)(a)))->f4);
}

