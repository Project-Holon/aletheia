/*
 * file:     vct_main.c
 * unit:     yes
 * function: VCT_MAIN_InitAudio, VCT_MAIN_MicRestartDone, VCT_MAIN_StreamCallback, VCT_MAIN_RequestConnection, VCT_MAIN_AcceptPendingPeer, VCT_MAIN_OnEventGroup, VCT_MAIN_OnEventPair, VCT_MAIN_ReleasePeer, VCT_MAIN_Update, VCT_MAIN_HandlePacket, VCT_MAIN_Start, VCT_MAIN_StartStream, VCT_MAIN_HangUp, VCT_MAIN_SetExitCallback, VCT_MAIN_Exit, VCT_MAIN_GetVoiceLevel, VCT_MAIN_ConnectPeers, VCT_MAIN_DisconnectPeers, VCT_MAIN_SetMuted, VCT_ADPCM_Decode4Bit, VCT_ADPCM_Encode4Bit, VCT_ADPCM_Decode3Bit, VCT_ADPCM_Encode3Bit, VCT_ADPCM_Decode2Bit, VCT_ADPCM_Encode2Bit, VCT_ADPCM_DecodePacket, VCT_ADPCM_EncodePacket, VCT_SESSION_Init, VCT_SESSION_ClearMemberCount, VCT_SESSION_AddMember, VCT_SESSION_RemoveMember, VCT_SESSION_QueueFrame, VCT_SESSION_ReadChannel, VCT_SESSION_MixVoices, VCT_SESSION_SetCodecMode, VCT_SESSION_SetSendEnabled, VCT_SESSION_SetFilterEnabled
 * address:  0x021AEB20
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MIC_Init  0x0208B24C  arm
 *   PM_Init  0x0208B8B0  arm
 *   PM_SetAmp  0x0208BEF0  arm
 *   PM_SetAmpGain  0x0208BF38  arm
 *   VCT_SESSION_SetSendEnabled  0x021B0CD8  arm ov013
 *   NNS_SndInit  0x020726D0  arm
 *   NNS_SndStrmInit  0x020737C0  arm
 *   func_02082AC0  0x02082AC0  arm
 *   VCT_SESSION_SetFilterEnabled  0x021B0D08  arm ov013
 *   gVctWork     0x021B3C80  data ov013
 *   MI_CpuFill8  0x02082BCC  arm
 *   APP_ENV_IsRunOnTwl  0x0202EB0C  thumb
 *   MIC_StartAutoSamplingAsync  0x0208B2BC  arm
 *   MIC_StartLimitedSamplingAsync  0x0208B4C8  arm
 *   MIC_GetLastSamplingAddress  0x0208B4B8  arm
 *   VCT_SESSION_MixVoices  0x021B0B48  arm ov013
 *   VCT_SESSION_QueueFrame  0x021B07F8  arm ov013
 *   VCT_SESSION_AllocPeerRecord  0x021B1F2C  arm ov013
 *   VCT_SESSION_SendGroupCommand  0x021B20B0  arm ov013
 *   VCT_SESSION_FreePeerRecord  0x021B1F54  arm ov013
 *   VCT_SESSION_SendPeerReply  0x021B2180  arm ov013
 *   VCT_SESSION_AddMember  0x021B0614  arm ov013
 *   VCT_MAIN_ReleasePeer  0x021AEDEC  thumb ov013
 *   VCT_SESSION_RemoveMember  0x021B074C  arm ov013
 *   DWC_RAP_CleanupVchat  0x02156400  thumb ov009
 *   func_020870D0  0x020870D0  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   VCT_Update  0x021B386C  arm ov013
 *   DWC_GetMyAID  0x0216B838  arm ov009
 *   VCT_MAIN_RequestConnection  0x021AEC74  thumb ov013
 *   VCT_MAIN_AcceptPendingPeer  0x021AECC4  thumb ov013
 *   VCT_ReceiveFrame  0x021B38B0  arm ov013
 *   DWC_RAPCOMMON_Alloc  0x02156F5C  thumb ov009
 *   VCT_MAIN_InitAudio  0x021AEB20  thumb ov013
 *   NNS_SndStrmAllocChannel  0x02073838  arm
 *   NNS_SndStrmSetVolume  0x02073AD0  arm
 *   NNS_SndStrmSetup  0x020738C0  arm
 *   VCT_MAIN_StreamCallback  0x021AEB7C  thumb ov013
 *   func_02034714  0x02034714  arm
 *   VCT_MAIN_OnEventGroup  0x021AED08  thumb ov013
 *   VCT_MAIN_OnEventPair  0x021AED30  thumb ov013
 *   VCT_Init  0x021B370C  arm ov013
 *   VCT_SESSION_SetCodecMode  0x021B0C64  arm ov013
 *   VCT_MAIN_StartStream  0x021AF124  thumb ov013
 *   NNS_SndStrmStart  0x02073A60  arm
 *   MIC_StopAutoSampling  0x0208B480  arm
 *   MIC_StopLimitedSampling  0x0208B528  arm
 *   NNSi_SndStrmStopIfSetup  0x02073AB4  arm
 *   NNS_SndStrmFreeChannel  0x02073898  arm
 *   VCT_Exit  0x021B3844  arm ov013
 *   DWC_RAPCOMMON_Free  0x02156FDC  thumb ov009
 *   VCT_DSP_SetVoiceGateConfig  0x021B3064  arm ov013
 *   VCT_SESSION_AddPeer  0x021B21A4  arm ov013
 *   VCT_SESSION_RemovePeer  0x021B2254  arm ov013
 *   gAdpcmIndexTable4     0x021B3A0C  data ov013 a1
 *   gAdpcmStepTable     0x021B3A1C  data ov013 a2
 *   gAdpcmIndexTable3     0x021B3A04  data ov013 a1
 *   gAdpcmIndexTable2     0x021B3A00  data ov013 a1
 *   gVctSendState     0x021B3C84  data ov013 a4
 *   gVctSendEnabled     0x021B3C24  data ov013 a4
 *   gVctSession     0x021B60D8  data ov013 a4
 *   gVctFrameSpecs     0x021B3AD0  data ov013 a1
 *   gVctSendBuffer     0x021B42C0  data ov013 a4
 *   gVctMembers     0x021B3CB0  data ov013 a4
 *   gVctReceiveSources     0x021B3CBC  data ov013 a4
 *   OS_GetTickLo  0x02087170  arm
 *   VCT_DSP_InitVoiceGateDefaults  0x021B3250  arm ov013
 *   VCT_AUDIO_ClearReadyQueue  0x021B16E4  arm ov013
 *   VCT_AUDIO_InitReceiveSource  0x021B19BC  arm ov013
 *   VCT_AUDIO_ResetPendingList  0x021B12FC  arm ov013
 *   VCT_DSP_InitEchoState  0x021B3364  arm ov013
 *   VCT_DSP_ResetVoiceGate  0x021B3018  arm ov013
 *   VCT_AUDIO_DetachReceiveSource  0x021B1A48  arm ov013
 *   VCT_AUDIO_FlushReadyQueue  0x021B1720  arm ov013
 *   VCT_AUDIO_FlushPendingSlot  0x021B133C  arm ov013
 *   func_02082B0C  0x02082B0C  arm
 *   _ll_udiv       0x0209C00C  arm
 *   VCT_AUDIO_GetReadyCount  0x021B19AC  arm ov013
 *   VCT_AUDIO_PeekReadyPacket  0x021B190C  arm ov013
 *   VCT_POOL_FreeFrame  0x021B2FE4  arm ov013
 *   VCT_AUDIO_SetLastPacket  0x021B1A74  arm ov013
 *   gVctMixScratch     0x021B3E78  data ov013 a4
 *   VCT_SESSION_ReadChannel  0x021B0904  arm ov013
 *   VCT_DSP_MixSaturated  0x021B3624  arm ov013
 *   VCT_DSP_SetEchoReference  0x021B33E0  arm ov013
 *   MIi_CpuClearFast 0x02082AC0  arm
 */
