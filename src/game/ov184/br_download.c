/*
 * file:     br_download.c
 * unit:     yes
 * function: BR_DOWNLOAD_Create, BR_DOWNLOAD_Delete, BR_DOWNLOAD_Main, BR_DOWNLOAD_StepFadeIn, BR_DOWNLOAD_StepClose, BR_DOWNLOAD_HandleTouch, BR_DOWNLOAD_DownloadTask, BR_DOWNLOAD_Begin3d, BR_DOWNLOAD_End3d, BR_DOWNLOAD_CreateButtons, BR_DOWNLOAD_ResetSlots
 * address:  0x021F8480
 * region:   ov184
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * The Obj views are replaced by struct BrDownloadWork (the 0x34 task work) and
 * struct BrDownloadOwner (the screen object at work+0x30) in
 * br_download_types.h.
 *
 * The table slot must be spelled `a[i + 1]` (indexed form).  The byte-offset
 * spelling `*(int *)((char *)a + 4 + i * 4)` folds `a + 4` into a base
 * register and rotates the loop's registers; the subscript keeps the table
 * pointer in r6, i in r4 and 0 in r7, and recomputes `a + i*4 + 4`.
 * If the lead handle is live, flush the two sub-slots and clear them.
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
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MUSICAL_SAVE_GetFromSave 0x0200A5F8 thumb
 *   MUSICAL_SAVE_NoOp 0x0200A640 thumb
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   BR_UTIL_DeleteTask 0x021FD714 thumb ov186
 *   BR_UTIL_DeleteHandles 0x021FD820 thumb ov186
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
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
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 *   MUSICAL_SHOT_SYS_DrawScene 0x021F3C50 thumb ov112
 *   BR_FADE_Start   0x021FE784  thumb
 *   BR_FADE_GetResult   0x021FE7B0  thumb
 *   BR_UTIL_SetTaskStep   0x021FD73C  thumb
 *   BR_UTIL_ClearTaskStep   0x021FD744  thumb
 *   BR_PROC_SYS_PopEntry   0x021F9BA0  thumb
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BR_BTN_HitTestWithSound 0x021FB4B4 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   BR_NET_StartRequest 0x021FF54C thumb ov186
 *   BR_NET_IsIdle 0x021FF648 thumb ov186
 *   BR_NET_PollErrorMessage 0x021FF72C thumb ov186
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BR_SIDEBAR_SetVisibleBySpace  0x021FEEC0  thumb  ov186
 *   BR_RES_ApplyBgSet  0x021FBDA4  thumb  ov186
 *   BR_RES_ReleaseUiPalette  0x021FC1F8  thumb  ov186
 *   BR_GRAPHIC_Begin3d  0x021FC610  thumb  ov186
 *   MUSICAL_SHOT_SYS_CreateScene  0x021F3AF0  thumb  ov112
 *   MUSICAL_SHOT_SYS_DeleteScene  0x021F3BF0  thumb  ov112
 *   BR_GRAPHIC_End3d  0x021FC640  thumb  ov186
 *   BR_RES_LoadUiPalette  0x021FC148  thumb  ov186
 *   BR_RES_LoadBgGraphics  0x021FB964  thumb  ov186
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_BTN_CreateFromMessage 0x021FB378 thumb ov186
 *   BR_RES_ReleaseSprite   0x021FC0C8  thumb
 *   BR_BTN_DeleteObject   0x021FB494  thumb
 */
#include "br_download_types.h"

struct Proc;
struct GameData;
struct PrintQueue;
struct Proc;
#include "../types.h"

typedef struct BrDownloadCfg {int a,b;} BrDownloadCfg;

typedef struct BrDownloadPair {int x,y;} BrDownloadPair;

typedef struct
{
  u16 x;
  u16 y;
  u16 index;
  unsigned char flag;
  unsigned char pad;
} BrDownloadConfig;

