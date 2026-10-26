#ifndef GAME_OV110_PMS_INPUT_DATA_H
#define GAME_OV110_PMS_INPUT_DATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pms_input_data.c, prototypes copied from their definitions. */

struct PmsInputData;

#include "../types.h"

struct PmsInputData *PMS_INPUT_DATA_Create(u32 heap, void *save);
void PMS_INPUT_DATA_Delete(struct PmsInputData *d);
void PMS_INPUT_DATA_BuildCategoryWords(struct PmsInputData *d);
u32 PMS_INPUT_DATA_CollectSeenWords(struct PmsInputData *d, const u16 *ids, u32 count, u16 *out);
u32 PMS_INPUT_DATA_CollectEventWords(struct PmsInputData *d, const u16 *ids, u32 count, u16 *out);
u32 PMS_INPUT_DATA_CollectUnlockedWords(struct PmsInputData *d, const u16 *ids, u32 n, u16 *out);
u32 PMS_INPUT_DATA_CollectOptionWords(struct PmsInputData *d, const u16 *ids, u32 count, u16 *out);
u32 PMS_INPUT_DATA_CollectRangeWords(struct PmsInputData *d, const u16 *src, u32 count, u16 *out);
void PMS_INPUT_DATA_BuildInitialWords(struct PmsInputData *d);
u32 PMS_INPUT_DATA_FilterInitialWords(struct PmsInputData *d, const u16 *src, u16 *out, u32 outIndex);
u32 PMS_INPUT_DATA_GetCategoryWordCount(struct PmsInputData *d, int category);
void PMS_INPUT_DATA_GetCategoryWordString(struct PmsInputData *d, unsigned int category, unsigned int index, void *mode);
unsigned short PMS_INPUT_DATA_GetCategoryWordId(struct PmsInputData *d, unsigned int category, unsigned int index);
u32 PMS_INPUT_DATA_FilterWordList(struct PmsInputData *a, u16 *b, u16 *c);
const u16 *PMS_INPUT_DATA_SkipRangeEntry(const u16 *rangeEntry);
u16 PMS_INPUT_DATA_GetInitialWordId(struct PmsInputData *unused, int initial, int index);
void PMS_INPUT_DATA_GetWordString(struct PmsInputData *d, u16 wordId, void *mode);
int PMS_INPUT_DATA_GetInvalidWordId(struct PmsInputData *unused);
/* END mkheaders: generated region */

#endif
