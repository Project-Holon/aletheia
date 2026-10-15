/*
 * file:     br_pokesearch.c
 * unit:     yes
 * function: BR_POKESEARCH_CreateWork, BR_POKESEARCH_DestroyWork, BR_POKESEARCH_Update, BR_POKESEARCH_OpenTask, BR_POKESEARCH_CloseTask, BR_POKESEARCH_MainTask, BR_POKESEARCH_HandleTouch, BR_POKESEARCH_NetworkTask, BR_POKESEARCH_DownloadDoneTask, BR_POKESEARCH_ExitTask, BR_POKESEARCH_RefreshTask, BR_POKESEARCH_EnterListTask, BR_POKESEARCH_ChangePageTask, BR_POKESEARCH_ChangeCategoryTask, BR_POKESEARCH_CreateSidebar, BR_POKESEARCH_ShowBg, BR_POKESEARCH_CreateDetail, BR_POKESEARCH_DestroyDetail, BR_POKESEARCH_CreateText, BR_POKESEARCH_DestroyText, BR_POKESEARCH_CreateSearch, BR_POKESEARCH_DestroySearch, BR_POKESEARCH_CreateMsgbox, BR_POKESEARCH_DestroyMsgbox, BR_POKESEARCH_HitTab, BR_POKESEARCH_HitPrev, BR_POKESEARCH_HitNext
 * address:  0x021F8480
 * region:   ov185
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ov112_id 0x00000070 data
 *   func_02034AC4 0x02034AC4 arm
 *   BR_PROC_SYS_GetSlotId 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BR_GRAPHIC_GetActorUnit 0x021FC4DC thumb ov186
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   BR_UTIL_CreateHandles 0x021FD760 thumb ov186
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   func_02040588 0x02040588 arm
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   BR_UTIL_DeleteTask 0x021FD714 thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   BR_UTIL_DeleteHandles 0x021FD820 thumb ov186
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_02034A5C 0x02034A5C arm
 *   BR_NET_HandleNetError 0x021FF88C thumb ov186
 *   BR_PROC_SYS_FlushWindows 0x021F9C6C thumb ov186
 *   BR_UTIL_RunTask 0x021FD71C thumb ov186
 *   BR_UTIL_IsTaskIdle 0x021FD72C thumb ov186
 *   BR_UTIL_RunHandles 0x021FD854 thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BR_UTIL_FlushText 0x021FC830 thumb ov186
 *   BR_UTIL_MainProfileScreen 0x021FD6B0 thumb ov186
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 *   func_021F3C50 0x021F3C50 thumb ov112
 *   BR_POKESEARCH_UpdatePrint 0x021FFE34 thumb ov186
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_UTIL_ClearTaskStep 0x021FD744 thumb ov186
 *   BR_PROC_SYS_PopEntry 0x021F9BA0 thumb ov186
 *   BR_POKESEARCH_Main   0x021FFC9C  thumb
 *   BR_POKESEARCH_GetResult   0x021FFE90  thumb
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BR_BTN_HitTestWithSound 0x021FB4B4 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_POKESEARCH_HitNext 0x021F9048 thumb ov185
 *   BR_NET_StartRequest 0x021FF54C thumb ov186
 *   BR_NET_IsIdle 0x021FF648 thumb ov186
 *   BR_NET_PollErrorMessage 0x021FF72C thumb ov186
 *   BR_NET_GetDownloadEntries 0x021FF660 thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 *   BR_SIDEBAR_SetVisibleBySpace   0x021FEEC0  thumb
 *   BR_RES_ApplyBgSet   0x021FBDA4  thumb
 *   BR_RES_ReleaseUiPalette   0x021FC1F8  thumb
 *   WORLDTRADE_DETAIL_StateStartWipeOut   0x021FC610  thumb  ov135
 *   func_021F3AF0   0x021F3AF0  thumb
 *   func_021F3BF0 0x021F3BF0 thumb ov112
 *   BR_GRAPHIC_End3d 0x021FC640 thumb ov186
 *   BR_RES_LoadUiPalette 0x021FC148 thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_BTN_CreateFromMessage 0x021FB378 thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   func_02034714 0x02034714 arm
 *   BR_BTN_DeleteObject 0x021FB494 thumb ov186
 *   BR_UTIL_Delete 0x021FC734 thumb ov186
 *   BR_UTIL_CreateProfileScreen 0x021FD1C4 thumb ov186
 *   BR_UTIL_DeleteProfileScreen  0x021FD640  thumb  ov186
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   BR_POKESEARCH_Create 0x021FFBD4 thumb ov186
 *   BR_POKESEARCH_Open 0x021FFE5C thumb ov186
 *   BR_POKESEARCH_Close 0x021FFE70 thumb ov186
 *   BR_POKESEARCH_Destroy 0x021FFC6C thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 */
