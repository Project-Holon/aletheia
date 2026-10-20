/*
 * file:     battle_championship_flow.c
 * unit:     yes
 * function: BATTLE_CHAMPIONSHIP_FLOW_Create, BATTLE_CHAMPIONSHIP_FLOW_Delete, BATTLE_CHAMPIONSHIP_FLOW_IsFinished, BATTLE_CHAMPIONSHIP_FLOW_CreateGraphic, BATTLE_CHAMPIONSHIP_FLOW_DeleteGraphic, BATTLE_CHAMPIONSHIP_FLOW_ReleaseGraphic, BATTLE_CHAMPIONSHIP_FLOW_CreateView, BATTLE_CHAMPIONSHIP_FLOW_DeleteView, BATTLE_CHAMPIONSHIP_FLOW_CreateText, BATTLE_CHAMPIONSHIP_FLOW_DeleteText, BATTLE_CHAMPIONSHIP_FLOW_UpdateText, BATTLE_CHAMPIONSHIP_FLOW_SelectFlow, BATTLE_CHAMPIONSHIP_FLOW_End, BATTLE_CHAMPIONSHIP_FLOW_FadeIn, BATTLE_CHAMPIONSHIP_FLOW_FadeOut, BATTLE_CHAMPIONSHIP_FLOW_StartMenu, BATTLE_CHAMPIONSHIP_FLOW_StartLiveMatch, BATTLE_CHAMPIONSHIP_FLOW_CreateMenu, BATTLE_CHAMPIONSHIP_FLOW_DeleteMenu, BATTLE_CHAMPIONSHIP_FLOW_InvokeCallback, BATTLE_CHAMPIONSHIP_FLOW_GetMenuResult, BATTLE_CHAMPIONSHIP_FLOW_SelectMenuPhase, BATTLE_CHAMPIONSHIP_FLOW_EndMenu, BATTLE_CHAMPIONSHIP_FLOW_MenuMain, BATTLE_CHAMPIONSHIP_FLOW_MenuConfirm, BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse, BATTLE_CHAMPIONSHIP_FLOW_MenuClose, BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck1, BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck2, BATTLE_CHAMPIONSHIP_FLOW_MenuExtra, BATTLE_CHAMPIONSHIP_FLOW_MenuExtraConfirm, BATTLE_CHAMPIONSHIP_FLOW_MenuExtraBrowse, BATTLE_CHAMPIONSHIP_FLOW_DrawMenu, BATTLE_CHAMPIONSHIP_FLOW_HideWindow, BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult, BATTLE_CHAMPIONSHIP_FLOW_SetOption, BATTLE_CHAMPIONSHIP_FLOW_SetExtraOption, BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone, BATTLE_CHAMPIONSHIP_FLOW_FinishMenu
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
 */
#include "livebattlematch_shared_types.h"

struct ProcOwner;

struct Proc;

struct PrintSys;

/* The caller supplied context (only the fields this file reads). */
typedef struct {
    void *save;          /* 00 save control handed to GAME_DATA_GetSaveControl */
    int mode;            /* 04 selects the first flow handler */
    int state;           /* 08 extra state the menu flow reports back */
    void *battleData;    /* 0C copied into the live match 0x1BC slot */
    void *partyData;     /* 10 copied into the live match 0x1C0 slot */
    void *stateObj;      /* 14 copied into the live match 0x1C4 slot */
} BattleChampionshipFlowContext;

/* The championship flow proc work (0x34 bytes), the object every handler
 * of the first flow (BATTLE_CHAMPIONSHIP_FLOW_Create .. BATTLE_CHAMPIONSHIP_FLOW_CreateText) receives. */
typedef struct {
    u16 heapId;          /* 00 heap the flow runs on (0x4e) */
    u8  pad_2[2];
    void *proc;          /* 04 sub proc created by WIFIBATTLEMATCH_UTIL_CreateCallback */
    void *printSys;      /* 08 print system created by WIFIBATTLEMATCH_UTIL_Create */
    void *font;          /* 0C font created by GF_FONT_Create */
    void *msgBank;       /* 10 message bank created by MSGDATA_CreateFromArchive */
    void *printQue;      /* 14 print queue created by PRINTSYS_QUE_Create */
    u8  pad_18[8];
    int view;            /* 20 view object created by WIFIBATTLEMATCH_VIEW_Create */
    int graphic;         /* 24 graphic object created by WIFIBATTLEMATCH_GRAPHIC_Create */
    BattleChampionshipFlowContext *context; /* 28 the caller supplied context */
    int flow;            /* 2C the second flow object (menu or live match) */
    int useAltFlow;      /* 30 non zero selects the live battle match flow */
} BattleChampionshipFlowWork;

