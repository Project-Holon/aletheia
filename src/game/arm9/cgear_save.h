#ifndef GAME_ARM9_CGEAR_SAVE_H
#define GAME_ARM9_CGEAR_SAVE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of cgear_save.c, prototypes copied from their definitions. */

struct CGearSave;

#include "../types.h"

u32 CGEAR_SAVE_GetSize(void);
void CGEAR_SAVE_Init(struct CGearSave *save);
void CGEAR_SAVE_SetObtained(struct CGearSave *save, u8 isObtained);
u8 CGEAR_SAVE_GetObtained(const struct CGearSave *save);
void CGEAR_SAVE_SetPowerSetting(struct CGearSave *save, u8 powerSetting);
u8 CGEAR_SAVE_GetPowerSetting(const struct CGearSave *save);
void CGEAR_SAVE_SetGsyncState(struct CGearSave *save, u8 gsyncState);
u8 CGEAR_SAVE_GetGsyncState(const struct CGearSave *save);
void CGEAR_SAVE_SetGsyncId(struct CGearSave *save, u16 gsyncId);
u16 CGEAR_SAVE_GetGsyncId(const struct CGearSave *save);
u32 CGEAR_SAVE_GetPanelValue(const struct CGearSave *save, int row, int col);
int CGEAR_SAVE_GetPanelFlag(const struct CGearSave *save, int row, int col);
/* END mkheaders: generated region */

#endif