#include "../../matched/include/Obj00278.h"
#include "../../matched/include/Obj02526.h"
#include "../../matched/include/Obj03337.h"
#include "../../matched/include/Obj04583.h"
#include "../../matched/include/Obj01966.h"
#include "../../matched/include/Obj24716.h"
#include "../../matched/include/Obj24717.h"
#include "../../matched/include/Obj10769.h"
#include "../../matched/include/Obj08320.h"
#include "../../matched/include/Obj24722.h"
#include "../../matched/include/Obj10771.h"
#include "../../matched/include/Obj02525.h"
#include "../../matched/include/Obj01276.h"
#include "../../matched/include/Obj24723.h"
#include "../../matched/include/Obj24724.h"
#include "../../matched/include/Obj24725.h"
#include "../../matched/include/Obj24726.h"
#include "../../matched/include/Obj24727.h"
#include "../../matched/include/Obj24728.h"
#include "../../matched/include/Obj03886.h"
#include "../../matched/include/Obj04582.h"
#include "../../matched/include/Obj01568.h"
#include "../../matched/include/Obj01769.h"
#include "../../matched/include/Obj24755.h"
#include "../../matched/include/Obj24756.h"
#include "../../matched/include/Obj06622.h"
#include "../../matched/include/Obj03337.h"
#include "../../matched/include/Obj04583.h"
#include "../../matched/include/Obj03338.h"
#include "../../matched/include/Obj05490.h"
#include "../../matched/include/Obj06623.h"
#include "../../matched/include/Obj10772.h"
#include "../../matched/include/Obj04584.h"
#include "../../matched/include/Obj24759.h"
#include "../../matched/include/Obj06624.h"
#include "../../matched/include/Obj14448.h"
#include "../../matched/include/Obj10773.h"
#include "../../matched/include/Obj24760.h"
#include "../../matched/include/Obj24761.h"
#include "../../matched/include/Obj24762.h"

struct Obj24810;
struct Obj0203159C;
struct PrintSys;
struct S020315D4;
struct Pair;
typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned char  u8;

typedef struct Cfg {u16 heap;unsigned char rest[6];} Cfg;

typedef struct Pair {int x,y;} Pair;

typedef struct Config {u16 x,y,z; unsigned char a,b;} Config;

typedef struct Triple {int a,b,c;} Triple;