/* The menu work of the first flow (0x3c bytes), built by BATTLE_CHAMPIONSHIP_FLOW_CreateMenu and
 * driven by the BATTLE_CHAMPIONSHIP_FLOW_MenuMain / BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse / BATTLE_CHAMPIONSHIP_FLOW_MenuExtra state machines. */
typedef struct {
    void *proc;          /* 00 proc created by WIFIBATTLEMATCH_UTIL_CreateCallback */
    void *window;        /* 04 window returned by WIFIBATTLEMATCH_UTIL_CreateMenu */
    int index;           /* 08 index last drawn */
    void *msgBank;       /* 0C message bank created by MSGDATA_CreateFromArchive */
    int result;          /* 10 menu result read by BATTLE_CHAMPIONSHIP_FLOW_GetMenuResult */
    int phase;           /* 14 phase selected by BATTLE_CHAMPIONSHIP_FLOW_SelectMenuPhase */
    void *printSys;      /* 18 print system (copied from the flow work) */
    void *font;          /* 1C font (copied from the flow work) */
    void *msgBank2;      /* 20 message bank (copied from the flow work) */
    void *printQue;      /* 24 print queue (copied from the flow work) */
    void *view;          /* 28 view (copied from the flow work) */
    void *graphic;       /* 2C graphic (copied from the flow work) */
    void *save;          /* 30 save control (from the context) */
    u16 heapId;          /* 34 heap the menu runs on */
    u8  pad_36[2];
    int cardCheck;       /* 38 digital card check created by DIGITALCARDCHECK_Create */
} BattleChampionshipFlowMenu;

/* 32-byte menu/flow descriptor passed to BATTLE_CHAMPIONSHIP_FLOW_CreateMenu and DIGITALCARDCHECK_Create. */
typedef struct {
    int mode;            /* 00 */
    int printSys;        /* 04 */
    int font;            /* 08 */
    int msgBank;         /* 0C */
    int printQue;        /* 10 */
    int view;            /* 14 */
    int graphic;         /* 18 */
    int save;            /* 1C */
} BattleChampionshipFlowConfig;

#include "../arm9/gfl_heap.h"

#include "../arm9/procsys.h"

#include "../arm9/mi_memory.h"

#include "../arm9/gf_overlay.h"
struct WifibattlematchCallback;

#include "../ov177/wifibattlematch_util.h"




#include "../arm9/gfl_heap_wrap.h"

extern void BATTLE_CHAMPIONSHIP_FLOW_ReleaseGraphic(int *),BATTLE_CHAMPIONSHIP_FLOW_UpdateText(int *);


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





int BATTLE_CHAMPIONSHIP_FLOW_Create(void *a,void *b,void *context);

int BATTLE_CHAMPIONSHIP_FLOW_Delete(int a, int b, int c, int *p);

int BATTLE_CHAMPIONSHIP_FLOW_IsFinished(u32 a,u32 b,u32 c,int *p);

void BATTLE_CHAMPIONSHIP_FLOW_CreateGraphic(int *p);

void BATTLE_CHAMPIONSHIP_FLOW_DeleteGraphic(int *p);

void BATTLE_CHAMPIONSHIP_FLOW_ReleaseGraphic(int *p);

void BATTLE_CHAMPIONSHIP_FLOW_CreateView(int *p);

void BATTLE_CHAMPIONSHIP_FLOW_DeleteView(int *p);

void BATTLE_CHAMPIONSHIP_FLOW_CreateText(char *p);

void BATTLE_CHAMPIONSHIP_FLOW_DeleteText(int *p);

void BATTLE_CHAMPIONSHIP_FLOW_UpdateText(int *p);

void BATTLE_CHAMPIONSHIP_FLOW_SelectFlow(void *a,int b,char *p);

void BATTLE_CHAMPIONSHIP_FLOW_End(void *a);

void BATTLE_CHAMPIONSHIP_FLOW_FadeIn(void *a,int *state,char *p);

void BATTLE_CHAMPIONSHIP_FLOW_FadeOut(void *a,int *state,char *p);

void BATTLE_CHAMPIONSHIP_FLOW_StartMenu(int *a,int *state,BattleChampionshipFlowWork *p);

void BATTLE_CHAMPIONSHIP_FLOW_StartLiveMatch(int *a,int *state,BattleChampionshipFlowWork *p);

