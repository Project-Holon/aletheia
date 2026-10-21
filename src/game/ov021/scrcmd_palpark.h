#ifndef GAME_OV021_SCRCMD_PALPARK_H
#define GAME_OV021_SCRCMD_PALPARK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_palpark.c, prototypes copied from their definitions. */

struct ScrcmdWork;
struct ScriptVm;

struct ScriptVM;
typedef struct ScriptVM ScriptVM;

#include "../types.h"

int SCRCMD_PALPARK_CallFallEvent(struct ScriptVm *core, struct ScrcmdWork *work);
int SCRCMD_PALPARK_CallPalParkProc(struct ScriptVm *core, struct ScrcmdWork *work);
int SCRCMD_PALPARK_GetSaveValue(struct ScriptVm *core, struct ScrcmdWork *work);
int SCRCMD_PALPARK_SetBeacon(struct ScriptVm *core, struct ScrcmdWork *work);
int SCRCMD_PALPARK_ClearExpiredGPower(struct ScriptVm *core, struct ScrcmdWork *work);
int SCRCMD_PALPARK_CallGPowerFlashEvent(u32 unused, struct ScrcmdWork *work, u32 unused2, u32 unused3);
/* END mkheaders: generated region */

#endif