extern int func_02034AC4(s32 handle);
extern unsigned BR_PROC_SYS_GetSlotId(struct Obj24810 *p);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,unsigned);
extern u32 PRINTSYS_QUE_Create(void *);
extern u32 BR_GRAPHIC_GetActorUnit(u8 *p);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
extern char *BR_UTIL_CreateHandles(unsigned owner, char *resources, int index, int heap);
extern void BR_RES_LoadSprite(char *base, u32 idx, u32 area);
extern void func_02040588(unsigned char which, unsigned char enable);
extern int *BR_UTIL_CreateTask(int payload, int callback, u32 heap);
extern void BR_UTIL_DeleteTask(void *p);
extern void BR_RES_ReleaseSprite(char *p, unsigned i);
extern void BR_UTIL_DeleteHandles(char *);
extern void BMP_OAM_DeleteSys(void *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_02034A5C(int);
extern int BR_NET_HandleNetError(char *);
extern void BR_PROC_SYS_FlushWindows(char *);
extern void BR_UTIL_RunTask(u8 *p);
extern int BR_UTIL_IsTaskIdle(int *);
extern void BR_UTIL_RunHandles(char *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern int BR_UTIL_FlushText(u8 *p);
extern int BR_UTIL_MainProfileScreen(u8 *p);
extern void BR_UTIL_FlushWindow(void *p);
extern void func_021F3C50(u8 *p);
extern unsigned BR_POKESEARCH_UpdatePrint(char *p);
extern void BR_FADE_Start(int a, int b, int c, int d);
extern int BR_FADE_GetResult(int *p);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern int BR_UTIL_ClearTaskStep(int *a);
extern void BR_PROC_SYS_PopEntry(unsigned *ctx);
extern void BR_POKESEARCH_Main(int);
extern int BR_POKESEARCH_GetResult(int, unsigned short *);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int BR_BTN_HitTestWithSound(unsigned int *obj, int x, int y);
extern void BR_UTIL_StartEffect(int,int,int *);
extern int BR_POKESEARCH_HitNext(char *p, unsigned x, unsigned y);
extern void BR_NET_StartRequest(char *p, int kind, const int *values);
extern int BR_NET_IsIdle(char *),BR_NET_PollErrorMessage(char *,int *),BR_NET_GetDownloadEntries(char *,int,int,int *);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern int TOUCHPANEL_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern void BR_UTIL_SetTextFromMessage(char *,void *,void *,void *,unsigned short);
extern void BR_SIDEBAR_SetVisibleBySpace(int, int, int);
extern void BR_RES_ApplyBgSet(int, int);
extern void BR_RES_ReleaseUiPalette(int, int);
extern int WORLDTRADE_DETAIL_StateStartWipeOut(u8 *p, int a1);
extern int func_021F3AF0(int, int);
extern void func_021F3BF0(u8 *);
extern void BR_GRAPHIC_End3d(void *,unsigned);
extern void BR_RES_LoadUiPalette(char *,unsigned,unsigned);
extern void BR_RES_LoadBgGraphics(void *,unsigned,u16);
extern int BR_RES_GetSprite(void *,unsigned,void *);
extern void func_02034714(const char *,unsigned,const char *);
extern void *BR_BTN_CreateFromMessage(void *,int,int,int,int,int,int,int,void *,u16);
extern void *BR_UTIL_Create(u16,unsigned,u16,u16,unsigned char,unsigned char,void *,u16);
extern void BR_BTN_DeleteObject(char *p);
extern void BR_UTIL_Delete(u8 *p);
extern char *BR_UTIL_CreateProfileScreen(void *prof, char *q, void *a2, void *a3, int mode, u16 heap);
extern void BR_UTIL_DeleteProfileScreen(int *p);
extern void *BR_UTIL_CreateTextWin(int a, void *owner, u16 heap);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern char *BR_POKESEARCH_Create(void *owner, void *table, int a, int b, int c, int d, int e, unsigned short heap);
extern void BR_POKESEARCH_Open(char *);
extern void BR_POKESEARCH_Close(char *p);
extern void BR_POKESEARCH_Destroy(char *p);
extern void func_020409B4(unsigned);
extern void BR_UTIL_DeleteTextWin(void *,int);
int BR_POKESEARCH_CreateWork(void *obj,int b,char *q);
int BR_POKESEARCH_DestroyWork(int obj,int b,char *q,char *p);
int BR_POKESEARCH_Update(int a,int b,int c,char *p);
void BR_POKESEARCH_OpenTask(int a,int *state,char *p);
void BR_POKESEARCH_CloseTask(int a,int *state,char *p);
void BR_POKESEARCH_MainTask(int a, int b, char *p);
void BR_POKESEARCH_HandleTouch(int a,int b,char *p);
void BR_POKESEARCH_NetworkTask(int *task,unsigned *state,char *p);
void BR_POKESEARCH_DownloadDoneTask(int a,int *state,char *p);
void BR_POKESEARCH_ExitTask(int *sys,int *state,char *p);
void BR_POKESEARCH_RefreshTask(int *sys,int *state,char *p);
void BR_POKESEARCH_EnterListTask(int *sys,int *state,char *p);
void BR_POKESEARCH_ChangePageTask(int *task,int *state,char *p);
void BR_POKESEARCH_ChangeCategoryTask(int *task,int *state,char *p);
void BR_POKESEARCH_CreateSidebar(char *a, int *r4);
void BR_POKESEARCH_ShowBg(char *p,char *q);
void BR_POKESEARCH_CreateDetail(char *p,char *q);
void BR_POKESEARCH_DestroyDetail(char *p,char *q);
void BR_POKESEARCH_CreateText(char *p,int *source);
void BR_POKESEARCH_DestroyText(char *p, int *a1);
void BR_POKESEARCH_CreateSearch(char *p,int *source);
void BR_POKESEARCH_DestroySearch(char *p,char *q);
void BR_POKESEARCH_CreateMsgbox(char *p, int *q);
void BR_POKESEARCH_DestroyMsgbox(char *p, char *a1);
int BR_POKESEARCH_HitTab(int a, int b, int c);
int BR_POKESEARCH_HitPrev(int a, int b, int c);
extern char ov112_id[];











int BR_POKESEARCH_CreateWork(void *obj,int b,char *q)
{
    char *p;
    void *v;
    int i;
    func_02034AC4((int)ov112_id);
    p=PROCSYS_AllocProcWork(obj,88,BR_PROC_SYS_GetSlotId(((struct Obj02526 *)q)->f10));
    MI_CpuFill8(p,0,88);
    *(char * *)&((struct Obj00278 *)p)->f34=q;
    ((struct Obj00278 *)p)->f30=BR_PROC_SYS_GetSlotId(((struct Obj02526 *)q)->f10);
    ((struct Obj00278 *)p)->f2C=PRINTSYS_QUE_Create((void *)(unsigned int)((struct Obj00278 *)p)->f30);
    v=(void *)BR_GRAPHIC_GetActorUnit(((struct Obj02526 *)q)->f8);
    ((struct Obj00278 *)p)->f28=BMP_OAM_CreateSys(((struct Obj00278 *)p)->f30,v);
    for (i=0;i<2;i++) *(void **)(p+i*4+56)=BR_UTIL_CreateHandles((unsigned int)v,(char *)(((struct Obj02526 *)q)->fC),i,((struct Obj00278 *)p)->f30);
    BR_RES_LoadSprite((char *)(((struct Obj02526 *)q)->fC),6,((struct Obj00278 *)p)->f30);
    func_02040588(0,1);
    BR_POKESEARCH_CreateSearch(p,(int *)q);
    ((struct Obj00278 *)p)->f24=BR_UTIL_CreateTask((int)p,(int)BR_POKESEARCH_OpenTask,((struct Obj00278 *)p)->f30);
    return 1;
}











int BR_POKESEARCH_DestroyWork(int obj,int b,char *q,char *p)
{
    int i;
    BR_POKESEARCH_ShowBg(p,q);
    BR_POKESEARCH_DestroyDetail(p,q);
    BR_POKESEARCH_DestroyText(p,(int *)q);
    BR_POKESEARCH_DestroySearch(p,q);
    BR_POKESEARCH_DestroyMsgbox(p,q);
    BR_UTIL_DeleteTask((void *)(((struct Obj03337 *)p)->f24));
    BR_POKESEARCH_DestroySearch(p,q);
    BR_RES_ReleaseSprite((char *)(*(int *)&((struct Obj04583 *)q)->fC),6);
    for (i=0;i<2;i++) BR_UTIL_DeleteHandles(*(char **)(p+i*4+56));
    BMP_OAM_DeleteSys((void *)(((struct Obj03337 *)p)->f28));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj03337 *)p)->f2C));
    func_020315D4((struct S020315D4 *)obj);
    func_02034A5C((int)ov112_id);
    return 1;
}











