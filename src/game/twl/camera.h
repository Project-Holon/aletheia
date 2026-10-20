#ifndef GAME_TWL_CAMERA_H
#define GAME_TWL_CAMERA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of camera.c, prototypes copied from their definitions. */

#include "../types.h"

void CAMERA_ResetCore(void);
s32 CAMERA_IsBusyCore(void);
void CAMERA_StartCaptureCore(void);
void CAMERA_StopCaptureCore(void);
void CAMERA_SetTrimmingCore(unsigned int enable);
void CAMERA_SetOutputFormatCore(int mode);
s32 CAMERA_GetErrorStatusCore(void);
void CAMERA_ClearBufferCore(void);
void CAMERA_SetMasterInterruptCore(unsigned int enable);
void CAMERA_SetVsyncInterruptCore(unsigned int val);
void CAMERA_SetBufferErrorInterruptCore(unsigned int enable);
void CAMERA_SetTransferLinesCore(int mode);
s32 CAMERA_GetTransferLinesCore(void);
u32 CAMERA_GetMaxLinesRoundCore(u32 width, u32 height);
u32 CAMERA_GetBytesAtOnceCore(u32 width);
/* END mkheaders: generated region */

#endif