#include "../arm9/gf_overlay.h"
#include "../ov186/br_proc_sys.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "../arm9/printsys.h"
#include "../ov186/br_graphic.h"
#include "../arm9/bmp_oam.h"
#include "../ov186/br_util.h"
#include "../arm9/musical_save.h"
#include "../ov112/mus_shot_photo.h"
#include "../ov186/br_fade.h"
#include "../arm9/touchpanel.h"
#include "../ov186/br_btn.h"
#include "../arm9/gfl_use.h"
#include "../arm9/game_data.h"
#include "../ov186/br_net.h"
#include "../ov186/br_sidebar.h"
#include "../ov186/br_res.h"
int BR_DOWNLOAD_Create(void *obj,int b,char *q);
int BR_DOWNLOAD_Delete(int obj,int b,char *q,char *p);
int BR_DOWNLOAD_Main(int a,int b,int c,char *p);
void BR_DOWNLOAD_StepFadeIn(int a, int *state, char *p);
void BR_DOWNLOAD_StepClose(int a, int *state, char *p);
void BR_DOWNLOAD_HandleTouch(int a,int b,char *p);
void BR_DOWNLOAD_DownloadTask(int *task,unsigned *state,char *p);
void BR_DOWNLOAD_Begin3d(char *p, char *q);
void BR_DOWNLOAD_End3d(char *p, char *q);
void BR_DOWNLOAD_CreateButtons(char *p, const char *q);
void BR_DOWNLOAD_ResetSlots(int *a, char *p);
extern char ov112_id[];

int BR_DOWNLOAD_Create(void *obj,int b,char *q)
{
    char *p;
    void *v;
    int i;
    GF_OVERLAY_Load((int)ov112_id);
    p=PROCSYS_AllocProcWork(obj,0x34,BR_PROC_SYS_GetSlotId(((struct BrDownloadOwner *)q)->proc.proc));
    MI_CpuFill8(p,0,0x34);
    ((struct BrDownloadWork *)p)->heapId=BR_PROC_SYS_GetSlotId((struct BrProcQuery *)(((struct BrDownloadOwner *)q)->proc.proc));
    ((struct BrDownloadWork *)p)->owner.owner=q;
    ((struct BrDownloadWork *)p)->printQue.printQue=(unsigned int)PRINTSYS_QUE_Create((unsigned int)((struct BrDownloadWork *)p)->heapId);
    v=(void *)BR_GRAPHIC_GetActorUnit((struct BrGraphic *)(((struct BrDownloadOwner *)q)->graphic.graphic));
    ((struct BrDownloadWork *)p)->oamSys.oamSys=BMP_OAM_CreateSys(((struct BrDownloadWork *)p)->heapId,v);
    for (i=0;i<2;i++) ((struct BrDownloadWork *)p)->handles[i]=BR_UTIL_CreateHandles((void *)((unsigned int)v),(char *)(((struct BrDownloadOwner *)q)->res.res),i,((struct BrDownloadWork *)p)->heapId);
    ((struct BrDownloadWork *)p)->saveData.saveValue=(int)MUSICAL_SAVE_NoOp((struct MusicalSave *)((int)MUSICAL_SAVE_GetFromSave((struct SaveControl *)((void *)GAME_DATA_GetSaveControl((struct GameData *)((struct BrDownloadOwner *)q)->zukanSource)))));
    BR_DOWNLOAD_Begin3d(p,q);
    BR_DOWNLOAD_CreateButtons(p,q);
    ((struct BrDownloadWork *)p)->task.task=BR_UTIL_CreateTask((int)p,(int)BR_DOWNLOAD_StepFadeIn,((struct BrDownloadWork *)p)->heapId);
    return 1;
}

int BR_DOWNLOAD_Delete(int obj,int b,char *q,char *p)
{
    int i;
    BR_UTIL_DeleteTask((void *)(((struct BrDownloadWork *)p)->task.task));
    BR_DOWNLOAD_ResetSlots((int *)p,q);
    BR_DOWNLOAD_End3d(p,q);
    for (i=0;i<2;i++) BR_UTIL_DeleteHandles((char *)((struct BrDownloadWork *)p)->handles[i]);
    if (((struct BrDownloadWork *)p)->textWin) {
        BR_UTIL_DeleteTextWin(((struct BrDownloadWork *)p)->textWin,((struct BrDownloadOwner *)q)->res.resHandle);
        ((struct BrDownloadWork *)p)->textWin=0;
    }
    BMP_OAM_DeleteSys((void *)(((struct BrDownloadWork *)p)->oamSys.oamSys));
    PRINTSYS_QUE_Delete((struct PrintQueue *)(((struct BrDownloadWork *)p)->printQue.printQue));
    PROCSYS_FreeProcWork((struct Proc *)obj);
    GF_OVERLAY_Unload((int)ov112_id);
    return 1;
}

