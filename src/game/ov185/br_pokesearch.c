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
 *   GF_PANIC_Fail 0x02034714 arm
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
#include "br_pokesearch.h"

struct PrintSys;
struct BrPokesearchPair;
#include "../types.h"

typedef struct BrPokesearchCfg {u16 heap;unsigned char rest[6];} BrPokesearchCfg;

typedef struct BrPokesearchPair {int x,y;} BrPokesearchPair;

typedef struct BrPokesearchConfig {u16 x,y,z; unsigned char a,b;} BrPokesearchConfig;

typedef struct BrPokesearchTriple {int a,b,c;} BrPokesearchTriple;

#include "../arm9/gf_overlay.h"
struct BrProcQuery;
#include "../ov186/br_proc_sys.h"
struct Proc;
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
struct PrintQueue;
#include "../arm9/printsys.h"
struct BrGraphic;
#include "../ov186/br_graphic.h"
struct BmpOamSys;
#include "../arm9/bmp_oam.h"
#include "../ov186/br_util.h"
struct BrRes;
#include "../arm9/bg_sys.h"
struct BrNet;
#include "../ov186/br_net.h"
#include "../ov112/mus_shot_photo.h"
struct BrPokeSearch;
#include "../ov186/br_pokesearch.h"
#include "../ov186/br_fade.h"
struct BrFade;
#include "../arm9/touchpanel.h"
#include "../ov186/br_btn.h"
union BrNetRequest;
#include "../arm9/gfl_use.h"
#include "../arm9/gf_panic.h"
#include "../arm9/zukan_save.h"
#include "../ov186/br_res.h"
#include "../ov186/br_sidebar.h"
struct BrTapFx;
struct ZukanSave;
extern char ov112_id[];

int BR_POKESEARCH_CreateWork(void *procSys,int unused,struct BrDownloadOwner *owner)
{
    struct BrPokeSearchWork *work;
    void *graphic;
    int handleIndex;
    GF_OVERLAY_Load((sptr)ov112_id);
    work=PROCSYS_AllocProcWork(procSys,sizeof(struct BrPokeSearchWork),BR_PROC_SYS_GetSlotId(owner->proc));
    MI_CpuFill8(work,0,sizeof(struct BrPokeSearchWork));
    work->owner=owner;
    work->heapId=BR_PROC_SYS_GetSlotId(owner->proc);
    work->printQue=PRINTSYS_QUE_Create((unsigned int)(unsigned int)work->heapId);
    graphic=(void *)BR_GRAPHIC_GetActorUnit(owner->graphic);
    work->oamData=BMP_OAM_CreateSys(work->heapId,graphic);
    for (handleIndex=0;handleIndex<2;handleIndex++) work->handles[handleIndex]=BR_UTIL_CreateHandles(graphic,owner->res,handleIndex,work->heapId);
    BR_RES_LoadSprite((struct BrRes *)(owner->res),6,work->heapId);
    BG_SYS_SetPlaneVisible(0,1);
    BR_POKESEARCH_CreateSearch(work,owner);
    work->task=BR_UTIL_CreateTask(work,BR_POKESEARCH_OpenTask,work->heapId);
    return 1;
}

int BR_POKESEARCH_DestroyWork(void *procSys,int unused,struct BrDownloadOwner *owner,struct BrPokeSearchWork *work)
{
    int handleIndex;
    BR_POKESEARCH_ShowBg(work,owner);
    BR_POKESEARCH_DestroyDetail(work,owner);
    BR_POKESEARCH_DestroyText(work,owner);
    BR_POKESEARCH_DestroySearch(work,owner);
    BR_POKESEARCH_DestroyMsgbox(work,owner);
    BR_UTIL_DeleteTask((void *)(work->task));
    BR_POKESEARCH_DestroySearch(work,owner);
    BR_RES_ReleaseSprite((struct BrRes *)(owner->res),6);
    for (handleIndex=0;handleIndex<2;handleIndex++) BR_UTIL_DeleteHandles(work->handles[handleIndex]);
    BMP_OAM_DeleteSys((void *)(work->oamData));
    PRINTSYS_QUE_Delete((struct PrintQueue *)(work->printQue));
    PROCSYS_FreeProcWork(procSys);
    GF_OVERLAY_Unload((sptr)ov112_id);
    return 1;
}

