#ifndef GAME_ARM9_RECENT_ID_LIST_SAVEDATA_H
#define GAME_ARM9_RECENT_ID_LIST_SAVEDATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of recent_id_list_savedata.c, prototypes copied from their definitions. */

struct RecentIdList;

#include "../types.h"

u32 RECENT_ID_LIST_SAVEDATA_GetBlockSize(void);
void RECENT_ID_LIST_SAVEDATA_InitBlock(struct RecentIdList *list);
void *RECENT_ID_LIST_SAVEDATA_GetBlockFromSys(void *sys);
void *RECENT_ID_LIST_SAVEDATA_GetBlock(void *sys);
void RECENT_ID_LIST_SAVEDATA_SetId(u8 *ids, u32 id, u32 enabled);
u32 RECENT_ID_LIST_SAVEDATA_ContainsId(const u8 *ids, u32 id);
u8 RECENT_ID_LIST_SAVEDATA_GetIdAt(const u8 *ids, u32 index);
u16 RECENT_ID_LIST_SAVEDATA_CountIds(const u8 *ids);
u8 RECENT_ID_LIST_SAVEDATA_InsertId(u8 *ids, int id, u8 position);
void RECENT_ID_LIST_SAVEDATA_CompactIds(u8 *ids);
int RECENT_ID_LIST_SAVEDATA_GetSaveAreaSize(void);
void RECENT_ID_LIST_SAVEDATA_InitArea(void);
/* END mkheaders: generated region */

#endif
