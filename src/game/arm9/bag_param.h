#ifndef GAME_ARM9_BAG_PARAM_H
#define GAME_ARM9_BAG_PARAM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of bag_param.c, prototypes copied from their definitions. */

struct BigObj;

#include "../types.h"

void *BAG_PARAM_Create(const struct BigObj *gameData, u8 *itemCheck, int mode, int heapId);
/* END mkheaders: generated region */

#endif