int BR_DOWNLOAD_Main(int a,int b,int c,char *p)
{
    int i;
    if (BR_NET_HandleNetError((struct BrNet *)(char *)((struct BrDownloadOwner *)((struct BrDownloadWork *)p)->owner.owner)->net)==2) {
        BR_PROC_SYS_FlushWindows((struct Context *)((char *)((struct BrDownloadOwner *)((struct BrDownloadWork *)p)->owner.owner)->proc.proc));
        return 1;
    }
    BR_UTIL_RunTask((u8 *)((struct BrDownloadWork *)p)->task.task);
    if (BR_UTIL_IsTaskIdle((int *)((struct BrDownloadWork *)p)->task.task)) return 1;
    for (i=0;i<2;i++) BR_UTIL_RunHandles((char *)((struct BrDownloadWork *)p)->handles[i]);
    PRINTSYS_QUE_Main((struct PrintQueue *)((struct BrDownloadWork *)p)->printQue.printQue);
    if (((struct BrDownloadWork *)p)->textWin) BR_UTIL_FlushWindow(((struct BrDownloadWork *)p)->textWin);
    if (((struct BrDownloadWork *)p)->scene.scene) MUSICAL_SHOT_SYS_DrawScene((u8 *)((struct BrDownloadWork *)p)->scene.scene);
    return 0;
}

/*
 *   wildcarded because that address lies outside ov184's own 0x5A0-byte
 *   region and no listing labels it -- the only branch image-wide is the
 *   one inside this range.
 *
 * Three-state step over the object at *(p+0x30): submit on 0, poll on 1,
 *   finish through 0x21FD73C on 2.
 */
void BR_DOWNLOAD_StepFadeIn(int a, int *state, char *p)
{
    switch (*state) {
    case 0:
        BR_FADE_Start((void *)(*(int *)((struct BrDownloadWork *)p)->owner.ownerHandle), 4, 3, 0);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult((struct BrFade *)(*(int *)((struct BrDownloadWork *)p)->owner.ownerHandle)))
            *state = 2;
        break;
    case 2:
        BR_UTIL_SetTaskStep((int *)a, (int)BR_DOWNLOAD_HandleTouch);
        break;
    }
}

/*
 *   outside ov184's 0x5A0-byte region and no listing labels them, so the
 *   two calls stay wildcarded.
 *
 * Three-state step over the object at *(p+0x30): submit on 0, poll on 1,
 *   release the two child handles on 2.
 */
void BR_DOWNLOAD_StepClose(int a, int *state, char *p)
{
    switch (*state) {
    case 0:
        BR_FADE_Start((void *)(*(int *)((struct BrDownloadWork *)p)->owner.ownerHandle), 4, 3, 1);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult((struct BrFade *)(*(int *)((struct BrDownloadWork *)p)->owner.ownerHandle)))
            *state = 2;
        break;
    case 2:
        BR_UTIL_ClearTaskStep((int *)(((struct BrDownloadWork *)p)->task.taskHandle));
        BR_PROC_SYS_PopEntry((unsigned *)(*(int *)(((struct BrDownloadWork *)p)->owner.ownerHandle + 0x10)));
        break;
    }
}

void BR_DOWNLOAD_HandleTouch(int a,int b,char *p)
{
    int x,y;
    if (TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))) {
        if (BR_BTN_HitTestWithSound((unsigned int *)((struct BrDownloadWork *)p)->buttons[0],x,y)) {
            int pair[2];
            pair[0]=x; pair[1]=y;
            BR_UTIL_StartEffect((char *)((int)((struct BrDownloadWork *)p)->handles[1]),1,(const BrPair *)pair);
            ((struct BrDownloadOwner *)((struct BrDownloadWork *)p)->owner.owner)->downloadMode=0;
            BR_UTIL_SetTaskStep((int *)((int)((int *)a)), (int)BR_DOWNLOAD_StepClose);
        }
        if (BR_BTN_HitTestWithSound((unsigned int *)((struct BrDownloadWork *)p)->buttons[1],x,y)) {
            int pair[2];
            pair[0]=x; pair[1]=y;
            BR_UTIL_StartEffect((char *)((int)((struct BrDownloadWork *)p)->handles[1]),1,(const BrPair *)pair);
            ((struct BrDownloadOwner *)((struct BrDownloadWork *)p)->owner.owner)->downloadMode=1;
            BR_UTIL_SetTaskStep((int *)((int)((int *)a)), (int)BR_DOWNLOAD_DownloadTask);
        }
    }
}

