/*
 * function: BR_CODEIN_SidebarStepIntro
 * address: 0x021DB3C4
 * packet: pkt_ov183_021DB3C4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: enum-valued one-bit mask preserves the original call/mask scheduling, as in sibling 021DB594.
 * abi: 02035C60 returns a full word consumed by the original caller's comparison.
 * symbols:
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_UTIL_IsEffectDone 0x021FD938 thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 *   BR_FADE_StartTimed 0x021FE794 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_Delete 0x021FC734 thumb ov186
 *   BR_SIDEBAR_StartBounce 0x021FEE24 thumb ov186
 *   BR_PROC_SYS_PushEntry 0x021F9BF4 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_UTIL_FlushText 0x021FC830 thumb ov186
 *   BR_CODEIN_SidebarClearStep 0x021DB690 thumb ov183
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj00630.h"
#include "../include/Obj24519.h"
#include "../include/Obj24520.h"
#include "../include/Obj24521.h"
#include "../include/Obj24522.h"
#include "../include/Obj24523.h"
#include "../include/Obj24524.h"
#include "../include/Obj24525.h"
#include "../include/Obj24526.h"
#include "../include/Obj24527.h"
#include "../include/Obj24528.h"
#include "../include/Obj24529.h"
#include "../include/Obj24530.h"
extern void BR_UTIL_StartEffect(int,int,int *);
extern int BR_UTIL_IsEffectDone(char *);
extern void *BR_UTIL_Create(unsigned short,unsigned,unsigned short,unsigned short,unsigned char,unsigned char,void *,unsigned short);
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern void BR_UTIL_SetTextFromMessage(char *,void *,void *,void *,unsigned short);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void BR_FADE_StartTimed(char *p, u32 index, u32 a, u32 b, u32 c);
extern int BR_FADE_GetResult(int *);
extern void BR_UTIL_Delete(u8 *p);
extern void BR_SIDEBAR_StartBounce(char *p);
extern int BR_UTIL_FlushText(u8 *p);
extern void BR_PROC_SYS_PushEntry(unsigned *,unsigned);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_CODEIN_SidebarClearStep(int *task);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_020409B4(u32 index);
extern int TOUCHPANEL_GetTrg(void);
void BR_CODEIN_SidebarStepIntro(int *task,int *state,char *p)
{
    int a,b;
    switch(*state) {
    case 0: {int args[2];args[0]=128;args[1]=96;BR_UTIL_StartEffect(*(int *)&((struct Obj00630 *)p)->f14,2,args);GFL_USE_PlaySeDefaultVolume(0x700);*state=1;break;}
    case 1: if(BR_UTIL_IsEffectDone(*(char * *)&((struct Obj00630 *)p)->f14))*state=2;break;
    case 2: {int args[2];args[0]=128;args[1]=-8;BR_UTIL_StartEffect(*(int *)&((struct Obj00630 *)p)->f18,3,args);*state=3;break;}
    case 3: if(BR_UTIL_IsEffectDone(*(char * *)&((struct Obj00630 *)p)->f18))*state=4;break;
    case 4:
        ((struct Obj00630 *)p)->f8=BR_UTIL_Create(4,8,16,16,2,14,((struct Obj00630 *)p)->fC,((struct Obj00630 *)p)->f4);
        a=BR_RES_GetFont(*(char * *)&((struct Obj24519 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->fC);
        b=BR_RES_GetMsgData(*(char * *)&((struct Obj24520 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->fC);
        BR_UTIL_SetTextFromMessage(*(char * *)&((struct Obj00630 *)p)->f8,(void *)b,(void *)228,(void *)a,0x440);
        BR_FADE_StartTimed((char *)(((struct Obj24521 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8),3,15,1,4);*state=5;break;
    case 5: if(BR_FADE_GetResult(*(int * *)&((struct Obj24522 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8))*state=6;break;
    case 6: BR_FADE_StartTimed((char *)(((struct Obj24523 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8),3,15,0,4);*state=7;break;
    case 7: if(BR_FADE_GetResult(*(int * *)&((struct Obj24524 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8))*state=8;break;
    case 8: if(TOUCHPANEL_GetTrg()) {GFL_USE_PlaySeDefaultVolume(0x6ff);BR_UTIL_Delete(((struct Obj00630 *)p)->f8);*(int *)&((struct Obj00630 *)p)->f8=0;func_020409B4(4);*state=9;}break;
    case 9: BR_FADE_StartTimed((char *)(((struct Obj24525 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8),3,3,0,48);BR_SIDEBAR_StartBounce((char *)(((struct Obj24526 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f14));*state=10;break;
    case 10: {enum {ONE=1} mask=ONE;if(BR_FADE_GetResult(*(int * *)&((struct Obj24527 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8)&mask) {BR_UTIL_StartEffect(*(int *)&((struct Obj00630 *)p)->f18,8,0);*state=11;}break;}
    case 11: BR_FADE_StartTimed((char *)(((struct Obj24528 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8),2,3,1,1);*state=12;break;
    case 12: if(BR_FADE_GetResult(*(int * *)&((struct Obj24529 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8))*state=13;break;
    case 13: if(BR_UTIL_IsEffectDone(*(char * *)&((struct Obj00630 *)p)->f18)) {BR_PROC_SYS_PushEntry(*(unsigned * *)&((struct Obj24530 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f10,1);BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_SidebarClearStep);}break;
    }
    if(((struct Obj00630 *)p)->f8)BR_UTIL_FlushText(((struct Obj00630 *)p)->f8);
}
