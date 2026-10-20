#ifndef GAME_ARM9_PMS_WORD_H
#define GAME_ARM9_PMS_WORD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pms_word.c, prototypes copied from their definitions. */

struct PmsWordSys;
struct PmsWord;
struct WinPanel020071CCCtrl;

#include "../types.h"

struct PmsWordSys *PMS_WORD_Create(u32 heapId);
void PMS_WORD_Delete(struct PmsWordSys *p);
void PMS_WORD_GetString(struct PmsWordSys *p, u32 id, void *dest);
void PMS_WORD_LoadString(u32 id, void *dest, u16 heap);
u16 PMS_WORD_MakeWordId(u32 idx, u16 add);
int PMS_WORD_SplitWordId(u32 wordId, u32 *bankIndex, u32 *wordIndex);
void *PMS_WORD_GetSaveEntry(char *p, int idx);
void PMS_WORD_SetSaveEntry(struct PmsWord *p, s32 idx, const void *src);
u32 PMS_WORD_GetSaveSize(void);
void PMS_WORD_InitSave(struct PmsWord *p);
void *PMS_WORD_GetSaveData(struct WinPanel020071CCCtrl *ctrl);
int PMS_WORD_CheckFlag(const u32 *p, u32 idx);
void PMS_WORD_SetFlag(int *p, int bit);
int PMS_WORD_IsSameGroup(u32 a, u16 b);
/* END mkheaders: generated region */

#endif
