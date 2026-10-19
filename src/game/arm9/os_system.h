#ifndef GAME_ARM9_OS_SYSTEM_H
#define GAME_ARM9_OS_SYSTEM_H

/* Public functions of os_system.c, prototypes copied from their definitions. */

OSIntrMode OS_EnableInterrupts(void);
OSIntrMode OS_DisableInterrupts(void);
OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
void OS_DisableInterrupts_IrqAndFiq(void);
void OS_RestoreInterrupts_IrqAndFiq(void);
unsigned int OS_GetCpsrIrq(void);
unsigned int OS_GetProcMode(void);
void OS_SpinWaitCpuCycles(u32 cycle);
void OS_SpinWaitSysCycles(u32 cycle);
void OS_WaitInterrupt(BOOL clear, u32 irqFlags);
void OS_WaitVBlankIntr(void);

#endif
