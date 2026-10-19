/*
 * file:     vct.c
 * unit:     yes
 * function: VCT_Init, VCT_Exit, VCT_Update, VCT_ReceiveFrame, VCT_ParseFrame
 * address:  0x021B370C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from vct_main.c, vct_audio.c, vct_session.c, vct_dsp.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_GetTick  0x020870D0  arm
 *   VCT_Update  0x021B386C  arm ov013
 *   VCT_ReceiveFrame  0x021B38B0  arm ov013
 *   VCT_Init  0x021B370C  arm ov013
 *   VCT_Exit  0x021B3844  arm ov013
 *   gVctSession     0x021B60D8  data ov013 a4
 *   OSi_ReferSymbol  0x02004EB0  arm
 *   d_02005108     0x02005108  data
 *   gVctState     0x021B60CC  data ov013
 *   VCT_MIXER_Init  0x021B0508  arm ov013
 *   VCT_SESSION_InitPeerPool  0x021B22B4  arm ov013
 *   VCT_SESSION_ResetPeerPool  0x021B23C8  arm ov013
 *   VCT_POOL_InitFrames  0x021B2ED8  arm ov013
 *   VCT_POOL_Reset  0x021B2F98  arm ov013
 *   VCT_MIXER_ClearMemberCount  0x021B0600  arm ov013
 *   VCT_SESSION_CheckAnnounceTimeout  0x021B23E0  arm ov013
 *   VCT_AUDIO_SendFrameStep  0x021B11E8  arm ov013
 *   VCT_AUDIO_DecodePendingFrames  0x021B111C  arm ov013
 *   VCT_AUDIO_ReceiveFrame  0x021B0F38  arm
 *   VCT_SESSION_HandlePacket  0x021B2488  arm
 */
#include "vct_types.h"

extern unsigned long long OS_GetTick(void);

extern void OSi_ReferSymbol(const void *symbol);

extern void MI_CpuFill8(void *dst, int c, int n);

extern int  VCT_MIXER_Init(void);

extern int VCT_SESSION_InitPeerPool(VctInitParams *params);

extern void VCT_SESSION_ResetPeerPool(void);

extern int VCT_POOL_InitFrames(VctRxPacket *buffer, u32 size);

extern void VCT_POOL_Reset(void);

extern void VCT_MIXER_ClearMemberCount(void);

extern void VCT_SESSION_CheckAnnounceTimeout(void);

extern int VCT_AUDIO_SendFrameStep(void);

extern int VCT_AUDIO_DecodePendingFrames(void);
struct VctAudioFrame;

extern int VCT_AUDIO_ReceiveFrame(u32 senderAid, struct VctAudioFrame *frame, u32 size, u64 arrivalTick);

extern int VCT_SESSION_HandlePacket(int senderId, VctPacket *packet, int length, VctEvent *event);

int VCT_Init(VctInitParams *params);

void VCT_Exit(void);

void VCT_Update(void);

int VCT_ReceiveFrame(int senderId, VctFrameHeader *frame, int length);

int VCT_ParseFrame(int senderId, VctFrameHeader *header, int length, VctEvent *eventOut);

extern char d_02005108[];

int VCT_Init(VctInitParams *params)
{
    OSi_ReferSymbol(d_02005108);
    if (params == 0)
        return 0;
    if (gVctState.initialized != 0)
        return 1;
    if (params->mode != 1 && params->mode != 2 && params->mode != 3)
        return 0;
    if (params->eventCallback == 0)
        return 0;
    if (params->frameBuffer == 0 || params->frameBufferSize == 0)
        return 0;
    if (params->frameBuffer % 32 != 0)
        return 0;
    MI_CpuFill8(&gVctSession, 0, sizeof(VctSession));
    gVctState.session.eventCallback = params->eventCallback;
    gVctState.session.callbackArg = params->callbackArg;
    gVctState.session.mode = params->mode;
    gVctState.session.sharedSession = 0;
    if (params->localId >= 0x20)
        return 0;
    gVctState.session.localId = params->localId;
    if (VCT_POOL_InitFrames((VctRxPacket *)params->frameBuffer, params->frameBufferSize) == 0) {
        VCT_POOL_Reset();
        return 0;
    }
    if (VCT_SESSION_InitPeerPool(params) == 0) {
        VCT_POOL_Reset();
        return 0;
    }
    if (VCT_MIXER_Init() != 0) {
        gVctState.initialized = 1;
        return 1;
    }
    VCT_SESSION_ResetPeerPool();
    VCT_POOL_Reset();
    return 0;
}

void VCT_Exit(void)
{
    VCT_MIXER_ClearMemberCount();
    VCT_SESSION_ResetPeerPool();
    VCT_POOL_Reset();
    gVctState.session.mode = 0;
    gVctState.initialized = 0;
}

void VCT_Update(void)
{
    if (gVctState.initialized == 0)
        return;
    gVctState.tickCount++;
    if ((gVctState.tickCount & 0xf) == 0)
        VCT_SESSION_CheckAnnounceTimeout();
    if (VCT_AUDIO_SendFrameStep())
        VCT_AUDIO_DecodePendingFrames();
}

int VCT_ReceiveFrame(int senderId, VctFrameHeader *frame, int length)
{
    VctEvent event;

    switch (VCT_ParseFrame(senderId, frame, length, &event)) {
    case 0:
        break;
    case 1:
        gVctState.session.eventCallback(senderId, event.code, event.peer, gVctState.session.callbackArg);
        return 1;
    case 2:
        return 0;
    }
    return 1;
}

#pragma opt_common_subs off

int VCT_ParseFrame(int senderId, VctFrameHeader *header, int length, VctEvent *eventOut)
{
    unsigned long long tick;

    if (header == 0)
        return 0;
    if (header->magic != 0x5F564354)
        return 2;
    if (gVctState.session.mode == 0 || gVctState.initialized == 0)
        return 0;
    eventOut->code = 0;
    eventOut->peer = 0;
    tick = OS_GetTick();
    if ((header->type & 0xf0) == 0x40) {
        gVctState.audioFrameCount++;
        VCT_AUDIO_ReceiveFrame(senderId, (VctAudioFrame *)header, length, tick);
        return 0;
    }
    if (header->type == 0 || header->type == 0xff)
        return VCT_SESSION_HandlePacket(senderId, (VctPacket *)header, length, eventOut) != 0;
    return 0;
}
