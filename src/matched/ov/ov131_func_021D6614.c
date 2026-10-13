/*
 * function: P_STA_SUB_Main
 * address: 0x021D6614
 * packet: pkt_ov131_021D6614
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STA_SUB_UpdateTouch 0x021D7460 thumb ov131
 *   P_STA_SUB_UpdatePet 0x021D6F54 thumb ov131
 *   P_STA_SUB_SetPetOffset 0x021D79A8 thumb ov131
 *   MCSS_ResetVanishFlag 0x02015EB0 thumb
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   MCSS_SetOfsPosition 0x02015C78 thumb
 *   MCSS_SetOfsScale 0x02015D30 thumb
 *   G3D_CAMERA_SetEye 0x02048AFC arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   d_021DC234 0x021DC234 data a4
 *   d_021DC228 0x021DC228 data a4
 *   d_021DC198 0x021DC198 data a4
 *   d_021DC210 0x021DC210 data a4
 *   d_021DC170 0x021DC170 data a4
 *   d_021DC178 0x021DC178 data a4
 *   d_021DC168 0x021DC168 data a4
 */
#include "../include/Obj00200.h"
#include "../include/Obj05385.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct {int x,y,z;} Vec;
typedef struct {int v[2];} Pair;
extern void P_STA_SUB_UpdateTouch(u8 *,u8 *);
extern void P_STA_SUB_UpdatePet(u8 *,u8 *);
extern void P_STA_SUB_SetPetOffset(void *,u8 *,int);
extern void MCSS_ResetVanishFlag(void *);
extern void MCSS_SetVanishFlag(void *);
extern void MCSS_SetOfsPosition(void *p, u32 *src);
extern void MCSS_SetOfsScale(void *p, u32 *src);
extern void G3D_CAMERA_SetEye(void *,const Vec *);
struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);
extern const s16 d_020A1B38[];
extern const Vec d_021DC234,d_021DC228,d_021DC198,d_021DC210;
extern const Pair d_021DC170,d_021DC178,d_021DC168;
void P_STA_SUB_Main(u8 *a,u8 *p) {
    u32 st=((struct Obj00200 *)p)->f8;
    if(st==0 || st==2) {
        P_STA_SUB_UpdateTouch(a,p);
        P_STA_SUB_UpdatePet(a,p);
        return;
    }
    if(st==3) {
        Vec v48=d_021DC234;
        Vec v3c=d_021DC228;
        Vec v30={0,0,0};
        u8 c;
        p[0x9b]=p[0x9b]+1;
        if(p[0x9b]>5 && ((struct Obj00200 *)p)->fC==0) {
            MCSS_ResetVanishFlag(((struct Obj00200 *)p)->f0);
            MCSS_SetVanishFlag(((struct Obj00200 *)p)->f4);
            ((struct Obj00200 *)p)->fC=1;
        }
        c=p[0x9b];
        if(c>=10) {
            P_STA_SUB_SetPetOffset(a,p,0);
            ((struct Obj00200 *)p)->f8=0;
        } else {
            u16 ang;
            v48.x=c*0x19000/10-0x42000;
            ang=(p[0x9b]<<15)/10;
            v30.y=d_020A1B38[(ang>>4)*2]<<5;
            if(((struct Obj00200 *)p)->f10==1) v30.y=0;
            P_STA_SUB_SetPetOffset(a,p,v30.y);
        }
        MCSS_SetOfsPosition(((struct Obj00200 *)p)->f0,(u32 *)(&v30));
        MCSS_SetOfsPosition(((struct Obj00200 *)p)->f4,(u32 *)(&v30));
        MCSS_SetOfsScale(((struct Obj00200 *)p)->f0,(u32 *)(&v3c));
        G3D_CAMERA_SetEye(((struct Obj05385 *)a)->f70,&v48);
        G3D_CAMERA_Reset(((struct Obj05385 *)a)->f70);
    } else if(st==1) {
        Vec v24=d_021DC198;
        Vec v18=d_021DC210;
        u8 c;
        p[0x9b]=p[0x9b]+1;
        c=p[0x9b];
        if(c<3) {
            Pair t1=d_021DC170;
            Pair t2=d_021DC178;
            Pair t3=d_021DC168;
            u8 k=c-1;
            v18.x=t1.v[k];
            v18.y=t2.v[k];
            v24.x=t3.v[k];
            G3D_CAMERA_SetEye(((struct Obj05385 *)a)->f70,&v24);
            G3D_CAMERA_Reset(((struct Obj05385 *)a)->f70);
            MCSS_SetOfsScale(((struct Obj00200 *)p)->f0,(u32 *)(&v18));
        } else {
            MCSS_SetVanishFlag(((struct Obj00200 *)p)->f0);
            MCSS_ResetVanishFlag(((struct Obj00200 *)p)->f4);
            MCSS_SetOfsScale(((struct Obj00200 *)p)->f4,(u32 *)(&v18));
            G3D_CAMERA_SetEye(((struct Obj05385 *)a)->f70,&v24);
            G3D_CAMERA_Reset(((struct Obj05385 *)a)->f70);
            ((struct Obj00200 *)p)->fC=0;
            ((struct Obj00200 *)p)->f8=2;
            ((struct Obj00200 *)p)->f6C=0;
        }
    }
}
