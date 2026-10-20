#ifndef GAME_ARM9_BGM_INFO_H
#define GAME_ARM9_BGM_INFO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of bgm_info.c, prototypes copied from their definitions. */

struct BgmInfoTable;

#include "../types.h"

struct BgmInfoTable *BGM_INFO_Create(u32 heapId);
void BGM_INFO_Free(struct BgmInfoTable *table);
u8 BGM_INFO_GetIssMode(const struct BgmInfoTable *table, u16 bgmId);
void BGM_INFO_Load(struct BgmInfoTable *table, u32 heapId);
/* END mkheaders: generated region */

#endif