#include "vct_types.h"

extern VctWork *gVctWork;

/* Power management and microphone driver. */
extern void MIC_Init(void);
extern void PM_Init(void);
extern unsigned int PM_SetAmp(unsigned int status);
extern unsigned int PM_SetAmpGain(unsigned int gain);
extern u32 APP_ENV_IsRunOnTwl(void);
extern int MIC_StartAutoSamplingAsync(void *param, void (*callback)(void), void *arg);
extern int MIC_StartLimitedSamplingAsync(void *param, void (*callback)(void), void *arg);
extern u32 MIC_GetLastSamplingAddress(void);
extern int MIC_StopAutoSampling(void);
extern int MIC_StopLimitedSampling(void);

/* Sound system and sound stream object (arm9 unit_020737C0). */
extern void NNS_SndInit(void);
extern void NNS_SndStrmInit(void *stream);
extern int NNS_SndStrmAllocChannel(u8 *stream, int channelCount, u8 *channelNumbers);
extern void NNS_SndStrmSetVolume(void *stream, s32 volume);
extern int NNS_SndStrmSetup(void *stream, int format, void *buffer, u32 length, int rate,
                         int frames, VctStreamCallback callback, void *arg);
extern void NNS_SndStrmStart(void *stream);
extern void NNSi_SndStrmStopIfSetup(void *stream);
extern void NNS_SndStrmFreeChannel(void *stream);

/* Memory, time and error helpers. */
extern void func_02082AC0(int value, void *dst, u32 size);
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern void func_02082B0C(const void *src, void *dst, u32 size);
extern u64 func_020870D0(void);
extern u16 OS_GetTickLo(void);
extern void func_02034714(const char *expr, u32 line, const char *file);

/* Wi-Fi glue (ov009). */
extern void DWC_RAP_CleanupVchat(void);
extern void *DWC_RAPCOMMON_Alloc(void *heap, u32 size, u32 align);
extern void DWC_RAPCOMMON_Free(u32 heap, void *block, int unused);
extern u8 DWC_GetMyAID(void);

/* Engine (ov013). */
extern VctPeer *VCT_SESSION_AllocPeerRecord(unsigned int peerType);
extern int VCT_SESSION_SendGroupCommand(VctPeer *peer, int command);
extern int VCT_SESSION_FreePeerRecord(VctPeer *peer);
extern int VCT_SESSION_SendPeerReply(VctPeer *peer, int state);
extern int VCT_SESSION_AddPeer(u8 aid);
extern int VCT_SESSION_RemovePeer(int aid);
extern void VCT_Update(void);
extern int VCT_ReceiveFrame(int aid, void *data, int size);
extern void VCT_Init(VctInitParams *param);
extern void VCT_Exit(void);
extern void VCT_DSP_SetVoiceGateConfig(void *out);
extern void VCT_DSP_InitVoiceGateDefaults(void);
extern void VCT_AUDIO_ClearReadyQueue(u32 index);
extern void VCT_AUDIO_InitReceiveSource(VctReceiveSource *channel, int index, int aid);
extern void VCT_AUDIO_ResetPendingList(void);
extern void VCT_DSP_InitEchoState(void);
extern int VCT_AUDIO_GetReadyCount(u32 index);
extern VctRxPacket *VCT_AUDIO_PeekReadyPacket(unsigned int index);
extern void VCT_POOL_FreeFrame(VctRxPacket *packet);
extern int VCT_AUDIO_SetLastPacket(VctReceiveSource *channel, VctRxPacket *packet);
extern void VCT_AUDIO_DetachReceiveSource(VctReceiveSource *channel);
extern void VCT_AUDIO_FlushReadyQueue(u32 index);
extern void VCT_AUDIO_FlushPendingSlot(u32 index);
extern void VCT_DSP_ResetVoiceGate(void);
extern void VCT_DSP_MixSaturated(s16 *input, s16 *other, s16 *output, u32 length);
extern void VCT_DSP_SetEchoReference(void *samples, u32 length);

extern void VCT_SESSION_SetSendEnabled(int enabled);
extern void VCT_SESSION_SetFilterEnabled(int enabled);

/* Two names for 0x02082AC0: see VCT_SESSION_MixVoices. */
extern void MIi_CpuClearFast(int value, void *dst, u32 size);

void VCT_MAIN_InitAudio(void);
void VCT_MAIN_MicRestartDone(void);
void VCT_MAIN_StreamCallback(int status, int channelCount, void **buffers, u32 length, int format, VctWork *work);
int VCT_MAIN_RequestConnection(int peerType);
int VCT_MAIN_AcceptPendingPeer(int unused);
void VCT_MAIN_OnEventGroup(int aid, int event, VctPeer *peer, int arg);
void VCT_MAIN_OnEventPair(int aid, int event, VctPeer *peer, int arg);
void VCT_MAIN_ReleasePeer(VctPeer *peer);
void VCT_MAIN_Update(int sendPaused);
int VCT_MAIN_HandlePacket(int aid, int data, int size);
void VCT_MAIN_Start(void *heap, int codecMode, int peerCount);
void VCT_MAIN_StartStream(void);
void VCT_MAIN_HangUp(void);
void VCT_MAIN_SetExitCallback(void (*callback)(void));
void VCT_MAIN_Exit(void);
int VCT_MAIN_GetVoiceLevel(void);
int VCT_MAIN_ConnectPeers(u32 peerMask, int excludedAid);
int VCT_MAIN_DisconnectPeers(int excludedAid);
void VCT_MAIN_SetMuted(int muted);

void VCT_ADPCM_Decode4Bit(const u8 *src, s16 *dst, u32 byteCount, AdpcmState *st);
void VCT_ADPCM_Encode4Bit(u8 *dst, s16 *src, u32 sampleCount, AdpcmState *st);
void VCT_ADPCM_Decode3Bit(const u8 *src, s16 *dst, u32 byteCount, AdpcmState *st);
void VCT_ADPCM_Encode3Bit(u8 *dst, s16 *src, u32 sampleCount, AdpcmState *st);
void VCT_ADPCM_Decode2Bit(const u8 *src, s16 *dst, u32 byteCount, AdpcmState *st);
void VCT_ADPCM_Encode2Bit(u8 *dst, s16 *src, u32 sampleCount, AdpcmState *st);
void VCT_ADPCM_DecodePacket(AdpcmState *hdr, void *dst, int packetBytes, int bits);
void VCT_ADPCM_EncodePacket(AdpcmHeader *out, void *samples, int sampleCount, AdpcmState *st, int bits);
int VCT_SESSION_Init(void);
void VCT_SESSION_ClearMemberCount(void);
int VCT_SESSION_AddMember(VctPeer *peer);
void VCT_SESSION_RemoveMember(VctPeer *peer);
int VCT_SESSION_QueueFrame(const u8 *src, u32 length);
int VCT_SESSION_ReadChannel(void *dst, u32 size, u32 channelIndex, u32 *sourceMask);
int VCT_SESSION_MixVoices(void *output, u32 length, u32 *sourceMask);
int VCT_SESSION_SetCodecMode(int codecMode);

/* ADPCM index tables (4, 3 and 2 bit codes) and the step table. */
extern const s8 gAdpcmIndexTable4[16];
extern const s16 gAdpcmStepTable[89];
extern const s8 gAdpcmIndexTable3[8];
extern const s8 gAdpcmIndexTable2[4];
extern VctPeer *gVctMembers[3];
extern s16 gVctMixScratch[];

/* Fixed text the engine passes to the error call (raw address kept: it lives in the overlay image). */
#define VCT_ERROR_TEXT ((const char *)0x021B3C20)

