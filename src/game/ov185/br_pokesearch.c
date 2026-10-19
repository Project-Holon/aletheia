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
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   BR_PROC_SYS_GetSlotId 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BR_GRAPHIC_GetActorUnit 0x021FC4DC thumb ov186
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   BR_UTIL_CreateHandles 0x021FD760 thumb ov186
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   BR_UTIL_DeleteTask 0x021FD714 thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   BR_UTIL_DeleteHandles 0x021FD820 thumb ov186
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   BR_NET_HandleNetError 0x021FF88C thumb ov186
 *   BR_PROC_SYS_FlushWindows 0x021F9C6C thumb ov186
 *   BR_UTIL_RunTask 0x021FD71C thumb ov186
 *   BR_UTIL_IsTaskIdle 0x021FD72C thumb ov186
 *   BR_UTIL_RunHandles 0x021FD854 thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BR_UTIL_FlushText 0x021FC830 thumb ov186
 *   BR_UTIL_MainProfileScreen 0x021FD6B0 thumb ov186
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 *   MUSICAL_SHOT_SYS_DrawScene 0x021F3C50 thumb ov112
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
 *   BR_GRAPHIC_Begin3d   0x021FC610  thumb  ov186
 *   MUSICAL_SHOT_SYS_CreateScene   0x021F3AF0  thumb
 *   MUSICAL_SHOT_SYS_DeleteScene 0x021F3BF0 thumb ov112
 *   BR_GRAPHIC_End3d 0x021FC640 thumb ov186
 *   BR_RES_LoadUiPalette 0x021FC148 thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_BTN_CreateFromMessage 0x021FB378 thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   SAVEDATA_PanicFail 0x02034714 arm
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
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 */
#include "br_pokesearch_types.h"

struct PrintSys;
struct Pair;
typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned char  u8;

typedef struct Cfg {u16 heap;unsigned char rest[6];} Cfg;

typedef struct Pair {int x,y;} Pair;

typedef struct Config {u16 x,y,z; unsigned char a,b;} Config;

typedef struct Triple {int a,b,c;} Triple;

