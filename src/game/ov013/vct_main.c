/*
 * file:     vct_main.c
 * unit:     yes
 * function: VCT_MAIN_InitAudio, VCT_MAIN_MicRestartDone, VCT_MAIN_StreamCallback, VCT_MAIN_RequestConnection, VCT_MAIN_AcceptPendingPeer, VCT_MAIN_OnEventGroup, VCT_MAIN_OnEventPair, VCT_MAIN_ReleasePeer, VCT_MAIN_Update, VCT_MAIN_HandlePacket, VCT_MAIN_Start, VCT_MAIN_StartStream, VCT_MAIN_HangUp, VCT_MAIN_SetExitCallback, VCT_MAIN_Exit, VCT_MAIN_GetVoiceLevel, VCT_MAIN_ConnectPeers, VCT_MAIN_DisconnectPeers, VCT_MAIN_SetMuted
 * address:  0x021AEB20
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from vct_main.c, vct_audio.c, vct_session.c, vct_dsp.c by tools/splitfile.py.
 *
 * symbols:
 *   MIC_Init  0x0208B24C  arm
 *   PM_Init  0x0208B8B0  arm
 *   PM_SetAmp  0x0208BEF0  arm
 *   PM_SetAmpGain  0x0208BF38  arm
 *   VCT_MIXER_SetSendEnabled  0x021B0CD8  arm ov013
 *   NNS_SndInit  0x020726D0  arm
 *   NNS_SndStrmInit  0x020737C0  arm
 *   VCT_MIXER_SetFilterEnabled  0x021B0D08  arm ov013
 *   gVctWork     0x021B3C80  data ov013
 *   MI_CpuFill8  0x02082BCC  arm
 *   APP_ENV_IsRunOnTwl  0x0202EB0C  thumb
 *   MIC_StartAutoSamplingAsync  0x0208B2BC  arm
 *   MIC_StartLimitedSamplingAsync  0x0208B4C8  arm
 *   MIC_GetLastSamplingAddress  0x0208B4B8  arm
 *   VCT_MIXER_MixVoices  0x021B0B48  arm ov013
 *   VCT_MIXER_QueueFrame  0x021B07F8  arm ov013
 *   VCT_SESSION_AllocPeerRecord  0x021B1F2C  arm ov013
 *   VCT_SESSION_SendGroupCommand  0x021B20B0  arm ov013
 *   VCT_SESSION_FreePeerRecord  0x021B1F54  arm ov013
 *   VCT_SESSION_SendPeerReply  0x021B2180  arm ov013
 *   VCT_MIXER_AddMember  0x021B0614  arm ov013
 *   VCT_MAIN_ReleasePeer  0x021AEDEC  thumb ov013
 *   VCT_MIXER_RemoveMember  0x021B074C  arm ov013
 *   DWC_RAP_CleanupVchat  0x02156400  thumb ov009
 *   OS_GetTick  0x020870D0  arm
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
 *   GF_PANIC_Fail  0x02034714  arm
 *   VCT_MAIN_OnEventGroup  0x021AED08  thumb ov013
 *   VCT_MAIN_OnEventPair  0x021AED30  thumb ov013
 *   VCT_Init  0x021B370C  arm ov013
 *   VCT_MIXER_SetCodecMode  0x021B0C64  arm ov013
 *   VCT_MAIN_StartStream  0x021AF124  thumb ov013
 *   NNS_SndStrmStart  0x02073A60  arm
 *   MIC_StopAutoSampling  0x0208B480  arm
 *   MIC_StopLimitedSampling  0x0208B528  arm
 *   NNSi_SndStrmStopIfSetup  0x02073AB4  arm
 *   NNS_SndStrmFreeChannel  0x02073898  arm
 *   VCT_Exit  0x021B3844  arm ov013
 *   DWC_RAPCOMMON_Free  0x02156FDC  thumb ov009
 *   VCT_DSP_GetVoiceGateConfig  0x021B3064  arm ov013
 *   VCT_SESSION_AddPeer  0x021B21A4  arm ov013
 *   VCT_SESSION_RemovePeer  0x021B2254  arm ov013
 *   MIi_CpuClearFast 0x02082AC0  arm
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "vct_types.h"

extern VctWork *gVctWork;

/* Power management and microphone driver. */
extern void MIC_Init(void);

extern void PM_Init(void);

extern unsigned int PM_SetAmp(unsigned int status);

extern unsigned int PM_SetAmpGain(unsigned int gain);

extern u32 APP_ENV_IsRunOnTwl(void);
struct MICAutoParam;

extern int MIC_StartAutoSamplingAsync(struct MICAutoParam *param, void (*callback)(void), void *arg);

extern int MIC_StartLimitedSamplingAsync(struct MICAutoParam *param, void (*callback)(void), void *arg);

extern u32 MIC_GetLastSamplingAddress(void);

extern int MIC_StopAutoSampling(void);

extern int MIC_StopLimitedSampling(void);

