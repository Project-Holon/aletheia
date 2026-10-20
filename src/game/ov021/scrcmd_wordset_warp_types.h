#ifndef GAME_OV021_SCRCMD_WORDSET_WARP_TYPES_H
#define GAME_OV021_SCRCMD_WORDSET_WARP_TYPES_H

#include "../types.h"

struct WordSet;
typedef void (*WordSetRegisterFn)(struct WordSet *wordSet, u32 slot, u32 value);


#endif
