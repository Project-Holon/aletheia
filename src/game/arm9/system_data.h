#ifndef GAME_ARM9_SYSTEM_DATA_H
#define GAME_ARM9_SYSTEM_DATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of system_data.c, prototypes copied from their definitions. */

struct SystemData;
struct MyStatus;
struct Config;
struct PlayTime;
struct MyStatusHolder;

#include "../types.h"

u32 SYSTEM_DATA_GetSize(void);
void SYSTEM_DATA_Init(struct SystemData *sys_data);
struct MyStatus *SYSTEM_DATA_GetMyStatus(void *save);
struct Config *SYSTEM_DATA_GetConfig(void *save);
struct PlayTime *SYSTEM_DATA_GetPlayTime(void *save);
u8 SYSTEM_DATA_IsActive(void *save);
void SYSTEM_DATA_SetActive(void *save);
void SYSTEM_DATA_ClearActive(void *save);
int SYSTEM_DATA_IsMarked(void *save, u32 index);
void SYSTEM_DATA_SetMark(void *save, u32 index);
void SYSTEM_DATA_ClearMark(void *save, u32 index);
u32 *SYSTEM_DATA_GetWordSlot(void *save, u32 index);
void SYSTEM_DATA_SetMyStatus(void *save, const struct MyStatusHolder *src);
void SYSTEM_DATA_CopyMyStatus(void *save, struct MyStatusHolder *dest);
/* END mkheaders: generated region */

#endif
