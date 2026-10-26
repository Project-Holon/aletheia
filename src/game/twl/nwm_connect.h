#ifndef GAME_TWL_NWM_CONNECT_H
#define GAME_TWL_NWM_CONNECT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nwm_connect.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../twl/nwm_callback_types.h"

u32 NWM_Connect(NWMCallbackFunc callback, u32 authMode, const u16 *bssDesc);
/* END mkheaders: generated region */

#endif
