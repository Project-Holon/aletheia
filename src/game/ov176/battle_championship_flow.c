/*
 * file:     battle_championship_flow.c
 * unit:     yes
 * function: selected, BATTLE_CHAMPIONSHIP_FLOW_CreateMenu, BATTLE_CHAMPIONSHIP_FLOW_DeleteMenu, BATTLE_CHAMPIONSHIP_FLOW_InvokeCallback, BATTLE_CHAMPIONSHIP_FLOW_GetMenuResult, BATTLE_CHAMPIONSHIP_FLOW_SelectMenuPhase, BATTLE_CHAMPIONSHIP_FLOW_EndMenu, BATTLE_CHAMPIONSHIP_FLOW_MenuMain, BATTLE_CHAMPIONSHIP_FLOW_MenuConfirm, BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse, BATTLE_CHAMPIONSHIP_FLOW_MenuClose, BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck1, BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck2, BATTLE_CHAMPIONSHIP_FLOW_MenuExtra, BATTLE_CHAMPIONSHIP_FLOW_MenuExtraConfirm, BATTLE_CHAMPIONSHIP_FLOW_MenuExtraBrowse, BATTLE_CHAMPIONSHIP_FLOW_DrawMenu, BATTLE_CHAMPIONSHIP_FLOW_HideWindow, BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult, BATTLE_CHAMPIONSHIP_FLOW_SetOption, BATTLE_CHAMPIONSHIP_FLOW_SetExtraOption, BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone, BATTLE_CHAMPIONSHIP_FLOW_FinishMenu
 * address:  0x0217B2E4
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

#include "livebattlematch_flow.h"
#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_0217E560[];
extern const char str_ja_0217E57C[];
#endif


extern char ov67_id[],ov177_id[];

extern char ov67_id[];

extern const char d_0217E5E0[];

extern const char d_0217E5E4[];


void *BATTLE_CHAMPIONSHIP_FLOW_CreateMenu(const RequestConfig *config,u16 heap)
{
    char *menu;
    menu=GFL_HEAP_Alloc(heap,0x3c,0,d_0217E5E4,0xaf);
    MI_CpuFill8(menu,0,0x3c);
    ((BattleChampionshipFlowMenu *)menu)->config=*config;
    ((BattleChampionshipFlowMenu *)menu)->heapId=heap;
    ((BattleChampionshipFlowMenu *)menu)->msgBank=MSGDATA_CreateFromArchive(0,3,0x9e,heap);
    ((BattleChampionshipFlowMenu *)menu)->proc=WIFIBATTLEMATCH_UTIL_CreateCallback(menu, BATTLE_CHAMPIONSHIP_FLOW_SelectMenuPhase,heap);
    return menu;
}

void BATTLE_CHAMPIONSHIP_FLOW_DeleteMenu(BattleChampionshipFlowMenu *work) {WIFIBATTLEMATCH_UTIL_DeleteCallback((work->proc));MSGDATA_Delete(work->msgBank);GFL_HEAP_Free(work);}

/*
 * leaf: sole blocker of owned 0217B0C8 MATCH; no prior source/unit/shard, parent claim accepted.
 */
void BATTLE_CHAMPIONSHIP_FLOW_InvokeCallback(struct WifibattlematchCallback **callback)
{
    WIFIBATTLEMATCH_UTIL_InvokeCallback(*callback);
}

/*
 *   WIFIBATTLEMATCH_UTIL_IsCallbackNull (0x021E8A90) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
int BATTLE_CHAMPIONSHIP_FLOW_GetMenuResult(BattleChampionshipFlowMenu *work)
{
    if (WIFIBATTLEMATCH_UTIL_IsCallbackNull(work->proc))
        return work->result;
    return 0;
}

void BATTLE_CHAMPIONSHIP_FLOW_SelectMenuPhase(WifibattlematchCallback *proc, int *unused, void *workArg)
{
    BattleChampionshipFlowMenu *work = workArg;
    switch (work->config.slot) {
    case 0:
        WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuMain);
        break;
    case 1:
        WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse);
        break;
    case 2:
        WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuExtra);
        break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_EndMenu(WifibattlematchCallback *proc, int *unusedState, void *unusedWork) {WIFIBATTLEMATCH_UTIL_ClearCallback((void *)proc);}

void BATTLE_CHAMPIONSHIP_FLOW_MenuMain(WifibattlematchCallback *proc, int *state, void *workArg)
{
    BattleChampionshipFlowMenu *work = workArg;
    unsigned result;
    switch (*state) {
    case 0: BATTLE_CHAMPIONSHIP_FLOW_SetOption(work,0); *state = 1; break;
    case 1: if (BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(work) == 1) *state = 2; break;
    case 2: BATTLE_CHAMPIONSHIP_FLOW_DrawMenu(work,0); *state = 3; break;
    case 3:
        result = BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult(work);
        if (result != -1) {
            switch (result) {
            case 0: WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse); break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuExtra); break;
            case 2: WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuConfirm); break;
            case 3: BATTLE_CHAMPIONSHIP_FLOW_FinishMenu(work,1); break;
            }
            BATTLE_CHAMPIONSHIP_FLOW_HideWindow(work);
        }
        break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_MenuConfirm(WifibattlematchCallback *proc, int *state, void *workArg) { BattleChampionshipFlowMenu *work = workArg;switch(*state) {case 0:BATTLE_CHAMPIONSHIP_FLOW_SetOption(work,1);*state=1;break;case 1:if(BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(work)==1) WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuMain);break;}}

/*
 * extent: stale 0217B550 data label splits its final twelve pool bytes; real next function is separately filed 0217B55C.
 */
void BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse(WifibattlematchCallback *proc, int *state, void *workArg)
{
    BattleChampionshipFlowMenu *work = workArg;
    unsigned result;
    switch (*state) {
    case 0: BATTLE_CHAMPIONSHIP_FLOW_SetOption(work,9); *state=1; break;
    case 1: if(BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(work)==1) *state=2; break;
    case 2: BATTLE_CHAMPIONSHIP_FLOW_DrawMenu(work,1); *state=3; break;
    case 3:
        result=BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult(work);
        if(result!=-1) {
            switch(result) {
            case 0:
                if(APP_ENV_IsWirelessAvailable()==0) WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuExtraBrowse);
                else {BATTLE_REC_ClearWork(); BATTLE_CHAMPIONSHIP_FLOW_FinishMenu(work,2);}
                break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuClose); break;
            case 2: WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck1); break;
            case 3: WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuMain); break;
            }
            BATTLE_CHAMPIONSHIP_FLOW_HideWindow(work);
        }
        break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_MenuClose(WifibattlematchCallback *proc, int *state, void *workArg)
{
    BattleChampionshipFlowMenu *work = workArg;
    switch(*state) {
    case 0: BATTLE_CHAMPIONSHIP_FLOW_SetOption(work,8); *state=1; break;
    case 1: if(BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(work)==1) WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse); break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck1(WifibattlematchCallback *proc, int *state, void *workArg)
{
    BattleChampionshipFlowMenu *work = workArg;
    RequestConfig config;
    switch (*state) {
    case 0:
        MI_CpuFill8(&config, 0, sizeof(config));
        config.slot = 0;
        config.printSys = work->config.printSys;
        config.font = work->config.font;
        config.msgBank = work->config.msgBank;
        config.printQue = work->config.printQue;
        config.view = work->config.view;
        config.graphic = work->config.graphic;
        config.save = work->config.save;
        work->cardCheck = DIGITALCARDCHECK_Create(&config, work->heapId);
        (*state)++;
        break;
    case 1:
        DIGITALCARDCHECK_DeleteAlt(work->cardCheck);
        if (DIGITALCARDCHECK_GetProcResult(work->cardCheck)) (*state)++;
        break;
    case 2:
        DIGITALCARDCHECK_Delete(work->cardCheck);
        WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse);
        break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck2(WifibattlematchCallback *proc, int *state, void *workArg)
{
    BattleChampionshipFlowMenu *work = workArg;
    RequestConfig config;
    switch (*state) {
    case 0:
        MI_CpuFill8(&config, 0, sizeof(config));
        config.slot = 1;
        config.printSys = work->config.printSys;
        config.font = work->config.font;
        config.msgBank = work->config.msgBank;
        config.printQue = work->config.printQue;
        config.view = work->config.view;
        config.graphic = work->config.graphic;
        config.save = work->config.save;
        work->cardCheck = DIGITALCARDCHECK_Create(&config, work->heapId);
        (*state)++;
        break;
    case 1:
        DIGITALCARDCHECK_DeleteAlt(work->cardCheck);
        if (DIGITALCARDCHECK_GetProcResult(work->cardCheck)) (*state)++;
        break;
    case 2:
        DIGITALCARDCHECK_Delete(work->cardCheck);
        WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuExtra);
        break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_MenuExtra(WifibattlematchCallback *proc, int *state, void *workArg)
{
    BattleChampionshipFlowMenu *work = workArg;
    unsigned result;
    switch (*state) {
    case 0: BATTLE_CHAMPIONSHIP_FLOW_SetOption(work,14); *state=1; break;
    case 1: if(BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(work)==1) *state=2; break;
    case 2: BATTLE_CHAMPIONSHIP_FLOW_DrawMenu(work,2); *state=3; break;
    case 3:
        result=BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult(work);
        if(result!=-1) {
            switch(result) {
            case 0:
                if(APP_ENV_IsWirelessAvailable()==0) WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuExtraBrowse);
                else {BATTLE_REC_ClearWork(); BATTLE_CHAMPIONSHIP_FLOW_FinishMenu(work,3);}
                break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuExtraConfirm); break;
            case 2: WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck2); break;
            case 3: WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuMain); break;
            }
            BATTLE_CHAMPIONSHIP_FLOW_HideWindow(work);
        }
        break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_MenuExtraConfirm(WifibattlematchCallback *proc, int *state, void *workArg) { BattleChampionshipFlowMenu *work = workArg;switch(*state) {case 0:BATTLE_CHAMPIONSHIP_FLOW_SetOption(work,15);*state=1;break;case 1:if(BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(work)==1) WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuExtra);break;}}

