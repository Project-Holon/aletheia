/*
 * file:     btlv_scd.c
 * unit:     yes
 * function: BTLV_SCD_Create, BTLV_SCD_CreateInput, BTLV_SCD_StartInputSlideIn, BTLV_SCD_StartInputSlideOut, BTLV_SCD_IsInputSlideDone, BTLV_SCD_OnSlideInDone, BTLV_SCD_OnSlideOutStart, BTLV_SCD_Nop, BTLV_SCD_CloseInputIfOpen, BTLV_SCD_CloseInput, BTLV_SCD_IsInputIdle, BTLV_SCD_Delete, BTLV_SCD_ClearTasks, BTLV_SCD_PushTask, BTLV_SCD_RunTask, BTLV_SCD_StartActionMenu, BTLV_SCD_StartActionMenuBackOnly, BTLV_SCD_WaitActionMenu, BTLV_SCD_StartMoveMenu, BTLV_SCD_StartRotateMenu, BTLV_SCD_WaitMoveMenu, BTLV_SCD_ReopenMenu, BTLV_SCD_StartMoveInfoMenu, BTLV_SCD_StartTargetMenu, BTLV_SCD_WaitTargetMenu, BTLV_SCD_CancelMenus, BTLV_SCD_OpenActionMenuStep, BTLV_SCD_WaitActionTouchStep, BTLV_SCD_WaitBackTouchStep, BTLV_SCD_OpenMoveMenuStep, BTLV_SCD_WaitMoveTouchStep, BTLV_SCD_OpenRotateMenuStep, BTLV_SCD_WaitRotateTouchStep, BTLV_SCD_ClearTargetSet, BTLV_SCD_SetTargetsMain, BTLV_SCD_SetTargetsAltKind1, BTLV_SCD_SetTargetsAltKind2, BTLV_SCD_AddFrontEnemyTargets, BTLV_SCD_PickTargetFromTouch, BTLV_SCD_ShowTargetMenu, BTLV_SCD_ShowTargetSetMenu, BTLV_SCD_IsTargetChosen, BTLV_SCD_OpenTargetMenuStep, BTLV_SCD_WaitTargetTouchStep, BTLV_SCD_BuildTargetSet, BTLV_SCD_ShowRotateScreen, BTLV_SCD_PollTouchKey, BTLV_SCD_CloseInputScreen, BTLV_SCD_OpenChoiceScreen, BTLV_SCD_PollChoiceScreen, BTLV_SCD_GetInputFlags, BTLV_SCD_BeginCloseSequence, BTLV_SCD_RunCloseSequence, BTLV_SCD_ShowCounterScreen, BTLV_SCD_PollCounterTouch
 * address:  0x06899AF0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Battle command select view (BTLV_SCD): the touch screen menus of one turn. Merged from
 * 27 units; types in btlv_scd_types.h.
 *
 * symbols:
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   STRBUF_Create  0x020457B0  arm
 *   BTL_SIDE_GetSlotOfClientThunk  0x021B9AF8  thumb
 *   BTL_CLIENT_GetClientId  0x021D3D70  thumb
 *   BTLV_SCD_ClearTasks  0x06899E2C  thumb  ov095
 *   gBtlvScdFileName  0x0689E7B8  data  ov095  a4
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   BTL_MAIN_GetRule  0x021B8588  thumb
 *   BTL_MAIN_GetCompetitor  0x021B86B8  thumb
 *   BTL_MAIN_GetGameData  0x021B8748  thumb
 *   BTLV_EFFECT_GetPalanm  0x021F86E0  thumb
 *   BTLV_INPUT_CreateWithMode  0x0220207C  thumb
 *   BTLV_INPUT_StartPaletteFadeTask  0x022025D8  thumb
 *   BTLV_SCD_Nop  0x06899D38  thumb  ov095
 *   BTLV_INPUT_IsScreenBusy  0x022026FC  thumb
 *   BTLV_INPUT_StartScreenFadeTask  0x0220266C  thumb  ov094
 *   BTLV_EFFECT_GaugeSelectSlot  0x021F81EC  thumb
 *   BTLV_EFFECT_StartIntroEffect  0x021F8A78  thumb
 *   BTLV_INPUT_ChangeScreen  0x0220270C  thumb
 *   BTLV_INPUT_GetScreen  0x022033F0  thumb
 *   BTLV_INPUT_IsInputBlocked  0x022033CC  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   MIi_CpuClear16  0x02082A48  arm
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb
 *   BTL_MAIN_GetSlotFromViewPos  0x021B8ED8  thumb
 *   BTL_MAIN_GetOwnClientId  0x021B8FF4  thumb
 *   BTL_MAIN_GetOwnPartnerClient  0x021B9000  thumb
 *   BTL_MAIN_GetOwnOpponentClient  0x021B904C  thumb
 *   BTL_SIDE_GetPokeAtPos  0x021B98AC  thumb
 *   BTL_SLOT_GetCount  0x021B9B94  thumb
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb
 *   BTL_CLIENT_GetFieldCountdownByte  0x021D3D84  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb
 *   BTL_POKEPARAM_GetDisplayMon  0x021D5864  thumb
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb
 *   BTL_POKEPARAM_IsAbleToBattle  0x021D5B7C  thumb
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   BTLV_INPUT_Delete  0x022021F4  thumb
 *   BTL_ACTION_SetNone  0x021D8434  thumb
 *   BTLV_SCD_WaitActionTouchStep  0x0689A76C  thumb  ov095
 *   BTLV_SCD_WaitBackTouchStep  0x0689A84C  thumb  ov095
 *   BTLV_SCD_WaitMoveTouchStep  0x0689A988  thumb  ov095
 *   BTLV_SCD_OpenMoveMenuStep  0x0689A878  thumb  ov095
 *   BTLV_SCD_WaitRotateTouchStep  0x0689ABA0  thumb  ov095
 *   BTLV_SCD_OpenRotateMenuStep  0x0689AB48  thumb  ov095
 *   BTLV_SCD_OpenTargetMenuStep  0x0689B0D4  thumb  ov095
 *   BTLV_SCD_WaitTargetTouchStep  0x0689B1E4  thumb  ov095
 *   BTL_ACTION_SetEscape  0x021D8414  thumb
 *   BTLV_INPUT_ProcessTouchInput  0x02202DC4  thumb
 *   gBtlvScdActionRegionsA  0x0689D8D4  data  ov095
 *   gBtlvScdActionRegionsB  0x0689DF64  data  ov095
 *   gBtlvScdActionButtonByRegion  0x0689D828  data  ov095
 *   BTLV_INPUT_StepFingerDemo  0x02203040  thumb
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb
 *   BTL_POKEPARAM_GetMovePP  0x021D5528  thumb
 *   BTL_POKEPARAM_IsTransformed  0x021D6D54  thumb
 *   BTL_POKEPARAM_GetMoveId  0x021D54C0  thumb
 *   BTL_ACTION_SetFight  0x021D82D0  thumb
 *   BTL_ACTION_SetFightSlotFlag  0x021D8318  thumb
 *   BTL_ACTION_SetSkip  0x021D8424  thumb
 *   gBtlvScdMoveRegionsDoubleA  0x0689D880  data  a4
 *   gBtlvScdMoveRegionsSingleA  0x0689D91C  data  a4
 *   gBtlvScdMoveRegionsDoubleB  0x0689E128  data  a4
 *   gBtlvScdMoveRegionsSingleB  0x0689E054  data  a4
 *   BTL_SLOT_GetRotateSrcIndex  0x021B9AB0  thumb
 *   BTL_ACTION_SetRotate  0x021D83FC  thumb
 *   BTLV_INPUT_ProcessKeyInput  0x022030F0  thumb
 *   BTL_MAIN_DecodeMessageCode  0x021B8778  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_MAIN_GetFacingPos  0x021B8C5C  thumb
 *   BTL_MAIN_GetFrontEnemyPos  0x021B9A00  thumb
 *   gBtlvScdViewPosByRegion  0x0689D82C  data  ov095
 *   POKE_TOOL_GetGender  0x02017F00  thumb
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   BTL_CALC_GetCurseTargetKind  0x021D80A8  thumb
 *   BTL_MAIN_GetPosTable  0x021B99E0  thumb
 *   BTLV_SCD_ShowTargetMenu  0x0689AE34  thumb  ov095
 *   BTLV_SCD_BuildTargetSet  0x0689B354  thumb  ov095
 *   BTLV_SCD_PickTargetFromTouch  0x0689ADDC  thumb  ov095
 *   gBtlvScdTargetRegionsSingleA  0x0689E5D8  data  a4
 *   gBtlvScdTargetRegionsSingleB  0x0689E560  data  a4
 *   gBtlvScdTargetRegionsDoubleA  0x0689E650  data  a4
 *   gBtlvScdTargetRegionsDoubleB  0x0689E704  data  a4
 *   BTLV_SCD_ClearTargetSet  0x0689ACCC  thumb  ov095
 *   BTLV_SCD_SetTargetsMain  0x0689ACD8  thumb  ov095
 *   BTLV_SCD_SetTargetsAltKind1  0x0689ACFC  thumb  ov095
 *   BTLV_SCD_SetTargetsAltKind2  0x0689AD24  thumb  ov095
 *   BTLV_SCD_AddFrontEnemyTargets  0x0689AD4C  thumb  ov095
 *   gBtlvScdChoiceRegionsA  0x0689D88C  data  ov095
 *   gBtlvScdChoiceRegionsB  0x0689DC48  data  ov095
 *   gBtlvScdCounterRegionsA  0x0689D934  data  ov095
 *   gBtlvScdCounterRegionsB  0x0689DEBC  data  ov095
 */
