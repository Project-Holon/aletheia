#ifndef GAME_ARM9_INTERNAL_H
#define GAME_ARM9_INTERNAL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of internal.c, prototypes copied from their definitions. */

#include "../types.h"

int RTCi_ReadRawDateTimeAsync(void);
int RTCi_ReadRawDateAsync(void);
int RTCi_ReadRawTimeAsync(void);
int RTCi_WriteRawStatus2Async(void);
BOOL RtcSendPxiCommand(unsigned long command);
/* END mkheaders: generated region */

#endif
