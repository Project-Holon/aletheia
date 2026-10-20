#ifndef GAME_OV010_SCRCMD_PROC_H
#define GAME_OV010_SCRCMD_PROC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_proc.c, prototypes copied from their definitions. */

struct ScriptVm;
struct PokemonSpec;
struct BagCloseData;
struct GtsCallbackData;
typedef struct PokemonSpec PokemonSpec;
typedef struct BagCloseData BagCloseData;
typedef struct GtsCallbackData GtsCallbackData;

#include "../types.h"

int SCRCMD_PROC_LookupTableValue(int vm,int cmdWork);
int SCRCMD_PROC_GetPartyMember(void *cmdWork, u32 partyIndex, void **outMemberArg);
int SCRCMD_PROC_GetPartyMemberParam(void *cmdWork, void *partyIndex, void *paramId);
int SCRCMD_PROC_CheckMonKnowsMove(int callArg0, int callArg1);
int SCRCMD_PROC_GetMonPairedParams(int vm, int cmdWork);
int SCRCMD_PROC_HealParty(int callArg0, int callArg1);
int SCRCMD_PROC_GetMonEvTotal(void *vm, void *cmdWork);
int SCRCMD_PROC_CheckMonHpNotFullOrEgg(int callArg0, int callArg1, int callArg2);
int SCRCMD_PROC_CheckMonIsEgg(int callArg0, int callArg1, int callArg2);
int SCRCMD_PROC_GetMonFriendship(int callArg0, int callArg1, int callArg2);
int SCRCMD_PROC_ChangeMonFriendship(int vm, int cmdWork);
int SCRCMD_PROC_GetMonSpeciesOrEgg(int vm,int cmdWork);
int SCRCMD_PROC_GetMonForm(int callArg0, int callArg1, int callArg2);
int SCRCMD_PROC_FindFirstPartyIndex(int callArg0, int callArg1);
int SCRCMD_PROC_GetPartyCount(void *vm, void *cmdWork);
int SCRCMD_PROC_CountPartyMonsOfSpecies(void *vm, void *cmdWork);
int SCRCMD_PROC_GetBoxMonCount(void *vm, void *cmdWork);
int SCRCMD_PROC_FindPartyMonBySpecies(void *vm, void *cmdWork);
int SCRCMD_PROC_CheckPartyMonKnowsMove(int callArg0, int callArg1, int callArg2);
int SCRCMD_PROC_FindPartyMonWithMove(void *vm, void *cmdWork);
int SCRCMD_PROC_AddMonToPartySimple(void *vm, void *cmdWork);
int SCRCMD_PROC_AddMonToPartyDetailed(void *vm, void *cmdWork);
int SCRCMD_PROC_CountMonMoves(int callArg0, int callArg1, int callArg2);
int SCRCMD_PROC_GetMonMove(void *vm, void *cmdWork);
int SCRCMD_PROC_SetMonMove(void *vm, void *cmdWork);
int SCRCMD_PROC_CheckMonIsPlayerOwned(void *vm, void *cmdWork);
int SCRCMD_PROC_ChangeMonForm(void *vm, void *cmdWork);
int SCRCMD_PROC_SetRotomFormMove(void *vm, void *cmdWork);
int SCRCMD_PROC_GetRelearnableMoveCount(int callArg0, int callArg1, int callArg2);
int SCRCMD_PROC_CheckMonParamMatchesTable(void *vm, void *cmdWork);
int SCRCMD_PROC_GetMonTripleParams(void *vm, void *cmdWork);
int SCRCMD_PROC_SetMonParamChecked(void *vm, void *cmdWork);
int SCRCMD_PROC_GetMonParamIfListed(void *vm, void *cmdWork);
int SCRCMD_PROC_AddMonToBoxSimple(void *vm, void *cmdWork);
int SCRCMD_PROC_AddMonToBoxDetailed(void *vm, void *cmdWork);
int SCRCMD_PROC_AddEggToParty(void *vm, void *cmdWork);
void *SCRCMD_PROC_CreateMonFromSpec(void *gameData, PokemonSpec *spec);
int SCRCMD_PROC_AddMonToBox(void *gameData, void *spec);
int SCRCMD_PROC_AddMonToParty(void *gameData, void *spec);
int SCRCMD_PROC_AddMoney(int vm,int cmdWork);
int SCRCMD_PROC_SubMoney(int vm,int cmdWork);
int SCRCMD_PROC_CheckMoneyAtLeast(void *vm, void *cmdWork);
int SCRCMD_PROC_CallFieldOpenEvent(void *vm, void *cmdWork);
int SCRCMD_PROC_CallFieldCloseEvent(int callArg0, int callArg1);
void SCRCMD_PROC_StartOverlayProc(struct ScriptVm *vm, void *cmdWork, u32 overlayId, const void *procData, void *procWork, u32 onFinish, u32 userData);
int SCRCMD_PROC_WaitOverlayProc(int callArg0, int callArg1);
int SCRCMD_PROC_FreeScriptUserWork(int callArg0, int callArg1);
void SCRCMD_PROC_OnBagClosed(BagCloseData *closeData);
int SCRCMD_PROC_CallBagScreen(void *vm, void *cmdWork);
void SCRCMD_PROC_OnGtsNegotiationDone(GtsCallbackData *callbackData);
int SCRCMD_PROC_CallGtsNegotiation(void *vm, void *cmdWork);
int SCRCMD_PROC_OnMoveRelearnDone(int callArg0, int callArg1);
int SCRCMD_PROC_CallMoveRelearn(void *vm, void *cmdWork);
int SCRCMD_PROC_CallPlayerProfile(void *vm, void *cmdWork);
int SCRCMD_PROC_CallSubEvent(void *vm, void *cmdWork);
int SCRCMD_PROC_CallValueScreen(void *vm, void *cmdWork);
int SCRCMD_PROC_CallModeScreen(void *vm, void *cmdWork);
int SCRCMD_PROC_CallWordScreen(void *vm, void *cmdWork);
int SCRCMD_PROC_WaitNothing(int callArg0, int callArg1);
int SCRCMD_PROC_CallWifiBattleMatch(void *vm, void *cmdWork);
int SCRCMD_PROC_CallMenuProc(void *vm, void *cmdWork);
int SCRCMD_PROC_Ov037InitFromVars(void *vm, void *cmdWork);
int SCRCMD_PROC_Ov037SetValueA(void *vm, void *cmdWork);
int SCRCMD_PROC_Ov037SetValueB(void *vm, void *cmdWork);
int SCRCMD_PROC_Ov037ReadEightVars(void *vm, void *cmdWork);
int SCRCMD_PROC_Ov037Finish(void *vm, void *cmdWork);
int SCRCMD_PROC_CheckDaycareHasEgg(int callArg0, int callArg1);
int SCRCMD_PROC_ReceiveDaycareEgg(void *vm, void *cmdWork);
int SCRCMD_PROC_DeclineDaycareEgg(int callArg0, int callArg1);
int SCRCMD_PROC_CallDaycarePartyMenu(void *vm, void *cmdWork);
int SCRCMD_PROC_DepositDaycareMon(void *vm, void *cmdWork);
int SCRCMD_PROC_WithdrawDaycareMon(void *vm, void *cmdWork);
int SCRCMD_PROC_GetDaycareMonCount(int callArg0, int callArg1);
int SCRCMD_PROC_GetDaycareCompatibility(int callArg0, int callArg1);
int SCRCMD_PROC_GetDaycareMonSpecies(void *vm, void *cmdWork);
int SCRCMD_PROC_GetDaycareMonForm(void *vm, void *cmdWork);
int SCRCMD_PROC_GetDaycareMonGender(void *vm, void *cmdWork);
int SCRCMD_PROC_GetDaycareSlotLevel(void *vm, void *cmdWork);
int SCRCMD_PROC_GetDaycareSlotLevelsGrown(void *vm,void *cmdWork);
int SCRCMD_PROC_GetDaycareSlotPrice(void *vm,void *cmdWork);
int SCRCMD_PROC_GetDaycareMonGenderKindIfFirst(void *vm, void *cmdWork);
int SCRCMD_PROC_GetDaycareGenderKind(void *mon);
/* END mkheaders: generated region */

#endif
