#ifndef GAME_TWL_NWM_UNLOADDEV_H
#define GAME_TWL_NWM_UNLOADDEV_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nwm_unloaddev.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../twl/nwm_callback_types.h"

u32 NWM_UnloadDevice(NWMCallbackFunc callback);
u32 NWMi_ForceUnloadDevice(NWMCallbackFunc callback);
void NWMi_ForceExit(void);
/* END mkheaders: generated region */

#endif