extern int GF_OVERLAY_Load(s32 handle);
extern unsigned BR_PROC_SYS_GetSlotId(void *p);
extern void *PROCSYS_AllocProcWork(void *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,unsigned);
extern u32 PRINTSYS_QUE_Create(void *);
extern u32 BR_GRAPHIC_GetActorUnit(u8 *p);
extern void *BMP_OAM_CreateSys(unsigned int heapId, void *clact);
extern char *BR_UTIL_CreateHandles(unsigned owner, char *resources, int index, int heap);
extern void BR_RES_LoadSprite(char *base, u32 idx, u32 area);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern int *BR_UTIL_CreateTask(int payload, int callback, u32 heap);
extern void BR_UTIL_DeleteTask(void *p);
extern void BR_RES_ReleaseSprite(char *p, unsigned i);
extern void BR_UTIL_DeleteHandles(char *);
extern void BMP_OAM_DeleteSys(void *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void PROCSYS_FreeProcWork(void *p);
extern void GF_OVERLAY_Unload(int);
extern int BR_NET_HandleNetError(char *);
extern void BR_PROC_SYS_FlushWindows(char *);
extern void BR_UTIL_RunTask(u8 *p);
extern int BR_UTIL_IsTaskIdle(int *);
extern void BR_UTIL_RunHandles(char *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern int BR_UTIL_FlushText(u8 *p);
extern int BR_UTIL_MainProfileScreen(u8 *p);
extern void BR_UTIL_FlushWindow(void *p);
extern void MUSICAL_SHOT_SYS_DrawScene(u8 *p);
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
extern int BR_GRAPHIC_Begin3d(u8 *p, int a1);
extern int MUSICAL_SHOT_SYS_CreateScene(int, int);
extern void MUSICAL_SHOT_SYS_DeleteScene(u8 *);
extern void BR_GRAPHIC_End3d(void *,unsigned);
extern void BR_RES_LoadUiPalette(char *,unsigned,unsigned);
extern void BR_RES_LoadBgGraphics(void *,unsigned,u16);
extern int BR_RES_GetSprite(void *,unsigned,void *);
extern void SAVEDATA_PanicFail(const char *,unsigned,const char *);
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
extern void BG_SYS_PushTile(unsigned);
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
void BR_POKESEARCH_DestroyText(char *p, int *unused);
void BR_POKESEARCH_CreateSearch(char *p,int *source);
void BR_POKESEARCH_DestroySearch(char *p,char *q);
void BR_POKESEARCH_CreateMsgbox(char *p, int *q);
void BR_POKESEARCH_DestroyMsgbox(char *p, char *owner);
int BR_POKESEARCH_HitTab(int a, int b, int c);
int BR_POKESEARCH_HitPrev(int a, int b, int c);
extern char ov112_id[];











int BR_POKESEARCH_CreateWork(void *procSys,int unused,char *owner)
{
    char *work;
    void *graphic;
    int handleIndex;
    GF_OVERLAY_Load((int)ov112_id);
    work=PROCSYS_AllocProcWork(procSys,88,BR_PROC_SYS_GetSlotId(((struct BrDownloadOwner *)owner)->proc.proc));
    MI_CpuFill8(work,0,88);
    *(char * *)&((struct BrPokeSearchWork *)work)->owner=owner;
    ((struct BrPokeSearchWork *)work)->heapId=BR_PROC_SYS_GetSlotId(((struct BrDownloadOwner *)owner)->proc.proc);
    ((struct BrPokeSearchWork *)work)->printQue.printQue=PRINTSYS_QUE_Create((void *)(unsigned int)((struct BrPokeSearchWork *)work)->heapId);
    graphic=(void *)BR_GRAPHIC_GetActorUnit(((struct BrDownloadOwner *)owner)->graphic.graphic);
    ((struct BrPokeSearchWork *)work)->oamData.oamData=BMP_OAM_CreateSys(((struct BrPokeSearchWork *)work)->heapId,graphic);
    for (handleIndex=0;handleIndex<2;handleIndex++) ((void **)&((struct BrPokeSearchWork *)work)->listParam)[handleIndex]=BR_UTIL_CreateHandles((unsigned int)graphic,(char *)(((struct BrDownloadOwner *)owner)->res.resHandle),handleIndex,((struct BrPokeSearchWork *)work)->heapId);
    BR_RES_LoadSprite((char *)(((struct BrDownloadOwner *)owner)->res.resHandle),6,((struct BrPokeSearchWork *)work)->heapId);
    BG_SYS_SetPlaneVisible(0,1);
    BR_POKESEARCH_CreateSearch(work,(int *)owner);
    ((struct BrPokeSearchWork *)work)->task.task=BR_UTIL_CreateTask((int)work,(int)BR_POKESEARCH_OpenTask,((struct BrPokeSearchWork *)work)->heapId);
    return 1;
}











int BR_POKESEARCH_DestroyWork(int procSys,int unused,char *owner,char *work)
{
    int handleIndex;
    BR_POKESEARCH_ShowBg(work,owner);
    BR_POKESEARCH_DestroyDetail(work,owner);
    BR_POKESEARCH_DestroyText(work,(int *)owner);
    BR_POKESEARCH_DestroySearch(work,owner);
    BR_POKESEARCH_DestroyMsgbox(work,owner);
    BR_UTIL_DeleteTask((void *)(((struct BrPokeSearchWork *)work)->task.taskHandle));
    BR_POKESEARCH_DestroySearch(work,owner);
    BR_RES_ReleaseSprite((char *)(*(int *)&((struct BrDownloadOwner *)owner)->res.res),6);
    for (handleIndex=0;handleIndex<2;handleIndex++) BR_UTIL_DeleteHandles(((char **)&((struct BrPokeSearchWork *)work)->listParam)[handleIndex]);
    BMP_OAM_DeleteSys((void *)(((struct BrPokeSearchWork *)work)->oamData.oamHandle));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct BrPokeSearchWork *)work)->printQue.printQueHandle));
    PROCSYS_FreeProcWork((void *)procSys);
    GF_OVERLAY_Unload((int)ov112_id);
    return 1;
}











int BR_POKESEARCH_Update(int task,int unused,int unused2,char *work)
{
    int handleIndex;
    if (BR_NET_HandleNetError(*(char * *)&((struct BrDownloadOwner *)(*(char * *)&((struct BrPokeSearchWork *)work)->owner))->net)==2) {
        BR_PROC_SYS_FlushWindows(*(char * *)&((struct BrDownloadOwner *)(*(char * *)&((struct BrPokeSearchWork *)work)->owner))->proc.proc);
        return 1;
    }
    BR_UTIL_RunTask((u8 *)(*(char * *)&((struct BrPokeSearchWork *)work)->task.task));
    if (BR_UTIL_IsTaskIdle(*(int * *)&((struct BrPokeSearchWork *)work)->task.task)) return 1;
    for (handleIndex=0;handleIndex<2;handleIndex++) BR_UTIL_RunHandles(((char **)&((struct BrPokeSearchWork *)work)->listParam)[handleIndex]);
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct BrPokeSearchWork *)work)->printQue.printQueHandle));
    if (*(char * *)&((struct BrPokeSearchWork *)work)->detailWin) BR_UTIL_FlushText((u8 *)(*(char * *)&((struct BrPokeSearchWork *)work)->detailWin));
    if (*(char * *)&((struct BrPokeSearchWork *)work)->profileScreen.profileScreen) BR_UTIL_MainProfileScreen((u8 *)(*(char * *)&((struct BrPokeSearchWork *)work)->profileScreen.profileScreen));
    if (*(char * *)&((struct BrPokeSearchWork *)work)->window.window) BR_UTIL_FlushWindow(*(char * *)&((struct BrPokeSearchWork *)work)->window.window);
    if (*(char * *)&((struct BrPokeSearchWork *)work)->scene.scene) MUSICAL_SHOT_SYS_DrawScene((u8 *)(*(char * *)&((struct BrPokeSearchWork *)work)->scene.scene));
    return 0;
}










