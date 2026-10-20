#ifndef GAME_ARM9_CARD_UTILITY_H
#define GAME_ARM9_CARD_UTILITY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of card_utility.c, prototypes copied from their definitions. */

#include "../arm9/card_common.h"
#include "../types.h"

CARDDmaInterface *CARDi_GetDmaInterface(u32 channel);
void CARDi_ICInvalidateSmart(void *p, unsigned int a, unsigned int b);
void CARDi_DCInvalidateSmart(void *buffer, u32 length, u32 threshold);
/* END mkheaders: generated region */

#endif
