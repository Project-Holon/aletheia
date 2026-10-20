#ifndef GAME_OV010_EVOLUTION_REQUEST_TYPES_H
#define GAME_OV010_EVOLUTION_REQUEST_TYPES_H

#include "../types.h"

struct GameData;

/* Evolution demo request (0x14 bytes, read by the evolution demo overlay). */
typedef struct EvolutionRequest {
    struct GameData *gameData;  /* 0x00 */
    void *party;                /* 0x04 */
    u16 targetSpecies;          /* 0x08: result of the evolution check */
    u8 partySlot;               /* 0x0A */
    u8 evolveCondition;         /* 0x0B: how the evolution is triggered */
    u32 fromTrade;              /* 0x0C */
    u32 fromField;              /* 0x10 */
} EvolutionRequest;

#endif