void BR_POKESEARCH_OpenTask(int task,int *state,char *work)
{
    switch (*state) {
    case 0: if (BR_POKESEARCH_UpdatePrint((char *)(((struct BrPokeSearchWork *)work)->search.searchHandle))) { BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,2,3,0); *state=1; } break;
    case 1: if (BR_FADE_GetResult((int *)(**(int * *)&((struct BrPokeSearchWork *)work)->owner))) *state=2; break;
    case 2: BR_UTIL_SetTaskStep((int *)task,(int)BR_POKESEARCH_MainTask); break;
    }
}










void BR_POKESEARCH_CloseTask(int task,int *state,char *work)
{
    switch (*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,2,3,1); *state=1; break;
    case 1: if (BR_FADE_GetResult((int *)(**(int * *)&((struct BrPokeSearchWork *)work)->owner))) *state=2; break;
    case 2: BR_UTIL_ClearTaskStep((int *)(((struct BrPokeSearchWork *)work)->task.taskHandle)); BR_PROC_SYS_PopEntry((unsigned int *)(((struct BrDownloadOwner *)(*(char * *)&((struct BrPokeSearchWork *)work)->owner))->proc.procHandle)); break;
    }
}











void BR_POKESEARCH_MainTask(int task, int unused, char *work)
{
    unsigned short speciesOut;
    int result;
    BR_POKESEARCH_Main(((struct BrPokeSearchWork *)work)->search.searchHandle);
    result = BR_POKESEARCH_GetResult(((struct BrPokeSearchWork *)work)->search.searchHandle, &speciesOut);
    if (result == 0)
        return;
    if (result == 2) {
        ((struct BrPokeSearchWork *)work)->speciesId = speciesOut;
        BR_UTIL_SetTaskStep((int *)task, (int)BR_POKESEARCH_EnterListTask);
    } else {
        BR_UTIL_SetTaskStep((int *)task, (int)BR_POKESEARCH_CloseTask);
    }
}








void BR_POKESEARCH_HandleTouch(int task,int unused,char *work)
{
    int touchX,touchY;
    if (TOUCHPANEL_GetPointTrg((u32 *)(&touchX),(u32 *)(&touchY))) {
        if (BR_BTN_HitTestWithSound((unsigned int *)(((struct BrPokeSearchWork *)work)->backButton.backButtonHandle),touchX,touchY)) {
            int point[2];
            point[0]=touchX; point[1]=touchY;
            BR_UTIL_StartEffect(((struct BrPokeSearchWork *)work)->tapFx.tapFxHandle,1,point);
            BR_UTIL_SetTaskStep((int *)task,(int)BR_POKESEARCH_ExitTask);
        }
        if (BR_POKESEARCH_HitTab((int)work,touchX,touchY)) BR_UTIL_SetTaskStep((int *)task,(int)BR_POKESEARCH_ChangeCategoryTask);
        if (BR_POKESEARCH_HitPrev((int)work,touchX,touchY)) {
            int pageIndex=((struct BrPokeSearchWork *)work)->listIndex-1;
            if (pageIndex<0) ((struct BrPokeSearchWork *)work)->listIndex=((struct BrPokeSearchWork *)work)->count-1;
            else ((struct BrPokeSearchWork *)work)->listIndex=pageIndex;
            BR_UTIL_SetTaskStep((int *)task,(int)BR_POKESEARCH_ChangePageTask);
        }
        if (BR_POKESEARCH_HitNext((char *)((int)work),touchX,touchY)) {
            ((struct BrPokeSearchWork *)work)->listIndex=((struct BrPokeSearchWork *)work)->listIndex+1;
            ((struct BrPokeSearchWork *)work)->listIndex=(int)((struct BrPokeSearchWork *)work)->listIndex % ((struct BrPokeSearchWork *)work)->count;
            BR_UTIL_SetTaskStep((int *)task,(int)BR_POKESEARCH_ChangePageTask);
        }
    }
}








