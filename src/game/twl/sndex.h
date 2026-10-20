#ifndef GAME_TWL_SNDEX_H
#define GAME_TWL_SNDEX_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sndex.c, prototypes copied from their definitions. */

#include "../types.h"

typedef void (*Cb)(u32, void *);

void SNDEXi_Init(void);
u32 SNDEXi_SetVolumeAsync(u32 volume, Cb callback, void *userData, u32 mode);
u32 SNDEXi_SetVolumeExAsync(u32 volume, Cb callback, void *userData);
u32 SNDEXi_SetIirFilterAsync(u32 target, u16 *coefficients, Cb callback, void *userData);
u32 SNDEXi_SetIirFilter(u32 target, u16 *coefficients);
u32 SNDEXi_PreProcessForShutterSound(void);
u32 SNDEXi_PostProcessForShutterSound(Cb callback, void *userData);
void CommonCallback(u32 tag, u32 data, u32 err);
void SyncCallback(u32 result, void *queue);
u32 SendCommand(u32 command, u8 data);
u32 SendCommandEx(u32 command, u32 data);
u32 CheckState(void);
void ReplyCallback(u32 result);
void SetSndexWork(Cb callback, void *callbackArg, void *resultPtr, u32 command);
void SndexSleepAndExitCallback(void);
void WaitIirFilterSetting(void);
void WaitResetSoundCallback(u32 result, void *userData);
void ResetTempVolume(void);
/* END mkheaders: generated region */

#endif
