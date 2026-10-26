#ifndef GAME_ARM9_MISC_SAVEDATA_H
#define GAME_ARM9_MISC_SAVEDATA_H

typedef struct Tally Tally;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of misc_savedata.c, prototypes copied from their definitions. */

struct Tally;
typedef struct Tally Tally;

#include "../types.h"

int MISC_SAVEDATA_GetStatusByte(void *tally, int index);
u16 MISC_SAVEDATA_GetHalfword(const u16 *array, int index);
void MISC_SAVEDATA_AddHalfwordClamped(char *tally, s32 index, s32 delta);
u32 MISC_SAVEDATA_GetTallyWord(u8 *tally, int index);
u32 MISC_SAVEDATA_GetAnswerMessageOffset(u32 fieldId, u32 index);
u32 MISC_SAVEDATA_IsTallyFull(u8 *tally, u32 fieldId, u32 index);
u32 MISC_SAVEDATA_GetTallyValue(u8 *tally, u32 fieldId, u32 index);
void MISC_SAVEDATA_AddTallyValue(u8 *tally, u32 fieldId, u32 index, s32 delta);
int MISC_SAVEDATA_GetScoreValue(const u8 *tally, int fieldId, int index);
void MISC_SAVEDATA_FoldTally(Tally *tally);
/* END mkheaders: generated region */

#endif