int BR_POKESEARCH_Update(int a,int b,int c,char *p)
{
    int i;
    if (BR_NET_HandleNetError(*(char * *)&((struct Obj24716 *)(*(char * *)&((struct Obj01966 *)p)->f34))->f14)==2) {
        BR_PROC_SYS_FlushWindows(*(char * *)&((struct Obj24717 *)(*(char * *)&((struct Obj01966 *)p)->f34))->f10);
        return 1;
    }
    BR_UTIL_RunTask((u8 *)(*(char * *)&((struct Obj01966 *)p)->f24));
    if (BR_UTIL_IsTaskIdle(*(int * *)&((struct Obj01966 *)p)->f24)) return 1;
    for (i=0;i<2;i++) BR_UTIL_RunHandles(*(char **)(p+i*4+56));
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj01966 *)p)->f2C));
    if (*(char * *)&((struct Obj01966 *)p)->f1C) BR_UTIL_FlushText((u8 *)(*(char * *)&((struct Obj01966 *)p)->f1C));
    if (*(char * *)&((struct Obj01966 *)p)->f10) BR_UTIL_MainProfileScreen((u8 *)(*(char * *)&((struct Obj01966 *)p)->f10));
    if (*(char * *)&((struct Obj01966 *)p)->f4) BR_UTIL_FlushWindow(*(char * *)&((struct Obj01966 *)p)->f4);
    if (*(char * *)&((struct Obj01966 *)p)->f14) func_021F3C50((u8 *)(*(char * *)&((struct Obj01966 *)p)->f14));
    return 0;
}










void BR_POKESEARCH_OpenTask(int a,int *state,char *p)
{
    switch (*state) {
    case 0: if (BR_POKESEARCH_UpdatePrint((char *)(((struct Obj10769 *)p)->f0))) { BR_FADE_Start(**(int * *)&((struct Obj10769 *)p)->f34,2,3,0); *state=1; } break;
    case 1: if (BR_FADE_GetResult((int *)(**(int * *)&((struct Obj10769 *)p)->f34))) *state=2; break;
    case 2: BR_UTIL_SetTaskStep((int *)a,(int)BR_POKESEARCH_MainTask); break;
    }
}










void BR_POKESEARCH_CloseTask(int a,int *state,char *p)
{
    switch (*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct Obj08320 *)p)->f34,2,3,1); *state=1; break;
    case 1: if (BR_FADE_GetResult((int *)(**(int * *)&((struct Obj08320 *)p)->f34))) *state=2; break;
    case 2: BR_UTIL_ClearTaskStep((int *)(((struct Obj08320 *)p)->f24)); BR_PROC_SYS_PopEntry((unsigned int *)(((struct Obj24722 *)(*(char * *)&((struct Obj08320 *)p)->f34))->f10)); break;
    }
}











void BR_POKESEARCH_MainTask(int a, int b, char *p)
{
    unsigned short buf;
    int r;
    BR_POKESEARCH_Main(((struct Obj10771 *)p)->f0);
    r = BR_POKESEARCH_GetResult(((struct Obj10771 *)p)->f0, &buf);
    if (r == 0)
        return;
    if (r == 2) {
        ((struct Obj10771 *)p)->f8 = buf;
        BR_UTIL_SetTaskStep((int *)a, (int)BR_POKESEARCH_EnterListTask);
    } else {
        BR_UTIL_SetTaskStep((int *)a, (int)BR_POKESEARCH_CloseTask);
    }
}








void BR_POKESEARCH_HandleTouch(int a,int b,char *p)
{
    int x,y;
    if (TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))) {
        if (BR_BTN_HitTestWithSound((unsigned int *)(((struct Obj02525 *)p)->f18),x,y)) {
            int pair[2];
            pair[0]=x; pair[1]=y;
            BR_UTIL_StartEffect(((struct Obj02525 *)p)->f3C,1,pair);
            BR_UTIL_SetTaskStep((int *)a,(int)BR_POKESEARCH_ExitTask);
        }
        if (BR_POKESEARCH_HitTab((int)p,x,y)) BR_UTIL_SetTaskStep((int *)a,(int)BR_POKESEARCH_ChangeCategoryTask);
        if (BR_POKESEARCH_HitPrev((int)p,x,y)) {
            int index=((struct Obj02525 *)p)->fC-1;
            if (index<0) ((struct Obj02525 *)p)->fC=((struct Obj02525 *)p)->f54-1;
            else ((struct Obj02525 *)p)->fC=index;
            BR_UTIL_SetTaskStep((int *)a,(int)BR_POKESEARCH_ChangePageTask);
        }
        if (BR_POKESEARCH_HitNext((char *)((int)p),x,y)) {
            ((struct Obj02525 *)p)->fC=((struct Obj02525 *)p)->fC+1;
            ((struct Obj02525 *)p)->fC=(int)((struct Obj02525 *)p)->fC % ((struct Obj02525 *)p)->f54;
            BR_UTIL_SetTaskStep((int *)a,(int)BR_POKESEARCH_ChangePageTask);
        }
    }
}