void BR_POKESEARCH_NetworkTask(int *task,unsigned *state,char *work)
{
    Cfg request;
    int errorCode,touchX,touchY;
    Pair point;
    switch(*state) {
    case 0:
        MI_CpuFill8(&request,0,8);
        request.heap=((struct BrPokeSearchWork *)work)->speciesId;
        ((struct BrPokeSearchWork *)work)->netRetry=0;
        BR_NET_StartRequest(*(char * *)&((struct BrDownloadOwner *)(*(char * *)&((struct BrPokeSearchWork *)work)->owner))->net,1,(const int *)(&request));
        *state=1; break;
    case 1:
        ((struct BrPokeSearchWork *)work)->netRetry=((struct BrPokeSearchWork *)work)->netRetry+1;
        if(BR_NET_IsIdle(*(char * *)&((struct BrDownloadOwner *)(*(char * *)&((struct BrPokeSearchWork *)work)->owner))->net) && ((struct BrPokeSearchWork *)work)->netRetry>0x60) {
            BR_UTIL_StartEffect(((struct BrPokeSearchWork *)work)->listParam.listParam, 0, (int *)0);
            *state=2;
        }
        break;
    case 2:
        if(!BR_NET_PollErrorMessage(*(char * *)&((struct BrDownloadOwner *)(*(char * *)&((struct BrPokeSearchWork *)work)->owner))->net,&errorCode)) {
            if(BR_NET_GetDownloadEntries(*(char * *)&((struct BrDownloadOwner *)(*(char * *)&((struct BrPokeSearchWork *)work)->owner))->net,(int)((struct BrPokeSearchWork *)work)->table,5,(int *)&((struct BrPokeSearchWork *)work)->count) && ((struct BrPokeSearchWork *)work)->count) {
                ((struct BrPokeSearchWork *)work)->listIndex=0;
                BR_UTIL_SetTaskStep(task,(int)BR_POKESEARCH_DownloadDoneTask);
                break;
            }
            *state=3;
            BR_UTIL_SetWindowText(((struct BrPokeSearchWork *)work)->window.window,((struct BrDownloadOwner *)(*(char * *)&((struct BrPokeSearchWork *)work)->owner))->res.res,(void *)0x14d);
        }else{
            *state=3;
            BR_UTIL_SetWindowText(((struct BrPokeSearchWork *)work)->window.window,((struct BrDownloadOwner *)(*(char * *)&((struct BrPokeSearchWork *)work)->owner))->res.res,(void *)errorCode);
        }
        break;
    case 3:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg((u32 *)(&touchX),(u32 *)(&touchY));
            point.x=touchX;point.y=touchY;
            BR_UTIL_StartEffect(((struct BrPokeSearchWork *)work)->tapFx.tapFxHandle, 1, (int *)&point);
            GFL_USE_PlaySeDefaultVolume(0x703);
            BR_UTIL_SetTaskStep(task,(int)BR_POKESEARCH_RefreshTask);
        }
        break;
    }
}








void BR_POKESEARCH_DownloadDoneTask(int task,int *state,char *work)
{
    switch (*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,4,3,1); *state=1; break;
    case 1: if (BR_FADE_GetResult((int *)(**(int * *)&((struct BrPokeSearchWork *)work)->owner))) *state=2; break;
    case 2: BR_POKESEARCH_DestroyMsgbox(work,*(char * *)&((struct BrPokeSearchWork *)work)->owner); BR_POKESEARCH_CreateSidebar(work,*(int * *)&((struct BrPokeSearchWork *)work)->owner); BR_POKESEARCH_CreateDetail(work,*(char * *)&((struct BrPokeSearchWork *)work)->owner); *state=3; break;
    case 3: BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,4,3,0); *state=4; break;
    case 4: if (BR_FADE_GetResult((int *)(**(int * *)&((struct BrPokeSearchWork *)work)->owner))) *state=5; break;
    case 5: ((struct BrPokeSearchWork *)work)->sidebarShown=1; BR_UTIL_SetTaskStep((int *)task,(int)BR_POKESEARCH_HandleTouch); break;
    }
}







void BR_POKESEARCH_ExitTask(int *task,int *state,char *work)
{
    switch(*state) {
    case 0:
        if(((struct BrPokeSearchWork *)work)->sidebarShown) BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,4,3,1);
        else BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,2,3,1);
        *state=1; break;
    case 1: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct BrPokeSearchWork *)work)->owner)) *state=2; break;
    case 2:
        BR_POKESEARCH_DestroyText(work,*(int * *)&((struct BrPokeSearchWork *)work)->owner);
        BR_POKESEARCH_ShowBg(work,(char *)(*(int * *)&((struct BrPokeSearchWork *)work)->owner));
        BR_POKESEARCH_DestroyDetail(work,(char *)(*(int * *)&((struct BrPokeSearchWork *)work)->owner));
        BR_POKESEARCH_CreateSearch(work,*(int * *)&((struct BrPokeSearchWork *)work)->owner);
        *state=3; break;
    case 3:
        if(((struct BrPokeSearchWork *)work)->sidebarShown) BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,4,3,0);
        else BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,2,3,0);
        *state=4; break;
    case 4: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct BrPokeSearchWork *)work)->owner)) *state=5; break;
    case 5: BR_UTIL_SetTaskStep(task,(int)BR_POKESEARCH_MainTask); break;
    }
}







