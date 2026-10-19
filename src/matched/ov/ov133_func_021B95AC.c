/*
 * function: DUP_FITTING_DragRotate
 * address: 0x021B95AC
 * packet: pkt_ov133_021B95AC
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DUP_FITTING_ITEM_ElemGetFrameIndex 0x021BA258 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetRenderElem 0x021BA218 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetPos 0x021BA228 thumb ov133
 *   MUSICAL_MCSS_GetRenderElem 0x021F5450 thumb ov112
 *   MUSICAL_MCSS_SetElemField 0x021F4ED4 thumb ov112
 *   func_0207CFB8 0x0207CFB8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../include/Obj00004.h"
#include "../include/Obj23321.h"
#include "../include/Obj23322.h"
#include "../include/Obj23323.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern u32 DUP_FITTING_ITEM_ElemGetFrameIndex(char *p);
extern u32 DUP_FITTING_ITEM_ElemGetRenderElem(u8 *p);
extern u8 *DUP_FITTING_ITEM_ElemGetPos(u8 *p);
extern u8 *MUSICAL_MCSS_GetRenderElem(u8 *,int);
extern void MUSICAL_MCSS_SetElemField(u32 unused, u32 p, u16 v);
extern u16 func_0207CFB8(long,long);
extern void GFL_USE_PlaySeDefaultVolume(u32);
static inline int fx(int x)
{
    if(x>0) return (int)(0.5f+(float)(int)((unsigned)x<<12));
    return (int)((float)(int)((unsigned)x<<12)-0.5f);
}
void DUP_FITTING_DragRotate(u8 *p)
{
    u16 index,angle;
    u8 *rec;
    u32 *xy;
    int dx,dy,stride,absval,y;
    s16 old,adjust;
    index=DUP_FITTING_ITEM_ElemGetFrameIndex((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38));
    rec=MUSICAL_MCSS_GetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f1880,index);
    DUP_FITTING_ITEM_ElemGetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f38);
    xy=(u32 *)DUP_FITTING_ITEM_ElemGetPos(*(u8 * *)&((struct Obj00004 *)p)->f38);
    y=xy[1];
    dx=fx((int)(*(u32 *)&((struct Obj00004 *)p)->f1C-xy[0]));
    dy=fx((int)(((struct Obj00004 *)p)->f20-(unsigned)y));
    angle=func_0207CFB8(dx,dy);
    if(((struct Obj00004 *)p)->f30==1) {
        stride=index*6;
        old=*(s16 *)(*(u8 * *)&((struct Obj23322 *)(*(u8 * *)&((struct Obj00004 *)p)->f4))->f4+stride+0x16);
        adjust=old+(s16)(((struct Obj00004 *)p)->f2C-angle);
        if(adjust< -2730) adjust= -2730;
        if(adjust>2730) adjust=2730;
        ((struct Obj00004 *)p)->f18C4+=(s16)(old-adjust);
        absval=((struct Obj00004 *)p)->f18C4;
        if(absval<0) absval= -absval;
        if(absval>1820) {
            ((struct Obj00004 *)p)->f18C4=0;
            GFL_USE_PlaySeDefaultVolume(1577);
        }
        MUSICAL_MCSS_SetElemField((u32)(((struct Obj00004 *)p)->f1884),DUP_FITTING_ITEM_ElemGetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f38),((struct Obj23321 *)rec)->f36+adjust);
        *(s16 *)(*(u8 * *)&((struct Obj23323 *)(*(u8 * *)&((struct Obj00004 *)p)->f4))->f4+stride+0x16)=adjust;
    }
    ((struct Obj00004 *)p)->f2C=angle;
    ((struct Obj00004 *)p)->f30=1;
}
