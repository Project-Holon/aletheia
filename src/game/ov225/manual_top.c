/*
 * file:     manual_top.c
 * unit:     yes
 * function: MANUAL_COMMON_CreateDialog, MANUAL_COMMON_DeleteDialog, MANUAL_COMMON_UpdateDialog, MANUAL_COMMON_DialogTaskNoop, MANUAL_COMMON_LoadDialogAssets, MANUAL_COMMON_CreateDialogWindows, MANUAL_COMMON_SetDialogBgMode, MANUAL_COMMON_DeleteDialogStep, MANUAL_COMMON_DeleteDialogWindows, MANUAL_COMMON_UpdateDialogInput
 * address:  0x021BB2B4
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
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   KEY_GetRepeat 0x0203633C arm
 *   UI_SetInputMode 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandleExt 0x020499D4 arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   UI_GetInputMode 0x020355C4 arm
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   KEY_GetTrg 0x020362DC arm
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   APP_TASKMENU_WIN_Create 0x02027FEC thumb
 *   gManualCommonDialogAllocFile 0x021BC038 data a1
 *   gManualCommonDialogHitRects 0x021BBF9C data a4
 *   MANUAL_COMMON_UpdateTouchbar 0x021B9FBC thumb ov225
 *   MANUAL_COMMON_SetTouchbarState 0x021BA068 thumb ov225
 *   MANUAL_COMMON_GetTouchbarSelected 0x021BA154 thumb ov225
 *   MANUAL_COMMON_GetTouchbarPressed 0x021BA158 thumb ov225
 */
#include "../types.h"
#include "manual_common_shared_types.h"
#include "manual_touchbar_shared_types.h"
#include "manual_list_shared_types.h"
#include "../arm9/key.h"

struct ManualListBuffer;

/* Confirm dialog object built by MANUAL_COMMON_CreateDialog (0x20). */
struct ManualDialog {
    char *owner;                     /* 0x00 selection buffer */
    struct ManualData *data;         /* 0x04 */
    void *resource;                  /* 0x08 taskmenu resource */
    void *win[2];                    /* 0x0C */
    void *task;                      /* 0x14 */
    u32 state;                       /* 0x18 */
    signed char timer;               /* 0x1C */
    u8 pad1D[3];                     /* 0x1D */
};

/* Selection region at ManualWork+0x14 passed to MANUAL_COMMON_CreateDialog (0x8). */
struct ManualListBuffer {
    u8 selected;    /* 0x00 */
    u8 pad01[3];    /* 0x01 */
    u32 choice;     /* 0x04 */
};

#include "../arm9/gfl_heap_wrap.h"

struct PrintQueue;

#include "../arm9/printsys.h"

#include "../arm9/gfl_use.h"
struct TcbTask;

#include "../arm9/tcb_list.h"

extern void PRINTSYS_QUE_Clear(struct PrintQueue *),BMP_WIN_Delete(struct Descriptor *);
struct MsgBank;
struct Strbuf;

#include "../arm9/msgdata.h"

#include "../arm9/strbuf.h"


#include "../arm9/ui.h"

struct TaskMenuWin;

#include "../arm9/app_taskmenu.h"


#include "../arm9/arc_util.h"


struct PrintQueue;
struct GFont;
struct TaskMenuRes;




#include "../arm9/bg_sys.h"



#include "../arm9/touchpanel.h"

struct TaskMenuItem;


#include "manual_touchbar.h"




char *MANUAL_COMMON_CreateDialog(char *p, char *data);

void MANUAL_COMMON_DeleteDialog(char *p);

int MANUAL_COMMON_UpdateDialog(char *p);

void MANUAL_COMMON_DialogTaskNoop(struct TcbTask *unused, void *unused1);

void MANUAL_COMMON_LoadDialogAssets(char *p);

void MANUAL_COMMON_CreateDialogWindows(char *p);

void MANUAL_COMMON_SetDialogBgMode(char *dialog);