void BR_POKESEARCH_NetworkTask(int *task,unsigned *state,char *p)
{
    Cfg cfg;
    int out,x,y;
    Pair pair;
    switch(*state) {
    case 0:
        MI_CpuFill8(&cfg,0,8);
        cfg.heap=((struct Obj01276 *)p)->f8;
        ((struct Obj01276 *)p)->fA=0;
        BR_NET_StartRequest(*(char * *)&((struct Obj24723 *)(*(char * *)&((struct Obj01276 *)p)->f34))->f14,1,(const int *)(&cfg));
        *state=1; break;
    case 1:
        ((struct Obj01276 *)p)->fA=((struct Obj01276 *)p)->fA+1;
        if(BR_NET_IsIdle(*(char * *)&((struct Obj24724 *)(*(char * *)&((struct Obj01276 *)p)->f34))->f14) && ((struct Obj01276 *)p)->fA>0x60) {
            BR_UTIL_StartEffect(((struct Obj01276 *)p)->f38, 0, (int *)0);
            *state=2;
        }
        break;
    case 2:
        if(!BR_NET_PollErrorMessage(*(char * *)&((struct Obj24725 *)(*(char * *)&((struct Obj01276 *)p)->f34))->f14,&out)) {
            if(BR_NET_GetDownloadEntries(*(char * *)&((struct Obj24726 *)(*(char * *)&((struct Obj01276 *)p)->f34))->f14,(int)(p+0x40),5,(int *)(p+0x54)) && ((struct Obj01276 *)p)->f54) {
                ((struct Obj01276 *)p)->fC=0;
                BR_UTIL_SetTaskStep(task,(int)BR_POKESEARCH_DownloadDoneTask);
                break;
            }
            *state=3;
            BR_UTIL_SetWindowText(((struct Obj01276 *)p)->f4,((struct Obj24727 *)(*(char * *)&((struct Obj01276 *)p)->f34))->fC,(void *)0x14d);
        }else{
            *state=3;
            BR_UTIL_SetWindowText(((struct Obj01276 *)p)->f4,((struct Obj24728 *)(*(char * *)&((struct Obj01276 *)p)->f34))->fC,(void *)out);
        }
        break;
    case 3:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y));
            pair.x=x;pair.y=y;
            BR_UTIL_StartEffect(((struct Obj01276 *)p)->f3C, 1, (int *)&pair);
            GFL_USE_PlaySeDefaultVolume(0x703);
            BR_UTIL_SetTaskStep(task,(int)BR_POKESEARCH_RefreshTask);
        }
        break;
    }
}








void BR_POKESEARCH_DownloadDoneTask(int a,int *state,char *p)
{
    switch (*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct Obj03886 *)p)->f34,4,3,1); *state=1; break;
    case 1: if (BR_FADE_GetResult((int *)(**(int * *)&((struct Obj03886 *)p)->f34))) *state=2; break;
    case 2: BR_POKESEARCH_DestroyMsgbox(p,*(char * *)&((struct Obj03886 *)p)->f34); BR_POKESEARCH_CreateSidebar(p,*(int * *)&((struct Obj03886 *)p)->f34); BR_POKESEARCH_CreateDetail(p,*(char * *)&((struct Obj03886 *)p)->f34); *state=3; break;
    case 3: BR_FADE_Start(**(int * *)&((struct Obj03886 *)p)->f34,4,3,0); *state=4; break;
    case 4: if (BR_FADE_GetResult((int *)(**(int * *)&((struct Obj03886 *)p)->f34))) *state=5; break;
    case 5: ((struct Obj03886 *)p)->f20=1; BR_UTIL_SetTaskStep((int *)a,(int)BR_POKESEARCH_HandleTouch); break;
    }
}







void BR_POKESEARCH_ExitTask(int *sys,int *state,char *p)
{
    switch(*state) {
    case 0:
        if(((struct Obj00278 *)p)->f20) BR_FADE_Start(**(int * *)&((struct Obj00278 *)p)->f34,4,3,1);
        else BR_FADE_Start(**(int * *)&((struct Obj00278 *)p)->f34,2,3,1);
        *state=1; break;
    case 1: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj00278 *)p)->f34)) *state=2; break;
    case 2:
        BR_POKESEARCH_DestroyText(p,*(int * *)&((struct Obj00278 *)p)->f34);
        BR_POKESEARCH_ShowBg(p,(char *)(*(int * *)&((struct Obj00278 *)p)->f34));
        BR_POKESEARCH_DestroyDetail(p,(char *)(*(int * *)&((struct Obj00278 *)p)->f34));
        BR_POKESEARCH_CreateSearch(p,*(int * *)&((struct Obj00278 *)p)->f34);
        *state=3; break;
    case 3:
        if(((struct Obj00278 *)p)->f20) BR_FADE_Start(**(int * *)&((struct Obj00278 *)p)->f34,4,3,0);
        else BR_FADE_Start(**(int * *)&((struct Obj00278 *)p)->f34,2,3,0);
        *state=4; break;
    case 4: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj00278 *)p)->f34)) *state=5; break;
    case 5: BR_UTIL_SetTaskStep(sys,(int)BR_POKESEARCH_MainTask); break;
    }
}







