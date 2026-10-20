#ifndef GAME_OV091_POKELIST_H
#define GAME_OV091_POKELIST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokelist.c, prototypes copied from their definitions. */

struct Proc;
struct Descriptor;

#include "../ov091/pokelist_types.h"
#include "../ov091/pokelist_types.h"
#include "../types.h"

int POKELIST_Init(struct Proc *procObj, int *seq, PokelistArg *arg, PokelistWork *work);
int POKELIST_Exit(int procObj, int procArg, int procState, PokelistWork *work);
int POKELIST_Main(int procObj, int procArg, int procState, PokelistWork *work);
int POKELIST_InitWork(PokelistWork *work);
int POKELIST_ExitWork(PokelistWork *work);
int POKELIST_UpdatePhase(PokelistWork *work);
void POKELIST_UpdatePaletteFade(PokelistWork *work);
void POKELIST_UpdateWindowMaskTask(void *tcb, PokelistWork *work);
void POKELIST_SetupDisplay(PokelistWork *work);
void POKELIST_SetupBgPlanes(PokelistWork *work);
void POKELIST_SetupLight(PokelistWork *work);
void POKELIST_ShutdownDisplay(PokelistWork *work);
void POKELIST_ShutdownBgPlane0(PokelistWork *work);
void POKELIST_ShutdownLight(PokelistWork *work);
void POKELIST_LoadBgPlane(const void *work, u8 id,unsigned type);
void POKELIST_CreateClactUnit(PokelistWork *work);
void POKELIST_DeleteClactUnit(PokelistWork *work);
void POKELIST_CreateFonts(PokelistWork *work);
void POKELIST_DeleteFonts(PokelistWork *work);
void POKELIST_LoadGraphics(PokelistWork *work);
void POKELIST_FreeGraphics(PokelistWork *work);
void POKELIST_StartMode(PokelistWork *work);
void POKELIST_SetupModeScreen(PokelistWork *work);
void POKELIST_ApplySelection(PokelistWork *work);
void POKELIST_OpenContextMenu(PokelistWork *work);
void POKELIST_UpdateInputStage(PokelistWork *work);
void POKELIST_RefreshCursor(PokelistWork *work);
void POKELIST_HandleCommand(PokelistWork *work);
void POKELIST_UpdateSwapCommand(PokelistWork *work);
void POKELIST_UpdateHealShareCommand(PokelistWork *work);
void POKELIST_ConfirmBattleParty(PokelistWork *work);
void POKELIST_UpdateCursorInput(PokelistWork *work);
void POKELIST_ReadCursorKeys(PokelistWork *work);
void POKELIST_HandleTouch(PokelistWork *work);
void POKELIST_MoveCursorToPlate(PokelistWork *work, int plateIndex);
void POKELIST_MoveSwapMarkerToPlate(PokelistWork *work, int plateIndex);
void POKELIST_RunContextMenu(PokelistWork *work);
void POKELIST_EnterMenuPhase(PokelistWork *work);
void POKELIST_CloseContextMenu(PokelistWork *work);
void POKELIST_DispatchMenuChoice(PokelistWork *work);
void POKELIST_UpdateMessagePhase(PokelistWork *work);
void POKELIST_ShowMessage(PokelistWork *work, int messageId, int waitForKey, PokelistFn onDone);
void POKELIST_PollContextMenuChoice(PokelistWork *work);
void POKELIST_OpenMenuWithCallback(PokelistWork *work, PokelistMenuFn onChoice);
void POKELIST_UpdateSwapAnimation(PokelistWork *work);
void POKELIST_StartSwapAnimation(PokelistWork *work);
void POKELIST_FinishSwap(PokelistWork *work);
int POKELIST_GetFieldMoveMenuIndex(void *mon, int moveSlot);
int POKELIST_IsItemMode(PokelistWork *work);
int POKELIST_IsNotItemUseMode(PokelistWork *work);
int POKELIST_HasBackButton(PokelistWork *work);
int POKELIST_GetMoveLearnStatus(PokelistWork *work, void *mon, u8 partySlot);
u32 POKELIST_CheckEvolution(PokelistWork *work, void *mon, u32 param);
void POKELIST_PrintTextMain(PokelistWork *work, struct Descriptor *window, u32 messageId, int x, s16 y, u16 color);
void POKELIST_PrintTextSub(PokelistWork *work, struct Descriptor *window, u32 messageId, u32 x, s16 y, u16 color);
void POKELIST_PrintTextSubDirect(PokelistWork *work, struct Descriptor *window, u32 messageId, u32 x, s16 y, u16 color);
void POKELIST_PrintExpandedTextMain(PokelistWork *work, struct Descriptor *window, void *wordSet, u32 messageId, s16 x, s16 y, u16 color);
void POKELIST_PrintExpandedTextSub(PokelistWork *work, struct Descriptor *window, void *wordSet, u32 messageId, s16 x, s16 y, u16 color);
void POKELIST_PrintExpandedTextSubDirect(PokelistWork *work, struct Descriptor *window, void *wordSet, u32 messageId, s16 x, s16 y, u16 color);
void POKELIST_CloseMessageToList(PokelistWork *work);
void POKELIST_EndMessageToExit(PokelistWork *work);
void POKELIST_CloseMessageIfItemInBag(PokelistWork *work);
void POKELIST_OpenGiveUpMoveMenu(PokelistWork *work);
void POKELIST_OnGiveUpMoveChoice(PokelistWork *work, int choice);
void POKELIST_OpenForgetMoveMenu(PokelistWork *work);
void POKELIST_OnForgetMoveChoice(PokelistWork *work, int choice);
void POKELIST_ShowMoveLearned(PokelistWork *work);
void POKELIST_OpenTakeItemMenu(PokelistWork *work);
void POKELIST_OnTakeItemChoice(PokelistWork *work, int choice);
void POKELIST_StartHpTransfer(PokelistWork *work);
void POKELIST_ShowHealResult(PokelistWork *work);
void POKELIST_OpenTakeMailMenu(PokelistWork *work);
void POKELIST_OnTakeMailChoice(PokelistWork *work, int choice);
void POKELIST_OpenMailItemMenu(PokelistWork *work);
void POKELIST_OnMailItemChoice(PokelistWork *work, int choice);
void POKELIST_EndMessageToEvolve(PokelistWork *work);
void POKELIST_ForceSelectionEnd(PokelistWork *work);
u32 POKELIST_TryLearnMove(PokelistWork *work, void *mon);
void POKELIST_ReplaceMoveSlot(PokelistWork *work, void *mon, u8 slot);
void POKELIST_ApplyItemEffect(PokelistWork *work, void *mon);
void POKELIST_SetHeldItem(PokelistWork *work, void *mon, u16 itemId);
u32 POKELIST_CheckBagItem(PokelistWork *work, u16 itemId);
u32 POKELIST_RemoveBagItem(PokelistWork *work, u16 itemId);
u32 POKELIST_ReturnBagItem(PokelistWork *work, u16 itemId);
/* END mkheaders: generated region */

#endif