/* The original callers declare these with other argument or return widths than the headers do. */
#ifdef __MWERKS__
#define WAZA_TOOL_GetFlag WAZA_TOOL_GetFlagHeader
#define WAZA_TOOL_GetParam WAZA_TOOL_GetParamHeader
#endif
/* The original callers declare these with other argument or return widths than the headers do. */
#ifdef __MWERKS__
#define BTL_MAIN_GetTrainerSlotOfPoke BTL_MAIN_GetTrainerSlotOfPokeHeader
#define BTL_MAIN_GetOwnClientId BTL_MAIN_GetOwnClientIdHeader
#define BTL_MAIN_GetOwnPartnerClient BTL_MAIN_GetOwnPartnerClientHeader
#define BTL_SIDE_GetPokeAtPos BTL_SIDE_GetPokeAtPosHeader
#define BTL_SLOT_GetPokeParam BTL_SLOT_GetPokeParamHeader
#endif
/* The original callers declare these with other argument or return widths than the headers do. */
#ifdef __MWERKS__
#define GFL_HEAP_Alloc GFL_HEAP_AllocHeader
#endif
#include "btlv_scd_types.h"

/* Services of the input module and the effects (ov094). */
#include "../ov094/btlv_input.h"
#include "../ov094/btlv_effect.h"

/* Services of the battle main module. */

/* Services of the poke container and the parties. */

/* Services of the poke parameter. */
#include "../arm9/poke_tool.h"

/* Services of the actions and the move data. */
#include "../ov093/btl_calc.h"

/* System services. */
#include "../arm9/mi_memory.h"
#include "../arm9/bg_sys.h"
#include "../arm9/strbuf.h"
#include "../arm9/printsys.h"
#include "../ov093/btl_client.h"
#include "../ov093/btl_pokeparam.h"
#include "../arm9/waza_tool.h"
#include "../ov093/btl_main.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../ov093/btl_action_word.h"
#ifdef __MWERKS__
#undef GFL_HEAP_Alloc
extern void * GFL_HEAP_Alloc(u16 heapId, u32 size, int clear, const char *site, int tag);
#endif
#ifdef __MWERKS__
#undef BTL_MAIN_GetTrainerSlotOfPoke
#undef BTL_MAIN_GetOwnClientId
#undef BTL_MAIN_GetOwnPartnerClient
#undef BTL_SIDE_GetPokeAtPos
#undef BTL_SLOT_GetPokeParam
extern u8 * BTL_SIDE_GetPokeAtPos(struct BtlMain *const *side, u32 position);
extern struct BtlPokeParam * BTL_SLOT_GetPokeParam(struct BtlSideSlot *slot, u8 index);
#endif
#ifdef __MWERKS__
#undef WAZA_TOOL_GetFlag
#undef WAZA_TOOL_GetParam
extern u32 WAZA_TOOL_GetFlag(u16 move, u32 flag);
extern u32 WAZA_TOOL_GetParam(u16 move, u32 param);
#endif

/* Touch region tables of the menus and data of the view. */
extern u8 gBtlvScdFileName[];
extern u8 gBtlvScdActionButtonByRegion[];
extern u8 gBtlvScdViewPosByRegion[];
extern BtlvInputTouchTable gBtlvScdMoveRegionsDoubleA;
extern BtlvInputTouchTable gBtlvScdChoiceRegionsA;
extern BtlvInputTouchTable gBtlvScdActionRegionsA;
extern BtlvInputTouchTable gBtlvScdMoveRegionsSingleA;
extern BtlvInputTouchTable gBtlvScdCounterRegionsA;
extern s8 gBtlvScdCounterRegionsB[][12];
extern s8 gBtlvScdChoiceRegionsB[][12];
extern s8 gBtlvScdActionRegionsB[][12];
extern s8 gBtlvScdMoveRegionsSingleB[][12];
extern s8 gBtlvScdMoveRegionsDoubleB[][12];
extern s8 (*const gBtlvScdTargetRegionsSingleB[][15])[12];
extern BtlvInputTouchTable *const gBtlvScdTargetRegionsSingleA[][15];
extern BtlvInputTouchTable *const gBtlvScdTargetRegionsDoubleA[][15];
extern s8 (*const gBtlvScdTargetRegionsDoubleB[][15])[12];

