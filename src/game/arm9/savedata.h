#ifndef GAME_ARM9_SAVEDATA_H
#define GAME_ARM9_SAVEDATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of savedata.c, prototypes copied from their definitions. */

struct SaveDataTable;
struct SaveBlockDef;

#include "../types.h"

struct SaveDataTable *SAVEDATA_CreateTable(u16 heap_id, struct SaveBlockDef *table, u32 table_max, u32 size_limit, u32 header_size, u32 block_overhead, u32 footer_size);
void SAVEDATA_DeleteTable(struct SaveDataTable *svdt);
void SAVEDATA_InitBuffer(u32 buffer_addr, struct SaveDataTable *svdt);
u32 SAVEDATA_QueryBlockSize(struct SaveDataTable *svdt, u32 id);
void SAVEDATA_BuildLayout(struct SaveDataTable *svdt, u32 block_overhead);
u32 SAVEDATA_GetBlockOffset(struct SaveDataTable *svdt, u32 gmdataid);
u32 SAVEDATA_GetBlockSize(struct SaveDataTable *svdt, u32 gmdataid);
u32 SAVEDATA_GetTableMax(struct SaveDataTable *svdt);
u32 SAVEDATA_GetTotalSize(struct SaveDataTable *svdt);
/* END mkheaders: generated region */

#endif
