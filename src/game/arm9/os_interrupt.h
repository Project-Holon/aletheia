#ifndef GAME_ARM9_OS_INTERRUPT_H
#define GAME_ARM9_OS_INTERRUPT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_interrupt.c, prototypes copied from their definitions. */

#include "../types.h"

void OS_InitIrqTable(void);
void OSi_EnterDmaCallback(u32 dmaNo, void (*callback)(void *), void *arg);
void OSi_EnterNDmaCallback(u32 dmaNo, void (*callback)(void *), void *arg);
void OSi_EnterTimerCallback(u32 timerNo, void (*callback)(void *), void *arg);
OSIrqMask OS_SetIrqMask(OSIrqMask intr);
OSIrqMask OS_EnableIrqMask(OSIrqMask intr);
OSIrqMask OS_DisableIrqMask(OSIrqMask intr);
OSIrqMask OS_ResetRequestIrqMask(OSIrqMask intr);
void OS_SetIrqStackChecker(void);
/* END mkheaders: generated region */

#endif