/* One-time setup of the audio hardware and the stream object. */
void VCT_MAIN_InitAudio(void)
{
    MIC_Init();
    PM_Init();
    PM_SetAmp(1);
    PM_SetAmpGain(3);
    VCT_SESSION_SetSendEnabled(1);
    NNS_SndInit();
    NNS_SndStrmInit(gVctWork->audioStream);
    func_02082AC0(0, gVctWork->playbackBuffers[1], VCT_BUFFER_BYTES);
    gVctWork->microsecondDebt = 0;
    VCT_SESSION_SetFilterEnabled(1);
}


/*
 * Unlabelled leaf (no lr save, so disasm.py never labels it); its address
 * is taken as a completion callback by VCT_MAIN_StreamCallback.
 */
void VCT_MAIN_MicRestartDone(void)
{
}



/*
 * Audio stream callback, one call per refill of the playback buffers. With
 * status 0 it clears the buffers; otherwise it restarts the microphone
 * auto-sampling if a restart is pending (param block at VctWork.micParam),
 * picks the half of the microphone ring that is not being written, and
 * mixes the received voices into each playback buffer. While the lid is
 * closed or the chat is muted it sends the silent second playback buffer
 * instead. Unless sending is paused it queues the chosen frame for sending.
 */
void VCT_MAIN_StreamCallback(int status, int channelCount, void **buffers, u32 length, int format, VctWork *work)
{
    u8 *micAddress;
    u32 i;

    micAddress = (u8 *)work;

    if (status == 0) {
        for (i = 0; i < channelCount; i++) {
            MI_CpuFill8(buffers[i], 0, length);
        }
        return;
    }
    if (APP_ENV_IsRunOnTwl() == 0) {
        if (gVctWork->micRestartPending != 0) {
            MIC_StartAutoSamplingAsync(&gVctWork->micParam, VCT_MAIN_MicRestartDone, 0);
            gVctWork->micRestartPending = 0;
        }
    } else {
        if (gVctWork->micRestartPending != 0) {
            MIC_StartLimitedSamplingAsync(&gVctWork->micParam, VCT_MAIN_MicRestartDone, 0);
            gVctWork->micRestartPending = 0;
        }
    }
    if ((u32)(MIC_GetLastSamplingAddress() - (u32)micAddress) < length) {
        micAddress = micAddress + length;
    }
    if (((*(volatile u16 *)HW_BUTTON_XY_BUF & PAD_DETECT_FOLD_MASK) >> PAD_DETECT_FOLD_SHIFT) != 0
        || gVctWork->muted != 0) {
        micAddress = gVctWork->playbackBuffers[1];
    }
    for (i = 0; i < channelCount; i++) {
        VCT_SESSION_MixVoices(buffers[i], length, 0);
    }
    if (gVctWork->sendPaused == 0) {
        VCT_SESSION_QueueFrame(micAddress, length);
    }
    gVctWork->streamPhase = 2;
}



/*
 * Start a connection to a peer of type peerType: reuse the pending peer or
 * allocate one, then issue command 0 to it. Returns 1 when the request was
 * started, 0 when it failed (the peer is released again).
 *
 * note: 2026-10-05 the call to VCT_SESSION_SendGroupCommand is written in each arm of the
 *   null test (new allocation, existing node); the compiler cross-jumps the
 *   shared tail and the first arm uses the call result register directly.
 */
int VCT_MAIN_RequestConnection(int peerType)
{
    VctPeer *peer = gVctWork->pendingPeer;
    int result;

    if (peer == 0) {
        peer = VCT_SESSION_AllocPeerRecord(peerType);
        if (peer == 0) {
            return 0;
        }
        result = VCT_SESSION_SendGroupCommand(peer, 0);
    } else {
        result = VCT_SESSION_SendGroupCommand(peer, 0);
    }
    if (result != 0) {
        VCT_SESSION_FreePeerRecord(peer);
        gVctWork->pendingPeer = 0;
        return 0;
    }
    gVctWork->pendingPeer = peer;
    return 1;
}



/* Accept the pending peer once the engine marked it closed-and-ready (phase 4). Returns 1 on success. */
int VCT_MAIN_AcceptPendingPeer(int unused)
{
    VctPeer *peer = gVctWork->pendingPeer;
    int accepted;

    if (peer != 0 && peer->phase == 4) {
        accepted = 0;
        if (VCT_SESSION_SendPeerReply(peer, 0) != 0) {
            return accepted;
        }
        if (VCT_SESSION_AddMember(gVctWork->pendingPeer) != 0) {
            accepted = 1;
        }
        return accepted;
    }
    return 0;
}



/* Engine event handler used when the chat mode is 3. */
void VCT_MAIN_OnEventGroup(int aid, int event, VctPeer *peer, int arg)
{
    switch(event) {
    case VCT_EVENT_PEER_LEFT: VCT_MAIN_ReleasePeer(peer); break;
    case VCT_EVENT_PEER_JOINED: VCT_SESSION_AddMember(peer); break;
    case VCT_EVENT_ENGINE_STOPPED: VCT_MAIN_ReleasePeer(peer); break;
    }
}


/* Engine event handler used for the other chat modes. */
void VCT_MAIN_OnEventPair(int aid, int event, VctPeer *peer, int arg)
{
    switch (event) {
    case VCT_EVENT_REQUEST_RECEIVED:
        if (gVctWork->pendingPeer != 0) {
            VCT_SESSION_SendPeerReply(peer, 3);
            VCT_SESSION_FreePeerRecord(peer);
            return;
        }
        gVctWork->pendingPeer = peer;
        return;
    case VCT_EVENT_REQUEST_REFUSED:
        VCT_SESSION_SendPeerReply(peer, 0);
        VCT_MAIN_ReleasePeer(peer);
        return;
    case VCT_EVENT_PEER_LEFT:
        VCT_MAIN_ReleasePeer(peer);
        return;
    case VCT_EVENT_CONNECTION_CLOSED:
        VCT_SESSION_SendPeerReply(peer, 4);
        VCT_MAIN_ReleasePeer(peer);
        return;
    case VCT_EVENT_PEER_JOINED:
        if (peer->mode != gVctWork->mode) {
            VCT_MAIN_ReleasePeer(peer);
            return;
        }
        if (VCT_SESSION_AddMember(peer) != 0) {
            gVctWork->linkState = 2;
            return;
        }
        break;
    case VCT_EVENT_REQUEST_CANCELLED:
        VCT_MAIN_ReleasePeer(peer);
        return;
    case VCT_EVENT_REQUEST_TIMED_OUT:
    case VCT_EVENT_ENGINE_ERROR:
    case VCT_EVENT_ENGINE_STOPPED:
        VCT_MAIN_ReleasePeer(peer);
        break;
    }
}


/* Drop a peer: remove it from the members, free its node, clear the pending slot and stop the chat. */
void VCT_MAIN_ReleasePeer(VctPeer *peer)
{
    VCT_SESSION_RemoveMember(peer);
    VCT_SESSION_FreePeerRecord(peer);
    gVctWork->pendingPeer = 0;
    DWC_RAP_CleanupVchat();
}



/*
 * Frame step: records sendPaused, accumulates the elapsed microseconds
 * past one 60 Hz frame (VCT_FRAME_MICROSECONDS) in microsecondDebt since
 * the tick stamped in lastTick, runs the engine step (VCT_Update) once
 * per whole frame owed, then advances the link state machine unless the
 * chat mode is 3: 0 = try to start (host) or accept (client) a connection,
 * 1 = wait 60 frames before retrying, 2 = connected.
 */
