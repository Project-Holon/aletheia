#ifndef GAME_TWL_NWM_SENDFRAME_H
#define GAME_TWL_NWM_SENDFRAME_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nwm_sendframe.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../twl/nwm_callback_types.h"

u32 NWM_SendFrame(NWMCallbackFunc callback, u8 *destMac, u8 *frame, u32 length);
void NWMi_AddMACHeader(u8 *destMac, u8 *srcMac, u8 *frame, u32 length);
/* END mkheaders: generated region */

#endif
