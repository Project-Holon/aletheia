#ifndef GAME_TWL_PM_H
#define GAME_TWL_PM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pm.c, prototypes copied from their definitions. */

#include "../types.h"

u32 PMi_GetBatteryLevelCore(u16 *levelBuf);
void PMi_PreSleepForNdma(int ch);
void PMi_ProceedToExit(u32 factor);
void PM_ReadyToExit(void);
void PMi_FinalizeDebugger(void);
u32 PM_GetExitFactor(void);
void PMi_ExecutePostExitCallbackList(void);
void PM_SetAutoExit(u32 enable);
u32 PM_GetAutoExit(void);
void PMi_CallPostExitCallbackAndReset(int flag);
int PMi_TryLockForReset(void);
/* END mkheaders: generated region */

#endif
