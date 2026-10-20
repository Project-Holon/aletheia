#ifndef GAME_TWL_DSP_IF_H
#define GAME_TWL_DSP_IF_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dsp_if.c, prototypes copied from their definitions. */

#include "../types.h"

void DSP_PowerOnCore(void);
void DSP_PowerOffCore(void);
void DSP_ResetOnCore(void);
void DSP_ResetOffExCore(u32 mask);
void DSP_ResetInterfaceCore(void);
u32 DSP_SendDataIsEmptyCore(u32 index);
u32 DSP_RecvDataIsReadyCore(u32 index);
void DSP_SendDataCore(u32 index, u32 data);
u16 DSP_RecvDataCore(u32 ch);
void DSP_SendFifoExCore(u32 mode, u16 control, u16 *src, s32 count, u16 flags);
void DSP_RecvFifoExCore(u32 mode, u16 *dst, u16 control, s32 count, u16 flags);
u16 DSP_GetSemaphoreCore(void);
void DSP_ClearSemaphoreCore(u16 mask);
void DSP_MaskSemaphoreCore(u16 mask);
/* END mkheaders: generated region */

#endif
