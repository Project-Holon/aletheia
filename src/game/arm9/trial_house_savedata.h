#ifndef GAME_ARM9_TRIAL_HOUSE_SAVEDATA_H
#define GAME_ARM9_TRIAL_HOUSE_SAVEDATA_H

/* Public functions of trial_house_savedata.c, prototypes copied from their definitions. */

#include "../types.h"

u32 TRIAL_HOUSE_SAVE_GetSize(void);
void TRIAL_HOUSE_SAVE_Clear(void *dest);
void *TRIAL_HOUSE_SAVE_GetFromSave(void *saveData);

#endif