void VCT_MAIN_Update(int sendPaused)
{
    u64 tick;

    gVctWork->sendPaused = sendPaused;
    tick = func_020870D0();
    gVctWork->microsecondDebt +=
        (s32)(((u32)tick - (u32)gVctWork->lastTick) * 64000 / 33514) - VCT_FRAME_MICROSECONDS;
    if (gVctWork->microsecondDebt < -10000) {
        gVctWork->microsecondDebt = 0;
    }
    gVctWork->lastTick = tick;
    VCT_Update();
    while (gVctWork->microsecondDebt >= VCT_FRAME_MICROSECONDS) {
        VCT_Update();
        gVctWork->microsecondDebt -= VCT_FRAME_MICROSECONDS;
    }
    if (gVctWork->mode == 3) {
        return;
    }
    switch (gVctWork->linkState) {
    case 0:
        if (DWC_GetMyAID() == 0) {
            if (VCT_MAIN_RequestConnection(1) != 0) {
                gVctWork->linkState = 1;
                gVctWork->requestCooldown = 60;
            }
        } else if (DWC_GetMyAID() == 1) {
            if (VCT_MAIN_AcceptPendingPeer(0) != 0) {
                gVctWork->linkState = 2;
            }
        }
        break;
    case 1:
        gVctWork->requestCooldown -= 1;
        if (gVctWork->requestCooldown == 0) {
            gVctWork->linkState = 0;
        }
        break;
    case 2:
        break;
    }
}

/*
 * Hand a received signalling packet to the engine. Returns 0 when there is
 * no chat or the engine rejects the packet, else 1.
 * Narrow first callee argument follows the explicit lsls/lsrs at 021AEF52;
 * the other two inputs stay live from entry for the three-input callee.
 */
int VCT_MAIN_HandlePacket(int aid, int data, int size)
{
    if (gVctWork == 0) return 0;
    if (VCT_ReceiveFrame((unsigned char)aid, (void *)data, size) != 0) return 1;
    return 0;
}


/*
 * Start the voice chat: allocate the work block and the engine queue memory
 * (first call only), start microphone sampling and the playback stream,
 * start the engine with the matching event handler, then set the codec mode.
 * peerCount sizes the receive queue memory.
 */
void VCT_MAIN_Start(void *heap, int codecMode, int peerCount)
{
    VctInitParams param;
    u8 channelNumbers[3] = {0, 0, 0};

    if (gVctWork == 0) {
        gVctWork = DWC_RAPCOMMON_Alloc(heap, sizeof(VctWork), 0x20);
        MI_CpuFill8(gVctWork, 0, sizeof(VctWork));
        gVctWork->frameMemory = DWC_RAPCOMMON_Alloc(heap, peerCount * VCT_PEER_QUEUE_BYTES + 0x20, 0x20);
        gVctWork->exitCallback = 0;
        VCT_MAIN_InitAudio();
    }
    gVctWork->micParam.type = 3;
    gVctWork->micParam.buffer = gVctWork;
    gVctWork->micParam.size = VCT_BUFFER_BYTES;
    if (APP_ENV_IsRunOnTwl() == 0) {
        gVctWork->micParam.rate = 0x1040;
    } else {
        gVctWork->micParam.rate = 0x1001;
    }
    gVctWork->micParam.loopEnable = 1;
    gVctWork->micParam.fullCallback = 0;
    gVctWork->micParam.fullArg = 0;
    gVctWork->micRestartPending = 1;
    NNS_SndStrmAllocChannel(gVctWork->audioStream, 1, channelNumbers);
    NNS_SndStrmSetVolume(gVctWork->audioStream, 0);
    if (NNS_SndStrmSetup(gVctWork->audioStream, 1, gVctWork->playbackBuffers, VCT_BUFFER_BYTES,
                      APP_ENV_IsRunOnTwl() ? 0x40 : 0x41, 2, VCT_MAIN_StreamCallback,
                      gVctWork) == 0) {
        func_02034714(VCT_ERROR_TEXT, 0, VCT_ERROR_TEXT);
    }
    gVctWork->linkState = 0;
    gVctWork->pendingPeer = 0;
    gVctWork->mode = param.mode = 1;
    param.peerBuffer = &gVctWork->enginePeer;
    param.peerCount = peerCount;
    param.localId = DWC_GetMyAID();
    if (param.localId == -1) {
        func_02034714(VCT_ERROR_TEXT, 0, VCT_ERROR_TEXT);
    }
    if (gVctWork->mode == 3) {
        param.eventCallback = VCT_MAIN_OnEventGroup;
    } else {
        param.eventCallback = VCT_MAIN_OnEventPair;
    }
    param.callbackArg = 0;
    param.frameBuffer = (int)gVctWork->frameMemory;
    param.frameBufferSize = peerCount * VCT_PEER_QUEUE_BYTES + 0x20;
    VCT_Init(&param);
    gVctWork->sendPaused = 0;
    VCT_SESSION_SetCodecMode(codecMode);
    VCT_MAIN_StartStream();
    VCT_SESSION_SetFilterEnabled(1);
}


/* Start the playback stream. */
void VCT_MAIN_StartStream(void) { NNS_SndStrmStart(gVctWork->audioStream); }


/* Hang up: ask the engine to end the pending request, then stop the chat. */
void VCT_MAIN_HangUp(void)
{
    if (gVctWork->pendingPeer == 0 || gVctWork->linkState == 0) {
        DWC_RAP_CleanupVchat();
        return;
    }
    if (gVctWork->linkState == 1) {
        if (VCT_SESSION_SendGroupCommand(gVctWork->pendingPeer, 2)) {
            DWC_RAP_CleanupVchat();
            return;
        }
    }
    if (VCT_SESSION_SendGroupCommand(gVctWork->pendingPeer, 1)) {
        DWC_RAP_CleanupVchat();
    }
}


/* Register the function called when the chat has shut down. */
void VCT_MAIN_SetExitCallback(void (*callback)(void))
{
    gVctWork->exitCallback = callback;
}



/* Shut the chat down: stop microphone and stream, free the memory, then call the exit callback. */
void VCT_MAIN_Exit(void)
{
    void (*callback)(void);

    if (gVctWork == 0) {
        return;
    }
    callback = gVctWork->exitCallback;
    if (APP_ENV_IsRunOnTwl() == 0) {
        MIC_StopAutoSampling();
    } else {
        MIC_StopLimitedSampling();
    }
    NNSi_SndStrmStopIfSetup(gVctWork->audioStream);
    NNS_SndStrmFreeChannel(gVctWork->audioStream);
    VCT_Exit();
    PM_SetAmp(0);
    DWC_RAPCOMMON_Free(0, gVctWork->frameMemory, 0);
    DWC_RAPCOMMON_Free(0, gVctWork, 0);
    gVctWork = 0;
    if (callback) {
        callback();
    }
}


/* Voice-activity level: returns the first gate statistic when the second one exceeds 2, else 0. */
int VCT_MAIN_GetVoiceLevel(void)
{
    int gateStats[4];
    if (gVctWork != 0) {
        VCT_DSP_SetVoiceGateConfig(gateStats);
        if (gateStats[1] > 2) return gateStats[0];
    }
    return 0;
}



/* Group chat: connect every peer in peerMask except excludedAid. Returns 0 when the engine refuses one. */
int VCT_MAIN_ConnectPeers(u32 peerMask, int excludedAid)
{
    int i;

    if (gVctWork == 0 || gVctWork->mode != 3) {
        return 0;
    }
    for (i = 0; i < 2; i++) {
        if (i == excludedAid) {
            continue;
        }
        if (!(peerMask & (1 << i))) {
            continue;
        }
        if (gVctWork->peerActive[i] == 1) {
            continue;
        }
        if (VCT_SESSION_AddPeer(i)) {
            return 0;
        }
        gVctWork->peerActive[i] = 1;
    }
    return 1;
}



/* Group chat: disconnect every connected peer except excludedAid. Returns 0 when the engine refuses one. */
int VCT_MAIN_DisconnectPeers(int excludedAid)
{
    int i;

    if (gVctWork == 0 || gVctWork->mode != 3) {
        return 0;
    }
    for (i = 0; i < 2; i++) {
        if (i == excludedAid) {
            continue;
        }
        if (gVctWork->peerActive[i] != 1) {
            continue;
        }
        if (VCT_SESSION_RemovePeer((u8)i)) {
            return 0;
        }
        gVctWork->peerActive[i] = 0;
    }
    return 1;
}