void BR_POKESEARCH_RefreshTask(int *task,int *state,char *work)
{
    switch(*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,2,3,1); *state=1; break;
    case 1: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct BrPokeSearchWork *)work)->owner)) *state=2; break;
    case 2: BR_POKESEARCH_DestroyMsgbox(work,(char *)(*(int * *)&((struct BrPokeSearchWork *)work)->owner)); BR_POKESEARCH_CreateSearch(work,*(int * *)&((struct BrPokeSearchWork *)work)->owner); *state=3; break;
    case 3: if(BR_POKESEARCH_UpdatePrint((char *)(*(int *)&((struct BrPokeSearchWork *)work)->search.search))) {BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,2,3,0); *state=4;} break;
    case 4: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct BrPokeSearchWork *)work)->owner)) *state=5; break;
    case 5: BR_UTIL_SetTaskStep(task,(int)BR_POKESEARCH_MainTask); break;
    }
}







void BR_POKESEARCH_EnterListTask(int *task,int *state,char *work)
{
    int point[2];
    switch(*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,2,3,1); *state=1; break;
    case 1: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct BrPokeSearchWork *)work)->owner)) *state=2; break;
    case 2:
        BR_POKESEARCH_DestroySearch(work,(char *)(*(int * *)&((struct BrPokeSearchWork *)work)->owner));
        BR_POKESEARCH_CreateMsgbox(work,*(int * *)&((struct BrPokeSearchWork *)work)->owner);
        point[0]=0x80;point[1]=0x60;
        BR_UTIL_StartEffect((int)(((struct BrPokeSearchWork *)work)->listParam.listParamPtr), 4, point); *state=3; break;
    case 3: BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,2,3,0); *state=4; break;
    case 4: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct BrPokeSearchWork *)work)->owner)) *state=5; break;
    case 5: BR_UTIL_SetTaskStep(task,(int)BR_POKESEARCH_NetworkTask); break;
    }
}







/*
 * abi: 021F8BBC/021F8BD6 load r1 for BR_POKESEARCH_DestroyText, retained despite unused callee input.
 */
void BR_POKESEARCH_ChangePageTask(int *task,int *state,char *work)
{
    switch (*state) {
    case 0:
        if (((struct BrPokeSearchWork *)work)->sidebarShown) BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,1,1,1);
        else BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,2,1,1);
        *state=1;break;
    case 1: if (BR_FADE_GetResult(*(int **)*(int * *)&((struct BrPokeSearchWork *)work)->owner)) *state=2;break;
    case 2:
        if (((struct BrPokeSearchWork *)work)->sidebarShown) {
            BR_POKESEARCH_DestroyText(work,*(int * *)&((struct BrPokeSearchWork *)work)->owner);
            BR_POKESEARCH_ShowBg(work,(char *)(*(int * *)&((struct BrPokeSearchWork *)work)->owner));
            BR_POKESEARCH_CreateSidebar(work,*(int * *)&((struct BrPokeSearchWork *)work)->owner);
        } else {
            BR_POKESEARCH_DestroyText(work,*(int * *)&((struct BrPokeSearchWork *)work)->owner);
            BR_POKESEARCH_ShowBg(work,(char *)(*(int * *)&((struct BrPokeSearchWork *)work)->owner));
            BR_POKESEARCH_CreateText(work,*(int * *)&((struct BrPokeSearchWork *)work)->owner);
        }
        *state=3;break;
    case 3:
        if (((struct BrPokeSearchWork *)work)->sidebarShown) BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,1,1,0);
        else BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,2,1,0);
        *state=4;break;
    case 4: if (BR_FADE_GetResult(*(int **)*(int * *)&((struct BrPokeSearchWork *)work)->owner)) *state=5;break;
    case 5: BR_UTIL_SetTaskStep(task,(int)BR_POKESEARCH_HandleTouch);break;
    }
}





/*
 * abi: 021F8C9E passes r1 to BR_POKESEARCH_DestroyText despite its unused second input.
 */
