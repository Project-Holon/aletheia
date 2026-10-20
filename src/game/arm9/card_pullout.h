#ifndef GAME_ARM9_CARD_PULLOUT_H
#define GAME_ARM9_CARD_PULLOUT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of card_pullout.c, prototypes copied from their definitions. */

#include "../types.h"

void CARD_InitPulledOutCallback(void);
void CARDi_PulledOutCallback(int tag, u32 data, BOOL err);
void CARD_SetPulledOutCallback(int (*callback)(void));
void *CARD_IsPulledOut(void);
void CARD_TerminateForPulledOut(void);
void CARDi_CheckPulledOutCore(u32 id);
void CARDi_SendtoPxi(u32 data, u32 wait);
/* END mkheaders: generated region */

#endif
