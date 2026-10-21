#ifndef GAME_ARM9_POKE_TOOL_H
#define GAME_ARM9_POKE_TOOL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of poke_tool.c, prototypes copied from their definitions. */

struct PokemonParam;
struct BoxPokemon;
struct MyStatus;
struct PersonalData;
struct PartyPokemon;

#include "../types.h"
#include "../arm9/poke_tool_shared_types.h"

void POKE_TOOL_InitSystem(u32 heapId);
u32 POKE_TOOL_GetBoxParamSize(void);
u32 POKE_TOOL_GetPartyParamSize(void);
struct PokemonParam *POKE_TOOL_Create(u16 species, u16 level, u64 otId, u16 heapId);
struct PokemonParam *POKE_TOOL_CreateEx(u16 species, u16 level, u64 otId, u32 ivs, u64 personality, u16 heapId);
struct PokemonParam *POKE_TOOL_CreateFromBoxParam(struct PokemonParam *src, u16 heapId);
void POKE_TOOL_ClearPartyParam(struct PokemonParam *pp);
void POKE_TOOL_ClearBoxParam(struct BoxPokemon *box);
void POKE_TOOL_SetupPartyParam(struct PokemonParam *pp, u16 species, u16 level, u64 otId);
void POKE_TOOL_SetupPartyParamEx(struct PokemonParam *pp, u16 species, u16 level, u64 otId, u32 ivs, u64 personality);
void POKE_TOOL_SetupBoxParam(struct BoxPokemon *box, u16 species, u16 level, u64 otId);
void POKE_TOOL_SetupBoxParamEx(struct BoxPokemon *box, u16 species, u16 level, u64 otId, u32 ivs, u64 personality);
void POKE_TOOL_ChangeSpecies(struct PokemonParam *pp, u32 species);
u32 POKE_TOOL_ChangeBoxSpecies(struct BoxPokemon *box, u32 newSpecies);
u32 POKE_TOOL_ChangeForm(struct PokemonParam *pp, u32 form);
int POKE_TOOL_ChangeBoxForm(struct BoxPokemon *box, int newForm);
u32 POKE_TOOL_SetRotomFormMove(struct PokemonParam *pp, u32 formIndex, u32 fallbackSlot);
void POKE_TOOL_HatchEgg(struct PokemonParam *pp, PokeToolArg trainer, u32 location, u32 arg);
u32 POKE_TOOL_HatchBoxEgg(struct BoxPokemon *box, PokeToolArg trainer, u32 location, u32 arg);
void POKE_TOOL_DeleteMoveSlot(struct PokemonParam *pp, u32 slot);
void POKE_TOOL_UpdateAbilityForSpecies(struct BoxPokemon *box, int newSpecies, int oldSpecies);
void POKE_TOOL_UpdateGenderForSpecies(struct BoxPokemon *box, u32 newSpecies, u32 oldSpecies);
u32 POKE_TOOL_DecodePartyParam(struct PokemonParam *pp);
u32 POKE_TOOL_EncodePartyParam(struct PokemonParam *pp, u32 didDecode);
u32 POKE_TOOL_DecodeBoxParam(struct BoxPokemon *box);
u32 POKE_TOOL_EncodeBoxParam(struct BoxPokemon *box, u32 didDecode);
u32 POKE_TOOL_GetPartyValue(struct PokemonParam *pp, u32 paramId, PokeToolArg arg);
void POKE_TOOL_SetPartyValue(struct PokemonParam *pp, u32 paramId, PokeToolArg value);
void POKE_TOOL_SetBoxValue(struct BoxPokemon *box, u32 paramId, PokeToolArg value);
u32 POKE_TOOL_GetBoxValue(struct BoxPokemon *box, u32 paramId, PokeToolArg arg);
u32 POKE_TOOL_IsShiny(struct PokemonParam *pp);
u32 POKE_TOOL_IsBoxShiny(struct BoxPokemon *box);
u32 POKE_TOOL_IsShinyOtIdPersonality(u32 otId, u32 personality);
u8 POKE_TOOL_GetGender(struct PokemonParam *pp);
u8 POKE_TOOL_GetBoxGender(struct BoxPokemon *box);
u8 POKE_TOOL_CalcGender(u32 species, u16 form, u32 personality);
u32 POKE_TOOL_GetStatusCondition(struct PokemonParam *pp);
void POKE_TOOL_SetStatusCondition(struct PokemonParam *pp, u32 statusCondition);
u32 POKE_TOOL_SetDefaultMoves(struct PokemonParam *pp);
u32 POKE_TOOL_SetBoxDefaultMoves(struct BoxPokemon *box);
u16 POKE_TOOL_AddMove(struct PokemonParam *pp, u16 move);
u16 POKE_TOOL_AddBoxMove(struct BoxPokemon *box, u16 move);
void POKE_TOOL_PushMove(struct PokemonParam *pp, u16 move);
void POKE_TOOL_PushBoxMove(struct BoxPokemon *box, u16 move);
void POKE_TOOL_RecoverAllPP(struct PokemonParam *pp);
void POKE_TOOL_RecoverBoxAllPP(struct BoxPokemon *box);
void POKE_TOOL_SetMoveSlot(struct PokemonParam *pp, u16 move, u32 slot);
void POKE_TOOL_SetBoxMoveSlot(struct BoxPokemon *box, u16 move, u32 slot);
u32 POKE_TOOL_AddMoveAlt(struct PokemonParam *pp, u16 move);
u32 POKE_TOOL_AddBoxMoveAlt(struct BoxPokemon *box, u16 move);
void POKE_TOOL_ReplaceMoveSlot(struct PokemonParam *pp, u16 move, u8 slot);
void POKE_TOOL_ReplaceBoxMoveSlot(struct BoxPokemon *box, u16 move, u8 slot);
u16 POKE_TOOL_LearnLevelUpMove(struct PokemonParam *pp, u32 *tableIndex, u32 heapId);
u32 POKE_TOOL_CalcLevel(struct PokemonParam *pp);
u32 POKE_TOOL_CalcBoxLevel(struct BoxPokemon *box);
int POKE_TOOL_IsOwnedByPlayer(struct PokemonParam *pp, struct MyStatus *myStatus);
u32 POKE_TOOL_IsBoxOwnedByPlayer(struct BoxPokemon *box, struct MyStatus *myStatus);
u32 POKE_TOOL_CalcLevelFromExp(u16 species, u16 form, u32 exp);
u32 POKE_TOOL_GetLevelMinExp(struct PokemonParam *pp);
u32 POKE_TOOL_GetBoxLevelMinExp(struct BoxPokemon *box);
u32 POKE_TOOL_GetExpForLevel(u16 species, u16 form, u16 level);
u8 POKE_TOOL_GetNature(struct PokemonParam *pp);
u8 POKE_TOOL_GetBoxNature(struct BoxPokemon *box);
void POKE_TOOL_SetNature(struct PokemonParam *pp, u32 nature);
void POKE_TOOL_RecalcParam(struct PokemonParam *pp);
struct BoxPokemon *POKE_TOOL_CastToBoxParam(struct PokemonParam *mon);
struct BoxPokemon *POKE_TOOL_GetBoxParam(struct PokemonParam *pp);
u32 POKE_TOOL_GetGenderPersonalityByte(int species, u16 form, int ratioMode);
u32 POKE_TOOL_AdjustPersonalRnd(u32 otId, u16 species, u16 form, u8 ratioMode, u8 shinyWanted, int genderMode);
u32 POKE_TOOL_CreatePersonalRnd(u32 otId, int species, u16 form, int ratioMode, int shinyWanted, int mode);
u32 POKE_TOOL_GetHiddenPowerType(struct PokemonParam *pp);
u32 POKE_TOOL_GetHiddenPowerPower(struct PokemonParam *pp);
u32 POKE_TOOL_CheckTmCompat(struct PokemonParam *pp, int tmIndex);
u32 POKE_TOOL_CheckBoxTmCompat(struct BoxPokemon *box, s32 tmIndex);
u32 POKE_TOOL_CheckSpeciesTmCompat(u16 species, u16 form, s32 tmIndex);
u32 POKE_TOOL_CheckTutorCompat(struct PokemonParam *pp, s32 tutorIndex);
u32 POKE_TOOL_CheckSpeciesTutorCompat(u16 species, u16 form, s32 tutorIndex);
u32 POKE_TOOL_HasRibbonData(struct BoxPokemon *box);
int POKE_TOOL_GetNatureStatMod(struct BoxPokemon *box, int stat);
s8 POKE_TOOL_GetBoxNatureStatMod(struct BoxPokemon *box, u32 stat);
s8 POKE_TOOL_GetNatureStatModByNature(u8 nature, u32 stat);
void POKE_TOOL_SetAbility(struct BoxPokemon *box, u32 species, u32 form);
void POKE_TOOL_SetBoxAbility(struct BoxPokemon *box, u32 species, u32 form);
void POKE_TOOL_CalcParam(struct PokemonParam *pp);
u32 POKE_TOOL_DecodeCalcBlock(struct PokemonParam *pp);
u32 POKE_TOOL_DecodeBoxBlock(struct BoxPokemon *box);
void POKE_TOOL_EncodeCalcBlock(struct PokemonParam *pp);
void POKE_TOOL_EncodeBoxBlock(struct BoxPokemon *box);
u32 POKE_TOOL_GetPartyValueRaw(struct PokemonParam *pp, u32 paramId, PokeToolArg arg);
u32 POKE_TOOL_GetBoxValueRaw(struct BoxPokemon *box, u32 paramId, PokeToolArg arg);
void POKE_TOOL_SetPartyValueRaw(struct PokemonParam *pp, u32 paramId, PokeToolArg value);
void POKE_TOOL_SetBoxValueRaw(struct BoxPokemon *box, u32 paramId, PokeToolArg value);
void POKE_CRYPTO_XorBlock(u16 *data, u32 size, u32 seed);
u16 POKE_CRYPTO_NextRandom(u32 *state);
u16 POKE_CRYPTO_Checksum(const u16 *data, u32 size);
u32 POKE_TOOL_HasNickname(struct BoxPokemon *box);
u32 POKE_TOOL_ApplyNatureModifier(u32 nature, u32 stat, u32 statIndex);
s8 POKE_TOOL_GetNatureModifier(u32 nature, u32 statIndex);
void POKE_TOOL_SetDefaultName(struct PokemonParam *mon);
void POKE_TOOL_SetNameFromSpecies(struct BoxPokemon *mon);
void POKE_TOOL_LoadExpTable(u32 growthRate, u32 *dest);
u32 POKE_TOOL_GetExpValue(u32 growthRate, u32 level);
u32 POKE_TOOL_GetPlateType(u32 item);
void *POKE_TOOL_GetBoxSubstruct(struct BoxPokemon *box, u32 personality, u32 block);
struct PersonalData *POKE_TOOL_GetPersonalData(u32 species, u16 form);
u32 POKE_TOOL_GetPersonalAbilityCount(const struct PersonalData *personal);
u32 POKE_TOOL_GetPersonalParam(u16 species, u16 form, u32 field);
void POKE_TOOL_SetLevelAndRecalc(struct PokemonParam *mon, u32 level);
void POKE_TOOL_CopyPartyPokemon(const struct PartyPokemon *src, struct PartyPokemon *dest);
unsigned int POKE_TOOL_GetPlateTypeForwarder(unsigned int item);
u32 POKE_TOOL_GetBoxParamIndex(u32 paramId);
u32 POKE_TOOL_NormalizeForm(u16 species, u16 form);
int POKE_TOOL_FilterSpecies(u16 species, int value);
/* END mkheaders: generated region */

#endif
