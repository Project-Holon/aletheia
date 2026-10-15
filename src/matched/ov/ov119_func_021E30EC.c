/*
 * function: POKETRADE_3D_Init3DScene
 * address: 0x021E30EC
 * packet: pkt_ov119_021E30EC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_Init3DProjection 0x021E2B14 thumb ov119
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   gCubeRotation 0x021E7AF4 data a4
 *   gCameraParams 0x020A1EB8 data a2
 *   g3dStateCallbacks 0x021E7AC4 data a4
 */
#include "../include/Obj04482.h"
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {u32 x,y,z;} Vec;
typedef struct {void (*call)(char *);u32 other;} Callback;
extern Vec gCubeRotation;
extern const s16 gCameraParams[];
extern Callback g3dStateCallbacks[];
extern void POKETRADE_SAVE_Init3DProjection(int);
extern void *G3D_UTIL_Create(u16,u16,u16);
extern void *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,Vec *,Vec *,Vec *,u16);
void POKETRADE_3D_Init3DScene(char *p)
{
    ((struct Obj04482 *)p)->f824=0xffff;
    ((struct Obj04482 *)p)->f109C=~0u;
    POKETRADE_SAVE_Init3DProjection(0x91);
    ((struct Obj04482 *)p)->f820=G3D_UTIL_Create(20,20,0x91);
    if (!((struct Obj04482 *)p)->f83C) {
        Vec a={0,0,0};
        Vec b={0,0,0};
        Vec c;
        u16 heap;
        heap=((struct Obj04482 *)p)->f5F4;
        c=gCubeRotation;
        ((struct Obj04482 *)p)->f83C=G3D_CAMERA_Create(0,gCameraParams[6],gCameraParams[7],0x1555,0,0x1000,0x400000,0,&a,&c,&b,heap);
    }
    if (((struct Obj04482 *)p)->f109C!=~0u)
        g3dStateCallbacks[*(u32 *)(p+0x109c)].call(p);
}
