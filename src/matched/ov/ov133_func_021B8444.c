/*
 * function: DUP_FITTING_MoveElem
 * address: 0x021B8444
 * packet: pkt_ov133_021B8444
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: MUSICAL_MCSS_GetFlagA declared int here: its forwarded MUSICAL_MCSS_GetStateA returns 0/1; original compares the returned r0 despite legacy void declarations.
 * symbols:
 *   DUP_FITTING_ITEM_ElemGetRenderElem 0x021BA218 thumb ov133
 *   DUP_FITTING_IsFrameOwned 0x021B8B78 thumb ov133
 *   MUSICAL_MCSS_GetIndex 0x021F50F4 thumb ov112
 *   DUP_FITTING_ITEM_ListGetHead 0x021BA184 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetF20 0x021BA258 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetNext 0x021BA208 thumb ov133
 *   d_021BA570 0x021BA570 data a4
 *   MUSICAL_MCSS_GetElemOffset 0x021F4F04 thumb ov112
 *   DUP_FITTING_RandomPos 0x021B7458 thumb ov133
 *   DUP_FITTING_ITEM_RemoveElem 0x021BA148 thumb ov133
 *   DUP_FITTING_ITEM_InsertElemTail 0x021BA124 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetPos 0x021BA228 thumb ov133
 *   DUP_FITTING_ITEM_ElemSetBasePos 0x021BA22C thumb ov133
 *   MUSICAL_MCSS_SetElemPos 0x021F4E8C thumb ov112
 *   MUSICAL_MCSS_SetElemField 0x021F4ED4 thumb ov112
 *   DUP_FITTING_ITEM_ElemSetPos 0x021BA21C thumb ov133
 *   DUP_FITTING_ITEM_ElemSetF1C 0x021BA24C thumb ov133
 *   MUSICAL_MCSS_SetElemScale 0x021F4EA4 thumb ov112
 *   MUSICAL_MCSS_SetElemRotZ 0x021F4EB4 thumb ov112
 *   DUP_FITTING_ITEM_ElemSetF20 0x021BA254 thumb ov133
 *   MUSICAL_MCSS_GetFlagA 0x021F4B24 thumb ov112
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
typedef struct { int x,y,z; } Vec;
typedef struct { int x,y; } Pair;
extern const Vec d_021BA570;
extern unsigned int DUP_FITTING_ITEM_ElemGetRenderElem(u8 *p);
typedef signed short   s16;
typedef unsigned short u16;
typedef unsigned int   u32;
extern int DUP_FITTING_IsFrameOwned(unsigned char *p, unsigned int id);
extern int MUSICAL_MCSS_GetIndex(unsigned int);
extern void *DUP_FITTING_ITEM_ListGetHead(char *p);
extern u32 DUP_FITTING_ITEM_ElemGetF20(char *p);
extern u32 DUP_FITTING_ITEM_ElemGetNext(u8 *p);
extern void MUSICAL_MCSS_GetElemOffset(u8 *,Pair *);
extern void DUP_FITTING_RandomPos(void *,int *);
extern void DUP_FITTING_ITEM_RemoveElem(u8 *p, u8 *q);
extern void DUP_FITTING_ITEM_InsertElemTail(u8 *p, u8 *q);
extern u8 *DUP_FITTING_ITEM_ElemGetPos(u8 *p);
extern void DUP_FITTING_ITEM_ElemSetBasePos(u8 *p, const u8 *src);
extern void MUSICAL_MCSS_SetElemPos(int,int,Vec *);
extern void MUSICAL_MCSS_SetElemField(u32 unused, u32 p, u16 v);
extern void DUP_FITTING_ITEM_ElemSetPos(u8 *p, const u8 *src);
extern void DUP_FITTING_ITEM_ElemSetF1C(char *p, u32 v);
extern void MUSICAL_MCSS_SetElemScale(u32 unused, u32 p, u32 q);
extern void MUSICAL_MCSS_SetElemRotZ(u32 unused, u32 p, s16 a, s16 b);
extern void DUP_FITTING_ITEM_ElemSetF20(char *p, int v);
extern int MUSICAL_MCSS_GetFlagA(u8 *);
void DUP_FITTING_MoveElem(u8 *p)
{
    Vec v, first, second;
    Pair pos, offset;
    u8 *sprite,*entry,*s;
    Pair *old;
    int state,depth;
    DUP_FITTING_ITEM_ElemGetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f38);
    sprite=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f38);
    if(DUP_FITTING_IsFrameOwned(p,((struct Obj00004 *)p)->f34)==1) {
        state=MUSICAL_MCSS_GetIndex(((struct Obj00004 *)p)->f34);
        entry=DUP_FITTING_ITEM_ListGetHead(((struct Obj00004 *)p)->f1824);
        while(entry) {
            if(state==MUSICAL_MCSS_GetIndex(DUP_FITTING_ITEM_ElemGetF20((char *)entry))) break;
            entry=(u8 *)DUP_FITTING_ITEM_ElemGetNext(entry);
        }
        if(entry) {
            v=d_021BA570;
            s=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(entry);
            MUSICAL_MCSS_GetElemOffset(s,&offset);
            DUP_FITTING_RandomPos(p,(int *)&pos);
            pos.x+=offset.x;
            pos.y+=offset.y;
            DUP_FITTING_ITEM_RemoveElem(((struct Obj00004 *)p)->f1824,entry);
            DUP_FITTING_ITEM_InsertElemTail(((struct Obj00004 *)p)->f1820,entry);
            old=(Pair *)DUP_FITTING_ITEM_ElemGetPos(entry);
            if(pos.x>0) v.x=(int)(0.5f+(float)(pos.x<<12));
            else v.x=(int)((float)(pos.x<<12)-0.5f);
            if(pos.y>0) v.y=(int)(0.5f+(float)(pos.y<<12));
            else v.y=(int)((float)(pos.y<<12)-0.5f);
            DUP_FITTING_ITEM_ElemSetBasePos(entry,(const u8 *)old);
            MUSICAL_MCSS_SetElemPos(*(int *)&((struct Obj00004 *)p)->f1884,(int)s,&v);
            MUSICAL_MCSS_SetElemField(*(int *)&((struct Obj00004 *)p)->f1884,(int)s,0);
            DUP_FITTING_ITEM_ElemSetPos(entry,(const u8 *)(&pos));
            DUP_FITTING_ITEM_ElemSetF1C((char *)entry,10);
            depth=0;
            entry=DUP_FITTING_ITEM_ListGetHead(((struct Obj00004 *)p)->f1820);
            while(entry) {
                s=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(entry);
                MUSICAL_MCSS_SetElemScale(*(int *)(p+0x1884),(int)s,(u32)(&first));
                first.z=depth;
                MUSICAL_MCSS_SetElemPos(*(int *)(p+0x1884),(int)s,&first);
                depth-=1024;
                entry=(u8 *)DUP_FITTING_ITEM_ElemGetNext(entry);
            }
        }
    }
    DUP_FITTING_ITEM_RemoveElem(((struct Obj00004 *)p)->f1820,*(u8 * *)&((struct Obj00004 *)p)->f38);
    DUP_FITTING_ITEM_InsertElemTail(((struct Obj00004 *)p)->f1824,*(u8 * *)&((struct Obj00004 *)p)->f38);
    MUSICAL_MCSS_SetElemRotZ(*(int *)&((struct Obj00004 *)p)->f1884,(int)sprite,4096,4096);
    DUP_FITTING_ITEM_ElemSetF20((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38),((struct Obj00004 *)p)->f34);
    entry=DUP_FITTING_ITEM_ListGetHead(((struct Obj00004 *)p)->f1824);
    depth=0;
    while(entry) {
        s=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(entry);
        MUSICAL_MCSS_SetElemScale(*(int *)(p+0x1884),(int)s,(u32)(&second));
        if(MUSICAL_MCSS_GetFlagA(s)==1) second.z=depth+(102<<10);
        else if(DUP_FITTING_ITEM_ElemGetF20((char *)entry)==7 || DUP_FITTING_ITEM_ElemGetF20((char *)entry)==8) second.z=depth+(222<<10);
        else second.z=depth+(202<<10);
        MUSICAL_MCSS_SetElemPos(*(int *)(p+0x1884),(int)s,&second);
        depth-=1024;
        entry=(u8 *)DUP_FITTING_ITEM_ElemGetNext(entry);
    }
}