BtlvAuxView *BTLV_SCD_Create(struct BtlvCore *core, struct BtlMain *mainModule, struct BtlSide *pokeCon, void *taskList, void *fontMain, struct BtlClient *client, int viewParam, u16 heapId);
void BTLV_SCD_CreateInput(BtlvAuxView *view);
void BTLV_SCD_StartInputSlideIn(BtlvAuxView *view, u32 mode);
void BTLV_SCD_StartInputSlideOut(BtlvAuxView *view);
int BTLV_SCD_IsInputSlideDone(BtlvAuxView *view);
void BTLV_SCD_OnSlideInDone(BtlvAuxView *view);
void BTLV_SCD_OnSlideOutStart(BtlvAuxView *view);
void BTLV_SCD_Nop(BtlvAuxView *view);
void BTLV_SCD_CloseInputIfOpen(BtlvAuxView *view);
void BTLV_SCD_CloseInput(BtlvAuxView *view);
int BTLV_SCD_IsInputIdle(BtlvAuxView *view);
void BTLV_SCD_Delete(BtlvAuxView *view);
void BTLV_SCD_ClearTasks(BtlvAuxView *view);
void BTLV_SCD_PushTask(BtlvAuxView *view, BtlvScdStepFn openFn, BtlvScdStepFn waitFn);
int BTLV_SCD_RunTask(BtlvAuxView *view);
void BTLV_SCD_StartActionMenu(BtlvAuxView *view, struct BtlPokeParam *pokeParam, u8 canBack, u8 clientSlot, union BtlAction *action);
void BTLV_SCD_StartActionMenuBackOnly(BtlvAuxView *view, struct BtlPokeParam *pokeParam, u8 canBack, union BtlAction *action);
u32 BTLV_SCD_WaitActionMenu(BtlvAuxView *view);
void BTLV_SCD_StartMoveMenu(BtlvAuxView *view, struct BtlPokeParam *pokeParam, union BtlAction *action);
void BTLV_SCD_StartRotateMenu(BtlvAuxView *view, BtlvRotateSet *rotateSet, union BtlAction *action);
int BTLV_SCD_WaitMoveMenu(BtlvAuxView *view);
void BTLV_SCD_ReopenMenu(BtlvAuxView *view);
void BTLV_SCD_StartMoveInfoMenu(BtlvAuxView *view, struct BtlPokeParam *pokeParam, union BtlAction *action);
void BTLV_SCD_StartTargetMenu(BtlvAuxView *view, struct BtlPokeParam *pokeParam, union BtlAction *action);
int BTLV_SCD_WaitTargetMenu(BtlvAuxView *view);
void BTLV_SCD_CancelMenus(BtlvAuxView *view);
int BTLV_SCD_OpenActionMenuStep(int *state, BtlvAuxView *view);
int BTLV_SCD_WaitActionTouchStep(int *state, BtlvAuxView *view);
int BTLV_SCD_WaitBackTouchStep(int *state, BtlvAuxView *view);
int BTLV_SCD_OpenMoveMenuStep(int *state, BtlvAuxView *view);
int BTLV_SCD_WaitMoveTouchStep(int *state, BtlvAuxView *view);
int BTLV_SCD_OpenRotateMenuStep(int *state, BtlvAuxView *view);
int BTLV_SCD_WaitRotateTouchStep(int *state, BtlvAuxView *view);
void BTLV_SCD_ClearTargetSet(BtlvTargetSet *targets);
void BTLV_SCD_SetTargetsMain(BtlvTargetSet *targets, struct BtlMain *mainModule, u16 code);
void BTLV_SCD_SetTargetsAltKind1(BtlvTargetSet *targets, struct BtlMain *mainModule, u16 code);
void BTLV_SCD_SetTargetsAltKind2(BtlvTargetSet *targets, struct BtlMain *mainModule, u16 code);
void BTLV_SCD_AddFrontEnemyTargets(BtlvTargetSet *targets, struct BtlMain *mainModule, u16 moveId, u32 userViewPos);
int BTLV_SCD_PickTargetFromTouch(BtlvTargetSet *targets, int index, struct BtlMain *mainModule, u8 *outSlot);
void BTLV_SCD_ShowTargetMenu(u8 *slots, u8 count, int altMode, BtlvAuxView *view);
void BTLV_SCD_ShowTargetSetMenu(BtlvTargetSet *targets, BtlvAuxView *view);
u8 BTLV_SCD_IsTargetChosen(BtlvAuxView *view);
int BTLV_SCD_OpenTargetMenuStep(int *state, BtlvAuxView *view);
int BTLV_SCD_WaitTargetTouchStep(int *state, BtlvAuxView *view);
void BTLV_SCD_BuildTargetSet(BtlvTargetSet *targets, BtlvAuxView *view);
void BTLV_SCD_ShowRotateScreen(BtlvAuxView *view, void *payload);
int BTLV_SCD_PollTouchKey(BtlvAuxView *view, u8 *outKey);
void BTLV_SCD_CloseInputScreen(BtlvAuxView *view);
struct BtlvYesNoWork;
void BTLV_SCD_OpenChoiceScreen(BtlvAuxView *view, struct BtlvYesNoWork *value);
int BTLV_SCD_PollChoiceScreen(BtlvAuxView *view, u32 *outChoice);
u8 *BTLV_SCD_GetInputFlags(BtlvAuxView *view);
void BTLV_SCD_BeginCloseSequence(BtlvAuxView *view);
int BTLV_SCD_RunCloseSequence(BtlvAuxView *view);
void BTLV_SCD_ShowCounterScreen(BtlvAuxView *view, void *payload);
int BTLV_SCD_PollCounterTouch(BtlvAuxView *view);

/* Creates the view: allocates it, takes the party of the local client and resets the task stack. */
BtlvAuxView *BTLV_SCD_Create(struct BtlvCore *core, struct BtlMain *mainModule, struct BtlSide *pokeCon, void *taskList, void *fontMain, struct BtlClient *client, int viewParam, u16 heapId)
{
    BtlvAuxView *view;

    view = GFL_HEAP_Alloc(heapId, sizeof(*view), 1, (const char *)gBtlvScdFileName, 0xc8);
    view->core = core;
    view->mainModule = mainModule;
    view->pokeCon = pokeCon;
    view->heapId = heapId;
    view->fontMain = fontMain;
    view->client = client;
    view->ownParty = BTL_SIDE_GetSlotOfClientThunk(pokeCon, BTL_CLIENT_GetClientId(client));
    view->msgBuffer = STRBUF_Create(0x80, heapId);
    view->cursorIndex = 0;
    view->viewParam = viewParam;
    view->clientSlot = 0;
    view->status.bits.step = 0;
    view->status.bits.active = 0;
    view->inputFlags = 0;
    view->printQueue = PRINTSYS_QUE_Create(view->heapId);
    BTLV_SCD_ClearTasks(view);
    return view;
}

/* Creates the input module of the touch screen and shows the sub screen plane. */
void BTLV_SCD_CreateInput(BtlvAuxView *view)
{
    struct GameData *gameData;
    u32 rule;
    u32 competitor;
    PaletteFade *palAnm;

    gameData = BTL_MAIN_GetGameData(view->mainModule);
    rule = BTL_MAIN_GetRule(view->mainModule);
    competitor = BTL_MAIN_GetCompetitor(view->mainModule);
    palAnm = BTLV_EFFECT_GetPalanm();
    view->input = BTLV_INPUT_CreateWithMode(gameData, rule, competitor, palAnm, view->fontMain, &view->inputFlags, view->viewParam, view->heapId);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    BTLV_SCD_Nop(view);
}

