/*
 * file:     battle_championship_core.c
 * unit:     yes
 * function: BATTLE_CHAMPIONSHIP_FLOW_Create, BATTLE_CHAMPIONSHIP_FLOW_Delete, BATTLE_CHAMPIONSHIP_FLOW_IsFinished, BATTLE_CHAMPIONSHIP_FLOW_CreateGraphic, BATTLE_CHAMPIONSHIP_FLOW_DeleteGraphic, BATTLE_CHAMPIONSHIP_FLOW_ReleaseGraphic, BATTLE_CHAMPIONSHIP_FLOW_CreateView, BATTLE_CHAMPIONSHIP_FLOW_DeleteView, BATTLE_CHAMPIONSHIP_FLOW_CreateText, BATTLE_CHAMPIONSHIP_FLOW_DeleteText, BATTLE_CHAMPIONSHIP_FLOW_UpdateText, BATTLE_CHAMPIONSHIP_FLOW_SelectFlow, BATTLE_CHAMPIONSHIP_FLOW_End, BATTLE_CHAMPIONSHIP_FLOW_FadeIn, BATTLE_CHAMPIONSHIP_FLOW_FadeOut, BATTLE_CHAMPIONSHIP_FLOW_StartMenu, BATTLE_CHAMPIONSHIP_FLOW_StartLiveMatch
 * address:  0x0217AE20
 * region:   ov176
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from battle_championship_flow.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   WIFIBATTLEMATCH_UTIL_CreateCallback 0x021E8A3C thumb ov177
 *   WIFIBATTLEMATCH_UTIL_DeleteCallback  0x021E8A78  thumb  ov177
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   ov177_id       0x000000B1  data
 *   ov67_id        0x00000043  data
 *   WIFIBATTLEMATCH_UTIL_InvokeCallback 0x021E8A80 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_IsCallbackNull 0x021E8A90 thumb ov177
 *   WIFIBATTLEMATCH_GRAPHIC_Create  0x021E5440  thumb  ov177
 *   WIFIBATTLEMATCH_GRAPHIC_Delete  0x021E54E0  thumb  ov177
 *   WIFIBATTLEMATCH_GRAPHIC_Draw  0x021E5534  thumb  ov177
 *   WIFIBATTLEMATCH_VIEW_UpdateAnimation  0x021E5980  thumb  ov177
 *   WIFIBATTLEMATCH_GRAPHIC_GetCamera  0x021E5548  thumb  ov177
 *   WIFIBATTLEMATCH_VIEW_Create  0x021E567C  thumb  ov177
 *   WIFIBATTLEMATCH_VIEW_Delete 0x021E5868 thumb ov177
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   WIFIBATTLEMATCH_UTIL_Create 0x021E8568 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_Delete  0x021E8628  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   WIFIBATTLEMATCH_UTIL_Main  0x021E867C  thumb  ov177
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_ClearCallback 0x021E8AA8 thumb ov177
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   GF_PANIC_Fail 0x02034714 arm
 *   d_0217E5E0 0x0217E5E0 data a1
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_0217E5E4 0x0217E5E4 data a1
 *   GFL_HEAP_Free 0x020307B0 arm
 *   APP_ENV_IsWirelessAvailable 0x0202EB44 thumb
 *   BATTLE_REC_ClearWork 0x0200B480 thumb
 *   DIGITALCARDCHECK_Create 0x0217D398 thumb ov176
 *   DIGITALCARDCHECK_DeleteAlt 0x0217D434 thumb ov176
 *   DIGITALCARDCHECK_GetProcResult 0x0217D44C thumb ov176
 *   DIGITALCARDCHECK_Delete 0x0217D410 thumb ov176
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   WIFIBATTLEMATCH_UTIL_CreateMenu 0x021E88B0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_DeleteMenu 0x021E89D0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_UpdateMenu 0x021E8A00 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_PrintMessage  0x021E8738  thumb  ov177
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   LIVEBATTLEMATCH_FLOW_Create 0x0217B984 thumb ov176
 *   LIVEBATTLEMATCH_FLOW_Delete 0x0217BA9C thumb ov176
 *   LIVEBATTLEMATCH_FLOW_Release 0x0217BAF4 thumb ov176
 *   LIVEBATTLEMATCH_FLOW_GetResult 0x0217BB3C thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_CreateMenu  0x0217B2E4  thumb  ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_DeleteMenu  0x0217B344  thumb  ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_InvokeCallback  0x0217B35C  thumb  ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_GetMenuResult  0x0217B368  thumb  ov176
 */