int BR_POKESEARCH_Update(int task,int unused,int unused2,struct BrPokeSearchWork *work)
{
    int handleIndex;
    if (BR_NET_HandleNetError((struct BrNet *)work->owner->net)==2) {
        BR_PROC_SYS_FlushWindows((struct BrProcSysContext *)(((struct BrDownloadOwner *)(*(char * *)&work->owner))->proc));
        return 1;
    }
    BR_UTIL_RunTask(work->task);
    if (BR_UTIL_IsTaskIdle(work->task)) return 1;
    for (handleIndex=0;handleIndex<2;handleIndex++) BR_UTIL_RunHandles(work->handles[handleIndex]);
    PRINTSYS_QUE_Main((struct PrintQueue *)(work->printQue));
    if (*(char * *)&work->detailWin) BR_UTIL_FlushText((u8 *)(*(char * *)&work->detailWin));
    if (work->profileScreen) BR_UTIL_MainProfileScreen(work->profileScreen);
    if (work->window) BR_UTIL_FlushWindow(work->window);
    if (work->scene) MUSICAL_SHOT_SYS_DrawScene((u8 *)(work->scene));
    return 0;
}

void BR_POKESEARCH_OpenTask(struct BrUtilTask *task,int *state,struct BrPokeSearchWork *work)
{
    switch (*state) {
    case 0: if (BR_POKESEARCH_UpdatePrint((struct BrPokeSearch *)(work->search))) { BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,2,3,0); *state=1; } break;
    case 1: if (BR_FADE_GetResult((struct BrFade *)((struct BrDownloadOwner *)work->owner)->fade)) *state=2; break;
    case 2: BR_UTIL_SetTaskStep(task,BR_POKESEARCH_MainTask); break;
    }
}

void BR_POKESEARCH_CloseTask(struct BrUtilTask *task,int *state,struct BrPokeSearchWork *work)
{
    switch (*state) {
    case 0: BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,2,3,1); *state=1; break;
    case 1: if (BR_FADE_GetResult((struct BrFade *)((struct BrDownloadOwner *)work->owner)->fade)) *state=2; break;
    case 2: BR_UTIL_ClearTaskStep(work->task); BR_PROC_SYS_PopEntry((struct BrProcSysContext *)(((struct BrDownloadOwner *)(work->owner))->proc)); break;
    }
}

void BR_POKESEARCH_MainTask(struct BrUtilTask *task, int unused, struct BrPokeSearchWork *work)
{
    unsigned short speciesOut;
    int result;
    BR_POKESEARCH_Main((struct BrPokeSearch *)(work->search));
    result = BR_POKESEARCH_GetResult((struct BrPokeSearch *)(work->search), &speciesOut);
    if (result == 0)
        return;
    if (result == 2) {
        work->speciesId = speciesOut;
        BR_UTIL_SetTaskStep(task, BR_POKESEARCH_EnterListTask);
    } else {
        BR_UTIL_SetTaskStep(task, BR_POKESEARCH_CloseTask);
    }
}

