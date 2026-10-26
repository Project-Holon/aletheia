#ifndef GAME_TWL_NWM_RECVFRAME_H
#define GAME_TWL_NWM_RECVFRAME_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nwm_recvframe.c, prototypes copied from their definitions. */

struct TwlMsg;
typedef struct TwlMsg TwlMsg;

#include "../types.h"
#include "../twl/nwm_callback_types.h"

u32 NWM_SetReceivingFrameBuffer(NWMCallbackFunc callback, void *recvBuf, u32 recvBufSize, u32 protocol);
u32 NWM_UnsetReceivingFrameBuffer(NWMCallbackFunc callback, u32 protocol);
void NWMi_ReceivingFrameCallback(void *arg);
/* END mkheaders: generated region */

#endif
