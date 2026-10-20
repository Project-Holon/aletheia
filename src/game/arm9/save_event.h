#ifndef GAME_ARM9_SAVE_EVENT_H
#define GAME_ARM9_SAVE_EVENT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of save_event.c, prototypes copied from their definitions. */

struct MyStatus;
struct SaveData;

#include "../types.h"

void SAVE_EVENT_Write(void *gameData, u32 mode, const struct MyStatus *record, u32 eventId, u16 index);
void SAVE_EVENT_WriteMode(struct SaveData *save, u32 mode, const struct MyStatus *record, u32 eventId, u32 index);
void SAVE_EVENT_StoreTodayDate(struct SaveData *save);
void SAVE_EVENT_WriteWithDate(struct SaveData *save, u32 eventId, u32 year, u32 month, u32 day);
void SAVE_EVENT_ClearVariant(struct SaveData *save, u32 variant);
void SAVE_EVENT_WriteEventIdWithDate(struct SaveData *save, u32 eventId, u32 variant);
void SAVE_EVENT_StoreVariant(struct SaveData *save, u32 eventId, u32 year, u32 month, u32 day, u32 variant);
void SAVE_EVENT_CopyVariant(struct SaveData *save, u32 variant);
void SAVE_EVENT_StoreRecord(struct SaveData *save, const struct MyStatus *record, u32 index);
void SAVE_EVENT_CopyDoneFlag(struct SaveData *save);
void SAVE_EVENT_SetDoneFlag(struct SaveData *save);
int SAVE_EVENT_IsStageDone(void *gameData, int stage);
int SAVE_EVENT_CheckStage(struct SaveData *save, int stage);
void SAVE_EVENT_CommitStage(void *gameData, u32 stage);
void SAVE_EVENT_AdvanceStage(struct SaveData *save, u32 stage);
/* END mkheaders: generated region */

#endif