void BR_POKESEARCH_RefreshTask(int *sys,int *state,char *p)
{
    switch(*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct Obj00278 *)p)->f34,2,3,1); *state=1; break;
    case 1: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj00278 *)p)->f34)) *state=2; break;
    case 2: BR_POKESEARCH_DestroyMsgbox(p,(char *)(*(int * *)&((struct Obj00278 *)p)->f34)); BR_POKESEARCH_CreateSearch(p,*(int * *)&((struct Obj00278 *)p)->f34); *state=3; break;
    case 3: if(BR_POKESEARCH_UpdatePrint((char *)(*(int *)&((struct Obj00278 *)p)->f0))) {BR_FADE_Start(**(int * *)&((struct Obj00278 *)p)->f34,2,3,0); *state=4;} break;
    case 4: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj00278 *)p)->f34)) *state=5; break;
    case 5: BR_UTIL_SetTaskStep(sys,(int)BR_POKESEARCH_MainTask); break;
    }
}







void BR_POKESEARCH_EnterListTask(int *sys,int *state,char *p)
{
    int pair[2];
    switch(*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct Obj04582 *)p)->f34,2,3,1); *state=1; break;
    case 1: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj04582 *)p)->f34)) *state=2; break;
    case 2:
        BR_POKESEARCH_DestroySearch(p,(char *)(*(int * *)&((struct Obj04582 *)p)->f34));
        BR_POKESEARCH_CreateMsgbox(p,*(int * *)&((struct Obj04582 *)p)->f34);
        pair[0]=0x80;pair[1]=0x60;
        BR_UTIL_StartEffect((int)(((struct Obj04582 *)p)->f38), 4, pair); *state=3; break;
    case 3: BR_FADE_Start(**(int * *)&((struct Obj04582 *)p)->f34,2,3,0); *state=4; break;
    case 4: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj04582 *)p)->f34)) *state=5; break;
    case 5: BR_UTIL_SetTaskStep(sys,(int)BR_POKESEARCH_NetworkTask); break;
    }
}







/*
 * abi: 021F8BBC/021F8BD6 load r1 for BR_POKESEARCH_DestroyText, retained despite unused callee input.
 */
void BR_POKESEARCH_ChangePageTask(int *task,int *state,char *p)
{
    switch (*state) {
    case 0:
        if (((struct Obj01568 *)p)->f20) BR_FADE_Start(**(int * *)&((struct Obj01568 *)p)->f34,1,1,1);
        else BR_FADE_Start(**(int * *)&((struct Obj01568 *)p)->f34,2,1,1);
        *state=1;break;
    case 1: if (BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj01568 *)p)->f34)) *state=2;break;
    case 2:
        if (((struct Obj01568 *)p)->f20) {
            BR_POKESEARCH_DestroyText(p,*(int * *)&((struct Obj01568 *)p)->f34);
            BR_POKESEARCH_ShowBg(p,(char *)(*(int * *)&((struct Obj01568 *)p)->f34));
            BR_POKESEARCH_CreateSidebar(p,*(int * *)&((struct Obj01568 *)p)->f34);
        } else {
            BR_POKESEARCH_DestroyText(p,*(int * *)&((struct Obj01568 *)p)->f34);
            BR_POKESEARCH_ShowBg(p,(char *)(*(int * *)&((struct Obj01568 *)p)->f34));
            BR_POKESEARCH_CreateText(p,*(int * *)&((struct Obj01568 *)p)->f34);
        }
        *state=3;break;
    case 3:
        if (((struct Obj01568 *)p)->f20) BR_FADE_Start(**(int * *)&((struct Obj01568 *)p)->f34,1,1,0);
        else BR_FADE_Start(**(int * *)&((struct Obj01568 *)p)->f34,2,1,0);
        *state=4;break;
    case 4: if (BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj01568 *)p)->f34)) *state=5;break;
    case 5: BR_UTIL_SetTaskStep(task,(int)BR_POKESEARCH_HandleTouch);break;
    }
}





/*
 * abi: 021F8C9E passes r1 to BR_POKESEARCH_DestroyText despite its unused second input.
 */
void BR_POKESEARCH_ChangeCategoryTask(int *task,int *state,char *p)
{
    int flag,a,b,c;
    switch (*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct Obj01769 *)p)->f34,1,1,1);*state=1;break;
    case 1: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj01769 *)p)->f34)) *state=2;break;
    case 2:
        flag=1;
        if(!((struct Obj01769 *)p)->f14) flag=0;
        if(flag) {
            BR_POKESEARCH_ShowBg(p,(char *)(*(int * *)&((struct Obj01769 *)p)->f34));
            BR_POKESEARCH_CreateText(p,*(int * *)&((struct Obj01769 *)p)->f34);
        } else {
            BR_POKESEARCH_DestroyText(p,*(int * *)&((struct Obj01769 *)p)->f34);
            BR_POKESEARCH_CreateSidebar(p,*(int * *)&((struct Obj01769 *)p)->f34);
        }
        a=BR_RES_GetFont(*(char * *)&((struct Obj24755 *)(*(char * *)&((struct Obj01769 *)p)->f34))->fC);
        b=BR_RES_GetMsgData(*(char * *)&((struct Obj24756 *)(*(char * *)&((struct Obj01769 *)p)->f34))->fC);
        if(flag) {((struct Obj01769 *)p)->f20=0;c=0x72;}
        else {((struct Obj01769 *)p)->f20=1;c=0x71;}
        BR_UTIL_SetTextFromMessage(*(char * *)&((struct Obj01769 *)p)->f1C,(void *)b,(void *)c,(void *)a,0x3da0);
        *state=3;break;
    case 3: BR_FADE_Start(**(int * *)&((struct Obj01769 *)p)->f34,1,1,0);*state=4;break;
    case 4: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct Obj01769 *)p)->f34)) *state=5;break;
    case 5: BR_UTIL_SetTaskStep(task,(int)BR_POKESEARCH_HandleTouch);break;
    }
}





