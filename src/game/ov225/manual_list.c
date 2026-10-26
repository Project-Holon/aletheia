/*
 * file:     manual_list.c
 * unit:     yes
 * function: MANUAL_COMMON_CreateListWork, MANUAL_COMMON_DeleteListWork, MANUAL_COMMON_UpdateListWork, MANUAL_COMMON_ListWorkTaskNoop, MANUAL_COMMON_LoadListWorkAssets, MANUAL_COMMON_CreateListWorkMenu, MANUAL_COMMON_SetListWorkBgMode, MANUAL_COMMON_DeleteListWorkAssets, MANUAL_COMMON_DeleteListWorkMenu, MANUAL_COMMON_UpdateListWorkInput, MANUAL_COMMON_UpdateListWorkDrag, MANUAL_COMMON_BuildListRects, MANUAL_COMMON_GetCursorIndex, MANUAL_COMMON_GetLastVisible, MANUAL_COMMON_GetVisibleCount, MANUAL_COMMON_GetScrollTop, MANUAL_COMMON_RebuildListWindows, MANUAL_COMMON_HitToIndex, MANUAL_COMMON_IndexToY
 * address:  0x021BA65C
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from manual_common.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   MANUAL_GRAPHIC_GetClactUnit 0x021B9A08 thumb ov225
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   KEY_GetRepeat 0x0203633C arm
 *   UI_SetInputMode 0x020355D8 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   gManualCommonListWorkAllocFile 0x021BC028 data ov225 a1
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandleExt 0x020499D4 arm
 *   gManualCommonListHeadPos 0x021BBF8C data ov225 a2
 *   gManualCommonListRowPos 0x021BBF94 data ov225 a2
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   UI_GetInputMode 0x020355C4 arm
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   KEY_GetTrg 0x020362DC arm
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   APP_TASKMENU_WIN_ClearScreen 0x0202843C thumb
 *   APP_TASKMENU_WIN_DeleteNoClear 0x0202815C thumb
 *   APP_TASKMENU_WIN_CreateExNoScreen 0x0202804C thumb
 *   APP_TASKMENU_WIN_Create 0x02027FEC thumb
 *   MANUAL_COMMON_UpdateTouchbar 0x021B9FBC thumb ov225
 *   MANUAL_COMMON_SetTouchbarState 0x021BA068 thumb ov225
 *   MANUAL_COMMON_GetTouchbarSelected 0x021BA154 thumb ov225
 *   MANUAL_COMMON_GetTouchbarPressed 0x021BA158 thumb ov225
 */
#include "manual_common_shared_types.h"
#include "manual_category_shared_types.h"
#include "manual_touchbar_shared_types.h"
#include "manual_list_shared_types.h"
#include "../arm9/key.h"
#include "../arm9/touchpanel.h"

#include "../types.h"

/* List work object built by MANUAL_COMMON_CreateListWork (0x98). */
struct ManualListWork {
    char *owner;                /* 0x00 list state */
    struct ManualData *data;    /* 0x04 */
    void *resource;             /* 0x08 taskmenu resource */
    void *win[8];               /* 0x0C */
    u32 slotFlag[8];            /* 0x2C */
    u16 paletteColor;                /* 0x4C */
    u16 pad4E;                  /* 0x4E */
    u32 reg0;                   /* 0x50 */
    u32 reg1;                   /* 0x54 */
    u32 reg2;                   /* 0x58 */
    void *actor;                /* 0x5C */
    void *actorList[8];         /* 0x60 */
    void *task;                 /* 0x80 */
    u32 state;                  /* 0x84 */
    u32 dragging;               /* 0x88 */
    u32 dirty;                  /* 0x8C */
    signed char timer;          /* 0x90 */
    u8 pad91[3];                /* 0x91 */
    u32 listReady;              /* 0x94 */
};


struct ManualClactPos { s16 x; s16 y; };

struct ManualPoint {short x,y;};

struct ManualQuad { short x,y,z,w; };

#include "../arm9/gfl_heap_wrap.h"

struct PrintQueue;

#include "../arm9/printsys.h"

#include "../arm9/gfl_use.h"
struct TcbTask;

#include "../arm9/tcb_list.h"
struct Actor;

#include "../arm9/clact.h"

#include "manual_graphic.h"

extern void PRINTSYS_QUE_Clear(struct PrintQueue *),BMP_WIN_Delete(struct Descriptor *);
struct MsgBank;
struct Strbuf;