void BR_POKESEARCH_ChangeCategoryTask(int *task,int *state,char *work)
{
    int hasSidebar,font,msgData,msgId;
    switch (*state) {
    case 0: BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,1,1,1);*state=1;break;
    case 1: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct BrPokeSearchWork *)work)->owner)) *state=2;break;
    case 2:
        hasSidebar=1;
        if(!((struct BrPokeSearchWork *)work)->scene.sceneHandle) hasSidebar=0;
        if(hasSidebar) {
            BR_POKESEARCH_ShowBg(work,(char *)(*(int * *)&((struct BrPokeSearchWork *)work)->owner));
            BR_POKESEARCH_CreateText(work,*(int * *)&((struct BrPokeSearchWork *)work)->owner);
        } else {
            BR_POKESEARCH_DestroyText(work,*(int * *)&((struct BrPokeSearchWork *)work)->owner);
            BR_POKESEARCH_CreateSidebar(work,*(int * *)&((struct BrPokeSearchWork *)work)->owner);
        }
        font=BR_RES_GetFont(*(char * *)&((struct BrDownloadOwner *)(*(char * *)&((struct BrPokeSearchWork *)work)->owner))->res.res);
        msgData=BR_RES_GetMsgData(*(char * *)&((struct BrDownloadOwner *)(*(char * *)&((struct BrPokeSearchWork *)work)->owner))->res.res);
        if(hasSidebar) {((struct BrPokeSearchWork *)work)->sidebarShown=0;msgId=0x72;}
        else {((struct BrPokeSearchWork *)work)->sidebarShown=1;msgId=0x71;}
        BR_UTIL_SetTextFromMessage(*(char * *)&((struct BrPokeSearchWork *)work)->detailWin,(void *)msgData,(void *)msgId,(void *)font,0x3da0);
        *state=3;break;
    case 3: BR_FADE_Start(**(int * *)&((struct BrPokeSearchWork *)work)->owner,1,1,0);*state=4;break;
    case 4: if(BR_FADE_GetResult(*(int **)*(int * *)&((struct BrPokeSearchWork *)work)->owner)) *state=5;break;
    case 5: BR_UTIL_SetTaskStep(task,(int)BR_POKESEARCH_HandleTouch);break;
    }
}





/*
 * Build the scene handle once: flush the three sub-resources and start
 *   0x21F3AF0 on the indexed table entry.
 */
void BR_POKESEARCH_CreateSidebar(char *work, int *owner)
{
    if (((struct BrPokeSearchWork *)work)->scene.sceneHandle == 0) {
        BR_SIDEBAR_SetVisibleBySpace(((struct BrDownloadOwner *)owner)->sidebar, 0, 0);
        BR_RES_ApplyBgSet(((struct BrDownloadOwner *)owner)->res.resHandle, 0);
        BR_RES_ReleaseUiPalette(((struct BrDownloadOwner *)owner)->res.resHandle, 0);
        BR_GRAPHIC_Begin3d((u8 *)(((struct BrDownloadOwner *)owner)->graphic.graphic), ((struct BrPokeSearchWork *)work)->heapId);
        ((struct BrPokeSearchWork *)work)->scene.sceneHandle = MUSICAL_SHOT_SYS_CreateScene(
            (int)((struct BrPokeSearchWork *)work)->table[((struct BrPokeSearchWork *)work)->listIndex] + 0x80,
            ((struct BrPokeSearchWork *)work)->heapId);
    }
}



void BR_POKESEARCH_ShowBg(char *work,char *owner) { if(((struct BrPokeSearchWork *)work)->scene.scene){MUSICAL_SHOT_SYS_DeleteScene(((struct BrPokeSearchWork *)work)->scene.scene);((struct BrPokeSearchWork *)work)->scene.scene=0;BR_GRAPHIC_End3d(((struct BrDownloadOwner *)owner)->graphic.graphic,((struct BrPokeSearchWork *)work)->heapId);BR_RES_LoadUiPalette(*(char * *)&((struct BrDownloadOwner *)owner)->res.res,0,((struct BrPokeSearchWork *)work)->heapId);BR_RES_LoadBgGraphics(((struct BrDownloadOwner *)owner)->res.res,0,((struct BrPokeSearchWork *)work)->heapId);BR_SIDEBAR_SetVisibleBySpace((int)((char *)(((struct BrDownloadOwner *)owner)->sidebar)), 0, 1);} }