void *BATTLE_CHAMPIONSHIP_FLOW_CreateMenu(const BattleChampionshipFlowConfig *src,u16 heap);

void BATTLE_CHAMPIONSHIP_FLOW_DeleteMenu(int *p);

void BATTLE_CHAMPIONSHIP_FLOW_InvokeCallback(struct WifibattlematchCallback **p);

int BATTLE_CHAMPIONSHIP_FLOW_GetMenuResult(int *p);

void BATTLE_CHAMPIONSHIP_FLOW_SelectMenuPhase(int a, int b, int *p);

void BATTLE_CHAMPIONSHIP_FLOW_EndMenu(int p);

void BATTLE_CHAMPIONSHIP_FLOW_MenuMain(int p, unsigned *state, int *q);

void BATTLE_CHAMPIONSHIP_FLOW_MenuConfirm(int *p,int *state,u8 *q);

void BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse(int p,unsigned *state,int *q);

void BATTLE_CHAMPIONSHIP_FLOW_MenuClose(int p,int *state,int *q);

void BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck1(int p, int *state, char *q);

void BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck2(int p, int *state, char *q);

void BATTLE_CHAMPIONSHIP_FLOW_MenuExtra(int p,unsigned *state,int *q);

void BATTLE_CHAMPIONSHIP_FLOW_MenuExtraConfirm(int *p,int *state,u8 *q);

void BATTLE_CHAMPIONSHIP_FLOW_MenuExtraBrowse(int *p,int *state,u8 *q);

void BATTLE_CHAMPIONSHIP_FLOW_DrawMenu(int *p, int index);

void BATTLE_CHAMPIONSHIP_FLOW_HideWindow(int *p);

unsigned BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult(int *p);

void BATTLE_CHAMPIONSHIP_FLOW_SetOption(int *p, int b);

void BATTLE_CHAMPIONSHIP_FLOW_SetExtraOption(int *p, int b);

int BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(int *p);

void BATTLE_CHAMPIONSHIP_FLOW_FinishMenu(int *p,int a);

#include "livebattlematch_flow.h"




extern char ov67_id[],ov177_id[];

extern char ov67_id[];

extern const char d_0217E5E0[];

extern const char d_0217E5E4[];

int BATTLE_CHAMPIONSHIP_FLOW_Create(void *owner,void *unused,void *context)
{
    char *work;
    GFL_HEAP_CreateChildHeap(1,0x4e,0x30200);
    work=PROCSYS_AllocProcWork(owner,0x34,0x4e);
    MI_CpuFill8(work,0,0x34);
    ((BattleChampionshipFlowWork *)work)->context=context;
    ((BattleChampionshipFlowWork *)work)->heapId=0x4e;
    GF_OVERLAY_Load((int)ov67_id);
    GF_OVERLAY_Load((int)ov177_id);
    BATTLE_CHAMPIONSHIP_FLOW_CreateGraphic((int *)work);
    BATTLE_CHAMPIONSHIP_FLOW_CreateView((int *)work);
    BATTLE_CHAMPIONSHIP_FLOW_CreateText(work);
    ((BattleChampionshipFlowWork *)work)->proc=WIFIBATTLEMATCH_UTIL_CreateCallback((int)work,(int)BATTLE_CHAMPIONSHIP_FLOW_FadeIn,0x4e);
    return 1;
}

int BATTLE_CHAMPIONSHIP_FLOW_Delete(int owner, int unused, int unused2, int *work)
{
    WIFIBATTLEMATCH_UTIL_DeleteCallback(((BattleChampionshipFlowWork *)work)->proc);
    BATTLE_CHAMPIONSHIP_FLOW_DeleteText(work);
    BATTLE_CHAMPIONSHIP_FLOW_DeleteView(work);
    BATTLE_CHAMPIONSHIP_FLOW_DeleteGraphic(work);
    GF_OVERLAY_Unload((int)ov177_id);
    GF_OVERLAY_Unload((int)ov67_id);
    PROCSYS_FreeProcWork((struct Proc *)owner);
    GFL_HEAP_DeleteChecked(0x4e);
    return 1;
}

