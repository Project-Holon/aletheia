/*
 * function: DUP_FITTING_UpdateHeldElem
 * address: 0x021B8680
 * packet: pkt_ov133_021B8680
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Unsigned word state local restores the state/sprite register pair; int and long left DIFF7.
 * ABI: MUSICAL_MCSS_ElemHasAltDepth declared int here: its forwarded MUSICAL_MCSS_GetStateA returns 0/1; original compares the returned r0 despite legacy void declarations.
 * symbols:
 *   d_021BA57C 0x021BA57C data a4
 *   d_021BA5AC 0x021BA5AC data a4
 *   DUP_FITTING_ITEM_ElemGetRenderElem 0x021BA218 thumb ov133
 *   DUP_FITTING_ITEM_ElemSetBasePos 0x021BA22C thumb ov133
 *   MUSICAL_MCSS_SetElemPos 0x021F4E8C thumb ov112
 *   DUP_FITTING_ITEM_ElemSetPos 0x021BA21C thumb ov133
 *   DUP_FITTING_ITEM_ElemSetAnimFrames 0x021BA24C thumb ov133
 *   DUP_FITTING_ReleaseElem 0x021B8254 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetFrameIndex 0x021BA258 thumb ov133
 *   MUSICAL_MCSS_GetRenderElem 0x021F5450 thumb ov112
 *   MUSICAL_MCSS_ElemHasAltDepth 0x021F4B24 thumb ov112
 *   MUSICAL_MCSS_SetElemFlag 0x021F4EE8 thumb ov112
 *   MUSICAL_MCSS_SetElemField 0x021F4ED4 thumb ov112
 *   DUP_FITTING_MoveElem 0x021B8444 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetBasePos 0x021BA238 thumb ov133
 *   DUP_FITTING_ReturnElem 0x021B82E8 thumb ov133
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _fdiv 0x0209CE10 arm
 */
