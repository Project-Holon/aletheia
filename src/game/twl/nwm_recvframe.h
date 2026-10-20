#ifndef GAME_TWL_NWM_RECVFRAME_H
#define GAME_TWL_NWM_RECVFRAME_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nwm_recvframe.c, prototypes copied from their definitions. */

struct TwlMsg;
typedef struct TwlMsg TwlMsg;

#include "../types.h"

u32 NWM_SetReceivingFrameBuffer(void *callback, void *recvBuf, u32 recvBufSize, u32 protocol);
u32 NWM_UnsetReceivingFrameBuffer(void *callback, u32 protocol);
void NWMi_ReceivingFrameCallback(TwlMsg *msg);
/* END mkheaders: generated region */

#endif