int BATTLE_CHAMPIONSHIP_FLOW_IsFinished(u32 unused,u32 unused2,u32 unused3,int *work) {BATTLE_CHAMPIONSHIP_FLOW_ReleaseGraphic(work);BATTLE_CHAMPIONSHIP_FLOW_UpdateText(work);WIFIBATTLEMATCH_UTIL_InvokeCallback(*(struct WifibattlematchCallback * *)&((BattleChampionshipFlowWork *)work)->proc);if((struct WifibattlematchCallback *)WIFIBATTLEMATCH_UTIL_IsCallbackNull((int **)(*(int ** *)&((BattleChampionshipFlowWork *)work)->proc))) return 1;return 0;}

void BATTLE_CHAMPIONSHIP_FLOW_CreateGraphic(int *work)
{
    ((BattleChampionshipFlowWork *)work)->graphic = (int)WIFIBATTLEMATCH_GRAPHIC_Create(1, ((BattleChampionshipFlowWork *)work)->heapId);
}

void BATTLE_CHAMPIONSHIP_FLOW_DeleteGraphic(int *work)
{
    WIFIBATTLEMATCH_GRAPHIC_Delete((char *)(((BattleChampionshipFlowWork *)work)->graphic));
    ((BattleChampionshipFlowWork *)work)->graphic = 0;
}

void BATTLE_CHAMPIONSHIP_FLOW_ReleaseGraphic(int *work)
{
    if (((BattleChampionshipFlowWork *)work)->graphic) {
        WIFIBATTLEMATCH_GRAPHIC_Draw((u8 *)(((BattleChampionshipFlowWork *)work)->graphic));
        WIFIBATTLEMATCH_VIEW_UpdateAnimation((WifiBattleMatchViewAnimState *)((int)((BattleChampionshipFlowWork *)work)->view));
    }
}

/*
 *   WIFIBATTLEMATCH_GRAPHIC_GetCamera (0x021E5548) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
void BATTLE_CHAMPIONSHIP_FLOW_CreateView(int *work)
{
    ((BattleChampionshipFlowWork *)work)->view = (int)WIFIBATTLEMATCH_VIEW_Create(WIFIBATTLEMATCH_GRAPHIC_GetCamera((int *)(((BattleChampionshipFlowWork *)work)->graphic)), 1, ((BattleChampionshipFlowWork *)work)->heapId);
}

void BATTLE_CHAMPIONSHIP_FLOW_DeleteView(int *work) {WIFIBATTLEMATCH_VIEW_Delete((void *)((BattleChampionshipFlowWork *)work)->view);}

/*
 * trailing: two bytes alignment padding at 0x0217AF9A.
 */
void BATTLE_CHAMPIONSHIP_FLOW_CreateText(char *work)
{
    ((BattleChampionshipFlowWork *)work)->font=GF_FONT_Create(0x17,0,0,0,((BattleChampionshipFlowWork *)work)->heapId);
    ((BattleChampionshipFlowWork *)work)->msgBank=MSGDATA_CreateFromArchive(0,2,4,((BattleChampionshipFlowWork *)work)->heapId);
    ((BattleChampionshipFlowWork *)work)->printQue=(void *)PRINTSYS_QUE_Create((unsigned int)(((BattleChampionshipFlowWork *)work)->heapId));
    ((BattleChampionshipFlowWork *)work)->printSys=WIFIBATTLEMATCH_UTIL_Create((int)0,(int)15,14,10,(int)(((BattleChampionshipFlowWork *)work)->printQue),(int)(((BattleChampionshipFlowWork *)work)->font),((BattleChampionshipFlowWork *)work)->heapId);
}

void BATTLE_CHAMPIONSHIP_FLOW_DeleteText(int *work)
{
    WIFIBATTLEMATCH_UTIL_Delete(((BattleChampionshipFlowWork *)work)->printSys);
    PRINTSYS_QUE_Delete((struct PrintQueue *)(((BattleChampionshipFlowWork *)work)->printQue));
    MSGDATA_Delete((struct MsgBank *)(((BattleChampionshipFlowWork *)work)->msgBank));
    GF_FONT_Delete((void *)(((BattleChampionshipFlowWork *)work)->font));
}

void BATTLE_CHAMPIONSHIP_FLOW_UpdateText(int *work)
{
    WIFIBATTLEMATCH_UTIL_Main((struct WifibattlematchUtilWork *)(((BattleChampionshipFlowWork *)work)->printSys));
    PRINTSYS_QUE_Main((struct PrintQueue *)(((BattleChampionshipFlowWork *)work)->printQue));
}

