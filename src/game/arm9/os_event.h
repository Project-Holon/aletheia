#ifndef GAME_ARM9_OS_EVENT_H
#define GAME_ARM9_OS_EVENT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_event.c, prototypes copied from their definitions. */

#include "../sdk_os.h"
#include "../types.h"

void OS_InitEvent(OSEvent *event);
u32 OS_WaitEventEx(OSEvent *event, u32 pattern, OSEventMode mode, u32 clearBit);
void OS_SignalEvent(OSEvent *event, u32 setPattern);
/* END mkheaders: generated region */

#endif
