/*
 * unit: yes
 * function: func_021E2BD0, func_021E2C34
 * address: 0x021E2BD0
 * packet: pkt_ov119_021E2BD0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_CAMERA_SetEye 0x02048AFC arm
 *   G3D_CAMERA_SetUp 0x02048B44 arm
 *   G3D_CAMERA_SetScale 0x02048B60 arm
 *   G3D_CAMERA_SetRoll 0x02048B6C arm
 *   G3D_CAMERA_SetTarget 0x02048B20 arm
 *   func_021E3A40 0x021E3A40 thumb ov119
 */
#include "../include/Obj06427.h"
typedef struct {int x,y,z;} Vec;
extern void G3D_CAMERA_SetEye(void *,Vec *);
extern void G3D_CAMERA_SetUp(void *,Vec *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Light;
extern void G3D_CAMERA_SetScale(struct Light *l, const u32 *in);
extern void G3D_CAMERA_SetRoll(struct Light *l, const u32 *in);
extern void G3D_CAMERA_SetTarget(void *,Vec *);
void func_021E2BD0(char *p) {
    Vec a;
    Vec b;
    int c=0x1f40000;
    int d=0x1000;
    a.x=0; a.y=0x3000; a.z=0xf000;
    b.x=0; b.y=0; b.z=0;
    G3D_CAMERA_SetEye(((struct Obj06427 *)p)->f83C,&a);
    G3D_CAMERA_SetUp(((struct Obj06427 *)p)->f83C,&b);
    G3D_CAMERA_SetScale(((struct Obj06427 *)p)->f83C,(const u32 *)(&d));
    G3D_CAMERA_SetRoll(((struct Obj06427 *)p)->f83C,(const u32 *)(&c));
    b.x=0; b.y=0x10000; b.z=0x1000;
    G3D_CAMERA_SetTarget(((struct Obj06427 *)p)->f83C,&b);
}
extern void func_021E3A40(const u8 *p);
void func_021E2C34(char *p) {func_021E3A40((const u8 *)p);}