void BATTLE_CHAMPIONSHIP_FLOW_SelectFlow(void *proc,int unused,char *work)
{
    switch(((BattleChampionshipFlowContext *)(*(char * *)&((BattleChampionshipFlowWork *)work)->context))->mode){
    case 0: case 1: case 2:
        WIFIBATTLEMATCH_UTIL_SetCallback(proc,(int)BATTLE_CHAMPIONSHIP_FLOW_StartMenu); break;
    case 3: case 4: case 5: case 6:
        WIFIBATTLEMATCH_UTIL_SetCallback(proc,(int)BATTLE_CHAMPIONSHIP_FLOW_StartLiveMatch); break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_End(void *proc)
{
    WIFIBATTLEMATCH_UTIL_ClearCallback(proc);
}

void BATTLE_CHAMPIONSHIP_FLOW_FadeIn(void *proc,int *state,char *work)
{
    switch(*state){
    case 0: FADE_Start(3,16,0,0); *state=1; break;
    case 1: if(!FADE_IsActive()) *state=2; break;
    case 2: WIFIBATTLEMATCH_UTIL_SetCallback(proc,(int)BATTLE_CHAMPIONSHIP_FLOW_SelectFlow); break;
    default: GF_PANIC_Fail(d_0217E5E0,0,d_0217E5E0); break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_FadeOut(void *proc,int *state,char *work)
{
    int fadeMode;
    switch(*state){
    case 0:
        if(((BattleChampionshipFlowContext *)(*(char * *)&((BattleChampionshipFlowWork *)work)->context))->state==0){GFL_USE_FadeOutBgm(6);fadeMode=12;}else fadeMode=3;
        FADE_Start(fadeMode,0,16,0);
        *state=1;
        break;
    case 1: if(!FADE_IsActive()) *state=2; break;
    case 2: WIFIBATTLEMATCH_UTIL_SetCallback(proc,(int)BATTLE_CHAMPIONSHIP_FLOW_End); break;
    default: GF_PANIC_Fail(d_0217E5E0,0,d_0217E5E0); break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_StartMenu(int *proc,int *state,BattleChampionshipFlowWork *work)
{
    BattleChampionshipFlowConfig config;
    switch(*state) {
    case 0:
        MI_CpuFill8(&config,0,32);
        config.printSys=(int)work->printSys;
        config.font=(int)work->font;
        config.msgBank=(int)work->msgBank;
        config.printQue=(int)work->printQue;
        config.view=(int)work->view;
        config.graphic=work->graphic;
        config.save=(int)work->context->save;
        if(work->useAltFlow!=0) {work->useAltFlow=0;config.mode=2;}
        else {
            switch(work->context->mode) {
            case 0: config.mode=0;break;
            case 1: config.mode=1;break;
            }
        }
        work->flow=(int)BATTLE_CHAMPIONSHIP_FLOW_CreateMenu(&config,78);
        (*state)++;
        break;
    case 1:
        BATTLE_CHAMPIONSHIP_FLOW_InvokeCallback((struct WifibattlematchCallback * *)((int *)work->flow));
        switch(BATTLE_CHAMPIONSHIP_FLOW_GetMenuResult((int *)work->flow)) {
        case 1: work->context->state=0;*state=2;break;
        case 2: work->context->state=1;*state=2;break;
        case 3: work->context->mode=3;*state=3;break;
        }
        break;
    case 2:
        BATTLE_CHAMPIONSHIP_FLOW_DeleteMenu((int *)work->flow);
        WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)proc,(int)BATTLE_CHAMPIONSHIP_FLOW_FadeOut);
        break;
    case 3:
        BATTLE_CHAMPIONSHIP_FLOW_DeleteMenu((int *)work->flow);
        WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)proc,(int)BATTLE_CHAMPIONSHIP_FLOW_StartLiveMatch);
        break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_StartLiveMatch(int *proc,int *state,BattleChampionshipFlowWork *work)
{
    LiveBattleMatchInit config;
    switch(*state) {
    case 0:
        MI_CpuFill8(&config,0,40);
        config.words[1]=(u32)work->printSys;
        config.words[2]=(u32)work->font;
        config.words[3]=(u32)work->printQue;
        config.words[4]=(u32)work->view;
        config.words[5]=(u32)work->graphic;
        config.words[6]=(u32)work->context->save;
        config.words[7]=(u32)work->context->battleData;
        config.words[8]=(u32)work->context->partyData;
        config.words[9]=(u32)work->context->stateObj;
        switch(work->context->mode) {
        case 3: config.words[0]=0;break;
        case 4: config.words[0]=2;break;
        case 5: config.words[0]=3;break;
        case 6: config.words[0]=1;break;
        default: config.words[0]=0;break;
        }
        work->flow=(int)LIVEBATTLEMATCH_FLOW_Create((LiveBattleMatchInit *)&config, 78);
        (*state)++;
        break;
    case 1:
        LIVEBATTLEMATCH_FLOW_Release((int *)work->flow);
        switch(LIVEBATTLEMATCH_FLOW_GetResult((int *)work->flow)) {
        case 1: *state=3;break;
        case 2: work->context->state=2;*state=2;break;
        case 3: work->context->state=3;*state=2;break;
        case 4: work->context->state=4;*state=2;break;
        }
        break;
    case 2:
        LIVEBATTLEMATCH_FLOW_Delete((int *)work->flow);
        WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)proc,(int)BATTLE_CHAMPIONSHIP_FLOW_FadeOut);
        break;
    case 3:
        work->useAltFlow=1;
        LIVEBATTLEMATCH_FLOW_Delete((int *)work->flow);
        WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)proc,(int)BATTLE_CHAMPIONSHIP_FLOW_StartMenu);
        break;
    }
}