#include "../include/Obj00004.h"
#include "../include/Obj06498.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x,y,z; } Vec;
typedef struct { int x,y; } Pair;
typedef struct { u16 a:2; u16 flag:1; u16 b:13; } Flags;
extern const Vec d_021BA57C,d_021BA5AC;
extern unsigned int DUP_FITTING_ITEM_ElemGetRenderElem(u8 *p);
extern void DUP_FITTING_ITEM_ElemSetBasePos(u8 *p, const u8 *src);
extern void MUSICAL_MCSS_SetElemPos(int,int,Vec *);
extern void DUP_FITTING_ITEM_ElemSetPos(u8 *p, const u8 *src);
extern void DUP_FITTING_ITEM_ElemSetAnimFrames(char *p, unsigned int v);
extern void DUP_FITTING_ReleaseElem(u8 *);
extern unsigned int DUP_FITTING_ITEM_ElemGetFrameIndex(char *p);
extern u8 *MUSICAL_MCSS_GetRenderElem(u8 *,int);
extern int MUSICAL_MCSS_ElemHasAltDepth(u8 *);
extern void MUSICAL_MCSS_SetElemFlag(int,Flags *,int);
typedef unsigned int   u32;
extern void MUSICAL_MCSS_SetElemField(u32 unused, u32 p, u16 v);
extern void DUP_FITTING_MoveElem(u8 *);
extern u8 *DUP_FITTING_ITEM_ElemGetBasePos(u8 *p);
extern void DUP_FITTING_ReturnElem(u8 *,int);
void DUP_FITTING_UpdateHeldElem(u8 *p)
{
    Vec a,b,c;
    Pair posA,currentB,posB,posC;
    unsigned int state;
    u8 *sprite,*record;
    u16 flag;
    if(((struct Obj00004 *)p)->f40==2) {
        a=d_021BA57C;
        sprite=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f38);
        posA.x=((struct Obj00004 *)p)->f1C; posA.y=*(int *)&((struct Obj00004 *)p)->f20;
        if(((struct Obj00004 *)p)->f44>0) a.x=(int)(0.5f+(float)(((struct Obj00004 *)p)->f44<<12));
        else a.x=(int)((float)(((struct Obj00004 *)p)->f44<<12)-0.5f);
        if(((struct Obj00004 *)p)->f48>0) a.y=(int)(0.5f+(float)(((struct Obj00004 *)p)->f48<<12));
        else a.y=(int)((float)(((struct Obj00004 *)p)->f48<<12)-0.5f);
        DUP_FITTING_ITEM_ElemSetBasePos(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(&posA));
        MUSICAL_MCSS_SetElemPos(*(int *)&((struct Obj00004 *)p)->f1884,(int)sprite,&a);
        DUP_FITTING_ITEM_ElemSetPos(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(p+0x44));
        DUP_FITTING_ITEM_ElemSetAnimFrames((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38),10);
        DUP_FITTING_ReleaseElem(p);
        return;
    } else if(((struct Obj00004 *)p)->f40==3) {
        u8 *spriteB;
        spriteB=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f38);
        state=DUP_FITTING_ITEM_ElemGetFrameIndex((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38));
        record=MUSICAL_MCSS_GetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f1880,state);
        posB.x=(int)((float)(((struct Obj06498 *)record)->f4+((struct Obj06498 *)record)->f10)/4096.0f)+128;
        posB.y=(int)((float)(((struct Obj06498 *)record)->f8+((struct Obj06498 *)record)->f14)/4096.0f)+96;
        if(posB.x>0) b.x=(int)(0.5f+(float)(posB.x<<12));
        else b.x=(int)((float)(posB.x<<12)-0.5f);
        if(posB.y>0) b.y=(int)(0.5f+(float)(posB.y<<12));
        else b.y=(int)((float)(posB.y<<12)-0.5f);
        if(MUSICAL_MCSS_ElemHasAltDepth(spriteB)==1) b.z=102<<10;
        else if(DUP_FITTING_ITEM_ElemGetFrameIndex((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38))==7 || DUP_FITTING_ITEM_ElemGetFrameIndex((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38))==8) b.z=222<<10;
        else b.z=202<<10;
        flag=((struct Obj06498 *)record)->f36;
        MUSICAL_MCSS_SetElemFlag(*(int *)&((struct Obj00004 *)p)->f1884,(Flags *)spriteB,1);
        MUSICAL_MCSS_SetElemPos(*(int *)&((struct Obj00004 *)p)->f1884,(int)spriteB,&b);
        MUSICAL_MCSS_SetElemField(*(int *)&((struct Obj00004 *)p)->f1884,(int)DUP_FITTING_ITEM_ElemGetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f38),flag);
        DUP_FITTING_ITEM_ElemSetPos(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(&posB));
        currentB.x=((struct Obj00004 *)p)->f1C; currentB.y=*(int *)&((struct Obj00004 *)p)->f20;
        DUP_FITTING_ITEM_ElemSetBasePos(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(&currentB));
        DUP_FITTING_ITEM_ElemSetAnimFrames((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38),10);
        ((struct Obj00004 *)p)->f34=state;
        DUP_FITTING_MoveElem(p);
        ((struct Obj00004 *)p)->f34=10;
        return;
    } else if(((struct Obj00004 *)p)->f40==1) {
        DUP_FITTING_ITEM_ElemGetBasePos(*(u8 * *)&((struct Obj00004 *)p)->f38);
        c=d_021BA5AC;
        sprite=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f38);
        DUP_FITTING_ITEM_ElemSetPos(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(p+0x44));
        DUP_FITTING_ITEM_ElemSetAnimFrames((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38),10);
        posC.x=((struct Obj00004 *)p)->f1C; posC.y=*(int *)&((struct Obj00004 *)p)->f20;
        if(((struct Obj00004 *)p)->f44>0) c.x=(int)(0.5f+(float)(((struct Obj00004 *)p)->f44<<12));
        else c.x=(int)((float)(((struct Obj00004 *)p)->f44<<12)-0.5f);
        if(((struct Obj00004 *)p)->f48>0) c.y=(int)(0.5f+(float)(((struct Obj00004 *)p)->f48<<12));
        else c.y=(int)((float)(((struct Obj00004 *)p)->f48<<12)-0.5f);
        DUP_FITTING_ITEM_ElemSetBasePos(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(&posC));
        MUSICAL_MCSS_SetElemPos(*(int *)&((struct Obj00004 *)p)->f1884,(int)sprite,&c);
        DUP_FITTING_ReturnElem(p,1);
        return;
    }
    DUP_FITTING_ReturnElem(p,0);
}
