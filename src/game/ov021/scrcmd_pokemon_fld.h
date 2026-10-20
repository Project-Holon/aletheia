#ifndef GAME_OV021_SCRCMD_POKEMON_FLD_H
#define GAME_OV021_SCRCMD_POKEMON_FLD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_pokemon_fld.c, prototypes copied from their definitions. */

struct ScriptVm;
struct ScrcmdWork;
struct ThresholdEntry;
struct WarpEntry;
struct GameData;
struct FieldMap;
struct PokemonParam;
struct WordSet;
typedef struct ThresholdEntry ThresholdEntry;
typedef struct WarpEntry WarpEntry;
typedef struct ScrcmdWork ScrcmdWork;

#include "../types.h"
#include "../ov021/scrcmd_pokemon_fld_types.h"
#include "../ov010/fldmmdl_types.h"

int SCRCMD_POKEMON_FLD_SelectPartyMon(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_StoreMonRecord(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_StorePartySpeciesRecord(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_RegisterRecordSpecies(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_GetMonIvStat(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_LookupThreshold(ThresholdEntry *table, int count);
int SCRCMD_POKEMON_FLD_GetPokedexRating(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_GetPokedexComplete(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_GetTutorMoveId(void *mon, int tutorKind);
int SCRCMD_POKEMON_FLD_GetTutorFriendship(int tutorKind);
int SCRCMD_POKEMON_FLD_CheckTutorGroup(void *mon, int tutorKind);
int SCRCMD_POKEMON_FLD_FindTutorCandidates(struct ScriptVm *vm, struct ScrcmdWork *work, int tutorKind, u8 *eligibleMask, u32 checkFriendship);
int SCRCMD_POKEMON_FLD_GetTutorAvailability(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_GetMonTutorMove(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_CheckMonTutorStatus(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_SelectTutorMon(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_CheckPartyFlagged(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_GetMonTypeForTm(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_StartSelectEvent(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_SelectMonMove(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_StartEggHatch(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_CheckTradeMon(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_StartTradeEvent(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_GetRandomBagPocketValue(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_StoreMonName(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_RegisterStoredName(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_ControlLegendMon(struct ScriptVm *vm, struct ScrcmdWork *work);
void SCRCMD_POKEMON_FLD_SwapPartyMonWithBoxedLegend(struct ScrcmdWork *work, int partySlot);
int SCRCMD_POKEMON_FLD_FindBoxedLegend(void *gameData, u16 species, u16 *boxOut, u16 *slotOut);
void SCRCMD_POKEMON_FLD_MoveLegendToFront(struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_FindPartyLegend(void *gameData);
int SCRCMD_POKEMON_FLD_StartOv55SubProc(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_RegisterBirthdayEntry(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_GetMysteryEntryCount(struct ScriptVm *vm, struct ScrcmdWork *work);
WarpEntry *SCRCMD_POKEMON_FLD_GetWarpEntry(WarpEntry *table, u32 index);
void SCRCMD_POKEMON_FLD_NoopWarpEntry(u16 *labelId);
int SCRCMD_POKEMON_FLD_CountWarpEntries(WarpEntry *table);
int SCRCMD_POKEMON_FLD_SetWarpTable(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_AddWarpMenuItems(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_WarpToEntry(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_HandleMysteryGift(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_CheckGiftCanReceive(int giftKind, struct ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_PrepareGiftReceiveMessage(int giftKind, MysteryGiftCard *card, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_PrepareGiftFollowUpMessage(int giftKind, MysteryGiftCard *card, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_ReceiveGift(int giftKind, struct ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_GetGiftReceiveType(int giftKind, ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
u16 SCRCMD_POKEMON_FLD_GetDeliveryNpcId(struct FieldMap *fieldMap, struct GameData *gameData);
u16 SCRCMD_POKEMON_FLD_CheckDeliveryNpcLoaded(struct FieldMap *fieldMap);
Mmdl *SCRCMD_POKEMON_FLD_FindDeliveryMmdl(struct FieldMap *fieldMap);
int SCRCMD_POKEMON_FLD_FindDeliveryNpcObjId(struct GameData *gameData);
int SCRCMD_POKEMON_FLD_IsLibertyPassGift(MysteryGiftCard *card, int giftType);
struct PokemonParam *SCRCMD_POKEMON_FLD_CreateGiftMon(ScrcmdWork *work, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_CheckGiftMonCanReceive(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
void SCRCMD_POKEMON_FLD_ReceiveGiftMon(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_GetGiftMonReceiveType(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_PrepareGiftMonMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_PrepareGiftMonFollowUpMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_CheckGiftItemCanReceive(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
void SCRCMD_POKEMON_FLD_ReceiveGiftItem(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_GetGiftItemReceiveType(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_PrepareGiftItemMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_PrepareGiftItemFollowUpMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_CheckGiftFlagCanReceive(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
void SCRCMD_POKEMON_FLD_ReceiveGiftFlag(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_GetGiftFlagReceiveType(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_PrepareGiftFlagMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_PrepareGiftFlagFollowUpMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_LookupTableValue(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_CheckTableItemInBag(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_RegisterTableValueNumber(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_AddTableValueToPoints(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_GetDailyGift(void *core, void *work);
int SCRCMD_POKEMON_FLD_IsSpecialDate(u32 month, int day);
int SCRCMD_POKEMON_FLD_GetDailyGiftIndex(void *core, void *work);
/* END mkheaders: generated region */

#endif