void *BATTLE_CHAMPIONSHIP_FLOW_CreateMenu(const BattleChampionshipFlowConfig *config,u16 heap)
{
    char *menu;
    menu=GFL_HEAP_Alloc(heap,0x3c,0,d_0217E5E4,0xaf);
    MI_CpuFill8(menu,0,0x3c);
    *(BattleChampionshipFlowConfig *)(menu+0x14)=*config;
    ((BattleChampionshipFlowMenu *)menu)->heapId=heap;
    ((BattleChampionshipFlowMenu *)menu)->msgBank=MSGDATA_CreateFromArchive(0,3,0x9e,heap);
    ((BattleChampionshipFlowMenu *)menu)->proc=WIFIBATTLEMATCH_UTIL_CreateCallback((int)menu,(int)BATTLE_CHAMPIONSHIP_FLOW_SelectMenuPhase,heap);
    return menu;
}

void BATTLE_CHAMPIONSHIP_FLOW_DeleteMenu(int *work) {WIFIBATTLEMATCH_UTIL_DeleteCallback((((BattleChampionshipFlowMenu *)work)->proc));MSGDATA_Delete(((BattleChampionshipFlowMenu *)work)->msgBank);GFL_HEAP_Free(work);}

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
int BATTLE_CHAMPIONSHIP_FLOW_GetMenuResult(int *work)
{
    if (WIFIBATTLEMATCH_UTIL_IsCallbackNull((int **)(((BattleChampionshipFlowMenu *)work)->proc)))
        return ((BattleChampionshipFlowMenu *)work)->result;
    return 0;
}

void BATTLE_CHAMPIONSHIP_FLOW_SelectMenuPhase(int proc, int unused, int *work)
{
    switch (((BattleChampionshipFlowMenu *)work)->phase) {
    case 0:
        WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)proc), (int)BATTLE_CHAMPIONSHIP_FLOW_MenuMain);
        break;
    case 1:
        WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)proc), (int)BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse);
        break;
    case 2:
        WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)proc), (int)BATTLE_CHAMPIONSHIP_FLOW_MenuExtra);
        break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_EndMenu(int proc) {WIFIBATTLEMATCH_UTIL_ClearCallback((void *)proc);}

void BATTLE_CHAMPIONSHIP_FLOW_MenuMain(int proc, unsigned *state, int *work)
{
    unsigned result;
    switch (*state) {
    case 0: BATTLE_CHAMPIONSHIP_FLOW_SetOption(work,0); *state = 1; break;
    case 1: if (BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(work) == 1) *state = 2; break;
    case 2: BATTLE_CHAMPIONSHIP_FLOW_DrawMenu(work,0); *state = 3; break;
    case 3:
        result = BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult(work);
        if (result != -1) {
            switch (result) {
            case 0: WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)proc),(int)BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse); break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)proc),(int)BATTLE_CHAMPIONSHIP_FLOW_MenuExtra); break;
            case 2: WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)proc),(int)BATTLE_CHAMPIONSHIP_FLOW_MenuConfirm); break;
            case 3: BATTLE_CHAMPIONSHIP_FLOW_FinishMenu(work,1); break;
            }
            BATTLE_CHAMPIONSHIP_FLOW_HideWindow(work);
        }
        break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_MenuConfirm(int *proc,int *state,u8 *work) {switch(*state) {case 0:BATTLE_CHAMPIONSHIP_FLOW_SetOption((int *)work,1);*state=1;break;case 1:if(BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone((int *)work)==1) WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)proc,(int)BATTLE_CHAMPIONSHIP_FLOW_MenuMain);break;}}