void BR_POKESEARCH_CreateDetail(char *work,char *owner)
{
    int font,msgData;
    void *graphic;
    Config pos;
    Triple sprite;
    if (!*(int *)&((struct BrPokeSearchWork *)work)->detailWin) {
        font=BR_RES_GetFont(*(char * *)&((struct BrDownloadOwner *)owner)->res.res);
        msgData=BR_RES_GetMsgData(*(char * *)&((struct BrDownloadOwner *)owner)->res.res);
        BR_GRAPHIC_GetActorUnit(((struct BrDownloadOwner *)owner)->graphic.graphic);
        MI_CpuFill8(&pos,0,8);
        pos.x=0x50;pos.y=0xa8;pos.z=0;pos.a=1;
        graphic=(void *)BR_GRAPHIC_GetActorUnit(((struct BrDownloadOwner *)owner)->graphic.graphic);
        if (!BR_RES_GetSprite(((struct BrDownloadOwner *)owner)->res.res,6,&sprite)) SAVEDATA_PanicFail("",0,"");
        ((struct BrPokeSearchWork *)work)->backButton.backButton=BR_BTN_CreateFromMessage(&pos,4,0x60,1,(int)graphic,((struct BrPokeSearchWork *)work)->oamData.oamHandle,font,msgData,&sprite,((struct BrPokeSearchWork *)work)->heapId);
        ((struct BrPokeSearchWork *)work)->detailWin=BR_UTIL_Create(4,8,3,0x10,2,0xe,((struct BrPokeSearchWork *)work)->printQue.printQuePtr,((struct BrPokeSearchWork *)work)->heapId);
        BR_UTIL_SetTextFromMessage(*(char * *)&((struct BrPokeSearchWork *)work)->detailWin,(void *)msgData,(void *)0x71,(void *)font,0x3da0);
        BR_RES_LoadBgGraphics((void *)(*(int *)&((struct BrDownloadOwner *)owner)->res.res),0x16,((struct BrPokeSearchWork *)work)->heapId);
    }
}



void BR_POKESEARCH_DestroyDetail(char *work,char *owner) { if(((struct BrPokeSearchWork *)work)->detailWin){BR_RES_ApplyBgSet(*(int *)&((struct BrDownloadOwner *)owner)->res.res,22);BR_BTN_DeleteObject(((struct BrPokeSearchWork *)work)->backButton.backButton);((struct BrPokeSearchWork *)work)->backButton.backButton=0;BR_UTIL_Delete(((struct BrPokeSearchWork *)work)->detailWin);((struct BrPokeSearchWork *)work)->detailWin=0;BR_RES_ApplyBgSet(*(int *)&((struct BrDownloadOwner *)owner)->res.res,22);} }



/*
 * note: 2026-10-04 (D2-13): body is byte-correct. Callee BR_UTIL_CreateProfileScreen (ov186, 0x021FD1C4) is a 1148-byte function in pengy's ov186 split with no witness (its listing extent shows 64 bytes, a wrong label gap); the relocation cannot resolve until it is filed. No change possible here.
 * has a seven-case resource loop, nested branches, stack aggregates and
 * many calls; no mechanical whole-body lever. W29 S24 evidence agrees.
 * tu --suggest-split confirms no viable partition; no speculative leaf C.
 * note 2026-10-05 (D4-14): re-run, still MATCH, only BR_UTIL_CreateProfileScreen (ov186, pengy split) unresolved. No change.
 * note 2026-10-05 (D8-02): re-run, still MATCH. show --region ov186 at 0x021FD1C4 starts with push {r3-r7,lr},
 *   a real 1148-byte function in pengy's ov186 split; outside this lane's write set. No change.
 */
void BR_POKESEARCH_CreateText(char *work,int *owner)
{
    if(((struct BrPokeSearchWork *)work)->profileScreen.profileScreenHandle==0) {
        int font=BR_RES_GetFont((char *)(((struct BrDownloadOwner *)owner)->res.resHandle));
        int msgData=BR_RES_GetMsgData((char *)(((struct BrDownloadOwner *)owner)->res.resHandle));
        int actorUnit=BR_GRAPHIC_GetActorUnit((u8 *)(((struct BrDownloadOwner *)owner)->graphic.graphic));
        ((struct BrPokeSearchWork *)work)->profileScreen.profileScreen=BR_UTIL_CreateProfileScreen(((struct BrPokeSearchWork *)work)->table[((struct BrPokeSearchWork *)work)->listIndex],(char *)(((struct BrDownloadOwner *)owner)->res.resHandle),(void *)actorUnit,(void *)(((struct BrPokeSearchWork *)work)->printQue.printQueHandle),1,((struct BrPokeSearchWork *)work)->heapId);
        BR_UTIL_SetTextFromMessage(*(char * *)&((struct BrPokeSearchWork *)work)->detailWin,(void *)msgData,(void *)0x72,(void *)font,0x3da0);
    }
}



void BR_POKESEARCH_DestroyText(char *work, int *unused)
{
    if (((struct BrPokeSearchWork *)work)->profileScreen.profileScreenHandle != 0) {
        BR_UTIL_DeleteProfileScreen((int *)(((struct BrPokeSearchWork *)work)->profileScreen.profileScreenHandle));
        ((struct BrPokeSearchWork *)work)->profileScreen.profileScreenHandle = 0;
    }
}


