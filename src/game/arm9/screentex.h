#ifndef GAME_ARM9_SCREENTEX_H
#define GAME_ARM9_SCREENTEX_H

/* Public functions of screentex.c, prototypes copied from their definitions. */

#include "../types.h"

void *SCREENTEX_Create(u32 heapId, u32 slotCount);
void SCREENTEX_CaptureDisplay(u32 captureIndex, u32 copyIndex);
void SCREENTEX_SetupCamera(void *dst);

#endif
