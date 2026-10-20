#ifndef GAME_TWL_DSP_PROCESS_H
#define GAME_TWL_DSP_PROCESS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dsp_process.c, prototypes copied from their definitions. */

struct DspProc;
typedef struct DspProc DspProc;

#include "../types.h"

void DSP_StopDSPComponent(void);
void DSPi_ShutdownCallback(void *arg);
void DSPi_PreSleepCallback(void *arg);
void DSPi_MasterInterrupts(void);
u32 DSPi_ReadProcessImage(DspProc *proc, u32 offset, void *buf, s32 len);
u32 DSPi_CommitWram(DspProc *proc, s32 sel, u32 idx, s32 mode);
void DSP_InitProcessContext(DspProc *o, void *src);
u32 DSP_SwitchProcessMemory(DspProc *proc, s32 sel, u32 start, u32 count, s32 mode);
u32 DSP_MapAndLoadProcessImage(DspProc *proc, void *file, u16 bankMaskA, u16 bankMaskB);
void DSP_SetProcessHook(DspProc *proc, s32 mask, void (*handler)(u32), u32 arg);
void DSP_HookPostStartProcess(void);
u32 DSP_ExecuteProcess(DspProc *proc, void *file, u16 bankMaskA, u16 bankMaskB);
void DSP_QuitProcess(DspProc *proc);
DspProc *DSP_FindProcess(const char *name);
void DSP_WriteProcessPipe(void *process, int port, void *buf, u32 len);
/* END mkheaders: generated region */

#endif
