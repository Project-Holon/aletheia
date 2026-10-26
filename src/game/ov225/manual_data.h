#ifndef GAME_OV225_MANUAL_DATA_H
#define GAME_OV225_MANUAL_DATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of manual_data.c, prototypes copied from their definitions. */

struct Big;

#include "../types.h"

void *MANUAL_COMMON_CreateMenuTable(void *narc, u32 heap);
void MANUAL_COMMON_DeleteMenuTable(char *table);
u16 MANUAL_COMMON_GetEntryValue0(char *table,int index);
u16 MANUAL_COMMON_GetEntryValue1(char *table,int index);
u16 MANUAL_COMMON_GetEntryValue2(char *table,int index);
u16 MANUAL_COMMON_GetEntryValue3(char *table,int index);
u16 MANUAL_COMMON_GetEntryPair0(char *table, int idx, int pair);
u16 MANUAL_COMMON_GetEntryPair1(char *table, int idx, int pair);
u16 MANUAL_COMMON_GetEntryCount(const char *table);
u16 MANUAL_COMMON_GetGroupValue0(char *table,int index);
u16 MANUAL_COMMON_GetGroupValue1(char *table,int index);
u16 MANUAL_COMMON_GetGroupValue2(char *table, int idx, int index2);
u16 MANUAL_COMMON_GetGroupCount(const char *table);
int MANUAL_COMMON_CheckUnlocked(void *unused,int kind,void *save);
int MANUAL_COMMON_GetSaveValue(void *unused, int id, void *save);
void MANUAL_COMMON_SetSaveValue(void *unused,int value,struct Big *save);
int MANUAL_COMMON_IsValidKey(char *unused, unsigned key);
int MANUAL_COMMON_GetDefaultId(void *unused);
u8 *MANUAL_COMMON_GetGroupEntry(char *table, int idx);
unsigned short MANUAL_COMMON_GetGroupOffset(char *table,unsigned index);
u8 *MANUAL_COMMON_GetEntry(char *table, int idx);
unsigned short MANUAL_COMMON_GetEntryOffset(char *table,unsigned index);
/* END mkheaders: generated region */

#endif
