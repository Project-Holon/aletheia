#ifndef GAME_ARM9_SPL_RANDOM_H
#define GAME_ARM9_SPL_RANDOM_H

/* Public functions of spl_random.c, prototypes copied from their definitions. */

#include "../sdk_fx.h"

void SPLRandom_VecFx32_XY(volatile VecFx32 *v);
void SPLRandom_VecFx32(volatile VecFx32 *v);

#endif
