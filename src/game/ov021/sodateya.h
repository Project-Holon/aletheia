#ifndef GAME_OV021_SODATEYA_H
#define GAME_OV021_SODATEYA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sodateya.c, prototypes copied from their definitions. */

struct SodateyaWork;
struct PokemonParam;
struct FieldMap;
struct MyStatus;
struct DayCareEgg;
typedef struct SodateyaWork SodateyaWork;
typedef struct DayCareEgg DayCareEgg;

#include "../types.h"

SodateyaWork *SODATEYA_Create(u32 heapId, void *fieldMap, void *dayCare);
void SODATEYA_Delete(void *work);
void SODATEYA_DepositPokemon(SodateyaWork *work, void *party, u32 partyPos);
void SODATEYA_PrepareDeposit(void *mon);
void SODATEYA_RevertShaymin(void *mon);
void SODATEYA_WithdrawPokemon(SodateyaWork *work, u32 slot, void *party);
void SODATEYA_RegisterCaughtIfNew(SodateyaWork *work, void *mon);
void SODATEYA_ReceiveEgg(SodateyaWork *work, void *party);
void SODATEYA_DeclineEgg(SodateyaWork *work);
int SODATEYA_AddStep(SodateyaWork *work);
void SODATEYA_SetEggFlag(void *fieldMap);
void SODATEYA_ClearEggFlag(void *fieldMap);
int SODATEYA_HasEgg(void *work);
int SODATEYA_GetPokemonCount(SodateyaWork *work);
int SODATEYA_GetCurrentLevel(SodateyaWork *work, u32 slot);
int SODATEYA_GetLevelsGained(SodateyaWork *work, int slot);
int SODATEYA_GetWithdrawCost(SodateyaWork *work, int slot);
u8 SODATEYA_GetCompatibility(SodateyaWork *work);
void *SODATEYA_GetPokemon(SodateyaWork *work, u32 slot);
u32 SODATEYA_AddExpSaturated(u32 exp, u32 gain);
void SODATEYA_GrantExp(void *mon, u32 gain);
void SODATEYA_LearnMove(void *mon, u32 move);
int SODATEYA_MonKnowsMove(void *mon, u32 move);
void SODATEYA_CompactSlots(void *dayCare);
int SODATEYA_CalcCompatibility(struct PokemonParam *monA, struct PokemonParam *monB);
int SODATEYA_CalcCompatibilityScore(struct PokemonParam *monA, struct PokemonParam *monB);
int SODATEYA_UpdateStepCounter(SodateyaWork *work);
void SODATEYA_CreateEggMon(SodateyaWork *work, struct PokemonParam *eggMon);
void SODATEYA_SyncPartyAfterDeposit(struct FieldMap *fieldMap, void *party);
void SODATEYA_BuildEgg(u16 heapId, struct MyStatus *myStatus, u32 metPlace, struct PokemonParam *father, struct PokemonParam *mother, struct PokemonParam *eggMon);
void SODATEYA_SortParentsByGender(struct PokemonParam **parents);
void SODATEYA_PutDittoSecond(struct PokemonParam **parents);
void SODATEYA_SwapParents(struct PokemonParam **parents);
int SODATEYA_InitEgg(DayCareEgg *egg);
void SODATEYA_SetBaseSpecies(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_RollNidoranSpecies(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_RollVolbeatSpecies(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_ApplyPhioneRule(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_ApplyIncenseBabyRule(struct PokemonParam **parents, DayCareEgg *egg);
struct PokemonParam *SODATEYA_GetSpeciesParent(struct PokemonParam **parents);
int SODATEYA_ResetEggForm(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_InheritFormShellos(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_InheritFormBurmy(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_InheritFormBasculin(struct PokemonParam **parents, DayCareEgg *egg);
struct PokemonParam *SODATEYA_GetFormParent(struct PokemonParam **parents);
void SODATEYA_RollNature(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_ApplyEverstoneRule(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_RollAbilitySlot(struct PokemonParam **parents, DayCareEgg *egg, u32 heapId);
void SODATEYA_RollDittoAbilitySlot(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_SetAbilityFromSlot(struct PokemonParam **parents, DayCareEgg *egg, u32 heapId);
void SODATEYA_SetBaseFriendship(DayCareEgg *egg, u32 heapId);
void SODATEYA_ApplyPowerItemRule(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_RollRandomIvInheritance(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_CopyInheritedIvs(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_SetOtId(struct MyStatus *myStatus, DayCareEgg *egg);
void SODATEYA_RollPersonalRnd(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_ApplyMasudaMethod(struct PokemonParam **parents, DayCareEgg *egg);
u32 SODATEYA_RollRandomU32(void);
void SODATEYA_AddLevelUpMoves(DayCareEgg *egg);
void SODATEYA_AddEggMoves(struct PokemonParam **parents, DayCareEgg *egg, u32 heapId);
void SODATEYA_AddSharedMoves(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_AddTmMoves(struct PokemonParam **parents, DayCareEgg *egg, u32 heapId);
void SODATEYA_AddVoltTackle(struct PokemonParam **parents, DayCareEgg *egg);
void SODATEYA_AddMove(DayCareEgg *egg, u32 move);
void SODATEYA_SetupEggMon(struct PokemonParam *mon, const DayCareEgg *egg, struct MyStatus *myStatus, u32 metPlace, u16 heapId);
int SODATEYA_CanLearnTm(u32 heapId, u32 species, u32 form, u32 tmItem);
u16 SODATEYA_GetBaseSpecies(u16 species);
u8 SODATEYA_GetAbilitySlot(u32 species, u32 form, u32 ability, u32 heapId);
/* END mkheaders: generated region */

#endif
