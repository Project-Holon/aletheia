#ifndef GAME_ARM9_MUSICAL_SAVE_H
#define GAME_ARM9_MUSICAL_SAVE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of musical_save.c, prototypes copied from their definitions. */

struct MusicalSave;
struct SaveControl;

#include "../types.h"
#include "../arm9/musical_save_types.h"

u32 MUSICAL_SAVE_GetSize(void);
void MUSICAL_SAVE_Init(struct MusicalSave *musical);
struct MusicalSave *MUSICAL_SAVE_GetFromSave(struct SaveControl *save);
void MUSICAL_SAVE_InitOutfits(struct MusicalSave *musical);
MusicalOutfit *MUSICAL_SAVE_GetOutfits(struct MusicalSave *musical);
u32 MUSICAL_SAVE_IsShowActive(struct MusicalSave *musical);
void MUSICAL_SAVE_NoOp(void);
u32 MUSICAL_SAVE_IsPropOwned(struct MusicalSave *musical, u8 prop);
u32 MUSICAL_SAVE_IsPropNew(struct MusicalSave *musical, u8 prop);
void MUSICAL_SAVE_AddProp(struct MusicalSave *musical, u32 prop);
void MUSICAL_SAVE_ClearNewProps(struct MusicalSave *musical);
u32 MUSICAL_SAVE_CountOwnedProps(struct MusicalSave *musical);
u32 MUSICAL_SAVE_HasAllProps(struct MusicalSave *musical);
MusicalProgram *MUSICAL_SAVE_GetProgram(struct MusicalSave *musical, u32 index);
u16 MUSICAL_SAVE_GetShowCount(struct MusicalSave *musical);
void MUSICAL_SAVE_IncrementShowCount(struct MusicalSave *musical);
u16 MUSICAL_SAVE_GetTopRankCount(struct MusicalSave *musical);
void MUSICAL_SAVE_IncrementTopRankCount(struct MusicalSave *musical);
u8 MUSICAL_SAVE_GetEquippedProp(struct MusicalSave *musical, u32 index);
void MUSICAL_SAVE_SetEquippedProp(struct MusicalSave *musical, u32 index, u8 prop);
u8 MUSICAL_SAVE_GetSelectedProgram(struct MusicalSave *musical);
void MUSICAL_SAVE_SetSelectedProgram(struct MusicalSave *musical, u8 value);
u8 MUSICAL_SAVE_GetScriptSetting(struct MusicalSave *musical);
void MUSICAL_SAVE_SetScriptSetting(struct MusicalSave *musical, u8 value);
u8 MUSICAL_SAVE_GetHasDistData(struct MusicalSave *musical);
void MUSICAL_SAVE_SetHasDistData(struct MusicalSave *musical, u8 value);
u8 *MUSICAL_SAVE_GetStageData(struct MusicalSave *musical);
void MUSICAL_SAVE_AddFanPoints(struct MusicalSave *musical, s32 delta);
u16 MUSICAL_SAVE_GetFanPoints(struct MusicalSave *musical);
u32 MUSICAL_SAVE_GetFittingSetting(struct MusicalSave *musical);
void MUSICAL_SAVE_SetFittingSetting(struct MusicalSave *musical, u8 value);
/* END mkheaders: generated region */

#include "../arm9/musical_save_types.h"

#endif
