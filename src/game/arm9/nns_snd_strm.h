#ifndef GAME_ARM9_NNS_SND_STRM_H
#define GAME_ARM9_NNS_SND_STRM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_snd_strm.c, prototypes copied from their definitions. */

#include "../arm9/nns_snd_types.h"
#include "../types.h"

void NNS_SndStrmInit(SndStrm *strm);
int NNS_SndStrmAllocChannel(SndStrm *strm, int numChannels, const u8 *channelList);
void NNS_SndStrmFreeChannel(SndStrm *strm);
int NNS_SndStrmSetup(SndStrm *strm, int format, u32 bufferAddr, u32 length, u32 rate, s32 frames, NNSSndStrmCallback callback, u32 userData);
void NNS_SndStrmStart(SndStrm *strm);
void NNSi_SndStrmStopIfSetup(SndStrm *strm);
void NNS_SndStrmSetVolume(SndStrm *strm, s32 volume);
void NNS_SndStrmStop(SndStrm *strm);
void NNSi_SndStrmReleaseTimer(SndStrm *strm);
void NNSi_SndStrmTimerCallback(void * strmArg);
void NNSi_SndStrmUpdate(SndStrm *strm, u32 isTimerCall);
void NNSi_SndStrmAlarmHandler(void * strmArg);
/* END mkheaders: generated region */

#endif