/*
 * extent: stale 0217B550 data label splits its final twelve pool bytes; real next function is separately filed 0217B55C.
 */
void BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse(int proc,unsigned *state,int *work)
{
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
                if(APP_ENV_IsWirelessAvailable()==0) WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)proc),(int)BATTLE_CHAMPIONSHIP_FLOW_MenuExtraBrowse);
                else {BATTLE_REC_ClearWork(); BATTLE_CHAMPIONSHIP_FLOW_FinishMenu(work,2);}
                break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)proc),(int)BATTLE_CHAMPIONSHIP_FLOW_MenuClose); break;
            case 2: WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)proc),(int)BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck1); break;
            case 3: WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)proc),(int)BATTLE_CHAMPIONSHIP_FLOW_MenuMain); break;
            }
            BATTLE_CHAMPIONSHIP_FLOW_HideWindow(work);
        }
        break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_MenuClose(int proc,int *state,int *work)
{
    switch(*state) {
    case 0: BATTLE_CHAMPIONSHIP_FLOW_SetOption(work,8); *state=1; break;
    case 1: if(BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone((int *)work)==1) WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)proc),(int)BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse); break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck1(int proc, int *state, char *work)
{
    BattleChampionshipFlowConfig config;
    switch (*state) {
    case 0:
        MI_CpuFill8(&config, 0, 32);
        config.mode = 0;
        config.printSys = (int)((BattleChampionshipFlowMenu *)work)->printSys;
        config.font = (int)((BattleChampionshipFlowMenu *)work)->font;
        config.msgBank = (int)((BattleChampionshipFlowMenu *)work)->msgBank2;
        config.printQue = (int)((BattleChampionshipFlowMenu *)work)->printQue;
        config.view = (int)((BattleChampionshipFlowMenu *)work)->view;
        config.graphic = (int)((BattleChampionshipFlowMenu *)work)->graphic;
        config.save = (int)((BattleChampionshipFlowMenu *)work)->save;
        ((BattleChampionshipFlowMenu *)work)->cardCheck = (int)DIGITALCARDCHECK_Create((RequestConfig *)&config, ((BattleChampionshipFlowMenu *)work)->heapId);
        (*state)++;
        break;
    case 1:
        DIGITALCARDCHECK_DeleteAlt((int *)(((BattleChampionshipFlowMenu *)work)->cardCheck));
        if (DIGITALCARDCHECK_GetProcResult((int *)(((BattleChampionshipFlowMenu *)work)->cardCheck))) (*state)++;
        break;
    case 2:
        DIGITALCARDCHECK_Delete((int *)(((BattleChampionshipFlowMenu *)work)->cardCheck));
        WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)proc), (int)BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse);
        break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck2(int proc, int *state, char *work)
{
    BattleChampionshipFlowConfig config;
    switch (*state) {
    case 0:
        MI_CpuFill8(&config, 0, 32);
        config.mode = 1;
        config.printSys = (int)((BattleChampionshipFlowMenu *)work)->printSys;
        config.font = (int)((BattleChampionshipFlowMenu *)work)->font;
        config.msgBank = (int)((BattleChampionshipFlowMenu *)work)->msgBank2;
        config.printQue = (int)((BattleChampionshipFlowMenu *)work)->printQue;
        config.view = (int)((BattleChampionshipFlowMenu *)work)->view;
        config.graphic = (int)((BattleChampionshipFlowMenu *)work)->graphic;
        config.save = (int)((BattleChampionshipFlowMenu *)work)->save;
        ((BattleChampionshipFlowMenu *)work)->cardCheck = (int)DIGITALCARDCHECK_Create((RequestConfig *)&config, ((BattleChampionshipFlowMenu *)work)->heapId);
        (*state)++;
        break;
    case 1:
        DIGITALCARDCHECK_DeleteAlt((int *)(((BattleChampionshipFlowMenu *)work)->cardCheck));
        if (DIGITALCARDCHECK_GetProcResult((int *)(((BattleChampionshipFlowMenu *)work)->cardCheck))) (*state)++;
        break;
    case 2:
        DIGITALCARDCHECK_Delete((int *)(((BattleChampionshipFlowMenu *)work)->cardCheck));
        WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)proc), (int)BATTLE_CHAMPIONSHIP_FLOW_MenuExtra);
        break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_MenuExtra(int proc,unsigned *state,int *work)
{
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
                if(APP_ENV_IsWirelessAvailable()==0) WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)proc),(int)BATTLE_CHAMPIONSHIP_FLOW_MenuExtraBrowse);
                else {BATTLE_REC_ClearWork(); BATTLE_CHAMPIONSHIP_FLOW_FinishMenu(work,3);}
                break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)proc),(int)BATTLE_CHAMPIONSHIP_FLOW_MenuExtraConfirm); break;
            case 2: WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)proc),(int)BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck2); break;
            case 3: WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)proc),(int)BATTLE_CHAMPIONSHIP_FLOW_MenuMain); break;
            }
            BATTLE_CHAMPIONSHIP_FLOW_HideWindow(work);
        }
        break;
    }
}