void MANUAL_COMMON_DeleteDialogStep(char *p);

void MANUAL_COMMON_DeleteDialogWindows(char *p);

int MANUAL_COMMON_UpdateDialogInput(char *p);

extern const char gManualCommonDialogAllocFile[];

extern const u8 gManualCommonDialogHitRects[];

char *MANUAL_COMMON_CreateDialog(char *owner, char *data)
{
    char *dialog;
    dialog = GFL_HEAP_Alloc(((struct ManualData *)data)->heap, sizeof(struct ManualDialog), 1, gManualCommonDialogAllocFile, 157);
    *(char * *)&((struct ManualDialog *)dialog)->owner = owner;
    ((struct ManualListBuffer *)owner)->choice = 1;
    *(char * *)&((struct ManualDialog *)dialog)->data = data;
    MANUAL_COMMON_LoadDialogAssets(dialog);
    MANUAL_COMMON_SetDialogBgMode(dialog);
    ((struct ManualDialog *)dialog)->task = GFL_USE_AddMainTask(MANUAL_COMMON_DialogTaskNoop, (void *)((uptr)dialog), 1);
    ((struct ManualDialog *)dialog)->state = 0;
    ((struct ManualDialog *)dialog)->timer = -1;
    MANUAL_COMMON_SetTouchbarState(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->group, 0);
    return dialog;
}

void MANUAL_COMMON_DeleteDialog(char *dialog)
{
    TCB_DeleteTask((struct TcbTask *)(((struct ManualDialog *)dialog)->task));
    GFL_HEAP_Free(dialog);
}

/*
 * Tail: 021BB3FA alignment, existing matched follower 021BB3FC.
 * Lever: switch body order 1 then 0 preserves the shared store block.
 */
int MANUAL_COMMON_UpdateDialog(char *dialog)
{
    int done = 0;
    u8 i;
    if (((struct ManualDialog *)dialog)->timer==0) done=1;
    else if (((struct ManualDialog *)dialog)->timer>0) {
        if (((struct ManualDialog *)dialog)->timer==1) MANUAL_COMMON_DeleteDialogStep(dialog);
        --((struct ManualDialog *)dialog)->timer;
    }
    if (((struct ManualDialog *)dialog)->state==0 || ((struct ManualDialog *)dialog)->state==2) {
        MANUAL_COMMON_UpdateTouchbar(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->group);
        if (((struct ManualDialog *)dialog)->state==0) {
            if (MANUAL_COMMON_GetTouchbarPressed(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->group)!=-1)
                ((struct ManualDialog *)dialog)->state=2;
        } else {
            int result=MANUAL_COMMON_GetTouchbarSelected(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->group);
            if (result!=-1) {
                switch (result) {
                case 1: ((struct ManualListBuffer *)(*(char * *)&((struct ManualDialog *)dialog)->owner))->choice=1; break;
                case 0: ((struct ManualListBuffer *)(*(char * *)&((struct ManualDialog *)dialog)->owner))->choice=0; break;
                }
                ((struct ManualDialog *)dialog)->state=1;
                ((struct ManualDialog *)dialog)->timer=1;
            }
        }
    }
    if (((struct ManualDialog *)dialog)->state==0 || ((struct ManualDialog *)dialog)->state==3) {
        for (i=0;i<2;i++) APP_TASKMENU_WIN_Update((struct TaskMenuWin *)((struct ManualDialog *)dialog)->win[i]);
        if (((struct ManualDialog *)dialog)->state==0) {
            if (MANUAL_COMMON_UpdateDialogInput(dialog)) ((struct ManualDialog *)dialog)->state=3;
        } else {
            if (APP_TASKMENU_WIN_IsFinish((struct TaskMenuWin *)((struct ManualDialog *)dialog)->win[**(u8 * *)&((struct ManualDialog *)dialog)->owner])) {
                unsigned value;
                if (**(u8 * *)&((struct ManualDialog *)dialog)->owner==0) value=2;
                else if (**(u8 * *)&((struct ManualDialog *)dialog)->owner==1) value=3;
                else goto finish;
                ((struct ManualListBuffer *)(*(char * *)&((struct ManualDialog *)dialog)->owner))->choice=value;
finish:
                ((struct ManualDialog *)dialog)->state=1;
                ((struct ManualDialog *)dialog)->timer=1;
            }
        }
    }
    return done;
}

