#ifndef GAME_ARM9_NNS_SND_WAVEOUT_H
#define GAME_ARM9_NNS_SND_WAVEOUT_H

typedef struct NNSSndWaveOutHandle NNSSndWaveOutHandle;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_snd_waveout.c, prototypes copied from their definitions. */

struct NNSSndWaveOutHandle;
typedef struct NNSSndWaveOutHandle NNSSndWaveOutHandle;

#include "../types.h"

int NNSi_SndWaveOutLockChannels(int mask);
void SND_CHANNEL_UnlockChannels(u32 channelMask);
void SND_CHANNEL_ClearClaimedMask(u32 channelMask);
int NNSi_SndWaveOutAllocSlot(void);
void NNS_SndWaveOutFreeChannel(u32 slotNo);
void NNS_SndWaveOutInit(void);
NNSSndWaveOutHandle *NNS_SndWaveOutAllocChannel(u32 slotNo);
void NNSi_SndWaveOutUnlockChannel(u32 *channelNoPtr);
int NNS_SndWaveOutStart(NNSSndWaveOutHandle *handle, int format, void *waveData, int loopFlag, int loopStart, int loopEnd, int sampleRate, int volume, int playFreq, int pan);
void NNS_SndWaveOutStop(NNSSndWaveOutHandle *handle);
void NNS_SndWaveOutSetVolume(NNSSndWaveOutHandle *handle, u32 volume);
void NNS_SndWaveOutSetSpeed(NNSSndWaveOutHandle *handle, int speed);
int NNS_SndWaveOutIsPlaying(NNSSndWaveOutHandle *handle);
void NNS_SndWaveOutWaitIdle(NNSSndWaveOutHandle *handle);
/* END mkheaders: generated region */

#endif