/* Sound system and sound stream object (arm9 unit_020737C0). */
extern void NNS_SndInit(void);
struct SndStrm;

extern void NNS_SndStrmInit(struct SndStrm *strm);

extern int NNS_SndStrmAllocChannel(struct SndStrm *strm, int numChannels, unsigned char *channelList);

extern void NNS_SndStrmSetVolume(struct SndStrm *strm, int volume);

extern int NNS_SndStrmSetup(struct SndStrm *strm, int format, unsigned int bufferAddr, unsigned int length, unsigned int rate, int frames, VctStreamCallback callback, unsigned int userData);

extern void NNS_SndStrmStart(struct SndStrm *strm);

extern void NNSi_SndStrmStopIfSetup(struct SndStrm *strm);

extern void NNS_SndStrmFreeChannel(struct SndStrm *strm);

extern void MI_CpuFill8(void *dst, int value, u32 size);

extern u64 OS_GetTick(void);

extern void GF_PANIC_Fail(const char *expr, u32 line, const char *file);

/* Wi-Fi glue (ov009). */
extern void DWC_RAP_CleanupVchat(void);

extern unsigned int DWC_RAPCOMMON_Alloc(unsigned int ownerId, unsigned int size, unsigned int align);

extern void DWC_RAPCOMMON_Free(u32 heap, void *block, int unused);

extern u8 DWC_GetMyAID(void);

/* Engine (ov013). */
extern VctPeer *VCT_SESSION_AllocPeerRecord(unsigned int peerType);

extern int VCT_SESSION_SendGroupCommand(int peer, int type);

extern int VCT_SESSION_FreePeerRecord(VctPeer *peer);

extern int VCT_SESSION_SendPeerReply(int peer, int type);

extern int VCT_SESSION_AddPeer(u8 aid);

extern int VCT_SESSION_RemovePeer(int aid);

extern void VCT_Update(void);
struct VctFrameHeader;

extern int VCT_ReceiveFrame(int senderId, struct VctFrameHeader *frame, int length);
struct VctInitParams;

extern int VCT_Init(VctInitParams *param);

extern void VCT_Exit(void);

extern void VCT_DSP_GetVoiceGateConfig(void *out);

extern void VCT_MIXER_SetSendEnabled(int enabled);

extern void VCT_MIXER_SetFilterEnabled(int enabled);

/* Two names for 0x02082AC0: see VCT_MIXER_MixVoices. */
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

int VCT_MAIN_HandlePacket(int aid, u8 *data, int size);

void VCT_MAIN_Start(void *heap, int codecMode, int peerCount);

void VCT_MAIN_StartStream(void);

void VCT_MAIN_HangUp(void);

void VCT_MAIN_SetExitCallback(void (*callback)(void));

void VCT_MAIN_Exit(void);

int VCT_MAIN_GetVoiceLevel(void);

int VCT_MAIN_ConnectPeers(u32 peerMask, int excludedAid);

int VCT_MAIN_DisconnectPeers(int excludedAid);

void VCT_MAIN_SetMuted(int muted);

int VCT_MIXER_AddMember(VctPeer *peer);

void VCT_MIXER_RemoveMember(VctPeer *peer);

int VCT_MIXER_QueueFrame(const u8 *src, u32 length);

int VCT_MIXER_MixVoices(void *output, u32 length, u32 *sourceMask);

int VCT_MIXER_SetCodecMode(int codecMode);

/* Fixed text the engine passes to the error call (raw address kept: it lives in the overlay image). */
#define VCT_ERROR_TEXT ((const char *)0x021B3C20)

