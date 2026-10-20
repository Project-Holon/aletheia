#ifndef GAME_ARM9_SHINKA_CHECK_H
#define GAME_ARM9_SHINKA_CHECK_H

/* Public functions of shinka_check.c, prototypes copied from their definitions. */

struct Party;
struct PokemonParam;
struct ArcHandle;
struct EvolutionRow;

#include "../types.h"

u32 SHINKA_CHECK_CheckEvolution(struct Party *party, struct PokemonParam *pp, u32 mode, u32 arg, u8 timezone, u32 *methodOut, u16 heap);
struct ArcHandle *SHINKA_CHECK_OpenHandle(u32 heap);
u32 SHINKA_CHECK_GetRowParam(struct ArcHandle *arc, u32 species, u32 rowIndex, u32 field);
void SHINKA_CHECK_LoadData(u32 species, struct EvolutionRow *rows);
u32 SHINKA_CHECK_KnowsMove(struct PokemonParam *pp, u32 move);

#endif