/* Starts the slide-in of the touch screen input; mode selects the screen. */
void BTLV_SCD_StartInputSlideIn(BtlvAuxView *view, u32 mode)
{
    view->slideX = 0;
    view->slideY = -16;
    view->slideStep = -1;
    BTLV_INPUT_StartPaletteFadeTask(view->input, mode);
}

/* Starts the slide-out of the touch screen input. */
void BTLV_SCD_StartInputSlideOut(BtlvAuxView *view)
{
    view->slideX = -16;
    view->slideY = 0;
    view->slideStep = 1;
    BTLV_INPUT_StartScreenFadeTask(view->input);
}

/* Returns 1 when the input module no longer reports a slide in progress. */
int BTLV_SCD_IsInputSlideDone(BtlvAuxView *view)
{
    if (BTLV_INPUT_IsScreenBusy(view->input) == 0)
        return 1;
    return 0;
}

/* Empty hook called when the slide-in is done. */
void BTLV_SCD_OnSlideInDone(BtlvAuxView *view)
{
}

/* Hook called when the slide-out starts; forwards to the empty hook. */
void BTLV_SCD_OnSlideOutStart(BtlvAuxView *view)
{
    BTLV_SCD_Nop(view);
}

/* Empty hook. */
void BTLV_SCD_Nop(BtlvAuxView *view)
{
}

/* Closes the input screen when the input module reports it open. */
void BTLV_SCD_CloseInputIfOpen(BtlvAuxView *view)
{
    if (BTLV_INPUT_GetScreen(view->input) != 0)
        BTLV_SCD_CloseInput(view);
}

/* Clears the input screen and plays the close effect. */
void BTLV_SCD_CloseInput(BtlvAuxView *view)
{
    BTLV_INPUT_ChangeScreen(view->input, BTLV_INPUT_SCREEN_CLOSE, 0);
    BTLV_EFFECT_GaugeSelectSlot(8);
    BTLV_EFFECT_StartIntroEffect();
}

/* Returns 1 when the input module is idle. */
int BTLV_SCD_IsInputIdle(BtlvAuxView *view)
{
    return BTLV_INPUT_IsInputBlocked(view->input) == 0;
}

/* Deletes the view: print queue, message buffer, input module, then the view itself. */
void BTLV_SCD_Delete(BtlvAuxView *view)
{
    PRINTSYS_QUE_Delete(view->printQueue);
    STRBUF_Delete(view->msgBuffer);
    BTLV_INPUT_Delete(view->input);
    GFL_HEAP_Free(view);
}

/* Empties the task stack. */
void BTLV_SCD_ClearTasks(BtlvAuxView *view)
{
    int i;

    for (i = 0; i < BTLV_SCD_TASK_MAX; i++) {
        view->taskStack[i].openFn = 0;
        view->taskStack[i].waitFn = 0;
        view->taskStack[i].view = 0;
        view->taskStack[i].state = 0;
    }
    view->taskDepth = 0;
}

/* Pushes a task (open step, wait step) on the task stack. */
void BTLV_SCD_PushTask(BtlvAuxView *view, BtlvScdStepFn openFn, BtlvScdStepFn waitFn)
{
    int index = view->taskDepth++;
    BtlvScdTask *task = &view->taskStack[index];

    task->openFn = openFn;
    task->waitFn = waitFn;
    task->view = view;
    task->state = 0;
}

/* Runs the top task one step. Returns 1 when the stack is empty, else 0. */
int BTLV_SCD_RunTask(BtlvAuxView *view)
{
    BtlvScdTask *task;
    int popTask;

    if (view->taskDepth != 0) {
        task = &view->taskStack[view->taskDepth - 1];
        if (task->openFn != 0) {
            if (task->openFn(&task->state, task->view) != 0) {
                task->openFn = 0;
                task->state = 0;
            }
            popTask = 0;
        } else if (task->waitFn != 0) {
            if (task->waitFn(&task->state, task->view) != 0) {
                task->waitFn = 0;
                popTask = 1;
            } else {
                popTask = 0;
            }
        } else {
            popTask = 1;
        }
        if (popTask) {
            task->openFn = 0;
            task->waitFn = 0;
            task->view = 0;
            task->state = 0;
            view->taskDepth--;
        }
        return 0;
    }
    return 1;
}

/* Starts the action menu (Fight, Bag, Pokemon, Run) for a Pokemon. */
void BTLV_SCD_StartActionMenu(BtlvAuxView *view, struct BtlPokeParam *pokeParam, u8 canBack, u8 clientSlot, union BtlAction *action)
{
    view->pokeParam = pokeParam;
    view->action = action;
    view->result = 0;
    view->canBack = canBack;
    view->clientSlot = clientSlot;
    BTLV_SCD_PushTask(view, BTLV_SCD_OpenActionMenuStep, BTLV_SCD_WaitActionTouchStep);
}

/* Starts the action menu in the Back-only form. */
void BTLV_SCD_StartActionMenuBackOnly(BtlvAuxView *view, struct BtlPokeParam *pokeParam, u8 canBack, union BtlAction *action)
{
    view->pokeParam = pokeParam;
    view->action = action;
    view->result = 0;
    view->canBack = canBack;
    BTLV_SCD_PushTask(view, BTLV_SCD_OpenActionMenuStep, BTLV_SCD_WaitBackTouchStep);
}

/* Runs the menu task; returns the result once it ends, else 0. */
u32 BTLV_SCD_WaitActionMenu(BtlvAuxView *view)
{
    if (BTLV_SCD_RunTask(view))
        return view->result;
    return 0;
}

/* Starts the move menu; the wait step is also the one pushed again by a reselect. */
void BTLV_SCD_StartMoveMenu(BtlvAuxView *view, struct BtlPokeParam *pokeParam, union BtlAction *action)
{
    view->pokeParam = pokeParam;
    view->action = action;
    view->result = 0;
    view->reselectFn = BTLV_SCD_WaitMoveTouchStep;
    BTLV_SCD_PushTask(view, BTLV_SCD_OpenMoveMenuStep, BTLV_SCD_WaitMoveTouchStep);
}

/* Starts the rotation menu for a rotation battle. */
void BTLV_SCD_StartRotateMenu(BtlvAuxView *view, BtlvRotateSet *rotateSet, union BtlAction *action)
{
    view->result = 0;
    view->rotateSet = rotateSet;
    view->action = action;
    view->reselectFn = BTLV_SCD_WaitRotateTouchStep;
    BTL_ACTION_SetNone(action);
    BTL_ACTION_SetNone(&rotateSet->rotateAction);
    BTL_ACTION_SetNone(&rotateSet->fightAction);
    BTLV_SCD_PushTask(view, BTLV_SCD_OpenRotateMenuStep, BTLV_SCD_WaitRotateTouchStep);
}

/* Runs the menu task one step. */
int BTLV_SCD_WaitMoveMenu(BtlvAuxView *view)
{
    return BTLV_SCD_RunTask(view);
}

/* Pushes the wait step of the last menu again, without an open step. */
void BTLV_SCD_ReopenMenu(BtlvAuxView *view)
{
    BTLV_SCD_PushTask(view, 0, view->reselectFn);
}