void BR_DOWNLOAD_DownloadTask(int *task,unsigned *state,char *p)
{
    BrDownloadPair initial;
    BrDownloadCfg cfg;
    int out,x,y;
    BrDownloadPair pair;
    switch(*state) {
    case 0:BR_FADE_Start((void *)(*(int *)((struct BrDownloadWork *)p)->owner.owner),4,3,1);*state=1;break;
    case 1:if(BR_FADE_GetResult((struct BrFade *)(*(int *)((struct BrDownloadWork *)p)->owner.owner))) *state=2;break;
    case 2:
        BR_DOWNLOAD_ResetSlots((int *)p,(char *)((struct BrDownloadWork *)p)->owner.owner);
        BR_DOWNLOAD_End3d(p,(char *)((struct BrDownloadWork *)p)->owner.owner);
        ((struct BrDownloadWork *)p)->textWin=BR_UTIL_CreateTextWin((void *)(((struct BrDownloadOwner *)((struct BrDownloadWork *)p)->owner.owner)->res.resHandle),(void *)((struct BrDownloadWork *)p)->printQue.printQue,((struct BrDownloadWork *)p)->heapId);
        BR_UTIL_SetWindowText((char *)((struct BrDownloadWork *)p)->textWin,(char *)(((struct BrDownloadOwner *)((struct BrDownloadWork *)p)->owner.owner)->res.res),(void *)0x145);
        initial.x=0x80;initial.y=0x60;
        BR_UTIL_StartEffect((char *)((int)((struct BrDownloadWork *)p)->handles[0]), 4, (const BrPair *)((int *)&initial));
        *state=3;break;
    case 3:BR_FADE_Start((void *)(*(int *)((struct BrDownloadWork *)p)->owner.owner),4,3,0);*state=4;break;
    case 4:if(BR_FADE_GetResult((struct BrFade *)(*(int *)((struct BrDownloadWork *)p)->owner.owner))) *state=5;break;
    case 5:
        MI_CpuFill8(&cfg,0,8);
        cfg.a=((struct BrDownloadWork *)p)->saveData.saveValue;
        BR_NET_StartRequest((struct BrNet *)(char *)((struct BrDownloadOwner *)((struct BrDownloadWork *)p)->owner.owner)->net,0,(const union BrNetRequest *)(const int *)(&cfg));
        ((struct BrDownloadWork *)p)->counter=0;
        *state=6;break;
    case 6:
        ((struct BrDownloadWork *)p)->counter=((struct BrDownloadWork *)p)->counter+1;
        if(BR_NET_IsIdle((struct BrNet *)(char *)((struct BrDownloadOwner *)((struct BrDownloadWork *)p)->owner.owner)->net) && ((struct BrDownloadWork *)p)->counter>0x60) {
            BR_UTIL_StartEffect((char *)((int)((struct BrDownloadWork *)p)->handles[0]), 0, (const BrPair *)((int *)0));*state=7;
        }break;
    case 7:
        if(!BR_NET_PollErrorMessage((struct BrNet *)(char *)((struct BrDownloadOwner *)((struct BrDownloadWork *)p)->owner.owner)->net,&out)) *state=9;
        else {BR_UTIL_SetWindowText((char *)((struct BrDownloadWork *)p)->textWin,(char *)(((struct BrDownloadOwner *)((struct BrDownloadWork *)p)->owner.owner)->res.res),(void *)out);*state=8;}
        break;
    case 8:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y));pair.x=x;pair.y=y;
            BR_UTIL_StartEffect((char *)((int)((struct BrDownloadWork *)p)->handles[1]), 1, (const BrPair *)((int *)&pair));
            GFL_USE_PlaySeDefaultVolume(0x703);*state=9;
        }break;
    case 9:BR_FADE_Start((void *)(*(int *)((struct BrDownloadWork *)p)->owner.owner),2,3,1);*state=10;break;
    case 10:if(BR_FADE_GetResult((struct BrFade *)(*(int *)((struct BrDownloadWork *)p)->owner.owner))) *state=11;break;
    case 11:BR_UTIL_ClearTaskStep((int *)((int)task));BR_PROC_SYS_PopEntry((unsigned *)((int)((unsigned int *)((struct BrDownloadOwner *)((struct BrDownloadWork *)p)->owner.owner)->proc.procHandle)));break;
    }
}

