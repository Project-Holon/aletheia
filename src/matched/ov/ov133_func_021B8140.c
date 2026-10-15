/*
 * function: DUP_FITTING_CreateFitElem
 * address: 0x021B8140
 * packet: pkt_ov133_021B8140
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DUP_FITTING_ITEM_ElemGetData 0x021BA20C thumb ov133
 *   DUP_FITTING_ITEM_CreateElem 0x021BA19C thumb ov133
 *   DUP_FITTING_ITEM_InsertElem 0x021BA100 thumb ov133
 *   DUP_FITTING_ITEM_ElemSetPos 0x021BA21C thumb ov133
 *   DUP_FITTING_ITEM_ElemGetRenderElem 0x021BA218 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetPos 0x021BA228 thumb ov133
 *   DUP_FITTING_FreeHeldElem 0x021B7A18 thumb ov133
 *   MUSICAL_MCSS_SetElemRot 0x021F4EC4 thumb ov112
 *   MUSICAL_MCSS_SetElemRotZ 0x021F4EB4 thumb ov112
 *   MUSICAL_MCSS_SetElemFlag 0x021F4EE8 thumb ov112
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   d_021BA5B8 0x021BA5B8 data a4
 */
#include "../include/Obj00004.h"
#include "../include/Obj23312.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x,y,z; } Vec;
typedef struct { u32 x,y; } Pair;
typedef struct { short y,x; } Scale;
extern const Vec d_021BA5B8;
extern u32 DUP_FITTING_ITEM_ElemGetData(u8 *p);
extern u32 DUP_FITTING_ITEM_ElemGetRenderElem(u8 *p);
typedef signed short   s16;
struct Object;
extern u8 *DUP_FITTING_ITEM_CreateElem(u16 heap, struct Object *q, u8 *r, int *v);
extern void DUP_FITTING_ITEM_InsertElem(u8 *p, u8 *q);
extern void DUP_FITTING_ITEM_ElemSetPos(u8 *p, const u8 *src);
extern u8 *DUP_FITTING_ITEM_ElemGetPos(u8 *p);
extern void MUSICAL_MCSS_SetElemRot(u32 unused, u32 p, s16 *a, s16 *b);
extern void MUSICAL_MCSS_SetElemRotZ(u32 unused, u32 p, s16 a, s16 b);
extern void MUSICAL_MCSS_SetElemFlag(int,int,int),DUP_FITTING_FreeHeldElem(u8 *),GFL_USE_PlaySeDefaultVolume(u32);
void DUP_FITTING_CreateFitElem(u8 *p)
{
    Vec scale=d_021BA5B8;
    Pair pos;
    Scale old;
    u8 *q,*data,*s,*t;
    u32 *v;
    data=(u8 *)DUP_FITTING_ITEM_ElemGetData(*(u8 * *)&((struct Obj00004 *)p)->f38);
    pos.x=*(u32 *)&((struct Obj00004 *)p)->f1C;pos.y=((struct Obj00004 *)p)->f20;
    if(pos.x!=0) scale.x=(int)(0.5f+(float)(pos.x<<12));
    else scale.x=(int)((float)(pos.x<<12)-0.5f);
    if(((struct Obj00004 *)p)->f20!=0) scale.y=(int)(0.5f+(float)(((struct Obj00004 *)p)->f20<<12));
    else scale.y=(int)((float)(((struct Obj00004 *)p)->f20<<12)-0.5f);
    q=DUP_FITTING_ITEM_CreateElem(((struct Obj00004 *)p)->f0,((struct Obj00004 *)p)->f1884,data,(int *)(&scale));
    DUP_FITTING_ITEM_InsertElem(((struct Obj00004 *)p)->f1820,q);
    DUP_FITTING_ITEM_ElemSetPos(q,(const u8 *)(&pos));
    s=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f38);t=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(q);
    MUSICAL_MCSS_SetElemRot(*(int *)&((struct Obj00004 *)p)->f1884,(int)s,&old.x,&old.y);
    MUSICAL_MCSS_SetElemRotZ(*(int *)&((struct Obj00004 *)p)->f1884,(int)t,old.x,old.y);
    MUSICAL_MCSS_SetElemFlag(*(int *)&((struct Obj00004 *)p)->f1884,(int)t,0);
    v=(u32 *)DUP_FITTING_ITEM_ElemGetPos(*(u8 * *)&((struct Obj00004 *)p)->f38);
    *(u32 *)&((struct Obj00004 *)p)->f40=1;
    *(u32 *)&((struct Obj00004 *)p)->f44=v[0];*(u32 *)&((struct Obj00004 *)p)->f48=v[1];
    *(u32 *)&((struct Obj00004 *)p)->f3C=2;*(u8 * *)&((struct Obj00004 *)p)->f38=q;*(u32 *)&((struct Obj00004 *)p)->f40=1;
    ((struct Obj23312 *)data)->fC=1;
    DUP_FITTING_FreeHeldElem(p);GFL_USE_PlaySeDefaultVolume(0x625);
}
