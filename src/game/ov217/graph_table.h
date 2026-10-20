#ifndef GAME_OV217_GRAPH_TABLE_H
#define GAME_OV217_GRAPH_TABLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of graph_table.c, prototypes copied from their definitions. */

struct GraphTable;

#include "../types.h"

u32 GRAPHTABLE_GetEntryId(const struct GraphTable *table, u32 group, u8 entry);
u32 GRAPHTABLE_GetEntryRed(const struct GraphTable *table, u32 group, u32 entry);
u32 GRAPHTABLE_GetEntryGreen(const struct GraphTable *table, u32 group, u32 entry);
u32 GRAPHTABLE_GetEntryBlue(const struct GraphTable *table, u32 group, u32 entry);
u32 GRAPHTABLE_FindGroup(const struct GraphTable *table, u32 key);
u32 GRAPHTABLE_FindEntry(const struct GraphTable *table, u8 key, u8 entryId);
/* END mkheaders: generated region */

#endif
