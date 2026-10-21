#ifndef GAME_OV093_BTLV_CORE_H
#define GAME_OV093_BTLV_CORE_H




/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btlv_core.c, prototypes copied from their definitions. */

struct BtlvCore;
struct BtlSide;
struct BtlvDemoWork;
struct BtlPokeParam;
struct BtlvMessage;
struct Strbuf;
struct BtlExpResult;
typedef struct BtlvDemoWork BtlvDemoWork;

#include "../types.h"
#include "../ov093/btlv_core_types.h"
#include "../ov095/btl_pick_list_types.h"
#include "../ov095/btl_pick_list_types.h"
#include "../arm9/printsys_shared_types.h"

void BTLV_CORE_LoadOverlays(unsigned short heapId);
void BTLV_CORE_UnloadOverlays(void);
void BTLV_CORE_ResetDisplay(u16 heapId);
void BTLV_CORE_InitDisplay(u16 heapId);
void BTLV_CORE_ExitDisplay(void);
struct BtlvCore *BTLV_CORE_Create(void *context, void *client, struct BtlSide *monTable, int param, u16 heapId);
void BTLV_CORE_Delete(struct BtlvCore *core);
void BTLV_CORE_Update(struct BtlvCore *core);
void BTLV_CORE_StartOpening(struct BtlvCore *core, u32 state);
int BTLV_CORE_PollOpening(struct BtlvCore *core);
void *BTLV_CORE_GetTaskWork(struct BtlvCore *core, int size);
int BTLV_CORE_StepOpeningEntry(struct BtlvCore *core, int *state, void *work);
int BTLV_CORE_StepOpeningDemo(struct BtlvCore *core, int *state, BtlvDemoWork *demo);
struct BtlPokeParam *BTLV_CORE_GetPokeParamAtViewPos(struct BtlvCore *core, u32 viewPos);
int BTLV_CORE_StepActionMenu(struct BtlvCore *core, int *state, void *work);
int BTLV_CORE_StepTargetMenu(struct BtlvCore *core, int *state, void *work);
void BTLV_CORE_SetStep(struct BtlvCore *core, BtlvCoreStepFn stepFn);
void BTLV_CORE_ClearStep(struct BtlvCore *core);
int BTLV_CORE_RunStep(struct BtlvCore *core);
void BTLV_CORE_StartActionMenu(struct BtlvCore *core, struct BtlPokeParam *pokeParam, int canBack, u8 *cursor);
void BTLV_CORE_AbortActionMenu(struct BtlvCore *core);
int BTLV_CORE_PollActionMenu(struct BtlvCore *core);
void BTLV_CORE_StartMoveMenu(struct BtlvCore *core, struct BtlPokeParam *pokeParam, u8 *cursor);
void BTLV_CORE_StartMoveMenuForEntry(struct BtlvCore *core, struct BtlPokeParam **entry, u8 *cursor);
void BTLV_CORE_ReopenMoveMenu(struct BtlvCore *core);
int BTLV_CORE_StepMoveMenu(struct BtlvCore *core, int *state, void *work);
void BTLV_CORE_AbortMoveMenu(struct BtlvCore *core);
u32 BTLV_CORE_PollMoveMenu(struct BtlvCore *core);
void BTLV_CORE_StartTargetMenu(struct BtlvCore *core, struct BtlPokeParam *pokeParam, u8 *cursor);
int BTLV_CORE_PollTargetMenu(struct BtlvCore *core);
void BTLV_CORE_AbortTargetMenu(struct BtlvCore *core);
void BTLV_CORE_AbortInput(struct BtlvCore *core);
void BTLV_CORE_CloseMenu(struct BtlvCore *core);
void BTLV_CORE_CloseMenuToReselect(struct BtlvCore *core);
int BTLV_CORE_IsMenuClosed(struct BtlvCore *core);
void BTLV_CORE_InitPartyWork(struct BtlvCore *core, BtlvPlistWork *plist, int mode, u8 slot, int modeParam);
void BTLV_CORE_StartPartyMenu(struct BtlvCore *core, const BtlSlotChoices *slotChoices, int slot, int canCancel, BtlPickList *choiceFlags);
void BTLV_CORE_LockPartyChoice(struct BtlvCore *core);
int BTLV_CORE_PollPartyMenu(struct BtlvCore *core);
void BTLV_CORE_StartMoveHighlight(struct BtlvCore *core, u8 slot, u8 kind);
void BTLV_CORE_StartBagMenu(struct BtlvCore *core, int isComm, u8 pointCounter, u8 itemId, u8 isLastSlot, u8 foeSemiInvulnerable);
void BTLV_CORE_SkipBagPartyPrompt(struct BtlvCore *core);
int BTLV_CORE_PollBagMenu(struct BtlvCore *core);
u16 BTLV_CORE_GetSelectedItem(struct BtlvCore *core);
u8 BTLV_CORE_GetSelectedItemCost(struct BtlvCore *core);
u8 BTLV_CORE_GetItemTargetSlot(struct BtlvCore *core);
u8 BTLV_CORE_GetItemTargetFlag(struct BtlvCore *core);
void BTLV_CORE_SaveBagCursors(struct BtlvCore *core);
void BTLV_CORE_StartSceneEffect(struct BtlvCore *core, u32 slotFrom, u32 slotTo, u32 sceneId, u32 argA, u32 argB, u8 flags);
int BTLV_CORE_WaitSceneEffect(struct BtlvCore *core);
void BTLV_CORE_StartDamageEffect(struct BtlvCore *core, u32 animId, u32 slot, u32 effectiveness);
int BTLV_CORE_WaitDamageEffect(struct BtlvCore *core);
int BTLV_CORE_ProcDamageEffect(int *state, struct BtlvCore *core);
void BTLV_CORE_StartHitAnim(struct BtlvCore *core, u32 animId, int slot, int effectiveness);
int BTLV_CORE_WaitHitAnim(struct BtlvCore *core);
int BTLV_CORE_ProcHitAnim(int *state, struct BtlvCore *core);
void BTLV_CORE_StartMultiDamageEffect(struct BtlvCore *core, u32 count, int effectiveness, const u8 *pokeIds, u16 animId);
int BTLV_CORE_ProcMultiDamageEffect(struct BtlvCore *core);
void BTLV_CORE_PlayEffectivenessSe(struct BtlvCore *core, int effectiveness);
void BTLV_CORE_SetMonShown(struct BtlvCore *core, int viewPos, int shown);
void BTLV_CORE_StartMonSpriteUpdate(struct BtlvCore *core, int slot);
int BTLV_CORE_WaitMonSpriteUpdate(struct BtlvCore *core);
void BTLV_CORE_StartViewEffect(struct BtlvCore *core, int viewPos, int effectId);
int BTLV_CORE_WaitViewEffect(struct BtlvCore *core);
void BTLV_CORE_StartViewEffectEx(struct BtlvCore *core, int viewPos, int effectId, u32 param);
int BTLV_CORE_WaitViewEffectEx(void *viewPos);
void BTLV_CORE_StartMonReset(struct BtlvCore *core, int slot);
int BTLV_CORE_WaitMonReset(struct BtlvCore *core);
void BTLV_CORE_StartMonRefresh(struct BtlvCore *core, u32 slot);
int BTLV_CORE_WaitMonRefresh(struct BtlvCore *core);
void BTLV_CORE_StartMonEffectTask(struct BtlvCore *core, u16 viewPos, u16 effectId);
int BTLV_CORE_WaitMonEffectTask(struct BtlvCore *core);
void BTLV_CORE_StartMonSwap(struct BtlvCore *core, u8 slot, u8 clientId, u8 pokeIdx);
int BTLV_CORE_WaitMonSwap(struct BtlvCore *core);
int BTLV_CORE_ProcMonSwap(int *state, struct BtlvCore *core);
void BTLV_CORE_BuildMessage(struct BtlvMessage *msg, struct Strbuf *buf);
void BTLV_CORE_CopyMessageBuffer(struct BtlvCore *core, struct Strbuf *src);
void BTLV_CORE_BuildMessageToBuffer(struct BtlvCore *core, struct BtlvMessage *msg);
void BTLV_CORE_PrintMessageBuffer(struct BtlvCore *core);
void BTLV_CORE_BuildAndPrintMessage(struct BtlvCore *core, struct BtlvMessage *msg);
void BTLV_CORE_BuildAndPrintMessageFlag(struct BtlvCore *core, struct BtlvMessage *msg, PrintCallback callback);
void BTLV_CORE_BuildAndPrintMessageNow(struct BtlvCore *core, struct BtlvMessage *msg);
void BTLV_CORE_PrintSideMessage(struct BtlvCore *core, u16 msgId, u32 *args);
void BTLV_CORE_PrintTaggedMessage(struct BtlvCore *core, u16 msgId, u32 *args);
int BTLV_CORE_PrintTrainerMessage(struct BtlvCore *core, u16 trainerId, u16 msgIndex);
void BTLV_CORE_PrintItemUseMessage(struct BtlvCore *core, u8 clientId, u16 item);
int BTLV_CORE_WaitMessage(struct BtlvCore *core);
int BTLV_CORE_ConsumeMessageFlag(struct BtlvCore *core);
void BTLV_CORE_StartPrintMessage(struct BtlvCore *core, struct Strbuf *buf, u16 speed, PrintCallback callback);
void BTLV_CORE_PrintMessageNow(struct BtlvCore *core, struct Strbuf *buf);
void BTLV_CORE_ShowPortrait(struct BtlvCore *core, u32 slot, u32 flag);
int BTLV_CORE_UpdatePortraitSlideIn(struct BtlvCore *core, u32 slot);
void BTLV_CORE_StartPortraitSlideOut(struct BtlvCore *core, u32 slot);
int BTLV_CORE_WaitPortraitSlideOut(struct BtlvCore *core, u32 slot);
void BTLV_CORE_ReloadPortrait(struct BtlvCore *core, u32 slot);
int BTLV_CORE_UpdatePortraitMosaic(struct BtlvCore *core, u32 slot);
void BTLV_CORE_StartViewEffect262(struct BtlvCore *core, int viewPos);
void BTLV_CORE_StartViewEffect261(struct BtlvCore *core, int viewPos);
int BTLV_CORE_WaitViewEffectDone(struct BtlvCore *core, int viewPos);
void BTLV_CORE_StartWaitMessage(struct BtlvCore *core);
int BTLV_CORE_UpdateWaitMessage(struct BtlvCore *core);
void BTLV_CORE_EndWaitMessage(struct BtlvCore *core);
void BTLV_CORE_StartSlotEffect25F(struct BtlvCore *core, u32 slot);
int BTLV_CORE_WaitSlotEffect25F(struct BtlvCore *core, u32 slot);
void BTLV_CORE_StartMonSpriteLoad(struct BtlvCore *core, u32 slot, u32 mode);
int BTLV_CORE_WaitMonSpriteLoad(struct BtlvCore *core);
void BTLV_CORE_StartMonSpriteChange(struct BtlvCore *core, int viewPos);
int BTLV_CORE_WaitMonSpriteChange(struct BtlvCore *core);
void BTLV_CORE_StartMonSpriteChangeAt(struct BtlvCore *core, u32 viewPos, u32 srcViewPos);
int BTLV_CORE_WaitMonSpriteChangeAt(struct BtlvCore *core);
void BTLV_CORE_StartMonSpriteUnload(struct BtlvCore *core);
int BTLV_CORE_WaitMonSpriteUnload(struct BtlvCore *core);
void BTLV_CORE_StartRotation(struct BtlvCore *core, u32 clientId, u32 rotateA, u32 rotateB, u8 posA, u8 posB);
int BTLV_CORE_WaitRotation(struct BtlvCore *core);
int BTLV_CORE_ProcRotation(int *state, struct BtlvCore *core);
void BTLV_CORE_InitInputWork(struct BtlvCore *core, u8 unused);
int BTLV_CORE_PollWindowModeSelect(struct BtlvCore *core, u8 *outMode);
void BTLV_CORE_CancelWindowModeSelect(struct BtlvCore *core);
void BTLV_CORE_StartClearSidePosition(struct BtlvCore *core, u32 clientId, u32 kind);
int BTLV_CORE_RunProc(struct BtlvCore *core);
int BTLV_CORE_ProcClearSidePosition(int *state, struct BtlvCore *core);
void BTLV_CORE_StartYesNoMenu(struct BtlvCore *core, struct BtlvMessage *yesMsg, struct BtlvMessage *noMsg, u32 mode);
int BTLV_CORE_PollYesNoMenu(struct BtlvCore *core, int *outResult);
void BTLV_CORE_StartMoveForgetScreen(struct BtlvCore *core, u8 pokeSlot, int moveId);
int BTLV_CORE_ProcMoveForgetScreen(struct BtlvCore *core, u8 *outSlot);
void BTLV_CORE_StartBallWindowOpen(struct BtlvCore *core, void **pokeParam, struct BtlExpResult *result);
int BTLV_CORE_UpdateBallWindowOpen(struct BtlvCore *core);
void BTLV_CORE_StartBallWindowRefresh(struct BtlvCore *core);
int BTLV_CORE_UpdateBallWindowRefresh(struct BtlvCore *core);
void BTLV_CORE_StartBallWindowClose(struct BtlvCore *core);
int BTLV_CORE_UpdateBallWindowClose(struct BtlvCore *core);
void BTLV_CORE_StartFadeIn(struct BtlvCore *core);
int BTLV_CORE_PollFadeInDone(struct BtlvCore *core);
void BTLV_CORE_ClearWaitWindow(struct BtlvCore *core);
int BTLV_CORE_GetWaitState(struct BtlvCore *core);
void BTLV_CORE_StartAutoSelectNotice(struct BtlvCore *core);
int BTLV_CORE_PollAutoSelectNotice(struct BtlvCore *core);
int BTLV_CORE_PollCounterInput(struct BtlvCore *core);
void BTLV_CORE_SetCounterDisplay(struct BtlvCore *core, u32 current, u32 target);
void BTLV_CORE_ShowCounterValue(struct BtlvCore *core, int value);
void BTLV_CORE_SetCounterValueMode(struct BtlvCore *core, int value, int mode);
/* END mkheaders: generated region */

#endif