/* Mute or unmute the microphone: a muted chat sends silence, and the pending peer is removed or re-added. */
void VCT_MAIN_SetMuted(int muted)
{
    if (gVctWork != 0) {
        gVctWork->muted = muted;
        if (gVctWork->pendingPeer != 0) {
            if (muted != 0) VCT_SESSION_RemoveMember(gVctWork->pendingPeer);
            else VCT_SESSION_AddMember(gVctWork->pendingPeer);
        }
    }
}

#pragma thumb off

#define ADPCM_ENCODE(code, step, predicted, indexVar, diff, delta, newPred, sample) \
    indexVar = st->stepIndex;                                           \
    predicted = st->predictor;                                              \
    step = gAdpcmStepTable[indexVar];                                    \
    diff = (sample) - predicted;                                       \
    if (diff < 0) {                                            \
        code = 8;                                              \
        diff = -diff;                                          \
    } else {                                                   \
        code = 0;                                              \
    }                                                          \
    if (diff >= step) {                                        \
        code |= 4;                                             \
        diff -= step;                                          \
    }                                                          \
    if (diff >= (step >> 1)) {                                 \
        code |= 2;                                             \
        diff -= step >> 1;                                     \
    }                                                          \
    if (diff >= (step >> 2)) {                                 \
        code |= 1;                                             \
    }                                                          \
    delta = step >> 3;                                            \
    if (code & 4) {                                            \
        delta += step;                                            \
    }                                                          \
    if (code & 2) {                                            \
        delta += step >> 1;                                       \
    }                                                          \
    if (code & 1) {                                            \
        delta += step >> 2;                                       \
    }                                                          \
    if (code & 8) {                                            \
        delta = -delta;                                              \
    }                                                          \
    newPred = predicted + delta;                                               \
    if (newPred < -32768) {                                         \
        newPred = -32768;                                           \
    }                                                          \
    if (newPred > 32767) {                                          \
        newPred = 32767;                                            \
    }                                                          \
    indexVar += gAdpcmIndexTable4[code];                                   \
    if (indexVar < 0) {                                             \
        indexVar = 0;                                               \
    } else if (indexVar > 88) {                                     \
        indexVar = 88;                                              \
    }                                                          \
    st->predictor = (s16)newPred;                                        \
    st->stepIndex = indexVar

static inline s16 Adpcm4DecodeCode(AdpcmState *st, int code)
{
    int predicted;
    int stepIndex;
    int step;
    int diff;

    stepIndex = st->stepIndex;
    predicted = st->predictor;
    step = gAdpcmStepTable[stepIndex];
    diff = step >> 3;
    if (code & 4) {
        diff += step;
    }
    if (code & 2) {
        diff += step >> 1;
    }
    if (code & 1) {
        diff += step >> 2;
    }
    if (code & 8) {
        predicted -= diff;
        if (predicted < -32768) {
            predicted = -32768;
        }
    } else {
        predicted += diff;
        if (predicted > 32767) {
            predicted = 32767;
        }
    }
    stepIndex += gAdpcmIndexTable4[code];
    if (stepIndex < 0) {
        stepIndex = 0;
    } else if (stepIndex > 88) {
        stepIndex = 88;
    }
    st->stepIndex = stepIndex;
    st->predictor = (s16)predicted;
    return (s16)predicted;
}




/*
 * IMA ADPCM decoder: n source bytes, low nibble first, to 2n s16 samples,
 * with the predictor and step index carried in *st. Index table (s8[16])
 * at 0x021B3A0C, step table (s16[89]) at 0x021B3A1C.
 */
void VCT_ADPCM_Decode4Bit(const u8 *src, s16 *dst, u32 byteCount, AdpcmState *st)
{
    u32 i;

    for (i = 0; i < byteCount; i++) {
        *dst++ = Adpcm4DecodeCode(st, *src & 0xF);
        *dst++ = Adpcm4DecodeCode(st, (*src >> 4) & 0xF);
        src++;
    }
}





/*
 * IMA ADPCM encoder: n s16 samples to n/2 bytes, first sample in the low
 * nibble, predictor and step index carried in *st. Index table (s8[16])
 * at 0x021B3A0C, step table (s16[89]) at 0x021B3A1C. Same tables and
 * state struct as the decoders VCT_ADPCM_Decode4Bit and VCT_ADPCM_Decode3Bit.
 *
 * pass 6 2026-10-06 P6L06: closed with the register colouring capture
 * (scratchpad tools6/regalloc_trace.py). The colouring is round 1 (round 0
 * spills the hoisted constants). Simplify sweeps vregs in ascending order,
 * so the image needs vreg(step1) < vreg(pairCount) < vreg(predicted1, stepIndex1, code1).
 * With an inline helper the copy of its locals is one block below all outer
 * locals, so pairCount can never fall inside it. The encoder is a macro over
 * per-sample function locals; outer locals are numbered in reverse
 * declaration order, so the sample-1 locals are declared before pairCount and
 * step1/sample1 after it.
 */
void VCT_ADPCM_Encode4Bit(u8 *dst, s16 *src, u32 sampleCount, AdpcmState *st)
{
    u32 i;
    u8 lo;
    u8 hi;
    int newPred1, delta1, code1, diff1, stepIndex1, predicted1;
    u32 pairCount;
    int step1, sample1;
    int newPred2, delta2, code2, diff2, stepIndex2, predicted2;
    int step2, sample2;

    pairCount = sampleCount / 2;
    for (i = 0; i < pairCount; i++) {
        sample1 = *src++;
        ADPCM_ENCODE(code1, step1, predicted1, stepIndex1, diff1, delta1, newPred1, sample1);
        lo = code1;
        sample2 = *src++;
        ADPCM_ENCODE(code2, step2, predicted2, stepIndex2, diff2, delta2, newPred2, sample2);
        hi = code2;
        *dst++ = lo | (u8)(hi << 4);
    }
}




static inline s16 Adpcm3DecodeCode(AdpcmState *st, int code)
{
    int predicted;
    int stepIndex;
    int step;
    int diff;
    stepIndex = st->stepIndex;
    predicted = st->predictor;
    step = gAdpcmStepTable[stepIndex];
    diff = step >> 2;
    if (code & 2) diff += step;
    if (code & 1) diff += step >> 1;
    if (code & 4) {
        predicted -= diff;
        if (predicted < -32768) predicted = -32768;
    } else {
        predicted += diff;
        if (predicted > 32767) predicted = 32767;
    }
    stepIndex += gAdpcmIndexTable3[code];
    if (stepIndex < 0) stepIndex = 0;
    else if (stepIndex > 88) stepIndex = 88;
    st->stepIndex = stepIndex;
    st->predictor = (s16)predicted;
    return (s16)predicted;
}




/*
 * Byte locals for all three packed input bytes reproduce the spilled step
 * temporaries; fixed dst indexes and explicit pointer steps reproduce the tail.
 * 3-bit ADPCM decoder, eight samples per three input bytes, high bits first.
 */
void VCT_ADPCM_Decode3Bit(const u8 *src, s16 *dst, u32 byteCount, AdpcmState *st)
{
    u32 i;
    u8 byte0;
    u8 byte1;
    u8 byte2;
    for (i = 0; i < byteCount / 3; i++) {
    byte0 = src[0];
    byte1 = src[1];
    byte2 = src[2];
    dst[0] = Adpcm3DecodeCode(st, byte0 >> 5);
    dst[1] = Adpcm3DecodeCode(st, (byte0 >> 2) & 7);
    dst[2] = Adpcm3DecodeCode(st, ((byte0 << 1) & 7) | (byte1 >> 7));
    dst[3] = Adpcm3DecodeCode(st, (byte1 >> 4) & 7);
    dst[4] = Adpcm3DecodeCode(st, (byte1 >> 1) & 7);
    dst[5] = Adpcm3DecodeCode(st, ((byte1 << 2) & 7) | (byte2 >> 6));
    dst[6] = Adpcm3DecodeCode(st, (byte2 >> 3) & 7);
    dst[7] = Adpcm3DecodeCode(st, byte2 & 7);
        src += 3;
        dst += 8;
    }
}