void BATTLE_CHAMPIONSHIP_FLOW_MenuExtraBrowse(WifibattlematchCallback *proc, int *state, void *workArg) { BattleChampionshipFlowMenu *work = workArg;switch(*state) {case 0:BATTLE_CHAMPIONSHIP_FLOW_SetExtraOption(work,22);*state=1;break;case 1:if(BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(work)==1) WIFIBATTLEMATCH_UTIL_SetCallback(proc, BATTLE_CHAMPIONSHIP_FLOW_MenuMain);break;}}

static inline void selected(WifibattlematchMenuDesc *rec,void *cardBase,int index)
{
    char *card;
    card=(char *)REGULATION_GetCard(cardBase,index);
    rec->items[0]=7;
    rec->items[1]=5;
    if((u8)(s8)(((struct RegulationCard *)card)->bgm-1)<=1) rec->items[2]=13;
    else rec->items[2]=4;
    rec->items[3]=6;
    rec->count=4;
    rec->enabled=1;
    rec->kind=3;
}

/*
 * extent: following 0217B924 and 0217B930 tail-call stubs already have separate matched shards; lead only.
 * lever: descriptor assignments in member order fix constant scheduling; coordinates are u8, height u32 with logical shift and no outgoing truncation.
 * abi: E88B0 height widened from its narrow body spelling because original stores the full computed register into the outgoing slot.
 */
void BATTLE_CHAMPIONSHIP_FLOW_DrawMenu(BattleChampionshipFlowMenu *work, int index)
{
    WifibattlematchMenuDesc rec;
    void *cardBase;
    int layout;
    u8 x,y,width;
    u32 height;
    cardBase=BATTLE_COMPETITION_GetFromSave((void *)GAME_DATA_GetSaveControl(work->config.save));
    MI_CpuFill8(&rec,0,sizeof(rec));
    rec.msgBank=work->config.msgBank;
    rec.font=work->config.font;
    rec.printQue=work->config.printQue;
    switch(index) {
    case 0:
        rec.items[0]=2;rec.items[1]=3;rec.items[2]=5;rec.items[3]=6;rec.count=4;rec.enabled=1;rec.kind=3;layout=0;break;
    case 1: selected(&rec,cardBase,0);layout=0;break;
    case 2: selected(&rec,cardBase,1);layout=0;break;
    case 3:
        rec.items[0]=11;rec.items[1]=12;rec.count=2;layout=1;rec.enabled=1;rec.kind=1;break;
    }
    rec.a=0;rec.b=15;rec.c=13;rec.d=1;
    switch(layout) {
    case 0: width=28;height=(rec.count&127)*2;x=2;y=9-(height>>1);break;
    case 1: width=12;height=(rec.count&127)*2;x=19;y=17-height;break;
    }
    work->window=WIFIBATTLEMATCH_UTIL_CreateMenu(&rec, x, y, width, height, work->heapId);
    work->index=index;
}

void BATTLE_CHAMPIONSHIP_FLOW_HideWindow(BattleChampionshipFlowMenu *work) {WIFIBATTLEMATCH_UTIL_DeleteMenu(work->window);}

unsigned BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult(BattleChampionshipFlowMenu *work) {return WIFIBATTLEMATCH_UTIL_UpdateMenu(work->window);}

void BATTLE_CHAMPIONSHIP_FLOW_SetOption(BattleChampionshipFlowMenu *work, int option)
{
    WIFIBATTLEMATCH_UTIL_PrintMessage(work->config.printSys, work->config.msgBank, option, 1);
}

void BATTLE_CHAMPIONSHIP_FLOW_SetExtraOption(BattleChampionshipFlowMenu *work, int option)
{
    WIFIBATTLEMATCH_UTIL_PrintMessage(work->config.printSys, work->msgBank, option, 1);
}

int BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(BattleChampionshipFlowMenu *work) {return WIFIBATTLEMATCH_UTIL_GetBusy(work->config.printSys);}

void BATTLE_CHAMPIONSHIP_FLOW_FinishMenu(BattleChampionshipFlowMenu *work,int result) {work->result=result;WIFIBATTLEMATCH_UTIL_SetCallback(work->proc, BATTLE_CHAMPIONSHIP_FLOW_EndMenu);}
