#ifndef GAME_ARM9_OS_IRQHANDLER_H
#define GAME_ARM9_OS_IRQHANDLER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_irqhandler.c, prototypes copied from their definitions. */

#include "../types.h"

void OS_WaitIrq(BOOL clear, u32 irqFlags);
void OS_IrqDummy(void);
/* END mkheaders: generated region */

#endif
