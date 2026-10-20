#ifndef GAME_ARM9_NATSUKI_H
#define GAME_ARM9_NATSUKI_H

/* Public functions of natsuki.c, prototypes copied from their definitions. */

struct PokemonParam;
struct Party;

#include "../types.h"

void NATSUKI_Calc(struct PokemonParam *pp, int type, int zoneId, u16 heap);
void NATSUKI_CalcUseItem(struct PokemonParam *pp, int item, u16 zoneId, u16 heap);
void NATSUKI_CalcWalk(struct PokemonParam *pp, int zoneId, u16 heap);
void NATSUKI_CalcParty(struct Party *party, int zoneId, u16 heap);
void NATSUKI_Apply(struct PokemonParam *pp, const s8 *deltas, int zoneId, u16 heap);

#endif
