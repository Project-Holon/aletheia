#ifndef GAME_ARM9_ZUKAN_SKIN_SAVEDATA_H
#define GAME_ARM9_ZUKAN_SKIN_SAVEDATA_H

/* Public functions of zukan_skin_savedata.c, prototypes copied from their definitions. */

#include "../types.h"

u32 ZUKAN_SKIN_SAVE_GetSize(void);
void ZUKAN_SKIN_SAVE_Clear(void *dest);
void ZUKAN_SKIN_SAVE_GetTiles(void);
void *ZUKAN_SKIN_SAVE_GetPalette(void *saveData);
u32 ZUKAN_SKIN_SAVE_GetValidFlag(const void *saveData);
void ZUKAN_SKIN_SAVE_SetValidFlag(void *saveData, u32 value);

#endif
