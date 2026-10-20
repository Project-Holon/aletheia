#ifndef GAME_ARM9_POKEPARTY_H
#define GAME_ARM9_POKEPARTY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokeparty.c, prototypes copied from their definitions. */

struct Party;
struct PokemonParam;
struct SaveControl;

#include "../types.h"

struct Party *POKEPARTY_Create(u32 heap);
void POKEPARTY_Init(struct Party *party);
void POKEPARTY_InitEx(struct Party *party, s32 capacity);
u32 POKEPARTY_Add(struct Party *party, const struct PokemonParam *member);
u32 POKEPARTY_RemoveMember(struct Party *party, s32 pos);
u32 POKEPARTY_GetCapacity(const struct Party *party);
u32 POKEPARTY_GetCount(const struct Party *party);
u32 POKEPARTY_GetNonEggCount(struct Party *party);
u32 POKEPARTY_GetBattleReadyCount(struct Party *party);
u32 POKEPARTY_GetEggCount(struct Party *party);
u32 POKEPARTY_GetBadEggCount(struct Party *party);
u32 POKEPARTY_FindFirstBattleReady(struct Party *party);
u32 POKEPARTY_FindFirstNonEgg(struct Party *party);
struct PokemonParam *POKEPARTY_GetMember(struct Party *party, u32 pos);
u32 POKEPARTY_IsMemberBattleReady(struct Party *party, u32 pos);
void POKEPARTY_SetMember(struct Party *party, u32 pos, const struct PokemonParam *member);
u32 POKEPARTY_SwapMembers(struct Party *party, u32 pos1, u32 pos2, u32 heap);
void POKEPARTY_Copy(const struct Party *src, struct Party *dst);
u32 POKEPARTY_HasSpecies(struct Party *party, u32 species);
u32 POKEPARTY_GetAliveNonEggCount(struct Party *party);
int POKEPARTY_GetSlotFlag(const struct Party *party, u32 pos);
void POKEPARTY_SetSlotFlag(struct Party *party, u32 pos, u32 set);
struct Party *POKEPARTY_GetSaveData(struct SaveControl *save);
u32 POKEPARTY_IsBattleReady(struct PokemonParam *member);
u32 POKEPARTY_IsNotEgg(struct PokemonParam *member);
/* END mkheaders: generated region */

#endif