void BR_POKESEARCH_HandleTouch(struct BrUtilTask *task,int unused,struct BrPokeSearchWork *work)
{
    int touchX,touchY;
    if (TOUCHPANEL_GetPointTrg((u32 *)(&touchX),(u32 *)(&touchY))) {
        if (BR_BTN_HitTestWithSound(work->backButton,touchX,touchY)) {
            int point[2];
            point[0]=touchX; point[1]=touchY;
            BR_UTIL_StartEffect((char *)(work->handles[1]),1,(const BrPair *)point);
            BR_UTIL_SetTaskStep(task,BR_POKESEARCH_ExitTask);
        }
        if (BR_POKESEARCH_HitTab((struct BrPokeSearchWork *)work,touchX,touchY)) BR_UTIL_SetTaskStep(task,BR_POKESEARCH_ChangeCategoryTask);
        if (BR_POKESEARCH_HitPrev((struct BrPokeSearchWork *)work,touchX,touchY)) {
            int pageIndex=work->listIndex-1;
            if (pageIndex<0) work->listIndex=work->count-1;
            else work->listIndex=pageIndex;
            BR_UTIL_SetTaskStep(task,BR_POKESEARCH_ChangePageTask);
        }
        if (BR_POKESEARCH_HitNext(work,touchX,touchY)) {
            work->listIndex=work->listIndex+1;
            work->listIndex=(int)work->listIndex % work->count;
            BR_UTIL_SetTaskStep(task,BR_POKESEARCH_ChangePageTask);
        }
    }
}

void BR_POKESEARCH_NetworkTask(struct BrUtilTask *task,unsigned *state,struct BrPokeSearchWork *work)
{
    BrPokesearchCfg request;
    sptr errorCode; int touchX, touchY;
    BrPokesearchPair point;
    switch(*state) {
    case 0:
        MI_CpuFill8(&request,0,8);
        request.heap=work->speciesId;
        work->netRetry=0;
        BR_NET_StartRequest((struct BrNet *)work->owner->net,1,(union BrNetRequest *)(&request));
        *state=1; break;
    case 1:
        work->netRetry=work->netRetry+1;
        if(BR_NET_IsIdle((struct BrNet *)work->owner->net) && work->netRetry>0x60) {
            BR_UTIL_StartEffect((char *)(work->handles[0]), 0, (const BrPair *)((int *)0));
            *state=2;
        }
        break;
    case 2:
        if(!BR_NET_PollErrorMessage((struct BrNet *)work->owner->net,(int *)&errorCode)) {
            if(BR_NET_GetDownloadEntries((struct BrNet *)work->owner->net,(void **)(work->table),5,(int *)&work->count) && work->count) {
                work->listIndex=0;
                BR_UTIL_SetTaskStep(task,BR_POKESEARCH_DownloadDoneTask);
                break;
            }
            *state=3;
            BR_UTIL_SetWindowText(work->window,((struct BrDownloadOwner *)(work->owner))->res,0x14d);
        }else{
            *state=3;
            BR_UTIL_SetWindowText(work->window,((struct BrDownloadOwner *)(work->owner))->res,errorCode);
        }
        break;
    case 3:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg((u32 *)(&touchX),(u32 *)(&touchY));
            point.x=touchX;point.y=touchY;
            BR_UTIL_StartEffect((char *)(work->handles[1]), 1, (const BrPair *)((int *)&point));
            GFL_USE_PlaySeDefaultVolume(0x703);
            BR_UTIL_SetTaskStep(task,BR_POKESEARCH_RefreshTask);
        }
        break;
    }
}

void BR_POKESEARCH_DownloadDoneTask(struct BrUtilTask *task,int *state,struct BrPokeSearchWork *work)
{
    switch (*state) {
    case 0: BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,4,3,1); *state=1; break;
    case 1: if (BR_FADE_GetResult((struct BrFade *)((struct BrDownloadOwner *)work->owner)->fade)) *state=2; break;
    case 2: BR_POKESEARCH_DestroyMsgbox(work,work->owner); BR_POKESEARCH_CreateSidebar(work,work->owner); BR_POKESEARCH_CreateDetail(work,work->owner); *state=3; break;
    case 3: BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,4,3,0); *state=4; break;
    case 4: if (BR_FADE_GetResult((struct BrFade *)((struct BrDownloadOwner *)work->owner)->fade)) *state=5; break;
    case 5: work->sidebarShown=1; BR_UTIL_SetTaskStep(task,BR_POKESEARCH_HandleTouch); break;
    }
}

