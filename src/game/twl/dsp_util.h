#ifndef GAME_TWL_DSP_UTIL_H
#define GAME_TWL_DSP_UTIL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dsp_util.c, prototypes copied from their definitions. */

#include "../types.h"

void DSPiShutterPostProcessCallback(u32 mode, void *userData);
void sound_handler(void *arg);
void DSPi_PipeCallbackForSound(void *userdata, int port, int peer);
void DSPi_PlaySoundEx(u8 *data, u32 size, u32 mode, int priority);
u32 DSPi_PlayShutterSoundCore(u8 *p, u32 len);
void DSPi_StopSoundCore(void);
u32 DSPi_IsShutterSoundPlayingCore(void);
/* END mkheaders: generated region */

#endif
