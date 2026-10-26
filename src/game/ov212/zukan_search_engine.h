#ifndef GAME_OV212_ZUKAN_SEARCH_ENGINE_H
#define GAME_OV212_ZUKAN_SEARCH_ENGINE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_search_engine.c, prototypes copied from their definitions. */

struct Search;
struct Query;

#include "../types.h"

struct Search *ZUKAN_SEARCH_ENGINE_Create(struct Search *p, struct Query *b, int heap);
void ZUKAN_SEARCH_ENGINE_ReleaseWork(struct Search *work);
int ZUKAN_SEARCH_ENGINE_Filter(struct Search *p, u16 heap, u16 *outCount, u16 **out);
u32 ZUKAN_SEARCH_ENGINE_LoadSpeciesIds(u32 mode,u16 heap,u16 **out);
unsigned int ZUKAN_SEARCH_ENGINE_LoadFormIds(void *archive, int mode, int rule, int heapId, u16 **out);
void ZUKAN_SEARCH_ENGINE_LoadTables(void *archive, u32 heapId, u16 *count1, void **table1, u16 *count2, void **table2, u16 *count3, void **table3, u16 *count4, void **table4);
u8 ZUKAN_SEARCH_ENGINE_FinalTest(const u8 *t, const u16 *u, u32 s, u32 f);
/* END mkheaders: generated region */

#endif
