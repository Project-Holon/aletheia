#ifndef GAME_TWL_DSP_PIPE_H
#define GAME_TWL_DSP_PIPE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dsp_pipe.c, prototypes copied from their definitions. */

struct DspRing;
typedef struct DspRing DspRing;

#include "../types.h"

void DSPi_FileIOProc(void *arg);
void DSPi_NotifyFileIOUpdation(u32 ch);
void DSPi_PipeCallbackToConsole(void *userdata, int port, int peer);
void DSP_InitPipe(void);
DspRing *DSP_LoadPipe(DspRing *out, int ch, int dir);
DspRing *DSP_SyncPipe(DspRing *pipe);
void DSP_FlushPipe(DspRing *pipe);
u16 DSP_GetPipeReadableSize(DspRing *pipe);
void DSP_ReadPipe(DspRing *pipe, void *dst, u16 count);
void DSP_WritePipe(DspRing *pipe, void *src, u16 count);
void DSP_HookPipeNotification(u32 arg);
/* END mkheaders: generated region */

#endif