#include "livebattlematch_shared_types.h"

struct ProcOwner;

struct Proc;

#include "livebattlematch_shared_types.h"

#include "battle_championship_flow_types.h"

#include "../version.h"

/* Japanese: text bank id of the championship messages. */
#if LANGUAGE == LANGUAGE_JAPANESE
#define BATTLE_CHAMPIONSHIP_MSG_ARC 7
#else
#define BATTLE_CHAMPIONSHIP_MSG_ARC 4
#endif

#include "../arm9/gfl_heap.h"

#include "../arm9/procsys.h"

#include "../arm9/mi_memory.h"

#include "../arm9/gf_overlay.h"
struct WifibattlematchCallback;

#include "../ov177/wifibattlematch_util.h"


#include "../arm9/gfl_heap_wrap.h"


#include "../ov177/wifibattlematch_graphic.h"


#include "../ov177/wifibattlematch_view.h"


#include "../arm9/gf_font.h"

#include "../arm9/msgdata.h"
struct PrintQueue;

#include "../arm9/printsys.h"
struct WifibattlematchUtilWork;


#include "../arm9/fade.h"


#include "../arm9/gf_panic.h"

#include "../arm9/gfl_use.h"


#include "../arm9/app_env.h"

#include "../arm9/battle_rec.h"

#include "digitalcardcheck.h"


struct GameData;
struct SaveControl;

#include "../arm9/game_data.h"
struct BattleCompetitionSave;

#include "../arm9/regulation.h"

struct WifibattlematchMenu;

struct WifibattlematchMenu;


#include "battle_championship_flow.h"
#include "battle_championship_core.h"

#include "livebattlematch_flow.h"
#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_0217E560[];
extern const char str_ja_0217E57C[];
#endif


extern char ov67_id[],ov177_id[];

extern char ov67_id[];

extern const char d_0217E5E0[];

extern const char d_0217E5E4[];

int BATTLE_CHAMPIONSHIP_FLOW_Create(void *owner,void *unused,void *context)
{
    BattleChampionshipFlowWork *work;
    GFL_HEAP_CreateChildHeap(1,0x4e,PM_LANG_JA(0x30200, 0x30000));
    work=PROCSYS_AllocProcWork(owner,sizeof(*work),0x4e);
    MI_CpuFill8(work,0,sizeof(*work));
    work->context=context;
    work->heapId=0x4e;
    GF_OVERLAY_Load((sptr)ov67_id);
    GF_OVERLAY_Load((sptr)ov177_id);
    BATTLE_CHAMPIONSHIP_FLOW_CreateGraphic(work);
    BATTLE_CHAMPIONSHIP_FLOW_CreateView(work);
    BATTLE_CHAMPIONSHIP_FLOW_CreateText(work);
    work->proc=WIFIBATTLEMATCH_UTIL_CreateCallback(work, BATTLE_CHAMPIONSHIP_FLOW_FadeIn,0x4e);
    return 1;
}

int BATTLE_CHAMPIONSHIP_FLOW_Delete(void *owner, int unused, int unused2, BattleChampionshipFlowWork *work)
{
    WIFIBATTLEMATCH_UTIL_DeleteCallback(work->proc);
    BATTLE_CHAMPIONSHIP_FLOW_DeleteText(work);
    BATTLE_CHAMPIONSHIP_FLOW_DeleteView(work);
    BATTLE_CHAMPIONSHIP_FLOW_DeleteGraphic(work);
    GF_OVERLAY_Unload((sptr)ov177_id);
    GF_OVERLAY_Unload((sptr)ov67_id);
    PROCSYS_FreeProcWork(owner);
    GFL_HEAP_DeleteChecked(0x4e);
    return 1;
}

