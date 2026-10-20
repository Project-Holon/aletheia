#ifndef GAME_ARM9_INTRUDE_H
#define GAME_ARM9_INTRUDE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of intrude.c, prototypes copied from their definitions. */

struct IntrudeSave;
struct SaveControl;
struct IntrudeLogEntry;
struct PlayTime;

#include "../types.h"

u32 INTRUDE_GetSize(void);
void INTRUDE_Init(struct IntrudeSave *intrude);
void INTRUDE_InitOccupy(struct IntrudeSave *intrude);
u16 INTRUDE_GetMissionScore(struct IntrudeSave *intrude);
u16 INTRUDE_GetMissionBonusScore(struct IntrudeSave *intrude);
void INTRUDE_AddMissionScore(struct IntrudeSave *intrude, s32 add);
void INTRUDE_AddMissionBonusScore(struct IntrudeSave *intrude, s32 add);
struct IntrudeSave *INTRUDE_GetFromSave(struct SaveControl *save);
void INTRUDE_StoreOccupy(struct SaveControl *save, const u16 *src);
void INTRUDE_LoadOccupy(struct SaveControl *save, u16 *dest);
void INTRUDE_AddLogEntry(struct IntrudeSave *intrude, struct IntrudeLogEntry *entry);
void INTRUDE_SetMonolithLevel(struct IntrudeSave *intrude, u32 level);
u8 INTRUDE_GetMonolithLevel(struct IntrudeSave *intrude);
void INTRUDE_SetObtainedFlag(struct IntrudeSave *intrude, s32 id);
void INTRUDE_GetObtainedFlags(struct IntrudeSave *intrude, u8 *dest, u32 size);
u32 INTRUDE_GetMissionClearCount(struct IntrudeSave *intrude);
u32 INTRUDE_IncrementMissionClearCount(struct IntrudeSave *intrude);
u64 INTRUDE_GetPlaySeconds(struct IntrudeSave *intrude);
u64 INTRUDE_UpdatePlaySeconds(struct IntrudeSave *intrude, const struct PlayTime *time, u32 mode);
/* END mkheaders: generated region */

#endif