void MANUAL_COMMON_DialogTaskNoop(struct TcbTask *unused, void *unused1)
{
}

/*
 * extent: 86 compiled bytes followed by two zero alignment bytes at 021BB456.
 */
void MANUAL_COMMON_LoadDialogAssets(char *dialog)
{
    ARC_UTIL_UploadPaletteFromHandleWhole((void *)(((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->arc[0]), 0, 4, 0, 64, ((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->heap);
    ARC_UTIL_UploadBgCharFromHandle((void *)(((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->arc[0]), 2, 4, 0, 0, 0, ((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->heap);
    ARC_UTIL_UploadBgPaletteAddFromHandleExt((void *)(((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->arc[0]), 4, 4, 0, 0, 0, 0, ((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->heap);
    MANUAL_COMMON_CreateDialogWindows(dialog);
}

void MANUAL_COMMON_CreateDialogWindows(char *dialog)
{
    struct ManualTaskEntry entries[2];
    u8 i;
    *(struct ManualRes * *)&((struct ManualDialog *)dialog)->resource = (struct ManualRes *)APP_TASKMENU_RES_Create(5, 4, (struct GFont *)(((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->font), (struct PrintQueue *)(((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->printQue[1]), ((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->heap);
    entries[0].resource = MSGDATA_AllocString(*(struct MsgBank * *)&((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->bank[0], 0);
    entries[0].tag = 0x39e3;
    entries[0].flags = 0;
    entries[1].resource = MSGDATA_AllocString(*(struct MsgBank * *)&((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->bank[0], 1);
    entries[1].tag = 0x39e3;
    entries[1].flags = 0;
    for (i = 0; i < 2; i++) {
        ((struct ManualDialog *)dialog)->win[i] = APP_TASKMENU_WIN_Create((struct TaskMenuRes *)((struct ManualDialog *)dialog)->resource, (struct TaskMenuItem *)&entries[i], 1, (u8)((i + 1) * 3), 30, ((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->heap);
        STRBUF_Delete(entries[i].resource);
    }
    if (UI_GetInputMode() == 0) APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)(((struct ManualDialog *)dialog)->win[*(u8 *)*(char * *)&((struct ManualDialog *)dialog)->owner]), 1);
}

void MANUAL_COMMON_SetDialogBgMode(char *dialog) { BG_SYS_MarkTileDirty(4); }

void MANUAL_COMMON_DeleteDialogStep(char *dialog) { MANUAL_COMMON_DeleteDialogWindows(dialog); }

void MANUAL_COMMON_DeleteDialogWindows(char *dialog) { u8 i; PRINTSYS_QUE_Clear(*(struct PrintQueue * *)&((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->printQue[1]); for(i=0;i<2;i++) APP_TASKMENU_WIN_Delete((struct TaskMenuWin *)(((struct ManualDialog *)dialog)->win[i])); APP_TASKMENU_RES_Delete((struct TaskMenuRes *)(*(struct TaskMenuState * *)&((struct ManualDialog *)dialog)->resource)); BG_SYS_MarkTileDirty(5); }

/*
 * Lever: unhinted BF9C data uses this function's own overlay region.
 */
int MANUAL_COMMON_UpdateDialogInput(char *dialog)
{
    int hit=TOUCHPANEL_HitTrg((const TouchHitTable *)gManualCommonDialogHitRects);
    if(UI_GetInputMode()==0) {
        if(hit>=0 && hit<=1) {
            UI_SetInputMode(1);
            APP_TASKMENU_WIN_SetActive(((struct ManualDialog *)dialog)->win[**(u8 * *)&((struct ManualDialog *)dialog)->owner],0);
        }
    } else {
        if(KEY_GetTrg()!=0 && !(KEY_GetTrg()&0x402)) {
            UI_SetInputMode(0);
            APP_TASKMENU_WIN_SetActive(((struct ManualDialog *)dialog)->win[**(u8 * *)&((struct ManualDialog *)dialog)->owner],1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            return 0;
        }
    }
    if(UI_GetInputMode()==0) {
        if(KEY_GetTrg()&1) {
            APP_TASKMENU_WIN_SetDecide(((struct ManualDialog *)dialog)->win[**(u8 * *)&((struct ManualDialog *)dialog)->owner],1);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            return 1;
        } else if(KEY_GetRepeat()&0x40) {
            APP_TASKMENU_WIN_SetActive(((struct ManualDialog *)dialog)->win[**(u8 * *)&((struct ManualDialog *)dialog)->owner],0);
            if(**(u8 * *)&((struct ManualDialog *)dialog)->owner==0) **(u8 * *)&((struct ManualDialog *)dialog)->owner=1; else **(u8 * *)&((struct ManualDialog *)dialog)->owner=0;
            APP_TASKMENU_WIN_SetActive(((struct ManualDialog *)dialog)->win[**(u8 * *)&((struct ManualDialog *)dialog)->owner],1);
            GFL_USE_PlaySeDefaultVolume(0x548);
        } else if(KEY_GetRepeat()&0x80) {
            APP_TASKMENU_WIN_SetActive(((struct ManualDialog *)dialog)->win[**(u8 * *)&((struct ManualDialog *)dialog)->owner],0);
            if(**(u8 * *)&((struct ManualDialog *)dialog)->owner==1) **(u8 * *)&((struct ManualDialog *)dialog)->owner=0; else **(u8 * *)&((struct ManualDialog *)dialog)->owner=1;
            APP_TASKMENU_WIN_SetActive(((struct ManualDialog *)dialog)->win[**(u8 * *)&((struct ManualDialog *)dialog)->owner],1);
            GFL_USE_PlaySeDefaultVolume(0x548);
        } else if(KEY_GetRepeat()&0x220) {
            if(**(u8 * *)&((struct ManualDialog *)dialog)->owner==1) {
                APP_TASKMENU_WIN_SetActive(((struct ManualDialog *)dialog)->win[**(u8 * *)&((struct ManualDialog *)dialog)->owner],0);
                **(u8 * *)&((struct ManualDialog *)dialog)->owner=0;
                APP_TASKMENU_WIN_SetActive(((struct ManualDialog *)dialog)->win[**(u8 * *)&((struct ManualDialog *)dialog)->owner],1);
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
        } else if(KEY_GetRepeat()&0x110) {
            if(**(u8 * *)&((struct ManualDialog *)dialog)->owner==0) {
                APP_TASKMENU_WIN_SetActive(((struct ManualDialog *)dialog)->win[**(u8 * *)&((struct ManualDialog *)dialog)->owner],0);
                **(u8 * *)&((struct ManualDialog *)dialog)->owner=1;
                APP_TASKMENU_WIN_SetActive(((struct ManualDialog *)dialog)->win[**(u8 * *)&((struct ManualDialog *)dialog)->owner],1);
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
        }
    } else if(hit>=0 && hit<=1) {
        **(u8 * *)&((struct ManualDialog *)dialog)->owner=hit;
        APP_TASKMENU_WIN_SetActive(((struct ManualDialog *)dialog)->win[**(u8 * *)&((struct ManualDialog *)dialog)->owner],1);
        APP_TASKMENU_WIN_SetDecide(((struct ManualDialog *)dialog)->win[**(u8 * *)&((struct ManualDialog *)dialog)->owner],1);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return 1;
    }
    return 0;
}
