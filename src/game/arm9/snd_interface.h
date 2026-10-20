#ifndef GAME_ARM9_SND_INTERFACE_H
#define GAME_ARM9_SND_INTERFACE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of snd_interface.c, prototypes copied from their definitions. */

struct SNDBankData;
struct SNDDriverInfo;

#include "../types.h"

void SND_StopSeq(int playerNo);
void SND_PrepareSeq(int playerNo, const void *base, u32 offset, struct SNDBankData *bank);
void SND_StartPreparedSeq(u32 playerNo);
void SND_PauseSeq(int playerNo, int flag);
void SND_SetPlayerTempoRatio(int playerNo, int ratio);
void SND_SetPlayerVolume(int playerNo, int volume);
void SND_SetPlayerChannelPriority(int playerNo, int prio);
void SND_SetTrackVolume(int playerNo, u32 trackBitMask, int volume);
void SND_SetTrackPitch(int playerNo, u32 trackBitMask, int pitch);
void SND_SetTrackPan(int playerNo, u32 trackBitMask, int pan);
void SND_SetTrackModDepth(int playerNo, u32 trackBitMask, u32 depth);
void SND_SetTrackModSpeed(int playerNo, u32 trackBitMask, u32 speed);
void SND_SetTrackAllocatableChannel(int playerNo, u32 trackBitMask, u32 chBitMask);
void SND_StartTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
void SND_StopTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
void SND_SetTrackMute(int playerNo, u32 trackBitMask, int flag);
void SND_SetTrackMuteEx(int playerNo, u32 trackBitMask, int mute);
void SND_LockChannel(u32 chBitMask, u32 flags);
void SND_UnlockChannel(u32 chBitMask, u32 flags);
void SND_SetChannelTimer(u32 chBitMask, int timer);
void SND_SetChannelVolume(u32 chBitMask, int volume, int shift);
void SND_SetupChannelPcm(int chNo, int format, const void *dataaddr, int loop, int loopStart, int loopLen, int volume, int shift, int timer, int pan);
void SND_InvalidateSeqData(const void *start, const void *end);
void SND_InvalidateBankData(const void *start, const void *end);
void SND_InvalidateWaveData(const void *start, const void *end);
void SND_SetMasterVolume(int volume);
void SND_SetOutputSelector(int left, int right, int channel1, int channel3);
void SND_SetMasterPan(int pan);
void SND_ResetMasterPan(void);
void SND_ReadDriverInfo(struct SNDDriverInfo *info);
void SNDi_SetPlayerParam(int playerNo, u32 offset, u32 data, int size);
void SNDi_SetTrackParam(int playerNo, u32 trackBitMask, u32 offset, u32 data, int size);
void PushCommand_impl(int id, u32 value0, u32 value1, u32 value2, u32 value3);
/* END mkheaders: generated region */

#endif