/* Starts the move list display with the Back-only wait step. */
void BTLV_SCD_StartMoveInfoMenu(BtlvAuxView *view, struct BtlPokeParam *pokeParam, union BtlAction *action)
{
    view->pokeParam = pokeParam;
    view->action = action;
    view->result = 0;
    BTLV_SCD_PushTask(view, BTLV_SCD_OpenMoveMenuStep, BTLV_SCD_WaitBackTouchStep);
}

/* Starts the target menu. */
void BTLV_SCD_StartTargetMenu(BtlvAuxView *view, struct BtlPokeParam *pokeParam, union BtlAction *action)
{
    view->pokeParam = pokeParam;
    view->action = action;
    BTLV_SCD_PushTask(view, BTLV_SCD_OpenTargetMenuStep, BTLV_SCD_WaitTargetTouchStep);
}

/* Runs the menu task one step. */
int BTLV_SCD_WaitTargetMenu(BtlvAuxView *view)
{
    return BTLV_SCD_RunTask(view);
}

/* Drops every menu task. */
void BTLV_SCD_CancelMenus(BtlvAuxView *view)
{
    BTLV_SCD_ClearTasks(view);
}

/*
 * Open step of the action menu: collects the party status balls of both
 * sides and the first Pokemon names, then shows the action screen.
 */
int BTLV_SCD_OpenActionMenuStep(int *state, BtlvAuxView *view)
{
    u16 count;
    u16 pass;
    u16 index;
    struct BtlSideSlot *parties[2] = {0, 0};
    u16 counts[2] = {0, 0};
    u32 rule, first, second, side, slot;
    struct BtlPokeParam *mon;
    BtlvActionMenuInfo info;

    pass = 0;
    MIi_CpuClear16(0, &info, 200);
    info.viewParam = view->viewParam;
    info.clientSlot = view->clientSlot;
    first = BTL_POKEPARAM_GetPokeId(view->pokeParam);
    first = BTL_MAIN_GetTrainerSlotOfPoke(view->mainModule, view->pokeCon, first);
    info.userViewPos = BTL_MAIN_GetViewPosOfSlot(view->mainModule, first);
    BTLV_EFFECT_GaugeSelectSlot(info.userViewPos);
    rule = BTL_MAIN_GetRule(view->mainModule);
    for (; pass < 2; pass++) {
        parties[0] = 0;
        parties[1] = 0;
        if (pass == 0) {
            first = BTL_MAIN_GetOwnClientId(view->mainModule);
            second = BTL_MAIN_GetOwnPartnerClient(view->mainModule);
            if (rule == 1 && second != 4) {
                if (first < second) {
                    parties[0] = BTL_SIDE_GetSlotOfClientThunk(view->pokeCon, first);
                    counts[0] = BTL_SLOT_GetCount(parties[0]);
                    parties[1] = BTL_SIDE_GetSlotOfClientThunk(view->pokeCon, second);
                    counts[1] = BTL_SLOT_GetCount(parties[1]);
                } else {
                    parties[0] = BTL_SIDE_GetSlotOfClientThunk(view->pokeCon, second);
                    counts[0] = BTL_SLOT_GetCount(parties[0]);
                    parties[1] = BTL_SIDE_GetSlotOfClientThunk(view->pokeCon, first);
                    counts[1] = BTL_SLOT_GetCount(parties[1]);
                }
            } else {
                parties[0] = view->ownParty;
                counts[0] = BTL_SLOT_GetCount(parties[0]);
            }
            switch (rule) {
            case 0:
                slot = BTL_MAIN_GetSlotFromViewPos(view->mainModule, 0);
                mon = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain *const *)view->pokeCon, slot);
                if (BTL_POKEPARAM_IsFainted(mon) == 0) {
                    info.species[0] = BTL_POKEPARAM_GetSpecies(mon);
                    info.monLabel[0] = POKE_TOOL_GetPartyValue(BTL_POKEPARAM_GetDisplayMon(mon), 111, 0);
                    info.monValue[0] = BTL_POKEPARAM_GetValue(mon, 18);
                }
                break;
            case 2:
                slot = BTL_MAIN_GetSlotFromViewPos(view->mainModule, 6);
                mon = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain *const *)view->pokeCon, slot);
                if (BTL_POKEPARAM_IsFainted(mon) == 0) {
                    info.species[2] = BTL_POKEPARAM_GetSpecies(mon);
                    info.monLabel[2] = POKE_TOOL_GetPartyValue(BTL_POKEPARAM_GetDisplayMon(mon), 111, 0);
                    info.monValue[2] = BTL_POKEPARAM_GetValue(mon, 18);
                }
            case 1: case 3:
                slot = BTL_MAIN_GetSlotFromViewPos(view->mainModule, 2);
                mon = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain *const *)view->pokeCon, slot);
                if (BTL_POKEPARAM_IsFainted(mon) == 0) {
                    info.species[0] = BTL_POKEPARAM_GetSpecies(mon);
                    info.monLabel[0] = POKE_TOOL_GetPartyValue(BTL_POKEPARAM_GetDisplayMon(mon), 111, 0);
                    info.monValue[0] = BTL_POKEPARAM_GetValue(mon, 18);
                }
                slot = BTL_MAIN_GetSlotFromViewPos(view->mainModule, 4);
                mon = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain *const *)view->pokeCon, slot);
                if (BTL_POKEPARAM_IsFainted(mon) == 0) {
                    info.species[1] = BTL_POKEPARAM_GetSpecies(mon);
                    info.monLabel[1] = POKE_TOOL_GetPartyValue(BTL_POKEPARAM_GetDisplayMon(mon), 111, 0);
                    info.monValue[1] = BTL_POKEPARAM_GetValue(mon, 18);
                }
                break;
            default: break;
            }
        } else {
            if (BTL_MAIN_GetCompetitor(view->mainModule) == 0 || BTL_MAIN_GetCompetitor(view->mainModule) == 4) break;
            first = BTL_MAIN_GetOwnOpponentClient(view->mainModule, 0);
            second = BTL_MAIN_GetOwnOpponentClient(view->mainModule, 1);
            info.hasOpponentParty = 1;
            parties[0] = BTL_SIDE_GetSlotOfClientThunk(view->pokeCon, first);
            counts[0] = BTL_SLOT_GetCount(parties[0]);
            if (rule == 1 && first != second) {
                parties[1] = BTL_SIDE_GetSlotOfClientThunk(view->pokeCon, second);
                counts[1] = BTL_SLOT_GetCount(parties[1]);
            }
        }
        if (parties[1] == 0) count = counts[0];
        else {
            if (counts[0] > 3) counts[0] = 3;
            if (counts[1] > 3) counts[1] = 3;
            count = counts[0] + counts[1];
        }
        for (index = 0; index < count; index++) {
            if (index < counts[0]) { side = 0; slot = index; }
            else { side = 1; slot = index - counts[0]; }
            mon = BTL_SLOT_GetPokeParam(parties[side], slot);
            if (BTL_POKEPARAM_IsFainted(mon) == 0) {
                if (BTL_POKEPARAM_GetMajorStatusIndex(mon) != 0) info.balls[pass][side * 3 + slot].status = 3;
                else if (BTL_POKEPARAM_IsAbleToBattle(mon) == 0) info.balls[pass][side * 3 + slot].status = 0;
                else info.balls[pass][side * 3 + slot].status = 1;
            } else info.balls[pass][side * 3 + slot].status = 2;
        }
    }
    info.canBack = view->canBack;
    info.countdown = BTL_CLIENT_GetFieldCountdownByte(view->client);
    BTLV_INPUT_ChangeScreen(view->input, BTLV_INPUT_SCREEN_ACTION, &info);
    return 1;
}

