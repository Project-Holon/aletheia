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
#include "br_download.h"

struct Proc;
struct GameData;
struct PrintQueue;
struct Proc;
#include "../types.h"


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
extern char ov112_id[];

int BR_DOWNLOAD_Create(void *obj,int b,struct BrDownloadOwner *q)
{
    struct BrDownloadWork *p;
    void *v;
    int i;
    GF_OVERLAY_Load((sptr)ov112_id);
    p=PROCSYS_AllocProcWork(obj,sizeof(struct BrDownloadWork),BR_PROC_SYS_GetSlotId(q->proc));
    MI_CpuFill8(p,0,sizeof(struct BrDownloadWork));
    p->heapId=BR_PROC_SYS_GetSlotId(q->proc);
    p->owner=(struct BrDownloadOwner *)q;
    p->printQue=PRINTSYS_QUE_Create((unsigned int)p->heapId);
    v=(void *)BR_GRAPHIC_GetActorUnit((struct BrGraphic *)(q->graphic));
    p->oamSys=BMP_OAM_CreateSys(p->heapId,v);
    for (i=0;i<2;i++) p->handles[i]=BR_UTIL_CreateHandles((void *)(v),q->res,i,p->heapId);
    p->saveData=MUSICAL_SAVE_NoOp((struct MusicalSave *)(MUSICAL_SAVE_GetFromSave((struct SaveControl *)((void *)GAME_DATA_GetSaveControl((struct GameData *)q->zukanSource)))));
    BR_DOWNLOAD_Begin3d(p,q);
    BR_DOWNLOAD_CreateButtons(p,q);
    p->task=BR_UTIL_CreateTask(p,BR_DOWNLOAD_StepFadeIn,p->heapId);
    return 1;
}

int BR_DOWNLOAD_Delete(struct Proc *obj,int b,struct BrDownloadOwner *q,struct BrDownloadWork *p)
{
    int i;
    BR_UTIL_DeleteTask((void *)(p->task));
    BR_DOWNLOAD_ResetSlots(p,q);
    BR_DOWNLOAD_End3d(p,q);
    for (i=0;i<2;i++) BR_UTIL_DeleteHandles((char *)p->handles[i]);
    if (p->textWin) {
        BR_UTIL_DeleteTextWin(p->textWin,q->res);
        p->textWin=0;
    }
    BMP_OAM_DeleteSys((void *)(p->oamSys));
    PRINTSYS_QUE_Delete((struct PrintQueue *)(p->printQue));
    PROCSYS_FreeProcWork(obj);
    GF_OVERLAY_Unload((sptr)ov112_id);
    return 1;
}

int BR_DOWNLOAD_Main(int a,int b,int c,struct BrDownloadWork *p)
{
    int i;
    if (BR_NET_HandleNetError((struct BrNet *)(char *)(p->owner)->net)==2) {
        BR_PROC_SYS_FlushWindows((struct BrProcSysContext *)((char *)(p->owner)->proc));
        return 1;
    }
    BR_UTIL_RunTask(p->task);
    if (BR_UTIL_IsTaskIdle(p->task)) return 1;
    for (i=0;i<2;i++) BR_UTIL_RunHandles((char *)p->handles[i]);
    PRINTSYS_QUE_Main((struct PrintQueue *)p->printQue);
    if (p->textWin) BR_UTIL_FlushWindow(p->textWin);
    if (p->scene) MUSICAL_SHOT_SYS_DrawScene((u8 *)p->scene);
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
void BR_DOWNLOAD_StepFadeIn(struct BrUtilTask *a, int *state, struct BrDownloadWork *p)
{
    switch (*state) {
    case 0:
        BR_FADE_Start((void *)(p->owner->fade), 4, 3, 0);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult((struct BrFade *)(p->owner->fade)))
            *state = 2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(a, BR_DOWNLOAD_HandleTouch);
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
void BR_DOWNLOAD_StepClose(struct BrUtilTask *a, int *state, struct BrDownloadWork *p)
{
    switch (*state) {
    case 0:
        BR_FADE_Start((void *)(p->owner->fade), 4, 3, 1);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult((struct BrFade *)(p->owner->fade)))
            *state = 2;
        break;
    case 2:
        BR_UTIL_ClearTaskStep(p->task);
        BR_PROC_SYS_PopEntry((struct BrProcSysContext *)(p->owner)->proc);
        break;
    }
}

void BR_DOWNLOAD_HandleTouch(struct BrUtilTask *a,int b,struct BrDownloadWork *p)
{
    int x,y;
    if (TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))) {
        if (BR_BTN_HitTestWithSound(p->buttons[0],x,y)) {
            int pair[2];
            pair[0]=x; pair[1]=y;
            BR_UTIL_StartEffect((char *)(p->handles[1]),1,(const BrPair *)pair);
            (p->owner)->downloadMode=0;
            BR_UTIL_SetTaskStep(a, BR_DOWNLOAD_StepClose);
        }
        if (BR_BTN_HitTestWithSound(p->buttons[1],x,y)) {
            int pair[2];
            pair[0]=x; pair[1]=y;
            BR_UTIL_StartEffect((char *)(p->handles[1]),1,(const BrPair *)pair);
            (p->owner)->downloadMode=1;
            BR_UTIL_SetTaskStep(a, BR_DOWNLOAD_DownloadTask);
        }
    }
}

