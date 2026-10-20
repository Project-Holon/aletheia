#ifndef GAME_ARM9_SAVE_SYNC_SAVEDATA_H
#define GAME_ARM9_SAVE_SYNC_SAVEDATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of save_sync_savedata.c, prototypes copied from their definitions. */

int SAVE_SYNC_GetSize(void);
void SAVE_SYNC_Clear(void *dst);
void SAVE_SYNC_Store(void *src, void *saveData);
void SAVE_SYNC_Load(void *src, void *dest);
/* END mkheaders: generated region */

#endif