/* Wait step of the action menu: reads the touched button. */
int BTLV_SCD_WaitActionTouchStep(int *state, BtlvAuxView *view)
{
    int touched;
    u32 button;

    switch (*state) {
    case 0:
        touched = BTLV_INPUT_ProcessTouchInput(view->input, &gBtlvScdActionRegionsA, gBtlvScdActionRegionsB);
        if (touched == -1)
            break;
        button = gBtlvScdActionButtonByRegion[touched];
        view->result = button;
        if (button == 4) {
            BTL_ACTION_SetEscape(view->action);
            BTLV_INPUT_ChangeScreen(view->input, BTLV_INPUT_SCREEN_CLOSE, 0);
            BTLV_EFFECT_GaugeSelectSlot(8);
            BTLV_EFFECT_StartIntroEffect();
            (*state)++;
            break;
        }
        return 1;
    case 1:
        if (BTLV_INPUT_IsInputBlocked(view->input) == 0)
            return 1;
        break;
    }
    return 0;
}

/* Wait step of the Back-only menu: the input module reports 1 when Back was touched. */
int BTLV_SCD_WaitBackTouchStep(int *state, BtlvAuxView *view)
{
    int touched;

    touched = BTLV_INPUT_StepFingerDemo(view->input);
    if (touched == 1) {
        view->result = 1;
    }
    return touched;
}

/* Open step of the move menu: lists the moves of the Pokemon with their PP. */
int BTLV_SCD_OpenMoveMenuStep(int *state, BtlvAuxView *view)
{
    BtlvMoveMenuInfo info;
    u8 pp[2];
    u16 i;
    u32 moveCount;

    moveCount = BTL_POKEPARAM_GetMoveCount(view->pokeParam);
    info.transformed = BTL_POKEPARAM_IsTransformed(view->pokeParam);
    for (i = 0; i < moveCount; i++) {
        info.moveId[i] = BTL_POKEPARAM_GetMovePP(view->pokeParam, i, &pp[1], &pp[0]);
        info.pp[i] = pp[1];
        info.ppMax[i] = pp[0];
    }
    for (; i < 4; i++) {
        info.moveId[i] = 0;
        info.pp[i] = 0;
        info.ppMax[i] = 0;
    }
    info.userViewPos = BTL_MAIN_GetViewPosOfSlot(view->mainModule,
                        BTL_MAIN_GetTrainerSlotOfPoke(view->mainModule, view->pokeCon,
                                      BTL_POKEPARAM_GetPokeId(view->pokeParam)));
    BTLV_INPUT_ChangeScreen(view->input, BTLV_INPUT_SCREEN_MOVE, &info);
    return 1;
}

/* Wait step of the move menu: sets the fight action for the touched move. */
int BTLV_SCD_WaitMoveTouchStep(int *state, BtlvAuxView *view)
{
    int choice;
    BtlvInputTouchTable *regionsA;
    s8 (*regionsB)[12];
    int slotFlag;

    choice = BTL_MAIN_GetViewPosOfSlot(view->mainModule, BTL_MAIN_GetTrainerSlotOfPoke(view->mainModule, view->pokeCon, BTL_POKEPARAM_GetPokeId(view->pokeParam)));
    if (BTL_MAIN_GetRule(view->mainModule) == 2 && choice != 4) regionsA = &gBtlvScdMoveRegionsDoubleA;
    else regionsA = &gBtlvScdMoveRegionsSingleA;
    if (BTL_MAIN_GetRule(view->mainModule) == 2 && choice != 4) regionsB = gBtlvScdMoveRegionsDoubleB;
    else regionsB = gBtlvScdMoveRegionsSingleB;
    choice = BTLV_INPUT_ProcessTouchInput(view->input, regionsA, regionsB);
    if (choice != -1) {
        if (choice & 0x8000) slotFlag = 1;
        else slotFlag = 0;
        choice &= ~0x8000;
        if (choice == 4) {
            BTL_ACTION_SetNone(view->action);
            return 1;
        }
        if (choice < BTL_POKEPARAM_GetMoveCount(view->pokeParam)) {
            BTL_ACTION_SetFight(view->action, BTL_POKEPARAM_GetMoveId(view->pokeParam, (u8)choice), 6);
            if (slotFlag) BTL_ACTION_SetFightSlotFlag(view->action);
            return 1;
        }
        if (BTL_MAIN_GetRule(view->mainModule) == 2 && choice == 5) {
            BTL_ACTION_SetSkip(view->action);
            return 1;
        }
    }
    return 0;
}

/* Open step of the rotation menu: lists the three rotation candidates. */
int BTLV_SCD_OpenRotateMenuStep(int *state, BtlvAuxView *view)
{
    BtlvRotateMenuInfo info;
    int i;
    int j;

    for (i = 0; i < 3; i++) {
        info.pokeParam[i] = (uptr)view->rotateSet->cand[i].pokeParam;
        for (j = 0; j < 4; j++)
            info.info[i][j] = view->rotateSet->cand[i].info[j];
    }
    BTLV_INPUT_ChangeScreen(view->input, BTLV_INPUT_SCREEN_ROTATE, &info);
    return 1;
}

/* Wait step of the rotation menu: sets the rotate and fight actions. */
int BTLV_SCD_WaitRotateTouchStep(int *state, BtlvAuxView *view)
{
    struct {
        u8 key;
        u32 value;
    } touch;
    u32 slotFlag;
    u32 value;
    u32 moveId;

    if (BTLV_INPUT_ProcessKeyInput(view->input, &touch.key, &touch.value)) {
        slotFlag = (touch.value & 0x8000) != 0;
        touch.value &= ~0x8000;
        value = touch.value;
        if (value != 4) {
            if (touch.key == 0)
                touch.key = 1;
            if (value != 7)
                moveId = BTL_POKEPARAM_GetMoveId(view->rotateSet->cand[BTL_SLOT_GetRotateSrcIndex(touch.key)].pokeParam, (u8)touch.value);
            else
                moveId = 0xa5;
            BTL_ACTION_SetRotate(&view->rotateSet->rotateAction, touch.key);
            BTL_ACTION_SetFight(&view->rotateSet->fightAction, moveId, 6);
            BTL_ACTION_SetFight(view->action, moveId, 6);
            if (slotFlag)
                BTL_ACTION_SetFightSlotFlag(view->action);
        } else if (value == 4) {
            BTL_ACTION_SetNone(view->action);
        }
        return 1;
    }
    return 0;
}

/* Clears the target set. */
void BTLV_SCD_ClearTargetSet(BtlvTargetSet *targets)
{
    MI_CpuFill8(targets, 0, 9);
}

/* Fills the main list from a message code. */
void BTLV_SCD_SetTargetsMain(BtlvTargetSet *targets, struct BtlMain *mainModule, u16 code)
{
    targets->count = BTL_MAIN_DecodeMessageCode(mainModule, code, targets->viewPos);
}

