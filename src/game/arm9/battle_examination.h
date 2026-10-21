#ifndef GAME_ARM9_BATTLE_EXAMINATION_H
#define GAME_ARM9_BATTLE_EXAMINATION_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of battle_examination.c, prototypes copied from their definitions. */

#include "../types.h"

u32 BATTLE_EXAMINATION_GetBlockSize(void);
void BATTLE_EXAMINATION_ClearBlock(void *p);
int BATTLE_EXAMINATION_IsDeliveryValid(void *delivery);
int BATTLE_EXAMINATION_IsDeliveryUnused(void *delivery);
u16 BATTLE_EXAMINATION_GetDeliveryId(void *delivery);
void *BATTLE_EXAMINATION_GetTrainerSlot(void *base, u32 index);
void BATTLE_EXAMINATION_LoadDelivery(void *gameData, void *dst, u32 heap);
void BATTLE_EXAMINATION_RefreshMarker(void *delivery);
/* END mkheaders: generated region */

#endif
