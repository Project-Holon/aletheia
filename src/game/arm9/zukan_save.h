#ifndef GAME_ARM9_ZUKAN_SAVE_H
#define GAME_ARM9_ZUKAN_SAVE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_save.c, prototypes copied from their definitions. */

struct ZukanSave;

#include "../types.h"

u32 ZUKAN_SAVE_IsInvalidSpecies(u32 species);
void ZUKAN_SAVE_SetLanguageFlag(struct ZukanSave *pZukan, u32 species, u32 language);
int ZUKAN_SAVE_IsCountedForNationalCompletion(u32 species);
int ZUKAN_SAVE_IsCountedForRegionalCompletion(u32 species);
u32 ZUKAN_SAVE_GetFormBitBase(u16 species);
u32 ZUKAN_SAVE_GetFormTableIndex(u32 species);
void ZUKAN_SAVE_SetSeenGenderFlag(struct ZukanSave *pZukan, u32 species, int sel, int half);
void ZUKAN_SAVE_SetSeenFormFlag(struct ZukanSave *pZukan, u32 species, u32 sel, u32 shiny, u32 form);
u32 ZUKAN_SAVE_GetSize(void);
void ZUKAN_SAVE_Init(struct ZukanSave *pZukan);
void *ZUKAN_SAVE_GetBlock(void *saveControl);
void *ZUKAN_SAVE_GetFromGameData(void *gameData);
struct ZukanSave *ZUKAN_SAVE_EnableNationalDex(struct ZukanSave *pZukan);
u32 ZUKAN_SAVE_IsNationalDexEnabled(struct ZukanSave *pZukan);
struct ZukanSave *ZUKAN_SAVE_SetDexObtained(struct ZukanSave *pZukan);
u32 ZUKAN_SAVE_GetDexObtained(struct ZukanSave *pZukan);
void ZUKAN_SAVE_SetViewMode(struct ZukanSave *pZukan, u32 value);
u32 ZUKAN_SAVE_GetViewMode(struct ZukanSave *pZukan);
void ZUKAN_SAVE_SetLastViewedSpecies(struct ZukanSave *pZukan, u32 value);
u16 ZUKAN_SAVE_GetLastViewedSpecies(struct ZukanSave *pZukan);
void ZUKAN_SAVE_UpdateViewFlags(struct ZukanSave *pZukan, u16 species, u32 gender, u32 shiny, u32 form);
u16 ZUKAN_SAVE_GetFormCount(u32 species);
void ZUKAN_SAVE_GetViewGenderAndForm(struct ZukanSave *pZukan, u16 species, u32 *outGender, u32 *outShiny, u32 *outForm, u16 language);
void ZUKAN_SAVE_RegisterCaught(struct ZukanSave *pZukan, void *pMon);
u32 ZUKAN_SAVE_IsCaught(struct ZukanSave *pZukan, u16 species);
u16 ZUKAN_SAVE_CountCaught(struct ZukanSave *pZukan, u32 heap);
u16 ZUKAN_SAVE_CountCaughtNational(struct ZukanSave *pZukan);
u16 ZUKAN_SAVE_CountCaughtRegional(struct ZukanSave *pZukan, u32 heap);
void ZUKAN_SAVE_RegisterSeen(struct ZukanSave *pZukan, void *pMon);
u32 ZUKAN_SAVE_IsSeen(struct ZukanSave *pZukan, u16 species);
u32 ZUKAN_SAVE_CountSeen(struct ZukanSave *pZukan, u32 heap);
u16 ZUKAN_SAVE_CountSeenNational(struct ZukanSave *pZukan);
u16 ZUKAN_SAVE_CountSeenRegional(struct ZukanSave *pZukan, u32 heap);
u32 ZUKAN_SAVE_HasSeenGenderForm(struct ZukanSave *pZukan, u16 species, u32 gender, u32 shiny, u32 form);
u32 ZUKAN_SAVE_GetSpindaPersonality(struct ZukanSave *pZukan, u32 which);
int ZUKAN_SAVE_IsNationalCaughtComplete(struct ZukanSave *pZukan);
int ZUKAN_SAVE_IsRegionalCaughtComplete(struct ZukanSave *pZukan, int heap);
int ZUKAN_SAVE_IsRegionalSeenComplete(struct ZukanSave *pZukan, unsigned int heap);
u16 ZUKAN_SAVE_CountCaughtNationalCounted(struct ZukanSave *pZukan);
int ZUKAN_SAVE_CountCaughtRegionalCounted(struct ZukanSave *pZukan, int heap);
u16 ZUKAN_SAVE_CountSeenRegionalCounted(struct ZukanSave *pZukan, u32 heap);
u32 ZUKAN_SAVE_HasLanguageFlag(struct ZukanSave *pZukan, u32 species, u32 language);
/* END mkheaders: generated region */

#endif