void BR_DOWNLOAD_Begin3d(char *p, char *q)
{
    if (((struct BrDownloadWork *)p)->scene.sceneHandle != 0)
        return;
    BR_SIDEBAR_SetVisibleBySpace((struct BrSidebar *)(char *)((struct BrDownloadOwner *)q)->sidebar, 0, 0);
    BR_RES_ApplyBgSet((void *)(((struct BrDownloadOwner *)q)->res.resHandle), 0);
    BR_RES_ReleaseUiPalette((struct BrRes *)((int *)((struct BrDownloadOwner *)q)->res.resHandle), 0);
    BR_GRAPHIC_Begin3d((void *)((struct BrDownloadOwner *)q)->graphic.graphicHandle, ((struct BrDownloadWork *)p)->heapId);
    ((struct BrDownloadWork *)p)->scene.sceneHandle = (unsigned int)MUSICAL_SHOT_SYS_CreateScene((u8 *)((struct BrDownloadWork *)p)->saveData.saveData, ((struct BrDownloadWork *)p)->heapId);
}

void BR_DOWNLOAD_End3d(char *p, char *q)
{
    if (*(u32 *)&((struct BrDownloadWork *)p)->scene.scene == 0)
        return;
    MUSICAL_SHOT_SYS_DeleteScene(((struct BrDownloadWork *)p)->scene.scene);
    *(u32 *)&((struct BrDownloadWork *)p)->scene.scene = 0;
    BR_GRAPHIC_End3d((void *)((struct BrDownloadOwner *)q)->graphic.graphicHandle, ((struct BrDownloadWork *)p)->heapId);
    BR_RES_LoadUiPalette((struct BrRes *)((char *)(*(u32 *)&((struct BrDownloadOwner *)q)->res.res)), 0, ((struct BrDownloadWork *)p)->heapId);
    BR_RES_LoadBgGraphics((void *)(*(u32 *)&((struct BrDownloadOwner *)q)->res.res), 0, ((struct BrDownloadWork *)p)->heapId);
    BR_SIDEBAR_SetVisibleBySpace((struct BrSidebar *)(char *)((struct BrDownloadOwner *)q)->sidebar, 0, 1);
}

/*
 * tail: 021F89CE..021F89D0 is two zero alignment bytes before matched021F89D0.
 * lever: first types search extracted full-word temporaries and took kind's address;
 * its volatile parameter was removed, and the clean spelling independently matched.
 */
void BR_DOWNLOAD_CreateButtons(char *p, const char *q)
{
  BrDownloadConfig cfg;
  int resources[3];
  void *actorUnit;
  void *font;
  struct MsgBank *msgData;
  int i;
  int kind;
  int oamHandle;
  char **resHandlePtr;
  (void) (&kind);
  if (((struct BrDownloadWork *)p)->buttons[0])
    return;
  resHandlePtr = (char **) &((struct BrDownloadOwner *)q)->res.res;
  BR_RES_LoadBgGraphics((void *)(*(u32 *) resHandlePtr), 23, ((struct BrDownloadWork *)p)->heapId);
  BR_RES_LoadSprite((struct BrRes *)(*resHandlePtr), 6, ((struct BrDownloadWork *)p)->heapId);
  font = (void *)BR_RES_GetFont((struct BrRes *)(*resHandlePtr));
  msgData = (struct MsgBank *)BR_RES_GetMsgData((struct BrRes *)(*resHandlePtr));
  MI_CpuFill8(&cfg, 0, 8);
  cfg.y = 168;
  cfg.flag = 1;
  actorUnit = (void *)BR_GRAPHIC_GetActorUnit((struct BrGraphic *)(((struct BrDownloadOwner *)q)->graphic.graphic));
  BR_RES_GetSprite((struct BrRes *)(*resHandlePtr), 6, (void *)resources);
  for (i = 0; i < 2; i++)
  {
    if (i == 0)
    {
      kind = 4;
      cfg.x = 32;
      cfg.index = 0;
    }
    else
    {
      kind = 43;
      cfg.x = 128;
      cfg.index = 4;
    }
    oamHandle = ((struct BrDownloadWork *)p)->oamSys.oamHandle;
    ((struct BrDownloadWork *)p)->buttons[i] = (int)BR_BTN_CreateFromMessage((void *)&cfg, kind, 96, 1, actorUnit, (void *)oamHandle, font, msgData, (void *)resources, ((struct BrDownloadWork *)p)->heapId);
  }
}

void BR_DOWNLOAD_ResetSlots(int *slots, char *p)
{
    int i;
    if (slots[1] != 0) {
        BR_RES_ReleaseSprite((struct BrRes *)(((struct BrDownloadOwner *)p)->res.resHandle), 6);
        BR_RES_ApplyBgSet((void *)(((struct BrDownloadOwner *)p)->res.resHandle), 0x17);
        for (i = 0; i < 2; i++) {
            BR_BTN_DeleteObject((char *)(slots[i + 1]));
            slots[i + 1] = 0;
        }
    }
}