void BR_POKESEARCH_ExitTask(struct BrUtilTask *task,int *state,struct BrPokeSearchWork *work)
{
    switch(*state) {
    case 0:
        if(work->sidebarShown) BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,4,3,1);
        else BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,2,3,1);
        *state=1; break;
    case 1: if(BR_FADE_GetResult((struct BrFade *)(*(int **)work->owner))) *state=2; break;
    case 2:
        BR_POKESEARCH_DestroyText(work,work->owner);
        BR_POKESEARCH_ShowBg(work,work->owner);
        BR_POKESEARCH_DestroyDetail(work,work->owner);
        BR_POKESEARCH_CreateSearch(work,work->owner);
        *state=3; break;
    case 3:
        if(work->sidebarShown) BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,4,3,0);
        else BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,2,3,0);
        *state=4; break;
    case 4: if(BR_FADE_GetResult((struct BrFade *)(*(int **)work->owner))) *state=5; break;
    case 5: BR_UTIL_SetTaskStep(task,BR_POKESEARCH_MainTask); break;
    }
}

void BR_POKESEARCH_RefreshTask(struct BrUtilTask *task,int *state,struct BrPokeSearchWork *work)
{
    switch(*state) {
    case 0: BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,2,3,1); *state=1; break;
    case 1: if(BR_FADE_GetResult((struct BrFade *)(*(int **)work->owner))) *state=2; break;
    case 2: BR_POKESEARCH_DestroyMsgbox(work,work->owner); BR_POKESEARCH_CreateSearch(work,work->owner); *state=3; break;
    case 3: if(BR_POKESEARCH_UpdatePrint((struct BrPokeSearch *)(work->search))) {BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,2,3,0); *state=4;} break;
    case 4: if(BR_FADE_GetResult((struct BrFade *)(*(int **)work->owner))) *state=5; break;
    case 5: BR_UTIL_SetTaskStep(task,BR_POKESEARCH_MainTask); break;
    }
}

void BR_POKESEARCH_EnterListTask(struct BrUtilTask *task,int *state,struct BrPokeSearchWork *work)
{
    int point[2];
    switch(*state) {
    case 0: BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,2,3,1); *state=1; break;
    case 1: if(BR_FADE_GetResult((struct BrFade *)(*(int **)work->owner))) *state=2; break;
    case 2:
        BR_POKESEARCH_DestroySearch(work,work->owner);
        BR_POKESEARCH_CreateMsgbox(work,work->owner);
        point[0]=0x80;point[1]=0x60;
        BR_UTIL_StartEffect((char *)(work->handles[0]), 4, (const BrPair *)point); *state=3; break;
    case 3: BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,2,3,0); *state=4; break;
    case 4: if(BR_FADE_GetResult((struct BrFade *)(*(int **)work->owner))) *state=5; break;
    case 5: BR_UTIL_SetTaskStep(task,BR_POKESEARCH_NetworkTask); break;
    }
}

/*
 * abi: 021F8BBC/021F8BD6 load r1 for BR_POKESEARCH_DestroyText, retained despite unused callee input.
 */
void BR_POKESEARCH_ChangePageTask(struct BrUtilTask *task,int *state,struct BrPokeSearchWork *work)
{
    switch (*state) {
    case 0:
        if (work->sidebarShown) BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,1,1,1);
        else BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,2,1,1);
        *state=1;break;
    case 1: if (BR_FADE_GetResult((struct BrFade *)(*(int **)work->owner))) *state=2;break;
    case 2:
        if (work->sidebarShown) {
            BR_POKESEARCH_DestroyText(work,work->owner);
            BR_POKESEARCH_ShowBg(work,work->owner);
            BR_POKESEARCH_CreateSidebar(work,work->owner);
        } else {
            BR_POKESEARCH_DestroyText(work,work->owner);
            BR_POKESEARCH_ShowBg(work,work->owner);
            BR_POKESEARCH_CreateText(work,work->owner);
        }
        *state=3;break;
    case 3:
        if (work->sidebarShown) BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,1,1,0);
        else BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,2,1,0);
        *state=4;break;
    case 4: if (BR_FADE_GetResult((struct BrFade *)(*(int **)work->owner))) *state=5;break;
    case 5: BR_UTIL_SetTaskStep(task,BR_POKESEARCH_HandleTouch);break;
    }
}

