#ifndef GAME_ARM9_BSUBWAY_SAVEDATA_H
#define GAME_ARM9_BSUBWAY_SAVEDATA_H

#include "../types.h"

/* One row of the three 16-bit counters of a Battle Subway statistic. */
typedef u16 BsubwayStatRow[3];

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of bsubway_savedata.c, prototypes copied from their definitions. */

struct BsubwaySave;
struct TrainerExport;
struct HistoryBuf;
struct BsubwayHistoryEntry;

#include "../types.h"

u8 BSUBWAY_SAVEDATA_GetTrainersPresent(struct BsubwaySave *save);
u8 BSUBWAY_SAVEDATA_GetHistoryPresent(struct BsubwaySave *save);
void BSUBWAY_SAVEDATA_SetTrainers(struct BsubwaySave *save, const void *src, u8 tagA, u8 tagB);
u8 BSUBWAY_SAVEDATA_GetTrainersTagA(struct BsubwaySave *save);
u8 BSUBWAY_SAVEDATA_GetTrainersTagB(struct BsubwaySave *save);
void BSUBWAY_SAVEDATA_ExportTrainer(struct BsubwaySave *save, struct TrainerExport *out, int index, u32 heapId);
void BSUBWAY_SAVEDATA_SetHistory(struct BsubwaySave *save, const void *src, u8 tagA, u8 tagB);
int BSUBWAY_SAVEDATA_GetHistoryTagA(struct BsubwaySave *save);
u8 BSUBWAY_SAVEDATA_GetHistoryTagB(struct BsubwaySave *save);
struct HistoryBuf *BSUBWAY_SAVEDATA_AllocHistoryCopy(struct BsubwaySave *save, u32 heapId);
u32 BSUBWAY_SAVEDATA_CountHistoryEntries(struct HistoryBuf *history);
u32 BSUBWAY_SAVEDATA_GetHistoryEntryScore(struct BsubwayHistoryEntry *entry);
void BSUBWAY_SAVEDATA_InitStats(void *stats);
u32 BSUBWAY_SAVEDATA_GetStat(BsubwayStatRow *stats, u32 row, u32 col);
void BSUBWAY_SAVEDATA_SetStat(BsubwayStatRow *stats, int row, int col, int value);
void BSUBWAY_SAVEDATA_IncStat(u8 *stats, int row, int col);
/* END mkheaders: generated region */

#endif