/*
 * Build the p+0x14 handle once: flush the three sub-resources and start
 *   0x21F3AF0 on the indexed table entry.
 */
void BR_POKESEARCH_CreateSidebar(char *a, int *r4)
{
    if (((struct Obj06622 *)a)->f14 == 0) {
        BR_SIDEBAR_SetVisibleBySpace(r4[1], 0, 0);
        BR_RES_ApplyBgSet(r4[3], 0);
        BR_RES_ReleaseUiPalette(r4[3], 0);
        WORLDTRADE_DETAIL_StateStartWipeOut((u8 *)r4[2], ((struct Obj06622 *)a)->f30);
        ((struct Obj06622 *)a)->f14 = func_021F3AF0(
            *(int *)(a + 0x40 + ((struct Obj06622 *)a)->fC * 4) + 0x80,
            ((struct Obj06622 *)a)->f30);
    }
}



void BR_POKESEARCH_ShowBg(char *p,char *q) { if(((struct Obj03337 *)p)->f14){func_021F3BF0(((struct Obj03337 *)p)->f14);((struct Obj03337 *)p)->f14=0;BR_GRAPHIC_End3d(((struct Obj04583 *)q)->f8,((struct Obj03337 *)p)->f30);BR_RES_LoadUiPalette(*(char * *)&((struct Obj04583 *)q)->fC,0,((struct Obj03337 *)p)->f30);BR_RES_LoadBgGraphics(((struct Obj04583 *)q)->fC,0,((struct Obj03337 *)p)->f30);BR_SIDEBAR_SetVisibleBySpace((int)((char *)(((struct Obj04583 *)q)->f4)), 0, 1);} }



void BR_POKESEARCH_CreateDetail(char *p,char *q)
{
    int a,b;
    void *v;
    Config cfg;
    Triple triple;
    if (!*(int *)&((struct Obj03338 *)p)->f1C) {
        a=BR_RES_GetFont(*(char * *)&((struct Obj05490 *)q)->fC);
        b=BR_RES_GetMsgData(*(char * *)&((struct Obj05490 *)q)->fC);
        BR_GRAPHIC_GetActorUnit(((struct Obj05490 *)q)->f8);
        MI_CpuFill8(&cfg,0,8);
        cfg.x=0x50;cfg.y=0xa8;cfg.z=0;cfg.a=1;
        v=(void *)BR_GRAPHIC_GetActorUnit(((struct Obj05490 *)q)->f8);
        if (!BR_RES_GetSprite(((struct Obj05490 *)q)->fC,6,&triple)) func_02034714("",0,"");
        ((struct Obj03338 *)p)->f18=BR_BTN_CreateFromMessage(&cfg,4,0x60,1,(int)v,((struct Obj03338 *)p)->f28,a,b,&triple,((struct Obj03338 *)p)->f30);
        ((struct Obj03338 *)p)->f1C=BR_UTIL_Create(4,8,3,0x10,2,0xe,((struct Obj03338 *)p)->f2C,((struct Obj03338 *)p)->f30);
        BR_UTIL_SetTextFromMessage(*(char * *)&((struct Obj03338 *)p)->f1C,(void *)b,(void *)0x71,(void *)a,0x3da0);
        BR_RES_LoadBgGraphics((void *)(*(int *)&((struct Obj05490 *)q)->fC),0x16,((struct Obj03338 *)p)->f30);
    }
}



void BR_POKESEARCH_DestroyDetail(char *p,char *q) { if(((struct Obj06623 *)p)->f1C){BR_RES_ApplyBgSet(*(int *)&((struct Obj04583 *)q)->fC,22);BR_BTN_DeleteObject(((struct Obj06623 *)p)->f18);((struct Obj06623 *)p)->f18=0;BR_UTIL_Delete(((struct Obj06623 *)p)->f1C);((struct Obj06623 *)p)->f1C=0;BR_RES_ApplyBgSet(*(int *)&((struct Obj04583 *)q)->fC,22);} }



/*
 * note: 2026-10-04 (D2-13): body is byte-correct. Callee BR_UTIL_CreateProfileScreen (ov186, 0x021FD1C4) is a 1148-byte function in pengy's ov186 split with no witness (its listing extent shows 64 bytes, a wrong label gap); the relocation cannot resolve until it is filed. No change possible here.
 * has a seven-case resource loop, nested branches, stack aggregates and
 * many calls; no mechanical whole-body lever. W29 S24 evidence agrees.
 * tu --suggest-split confirms no viable partition; no speculative leaf C.
 * note 2026-10-05 (D4-14): re-run, still MATCH, only BR_UTIL_CreateProfileScreen (ov186, pengy split) unresolved. No change.
 * note 2026-10-05 (D8-02): re-run, still MATCH. show --region ov186 at 0x021FD1C4 starts with push {r3-r7,lr},
 *   a real 1148-byte function in pengy's ov186 split; outside this lane's write set. No change.
 */