static inline u8 Adpcm3EncodeSample(AdpcmState *st, int sample)
{
    int delta;
    int predicted;
    int step;
    int stepIndex;
    int diff;
    int code;
    int newPred;
    stepIndex = st->stepIndex;
    predicted = st->predictor;
    diff = sample - predicted;
    if (diff < 0) {
        code = 4;
        diff = -diff;
    } else {
        code = 0;
    }
    step = gAdpcmStepTable[stepIndex];
    if (diff >= step) {
        code |= 2;
        diff -= step;
    }
    if (diff >= (step >> 1)) {
        code |= 1;
    }
    delta = step >> 2;
    if (code & 2) delta += step;
    if (code & 1) delta += step >> 1;
    if (code & 4) delta = -delta;
    newPred = predicted + delta;
    if (newPred < -32768) newPred = -32768;
    if (newPred > 32767) newPred = 32767;
    stepIndex += gAdpcmIndexTable3[code];
    if (stepIndex < 0) stepIndex = 0;
    else if (stepIndex > 88) stepIndex = 88;
    st->predictor = (s16)newPred;
    st->stepIndex = stepIndex;
    return code;
}




/*
 * 3-bit ADPCM encoder (twin of the decoder VCT_ADPCM_Decode3Bit): n/8 groups of eight
 * s16 samples to three bytes each, high bits first. Predictor and step index
 * are carried in *st.
 * pass 6 2026-10-06 P6L07: EXACT (was 352 B off; EXACT in --lang c99 and --lang c). Found with a
 * capture of the mwccarm register allocator (SelectColors at 0x5269d0) and an exact replay model of
 * its simplify/select passes. Levers: (1) the step table read once after the sign if/else (join form);
 * (2) helper locals declared delta, predicted, step, stepIndex, diff, code, newPred (each inline copy numbers its
 * locals in declaration order, and steady and reloaded samples are simplified in different passes);
 * (3) one u8 accumulator reused for all three output bytes (the second and third live ranges become
 * new, late-numbered webs, so they take r6 as in the original).
 */
void VCT_ADPCM_Encode3Bit(u8 *dst, s16 *src, u32 sampleCount, AdpcmState *st)
{
    u32 i;
    u8 packed;
    u8 code2, code5;
    for (i = 0; i < sampleCount / 8; i++) {
        packed = Adpcm3EncodeSample(st, *src++) << 5;
        packed |= Adpcm3EncodeSample(st, *src++) << 2;
        code2 = Adpcm3EncodeSample(st, *src++);
        *dst++ = packed | (code2 >> 1);
        packed = Adpcm3EncodeSample(st, *src++) << 4;
        packed |= Adpcm3EncodeSample(st, *src++) << 1;
        code5 = Adpcm3EncodeSample(st, *src++);
        *dst++ = packed | (code2 << 7) | (code5 >> 2);
        packed = Adpcm3EncodeSample(st, *src++) << 3;
        packed |= Adpcm3EncodeSample(st, *src++);
        *dst++ = packed | (code5 << 6);
    }
}




static inline s16 Adpcm2DecodeCode(AdpcmState *st, int code)
{
    int predicted;
    int stepIndex;
    int diff;

    stepIndex = st->stepIndex;
    predicted = st->predictor;
    diff = gAdpcmStepTable[stepIndex];
    if (!(code & 1)) {
        diff = 0;
    }
    if (code & 2) {
        predicted -= diff;
        if (predicted < -32768) {
            predicted = -32768;
        }
    } else {
        predicted += diff;
        if (predicted > 32767) {
            predicted = 32767;
        }
    }
    stepIndex += gAdpcmIndexTable2[code];
    if (stepIndex < 0) {
        stepIndex = 0;
    } else if (stepIndex > 88) {
        stepIndex = 88;
    }
    st->stepIndex = stepIndex;
    st->predictor = (s16)predicted;
    return (s16)predicted;
}




/*
 * 2-bit ADPCM decoder: n source bytes, low pair first, to 4n s16 samples,
 * with the predictor and step index carried in *st (the 4-bit IMA twin is
 * VCT_ADPCM_Decode4Bit). Index table (s8[4]) at 0x021B3A00, step table (s16[89])
 * at 0x021B3A1C.
 */
void VCT_ADPCM_Decode2Bit(const u8 *src, s16 *dst, u32 byteCount, AdpcmState *st)
{
    u32 i;

    for (i = 0; i < byteCount; i++) {
        *dst++ = Adpcm2DecodeCode(st, *src & 3);
        *dst++ = Adpcm2DecodeCode(st, (*src >> 2) & 3);
        *dst++ = Adpcm2DecodeCode(st, (*src >> 4) & 3);
        *dst++ = Adpcm2DecodeCode(st, (*src >> 6) & 3);
        src++;
    }
}



static inline u8 Adpcm2EncodeSample(AdpcmState *st, int sample)
{
    int predicted;
    int stepIndex;
    int diff;
    int code;
    int delta;
    int newPred;
    stepIndex = st->stepIndex;
    predicted = st->predictor;
    diff = sample - predicted;
    if (diff < 0) {
        code = 2;
        diff = -diff;
    } else {
        code = 0;
    }
    if (diff >= gAdpcmStepTable[stepIndex]) {
        code |= 1;
    }
    delta = gAdpcmStepTable[stepIndex];
    if (!(code & 1)) delta = 0;
    if (code & 2) delta = -delta;
    newPred = predicted + delta;
    if (newPred < -32768) newPred = -32768;
    if (newPred > 32767) newPred = 32767;
    stepIndex += gAdpcmIndexTable2[code];
    if (stepIndex < 0) stepIndex = 0;
    else if (stepIndex > 88) stepIndex = 88;
    st->predictor = (s16)newPred;
    st->stepIndex = stepIndex;
    return code;
}



/*
 * 2-bit ADPCM encoder (twin of the decoder VCT_ADPCM_Decode2Bit): n/4 groups of four
 * s16 samples to one byte, low pair first.
 * final push 2026-10-05 G9L9: closed. Four changes from the old draft, all needed.
 * (1) No named step local: the table is read twice, in the compare and again for
 * the delta (`delta = gAdpcmStepTable[stepIndex]`); with a `step` local the preheader loaded
 * the index table first. (2) The new predictor is its own local `newPred`, so the add
 * does not write back into `predicted`. (3) `src` is not const: with const the stepIndex store
 * sinks below the orr. (4) The samples are read as `*src++`: that moves the src
 * increment into the last sample's slot (add r1,r1,#8 early).
 */
void VCT_ADPCM_Encode2Bit(u8 *dst, s16 *src, u32 sampleCount, AdpcmState *st)
{
    u32 i;
    u8 packed;
    for (i = 0; i < sampleCount / 4; i++) {
        packed = Adpcm2EncodeSample(st, *src++);
        packed |= Adpcm2EncodeSample(st, *src++) << 2;
        packed |= Adpcm2EncodeSample(st, *src++) << 4;
        packed |= Adpcm2EncodeSample(st, *src++) << 6;
        *dst++ = packed;
    }
}




void VCT_ADPCM_DecodePacket(AdpcmState *hdr, void *dst, int packetBytes, int bits)
{
    AdpcmState st;

    st.predictor = hdr->predictor;
    st.stepIndex = hdr->stepIndex;
    switch (bits) {
    case 2:
        VCT_ADPCM_Decode2Bit((u8 *)hdr + 4, dst, packetBytes - 4, &st);
        break;
    case 3:
        VCT_ADPCM_Decode3Bit((u8 *)hdr + 4, dst, packetBytes - 4, &st);
        break;
    case 4:
        VCT_ADPCM_Decode4Bit((u8 *)hdr + 4, dst, packetBytes - 4, &st);
        break;
    }
}