/*
 * abi: 021F8C9E passes r1 to BR_POKESEARCH_DestroyText despite its unused second input.
 */
void BR_POKESEARCH_ChangeCategoryTask(struct BrUtilTask *task,int *state,struct BrPokeSearchWork *work)
{
    int hasSidebar; void *font; void *msgData; sptr msgId;
    switch (*state) {
    case 0: BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,1,1,1);*state=1;break;
    case 1: if(BR_FADE_GetResult((struct BrFade *)(*(int **)work->owner))) *state=2;break;
    case 2:
        hasSidebar=1;
        if(!work->scene) hasSidebar=0;
        if(hasSidebar) {
            BR_POKESEARCH_ShowBg(work,work->owner);
            BR_POKESEARCH_CreateText(work,work->owner);
        } else {
            BR_POKESEARCH_DestroyText(work,work->owner);
            BR_POKESEARCH_CreateSidebar(work,work->owner);
        }
        font=BR_RES_GetFont((struct BrRes *)(((struct BrDownloadOwner *)(*(char * *)&work->owner))->res));
        msgData=BR_RES_GetMsgData((struct BrRes *)(((struct BrDownloadOwner *)(*(char * *)&work->owner))->res));
        if(hasSidebar) {work->sidebarShown=0;msgId=0x72;}
        else {work->sidebarShown=1;msgId=0x71;}
        BR_UTIL_SetTextFromMessage(*(char * *)&work->detailWin,(void *)msgData,msgId,(void *)font,0x3da0);
        *state=3;break;
    case 3: BR_FADE_Start((void *)((struct BrDownloadOwner *)work->owner)->fade,1,1,0);*state=4;break;
    case 4: if(BR_FADE_GetResult((struct BrFade *)(*(int **)work->owner))) *state=5;break;
    case 5: BR_UTIL_SetTaskStep(task,BR_POKESEARCH_HandleTouch);break;
    }
}

/*
 * Build the scene handle once: flush the three sub-resources and start
 *   0x21F3AF0 on the indexed table entry.
 */
void BR_POKESEARCH_CreateSidebar(struct BrPokeSearchWork *work, struct BrDownloadOwner *owner)
{
    if (work->scene == 0) {
        BR_SIDEBAR_SetVisibleBySpace((struct BrSidebar *)((struct BrDownloadOwner *)owner)->sidebar, 0, 0);
        BR_RES_ApplyBgSet((void *)((struct BrDownloadOwner *)owner)->res, 0);
        BR_RES_ReleaseUiPalette((struct BrRes *)(owner->res), 0);
        BR_GRAPHIC_Begin3d(((struct BrDownloadOwner *)owner)->graphic, work->heapId);
        work->scene = MUSICAL_SHOT_SYS_CreateScene(
            (u8 *)((char *)work->table[work->listIndex] + 0x80),
            work->heapId);
    }
}

void BR_POKESEARCH_ShowBg(struct BrPokeSearchWork *work,struct BrDownloadOwner *owner) { if(work->scene){MUSICAL_SHOT_SYS_DeleteScene((u8 *)(work->scene));work->scene=0;BR_GRAPHIC_End3d(owner->graphic,work->heapId);BR_RES_LoadUiPalette((struct BrRes *)owner->res,0,work->heapId);BR_RES_LoadBgGraphics((void *)(owner->res),0,work->heapId);BR_SIDEBAR_SetVisibleBySpace((struct BrSidebar *)((char *)(owner->sidebar)), 0, 1);} }