int BATTLE_CHAMPIONSHIP_FLOW_IsFinished(u32 unused,u32 unused2,u32 unused3,BattleChampionshipFlowWork *work) {BATTLE_CHAMPIONSHIP_FLOW_ReleaseGraphic(work);BATTLE_CHAMPIONSHIP_FLOW_UpdateText(work);WIFIBATTLEMATCH_UTIL_InvokeCallback(work->proc);if(WIFIBATTLEMATCH_UTIL_IsCallbackNull(work->proc)) return 1;return 0;}

void BATTLE_CHAMPIONSHIP_FLOW_CreateGraphic(BattleChampionshipFlowWork *work)
{
    work->graphic = WIFIBATTLEMATCH_GRAPHIC_Create(1, work->heapId);
}

void BATTLE_CHAMPIONSHIP_FLOW_DeleteGraphic(BattleChampionshipFlowWork *work)
{
    WIFIBATTLEMATCH_GRAPHIC_Delete(work->graphic);
    work->graphic = 0;
}

void BATTLE_CHAMPIONSHIP_FLOW_ReleaseGraphic(BattleChampionshipFlowWork *work)
{
    if (work->graphic) {
        WIFIBATTLEMATCH_GRAPHIC_Draw(work->graphic);
        WIFIBATTLEMATCH_VIEW_UpdateAnimation(work->view);
    }
}

/*
 *   WIFIBATTLEMATCH_GRAPHIC_GetCamera (0x021E5548) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
void BATTLE_CHAMPIONSHIP_FLOW_CreateView(BattleChampionshipFlowWork *work)
{
    work->view = WIFIBATTLEMATCH_VIEW_Create(WIFIBATTLEMATCH_GRAPHIC_GetCamera(work->graphic), 1, work->heapId);
}

void BATTLE_CHAMPIONSHIP_FLOW_DeleteView(BattleChampionshipFlowWork *work) {WIFIBATTLEMATCH_VIEW_Delete(work->view);}

/*
 * trailing: two bytes alignment padding at 0x0217AF9A.
 */
void BATTLE_CHAMPIONSHIP_FLOW_CreateText(BattleChampionshipFlowWork *work)
{
    work->font=GF_FONT_Create(0x17,0,0,0,work->heapId);
    work->msgBank=MSGDATA_CreateFromArchive(0,2,BATTLE_CHAMPIONSHIP_MSG_ARC,work->heapId);
    work->printQue=PRINTSYS_QUE_Create((unsigned int)(work->heapId));
    work->printSys=WIFIBATTLEMATCH_UTIL_Create((int)0,(int)15,14,10,work->printQue,work->font,work->heapId);
}

void BATTLE_CHAMPIONSHIP_FLOW_DeleteText(BattleChampionshipFlowWork *work)
{
    WIFIBATTLEMATCH_UTIL_Delete(work->printSys);
    PRINTSYS_QUE_Delete(work->printQue);
    MSGDATA_Delete(work->msgBank);
    GF_FONT_Delete(work->font);
}

void BATTLE_CHAMPIONSHIP_FLOW_UpdateText(BattleChampionshipFlowWork *work)
{
    WIFIBATTLEMATCH_UTIL_Main(work->printSys);
    PRINTSYS_QUE_Main(work->printQue);
}

void BATTLE_CHAMPIONSHIP_FLOW_SelectFlow(WifibattlematchCallback *proc, int *unused, void *workArg)
{
    BattleChampionshipFlowWork *work = workArg;
    switch(((BattleChampionshipFlowContext *)(*(char * *)&work->context))->mode){
    case 0: case 1: case 2:
        WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_StartMenu); break;
    case 3: case 4: case 5: case 6:
        WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_StartLiveMatch); break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_End(WifibattlematchCallback *proc, int *unusedState, void *unusedWork)
{
    WIFIBATTLEMATCH_UTIL_ClearCallback(proc);
}

