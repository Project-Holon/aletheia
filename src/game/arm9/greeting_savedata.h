#ifndef GAME_ARM9_GREETING_SAVEDATA_H
#define GAME_ARM9_GREETING_SAVEDATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of greeting_savedata.c, prototypes copied from their definitions. */

struct QuadRecord;

#include "../types.h"

u32 GREETING_SAVEDATA_GetSize(void);
void GREETING_SAVEDATA_Init(void *greetings);
void *GREETING_SAVEDATA_GetFromSaveThunk(u32 saveData);
void *GREETING_SAVEDATA_GetFromSave(u32 saveData);
void GREETING_SAVEDATA_GetSentence(struct QuadRecord *src, int idx, struct QuadRecord *dst);
void GREETING_SAVEDATA_SetSentence(struct QuadRecord *dst, int idx, struct QuadRecord *src);
/* END mkheaders: generated region */

#endif
