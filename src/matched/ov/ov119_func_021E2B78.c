/*
 * function: POKETRADE_SAVE_SetCameraSummary
 * address: 0x021E2B78
 * packet: pkt_ov119_021E2B78
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_CAMERA_SetEye 0x02048AFC arm
 *   G3D_CAMERA_SetCamTarget 0x02048B44 arm
 *   G3D_CAMERA_SetFar 0x02048B6C arm
 *   G3D_CAMERA_SetCamUp 0x02048B20 arm
 */
#include "../include/Obj08066.h"
typedef struct {int x,y,z;} Vec;
extern void G3D_CAMERA_SetEye(void *,Vec *);
extern void G3D_CAMERA_SetCamTarget(void *,Vec *);
typedef unsigned int   u32;
struct Light;
extern void G3D_CAMERA_SetFar(struct Light *l, const u32 *in);
extern void G3D_CAMERA_SetCamUp(void *,Vec *);
void POKETRADE_SAVE_SetCameraSummary(char *p) {
    Vec a;
    Vec b;
    a.x=0; a.y=0x2b000; a.z=0xf1000;
    b.x=0; b.y=0x2b000; b.z=0;
    G3D_CAMERA_SetEye(((struct Obj08066 *)p)->f83C,&a);
    G3D_CAMERA_SetCamTarget(((struct Obj08066 *)p)->f83C,&b);
    a.z-=0x1000;
    G3D_CAMERA_SetFar(((struct Obj08066 *)p)->f83C,(const u32 *)(&a.z));
    b.x=0; b.y=0x1000; b.z=0;
    G3D_CAMERA_SetCamUp(((struct Obj08066 *)p)->f83C,&b);
}