/* Fills the alternate list, kind 1. */
void BTLV_SCD_SetTargetsAltKind1(BtlvTargetSet *targets, struct BtlMain *mainModule, u16 code)
{
    targets->altCount = BTL_MAIN_DecodeMessageCode(mainModule, code, targets->viewPos);
    targets->altKind = 1;
}

/* Fills the alternate list, kind 2. */
void BTLV_SCD_SetTargetsAltKind2(BtlvTargetSet *targets, struct BtlMain *mainModule, u16 code)
{
    targets->altCount = BTL_MAIN_DecodeMessageCode(mainModule, code, targets->viewPos);
    targets->altKind = 2;
}

/* In a double battle, adds the front enemy and the position facing it for moves that reach both. */
void BTLV_SCD_AddFrontEnemyTargets(BtlvTargetSet *targets, struct BtlMain *mainModule, u16 moveId, u32 userViewPos)
{
    u8 frontPos;

    if (BTL_MAIN_GetRule(mainModule) == 2) {
        if (WAZA_TOOL_GetFlag(moveId, 0xb)) {
            if (BTL_MAIN_GetFrontEnemyPos(userViewPos, &frontPos)) {
                targets->viewPos[targets->count++] = frontPos;
                targets->viewPos[targets->count++] = BTL_MAIN_GetFacingPos(2, frontPos);
            }
        }
    }
}

/* Returns 1 and the slot of the touched region when it is in the target set. */
int BTLV_SCD_PickTargetFromTouch(BtlvTargetSet *targets, int index, struct BtlMain *mainModule, u8 *outSlot)
{
    u8 i;

    if (targets->count != 0) {
        *outSlot = BTL_MAIN_GetSlotFromViewPos(mainModule, gBtlvScdViewPosByRegion[index]);
        for (i = 0; i < targets->count; i++) {
            if (*outSlot == targets->viewPos[i])
                return 1;
        }
        return 0;
    }
    *outSlot = 6;
    return 1;
}

/* Shows the target menu: one row per listed Pokemon. */
void BTLV_SCD_ShowTargetMenu(u8 *slots, u8 count, int altMode, BtlvAuxView *view)
{
    BtlvTargetMenuInfo info;
    u16 moveId;
    struct BtlPokeParam *bpp;
    u32 monWord;
    u8 rowIndex;
    BtlvTargetRow *row;
    int species;

    moveId = view->action->fight.moveId;
    MIi_CpuClear16(0, &info, sizeof(info));
    info.userViewPos = BTL_MAIN_GetViewPosOfSlot(view->mainModule, BTL_MAIN_GetTrainerSlotOfPoke(view->mainModule, view->pokeCon, BTL_POKEPARAM_GetPokeId(view->pokeParam)));
    info.targetKind = WAZA_TOOL_GetParam(moveId, 0x1b);
    if (moveId == 0xae) info.targetKind = BTL_CALC_GetCurseTargetKind(view->pokeParam);
    if (info.targetKind == 0 && WAZA_TOOL_GetFlag(moveId, 0xb)) info.targetKind = 14;
    while (count-- != 0) {
        bpp = (struct BtlPokeParam *)BTL_SIDE_GetPokeAtPos((struct BtlMain *const *)view->pokeCon, *slots);
        monWord = (uptr)BTL_POKEPARAM_GetDisplayMon(bpp);
        rowIndex = BTL_MAIN_GetViewPosOfSlot(view->mainModule, *slots) - 2;
        row = &info.rows[rowIndex];
        row->hp = BTL_POKEPARAM_GetValue(bpp, 0xd);
        row->flags |= 4;
        if (row->hp != 0) {
            species = BTL_POKEPARAM_GetSpecies(bpp);
            row->monWord = monWord;
            row->hpMax = BTL_POKEPARAM_GetValue(bpp, 0xe);
            if (species == 32 || species == 29) row->flags = (row->flags & ~3) | 2;
            else row->flags = (row->flags & ~3) | (POKE_TOOL_GetGender(BTL_POKEPARAM_GetDisplayMon(bpp)) & 3);
            if (BTL_POKEPARAM_GetMajorStatusIndex(bpp)) row->state = 3;
            else row->state = 1;
        } else row->state = 2;
        slots++;
    }
    BTLV_INPUT_ChangeScreen(view->input, BTLV_INPUT_SCREEN_TARGET, &info);
}

/* Shows the target menu for the target set: the main list, else the alternate list of its kind. */
void BTLV_SCD_ShowTargetSetMenu(BtlvTargetSet *targets, BtlvAuxView *view)
{
    if (targets->count != 0) {
        BTLV_SCD_ShowTargetMenu(targets->viewPos, targets->count, 0, view);
    } else if (targets->altKind == 1) {
        BTLV_SCD_ShowTargetMenu(targets->viewPos, targets->altCount, 1, view);
    } else {
        BTLV_SCD_ShowTargetMenu(targets->viewPos, targets->altCount, 2, view);
    }
}

/* Returns the flag that says a target was chosen. */
u8 BTLV_SCD_IsTargetChosen(BtlvAuxView *view)
{
    return view->targetChosen;
}

/* Open step of the target menu. */
int BTLV_SCD_OpenTargetMenuStep(int *state, BtlvAuxView *view)
{
    u8 targetPos;

    BTLV_SCD_BuildTargetSet(&view->targets, view);
    if (BTL_MAIN_GetRule(view->mainModule) == 2) {
        targetPos = 6;
        if (view->targets.count != 0) {
            targetPos = BTL_MAIN_GetPosTable(BTL_MAIN_GetTrainerSlotOfPoke(view->mainModule, view->pokeCon, BTL_POKEPARAM_GetPokeId(view->pokeParam)))->positions[0];
        }
        BTL_ACTION_SetFight(view->action, (u16)view->action->fight.moveId, targetPos);
        view->targetChosen = 1;
    }
    BTLV_SCD_ShowTargetSetMenu(&view->targets, view);
    view->targetChosen = 0;
    view->moveTargetKind = WAZA_TOOL_GetParam(view->action->fight.moveId, 0x1b);
    if (view->action->fight.moveId == 0xae)
        view->moveTargetKind = BTL_CALC_GetCurseTargetKind(view->pokeParam);
    return 1;
}

/* Wait step of the target menu: stores the touched target in the fight action. */
int BTLV_SCD_WaitTargetTouchStep(int *state, BtlvAuxView *view)
{
    u8 kind, row, targetPos;
    int userViewPos, stopIndex, choice;
    BtlvInputTouchTable *regionsA;
    s8 (*regionsB)[12];

    if (*state == 0) {
        userViewPos = BTL_MAIN_GetViewPosOfSlot(view->mainModule, BTL_MAIN_GetTrainerSlotOfPoke(view->mainModule, view->pokeCon, BTL_POKEPARAM_GetPokeId(view->pokeParam)));
        kind = view->moveTargetKind;
        row = (userViewPos - 2) / 2;
        if (BTL_MAIN_GetRule(view->mainModule) != 2) {
            regionsA = gBtlvScdTargetRegionsSingleA[row][kind];
            regionsB = gBtlvScdTargetRegionsSingleB[row][kind];
            stopIndex = 4;
        } else {
            if (kind == 0 && WAZA_TOOL_GetFlag(view->action->fight.moveId, 0xb)) kind = 14;
            regionsA = gBtlvScdTargetRegionsDoubleA[row][kind];
            regionsB = gBtlvScdTargetRegionsDoubleB[row][kind];
            stopIndex = 6;
        }
        choice = BTLV_INPUT_ProcessTouchInput(view->input, regionsA, regionsB);
        if (choice != -1) {
            if (choice != stopIndex) {
                if (BTLV_SCD_PickTargetFromTouch(&view->targets, choice, view->mainModule, &targetPos)) {
                    BTL_ACTION_SetFight(view->action, (u16)view->action->fight.moveId, targetPos);
                    view->targetChosen = 1;
                    return 1;
                }
            } else {
                view->targetChosen = 0;
                return 1;
            }
        }
    }
    return 0;
}

