#ifndef GAME_ARM9_BLINK_PALANM_H
#define GAME_ARM9_BLINK_PALANM_H

#include "../types.h"

struct BlinkPalAnm *BLINK_PALANM_Create(u16 firstColor, u16 colorCount, u32 mode, u16 heapId);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of blink_palanm.c, prototypes copied from their definitions. */

struct BlinkPalAnm;

#include "../types.h"

struct BlinkPalAnm *BLINK_PALANM_Create(u16 firstColor, u16 colorCount, u32 mode, u16 heapId);
void BLINK_PALANM_LoadPalettes(struct BlinkPalAnm *anm, void *archive, u32 fileId, u32 srcStart, u32 dstStart);
u32 BLINK_PALANM_Delete(struct BlinkPalAnm *anm);
s32 BLINK_PALANM_Update(struct BlinkPalAnm *anm);
void BLINK_PALANM_ResetPhase(struct BlinkPalAnm *anm);
/* END mkheaders: generated region */

#endif
