#ifndef GAME_ARM9_CARD_API_H
#define GAME_ARM9_CARD_API_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of card_api.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../sdk_card.h"

void CARDi_PeekEventListener(void *arg);
BOOL CARDi_LockBusCondition(void *userdata);
void CARD_Init(void);
BOOL CARD_IsEnabled(void);
void CARD_CheckEnabled(void);
void CARD_Enable(BOOL enable);
int CARD_GetResultCode(void);
void *CARD_GetRomHeader(void);
const CARDRomHeader *CARD_GetOwnRomHeader(void);
const CARDRomHeaderTWL *CARD_GetOwnRomHeaderTWL(void);
void CARD_LockRom(u16 lock_id);
void CARD_UnlockRom(unsigned int id);
void CARD_LockBackup(s32 owner);
void CARD_UnlockBackup(u16 lock_id);
/* END mkheaders: generated region */

#endif