void VCT_ADPCM_EncodePacket(AdpcmHeader *out, void *samples, int sampleCount, AdpcmState *st, int bits)
{
    out->predictor = st->predictor;
    out->stepIndex = st->stepIndex;
    out->zero = 0;
    switch (bits) {
    case 2:
        VCT_ADPCM_Encode2Bit((u8 *)out + 4, samples, sampleCount, st);
        break;
    case 3:
        VCT_ADPCM_Encode3Bit((u8 *)out + 4, samples, sampleCount, st);
        break;
    case 4:
        VCT_ADPCM_Encode4Bit((u8 *)out + 4, samples, sampleCount, st);
        break;
    }
}



/* Packet bytes (12 byte header included) of one frame at the given codec mode. */
static inline u32 GetPacketBytes(u32 codecMode)
{
    const VctFrameSpec *spec;
    u32 blocks;
    blocks = gVctFrameSpecs[codecMode].blocks;
    spec = &gVctFrameSpecs[codecMode];
    return blocks * 0x44 + spec->extraBytes + 0xC;
}


/*
 * Initialize the transmit state: sequence start from the tick counter,
 * transmit on, no members, default codec mode, the send buffer indexes and
 * the three member slots.
 * final push 2026-10-05 G7L7: closed. Two changes from the old draft. The codecMode store is written in
 * each arm of the mode if/else (the join no longer splits the 3C84 pointer, codecMode goes through the
 * first load). The pair table read takes a = d[k].a first and then p = &d[k] for p->b, which
 * gives the later-born address temp the lower register (r1) and the table base r2, so the table
 * load stays below the f1C store.
 */
int VCT_SESSION_Init(void)
{
    u32 i;
    u32 codecMode;

    gVctSendState.sequence = OS_GetTickLo();
    gVctSendEnabled = 1;
    gVctSendState.memberCount = 0;
    gVctSendState.memberMask = 0;
    codecMode = 0;
    if (gVctSession.mode != 1) {
        codecMode = 4;
        gVctSendState.codecMode = codecMode;
    } else {
        gVctSendState.codecMode = codecMode;
    }
    gVctSendState.frameBytes = VCT_FRAME_BYTES;
    gVctSendState.packetBytes = GetPacketBytes(codecMode);
    gVctSendBuffer.readCount = 0;
    gVctSendBuffer.writeCount = 0;
    gVctSendBuffer.pendingMask = 0;
    gVctSendBuffer.sendFrame = 0;
    gVctSendBuffer.scheduleStep = 0;
    gVctSendBuffer.scheduleRow = 0;
    VCT_DSP_InitVoiceGateDefaults();
    for (i = 0; (i < VCT_MAX_MEMBERS) ? 1 : 0; i++) {
        gVctMembers[i] = 0;
        VCT_AUDIO_ClearReadyQueue(i);
        VCT_AUDIO_InitReceiveSource(&gVctReceiveSources[i], i, -1);
    }
    VCT_AUDIO_ResetPendingList();
    VCT_DSP_InitEchoState();
    return 1;
}


/* Forget all members (the member slots themselves are cleared by the engine shutdown). */
void VCT_SESSION_ClearMemberCount(void) { gVctSendState.memberCount = 0; }


/*
 * Register a peer as a chat member: needs a free slot and phase 2 or 3.
 * Returns 1 when the peer is a member afterwards. The first member joined
 * in phase 2 resets the encoder, the gate and the send buffer indexes.
 */
#pragma opt_lifetimes off
int VCT_SESSION_AddMember(VctPeer *peer)
{
    u32 slotIndex;

    if (peer == 0) {
        return 0;
    }
    if (gVctSendState.memberCount == VCT_MAX_MEMBERS) {
        return 0;
    }
    if (peer->phase != 2 && peer->phase != 3) {
        return 0;
    }
    for (slotIndex = 0; (slotIndex < VCT_MAX_MEMBERS) ? 1 : 0; slotIndex++) {
        if (gVctMembers[slotIndex] == peer) {
            return 1;
        }
    }
    for (slotIndex = 0; (slotIndex < VCT_MAX_MEMBERS) ? 1 : 0; slotIndex++) {
        if (gVctMembers[slotIndex] == 0) {
            gVctMembers[slotIndex] = peer;
            break;
        }
    }
    gVctSendState.memberCount++;
    gVctSendState.memberMask |= peer->memberMask;
    VCT_AUDIO_InitReceiveSource(&gVctReceiveSources[slotIndex], slotIndex, peer->floorHolderId);
    VCT_AUDIO_ClearReadyQueue(slotIndex);
    if (peer->phase != 2) {
        return 1;
    }
    if (gVctSendState.memberCount == 1) {
        VCT_DSP_ResetVoiceGate();
        gVctSendState.sequence = OS_GetTickLo();
        gVctSendState.adpcmPredictor = 0;
        gVctSendState.adpcmStepIndex = 0;
        gVctSendState.markerRequest = 1;
        gVctSendBuffer.readCount = 0;
        gVctSendBuffer.writeCount = 0;
        gVctSendBuffer.pendingMask = 0;
        gVctSendBuffer.sendFrame = 0;
        gVctSendBuffer.scheduleStep = 0;
        gVctSendBuffer.scheduleRow = 0;
    }
    return 1;
}
#pragma opt_lifetimes reset


/* Remove a peer from the members; the last member leaving resets the gate and the member mask. */
#pragma opt_propagation off
void VCT_SESSION_RemoveMember(VctPeer *peer)
{
    u32 slotIndex;
    int oldCount;
    VctPeer *nullPeer;
    slotIndex = 0;
    do {
        if(gVctMembers[slotIndex]==peer) {
            nullPeer = 0;
            oldCount = gVctSendState.memberCount;
            gVctMembers[slotIndex]=nullPeer;
            gVctSendState.memberCount = oldCount - 1;
            VCT_AUDIO_DetachReceiveSource(&gVctReceiveSources[slotIndex]);
            VCT_AUDIO_FlushReadyQueue(slotIndex);
            VCT_AUDIO_FlushPendingSlot(slotIndex);
            gVctSendState.memberMask &= ~peer->memberMask;
            break;
        }
        slotIndex++;
    } while(slotIndex<VCT_MAX_MEMBERS);
    if(gVctSendState.memberCount==0) {
        gVctSendState.markerRequest=1;
        VCT_DSP_ResetVoiceGate();
        gVctSendState.memberMask=0;
    }
}
#pragma opt_propagation reset


#pragma opt_propagation off

/*
 * Queue one microphone frame (length must be the frame size) into the next
 * send buffer slot and stamp its header (magic, tick divisor, sequence,
 * timestamp). Returns 1 when queued; 0 when the length is wrong, there is
 * no member, or no member is in phase 2.
 *
 * pass 3 2026-10-06 P3L09: closed. The codec mode field is read through a const pointer to the shared
 * state (`const VctSendState *sendState = &gVctSendState; if (sendState->codecMode >= 2)`). A const load has no memory
 * dependence on the header magic store, so the scheduler issues moveq before the f1C load
 * (idiom a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer). The rest is the
 * G7L4 form: opt_propagation off, `(i < 3) ? 1 : 0` while loop, magic and divisor as named locals.
 */
