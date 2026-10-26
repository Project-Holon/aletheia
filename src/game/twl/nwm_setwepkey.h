#ifndef GAME_TWL_NWM_SETWEPKEY_H
#define GAME_TWL_NWM_SETWEPKEY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nwm_setwepkey.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../twl/nwm_callback_types.h"

u32 NWM_SetWEPKey(NWMCallbackFunc callback, u32 wepMode, u32 keyId, const u8 *wepKey, u16 flags);
/* END mkheaders: generated region */

#endif