#include "../arm9/msgdata.h"

#include "../arm9/strbuf.h"












#include "../arm9/ui.h"



#include "../arm9/bg_sys.h"

struct PrintQueue;

struct TaskMenuWin;

#include "../arm9/app_taskmenu.h"


#include "../arm9/arc_util.h"



struct GFont;
struct TaskMenuRes;


/* The DS code passes the source as a pointer (the original prototype); the header takes an address word. The host build uses the header. */
#include "../arm9/nns_gfd_vram_transfer.h"









struct TaskMenuItem;



#include "manual_touchbar.h"




void *MANUAL_COMMON_CreateListWork(char *owner, struct ManualData *data);

void MANUAL_COMMON_DeleteListWork(char *p);

int MANUAL_COMMON_UpdateListWork(char *p);

void MANUAL_COMMON_ListWorkTaskNoop(struct TcbTask *unused0, void *unused1);

void MANUAL_COMMON_LoadListWorkAssets(char *p);

void MANUAL_COMMON_CreateListWorkMenu(char *p);

void MANUAL_COMMON_SetListWorkBgMode(struct ManualListWork *work);

void MANUAL_COMMON_DeleteListWorkAssets(char *p);

void MANUAL_COMMON_DeleteListWorkMenu(char *p);

int MANUAL_COMMON_UpdateListWorkInput(char *p);

int MANUAL_COMMON_UpdateListWorkDrag(char *p);

void MANUAL_COMMON_BuildListRects(u8 *p);

u16 MANUAL_COMMON_GetCursorIndex(u16 **p);

u16 MANUAL_COMMON_GetLastVisible(u16 **p);

u16 MANUAL_COMMON_GetVisibleCount(u16 **p);

u16 MANUAL_COMMON_GetScrollTop(u16 **p);

void MANUAL_COMMON_RebuildListWindows(char *p);

u16 MANUAL_COMMON_HitToIndex(void *p, u16 count, u16 value);

u16 MANUAL_COMMON_IndexToY(void *p, u16 count, u16 index);

extern const char gManualCommonListWorkAllocFile[];

extern const struct ManualQuad gManualCommonListHeadPos,gManualCommonListRowPos;

void *MANUAL_COMMON_CreateListWork(char *owner, struct ManualData *data)
{
  struct ManualListWork *work;
  struct ManualClactPos pos;
  u8 index;
  u32 flag;
  u32 state;
  int count;
  s16 y;
  int mode;
  work = GFL_HEAP_Alloc(data->heap, sizeof(struct ManualListWork), 1, gManualCommonListWorkAllocFile, 0xdf);
  work->owner = owner;
  ((struct ManualListState *)owner)->mode = 0;
  work->data = data;
  index = 0;
  do
  {
    work->win[index] = 0;
    work->slotFlag[index] = 0;
    index++;
  }
  while (index < 8);
  work->listReady = 0;
  MANUAL_COMMON_LoadListWorkAssets((char *)work);
  MANUAL_COMMON_SetListWorkBgMode(work);
  BG_SYS_ChangeScroll(5, 3, 12);
  flag = 0;
  if (((struct ManualListState *)work->owner)->count > 6)
    flag = 1;
  CLACT_SetActorDrawEnable(work->actor, flag);
  count = MANUAL_COMMON_GetScrollTop((u16 **) work);
  count = count + 1;
  y = MANUAL_COMMON_IndexToY(work, count, ((struct ManualListState *)work->owner)->top);
  pos.x = 240;
  pos.y = y;
  CLACT_AddActorSurfacePos((struct ClactActor *)work->actor, (const struct ClactVec2 *)&pos, 1);
  work->task = GFL_USE_AddMainTask(MANUAL_COMMON_ListWorkTaskNoop, (void *)((uptr) work), 1);
  work->state = 0;
  work->dragging = 0;
  work->dirty = 0;
  work->timer = -1;
  mode = *((int *) work->owner);
  state = 2;
  if (mode == 0)
    state = 1;
  else
    if (mode == 1)
    state = 2;
  MANUAL_COMMON_SetTouchbarState(((struct ManualData *)work->data)->group, state);
  return work;
}

void MANUAL_COMMON_DeleteListWork(char *work)
{
    TCB_DeleteTask(((struct ManualListWork *)work)->task);
    BG_SYS_ChangeScroll(5, 3, 0);
    GFL_HEAP_Free(work);
}

