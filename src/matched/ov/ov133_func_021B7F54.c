/*
 * function: DUP_FITTING_AttachElem
 * address: 0x021B7F54
 * packet: pkt_ov133_021B7F54
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DUP_FITTING_ITEM_ElemGetRenderElem 0x021BA218 thumb ov133
 *   DUP_FITTING_ITEM_ElemSetPos 0x021BA21C thumb ov133
 *   DUP_FITTING_ITEM_ElemSetFrameIndex 0x021BA254 thumb ov133
 *   DUP_FITTING_FindNearestFrame 0x021B8BB4 thumb ov133
 *   DUP_FITTING_IsFrameOwned 0x021B8B78 thumb ov133
 *   MUSICAL_MCSS_GetRenderElem 0x021F5450 thumb ov112
 *   MUSICAL_MCSS_SetElemFlag 0x021F4EE8 thumb ov112
 *   MUSICAL_MCSS_ElemHasAltDepth 0x021F4B24 thumb ov112
 *   MUSICAL_MCSS_SetElemPos 0x021F4E8C thumb ov112
 *   MUSICAL_MCSS_SetElemField 0x021F4ED4 thumb ov112
 *   MUSICAL_MCSS_SetElemRot 0x021F4EC4 thumb ov112
 *   MUSICAL_MCSS_SetElemRotZ 0x021F4EB4 thumb ov112
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _ffix 0x0209C494 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   d_021BA5A0 0x021BA5A0 data a4
 */
#include "../include/Obj00004.h"
#include "../include/Obj06497.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {int x,y,z;} Vec;
typedef struct {int x,y;} Pair;
typedef struct {s16 y,x;u16 limit;} Scale;
extern const Vec d_021BA5A0;
extern u32 DUP_FITTING_ITEM_ElemGetRenderElem(u8 *p);
extern u8 *MUSICAL_MCSS_GetRenderElem(u8 *,int);
extern int DUP_FITTING_FindNearestFrame(u8 *,void *,const int *,u16 *);
extern int DUP_FITTING_IsFrameOwned(unsigned char *p, unsigned int id);
extern int MUSICAL_MCSS_ElemHasAltDepth(u8 *);
extern void DUP_FITTING_ITEM_ElemSetPos(u8 *p, const u8 *src);
extern void DUP_FITTING_ITEM_ElemSetFrameIndex(char *p, int v);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void MUSICAL_MCSS_SetElemFlag(int,int,int);
extern void MUSICAL_MCSS_SetElemPos(int,int,Vec *);
extern void MUSICAL_MCSS_SetElemField(u32 unused, u32 p, u16 v);
extern void MUSICAL_MCSS_SetElemRot(u32 unused, u32 p, s16 *a, s16 *b);
extern void MUSICAL_MCSS_SetElemRotZ(u32 unused, u32 p, s16 a, s16 b);
void DUP_FITTING_AttachElem(u8 *p,int sound)
{
    Vec v;
    Pair pos,relative;
    Scale scale;
    int old,index;
    u8 *sprite,*q;
    u16 rotation=0;
    scale.limit=12;v=d_021BA5A0;
    old=((struct Obj00004 *)p)->f34;sprite=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f38);
    relative.x=((struct Obj00004 *)p)->f1C-128;relative.y=*(int *)&((struct Obj00004 *)p)->f20-112;
    index=DUP_FITTING_FindNearestFrame(p,sprite,(const int *)&relative,&scale.limit);((struct Obj00004 *)p)->f34=index;
    if(index!=10){
        q=MUSICAL_MCSS_GetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f1880,index);
        pos.x=(int)((float)(((struct Obj06497 *)q)->f4+((struct Obj06497 *)q)->f10)/4096.f)+128;
        pos.y=(int)((float)(((struct Obj06497 *)q)->f8+((struct Obj06497 *)q)->f14)/4096.f)+96;
        rotation=((struct Obj06497 *)q)->f36;MUSICAL_MCSS_SetElemFlag(*(int *)&((struct Obj00004 *)p)->f1884,(int)sprite,1);
        if(MUSICAL_MCSS_ElemHasAltDepth(sprite)==1)v.z=0x1a000;
        if(DUP_FITTING_IsFrameOwned(p,((struct Obj00004 *)p)->f34)==0){((struct Obj00004 *)p)->f40=3;((struct Obj00004 *)p)->f44=pos.x;((struct Obj00004 *)p)->f48=pos.y;}
        DUP_FITTING_ITEM_ElemSetFrameIndex((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38),((struct Obj00004 *)p)->f34);
        if(old!=((struct Obj00004 *)p)->f34 && sound==1)GFL_USE_PlaySeDefaultVolume(0x627);
    }else{
        ((struct Obj00004 *)p)->f34=10;pos.x=((struct Obj00004 *)p)->f1C;pos.y=*(int *)&((struct Obj00004 *)p)->f20;
        MUSICAL_MCSS_SetElemFlag(*(int *)&((struct Obj00004 *)p)->f1884,(int)sprite,rotation);
    }
    if(pos.x>0)v.x=(int)(0.5f+(float)(int)((u32)pos.x<<12));else v.x=(int)((float)(int)((u32)pos.x<<12)-0.5f);
    if(pos.y>0)v.y=(int)(0.5f+(float)(int)((u32)pos.y<<12));else v.y=(int)((float)(int)((u32)pos.y<<12)-0.5f);
    MUSICAL_MCSS_SetElemPos(*(int *)(p+0x1884),(int)sprite,&v);
    DUP_FITTING_ITEM_ElemSetPos(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(&pos));
    q=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f38);MUSICAL_MCSS_SetElemField(*(int *)(p+0x1884),(int)q,rotation);
    MUSICAL_MCSS_SetElemRot(*(int *)(p+0x1884),(int)sprite,&scale.x,&scale.y);
    if(scale.x<4096 || scale.y<4096){
        scale.x+=410;scale.y+=410;
        if(scale.x>4096)scale.x=4096;if(scale.y>4096)scale.y=4096;
        MUSICAL_MCSS_SetElemRotZ(*(int *)(p+0x1884),(int)sprite,scale.x,scale.y);
    }
}
