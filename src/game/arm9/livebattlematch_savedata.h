#ifndef GAME_ARM9_LIVEBATTLEMATCH_SAVEDATA_H
#define GAME_ARM9_LIVEBATTLEMATCH_SAVEDATA_H

/* Public functions of livebattlematch_savedata.c, prototypes copied from their definitions. */

void LIVEBATTLEMATCH_SAVE_InitRecord(void *buffer);
u8 LIVEBATTLEMATCH_SAVE_GetCounter(const u8 *keys, u32 index);
void LIVEBATTLEMATCH_SAVE_AddCounter(u8 *keys, u32 index, int delta);
void LIVEBATTLEMATCH_SAVE_GetOpponentMac(u8 *obj, u32 id, void *dest);
void LIVEBATTLEMATCH_SAVE_SetOpponentMac(u8 *obj, u32 id, const void *src);
void LIVEBATTLEMATCH_SAVE_SetOpponentResultByte(u8 *obj, u32 id, u32 extra, u8 value);
u32 LIVEBATTLEMATCH_SAVE_HasOpponentMac(void *keys, void *key);
unsigned int LIVEBATTLEMATCH_SAVE_GetSize(void);
void LIVEBATTLEMATCH_SAVE_Init(void *record);
void *LIVEBATTLEMATCH_SAVE_GetFromSave(void *saveData);
int LIVEBATTLEMATCH_SAVE_GetStats(int stats);
int LIVEBATTLEMATCH_SAVE_GetStats2(int stats);
int LIVEBATTLEMATCH_SAVE_GetRecord(int stats);

#endif