int VCT_SESSION_QueueFrame(const u8 *src, u32 length)
{
  VctAudioFrame *header;
  u32 i;
  u8 frameType;
  u32 slotOffset;
  u8 hasJoinedMember;
  u16 sequence;
  u32 magic;
  const VctSendState *sendState;
  hasJoinedMember = 0;
  if (length != gVctSendState.frameBytes)
  {
    return 0;
  }
  if (gVctSendState.memberCount == 0)
  {
    return 0;
  }
  i = 0;
  while ((i < VCT_MAX_MEMBERS) ? (1) : (0))
  {
    if ((0 != gVctMembers[i]) && (gVctMembers[i]->phase == 2))
    {
      hasJoinedMember = 1;
      break;
    }
    i++;
  }
  if (hasJoinedMember == 0)
  {
    return 0;
  }
  slotOffset = (gVctSendBuffer.writeCount & 1) ? 0 : VCT_PACKET_SLOT_BYTES;
  header = (VctAudioFrame *) ((u8 *) &gVctSendBuffer + slotOffset);
  magic = VCT_PACKET_MAGIC;
  header->magic = magic;
  sendState = &gVctSendState;
  if (sendState->codecMode >= 2)
  {
    func_02082B0C(src, ((u8 *) header) + 0x10, length);
  }
  else
  {
    func_02082B0C(src, ((u8 *) header) + 0xC, length);
  }
  frameType = 0x40;
  header->type = frameType;
  sequence = gVctSendState.sequence;
  gVctSendState.sequence = gVctSendState.sequence + 1;
  header->seq = sequence;
  header->timestamp = (u32) (func_020870D0() / (u32)frameType);
  gVctSendBuffer.writeCount++;
  return 1;
}

#pragma opt_propagation reset


/*
 * Take one queued packet for member channel channelIndex (0x94-byte
 * channels at 0x021B3CBC). Compares the packet's u64 due tick at +0x46C
 * against the tick count: more than 0x34 ahead falls back to the channel's
 * held packet at +0x3C, more than 0x8B4C behind is released and the loop
 * retries; otherwise it counts sequence gaps (lostPacketCount), updates
 * the delay estimate from the tick difference to the sent tick at +0x464,
 * copies the samples (+0x474) to dst and sets the sender's bit in
 * *sourceMask.
 * VCT_AUDIO_SetLastPacket is void in its own file, but this caller loops on the
 * r0 it leaves behind (mov r4, r0 after each call), so it is declared
 * int here.
 */
int VCT_SESSION_ReadChannel(void *dst, u32 size, u32 channelIndex, u32 *sourceMask)
{
    int queuedCount;
    VctRxPacket *packet;
    VctReceiveSource *channel;
    int isFirstTry;
    u64 nowTick;
    u32 delay;
    u32 delayDelta;

    channel = &gVctReceiveSources[channelIndex];
    isFirstTry = 1;
    queuedCount = VCT_AUDIO_GetReadyCount(channelIndex);
    while (queuedCount != 0) {
        nowTick = func_020870D0();
        packet = VCT_AUDIO_PeekReadyPacket(channelIndex);
        if (packet != 0) {
            if (packet->playTick > nowTick + 0x34) {
                if (packet->marker == 0 && channel->lastPacket != 0) {
                    channel->playedFrames++;
                    func_02082B0C(channel->lastPacket->payload, dst, size);
                    VCT_POOL_FreeFrame(channel->lastPacket);
                    channel->lastPacket = 0;
                    if (sourceMask != 0) {
                        *sourceMask |= 1 << packet->senderAid;
                    }
                    return 1;
                }
                return 0;
            }
            if (nowTick > packet->playTick + 0x8B4C) {
                channel->lastPlayedSeq = packet->seq;
                queuedCount = VCT_AUDIO_SetLastPacket(channel, packet);
                VCT_AUDIO_PeekReadyPacket(channelIndex);
                isFirstTry = 0;
                continue;
            }
            if (channel->lastPlayedSeq + 1 != packet->seq && channel->lastPlayedSeq != 0 && channel->lastPlayedSeq <= packet->seq) {
                if (packet->marker == 0) {
                    channel->dropped++;
                }
            }
            channel->lastPlayedSeq = packet->seq;
            if (isFirstTry != 0 && channel->pendingSkips != 0) {
                queuedCount = VCT_AUDIO_SetLastPacket(channel, packet);
                VCT_AUDIO_PeekReadyPacket(channelIndex);
                channel->pendingSkips--;
                continue;
            }
            delay = (u32)(nowTick - packet->arrivalTick);
            delayDelta = delay - channel->lastLatency;
            channel->lastLatency = delay;
            channel->latencyFilter = channel->lastLatency + ((delayDelta - channel->lastLatency) >> 4);
            channel->latency = channel->latencyFilter;
            func_02082B0C(packet->payload, dst, size);
            VCT_AUDIO_SetLastPacket(channel, packet);
            if (sourceMask != 0) {
                *sourceMask |= 1 << packet->senderAid;
            }
            return 1;
        } else {
            channel->queueDepth = queuedCount;
            return 0;
        }
    }
    if (channel->lastPacket != 0) {
        VCT_POOL_FreeFrame(channel->lastPacket);
        channel->lastPacket = 0;
    }
    return 0;
}


/*
 * Mix the voices of all members into output (length bytes): the first
 * member that delivers a packet fills output, the later ones are decoded
 * into a scratch buffer and added. With no members or a wrong length the
 * output is cleared. *sourceMask receives the senders that contributed.
 *
 * The two MIi_CpuClearFast calls (found==0 arm, failed-guard arm) are
 * kept apart in the original; under one extern name 1.1p1 cross-jumps the
 * two `bl`s into one (4 bytes short, see docs/notes/pkt_ov013_021B0B48.c.txt).
 * Two extern names for 0x02082AC0 give two independent call sites, the
 * call-site form of
 * docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.md.
 * `j = i + 1; if (j == 3) ret = 1; else for (...)` is what gives the
 * original's `cmp sb,#3; moveq r4,#1; beq; bhs`.
 */
int VCT_SESSION_MixVoices(void *output, u32 length, u32 *sourceMask)
{
    int mixed;
    u32 i;
    u32 next;

    if (sourceMask != 0)
        *sourceMask = 0;

    mixed = 0;
    if (length == gVctSendState.frameBytes && gVctSendState.memberCount != 0) {
        for (i = 0; i < VCT_MAX_MEMBERS; i++) {
            if (VCT_SESSION_ReadChannel(output, length, i, sourceMask) == 1) {
                mixed = 1;
                break;
            }
        }
        if (mixed != 0) {
            next = i + 1;
            if (next == VCT_MAX_MEMBERS) {
                mixed = 1;
            } else {
                for (; next < VCT_MAX_MEMBERS; next++) {
                    if (VCT_SESSION_ReadChannel(gVctMixScratch, length, next, sourceMask) == 1)
                        VCT_DSP_MixSaturated(output, gVctMixScratch, output, length);
                }
            }
        } else {
            MIi_CpuClearFast(0, output, length);
        }
    } else {
        mixed = 0;
        func_02082AC0(mixed, output, length);
    }

    if (gVctSendState.echoSuppressEnabled != 0)
        VCT_DSP_SetEchoReference(output, length);
    return mixed;
}


/* Select the codec mode (0 to 4; modes 0 and 1 need engine mode 1) and reset the encoder. Returns 1 on success. */
int VCT_SESSION_SetCodecMode(int codecMode)
{
    if (codecMode >= 5) {
        return 0;
    }
    if (gVctSession.mode != 1 && (unsigned)codecMode <= 1) {
        return 0;
    }
    gVctSendState.packetBytes = gVctFrameSpecs[codecMode].blocks * 0x44 + gVctFrameSpecs[codecMode].extraBytes + 0xC;
    gVctSendState.codecMode = codecMode;
    gVctSendState.adpcmPredictor = 0;
    gVctSendState.adpcmStepIndex = 0;
    return 1;
}

/* Enable or disable sending; the gate is reset and a disable asks the sender to mute. */
void VCT_SESSION_SetSendEnabled(int enabled)
{
    gVctSendEnabled = enabled;
    VCT_DSP_ResetVoiceGate();
    if (enabled == 0) gVctSendState.markerRequestNoVad = 1;
}

/* Switch the echo suppression stage of the voice chat on or off. */
void VCT_SESSION_SetFilterEnabled(int enabled)
{
    gVctSendState.echoSuppressEnabled = enabled;
}
