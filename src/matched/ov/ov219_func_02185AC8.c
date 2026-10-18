/*
 * function: BEACON_DETAIL_UpdateCamera
 * address: 0x02185AC8
 * packet: pkt_ov219_02185AC8
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_CAMERA_GetEye 0x02048AE8 arm
 *   G3D_CAMERA_GetCamTarget 0x02048B30 arm
 *   G3D_CAMERA_SetEye 0x02048AFC arm
 *   VEC_Subtract 0x0207CA00 arm
 *   VEC_Mag 0x0207CBD0 arm
 *   VEC_Normalize 0x0207CCA4 arm
 *   VEC_MultAdd 0x0207CEE4 arm
 */
#include "../include/Obj02935.h"
typedef struct {long x,y,z;} Vec;
extern void G3D_CAMERA_GetEye(void *,Vec *),G3D_CAMERA_GetCamTarget(void *,Vec *),G3D_CAMERA_SetEye(void *,const Vec *);
extern void VEC_Subtract(const Vec *,const Vec *,Vec *),VEC_Normalize(const Vec *,Vec *),VEC_MultAdd(long,const Vec *,const Vec *,Vec *);
extern long VEC_Mag(const Vec *);
int BEACON_DETAIL_UpdateCamera(char *p)
{
    Vec position,target,direction;
    long distance;
    int done;
    done=0;
    G3D_CAMERA_GetEye(((struct Obj02935 *)p)->fC36C,&position);
    G3D_CAMERA_GetCamTarget(((struct Obj02935 *)p)->fC36C,&target);
    VEC_Subtract(&position,&target,&direction);
    distance=VEC_Mag(&direction);
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
    VEC_MultAdd(distance,&direction,&target,&position);
    G3D_CAMERA_SetEye(((struct Obj02935 *)p)->fC36C,&position);
    return done;
}
