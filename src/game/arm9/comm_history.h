#ifndef GAME_ARM9_COMM_HISTORY_H
#define GAME_ARM9_COMM_HISTORY_H

/* Public functions of comm_history.c, prototypes copied from their definitions. */

struct HistoryOwner;
struct HistoryEntry;

#include "../types.h"

u32 COMM_HISTORY_InsertIfNationSet(struct HistoryOwner *owner, struct HistoryEntry *entry);
u32 COMM_HISTORY_InsertOrReplace(struct HistoryOwner *owner, struct HistoryEntry *entry);
u32 COMM_HISTORY_CountLeadingOccupied(const struct HistoryEntry *table);
u32 COMM_HISTORY_CountByKey(struct HistoryEntry *table, u32 key);
s32 COMM_HISTORY_FindByKey(struct HistoryEntry *table, u32 key);
s32 COMM_HISTORY_FindByKeys(struct HistoryEntry *table, struct HistoryEntry *entry);
void COMM_HISTORY_RemoveAt(struct HistoryEntry *table, u32 index);
void COMM_HISTORY_StoreAndNotify(struct HistoryOwner *owner, struct HistoryEntry *entry, u32 mark);
void COMM_HISTORY_StoreAt(struct HistoryEntry *table, struct HistoryEntry *entry, u32 mark);
u32 SCROLLBAR_GetValueFromPos(u32 maxValue, u32 value, u32 rangeStart, u32 rangeEnd, u32 margin);
u32 SCROLLBAR_GetPosFromValue(u32 total, u32 rate, u32 start, u32 end, u32 margin);

#endif
