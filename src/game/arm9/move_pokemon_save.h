#ifndef GAME_ARM9_MOVE_POKEMON_SAVE_H
#define GAME_ARM9_MOVE_POKEMON_SAVE_H

/* Public functions of move_pokemon_save.c, prototypes copied from their definitions. */

struct MovePokemonSave;
struct MovePokemonEntry;

#include "../types.h"

u32 MOVE_POKEMON_SAVE_GetSize(void);
void *MOVE_POKEMON_SAVE_GetBlock(void *saveControl);
void MOVE_POKEMON_SAVE_Init(struct MovePokemonSave *pSave);
void MOVE_POKEMON_SAVE_RollStartLocation(void *saveControl);
u8 MOVE_POKEMON_SAVE_GetStartLocation(struct MovePokemonSave *pSave);
void MOVE_POKEMON_SAVE_SetCommonArea(struct MovePokemonSave *pSave, u16 area);
u8 MOVE_POKEMON_SAVE_GetEntryState(struct MovePokemonSave *pSave, u32 slot);
void MOVE_POKEMON_SAVE_SetEntryState(struct MovePokemonSave *pSave, u32 slot, u32 state);
u8 MOVE_POKEMON_SAVE_GetEntryLocation(struct MovePokemonSave *pSave, u32 slot);
void MOVE_POKEMON_SAVE_SetEntryLocation(struct MovePokemonSave *pSave, u32 slot, u8 location);
u8 MOVE_POKEMON_SAVE_IsEntryActive(struct MovePokemonSave *pSave, u32 slot);
void MOVE_POKEMON_SAVE_InitEntry(struct MovePokemonEntry *pEntry);
struct MovePokemonEntry *MOVE_POKEMON_SAVE_GetEntry(struct MovePokemonSave *pSave, u32 slot);
u32 MOVE_POKEMON_SAVE_GetEntryField(const struct MovePokemonEntry *pEntry, u32 field);
void MOVE_POKEMON_SAVE_SetEntryField(struct MovePokemonEntry *pEntry, u32 field, u32 value);
void MOVE_POKEMON_SAVE_SetCooldown(struct MovePokemonSave *pSave, u8 cooldown);
u32 MOVE_POKEMON_SAVE_TickCooldown(struct MovePokemonSave *pSave);
u32 MOVE_POKEMON_SAVE_IsCooldownDone(struct MovePokemonSave *pSave);

#endif
