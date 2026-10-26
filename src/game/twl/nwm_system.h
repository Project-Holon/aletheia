#ifndef GAME_TWL_NWM_SYSTEM_H
#define GAME_TWL_NWM_SYSTEM_H

#include "nwm_system_types.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nwm_system.c, prototypes copied from their definitions. */

struct Msg;
typedef struct Msg Msg;
struct NwmSystemWork;

#include "../types.h"

struct NwmSystemWork *NWMi_GetSystemWork(void);
void NWMi_ClearFifoRecvFlag(void);
void NWMi_ReceiveFifo9(u32 tag, Msg *msg, u32 err);
u32 NWM_GetState(void);
u32 NWMi_CheckState(u32 n, ...);
u32 NWM_GetAllowedChannel(void);
u16 NWM_GetDispersionScanPeriod(u32 type);
void NWMi_RegisterSleepCallback(void);
void NWMi_DeleteSleepCallback(void);
void NwmSleepCallback(void);
/* END mkheaders: generated region */

#endif
