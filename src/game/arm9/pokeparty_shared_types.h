#ifndef POKEPARTY_SHARED_TYPES_H
#define POKEPARTY_SHARED_TYPES_H

struct ArcHandle;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned long long u64;

/* One party Pokemon record, 0xDC bytes (layout in poke_tool.c).  Declared
 * as words so that a whole-record assignment is the word ldm/stm loop. */
struct PokemonParam {
    u32 words[0x37];
};

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
