#ifndef GAME_OV013_VCT_AUDIO_H
#define GAME_OV013_VCT_AUDIO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of vct_audio.c, prototypes copied from their definitions. */

#include "../ov013/vct_types.h"
#include "../types.h"

VctAudioFrame *VCT_AUDIO_EncodeSendFrame(void);
int VCT_AUDIO_ReceiveFrame(u32 senderAid, VctAudioFrame *frame, u32 size, u64 arrivalTick);
int VCT_AUDIO_DecodePendingFrames(void);
int VCT_AUDIO_SendFrameStep(void);
void VCT_AUDIO_ResetPendingList(void);
void VCT_AUDIO_FlushPendingSlot(unsigned int slot);
void VCT_AUDIO_FlushPendingAll(void);
int VCT_AUDIO_QueuePending(VctRxPacket *packet);
VctRxPacket *VCT_AUDIO_GetPendingHead(void);
int VCT_AUDIO_GetPendingCount(unsigned int slot);
VctRxPacket *VCT_AUDIO_FindPending(u32 slot);
u32 VCT_AUDIO_UnlinkPending(VctRxPacket *packet);
void VCT_AUDIO_EncodeMuLaw(unsigned char *dst, const short *src, unsigned int sampleCount);
void VCT_AUDIO_DecodeMuLaw(unsigned char *src, short *dst, unsigned int sampleCount);
void VCT_AUDIO_ConvertPcm16ToPcm8(unsigned char *dst, short *src, unsigned int sampleCount);
void VCT_AUDIO_ConvertPcm8ToPcm16(signed char *src, short *dst, unsigned int sampleCount, int mode);
void VCT_AUDIO_ClearReadyQueue(unsigned int slot);
void VCT_AUDIO_FlushReadyQueue(u32 slot);
void VCT_AUDIO_FlushAllReadyQueues(void);
int VCT_AUDIO_InsertReadyPacket(VctRxPacket *packet, u32 slot);
void *VCT_AUDIO_PeekReadyPacket(unsigned int slot);
VctRxPacket *VCT_AUDIO_PopReadyPacket(u32 slot);
int VCT_AUDIO_GetReadyCount(unsigned int slot);
void VCT_AUDIO_InitReceiveSource(VctReceiveSource *source, u32 queueIndex, int peerAid);
void VCT_AUDIO_DetachReceiveSource(VctReceiveSource *source);
VctRxPacket *VCT_AUDIO_SetLastPacket(VctReceiveSource *source, VctRxPacket *packet);
void VCT_AUDIO_InitSequence(VctReceiveSource *source, u16 seq);
int VCT_AUDIO_UpdateSequence(VctReceiveSource *source, VctRxPacket *packet, u16 seq);
int VCT_AUDIO_TrackPacketTiming(VctReceiveSource *source, VctRxPacket *packet);
VctPeer *VCT_SESSION_AllocPeerRecord(unsigned int index);
int VCT_SESSION_FreePeerRecord(VctPeer *peer);
int VCT_SESSION_BuildGroupCommand(void *peer, unsigned int type, unsigned char *buffer, unsigned int size);
int VCT_SESSION_SendGroupCommand(VctPeer *peer, int type);
int VCT_SESSION_BuildPeerReply(VctPeer *peer, unsigned int type, unsigned char *buffer, unsigned int size);
int VCT_SESSION_SendPeerReply(VctPeer *peer, int type);
int VCT_SESSION_AddPeer(unsigned char aid);
int VCT_SESSION_RemovePeer(int aid);
int VCT_SESSION_InitPeerPool(VctInitParams *params);
void VCT_SESSION_ResetPeerPool(void);
/* END mkheaders: generated region */

#endif
