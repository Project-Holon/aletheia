#ifndef GAME_ARM9_MUSICAL_SAVE_TYPES_H
#define GAME_ARM9_MUSICAL_SAVE_TYPES_H

#include "../types.h"

/* One outfit of the musical save: the party slot it dresses and its props. */
typedef struct MusicalOutfit {
    u8 pokeSlot;                          /* 10: none */
    u8 props[5];
} MusicalOutfit;

/* One program slot of the musical save (4 bytes). */
typedef struct MusicalProgram {
    u8 state;                             /* 4: initial */
    u8 rank;
    u16 score;
} MusicalProgram;

#endif