void BATTLE_CHAMPIONSHIP_FLOW_MenuExtraConfirm(int *proc,int *state,u8 *work) {switch(*state) {case 0:BATTLE_CHAMPIONSHIP_FLOW_SetOption((int *)work,15);*state=1;break;case 1:if(BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone((int *)work)==1) WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)proc,(int)BATTLE_CHAMPIONSHIP_FLOW_MenuExtra);break;}}

void BATTLE_CHAMPIONSHIP_FLOW_MenuExtraBrowse(int *proc,int *state,u8 *work) {switch(*state) {case 0:BATTLE_CHAMPIONSHIP_FLOW_SetExtraOption((int *)work,22);*state=1;break;case 1:if(BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone((int *)work)==1) WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)proc,(int)BATTLE_CHAMPIONSHIP_FLOW_MenuMain);break;}}

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
void BATTLE_CHAMPIONSHIP_FLOW_DrawMenu(int *work, int index)
{
    WifibattlematchMenuDesc rec;
    void *cardBase;
    int layout;
    u8 x,y,width;
    u32 height;
    cardBase=BATTLE_COMPETITION_GetFromSave((void *)GAME_DATA_GetSaveControl(((BattleChampionshipFlowMenu *)work)->save));
    MI_CpuFill8(&rec,0,48);
    rec.msgBank=(u32)((BattleChampionshipFlowMenu *)work)->msgBank2;
    rec.font=(u32)((BattleChampionshipFlowMenu *)work)->font;
    rec.printQue=(u32)((BattleChampionshipFlowMenu *)work)->printQue;
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
    ((BattleChampionshipFlowMenu *)work)->window=WIFIBATTLEMATCH_UTIL_CreateMenu(&rec, x, y, width, height, ((BattleChampionshipFlowMenu *)work)->heapId);
    ((BattleChampionshipFlowMenu *)work)->index=index;
}

void BATTLE_CHAMPIONSHIP_FLOW_HideWindow(int *work) {WIFIBATTLEMATCH_UTIL_DeleteMenu((void *)((BattleChampionshipFlowMenu *)work)->window);}

unsigned BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult(int *work) {return WIFIBATTLEMATCH_UTIL_UpdateMenu((void *)((BattleChampionshipFlowMenu *)work)->window);}

void BATTLE_CHAMPIONSHIP_FLOW_SetOption(int *work, int option)
{
    WIFIBATTLEMATCH_UTIL_PrintMessage((struct WifibattlematchUtilWork *)(*(int *)&((BattleChampionshipFlowMenu *)work)->printSys), (void *)(*(int *)&((BattleChampionshipFlowMenu *)work)->msgBank2), option, 1);
}

void BATTLE_CHAMPIONSHIP_FLOW_SetExtraOption(int *work, int option)
{
    WIFIBATTLEMATCH_UTIL_PrintMessage((struct WifibattlematchUtilWork *)(*(int *)&((BattleChampionshipFlowMenu *)work)->printSys), ((BattleChampionshipFlowMenu *)work)->msgBank, option, 1);
}

int BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(int *work) {return WIFIBATTLEMATCH_UTIL_GetBusy((const WifibattlematchUtilWork *)((struct WifibattlematchUtilWork *)(*(int * *)&((BattleChampionshipFlowMenu *)work)->printSys)));}

void BATTLE_CHAMPIONSHIP_FLOW_FinishMenu(int *work,int result) {((BattleChampionshipFlowMenu *)work)->result=result;WIFIBATTLEMATCH_UTIL_SetCallback((WifibattlematchCallback *)((int *)((BattleChampionshipFlowMenu *)work)->proc),(int)BATTLE_CHAMPIONSHIP_FLOW_EndMenu);}
