#ifndef GAME_ARM9_GAME_SYNC_H
#define GAME_ARM9_GAME_SYNC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of game_sync.c, prototypes copied from their definitions. */

struct GameSyncData;
struct SaveControl;

#include "../types.h"

struct GameSyncData *GAME_SYNC_GetBlock(struct SaveControl *saveControl);
u32 GAME_SYNC_GetBlockSize(void);
void GAME_SYNC_ClearBlock(struct GameSyncData *data);
/* END mkheaders: generated region */

#endif
