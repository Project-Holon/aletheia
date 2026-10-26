#ifndef GAME_OV013_VCT_MAIN_H
#define GAME_OV013_VCT_MAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of vct_main.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov013/vct_types.h"
#include "../arm9/mic.h"

void VCT_MAIN_InitAudio(void);
void VCT_MAIN_MicRestartDone(MICResult unused0, void * unused1);
void VCT_MAIN_StreamCallback(int status, int channelCount, void **buffers, u32 length, int format, VctWork *work);
int VCT_MAIN_RequestConnection(int peerType);
int VCT_MAIN_AcceptPendingPeer(int unused);
void VCT_MAIN_OnEventGroup(int aid, int event, VctPeer *peer, int arg);
void VCT_MAIN_OnEventPair(int aid, int event, VctPeer *peer, int arg);
void VCT_MAIN_ReleasePeer(VctPeer *peer);
void VCT_MAIN_Update(int sendPaused);
int VCT_MAIN_HandlePacket(int aid, u8 *data, int size);
void VCT_MAIN_Start(int heapId, int codecMode, int peerCount);
void VCT_MAIN_StartStream(void);
void VCT_MAIN_HangUp(void);
void VCT_MAIN_SetExitCallback(void (*callback)(void));
void VCT_MAIN_Exit(void);
int VCT_MAIN_GetVoiceLevel(void);
int VCT_MAIN_ConnectPeers(u32 peerMask, int excludedAid);
int VCT_MAIN_DisconnectPeers(int excludedAid);
void VCT_MAIN_SetMuted(int muted);
/* END mkheaders: generated region */

#endif