void BR_POKESEARCH_CreateDetail(struct BrPokeSearchWork *work,struct BrDownloadOwner *owner)
{
    void *font;
    void *msgData;
    void *graphic;
    BrPokesearchConfig pos;
    BrPokesearchTriple sprite;
    if (!*(int *)&work->detailWin) {
        font=BR_RES_GetFont((struct BrRes *)(owner->res));
        msgData=BR_RES_GetMsgData((struct BrRes *)(owner->res));
        BR_GRAPHIC_GetActorUnit(owner->graphic);
        MI_CpuFill8(&pos,0,8);
        pos.x=0x50;pos.y=0xa8;pos.z=0;pos.a=1;
        graphic=(void *)BR_GRAPHIC_GetActorUnit((struct BrGraphic *)(owner->graphic));
        if (!BR_RES_GetSprite((struct BrRes *)(owner->res),6,(void *)&sprite)) GF_PANIC_Fail((const char *)(""),0,(const char *)(""));
        work->backButton=BR_BTN_CreateFromMessage((void *)(&pos),4,0x60,1,(void *)(graphic),(void *)(work->oamData),(void *)font,(struct MsgBank *)msgData,(void *)&sprite,work->heapId);
        work->detailWin=BR_UTIL_Create(4,8,3,0x10,2,0xe,work->printQue,work->heapId);
        BR_UTIL_SetTextFromMessage(*(char * *)&work->detailWin,(void *)msgData,0x71,(void *)font,0x3da0);
        BR_RES_LoadBgGraphics((void *)(owner->res),0x16,work->heapId);
    }
}

void BR_POKESEARCH_DestroyDetail(struct BrPokeSearchWork *work,struct BrDownloadOwner *owner) { if(work->detailWin){BR_RES_ApplyBgSet((void *)owner->res,22);BR_BTN_DeleteObject(work->backButton);work->backButton=0;BR_UTIL_Delete(work->detailWin);work->detailWin=0;BR_RES_ApplyBgSet((void *)owner->res,22);} }

/*
 * note: 2026-10-04 (D2-13): body is byte-correct. Callee BR_UTIL_CreateProfileScreen (ov186, 0x021FD1C4) is a 1148-byte function in pengy's ov186 split with no witness (its listing extent shows 64 bytes, a wrong label gap); the relocation cannot resolve until it is filed. No change possible here.
 * has a seven-case resource loop, nested branches, stack aggregates and
 * many calls; no mechanical whole-body lever. W29 S24 evidence agrees.
 * tu --suggest-split confirms no viable partition; no speculative leaf C.
 * note 2026-10-05 (D4-14): re-run, still MATCH, only BR_UTIL_CreateProfileScreen (ov186, pengy split) unresolved. No change.
 * note 2026-10-05 (D8-02): re-run, still MATCH. show --region ov186 at 0x021FD1C4 starts with push {r3-r7,lr},
 *   a real 1148-byte function in pengy's ov186 split; outside this lane's write set. No change.
 */
void BR_POKESEARCH_CreateText(struct BrPokeSearchWork *work,struct BrDownloadOwner *owner)
{
    if(work->profileScreen==0) {
        void *font=BR_RES_GetFont((struct BrRes *)(owner->res));
        void *msgData=BR_RES_GetMsgData((struct BrRes *)(owner->res));
        struct Unit *actorUnit=BR_GRAPHIC_GetActorUnit((struct BrGraphic *)(((struct BrDownloadOwner *)owner)->graphic));
        work->profileScreen=BR_UTIL_CreateProfileScreen(work->table[work->listIndex],((struct BrDownloadOwner *)owner)->res,(void *)actorUnit,(void *)(work->printQue),1,work->heapId);
        BR_UTIL_SetTextFromMessage(*(char * *)&work->detailWin,(void *)msgData,0x72,(void *)font,0x3da0);
    }
}

