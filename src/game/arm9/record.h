#ifndef GAME_ARM9_RECORD_H
#define GAME_ARM9_RECORD_H

/* Public functions of record.c, prototypes copied from their definitions. */

struct RecordBlock;
struct SaveControl;

#include "../types.h"

u32 RECORD_GetSize(void);
void RECORD_Init(struct RecordBlock *record);
struct RecordBlock *RECORD_GetFromSave(struct SaveControl *control);
void RECORD_Seal(struct RecordBlock *record, int enable);
void RECORD_Unseal(struct RecordBlock *record, int enable);
u32 RECORD_GetCounter(const struct RecordBlock *record, int index);
u32 RECORD_SetCounter(struct RecordBlock *record, int index, u32 value);
int RECORD_GetCeiling(int index);
u32 RECORD_SetCounterClamped(struct RecordBlock *record, int index, u32 value);
u32 RECORD_RaiseCounter(struct RecordBlock *record, int index, u32 minimum);
u32 RECORD_AddCounter(struct RecordBlock *record, int index, u32 delta);
u32 RECORD_AddOne(struct RecordBlock *record, int index);
u32 RECORD_GetCounterClamped(struct RecordBlock *record, int index);
void RECORD_FoldPairs(struct RecordBlock *record);
void RECORD_SetTrialRank(struct RecordBlock *record, u32 rank);
u8 RECORD_GetTrialRank(struct RecordBlock *record);
void RECORD_SetTrialScore(struct RecordBlock *record, u32 score);
u32 RECORD_GetTrialScore(struct RecordBlock *record);

#endif
