/*
 * unit: yes
 * function: POKETRADE_SAVE_SetCameraTrade, POKETRADE_SAVE_Update3DParticles
 * address: 0x021E2BD0
 * packet: pkt_ov119_021E2BD0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_CAMERA_SetEye 0x02048AFC arm
 *   G3D_CAMERA_SetCamTarget 0x02048B44 arm
 *   G3D_CAMERA_SetNear 0x02048B60 arm
 *   G3D_CAMERA_SetFar 0x02048B6C arm
 *   G3D_CAMERA_SetCamUp 0x02048B20 arm
 *   POKETRADE_3D_DrawRotatingCube 0x021E3A40 thumb ov119
 */
#include "../include/Obj06427.h"
typedef struct {int x,y,z;} Vec;
extern void G3D_CAMERA_SetEye(void *,Vec *);
extern void G3D_CAMERA_SetCamTarget(void *,Vec *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Light;
extern void G3D_CAMERA_SetNear(struct Light *l, const u32 *in);
extern void G3D_CAMERA_SetFar(struct Light *l, const u32 *in);
extern void G3D_CAMERA_SetCamUp(void *,Vec *);
void POKETRADE_SAVE_SetCameraTrade(char *p) {
    Vec a;
    Vec b;
    int c=0x1f40000;
    int d=0x1000;
    a.x=0; a.y=0x3000; a.z=0xf000;
    b.x=0; b.y=0; b.z=0;
    G3D_CAMERA_SetEye(((struct Obj06427 *)p)->f83C,&a);
    G3D_CAMERA_SetCamTarget(((struct Obj06427 *)p)->f83C,&b);
    G3D_CAMERA_SetNear(((struct Obj06427 *)p)->f83C,(const u32 *)(&d));
    G3D_CAMERA_SetFar(((struct Obj06427 *)p)->f83C,(const u32 *)(&c));
    b.x=0; b.y=0x10000; b.z=0x1000;
    G3D_CAMERA_SetCamUp(((struct Obj06427 *)p)->f83C,&b);
}
extern void POKETRADE_3D_DrawRotatingCube(const u8 *p);
void POKETRADE_SAVE_Update3DParticles(char *p) {POKETRADE_3D_DrawRotatingCube((const u8 *)p);}