void BR_DOWNLOAD_DownloadTask(struct BrUtilTask *task,unsigned *state,struct BrDownloadWork *p)
{
    BrDownloadPair initial;
    union BrNetRequest cfg;
    sptr out; int x, y;
    BrDownloadPair pair;
    switch(*state) {
    case 0:BR_FADE_Start((void *)(p->owner->fade),4,3,1);*state=1;break;
    case 1:if(BR_FADE_GetResult((struct BrFade *)(p->owner->fade))) *state=2;break;
    case 2:
        BR_DOWNLOAD_ResetSlots(p,p->owner);
        BR_DOWNLOAD_End3d(p,p->owner);
        p->textWin=BR_UTIL_CreateTextWin((void *)((p->owner)->res),(void *)p->printQue,p->heapId);
        BR_UTIL_SetWindowText((char *)p->textWin,(p->owner)->res,0x145);
        initial.x=0x80;initial.y=0x60;
        BR_UTIL_StartEffect((char *)(p->handles[0]), 4, (const BrPair *)((int *)&initial));
        *state=3;break;
    case 3:BR_FADE_Start((void *)(p->owner->fade),4,3,0);*state=4;break;
    case 4:if(BR_FADE_GetResult((struct BrFade *)(p->owner->fade))) *state=5;break;
    case 5:
        MI_CpuFill8(&cfg,0,8);
        cfg.payload=(const GdsPayloadBlock *)p->saveData;
        BR_NET_StartRequest((struct BrNet *)(char *)(p->owner)->net,0,&cfg);
        p->counter=0;
        *state=6;break;
    case 6:
        p->counter=p->counter+1;
        if(BR_NET_IsIdle((struct BrNet *)(char *)(p->owner)->net) && p->counter>0x60) {
            BR_UTIL_StartEffect((char *)(p->handles[0]), 0, (const BrPair *)((int *)0));*state=7;
        }break;
    case 7:
        if(!BR_NET_PollErrorMessage((struct BrNet *)(char *)(p->owner)->net,&out)) *state=9;
        else {BR_UTIL_SetWindowText((char *)p->textWin,(p->owner)->res,out);*state=8;}
        break;
    case 8:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y));pair.x=x;pair.y=y;
            BR_UTIL_StartEffect((char *)(p->handles[1]), 1, (const BrPair *)((int *)&pair));
            GFL_USE_PlaySeDefaultVolume(0x703);*state=9;
        }break;
    case 9:BR_FADE_Start((void *)(p->owner->fade),2,3,1);*state=10;break;
    case 10:if(BR_FADE_GetResult((struct BrFade *)(p->owner->fade))) *state=11;break;
    case 11:BR_UTIL_ClearTaskStep(task);BR_PROC_SYS_PopEntry((p->owner)->proc);break;
    }
}

void BR_DOWNLOAD_Begin3d(struct BrDownloadWork *p, struct BrDownloadOwner *q)
{
    if (p->scene != 0)
        return;
    BR_SIDEBAR_SetVisibleBySpace((struct BrSidebar *)(char *)q->sidebar, 0, 0);
    BR_RES_ApplyBgSet((void *)(q->res), 0);
    BR_RES_ReleaseUiPalette((struct BrRes *)((int *)q->res), 0);
    BR_GRAPHIC_Begin3d((void *)q->graphic, p->heapId);
    p->scene = MUSICAL_SHOT_SYS_CreateScene((u8 *)p->saveData, p->heapId);
}

void BR_DOWNLOAD_End3d(struct BrDownloadWork *p, struct BrDownloadOwner *q)
{
    if (p->scene == 0)
        return;
    MUSICAL_SHOT_SYS_DeleteScene(p->scene);
    p->scene = 0;
    BR_GRAPHIC_End3d((void *)q->graphic, p->heapId);
    BR_RES_LoadUiPalette((struct BrRes *)((char *)(q->res)), 0, p->heapId);
    BR_RES_LoadBgGraphics((void *)(q->res), 0, p->heapId);
    BR_SIDEBAR_SetVisibleBySpace((struct BrSidebar *)(char *)q->sidebar, 0, 1);
}

/*
 * tail: 021F89CE..021F89D0 is two zero alignment bytes before matched021F89D0.
 * lever: first types search extracted full-word temporaries and took kind's address;
 * its volatile parameter was removed, and the clean spelling independently matched.
 */
void BR_DOWNLOAD_CreateButtons(struct BrDownloadWork *p, struct BrDownloadOwner *q)
{
  BrDownloadConfig cfg;
  int resources[3];
  void *actorUnit;
  void *font;
  struct MsgBank *msgData;
  int i;
  int kind;
  void *oamHandle;
  char **resHandlePtr;
  (void) (&kind);
  if (p->buttons[0])
    return;
  resHandlePtr = (char **) &q->res;
  BR_RES_LoadBgGraphics((void *)(*resHandlePtr), 23, p->heapId);
  BR_RES_LoadSprite((struct BrRes *)(*resHandlePtr), 6, p->heapId);
  font = (void *)BR_RES_GetFont((struct BrRes *)(*resHandlePtr));
  msgData = (struct MsgBank *)BR_RES_GetMsgData((struct BrRes *)(*resHandlePtr));
  MI_CpuFill8(&cfg, 0, 8);
  cfg.y = 168;
  cfg.flag = 1;
  actorUnit = (void *)BR_GRAPHIC_GetActorUnit((struct BrGraphic *)(q->graphic));
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
    oamHandle = p->oamSys;
    p->buttons[i] = BR_BTN_CreateFromMessage((void *)&cfg, kind, 96, 1, actorUnit, oamHandle, font, msgData, (void *)resources, p->heapId);
  }
}

void BR_DOWNLOAD_ResetSlots(struct BrDownloadWork *work, struct BrDownloadOwner *p)
{
    int i;
    if (work->buttons[0] != 0) {
        BR_RES_ReleaseSprite(p->res, 6);
        BR_RES_ApplyBgSet(p->res, 0x17);
        for (i = 0; i < 2; i++) {
            BR_BTN_DeleteObject(work->buttons[i]);
            work->buttons[i] = 0;
        }
    }
}
