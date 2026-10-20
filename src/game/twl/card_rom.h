#ifndef GAME_TWL_CARD_ROM_H
#define GAME_TWL_CARD_ROM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of card_rom.c, prototypes copied from their definitions. */

#include "../types.h"

int CARDi_ReadCardWithHash(int userdata, int buffer, int offset, int length);
int CARDi_ReadCardWithHashInternalAsync(void *userdata, void *buffer, u32 offset, u32 length);
void CARDi_InitRomHash(void);
void data_0272EB9C(void);
/* END mkheaders: generated region */

#endif
