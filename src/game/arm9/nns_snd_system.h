#ifndef GAME_ARM9_NNS_SND_SYSTEM_H
#define GAME_ARM9_NNS_SND_SYSTEM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_snd_system.c, prototypes copied from their definitions. */

struct SNDTrackInfo;

#include "../types.h"

void NNS_SndInit(void);
void NNS_SndBoot(void);
void NNS_SndSetMasterVolume(int volume);
void NNS_SndSetMasterPan(u32 flag);
u32 NNS_SndReadDriverInfo(void);
int NNS_SndReadTrackInfo(int playerNo, int trackNo, struct SNDTrackInfo *trackInfo);
void NNS_SndPrependPostSleepCallback(void);
void NNS_SndAppendPostSleepCallback(void *p);
/* END mkheaders: generated region */

#endif