void BATTLE_CHAMPIONSHIP_FLOW_FadeIn(WifibattlematchCallback *proc, int *state, void *workArg)
{
    BattleChampionshipFlowMenu *work = workArg;
    switch(*state){
    case 0: FADE_Start(3,16,0,0); *state=1; break;
    case 1: if(!FADE_IsActive()) *state=2; break;
    case 2: WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_SelectFlow); break;
    default: GF_PANIC_Fail(PM_LANG_JA(d_0217E5E0, str_ja_0217E560),PM_SRC_LINE(0, 0x160),PM_LANG_JA(d_0217E5E0, str_ja_0217E57C)); break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_FadeOut(WifibattlematchCallback *proc, int *state, void *workArg)
{
    BattleChampionshipFlowWork *work = workArg;
    int fadeMode;
    switch(*state){
    case 0:
        if(((BattleChampionshipFlowContext *)(*(char * *)&work->context))->state==0){GFL_USE_FadeOutBgm(6);fadeMode=12;}else fadeMode=3;
        FADE_Start(fadeMode,0,16,0);
        *state=1;
        break;
    case 1: if(!FADE_IsActive()) *state=2; break;
    case 2: WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_End); break;
    default: GF_PANIC_Fail(PM_LANG_JA(d_0217E5E0, str_ja_0217E560),PM_SRC_LINE(0, 0x191),PM_LANG_JA(d_0217E5E0, str_ja_0217E57C)); break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_StartMenu(WifibattlematchCallback *proc, int *state, void *workArg)
{
    BattleChampionshipFlowWork *work = workArg;
    RequestConfig config;
    switch(*state) {
    case 0:
        MI_CpuFill8(&config,0,sizeof(config));
        config.printSys=work->printSys;
        config.font=work->font;
        config.msgBank=work->msgBank;
        config.printQue=work->printQue;
        config.view=work->view;
        config.graphic=work->graphic;
        config.save=work->context->save;
        if(work->useAltFlow!=0) {work->useAltFlow=0;config.slot=2;}
        else {
            switch(work->context->mode) {
            case 0: config.slot=0;break;
            case 1: config.slot=1;break;
            }
        }
        work->flow=BATTLE_CHAMPIONSHIP_FLOW_CreateMenu(&config,78);
        (*state)++;
        break;
    case 1:
        BATTLE_CHAMPIONSHIP_FLOW_InvokeCallback((struct WifibattlematchCallback * *)(work->flow));
        switch(BATTLE_CHAMPIONSHIP_FLOW_GetMenuResult(work->flow)) {
        case 1: work->context->state=0;*state=2;break;
        case 2: work->context->state=1;*state=2;break;
        case 3: work->context->mode=3;*state=3;break;
        }
        break;
    case 2:
        BATTLE_CHAMPIONSHIP_FLOW_DeleteMenu(work->flow);
        WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_FadeOut);
        break;
    case 3:
        BATTLE_CHAMPIONSHIP_FLOW_DeleteMenu(work->flow);
        WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_StartLiveMatch);
        break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_StartLiveMatch(WifibattlematchCallback *proc, int *state, void *workArg)
{
    BattleChampionshipFlowWork *work = workArg;
    LiveBattleMatchInit config;
    switch(*state) {
    case 0:
        MI_CpuFill8(&config,0,sizeof(config));
        config.printSys=work->printSys;
        config.font=work->font;
        config.printQue=work->printQue;
        config.view=work->view;
        config.graphic=work->graphic;
        config.save=work->context->save;
        config.battleData=work->context->battleData;
        config.partyData=work->context->partyData;
        config.stateObj=work->context->stateObj;
        switch(work->context->mode) {
        case 3: config.mode=0;break;
        case 4: config.mode=2;break;
        case 5: config.mode=3;break;
        case 6: config.mode=1;break;
        default: config.mode=0;break;
        }
        work->flow=LIVEBATTLEMATCH_FLOW_Create(&config, 78);
        (*state)++;
        break;
    case 1:
        LIVEBATTLEMATCH_FLOW_Release(work->flow);
        switch(LIVEBATTLEMATCH_FLOW_GetResult(work->flow)) {
        case 1: *state=3;break;
        case 2: work->context->state=2;*state=2;break;
        case 3: work->context->state=3;*state=2;break;
        case 4: work->context->state=4;*state=2;break;
        }
        break;
    case 2:
        LIVEBATTLEMATCH_FLOW_Delete(work->flow);
        WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_FadeOut);
        break;
    case 3:
        work->useAltFlow=1;
        LIVEBATTLEMATCH_FLOW_Delete(work->flow);
        WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_StartMenu);
        break;
    }
}


