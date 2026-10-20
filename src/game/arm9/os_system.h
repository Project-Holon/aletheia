#ifndef GAME_ARM9_OS_SYSTEM_H
#define GAME_ARM9_OS_SYSTEM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_system.c, prototypes copied from their definitions. */

#include "../types.h"

OSIntrMode OS_EnableInterrupts(void);
OSIntrMode OS_DisableInterrupts(void);
OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
OSIntrMode OS_DisableInterrupts_IrqAndFiq(void);
OSIntrMode OS_RestoreInterrupts_IrqAndFiq(OSIntrMode state);
unsigned int OS_GetCpsrIrq(void);
unsigned int OS_GetProcMode(void);
void OS_SpinWaitCpuCycles(u32 cycle);
void OS_SpinWaitSysCycles(u32 cycle);
void OS_WaitInterrupt(BOOL clear, u32 irqFlags);
void OS_WaitVBlankIntr(void);
/* END mkheaders: generated region */

#endif
