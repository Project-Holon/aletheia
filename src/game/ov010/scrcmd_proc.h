#ifndef GAME_OV010_SCRCMD_PROC_H
#define GAME_OV010_SCRCMD_PROC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_proc.c, prototypes copied from their definitions. */

struct ScriptVm;
struct ScrcmdWork;
struct PokemonParam;
struct PokemonSpec;
struct BagCloseData;
struct GtsCallbackData;
struct RelearnCallbackData;
typedef struct PokemonSpec PokemonSpec;
typedef struct BagCloseData BagCloseData;
typedef struct GtsCallbackData GtsCallbackData;
typedef struct RelearnCallbackData RelearnCallbackData;

#include "../types.h"

int SCRCMD_PROC_LookupTableValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetPartyMember(struct ScrcmdWork *cmdWork, u32 partyIndex, void **outMemberArg);
int SCRCMD_PROC_GetPartyMemberParam(struct ScrcmdWork *cmdWork, u32 partyIndex, u32 paramId);
int SCRCMD_PROC_CheckMonKnowsMove(struct PokemonParam *mon, int moveId);
int SCRCMD_PROC_GetMonPairedParams(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_HealParty(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetMonEvTotal(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CheckMonHpNotFullOrEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CheckMonIsEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetMonFriendship(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_ChangeMonFriendship(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetMonSpeciesOrEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetMonForm(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FindFirstPartyIndex(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetPartyCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CountPartyMonsOfSpecies(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetBoxMonCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FindPartyMonBySpecies(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CheckPartyMonKnowsMove(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FindPartyMonWithMove(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_AddMonToPartySimple(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_AddMonToPartyDetailed(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CountMonMoves(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetMonMove(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_SetMonMove(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CheckMonIsPlayerOwned(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_ChangeMonForm(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_SetRotomFormMove(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetRelearnableMoveCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CheckMonParamMatchesTable(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetMonTripleParams(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_SetMonParamChecked(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetMonParamIfListed(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_AddMonToBoxSimple(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_AddMonToBoxDetailed(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_AddEggToParty(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
void *SCRCMD_PROC_CreateMonFromSpec(void *gameData, PokemonSpec *spec);
int SCRCMD_PROC_AddMonToBox(void *gameData, PokemonSpec *spec);
int SCRCMD_PROC_AddMonToParty(void *gameData, PokemonSpec *spec);
int SCRCMD_PROC_AddMoney(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_SubMoney(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CheckMoneyAtLeast(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CallFieldOpenEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CallFieldCloseEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_WaitOverlayProc(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FreeScriptUserWork(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
void SCRCMD_PROC_OnBagClosed(BagCloseData *closeData);
int SCRCMD_PROC_CallBagScreen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
void SCRCMD_PROC_OnGtsNegotiationDone(GtsCallbackData *callbackData);
int SCRCMD_PROC_CallGtsNegotiation(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_OnMoveRelearnDone(RelearnCallbackData *callbackData, int callArg1);
int SCRCMD_PROC_CallMoveRelearn(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CallPlayerProfile(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CallSubEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CallValueScreen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CallModeScreen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CallWordScreen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_WaitNothing(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CallWifiBattleMatch(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CallMenuProc(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_Ov037InitFromVars(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_Ov037SetValueA(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_Ov037SetValueB(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_Ov037ReadEightVars(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_Ov037Finish(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CheckDaycareHasEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_ReceiveDaycareEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_DeclineDaycareEgg(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_CallDaycarePartyMenu(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_DepositDaycareMon(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_WithdrawDaycareMon(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetDaycareMonCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetDaycareCompatibility(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetDaycareMonSpecies(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetDaycareMonForm(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetDaycareMonGender(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetDaycareSlotLevel(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetDaycareSlotLevelsGrown(void *vm,void *cmdWork);
int SCRCMD_PROC_GetDaycareSlotPrice(void *vm,void *cmdWork);
int SCRCMD_PROC_GetDaycareMonGenderKindIfFirst(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_GetDaycareGenderKind(void *mon);
/* END mkheaders: generated region */

#endif