void BR_POKESEARCH_CreateSearch(char *work,int *owner)
{
    if(*(int *)&((struct BrPokeSearchWork *)work)->search.search==0) {
        int actorUnit=BR_GRAPHIC_GetActorUnit((u8 *)(((struct BrDownloadOwner *)owner)->graphic.graphic));
        char *searchScreen;
        if(*(int *)&((struct BrPokeSearchWork *)work)->window.window==0)
            ((struct BrPokeSearchWork *)work)->window.window=BR_UTIL_CreateTextWin((int)(((struct BrDownloadOwner *)owner)->res.resHandle),(void *)(*(int *)&((struct BrPokeSearchWork *)work)->printQue.printQue),((struct BrPokeSearchWork *)work)->heapId);
        BR_UTIL_SetWindowText(((struct BrPokeSearchWork *)work)->window.window,(void *)(((struct BrDownloadOwner *)owner)->res.resHandle),(void *)0x2c);
        searchScreen=BR_POKESEARCH_Create(ZUKAN_SAVE_GetFromGameData((void *)(((struct BrDownloadOwner *)owner)->zukanSource)),(void *)(((struct BrDownloadOwner *)owner)->res.resHandle),actorUnit,*(int *)&((struct BrPokeSearchWork *)work)->oamData.oamData,(int)((struct BrDownloadOwner *)owner)->fade,((struct BrPokeSearchWork *)work)->listParam.listParam,((struct BrPokeSearchWork *)work)->tapFx.tapFxHandle,((struct BrPokeSearchWork *)work)->heapId);
        *(char * *)&((struct BrPokeSearchWork *)work)->search.search=searchScreen;
        BR_POKESEARCH_Open(searchScreen);
    }
}


void BR_POKESEARCH_DestroySearch(char *work,char *owner) { if(((struct BrPokeSearchWork *)work)->search.search){BR_POKESEARCH_Close(((struct BrPokeSearchWork *)work)->search.search);BR_POKESEARCH_Destroy(((struct BrPokeSearchWork *)work)->search.search);((struct BrPokeSearchWork *)work)->search.search=0;BG_SYS_PushTile(4);if(((struct BrPokeSearchWork *)work)->window.window){BR_UTIL_DeleteTextWin(((struct BrPokeSearchWork *)work)->window.window,((struct BrDownloadOwner *)owner)->res.resHandle);((struct BrPokeSearchWork *)work)->window.window=0;}} }


void BR_POKESEARCH_CreateMsgbox(char *work, int *owner) { if(!((struct BrPokeSearchWork *)work)->window.window)((struct BrPokeSearchWork *)work)->window.window=BR_UTIL_CreateTextWin((int)(((struct BrDownloadOwner *)owner)->res.res),(void *)(((struct BrPokeSearchWork *)work)->printQue.printQueHandle),((struct BrPokeSearchWork *)work)->heapId);BR_UTIL_SetWindowText(((struct BrPokeSearchWork *)work)->window.window,((struct BrDownloadOwner *)owner)->res.res,(void *)0x146); }



void BR_POKESEARCH_DestroyMsgbox(char *work, char *owner)
{
    if (((struct BrPokeSearchWork *)work)->window.windowHandle != 0) {
        BR_UTIL_DeleteTextWin((void *)(((struct BrPokeSearchWork *)work)->window.windowHandle), ((struct BrDownloadOwner *)owner)->res.resHandle);
        ((struct BrPokeSearchWork *)work)->window.windowHandle = 0;
    }
}



/*
 * Range-gate the pair then hand them to 0x21FD860 as a two-word record.
 */
int BR_POKESEARCH_HitTab(int work, int touchX, int touchY)
{
    int inside = ((unsigned)(touchX - 0x40) <= 0x78) & ((unsigned)(touchY - 0x10) <= 0x20);
    if (inside) {
        int point[2];
        point[0] = touchX;
        point[1] = touchY;
        BR_UTIL_StartEffect(((struct BrPokeSearchWork *)work)->tapFx.tapFxHandle, 1, point);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return inside;
}



int BR_POKESEARCH_HitPrev(int a, int b, int c)
{
    int ok = ((unsigned)(b - 0x18) <= 0x28) & ((unsigned)(c - 0x40) <= 0x28);
    if (ok) {
        int buf[2];
        buf[0] = b;
        buf[1] = c;
        BR_UTIL_StartEffect(((struct BrPokeSearchWork *)a)->tapFx.tapFxHandle, 1, buf);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}


int BR_POKESEARCH_HitNext(char *p,unsigned x,unsigned y)
{
    int inside=((unsigned)(x-0xb8)<=0x28)&((unsigned)(y-0x40)<=0x28);
    if(inside) {
        int pair[2];
        pair[0]=x;
        pair[1]=y;
        BR_UTIL_StartEffect((int)((struct BrPokeSearchWork *)p)->tapFx.tapFxPtr,1,pair);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return inside;
}

