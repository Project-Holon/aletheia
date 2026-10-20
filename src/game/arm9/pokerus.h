#ifndef GAME_ARM9_POKERUS_H
#define GAME_ARM9_POKERUS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokerus.c, prototypes copied from their definitions. */

struct Party;
struct PokemonParam;
struct BoxPokemon;

#include "../types.h"

void POKERUS_TryInfectParty(struct Party *party);
void POKERUS_DecreaseDays(struct Party *party, s32 days);
void POKERUS_SpreadParty(struct Party *party);
u32 POKERUS_GetInfectedMask(struct Party *party);
u32 POKERUS_IsInfected(struct PokemonParam *pp);
u32 POKERUS_IsBoxInfected(struct BoxPokemon *box);
u32 POKERUS_IsCured(struct PokemonParam *pp);
u32 POKERUS_IsBoxCured(struct BoxPokemon *box);
/* END mkheaders: generated region */

#endif
