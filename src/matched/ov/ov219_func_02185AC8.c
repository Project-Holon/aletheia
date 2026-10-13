/*
 * function: func_02185AC8
 * address: 0x02185AC8
 * packet: pkt_ov219_02185AC8
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_CAMERA_GetEye 0x02048AE8 arm
 *   G3D_CAMERA_GetUp 0x02048B30 arm
 *   G3D_CAMERA_SetEye 0x02048AFC arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   VEC_Normalize 0x0207CCA4 arm
 *   func_0207CEE4 0x0207CEE4 arm
 */
#include "../include/Obj02935.h"
typedef struct {long x,y,z;} Vec;
extern void G3D_CAMERA_GetEye(void *,Vec *),G3D_CAMERA_GetUp(void *,Vec *),G3D_CAMERA_SetEye(void *,const Vec *);
extern void func_0207CA00(const Vec *,const Vec *,Vec *),VEC_Normalize(const Vec *,Vec *),func_0207CEE4(long,const Vec *,const Vec *,Vec *);
extern long func_0207CBD0(const Vec *);
int func_02185AC8(char *p)
{
    Vec position,target,direction;
    long distance;
    int done;
    done=0;
    G3D_CAMERA_GetEye(((struct Obj02935 *)p)->fC36C,&position);
    G3D_CAMERA_GetUp(((struct Obj02935 *)p)->fC36C,&target);
    func_0207CA00(&position,&target,&direction);
    distance=func_0207CBD0(&direction);
    VEC_Normalize(&direction,&direction);
    switch(((struct Obj02935 *)p)->fC30C) {
    case 1:
        if(distance>360448) {
            distance-=32768;
            ((struct Obj02935 *)p)->fC300-=128;
            ((struct Obj02935 *)p)->fC304=((struct Obj02935 *)p)->fC300;
        } else {distance=327680;done=1;}
        break;
    case 0:
        if(distance<1179648) {
            distance+=32768;
            ((struct Obj02935 *)p)->fC300+=128;
            ((struct Obj02935 *)p)->fC304=((struct Obj02935 *)p)->fC300;
        } else {distance=1212416;done=1;}
        break;
    }
    func_0207CEE4(distance,&direction,&target,&position);
    G3D_CAMERA_SetEye(((struct Obj02935 *)p)->fC36C,&position);
    return done;
}
