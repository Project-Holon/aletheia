#ifndef GAME_OV021_SCRCMD_PALPARK_H
#define GAME_OV021_SCRCMD_PALPARK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_palpark.c, prototypes copied from their definitions. */

struct ScriptVM;
typedef struct ScriptVM ScriptVM;

#include "../types.h"

int SCRCMD_PALPARK_CallFallEvent(void *core, void *work);
int SCRCMD_PALPARK_CallPalParkProc(u32 core, u32 work);
int SCRCMD_PALPARK_GetSaveValue(ScriptVM *core, void *work);
int SCRCMD_PALPARK_SetBeacon(u32 core, u32 work);
int SCRCMD_PALPARK_ClearExpiredGPower(void *core, void *work);
int SCRCMD_PALPARK_CallGPowerFlashEvent(u32 unused, u32 work, u32 unused2, u32 unused3);
/* END mkheaders: generated region */

#endif