void BR_POKESEARCH_DestroyText(struct BrPokeSearchWork *work, struct BrDownloadOwner *unused)
{
    if (work->profileScreen != 0) {
        BR_UTIL_DeleteProfileScreen(work->profileScreen);
        work->profileScreen = 0;
    }
}

void BR_POKESEARCH_CreateSearch(struct BrPokeSearchWork *work,struct BrDownloadOwner *owner)
{
    if(work->search==0) {
        struct Unit *actorUnit=BR_GRAPHIC_GetActorUnit((struct BrGraphic *)(((struct BrDownloadOwner *)owner)->graphic));
        char *searchScreen;
        if(work->window==0)
            work->window=BR_UTIL_CreateTextWin((void *)((owner->res)),(void *)(work->printQue),work->heapId);
        BR_UTIL_SetWindowText(work->window,((struct BrDownloadOwner *)owner)->res,0x2c);
        searchScreen=(char *)BR_POKESEARCH_Create(ZUKAN_SAVE_GetFromGameData((void *)(((struct BrDownloadOwner *)owner)->zukanSource)),(void *)(owner->res),actorUnit,work->oamData,((struct BrDownloadOwner *)owner)->fade,work->handles[0],(struct BrTapFx *)(work->handles[1]),work->heapId);
        work->search=searchScreen;
        BR_POKESEARCH_Open((struct BrPokeSearch *)searchScreen);
    }
}

void BR_POKESEARCH_DestroySearch(struct BrPokeSearchWork *work,struct BrDownloadOwner *owner) { if(work->search){BR_POKESEARCH_Close(work->search);BR_POKESEARCH_Destroy(work->search);work->search=0;BG_SYS_PushTile(4);if(work->window){BR_UTIL_DeleteTextWin(work->window,owner->res);work->window=0;}} }

void BR_POKESEARCH_CreateMsgbox(struct BrPokeSearchWork *work, struct BrDownloadOwner *owner) { if(!work->window)work->window=BR_UTIL_CreateTextWin((owner->res),(void *)(work->printQue),work->heapId);BR_UTIL_SetWindowText(work->window,((struct BrDownloadOwner *)owner)->res,0x146); }

void BR_POKESEARCH_DestroyMsgbox(struct BrPokeSearchWork *work, struct BrDownloadOwner *owner)
{
    if (work->window != 0) {
        BR_UTIL_DeleteTextWin((void *)(work->window), owner->res);
        work->window = 0;
    }
}

/*
 * Range-gate the pair then hand them to 0x21FD860 as a two-word record.
 */
int BR_POKESEARCH_HitTab(struct BrPokeSearchWork *work, int touchX, int touchY)
{
    int inside = ((unsigned)(touchX - 0x40) <= 0x78) & ((unsigned)(touchY - 0x10) <= 0x20);
    if (inside) {
        int point[2];
        point[0] = touchX;
        point[1] = touchY;
        BR_UTIL_StartEffect((char *)work->handles[1], 1, (const BrPair *)point);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return inside;
}

int BR_POKESEARCH_HitPrev(struct BrPokeSearchWork *work, int touchX, int touchY)
{
    int ok = ((unsigned)(touchX - 0x18) <= 0x28) & ((unsigned)(touchY - 0x40) <= 0x28);
    if (ok) {
        int buf[2];
        buf[0] = touchX;
        buf[1] = touchY;
        BR_UTIL_StartEffect((char *)work->handles[1], 1, (const BrPair *)buf);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}

int BR_POKESEARCH_HitNext(struct BrPokeSearchWork *p,unsigned x,unsigned y)
{
    int inside=((unsigned)(x-0xb8)<=0x28)&((unsigned)(y-0x40)<=0x28);
    if(inside) {
        int pair[2];
        pair[0]=x;
        pair[1]=y;
        BR_UTIL_StartEffect((char *)p->handles[1],1,(const BrPair *)pair);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return inside;
}