/* One-time setup of the audio hardware and the stream object. */
void VCT_MAIN_InitAudio(void)
{
    MIC_Init();
    PM_Init();
    PM_SetAmp(1);
    PM_SetAmpGain(3);
    VCT_MIXER_SetSendEnabled(1);
    NNS_SndInit();
    NNS_SndStrmInit((struct SndStrm *)gVctWork->audioStream);
    MIi_CpuClearFast(0, gVctWork->playbackBuffers[1], VCT_BUFFER_BYTES);
    gVctWork->microsecondDebt = 0;
    VCT_MIXER_SetFilterEnabled(1);
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
            MIC_StartAutoSamplingAsync((struct MICAutoParam *)(&gVctWork->micParam), VCT_MAIN_MicRestartDone, 0);
            gVctWork->micRestartPending = 0;
        }
    } else {
        if (gVctWork->micRestartPending != 0) {
            MIC_StartLimitedSamplingAsync((struct MICAutoParam *)(&gVctWork->micParam), VCT_MAIN_MicRestartDone, 0);
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
        VCT_MIXER_MixVoices(buffers[i], length, 0);
    }
    if (gVctWork->sendPaused == 0) {
        VCT_MIXER_QueueFrame(micAddress, length);
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
        result = VCT_SESSION_SendGroupCommand((int)peer, 0);
    } else {
        result = VCT_SESSION_SendGroupCommand((int)peer, 0);
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
        if (VCT_SESSION_SendPeerReply((int)peer, 0) != 0) {
            return accepted;
        }
        if (VCT_MIXER_AddMember(gVctWork->pendingPeer) != 0) {
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
    case VCT_EVENT_PEER_JOINED: VCT_MIXER_AddMember(peer); break;
    case VCT_EVENT_ENGINE_STOPPED: VCT_MAIN_ReleasePeer(peer); break;
    }
}

/* Engine event handler used for the other chat modes. */
void VCT_MAIN_OnEventPair(int aid, int event, VctPeer *peer, int arg)
{
    switch (event) {
    case VCT_EVENT_REQUEST_RECEIVED:
        if (gVctWork->pendingPeer != 0) {
            VCT_SESSION_SendPeerReply((int)peer, 3);
            VCT_SESSION_FreePeerRecord(peer);
            return;
        }
        gVctWork->pendingPeer = peer;
        return;
    case VCT_EVENT_REQUEST_REFUSED:
        VCT_SESSION_SendPeerReply((int)peer, 0);
        VCT_MAIN_ReleasePeer(peer);
        return;
    case VCT_EVENT_PEER_LEFT:
        VCT_MAIN_ReleasePeer(peer);
        return;
    case VCT_EVENT_CONNECTION_CLOSED:
        VCT_SESSION_SendPeerReply((int)peer, 4);
        VCT_MAIN_ReleasePeer(peer);
        return;
    case VCT_EVENT_PEER_JOINED:
        if (peer->mode != gVctWork->mode) {
            VCT_MAIN_ReleasePeer(peer);
            return;
        }
        if (VCT_MIXER_AddMember(peer) != 0) {
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
    VCT_MIXER_RemoveMember(peer);
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
    tick = OS_GetTick();
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
int VCT_MAIN_HandlePacket(int aid, u8 *data, int size)
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
        gVctWork = (struct VctWork *)DWC_RAPCOMMON_Alloc((unsigned int)heap, sizeof(VctWork), 0x20);
        MI_CpuFill8(gVctWork, 0, sizeof(VctWork));
        gVctWork->frameMemory = (void *)DWC_RAPCOMMON_Alloc((unsigned int)heap, peerCount * VCT_PEER_QUEUE_BYTES + 0x20, 0x20);
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
    NNS_SndStrmAllocChannel((struct SndStrm *)gVctWork->audioStream, 1, channelNumbers);
    NNS_SndStrmSetVolume((struct SndStrm *)gVctWork->audioStream, 0);
    if (NNS_SndStrmSetup((struct SndStrm *)gVctWork->audioStream, 1, (unsigned int)gVctWork->playbackBuffers, (unsigned int)VCT_BUFFER_BYTES,
                      (unsigned int)(APP_ENV_IsRunOnTwl() ? 0x40 : 0x41), 2, VCT_MAIN_StreamCallback,
                      (unsigned int)gVctWork) == 0) {
        GF_PANIC_Fail(VCT_ERROR_TEXT, 0, VCT_ERROR_TEXT);
    }
    gVctWork->linkState = 0;
    gVctWork->pendingPeer = 0;
    gVctWork->mode = param.mode = 1;
    param.peerBuffer = &gVctWork->enginePeer;
    param.peerCount = peerCount;
    param.localId = DWC_GetMyAID();
    if (param.localId == -1) {
        GF_PANIC_Fail(VCT_ERROR_TEXT, 0, VCT_ERROR_TEXT);
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
    VCT_MIXER_SetCodecMode(codecMode);
    VCT_MAIN_StartStream();
    VCT_MIXER_SetFilterEnabled(1);
}

/* Start the playback stream. */
void VCT_MAIN_StartStream(void) { NNS_SndStrmStart((struct SndStrm *)gVctWork->audioStream); }

/* Hang up: ask the engine to end the pending request, then stop the chat. */
void VCT_MAIN_HangUp(void)
{
    if (gVctWork->pendingPeer == 0 || gVctWork->linkState == 0) {
        DWC_RAP_CleanupVchat();
        return;
    }
    if (gVctWork->linkState == 1) {
        if (VCT_SESSION_SendGroupCommand((int)gVctWork->pendingPeer, 2)) {
            DWC_RAP_CleanupVchat();
            return;
        }
    }
    if (VCT_SESSION_SendGroupCommand((int)gVctWork->pendingPeer, 1)) {
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
    NNSi_SndStrmStopIfSetup((struct SndStrm *)gVctWork->audioStream);
    NNS_SndStrmFreeChannel((struct SndStrm *)gVctWork->audioStream);
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
        VCT_DSP_GetVoiceGateConfig(gateStats);
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
            if (muted != 0) VCT_MIXER_RemoveMember(gVctWork->pendingPeer);
            else VCT_MIXER_AddMember(gVctWork->pendingPeer);
        }
    }
}