/* Builds the target set for the move of the action by its target kind. */
void BTLV_SCD_BuildTargetSet(BtlvTargetSet *targets, BtlvAuxView *view)
{
    u16 moveId;
    u32 targetKind;
    int userViewPos;

    moveId = view->action->fight.moveId;
    targetKind = WAZA_TOOL_GetParam(moveId, 0x1b);
    userViewPos = BTL_MAIN_GetTrainerSlotOfPoke(view->mainModule, view->pokeCon, BTL_POKEPARAM_GetPokeId(view->pokeParam));
    BTLV_SCD_ClearTargetSet(targets);
    if (moveId == 0xae) targetKind = BTL_CALC_GetCurseTargetKind(view->pokeParam);
    switch (targetKind) {
    case 0:
        BTLV_SCD_SetTargetsMain(targets, view->mainModule, userViewPos | 0x200);
        BTLV_SCD_AddFrontEnemyTargets(targets, view->mainModule, moveId, userViewPos);
        return;
    case 3:
        BTLV_SCD_SetTargetsMain(targets, view->mainModule, userViewPos | 0x100);
        BTLV_SCD_AddFrontEnemyTargets(targets, view->mainModule, moveId, userViewPos);
        return;
    case 1:
        BTLV_SCD_SetTargetsMain(targets, view->mainModule, userViewPos | 0x300);
        return;
    case 2:
        BTLV_SCD_SetTargetsMain(targets, view->mainModule, userViewPos | 0x400);
        return;
    case 5:
        BTLV_SCD_SetTargetsAltKind1(targets, view->mainModule, userViewPos | 0x100);
        return;
    case 4:
        BTLV_SCD_SetTargetsAltKind1(targets, view->mainModule, userViewPos | 0x200);
        return;
    case 7:
    case 9:
        BTLV_SCD_SetTargetsAltKind1(targets, view->mainModule, userViewPos);
        return;
    case 6:
    case 12:
        BTLV_SCD_SetTargetsAltKind2(targets, view->mainModule, userViewPos | 0x700);
        return;
    case 11:
        BTLV_SCD_SetTargetsAltKind2(targets, view->mainModule, userViewPos | 0x600);
        return;
    case 8:
    case 10:
        BTLV_SCD_SetTargetsAltKind2(targets, view->mainModule, userViewPos | 0x800);
        return;
    case 13:
        BTLV_SCD_SetTargetsAltKind1(targets, view->mainModule, userViewPos);
        break;
    }
}

/* Shows the rotation screen with a payload built by the caller. */
void BTLV_SCD_ShowRotateScreen(BtlvAuxView *view, void *payload)
{
    BTLV_INPUT_ChangeScreen(view->input, BTLV_INPUT_SCREEN_ROTATE, payload);
}

/* Reads the touched key; returns 1 and the key when one was touched. */
int BTLV_SCD_PollTouchKey(BtlvAuxView *view, u8 *outKey)
{
    int value;

    value = BTLV_INPUT_ProcessTouchInput(view->input, 0, 0);
    if (value != -1) {
        *outKey = value;
        return 1;
    }
    return 0;
}

/* Clears the input screen and plays the close effect. */
void BTLV_SCD_CloseInputScreen(BtlvAuxView *view)
{
    BTLV_INPUT_ChangeScreen(view->input, BTLV_INPUT_SCREEN_CLOSE, 0);
    BTLV_EFFECT_GaugeSelectSlot(8);
    BTLV_EFFECT_StartIntroEffect();
}

/* Shows the choice screen with a value and resets its step. */
void BTLV_SCD_OpenChoiceScreen(BtlvAuxView *view, struct BtlvYesNoWork *value)
{
    BTLV_INPUT_ChangeScreen(view->input, BTLV_INPUT_SCREEN_CHOICE, (void *)value);
    view->choiceStep = 0;
}

/* Polls the choice screen: waits for a touch, closes the screen, returns the touched index. */
int BTLV_SCD_PollChoiceScreen(BtlvAuxView *view, u32 *outChoice)
{
    int touched;

    switch (view->choiceStep) {
    case 0:
        touched = BTLV_INPUT_ProcessTouchInput(view->input, &gBtlvScdChoiceRegionsA, gBtlvScdChoiceRegionsB);
        if (touched == -1)
            break;
        view->choiceIndex = touched;
        BTLV_INPUT_ChangeScreen(view->input, BTLV_INPUT_SCREEN_CLOSE, 0);
        view->choiceStep++;
        break;
    case 1:
        if (BTLV_INPUT_IsInputBlocked(view->input) == 0) {
            *outChoice = view->choiceIndex;
            return 1;
        }
        break;
    }
    return 0;
}

/* Returns the address of the input flags byte. */
u8 *BTLV_SCD_GetInputFlags(BtlvAuxView *view)
{
    return &view->inputFlags;
}

/* Begins the close sequence unless it is already active. */
void BTLV_SCD_BeginCloseSequence(BtlvAuxView *view)
{
    if (view->status.bits.active)
        return;
    view->status.bits.step = 0;
    view->status.bits.active = 1;
}

/* Runs the close sequence of the touch screen, one step per call. */
int BTLV_SCD_RunCloseSequence(BtlvAuxView *view)
{
    switch (view->status.bits.step) {
    case 0:
        if (BTLV_INPUT_IsInputBlocked(view->input) == 0)
            view->status.bits.step++;
        break;
    case 1:
        BTLV_INPUT_ChangeScreen(view->input, BTLV_INPUT_SCREEN_CLOSE, 0);
        BTLV_EFFECT_GaugeSelectSlot(8);
        BTLV_EFFECT_StartIntroEffect();
        view->status.bits.step++;
        break;
    case 2:
        if (BTLV_INPUT_IsInputBlocked(view->input) == 0)
            view->status.bits.step++;
        break;
    case 3:
        view->status.bits.active = 0;
        return 1;
    }
    return 0;
}

/* Shows the counter screen. */
void BTLV_SCD_ShowCounterScreen(BtlvAuxView *view, void *payload)
{
    BTLV_INPUT_ChangeScreen(view->input, BTLV_INPUT_SCREEN_COUNTER, payload);
}

/* Polls the touch regions of the counter screen. */
int BTLV_SCD_PollCounterTouch(BtlvAuxView *view)
{
    return BTLV_INPUT_ProcessTouchInput(view->input, &gBtlvScdCounterRegionsA, gBtlvScdCounterRegionsB);
}
