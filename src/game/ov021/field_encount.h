#ifndef GAME_OV021_FIELD_ENCOUNT_H
#define GAME_OV021_FIELD_ENCOUNT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_encount.c, prototypes copied from their definitions. */

struct FieldEncountParam;
struct GameData;
struct EncountMon;
struct Roamer;
struct FieldWfbc;
struct PokemonParam;
struct SwarmEntry;
struct PersonalData;
struct FieldMap;
struct GameEvent;
struct BattleSetupParam;
struct FieldSituation;
struct EncountStepWork;
struct FieldPlayer;
typedef struct FieldEncountParam FieldEncountParam;
typedef struct EncountMon EncountMon;
typedef struct SwarmEntry SwarmEntry;
typedef struct EncountStepWork EncountStepWork;

#include "../types.h"
#include "../ov021/field_encount_types.h"

void FIELD_ENCOUNT_SetupParam(FieldEncountParam *param, struct GameData *gameData, int encountType, int triggerMode, u16 weather);
u32 FIELD_ENCOUNT_CalcEncountRate(FieldEncountParam *param, struct GameData *gameData, u32 baseRate);
int FIELD_ENCOUNT_CreateWildMons(FieldEncountParam *param, EncountSlot *slots, EncountMon *mons);
int FIELD_ENCOUNT_CreateZoneWildMons(EncountData *encountData, FieldEncountParam *param, u16 zoneId, EncountMon *mons);
struct Roamer *FIELD_ENCOUNT_PickRoamer(EncountData *encountData, FieldEncountParam *param, u32 zoneId);
u32 FIELD_ENCOUNT_PickWfbcMon(struct FieldWfbc *wfbc, FieldEncountParam *param, EncountMon *mon);
void FIELD_ENCOUNT_InitWildPokemon(struct PokemonParam *pp, const FieldEncountParam *param, EncountMon *encMon);
void FIELD_ENCOUNT_InitRoamerPokemon(struct PokemonParam *pp, const FieldEncountParam *param, struct Roamer *roamer);
u16 FIELD_ENCOUNT_GetSwarmZoneId(struct GameData *gameData);
void FIELD_ENCOUNT_ApplyLeadAbility(FieldEncountParam *param, u16 weather);
int FIELD_ENCOUNT_IsRepelled(FieldEncountParam *param, u8 level);
const SwarmEntry *FIELD_ENCOUNT_GetSwarmEntry(struct GameData *gameData);
int FIELD_ENCOUNT_TrySwarmSlot(EncountData *encountData, FieldEncountParam *param, u16 zoneId, EncountSlot *slot);
u8 FIELD_ENCOUNT_LoadSlots(EncountData *encountData, FieldEncountParam *param, u16 zoneId, EncountSlot *slots);
void FIELD_ENCOUNT_RollSlotMon(EncountSlot *slot, EncountMon *mon);
u8 FIELD_ENCOUNT_PickSlotByType(FieldEncountParam *param, EncountSlot *slots, u32 type);
void FIELD_ENCOUNT_ApplyHighLevelBias(const FieldEncountParam *param, const EncountSlot *slots, EncountMon *mon);
void FIELD_ENCOUNT_SelectMon(FieldEncountParam *param, EncountSlot *slots, EncountMon *mon);
void FIELD_ENCOUNT_RollHeldItem(struct PokemonParam *pp, struct PersonalData *personal, int compoundEyes, int isDarkGrass);
u32 FIELD_ENCOUNT_CreatePersonality(const FieldEncountParam *param, struct PersonalData *personal, EncountMon *encMon);
u32 FIELD_ENCOUNT_RandPercent(void);
u32 FIELD_ENCOUNT_PickGroundSlot(u8 slotCount);
u32 FIELD_ENCOUNT_PickWaterSlot(u8 slotCount);
u32 FIELD_ENCOUNT_PickFishingSlot(u8 slotCount);
u32 FIELD_ENCOUNT_PickRandomSlot(u32 slotCount);
FieldEncount *FIELD_ENCOUNT_Create(struct FieldMap *fieldMap);
void FIELD_ENCOUNT_Delete(FieldEncount *encount);
struct GameEvent *FIELD_ENCOUNT_CheckWildEncount(FieldEncount *encount, int triggerMode);
struct GameEvent *FIELD_ENCOUNT_StartScriptedWild(FieldEncount *encount, u16 species, u8 level, u32 flags);
struct BattleSetupParam *FIELD_ENCOUNT_CheckFishingEncount(FieldEncount *encount, int triggerMode);
struct GameEvent *FIELD_ENCOUNT_CheckWfbcEncount(FieldEncount *encount, struct FieldWfbc *wfbc);
void FIELD_ENCOUNT_SetFieldSituation(struct FieldSituation *situation, struct GameData *gameData, struct FieldMap *fieldMap);
int FIELD_ENCOUNT_GetEncountType(FieldEncount *encount, int triggerMode, u8 *rateBonus);
int FIELD_ENCOUNT_GetEncountRate(FieldEncount *encount, int encountType, int rateBonus);
int FIELD_ENCOUNT_CheckEncountRoll(FieldEncount *encount, EncountStepWork *stepWork, u32 rate);
int FIELD_ENCOUNT_CheckWfbcRoll(EncountStepWork *stepWork, struct FieldWfbc *wfbc);
void FIELD_ENCOUNT_SetupWildBattle(FieldEncount *encount, FieldEncountParam *param, struct BattleSetupParam *btlSetup, u16 heapId, EncountMon *mons);
void FIELD_ENCOUNT_SetupRoamerBattle(FieldEncount *encount, const FieldEncountParam *param, struct BattleSetupParam *btlSetup, u16 heapId, struct Roamer *roamer);
void FIELD_ENCOUNT_SetupTrainerBattle(FieldEncount *encount, struct BattleSetupParam *btlSetup, u32 rule, u32 partnerId, u32 trainerId1, u32 trainerId2, u16 heapId);
u8 FIELD_ENCOUNT_GetBattleWeather(struct FieldMap *fieldMap);
u32 FIELD_ENCOUNT_RandRatePercent(void);
void FIELD_ENCOUNT_ResetStepWork(EncountStepWork *stepWork, struct FieldPlayer *player);
void FIELD_ENCOUNT_UpdateStepWork(EncountStepWork *stepWork, struct FieldPlayer *player);
u32 FIELD_ENCOUNT_GetStepCount(EncountStepWork *stepWork);
/* END mkheaders: generated region */

#endif
