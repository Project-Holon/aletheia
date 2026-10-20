#ifndef POKEPARTY_SHARED_TYPES_H
#define POKEPARTY_SHARED_TYPES_H

struct ArcHandle;

#include "../types.h"

#include "poke_tool_types.h"

/* The party: capacity, live count, six records and one byte of per-slot
 * flags (bit n for slot n, set when a member is added). */
struct Party {
    s32 capacity;
    s32 count;
    struct PokemonParam members[6];
    u8  slotFlags;
};

struct BoxPokemon;

#endif
