#ifndef GAME_ARM9_TPOKE_DATA_TYPES_H
#define GAME_ARM9_TPOKE_DATA_TYPES_H

#include "../types.h"

/* Trainer Pokemon data container: archive handle and the record buffers. */
typedef struct Tpoke {
    void *handle;
    void *buf;
    void *buf4;
    u32   count;
} Tpoke;

#endif
