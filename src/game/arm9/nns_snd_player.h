#ifndef GAME_ARM9_NNS_SND_PLAYER_H
#define GAME_ARM9_NNS_SND_PLAYER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_snd_player.c, prototypes copied from their definitions. */

struct SNDTrackInfo;

#include "../types.h"
#include "../arm9/nns_snd_arc_types.h"
#include "../arm9/nns_snd_types.h"

void NNS_SndPlayerSetPlayerVolume(u32 playerNo, u32 volume);
void NNS_SndPlayerSetPlayableSeqCount(int playerNo, int playableSeqCount);
void NNS_SndPlayerSetAllocatableChannel(u32 playerNo, u32 channelMask);
u32 NNS_SndPlayerCreateHeap(int playerNo, NNSSndHeap *heap, u32 size);
void NNS_SndHandleStopSeq(SndHandle *handle, int fadeFrame);
void NNS_SndHandlePauseSeq(SndHandle *handle, unsigned char flag);
void NNS_SndHandleInit(SndHandle *handle);
void NNS_SndHandleReleaseSeq(SndHandle *handle);
u16 NNS_SndPlayerGetActiveSeqCount(u32 playerNo);
s32 NNS_SndPlayerCountPlayingSeqBySeqNo(u32 seqNo);
void NNS_SndHandleSetVolume(SndHandle *handle, int volume);
void NNS_SndHandleSetInitialVolume(SndHandle *handle, u8 volume);
void NNS_SndHandleMoveVolume(SndHandle *handle, u32 volume, u32 frames);
void NNS_SndHandlePause(SndHandle *handle, u32 value);
void NNS_SndHandleSetTrackPause(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleSetTrackMute(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleSetTrackVolume(SndHandle *handle, u32 trackMask, int volumeIndex);
void NNS_SndHandleSetTrackPitch(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleSetTrackPan(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleSetTrackModDepth(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleSetTrackModSpeed(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleStop(SndHandle *handle, u32 value);
void NNSi_SndHandleSetSeqNo(SndHandle *handle, u32 seqNo);
void NNSi_SndHandleSetSeqArc(SndHandle *handle, u32 seqArcNo, u32 seqArcIndex);
int NNS_SndHandleReadTrackInfo(SndHandle *handle, int trackNo, struct SNDTrackInfo *trackInfo);
void NNS_SndPlayerInit(void);
void NNS_SndPlayerMain(void);
SndSeqPlayer *NNSi_SndPlayerAllocSeqPlayer(SndHandle *handle, s32 playerNo, s32 priority);
void NNSi_SndPlayerFreeSeqPlayer(SndSeqPlayer *seqPlayer);
void NNSi_SndPlayerStartSeqPlayer(SndSeqPlayer *seqPlayer, const void *seqBase, u32 seqOffset, const void *bankData);
void NNSi_SndSeqPlayerStop(SndSeqPlayer *seqPlayer, int fadeFrame);
void NNSi_SndSeqPlayerPause(SndSeqPlayer *seqPlayer, u8 flag);
NNSSndHeap *NNSi_SndPlayerAllocHeap(s32 playerNo, SndSeqPlayer *seqPlayer);
void NNSi_SndSeqPlayerResetState(SndSeqPlayer *seqPlayer);
void NNSi_SndPlayerInsertSeqPlayer(SndPlayer *player, SndSeqPlayer *seqPlayer);
void NNSi_SndInsertActiveSeqPlayer(SndSeqPlayer *seqPlayer);
void NNSi_SndSeqPlayerStopNow(SndSeqPlayer *seqPlayer);
SndSeqPlayer *NNSi_SndAllocFreeSeqPlayer(s32 priority);
void NNSi_SndSeqPlayerRelease(SndSeqPlayer *seqPlayer);
void NNSi_SndPlayerHeapDisposeCallback(SndPlayerHeap *pPlayerHeap);
void NNSi_SndSeqPlayerSetPriority(SndSeqPlayer *seqPlayer, u32 priority);
/* END mkheaders: generated region */

#endif
