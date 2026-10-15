/*
 * function: DUP_FITTING_UpdateCursor
 * address: 0x021B7A70
 * packet: pkt_ov133_021B7A70
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   DUP_FITTING_AttachElem 0x021B7F54 thumb ov133
 *   DUP_FITTING_PickElem 0x021B7F00 thumb ov133
 *   DUP_FITTING_ITEM_RemoveElem 0x021BA148 thumb ov133
 *   DUP_FITTING_ITEM_InsertElem 0x021BA100 thumb ov133
 *   DUP_FITTING_SelectFrame 0x021B8930 thumb ov133
 *   DUP_FITTING_HitCircle 0x021B8FF4 thumb ov133
 *   DUP_FITTING_RotateToCursor 0x021B7CFC thumb ov133
 *   DUP_FITTING_ITEM_ListIsFull 0x021BA18C thumb ov133
 *   DUP_FITTING_CreateFitElem 0x021B8140 thumb ov133
 *   DUP_FITTING_ResetActorPose 0x021BA098 thumb ov133
 *   DUP_FITTING_MoveElem 0x021B8444 thumb ov133
 *   DUP_FITTING_ReturnElem 0x021B82E8 thumb ov133
 *   DUP_FITTING_UpdateHeldElem 0x021B8680 thumb ov133
 *   DUP_FITTING_ReleaseElem 0x021B8254 thumb ov133
 *   DUP_FITTING_SetModelTransform 0x021B765C thumb ov133
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   _fflt 0x0209BDBC arm
 *   _fmul 0x0209C77C arm
 *   _ffix 0x0209C494 arm
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int TOUCHPANEL_GetTrg(void);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern void DUP_FITTING_AttachElem(u8 *,int);
extern void DUP_FITTING_ITEM_RemoveElem(u8 *p, u8 *q);
extern void DUP_FITTING_ITEM_InsertElem(u8 *p, u8 *q);
extern int DUP_FITTING_PickElem(u8 *,void *,u32);
extern int DUP_FITTING_SelectFrame(u8 *);
extern int DUP_FITTING_HitCircle(int,int,int,float);
extern int DUP_FITTING_ITEM_ListIsFull(char *p);
extern void DUP_FITTING_RotateToCursor(u8 *,int,int);
extern void DUP_FITTING_CreateFitElem(u8 *);
extern void DUP_FITTING_ResetActorPose(u8 *);
extern void DUP_FITTING_MoveElem(u8 *);
extern void DUP_FITTING_ReturnElem(u8 *,int);
extern void DUP_FITTING_UpdateHeldElem(u8 *);
extern void DUP_FITTING_ReleaseElem(u8 *);
extern void *DUP_FITTING_SetModelTransform(u8 *p, u16 base, s16 speed, u16 rx, u16 ry);
extern void GFL_USE_PlaySeDefaultVolume(u32);
void DUP_FITTING_UpdateCursor(u8 *p)
{
    int moved=0,other=0,hit=0,outer,n,dx,dy;
    if(((struct Obj00004 *)p)->f183C==0){((struct Obj00004 *)p)->f14=TOUCHPANEL_GetTrg();((struct Obj00004 *)p)->f18=TOUCHPANEL_GetPointCont((u32 *)(p+0x1c),(u32 *)(p+0x20));}
    if(((struct Obj00004 *)p)->f14!=0 || ((struct Obj00004 *)p)->f18!=0){
        if(((struct Obj00004 *)p)->f20>176)((struct Obj00004 *)p)->f20=176;
        if(((struct Obj00004 *)p)->f20<16)((struct Obj00004 *)p)->f20=16;
        if(((struct Obj00004 *)p)->f3C==2 && *(u8 * *)&((struct Obj00004 *)p)->f38)DUP_FITTING_AttachElem(p,1);
        else if(((struct Obj00004 *)p)->f14==1){
            hit=DUP_FITTING_PickElem(p,((struct Obj00004 *)p)->f1824,3);
            if(hit==1){DUP_FITTING_ITEM_RemoveElem(((struct Obj00004 *)p)->f1824,*(u8 * *)&((struct Obj00004 *)p)->f38);DUP_FITTING_ITEM_InsertElem(((struct Obj00004 *)p)->f1820,*(u8 * *)&((struct Obj00004 *)p)->f38);DUP_FITTING_AttachElem(p,0);}
            else other=DUP_FITTING_SelectFrame(p);
        }
        if(hit==0 && other==0 && ((*(u8 * *)&((struct Obj00004 *)p)->f38==0 && ((struct Obj00004 *)p)->f14==1)||((struct Obj00004 *)p)->f3C==1)){
            dy=(s16)(((struct Obj00004 *)p)->f20-80);dx=(s16)(*(u32 *)&((struct Obj00004 *)p)->f1C-128);
            hit=DUP_FITTING_HitCircle(dx,dy,28,0.5384615659713745f);
            outer=DUP_FITTING_HitCircle(dx,dy,68,0.739130437374115f);
            if(hit==0 && outer==1){moved=1;DUP_FITTING_RotateToCursor(p,dx,dy);}
            else if((hit==0 && outer==0)||(hit==1 && outer==1)){
                if(DUP_FITTING_ITEM_ListIsFull(((struct Obj00004 *)p)->f1820)==0 && ((struct Obj00004 *)p)->f3C==1 && *(u8 * *)&((struct Obj00004 *)p)->f38){
                    n=((struct Obj00004 *)p)->f182E;if(n<0)n=-n;
                    if(n<364)DUP_FITTING_CreateFitElem(p);
                }
            }
            if(moved==0 && ((struct Obj00004 *)p)->f14==1)DUP_FITTING_PickElem(p,((struct Obj00004 *)p)->f1820,2);
        }
        if(((struct Obj00004 *)p)->f14!=0 && *(u8 * *)&((struct Obj00004 *)p)->f38==0 && ((struct Obj00004 *)p)->f20>160 && *(u32 *)&((struct Obj00004 *)p)->f1C>96 && *(u32 *)&((struct Obj00004 *)p)->f1C<160){
            ((struct Obj00004 *)p)->fC=2;((struct Obj00004 *)p)->f10=0;GFL_USE_PlaySeDefaultVolume(0x622);DUP_FITTING_ResetActorPose(p);
        }
    }else {
        dy=(s16)(((struct Obj00004 *)p)->f28-80);dx=(s16)(((struct Obj00004 *)p)->f24-128);
        hit=DUP_FITTING_HitCircle(dx,dy,28,0.5384615659713745f);outer=DUP_FITTING_HitCircle(dx,dy,68,0.739130437374115f);
        if(((struct Obj00004 *)p)->f3C==2 && *(u8 * *)&((struct Obj00004 *)p)->f38){
            if(((struct Obj00004 *)p)->f34!=10)DUP_FITTING_MoveElem(p);
            else if(hit==0 && outer==1)DUP_FITTING_ReturnElem(p,0);
            else if(hit==1)DUP_FITTING_UpdateHeldElem(p);
            else DUP_FITTING_ReleaseElem(p);
        }
        ((struct Obj00004 *)p)->f30=0;*(int *)&((struct Obj00004 *)p)->f38=0;((struct Obj00004 *)p)->f3C=0;((struct Obj00004 *)p)->f40=0;((struct Obj00004 *)p)->f34=10;
    }
    if(((struct Obj00004 *)p)->f182E!=0 && moved==0){
        n=((struct Obj00004 *)p)->f182C+0x10000-((struct Obj00004 *)p)->f182E;if(n<0)n+=0x10000;if(n>=0x10000)n-=0x10000;
        ((struct Obj00004 *)p)->f182C=n;DUP_FITTING_SetModelTransform(p,((struct Obj00004 *)p)->f182C,((struct Obj00004 *)p)->f182E,72,48);
        if(((struct Obj00004 *)p)->f182E>128 || ((struct Obj00004 *)p)->f182E<-128)((struct Obj00004 *)p)->f182E*=0.75f;
        else ((struct Obj00004 *)p)->f182E=0;
    }
    ((struct Obj00004 *)p)->f24=*(u32 *)&((struct Obj00004 *)p)->f1C;((struct Obj00004 *)p)->f28=((struct Obj00004 *)p)->f20;
}