/*
 * extent: lead 308 bytes; empty callback at 021BA894 and two zero alignment bytes.
 * arity: 02028178 retains original r1 payload despite unused input in its body.
 */
int MANUAL_COMMON_UpdateListWork(char *work)
{
 u8 i;
 int result=0;
 unsigned selected;
 if(!PRINTSYS_QUE_IsFinished((struct PrintQueue *)(*(const struct PrintQueue * *)&((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->printQue[1]))) return 0;
 if(((struct ManualListWork *)work)->timer==0) result=1;
 else if(((struct ManualListWork *)work)->timer>0) {
  if(((struct ManualListWork *)work)->timer==1) MANUAL_COMMON_DeleteListWorkAssets(work);
  (((struct ManualListWork *)work)->timer)--;
 }
 if(((struct ManualListWork *)work)->state!=1) {
  for(i=0;i<8;i++) {
   if(((struct ManualListWork *)work)->win[i] && ((struct ManualListWork *)work)->slotFlag[i])
    APP_TASKMENU_WIN_Update((struct TaskMenuWin *)(((struct ManualListWork *)work)->win[i]));
  }
 }
 if(((struct ManualListWork *)work)->state==0 || ((struct ManualListWork *)work)->state==2) {
  if(MANUAL_COMMON_UpdateListWorkDrag(work)) ((struct ManualListWork *)work)->state=2;
  else ((struct ManualListWork *)work)->state=0;
 }
 if(((struct ManualListWork *)work)->state==0 || ((struct ManualListWork *)work)->state==3) {
  MANUAL_COMMON_UpdateTouchbar(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->group);
  if(((struct ManualListWork *)work)->state==0) {
   if(MANUAL_COMMON_GetTouchbarPressed(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->group)!=(unsigned)-1) ((struct ManualListWork *)work)->state=3;
  } else {
   selected=MANUAL_COMMON_GetTouchbarSelected(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->group);
   if(selected!=(unsigned)-1) {
    if(selected==1) ((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->mode=0;
    ((struct ManualListWork *)work)->state=1;
    ((struct ManualListWork *)work)->timer=1;
   }
  }
 }
 if(((struct ManualListWork *)work)->state==0 || ((struct ManualListWork *)work)->state==4) {
  if(((struct ManualListWork *)work)->state==0) {
   if(MANUAL_COMMON_UpdateListWorkInput(work)) ((struct ManualListWork *)work)->state=4;
  } else {
   if(APP_TASKMENU_WIN_IsFinish((struct TaskMenuWin *)(((struct ManualListWork *)work)->win[MANUAL_COMMON_GetCursorIndex((u16 **)work)]))) {
    ((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->mode=1;
    ((struct ManualListWork *)work)->state=1;
    ((struct ManualListWork *)work)->timer=1;
   }
  }
 }
 return result;
}

void MANUAL_COMMON_ListWorkTaskNoop(struct TcbTask *unused0, void *unused1) {}

/*
 * Lever: index before 0x60 keeps field offset in immediate; distinct loop
 * parent local restores r7 parent / r6 destination allocation.
 */
void MANUAL_COMMON_LoadListWorkAssets(char *work)
{
    struct ManualQuad quad[2];
    u8 i;
    char *parent;
    ARC_UTIL_UploadPaletteFromHandleWhole(((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->arc[0],0,4,0,0x40,((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
    ARC_UTIL_UploadBgCharFromHandle(((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->arc[0],2,4,0,0,0,((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
    ARC_UTIL_UploadBgPaletteAddFromHandleExt(((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->arc[0],5,4,0,0,0,0,((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
    *(int *)&((struct ManualListWork *)work)->reg1=CLACT_RegisterPaletteEx(((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->arc[0],1,1,0,0,1,((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
    *(int *)&((struct ManualListWork *)work)->reg0=CLACT_RegisterCharacter(((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->arc[0],3,0,1,((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
    *(int *)&((struct ManualListWork *)work)->reg2=CLACT_RegisterCellAnim(((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->arc[0],7,8,((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
    quad[1]=gManualCommonListHeadPos;
    parent=*(char * *)&((struct ManualListWork *)work)->data;
    ((struct ManualListWork *)work)->actor=CLACT_CreateActor(MANUAL_GRAPHIC_GetClactUnit((const u8 *)(((struct ManualData *)parent)->screen)),((struct ManualListWork *)work)->reg0,((struct ManualListWork *)work)->reg1,((struct ManualListWork *)work)->reg2,(const struct ActorInitParam *)&quad[1],1,((struct ManualData *)parent)->heap);
    CLACT_SetActorDrawEnable(((struct ManualListWork *)work)->actor,0);
    CLACT_SetActorAutoAnim(((struct ManualListWork *)work)->actor,1);
    quad[0]=gManualCommonListRowPos;
    for(i=0;i<8;i++) {
        char *loopparent;
        quad[0].y=i*24-8;
        loopparent=*(char * *)&((struct ManualListWork *)work)->data;
        ((struct ManualListWork *)work)->actorList[i]=CLACT_CreateActor(MANUAL_GRAPHIC_GetClactUnit((const u8 *)(((struct ManualData *)loopparent)->screen)),((struct ManualListWork *)work)->reg0,((struct ManualListWork *)work)->reg1,((struct ManualListWork *)work)->reg2,(const struct ActorInitParam *)&quad[0],1,((struct ManualData *)loopparent)->heap);
        CLACT_SetActorDrawEnable(((struct ManualListWork *)work)->actorList[i],0);
        CLACT_SetActorAutoAnim(((struct ManualListWork *)work)->actorList[i],1);
    }
    MANUAL_COMMON_CreateListWorkMenu(work);
}

void MANUAL_COMMON_CreateListWorkMenu(char *work)
{
    BG_SYS_FreeSlot(5);
    *(struct ManualRes * *)&((struct ManualListWork *)work)->resource = (struct ManualRes *)APP_TASKMENU_RES_Create(5, 4, (struct GFont *)(((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->font), (struct PrintQueue *)(((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->printQue[1]), ((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
    ((struct ManualListWork *)work)->paletteColor = 0x1ce7;
    NNS_GfdRegisterNewVramTransferTask(31, 154, &((struct ManualListWork *)work)->paletteColor, 2);
    NNS_GfdRegisterNewVramTransferTask(31, 186, &((struct ManualListWork *)work)->paletteColor, 2);
    MANUAL_COMMON_RebuildListWindows(work);
    if (UI_GetInputMode() == 0) {
        APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)(((struct ManualListWork *)work)->win[MANUAL_COMMON_GetCursorIndex((u16 **)work)]), 1);
        ((struct ManualListWork *)work)->dirty = 0;
    }
}

void MANUAL_COMMON_SetListWorkBgMode(struct ManualListWork *work) { BG_SYS_MarkTileDirty(4); }

void MANUAL_COMMON_DeleteListWorkAssets(char *work) { u8 i; MANUAL_COMMON_DeleteListWorkMenu(work); for(i=0;i<8;i++) CLACT_DeleteActor((struct ClactActor *)((((struct ManualListWork *)work)->actorList[i]))); CLACT_DeleteActor((struct ClactActor *)((*(struct ClactActor * *)&((struct ManualListWork *)work)->actor))); CLACT_ReleaseCellAnim(((struct ManualListWork *)work)->reg2); CLACT_ReleaseCharacter(((struct ManualListWork *)work)->reg0); CLACT_ReleasePalette(((struct ManualListWork *)work)->reg1); }

void MANUAL_COMMON_DeleteListWorkMenu(char *work) { u8 i; PRINTSYS_QUE_Clear(*(struct PrintQueue * *)&((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->printQue[1]); for(i=0;i<8;i++) if(*(u8 **)(work+i*4+12)) APP_TASKMENU_WIN_Delete((struct TaskMenuWin *)(*(u8 **)(work+i*4+12))); APP_TASKMENU_RES_Delete((struct TaskMenuRes *)(*(struct TaskMenuState * *)&((struct ManualListWork *)work)->resource)); BG_SYS_MarkTileDirty(5); }

int MANUAL_COMMON_UpdateListWorkInput(char *work)
{
    u8 rect[28];
    struct ManualPoint delta[4];
    int hit;
    u16 count,last,y;
    MANUAL_COMMON_BuildListRects(rect);
    hit=TOUCHPANEL_HitTrg((const TouchHitTable *)rect);
    count=MANUAL_COMMON_GetVisibleCount((u16 **)work);
    last=MANUAL_COMMON_GetLastVisible((u16 **)work);
    if(UI_GetInputMode()==0) {
        if(hit>=0 && hit<count) {
            UI_SetInputMode(1);
            APP_TASKMENU_WIN_SetActive(((struct ManualListWork *)work)->win[MANUAL_COMMON_GetCursorIndex((u16 **)work)],0);
        }
    } else {
        if(KEY_GetTrg()!=0 && !(KEY_GetTrg()&2)) {
            UI_SetInputMode(0);
            APP_TASKMENU_WIN_SetActive(((struct ManualListWork *)work)->win[MANUAL_COMMON_GetCursorIndex((u16 **)work)],1);
            ((struct ManualListWork *)work)->dirty=0;
            GFL_USE_PlaySeDefaultVolume(0x548);
            return 0;
        }
    }
    if(UI_GetInputMode()==0) {
        if(KEY_GetTrg()&1) {
            APP_TASKMENU_WIN_SetDecide(((struct ManualListWork *)work)->win[MANUAL_COMMON_GetCursorIndex((u16 **)work)],1);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            return 1;
        }
        if((*(struct ManualListState **)work)->count>1) {
            if(KEY_GetRepeat()&0x40) {
                APP_TASKMENU_WIN_SetActive(((struct ManualListWork *)work)->win[MANUAL_COMMON_GetCursorIndex((u16 **)work)],0);
                if((*(struct ManualListState **)work)->selected>(*(struct ManualListState **)work)->top) (*(struct ManualListState **)work)->selected--;
                else if((*(struct ManualListState **)work)->count<=6) (*(struct ManualListState **)work)->selected=(*(struct ManualListState **)work)->count-1;
                else {
                    if((*(struct ManualListState **)work)->selected!=0) {
                        (*(struct ManualListState **)work)->top--;
                        (*(struct ManualListState **)work)->selected--;
                    } else {
                        (*(struct ManualListState **)work)->top=MANUAL_COMMON_GetScrollTop((u16 **)work);
                        (*(struct ManualListState **)work)->selected=(*(struct ManualListState **)work)->count-1;
                    }
                    MANUAL_COMMON_RebuildListWindows(work);
                    y=MANUAL_COMMON_IndexToY(work,(u16)(MANUAL_COMMON_GetScrollTop((u16 **)work)+1),(*(struct ManualListState **)work)->top);
                    delta[3].x=240;
                    delta[3].y=y;
                    CLACT_AddActorSurfacePos((struct ClactActor *)(*(struct ClactActor * *)&((struct ManualListWork *)work)->actor), (const struct ClactVec2 *)((const struct ManualClactPos *)(&delta[3])), 1);
                }
                APP_TASKMENU_WIN_SetActive(((struct ManualListWork *)work)->win[MANUAL_COMMON_GetCursorIndex((u16 **)work)],1);
                ((struct ManualListWork *)work)->dirty=0;
                GFL_USE_PlaySeDefaultVolume(0x548);
            } else if(KEY_GetRepeat()&0x80) {
                APP_TASKMENU_WIN_SetActive(((struct ManualListWork *)work)->win[MANUAL_COMMON_GetCursorIndex((u16 **)work)],0);
                if((*(struct ManualListState **)work)->selected<last) (*(struct ManualListState **)work)->selected++;
                else if((*(struct ManualListState **)work)->count<=6) (*(struct ManualListState **)work)->selected=0;
                else {
                    if((*(struct ManualListState **)work)->selected<(*(struct ManualListState **)work)->count-1) {
                        (*(struct ManualListState **)work)->top++;
                        (*(struct ManualListState **)work)->selected++;
                    } else {(*(struct ManualListState **)work)->top=0;(*(struct ManualListState **)work)->selected=0;}
                    MANUAL_COMMON_RebuildListWindows(work);
                    y=MANUAL_COMMON_IndexToY(work,(u16)(MANUAL_COMMON_GetScrollTop((u16 **)work)+1),(*(struct ManualListState **)work)->top);
                    delta[2].x=240;
                    delta[2].y=y;
                    CLACT_AddActorSurfacePos((struct ClactActor *)(*(struct ClactActor * *)&((struct ManualListWork *)work)->actor), (const struct ClactVec2 *)((const struct ManualClactPos *)(&delta[2])), 1);
                }
                APP_TASKMENU_WIN_SetActive(((struct ManualListWork *)work)->win[MANUAL_COMMON_GetCursorIndex((u16 **)work)],1);
                ((struct ManualListWork *)work)->dirty=0;
                GFL_USE_PlaySeDefaultVolume(0x548);
            } else if(KEY_GetRepeat()&0x220) {
                if((*(struct ManualListState **)work)->selected!=0) {
                    APP_TASKMENU_WIN_SetActive(((struct ManualListWork *)work)->win[MANUAL_COMMON_GetCursorIndex((u16 **)work)],0);
                    if((*(struct ManualListState **)work)->count<=6) (*(struct ManualListState **)work)->selected=0;
                    else {
                        if((*(struct ManualListState **)work)->top>=6) {(*(struct ManualListState **)work)->top-=6;(*(struct ManualListState **)work)->selected-=6;}
                        else {(*(struct ManualListState **)work)->top=0;if((*(struct ManualListState **)work)->selected>=6) (*(struct ManualListState **)work)->selected-=6;else (*(struct ManualListState **)work)->selected=0;}
                        MANUAL_COMMON_RebuildListWindows(work);
                        y=MANUAL_COMMON_IndexToY(work,(u16)(MANUAL_COMMON_GetScrollTop((u16 **)work)+1),(*(struct ManualListState **)work)->top);
                        delta[1].x=240;
                        delta[1].y=y;
                        CLACT_AddActorSurfacePos((struct ClactActor *)(*(struct ClactActor * *)&((struct ManualListWork *)work)->actor), (const struct ClactVec2 *)((const struct ManualClactPos *)(&delta[1])), 1);
                    }
                    APP_TASKMENU_WIN_SetActive(((struct ManualListWork *)work)->win[MANUAL_COMMON_GetCursorIndex((u16 **)work)],1);
                    ((struct ManualListWork *)work)->dirty=0;
                    GFL_USE_PlaySeDefaultVolume(0x548);
                }
            } else if(KEY_GetRepeat()&0x110) {
                if((*(struct ManualListState **)work)->selected<(*(struct ManualListState **)work)->count-1) {
                    APP_TASKMENU_WIN_SetActive(((struct ManualListWork *)work)->win[MANUAL_COMMON_GetCursorIndex((u16 **)work)],0);
                    if((*(struct ManualListState **)work)->count<=6) (*(struct ManualListState **)work)->selected=(*(struct ManualListState **)work)->count-1;
                    else {
                        (*(struct ManualListState **)work)->top+=6;
                        if((*(struct ManualListState **)work)->top>MANUAL_COMMON_GetScrollTop((u16 **)work)) (*(struct ManualListState **)work)->top=MANUAL_COMMON_GetScrollTop((u16 **)work);
                        (*(struct ManualListState **)work)->selected+=6;
                        if((*(struct ManualListState **)work)->selected>=(*(struct ManualListState **)work)->count) (*(struct ManualListState **)work)->selected=(*(struct ManualListState **)work)->count-1;
                        MANUAL_COMMON_RebuildListWindows(work);
                        y=MANUAL_COMMON_IndexToY(work,(u16)(MANUAL_COMMON_GetScrollTop((u16 **)work)+1),(*(struct ManualListState **)work)->top);
                        delta[0].x=240;
                        delta[0].y=y;
                        CLACT_AddActorSurfacePos((struct ClactActor *)(*(struct ClactActor * *)&((struct ManualListWork *)work)->actor), (const struct ClactVec2 *)((const struct ManualClactPos *)(&delta[0])), 1);
                    }
                    APP_TASKMENU_WIN_SetActive(((struct ManualListWork *)work)->win[MANUAL_COMMON_GetCursorIndex((u16 **)work)],1);
                    ((struct ManualListWork *)work)->dirty=0;
                    GFL_USE_PlaySeDefaultVolume(0x548);
                }
            }
        }
    } else if(hit>=0 && hit<count) {
        (*(struct ManualListState **)work)->selected=(*(struct ManualListState **)work)->top+hit;
        APP_TASKMENU_WIN_SetActive(((struct ManualListWork *)work)->win[MANUAL_COMMON_GetCursorIndex((u16 **)work)],1);
        ((struct ManualListWork *)work)->dirty=0;
        APP_TASKMENU_WIN_SetDecide(((struct ManualListWork *)work)->win[MANUAL_COMMON_GetCursorIndex((u16 **)work)],1);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return 1;
    }
    return 0;
}

/*
 * Lever: initialise offset after cursor clear, letting zero schedule at
 * that call's argument setup rather than before the touch-mode setter.
 */
int MANUAL_COMMON_UpdateListWorkDrag(char *work)
{
    u32 dragx,dragy;
    struct ManualPoint drag;
    u32 clickx,clicky;
    struct ManualPoint click;
    if(CLACT_GetActorDrawEnable((struct ClactActor *)((*(struct ClactActor * *)&((struct ManualListWork *)work)->actor)))==0) return 0;
    if(((struct ManualListWork *)work)->dragging) {
        if(TOUCHPANEL_GetPointCont(&dragx,&dragy)) {
            int offset;
            u16 selection,end;
            UI_SetInputMode(1);
            APP_TASKMENU_WIN_SetActive(((struct ManualListWork *)work)->win[MANUAL_COMMON_GetCursorIndex((u16 **)work)],0);
            offset=0;
            drag.x=240;
            if(dragy>=8) offset=dragy-8;
            drag.y=offset;
            if(drag.y<17) drag.y=17;
            else if(drag.y>135) drag.y=135;
            CLACT_AddActorSurfacePos((struct ClactActor *)(*(struct ClactActor * *)&((struct ManualListWork *)work)->actor), (const struct ClactVec2 *)&drag, 1);
            selection=MANUAL_COMMON_HitToIndex(work,(u16)(MANUAL_COMMON_GetScrollTop((u16 **)work)+1),(u16)dragy);
            if(selection!=((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top) {
                ((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top=selection;
                end=MANUAL_COMMON_GetLastVisible((u16 **)work);
                if(((struct ManualListWork *)work)->dirty || ((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->selected<((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top || end<((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->selected) {
                    ((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->selected=((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top;
                    ((struct ManualListWork *)work)->dirty=1;
                }
                MANUAL_COMMON_RebuildListWindows(work);
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
        } else ((struct ManualListWork *)work)->dragging=0;
        return 1;
    } else {
        if(TOUCHPANEL_GetPointTrg(&clickx,&clicky) && clickx>=240 && clickx<=247 && clicky>=17 && clicky<=150) {
            int offset;
            u16 selection,end;
            UI_SetInputMode(1);
            APP_TASKMENU_WIN_SetActive(((struct ManualListWork *)work)->win[MANUAL_COMMON_GetCursorIndex((u16 **)work)],0);
            offset=0;
            GFL_USE_PlaySeDefaultVolume(0x548);
            ((struct ManualListWork *)work)->dragging=1;
            click.x=240;
            if(clicky>=8) offset=clicky-8;
            click.y=offset;
            if(click.y<17) click.y=17;
            else if(click.y>135) click.y=135;
            CLACT_AddActorSurfacePos((struct ClactActor *)(*(struct ClactActor * *)&((struct ManualListWork *)work)->actor), (const struct ClactVec2 *)&click, 1);
            selection=MANUAL_COMMON_HitToIndex(work,(u16)(MANUAL_COMMON_GetScrollTop((u16 **)work)+1),(u16)clicky);
            if(selection!=((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top) {
                ((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top=selection;
                end=MANUAL_COMMON_GetLastVisible((u16 **)work);
                if(((struct ManualListWork *)work)->dirty || ((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->selected<((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top || end<((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->selected) {
                    ((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->selected=((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top;
                    ((struct ManualListWork *)work)->dirty=1;
                }
                MANUAL_COMMON_RebuildListWindows(work);
            }
        }
        if(((struct ManualListWork *)work)->dragging) return 1;
        return 0;
    }
}

void MANUAL_COMMON_BuildListRects(u8 *rect) { u8 i; for(i=0;i<6;i++) { rect[i*4]=i*24+12; rect[i*4+1]=(i+1)*24+11; rect[i*4+2]=16; rect[i*4+3]=239; } rect[24]=255; rect[25]=0; rect[26]=0; rect[27]=0; }

u16 MANUAL_COMMON_GetCursorIndex(u16 **work)
{
    u16 *state = *work;
    return (u16)(state[7] - state[6] + 1);
}

u16 MANUAL_COMMON_GetLastVisible(u16 **work)
{
    u16 *state = *work;
    u16 limit = (u16)(state[6] + 5);
    u16 count = state[2];
    if (limit < count)
        return limit;
    return (u16)(count - 1);
}

u16 MANUAL_COMMON_GetVisibleCount(u16 **work)
{
    return (u16)(MANUAL_COMMON_GetLastVisible(work) - (*work)[6] + 1);
}

u16 MANUAL_COMMON_GetScrollTop(u16 **work)
{
    u16 count = (*work)[2];
    if (count <= 6)
        return 0;
    return (u16)(count - 6);
}

void MANUAL_COMMON_RebuildListWindows(char *work)
{
    struct ManualTaskEntry entry;
    u8 first,last,i;
    u16 index,end;
    first=0;
    index=(u16)(((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top-1);
    if (((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top==0) {
        if (*(u8 * *)&((struct ManualListWork *)work)->win[0]) {
            APP_TASKMENU_WIN_ClearScreen((struct TaskMenuWin *)(*(u8 * *)&((struct ManualListWork *)work)->win[0]));
            ((struct ManualListWork *)work)->slotFlag[0]=0;
        }
        index=((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top;
        first=1;
        CLACT_SetActorDrawEnable(((struct ManualListWork *)work)->actorList[0],0);
    }
    end=(u16)(MANUAL_COMMON_GetLastVisible((u16 **)work)+1);
    if (end>=((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->count) end--;
    last=(u8)(first+end-index);
    for(i=last+1;i<=7;i++) {
        if (((struct ManualListWork *)work)->win[i]) {
            APP_TASKMENU_WIN_ClearScreen((struct TaskMenuWin *)(((struct ManualListWork *)work)->win[i]));
            ((struct ManualListWork *)work)->slotFlag[i]=0;
        }
        CLACT_SetActorDrawEnable(((struct ManualListWork *)work)->actorList[i],0);
    }
    for(i=first;i<=last;i++) {
        if (((struct ManualListWork *)work)->win[i]) APP_TASKMENU_WIN_DeleteNoClear(((struct ManualListWork *)work)->win[i]);
        entry.resource=MSGDATA_AllocString(*(struct MsgBank * *)&((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->bank[1],*(u16 *)(*(char * *)&((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->data+index*8+2));
        if(i==0 || i==7) entry.tag=0x3da3; else entry.tag=0x39e3;
        entry.flags=0;
        if(((struct ManualListWork *)work)->listReady)
            ((struct ManualListWork *)work)->win[i]=APP_TASKMENU_WIN_CreateExNoScreen((struct TaskMenuRes *)((struct ManualListWork *)work)->resource,(struct TaskMenuItem *)&entry,2,(u8)(i*3),28,3,0,0,((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
        else
            ((struct ManualListWork *)work)->win[i]=APP_TASKMENU_WIN_Create((struct TaskMenuRes *)((struct ManualListWork *)work)->resource,(struct TaskMenuItem *)&entry,2,(u8)(i*3),28,((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
        APP_TASKMENU_WIN_Update((struct TaskMenuWin *)(((struct ManualListWork *)work)->win[i]));
        ((struct ManualListWork *)work)->slotFlag[i]=1;
        STRBUF_Delete(entry.resource);
        if (*(u32 *)(*(char * *)&((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->data+index*8+4)==0)
            CLACT_SetActorDrawEnable(((struct ManualListWork *)work)->actorList[i],0);
        else if (*(u32 *)(*(char * *)&((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->data+index*8+4)==1)
            CLACT_SetActorDrawEnable(((struct ManualListWork *)work)->actorList[i],1);
        index++;
    }
    ((struct ManualListWork *)work)->listReady=1;
}

u16 MANUAL_COMMON_HitToIndex(void *unused, u16 count, u16 value)
{
    u16 index, upper, lower;
    if (count <= 1) index = 0;
    else if (value < 25) index = 0;
    else if (value >= 144) index = count - 1;
    else {
        for (index = 0; index < count; index++) {
            upper = (119 * (index + 1)) / count + 25;
            lower = (119 * index) / count + 25;
            if (lower <= value && value < upper) break;
        }
    }
    if (index >= count) index = 0;
    return index;
}

/*
 * lever: narrow the average to u16 before subtracting 8; minimum clamp returns directly.
 * extent: 90 compiled bytes followed by two zero alignment bytes at 021BB2B2.
 */
u16 MANUAL_COMMON_IndexToY(void *unused, u16 count, u16 index)
{
    u16 result, low, high;
    if (index == 0) result = 17;
    else if (index == count - 1) result = 135;
    else {
        low = (119 * index) / count + 25;
        high = (119 * (index + 1)) / count + 25;
        result = (low + high) / 2;
        result -= 8;
    }
    if (result < 17) return 17;
    if (result > 135) result = 135;
    return result;
}