void BR_POKESEARCH_CreateText(char *p,int *source)
{
    if(*(int *)(p+0x10)==0) {
        int a=BR_RES_GetFont((char *)source[3]);
        int b=BR_RES_GetMsgData((char *)source[3]);
        int c=BR_GRAPHIC_GetActorUnit((u8 *)source[2]);
        *(void **)(p+0x10)=BR_UTIL_CreateProfileScreen(((void **)(p+0x40))[*(unsigned short *)(p+0xc)],(char *)source[3],(void *)c,(void *)(*(int *)(p+0x2c)),1,*(unsigned short *)(p+0x30));
        BR_UTIL_SetTextFromMessage(*(char **)(p+0x1c),(void *)b,(void *)0x72,(void *)a,0x3da0);
    }
}



void BR_POKESEARCH_DestroyText(char *p, int *a1)
{
    if (((struct Obj10772 *)p)->f10 != 0) {
        BR_UTIL_DeleteProfileScreen((int *)(((struct Obj10772 *)p)->f10));
        ((struct Obj10772 *)p)->f10 = 0;
    }
}


void BR_POKESEARCH_CreateSearch(char *p,int *source)
{
    if(*(int *)&((struct Obj00278 *)p)->f0==0) {
        int c=BR_GRAPHIC_GetActorUnit((u8 *)source[2]);
        char *result;
        if(*(int *)&((struct Obj00278 *)p)->f4==0)
            ((struct Obj00278 *)p)->f4=BR_UTIL_CreateTextWin((int)((void *)source[3]),(void *)(*(int *)&((struct Obj00278 *)p)->f2C),((struct Obj00278 *)p)->f30);
        BR_UTIL_SetWindowText(((struct Obj00278 *)p)->f4,(void *)source[3],(void *)0x2c);
        result=BR_POKESEARCH_Create(ZUKAN_SAVE_GetFromGameData((void *)source[6]),(void *)source[3],c,*(int *)&((struct Obj00278 *)p)->f28,source[0],((struct Obj00278 *)p)->f38,((struct Obj00278 *)p)->f3C,((struct Obj00278 *)p)->f30);
        *(char * *)&((struct Obj00278 *)p)->f0=result;
        BR_POKESEARCH_Open(result);
    }
}


void BR_POKESEARCH_DestroySearch(char *p,char *q) { if(((struct Obj04584 *)p)->f0){BR_POKESEARCH_Close(((struct Obj04584 *)p)->f0);BR_POKESEARCH_Destroy(((struct Obj04584 *)p)->f0);((struct Obj04584 *)p)->f0=0;func_020409B4(4);if(((struct Obj04584 *)p)->f4){BR_UTIL_DeleteTextWin(((struct Obj04584 *)p)->f4,((struct Obj24759 *)q)->fC);((struct Obj04584 *)p)->f4=0;}} }


void BR_POKESEARCH_CreateMsgbox(char *p, int *q) { if(!((struct Obj06624 *)p)->f4)((struct Obj06624 *)p)->f4=BR_UTIL_CreateTextWin((int)(((struct Obj14448 *)q)->fC),(void *)(((struct Obj06624 *)p)->f2C),((struct Obj06624 *)p)->f30);BR_UTIL_SetWindowText(((struct Obj06624 *)p)->f4,((struct Obj14448 *)q)->fC,(void *)0x146); }



void BR_POKESEARCH_DestroyMsgbox(char *p, char *a1)
{
    if (((struct Obj10773 *)p)->f4 != 0) {
        BR_UTIL_DeleteTextWin((void *)(((struct Obj10773 *)p)->f4), ((struct Obj24760 *)a1)->fC);
        ((struct Obj10773 *)p)->f4 = 0;
    }
}



/*
 * Range-gate the pair then hand them to 0x21FD860 as a two-word record.
 */
int BR_POKESEARCH_HitTab(int a, int b, int c)
{
    int ok = ((unsigned)(b - 0x40) <= 0x78) & ((unsigned)(c - 0x10) <= 0x20);
    if (ok) {
        int buf[2];
        buf[0] = b;
        buf[1] = c;
        BR_UTIL_StartEffect(((struct Obj24761 *)a)->f3C, 1, buf);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}



int BR_POKESEARCH_HitPrev(int a, int b, int c)
{
    int ok = ((unsigned)(b - 0x18) <= 0x28) & ((unsigned)(c - 0x40) <= 0x28);
    if (ok) {
        int buf[2];
        buf[0] = b;
        buf[1] = c;
        BR_UTIL_StartEffect(((struct Obj24762 *)a)->f3C, 1, buf);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}

#include "../../matched/include/Obj24763.h"

int BR_POKESEARCH_HitNext(char *p,unsigned x,unsigned y)
{
    int inside=((unsigned)(x-0xb8)<=0x28)&((unsigned)(y-0x40)<=0x28);
    if(inside) {
        int pair[2];
        pair[0]=x;
        pair[1]=y;
        BR_UTIL_StartEffect((int)((struct Obj24763 *)p)->f3C,1,pair);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return inside;
}

