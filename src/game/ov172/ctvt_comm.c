/*
 * file:     ctvt_comm.c
 * unit:     yes
 * function: CTVT_COMM_Create, CTVT_COMM_Delete, CTVT_COMM_Main, CTVT_COMM_StartSession, CTVT_COMM_StopSession, CTVT_COMM_IsSessionEnded, CTVT_COMM_SetRequestedMode, CTVT_COMM_GetNetMode, CTVT_COMM_SetConnectMac, CTVT_COMM_IsNetReady, CTVT_COMM_GetMyStatus, CTVT_COMM_GetStatusBlockSize, CTVT_COMM_IsModeSupported, CTVT_COMM_MatchPeerName, CTVT_COMM_Update, CTVT_COMM_SetScanWait, CTVT_COMM_UpdateMembers, CTVT_COMM_FindPeerName, CTVT_COMM_ClearPeerSlot, CTVT_COMM_UpdatePeerSlot, CTVT_COMM_SendSlotHit, CTVT_COMM_SendCommand, CTVT_COMM_HandleMessage, CTVT_COMM_SendVoiceData, CTVT_COMM_ResetVoiceRecord, CTVT_COMM_ReceiveVoicePacket, CTVT_COMM_SendStrokeQueue, CTVT_COMM_PushStrokes, CTVT_COMM_SendPeerStatus, CTVT_COMM_ClaimSlot, CTVT_COMM_GetSlotName, CTVT_COMM_SetTimingSync, CTVT_COMM_IsTimingSync, CTVT_COMM_GetHandleNetId, CTVT_COMM_GetMarkerSlot, CTVT_COMM_IsPostBusy, CTVT_COMM_GetMyStatusPtr, CTVT_COMM_GetVoiceRecord, CTVT_COMM_GetSlotConnected, CTVT_COMM_GetSlotParam, CTVT_COMM_GetPeerStatus, CTVT_COMM_IsSlotActive, CTVT_COMM_GetSlotReady, CTVT_COMM_PopStroke, CTVT_COMM_AdvanceWriteCursor, CTVT_COMM_ResetSlotTimer, CTVT_COMM_IsSlotTimerDone, CTVT_COMM_GetVoiceStatePending
 * address:  0x021B7BA8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from draw_system.c, ctvt_comm.c, ctvt_draw.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   GFL_NET_FreeAligned  0x0203D7FC  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   COMM_TVT_SYS_IsNetIdle 0x021BE100 thumb ov172
 *   COMM_TVT_SYS_GetHalfRes 0x021BE078 thumb ov172
 *   CTVT_COMM_GetSlotConnected 0x021B8B8C thumb ov172
 *   CTVT_COMM_GetSlotReady 0x021B8BAC thumb ov172
 *   MIi_CpuClear32 0x02082A7C arm
 *   COMM_TVT_SYS_GetCamView 0x021BDFDC thumb ov172
 *   COMM_TVT_SYS_GetMessageActive 0x021BE0AC thumb ov172
 *   MIi_CpuCopy32 0x02082A90 arm
 *   COMM_TVT_SYS_GetCameraBusy 0x021BE0F8 thumb ov172
 *   COMM_TVT_SYS_SetCameraBusy 0x021BE0FC thumb ov172
 *   CTVT_COMM_IsSlotActive 0x021B8BA4 thumb ov172
 *   COMM_TVT_SYS_IsLaunchModeCall 0x021BE0D8 thumb ov172
 *   SSP_GetJpegEncoderBufferSize 0x021C1A80 arm ov172
 *   COMM_TVT_SYS_GetLaunchParams 0x021BE004 thumb ov172
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   MYSTATUS_Copy 0x02008494 thumb
 *   GFL_NET_LOWER_DATA_Init 0x0203E5F8 arm
 *   gCtvtCommAllocSite 0x021C71F4 data a4
 *   GFL_NET_LOWER_DATA_Exit 0x0203E6C0 arm
 *   COMM_TVT_SYS_GetHeapId 0x021BE00C thumb ov172
 *   GFL_NET_SetWaitMode 0x0203D644 arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_BeaconScanStart 0x0203D010 arm
 *   GFL_NET_StartByNetType 0x0203D01C arm
 *   WIH_SetJudgeAcceptFunc 0x02179328 thumb ov014
 *   GFL_NET_ConnectMacAddressParent 0x0203CFF0 arm
 *   GFL_NET_HANDLE_CheckNegotiation 0x02039ACC arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsNegotiationDone 0x020399B8 arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   gCtvtCommCommandTable 0x021C6ED4 data a4
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   GFL_NET_StartSession  0x0203CBAC  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   GFL_NET_LOWER_DATA_IsSendFinished 0x0203EA54 arm
 *   GFL_NET_LOWER_DATA_SetSendData 0x0203E758 arm
 *   SSP_StartJpegEncoder 0x021C2B74 arm ov172
 *   CTVT_CAMVIEW_StartLayoutChange 0x021B7740 thumb ov172
 *   COMM_TVT_SYS_ClearNameWindows 0x021BE1A4 thumb ov172
 *   CTVT_CAMVIEW_GetWindowHeight 0x021B77B8 thumb ov172
 *   WIH_SetScanWaitFrames 0x02179650 thumb ov014
 *   GFL_NET_IsConnectMember 0x0203D1C0 arm
 *   GFL_NET_LOWER_DATA_CreatePostWork 0x0203E808 arm
 *   GFL_NET_LOWER_DATA_DeletePostWork 0x0203E8C8 arm
 *   COMM_TVT_SYS_SetMemberCount 0x021BE058 thumb ov172
 *   COMM_TVT_SYS_SetSelfSlot 0x021BE0A8 thumb ov172
 *   COMM_TVT_SYS_SavePeerRecord 0x021BE2F0 thumb ov172
 *   GFL_NET_LOWER_DATA_IsPostComplete 0x0203EA70 arm
 *   CTVT_CAMVIEW_ClearWindowDirty 0x021B7724 thumb ov172
 *   GFL_NET_LOWER_DATA_GetPostBuffer 0x0203E96C arm
 *   GFL_NET_LOWER_DATA_GetPostRecvSize 0x0203E9DC arm
 *   SSP_StartJpegDecoder 0x021BFFC4 arm ov172
 *   CTVT_CAMVIEW_MarkWindowDirty 0x021B7714 thumb ov172
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   COMM_TVT_SYS_PlaceSlotMarker 0x021BE210 thumb ov172
 *   COMM_TVT_SYS_GetTalkStatus 0x021BDFEC thumb ov172
 *   COMM_TVT_SYS_HideSlotMarker 0x021BE2E0 thumb ov172
 *   CTVT_MIC_StopVoice 0x021BA234 thumb ov172
 *   COMM_TVT_SYS_GetSprites 0x021BDFFC thumb ov172
 *   DRAW_SYSTEM_SetQueueIndex 0x021B6EA8 thumb ov172
 *   COMM_TVT_SYS_SetInputLocked 0x021BE0CC thumb ov172
 *   COMM_TVT_SYS_SetHalfRes 0x021BE0A0 thumb ov172
 *   CTVT_MIC_PlayVoice 0x021BA1E8 thumb ov172
 *   COMM_TVT_SYS_SetEndRequested 0x021BE0D4 thumb ov172
 *   CTVT_ADPCM_ResetDecoder 0x021B69F0 thumb ov172
 *   CTVT_MIC_DecodeAdpcm 0x021BA194 thumb ov172
 *   gCtvtCommFreqTable 0x021C6EC0 data a2
 *   DRAW_SYSTEM_PushStroke 0x021B6E88 thumb ov172
 *   CTVT_COMM_StopSession  0x021B8084  thumb  ov172
 *   CTVT_COMM_SendCommand  0x021B8740  thumb  ov172
 *   CTVT_COMM_SetTimingSync  0x021B8B34  thumb  ov172
 *   CTVT_COMM_IsTimingSync  0x021B8B48  thumb  ov172
 *   CTVT_COMM_PopStroke  0x021B8BB8  thumb  ov172
 *   CTVT_COMM_AdvanceWriteCursor  0x021B8BFC  thumb  ov172
 *   CTVT_COMM_GetNetMode  0x021B80E4  thumb  ov172
 *   CTVT_COMM_SetRequestedMode  0x021B80DC  thumb  ov172
 *   CTVT_COMM_SetConnectMac  0x021B80EC  thumb  ov172
 *   CTVT_COMM_GetMyStatusPtr  0x021B8B7C  thumb  ov172
 *   CTVT_COMM_ResetSlotTimer  0x021B8C14  thumb  ov172
 *   CTVT_COMM_IsSlotTimerDone  0x021B8C20  thumb  ov172
 *   CTVT_COMM_IsNetReady  0x021B8108  thumb  ov172
 *   CTVT_COMM_FindPeerName  0x021B85D0  thumb  ov172
 *   CTVT_COMM_Create 0x021B7BA8 thumb ov172
 *   CTVT_COMM_Delete 0x021B7DCC thumb ov172
 *   CTVT_COMM_Main  0x021B7E34  thumb  ov172
 *   CTVT_COMM_IsSessionEnded  0x021B80CC  thumb
 *   CTVT_COMM_GetSlotParam 0x021B8B94 thumb ov172
 *   CTVT_COMM_GetMarkerSlot 0x021B8B68 thumb ov172
 *   CTVT_COMM_SendSlotHit 0x021B8720 thumb ov172
 *   CTVT_CAMVIEW_GetWindowWidth 0x021B77E8 thumb ov172
 *   CTVT_CAMVIEW_GetOwnSlotBuffer 0x021B7818 thumb ov172
 *   CTVT_CAMVIEW_GetSlotBuffer 0x021B7830 thumb ov172
 *   CTVT_CAMVIEW_GetSlotBufferStep 0x021B785C thumb ov172
 *   CTVT_CAMVIEW_RequestWindowAnimation 0x021B7B20 thumb ov172
 */
#include "ctvt_types.h"

extern u32 GFL_HEAP_Free(void *p);



struct GflNetHandle;

struct GflNetLink;

struct GflNetSessionReq;

/* 0x70 byte session request template read from the GFL_NET rodata block. */
typedef struct {
    u32 w[0x1c];
} NetSessionTemplate;

/* 0x21 byte peer status block copied into the first peer slot. */
typedef struct { u8 x[0x21]; } PeerStatusBlock;

/* Frequency table indexed by the voice level of a received packet. */
typedef struct { u16 value[9]; } CtvtFreqTable;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);


extern void *GFL_NET_AllocAligned(u32 heap, u32 size, const char *file, u16 line);

extern unsigned long SSP_GetJpegEncoderBufferSize(unsigned long width, unsigned long height, unsigned long sampling, unsigned long option);


extern u8 *GAME_DATA_GetMyStatus(void *p);

extern void MYSTATUS_Copy(void *src, void *dst);

extern void GFL_NET_LOWER_DATA_Init(int heapId, int ackMode);

extern void GFL_NET_LOWER_DATA_Exit(void);

extern void GFL_NET_FreeAligned(void *);


extern void GFL_NET_SetWaitMode(int a);

extern int GFL_NET_GetRunState(void);

extern void GFL_NET_BeaconScanStart(void);

extern void GFL_NET_StartByNetType(void);

extern void WIH_SetJudgeAcceptFunc(void *v);

extern void GFL_NET_ConnectMacAddressParent(void *p);

extern int GFL_NET_HANDLE_CheckNegotiation(void);

extern struct GflNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);

extern u32 GFL_NET_HANDLE_IsNegotiationDone(u8 *p);

extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);

extern void GFL_NET_HANDLE_SetTimingSyncRange(struct GflNetLink *p, u32 a, u32 b);

extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct GflNetLink *p, u32 a, u32 b);

extern int GFL_NET_Exit(int a0);

extern int GFL_NET_IsSessionNull(void);

extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);

extern u32 GFL_NET_ERR_GetErrorLevel(void);

extern void GFL_NET_StartSession(struct GflNetSessionReq *req, u32 transportArg, u32 userArg);

extern void GFL_NET_SetLoginOption(u8 loginOption);

extern u32 GFL_NET_GetHandleNetID(struct GflNetLink *p);

extern int GFL_NET_GetNegotiationNum(void);

extern int GFL_NET_LOWER_DATA_IsSendFinished(void);

extern void GFL_NET_LOWER_DATA_SetSendData(int, int, int, int);

extern void MIi_CpuCopy32(const void *, void *, u32);

extern unsigned long SSP_StartJpegEncoder(void *src, unsigned char *dst, int limit, unsigned char *wrk, unsigned long width, unsigned long height, unsigned long quality, unsigned long sampling, unsigned long option);


extern void CTVT_CAMVIEW_StartLayoutChange(void *, char *, int, int);





extern u32 CTVT_CAMVIEW_GetWindowHeight(void *, u32);

extern void WIH_SetScanWaitFrames(u16 v);

extern u32 GFL_NET_IsConnectMember(u32 index);

extern void GFL_NET_LOWER_DATA_CreatePostWork(u32 a, int b, u32 c, u32 d);

extern void GFL_NET_LOWER_DATA_DeletePostWork(int a);



extern void COMM_TVT_SYS_SavePeerRecord(u32 *p, void *q);

extern int GFL_NET_LOWER_DATA_IsPostComplete(unsigned int idx);

extern void CTVT_CAMVIEW_ClearWindowDirty(void *a, char *b, int c);

extern int GFL_NET_LOWER_DATA_GetPostBuffer(unsigned int idx);

extern int GFL_NET_LOWER_DATA_GetPostRecvSize(unsigned int idx);

extern int SSP_StartJpegDecoder(unsigned char *data, unsigned long size, void *dst,
                         short *width, short *height, unsigned long option);

extern void CTVT_CAMVIEW_MarkWindowDirty(void *a, char *b, int c);

extern u32 GFL_NET_SendData(u32, u32, u32, u32, u32, u32, u32, u32);




extern void CTVT_MIC_StopVoice(void *p);


extern void DRAW_SYSTEM_SetQueueIndex(void *p, u16 v);



extern int CTVT_MIC_PlayVoice(int *self, char *buf, unsigned n, int vol, int freq);


extern void MIi_CpuClear32();

extern void CTVT_ADPCM_ResetDecoder(void);

extern int CTVT_MIC_DecodeAdpcm(int unused, int a, void *buf, unsigned n);

extern void DRAW_SYSTEM_PushStroke(char *p, void *q);




u32 CTVT_CAMVIEW_GetWindowWidth(void *p, u32 unused);

u32 CTVT_CAMVIEW_GetOwnSlotBuffer(void *p, void *q);

int CTVT_CAMVIEW_GetSlotBuffer(void *work, char *view, int slot);

u32 CTVT_CAMVIEW_GetSlotBufferStep(void *p, u32 unused);

void CTVT_CAMVIEW_RequestWindowAnimation(int unused, char *base, int i);

char *CTVT_COMM_Create(void *work, u16 heapId);

void CTVT_COMM_Delete(void *work, char *comm);

void CTVT_COMM_Main(void *work, char *comm);

void CTVT_COMM_StartSession(void *work, void *comm);

void CTVT_COMM_StopSession(void *work, char *comm);

u32 CTVT_COMM_IsSessionEnded(int unused, char *comm);

void CTVT_COMM_SetRequestedMode(int unused, char *comm, u32 mode);

u32 CTVT_COMM_GetNetMode(int unused, char *comm);

void CTVT_COMM_SetConnectMac(int unused, char *comm, const u8 *mac);

int CTVT_COMM_IsNetReady(void *unused, void *comm);

u8 *CTVT_COMM_GetMyStatus(u8 *comm);

int CTVT_COMM_GetStatusBlockSize(void);

int CTVT_COMM_IsModeSupported(int mode, int kind);

int CTVT_COMM_MatchPeerName(void *probe, u8 *comm);

void CTVT_COMM_Update(void *work, char *comm);

void CTVT_COMM_SetScanWait(void *work, char *comm);

void CTVT_COMM_UpdateMembers(void *work, char *comm);

int CTVT_COMM_FindPeerName(unsigned char *comm, unsigned char *probe);

void CTVT_COMM_ClearPeerSlot(int unused, int unused2, void *slot);

void CTVT_COMM_UpdatePeerSlot(void *work, int comm, int *slot, int slotIdx);

void CTVT_COMM_SendSlotHit(void *work, u32 *comm, u32 value);

u32 CTVT_COMM_SendCommand(int work, int comm, u8 command, u32 value);

void CTVT_COMM_HandleMessage(int id, int size, u32 *msg, char *comm);

int CTVT_COMM_SendVoiceData(void *work, char *comm, u16 *packet);

int CTVT_COMM_ResetVoiceRecord(void *work, char *comm);

void CTVT_COMM_ReceiveVoicePacket(int unused1, int unused2, int unused3, char *comm);

u32 CTVT_COMM_SendStrokeQueue(int unused, char *comm);

void CTVT_COMM_PushStrokes(int work, u32 size, char *strokes, char *comm);

int CTVT_COMM_SendPeerStatus(int unused, char *comm);

void CTVT_COMM_ClaimSlot(int slot, void *unused1, void *unused2, char *comm);

char *CTVT_COMM_GetSlotName(int slot, char *comm);

void CTVT_COMM_SetTimingSync(void *work, u32 unused, u32 command);

int CTVT_COMM_IsTimingSync(void *work, u32 unused, u32 command);

u32 CTVT_COMM_GetHandleNetId(void *unused, u32 unused2);

u32 CTVT_COMM_GetMarkerSlot(int unused, char *comm);

int CTVT_COMM_IsPostBusy(void *unused, u8 *comm);

u8 *CTVT_COMM_GetMyStatusPtr(void *unused, u8 *comm);

u32 CTVT_COMM_GetVoiceRecord(int unused, char *comm);

u32 CTVT_COMM_GetSlotConnected(int unused, char *comm, int slot);

char *CTVT_COMM_GetSlotParam(int unused, char *comm, int slot);

char *CTVT_COMM_GetPeerStatus(int unused, char *comm);

u32 CTVT_COMM_IsSlotActive(int unused, char *comm, int slot);

u8 CTVT_COMM_GetSlotReady(void *unused, char *comm, int slot);

int CTVT_COMM_PopStroke(int unused, unsigned char *comm, int *full);

void CTVT_COMM_AdvanceWriteCursor(int unused, u8 *comm);

void CTVT_COMM_ResetSlotTimer(void *unused, u8 *comm);

u32 CTVT_COMM_IsSlotTimerDone(void *unused, u8 *comm);

u32 CTVT_COMM_GetVoiceStatePending(void *unused, u8 *comm);

extern const char gCtvtCommAllocSite[];

extern u8 gCtvtCommCommandTable[];

extern const CtvtFreqTable gCtvtCommFreqTable;

char *CTVT_COMM_Create(void *work, u16 heapId)
{
    char *comm;
    u8 slot;
    u8 digit;
    comm = GFL_HEAP_Alloc(heapId, 0x3e0, 1, gCtvtCommAllocSite, 0xf4);
    ((CtvtComm *)comm)->work = work;
    ((CtvtComm *)comm)->netState = 0;
    ((CtvtComm *)comm)->memberCount = 1;
    ((CtvtComm *)comm)->voiceMask = 0;
    ((CtvtComm *)comm)->netMode = 0;
    ((CtvtComm *)comm)->requestedMode = 0;
    ((CtvtComm *)comm)->slotTimer = 0;
    for (slot = 0; slot < 4; slot++)
        CTVT_COMM_ClearPeerSlot((int)work, (int)comm, &((CtvtComm *)comm)->peers[slot]);
    for (slot = 0; slot < 3; slot++) {
        if (COMM_TVT_SYS_IsLaunchModeCall(work) == 0 || slot == 0)
            ((CtvtComm *)comm)->postWork[slot] = GFL_NET_AllocAligned(heapId, 3 << 14, gCtvtCommAllocSite, 0x107);
    }
    ((CtvtComm *)comm)->jpegWork = GFL_NET_AllocAligned(heapId, SSP_GetJpegEncoderBufferSize(0x80, 0xc0, 1, 4), gCtvtCommAllocSite, 0x10c);
    ((CtvtComm *)comm)->frameBuf = GFL_NET_AllocAligned(heapId, 0xc000, gCtvtCommAllocSite, 0x10e);
    ((CtvtComm *)comm)->jpegOut = GFL_NET_AllocAligned(heapId, 0xc000, gCtvtCommAllocSite, 0x10f);
    ((CtvtComm *)comm)->postWorkMask = 0;
    ((CtvtComm *)comm)->sendMask = 0;
    ((CtvtComm *)comm)->sendBusy = 0;
    ((CtvtComm *)comm)->postBusy = 0;
    ((CtvtComm *)comm)->playPending = 0;
    ((CtvtComm *)comm)->voiceRec = GFL_HEAP_Alloc(heapId, 0x208, 1, gCtvtCommAllocSite, 0x116);
    ((CtvtComm *)comm)->decodeBuf = GFL_HEAP_Alloc(heapId, 0xc800, 1, gCtvtCommAllocSite, 0x117);
    ((CtvtComm *)comm)->writeCursor = 0;
    ((CtvtComm *)comm)->readCursor = 0;
    ((CtvtComm *)comm)->markerSlot = 0xff;
    ((CtvtComm *)comm)->markerDirty = 0;
    ((CtvtComm *)comm)->statusDirty = 0;
    ((CtvtComm *)comm)->memberDirty = 0;
    ((CtvtComm *)comm)->halfResSync = 0;
    ((CtvtComm *)comm)->slotMarkerDirty = 0;
    ((CtvtComm *)comm)->strokeSendPending = 1;
    ((CtvtComm *)comm)->cmd4Pending = 0;
    ((CtvtComm *)comm)->voiceStatePending = 1;
    ((CtvtComm *)comm)->cmd5Pending = 0;
    ((CtvtComm *)comm)->currentSlot = 0xff;
    MYSTATUS_Copy(GAME_DATA_GetMyStatus((void *)(*((u32 *)COMM_TVT_SYS_GetLaunchParams(work)))), ((CtvtComm *)comm)->myStatus);
    ((CtvtComm *)comm)->prevMemberCount = 1;
    for (slot = 0; slot < 3; slot++)
        for (digit = 0; digit < 6; digit++)
            ((CtvtComm *)comm)->peerName[slot * 6 + digit] = 0xff;
    ((CtvtComm *)comm)->flags.netIdle = COMM_TVT_SYS_IsNetIdle();
    ((CtvtComm *)comm)->flags.nameMatchActive = 0;
    MYSTATUS_Copy(GAME_DATA_GetMyStatus((void *)(*((u32 *)COMM_TVT_SYS_GetLaunchParams(work)))), ((CtvtComm *)comm)->peerStatus);
    ((CtvtComm *)comm)->netIdle = COMM_TVT_SYS_IsNetIdle();
    ((CtvtComm *)comm)->state = 1;
    GFL_NET_LOWER_DATA_Init(heapId, 0);
    return comm;
}

void CTVT_COMM_Delete(void *work, char *comm)
{
    u8 slot;
    GFL_NET_LOWER_DATA_Exit();
    GFL_HEAP_Free(((CtvtComm *)comm)->decodeBuf);
    GFL_HEAP_Free(((CtvtComm *)comm)->voiceRec);
    GFL_NET_FreeAligned(((CtvtComm *)comm)->frameBuf);
    GFL_NET_FreeAligned(((CtvtComm *)comm)->jpegOut);
    GFL_NET_FreeAligned(((CtvtComm *)comm)->jpegWork);
    for (slot = 0; slot < 3; slot++) {
        if (COMM_TVT_SYS_IsLaunchModeCall(work) == 0 || slot == 0)
            GFL_NET_FreeAligned(((CtvtComm *)comm)->postWork[slot]);
    }
    GFL_HEAP_Free(comm);
}

void CTVT_COMM_Main(void *work, char *comm)
{
    u32 handle;
    u8 slot;
    u8 digit;
    COMM_TVT_SYS_GetHeapId(work);
    switch (((CtvtComm *)comm)->netState) {
    case 0:
        if (((CtvtComm *)comm)->requestedMode == 0)
            break;
        if (((CtvtComm *)comm)->requestedMode == 5) {
            GFL_NET_SetWaitMode(0);
            ((CtvtComm *)comm)->netState = 5;
            ((CtvtComm *)comm)->netMode = ((CtvtComm *)comm)->requestedMode;
        } else {
            ((CtvtComm *)comm)->netState = 1;
        }
        break;
    case 1:
        CTVT_COMM_StartSession(work, comm);
        ((CtvtComm *)comm)->netState = 2;
        break;
    case 2:
        if (GFL_NET_GetRunState() != 1)
            break;
        switch (((CtvtComm *)comm)->requestedMode) {
        case 2:
            GFL_NET_BeaconScanStart();
            ((CtvtComm *)comm)->netState = 7;
            break;
        case 3:
            GFL_NET_StartByNetType();
            WIH_SetJudgeAcceptFunc(CTVT_COMM_MatchPeerName);
            ((CtvtComm *)comm)->netState = 3;
            break;
        case 4:
            if (((CtvtComm *)comm)->netMode == 2)
                CTVT_COMM_ClearPeerSlot((int)work, (int)comm, &((CtvtComm *)comm)->peers[0]);
            GFL_NET_ConnectMacAddressParent(((CtvtComm *)comm)->connectMac);
            ((CtvtComm *)comm)->netState = 3;
            break;
        }
        ((CtvtComm *)comm)->netMode = ((CtvtComm *)comm)->requestedMode;
        break;
    case 3:
        if (GFL_NET_HANDLE_CheckNegotiation() == 1)
            ((CtvtComm *)comm)->netState = 4;
        if (((CtvtComm *)comm)->netMode != ((CtvtComm *)comm)->requestedMode)
            ((CtvtComm *)comm)->netState = 8;
        break;
    case 4:
        if (GFL_NET_HANDLE_IsNegotiationDone((u8 *)GFL_NET_HANDLE_GetCurrentHandle()) == 1)
            ((CtvtComm *)comm)->netState = 7;
        if (((CtvtComm *)comm)->netMode != ((CtvtComm *)comm)->requestedMode)
            ((CtvtComm *)comm)->netState = 8;
        break;
    case 5:
        handle = (u32)GFL_NET_HANDLE_GetCurrentHandle();
        GFL_NET_COMMAND_AddCommandTable(0x2000, (u32)gCtvtCommCommandTable, 4, (u32)comm);
        GFL_NET_HANDLE_SetTimingSyncRange((struct GflNetLink *)handle, 8, 0x20);
        ((CtvtComm *)comm)->netState = 6;
        break;
    case 6:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct GflNetLink *)GFL_NET_HANDLE_GetCurrentHandle(), 8, 0x20) == 1)
            ((CtvtComm *)comm)->netState = 7;
        break;
    case 7:
        CTVT_COMM_Update(work, comm);
        if (((CtvtComm *)comm)->netMode != ((CtvtComm *)comm)->requestedMode)
            ((CtvtComm *)comm)->netState = 8;
        if (((CtvtComm *)comm)->netMode == 2)
            CTVT_COMM_SetScanWait(work, comm);
        break;
    case 8:
        GFL_NET_Exit(0);
        ((CtvtComm *)comm)->netState = 11;
        break;
    case 11:
        if (GFL_NET_IsSessionNull() != 1)
            break;
        if (((CtvtComm *)comm)->requestedMode == 1)
            ((CtvtComm *)comm)->netState = 12;
        else
            ((CtvtComm *)comm)->netState = 1;
        break;
    case 9:
        GFL_NET_HANDLE_SetTimingSyncRange((struct GflNetLink *)GFL_NET_HANDLE_GetCurrentHandle(), 9, 0x20);
        ((CtvtComm *)comm)->netState = 10;
        break;
    case 10:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct GflNetLink *)GFL_NET_HANDLE_GetCurrentHandle(), 9, 0x20) == 1) {
            GFL_NET_COMMAND_DeleteCommandTable(0x2000);
            ((CtvtComm *)comm)->netState = 12;
        }
        if (GFL_NET_ERR_GetErrorLevel() != 0) {
            GFL_NET_COMMAND_DeleteCommandTable(0x2000);
            ((CtvtComm *)comm)->netState = 12;
        }
        break;
    }
    if (((CtvtComm *)comm)->slotTimer != 0) {
        (((CtvtComm *)comm)->slotTimer)--;
        if (((CtvtComm *)comm)->slotTimer == 0) {
            for (slot = 0; slot < 3; slot++)
                for (digit = 0; digit < 6; digit++)
                    ((CtvtComm *)comm)->peerName[slot * 6 + digit] = 0xff;
            ((CtvtComm *)comm)->flags.nameMatchActive = 0;
        }
    }
}

void CTVT_COMM_StartSession(void *work, void *comm)
{
    NetSessionTemplate s = *(NetSessionTemplate *)0x021C6EF4;

    COMM_TVT_SYS_GetHeapId(work);
    GFL_NET_StartSession((struct GflNetSessionReq *)(&s), 0, (u32)comm);
    GFL_NET_SetLoginOption(0);
}

/*
 * Chooses the +8 state from the +0x174 code and latches +0x178.
 *
 * Addresses are Black-image addresses.
 */
void CTVT_COMM_StopSession(void *work, char *comm)
{
    if (((CtvtComm *)comm)->memberCount <= 1) {
        if (((CtvtComm *)comm)->netMode == 5) {
            ((CtvtComm *)comm)->netState = 0xc;
            GFL_NET_COMMAND_DeleteCommandTable(0x2000);
        } else {
            GFL_NET_Exit(0);
            ((CtvtComm *)comm)->netState = 0xb;
        }
    } else {
        if (((CtvtComm *)comm)->netMode == 5) {
            ((CtvtComm *)comm)->netState = 9;
        } else {
            ((CtvtComm *)comm)->netState = 8;
        }
    }
    ((CtvtComm *)comm)->requestedMode = 1;
}

u32 CTVT_COMM_IsSessionEnded(int unused, char *comm)
{
    if (((CtvtComm *)comm)->netState == 12)
        return 1;
    return 0;
}

void CTVT_COMM_SetRequestedMode(int unused, char *comm, u32 mode)
{
    ((CtvtComm *)comm)->requestedMode = mode;
}

u32 CTVT_COMM_GetNetMode(int unused, char *comm)
{
    return ((CtvtComm *)comm)->netMode;
}

void CTVT_COMM_SetConnectMac(int unused, char *comm, const u8 *mac)
{
    u8 idx;
    for (idx = 0; idx < 6; idx++)
        ((CtvtComm *)comm)->connectMac[idx] = mac[idx];
}

/*
 * Test the u32 at +0x08 against 7.
 *
 * Addresses are Black-image addresses.
 */
int CTVT_COMM_IsNetReady(void *unused, void *comm)
{
    if (((CtvtComm *)comm)->netState == 7) {
        return 1;
    }
    return 0;
}

u8 *CTVT_COMM_GetMyStatus(u8 *comm)
{
    return ((CtvtComm *)comm)->myStatus;
}

int CTVT_COMM_GetStatusBlockSize(void)
{
    return 52;
}

int CTVT_COMM_IsModeSupported(int mode, int kind)
{
    if (kind == 0x20 || kind == 3) {
        return 1;
    }
    return 0;
}

/*
 * When bit 1 of a1[0x2d] is set, hands the two sub-objects (a1+0xc and
 * a0+0xa) to CTVT_COMM_FindPeerName; otherwise there is nothing to do and it returns 1.
 * The test is the shift pair (v << 30) >> 31, not an AND against 2, and the
 * shifted value has to be unsigned or the image's `lsrs` comes out `asrs`.
 *
 * Addresses are Black-image addresses.
 */
int CTVT_COMM_MatchPeerName(void *probe, u8 *comm)
{
    if ((((u32)*(u8 *)&((CtvtComm *)comm)->flags << 30) >> 31) == 0)
        return 1;
    return CTVT_COMM_FindPeerName(((CtvtComm *)comm)->myStatus, (u8 *)probe + 0xa);
}

/*
 * note 2026-10-05 wD4 lane05: EXACT*. Three source fixes: the 0x21-byte copy b+0x40 -> b+0x80 is a struct copy
 *   (one-member u8[0x21] struct); the slot stores go in offset order (0x74 = 0, 0x78 = 0xff, 0x7c = 0);
 *   in the j loop `hit = 1` comes before the slot store.
 */
void CTVT_COMM_Update(void *work, char *comm)
{
    int busy;
    u8 slot;
    u8 count;
    u8 slot2;
    u32 camView;
    u32 srcBuf, bufStep, winHeight, winWidth;
    int encSize;
    int hit;
    busy = GFL_NET_GetHandleNetID((struct GflNetLink *)GFL_NET_HANDLE_GetCurrentHandle());
    if (((CtvtComm *)comm)->netMode == 2) {
        if (((CtvtComm *)comm)->peers[0].active == 0) {
            u32 v = (u32)COMM_TVT_SYS_GetCamView(work);
            ((CtvtComm *)comm)->peers[0].active = 1;
            ((CtvtComm *)comm)->peers[0].connected = 1;
            ((CtvtComm *)comm)->peers[0].reported = 1;
            ((CtvtComm *)comm)->peers[0].isSelf = 1;
            ((CtvtComm *)comm)->peers[0].hit = 0;
            ((CtvtComm *)comm)->peers[0].postIndex = 0xff;
            ((CtvtComm *)comm)->peers[0].state = 0;
            *(PeerStatusBlock *)&((CtvtComm *)comm)->peers[0].peerParam = *(PeerStatusBlock *)&((CtvtComm *)comm)->peerStatus;
            ((CtvtComm *)comm)->prevMemberCount = 1;
            ((CtvtComm *)comm)->memberCount = 1;
            CTVT_CAMVIEW_StartLayoutChange(work, (char *)v, 0, 0);
        }
    } else {
        count = GFL_NET_GetNegotiationNum();
        if (((CtvtComm *)comm)->memberCount != count) {
            CTVT_COMM_UpdateMembers(work, comm);
            COMM_TVT_SYS_ClearNameWindows(work);
            if (((CtvtComm *)comm)->memberCount < count && busy == 0) {
                ((CtvtComm *)comm)->memberDirty = 1;
                ((CtvtComm *)comm)->halfResSync = COMM_TVT_SYS_GetHalfRes(work);
            }
            ((CtvtComm *)comm)->statusDirty = 1;
            ((CtvtComm *)comm)->memberCount = count;
            ((CtvtComm *)comm)->prevMemberCount = count;
        }
    }
    for (slot = 0; slot < 4; slot++) CTVT_COMM_UpdatePeerSlot(work, (int)comm, (int *)(comm + 0x64 + slot * 0x40), slot);
    if (((CtvtComm *)comm)->memberCount > 1) {
        if (((CtvtComm *)comm)->sendBusy == 1) {
            if (GFL_NET_LOWER_DATA_IsSendFinished() == 1) ((CtvtComm *)comm)->sendBusy = 0;
        } else {
            u8 sendBits = ((CtvtComm *)comm)->sendMask;
            u8 voiceBits = ((CtvtComm *)comm)->voiceMask;
            if (sendBits == (sendBits & voiceBits) && sendBits != 0) {
                if (COMM_TVT_SYS_GetCameraBusy(work) == 0) {
                    COMM_TVT_SYS_SetCameraBusy(work, 1);
                    if (COMM_TVT_SYS_GetMessageActive(work) == 0) {
                        camView = (u32)COMM_TVT_SYS_GetCamView(work);
                        srcBuf = CTVT_CAMVIEW_GetOwnSlotBuffer(work, (void *)camView);
                        bufStep = CTVT_CAMVIEW_GetSlotBufferStep(work, camView);
                        MIi_CpuCopy32((void *)srcBuf, (void *)((CtvtComm *)comm)->frameBuf, bufStep);
                        winHeight = CTVT_CAMVIEW_GetWindowHeight(work, camView);
                        winWidth = CTVT_CAMVIEW_GetWindowWidth(work, camView);
                        encSize = SSP_StartJpegEncoder((void *)((CtvtComm *)comm)->frameBuf, (unsigned char *)((CtvtComm *)comm)->jpegOut, bufStep, (unsigned char *)((CtvtComm *)comm)->jpegWork, winHeight, winWidth, 0x46, 1, 4);
                        if (encSize != 0) {
                            GFL_NET_LOWER_DATA_SetSendData((int)((CtvtComm *)comm)->jpegOut, encSize, ((CtvtComm *)comm)->sendMask, 0);
                            ((CtvtComm *)comm)->voiceMask = 0;
                            ((CtvtComm *)comm)->sendBusy = 1;
                        }
                    }
                    COMM_TVT_SYS_SetCameraBusy(work, 0);
                }
            }
        }
        if (((CtvtComm *)comm)->writeCursor != ((CtvtComm *)comm)->readCursor) {
            if (((CtvtComm *)comm)->strokeSendPending == 1) CTVT_COMM_SendStrokeQueue((int)work, comm);
        }
        if (((CtvtComm *)comm)->cmd4Pending == 1) {
            if (CTVT_COMM_SendCommand((int)work, (int)comm, 4, 0) == 1) ((CtvtComm *)comm)->cmd4Pending = 0;
        }
        if (((CtvtComm *)comm)->cmd5Pending == 1) {
            if (CTVT_COMM_SendCommand((int)work, (int)comm, 5, 0) == 1) ((CtvtComm *)comm)->cmd5Pending = 0;
        }
        if (((CtvtComm *)comm)->statusDirty == 1) {
            if (CTVT_COMM_SendPeerStatus((int)work, comm) == 1) ((CtvtComm *)comm)->statusDirty = 0;
        }
    }
    if (busy == 0) {
        if (((CtvtComm *)comm)->memberDirty == 1) {
            if (CTVT_COMM_SendCommand((int)work, (int)comm, 2, ((CtvtComm *)comm)->halfResSync) == 1) ((CtvtComm *)comm)->memberDirty = 0;
        }
        if (((CtvtComm *)comm)->markerDirty == 1) {
            hit = 0;
            for (slot2 = 0; slot2 < 4; slot2++) {
                if (((CtvtComm *)comm)->peers[slot2].hit == 1) {
                    if (((CtvtComm *)comm)->currentSlot == 0xff) ((CtvtComm *)comm)->currentSlot = slot2;
                    hit = 1;
                    ((CtvtComm *)comm)->peers[slot2].hit = 0;
                }
            }
            if (hit == 0) ((CtvtComm *)comm)->currentSlot = 0xff;
            if (((CtvtComm *)comm)->currentSlot != ((CtvtComm *)comm)->markerSlot) ((CtvtComm *)comm)->slotMarkerDirty = 1;
            ((CtvtComm *)comm)->markerDirty = 0;
        }
        count = ((CtvtComm *)comm)->currentSlot;
        if (count != 0xff) {
            if (((CtvtComm *)comm)->peers[count].active == 0) {
                ((CtvtComm *)comm)->currentSlot = 0xff;
                ((CtvtComm *)comm)->slotMarkerDirty = 1;
                ((CtvtComm *)comm)->markerDirty = 0;
            }
        }
        if (((CtvtComm *)comm)->slotMarkerDirty == 1) {
            if (CTVT_COMM_SendCommand((int)work, (int)comm, 1, ((CtvtComm *)comm)->currentSlot) == 1) ((CtvtComm *)comm)->slotMarkerDirty = 0;
        }
    }
}

/*
 * note (2026-10-05, wD4 lane17): still MATCH, only the ov014 leaf 02179650 (pengy range, no label) is unresolved.
 * note 2026-10-04 wD2 lane01: still MATCH. Symbols line already has `thumb ov014`; match.py still says no witness (ov009/ov014 overlap, 021797A8-area leaf WIH_SetScanWaitFrames unlabelled in pengy's ov014). Needs a matched/labelled leaf at 0x02179650 in ov014 (pengy range, not touched).
 * note 2026-10-02: byte-correct. Only open relocation: the tail-call target 0x02179650 (pool word 0x02179651)
 *   is an unlabelled thumb leaf in ov014 ("ldr r1, =g_021797A8; ldr r2, [r1]; ldr r1, =0x1EC2; strh r0, [r2, r1]; bx lr").
 *   ov014 is outside this lane (pengy range); seeding 0x02179650 there closes this one.
 * note 2026-10-05 (wD8 lane06): re-run, still MATCH. Only blocker: WIH_SetScanWaitFrames, an unlabelled Thumb leaf in ov014
 *   (pengy's overlay, not same-overlay, so the witness exception does not apply). Seeding that label closes this.
 */
void CTVT_COMM_SetScanWait(void *work, char *comm)
{
    WIH_SetScanWaitFrames(5);
}

/*
 * note 2026-10-05 wD4 lane05: EXACT. w is a u32 local (callee keeps its real u16 return) declared
 *   between me and base: declaration order me, w, base, e gives slots 0x10, 0xC, 8, 4.
 */
void CTVT_COMM_UpdateMembers(void *work, char *comm)
{
    u32 count = 0;
    int changed = 0;
    u8 slot;
    u32 selfSlot;
    u32 heapId;
    u32 camView;
    char *slotPtr;

    selfSlot = GFL_NET_GetHandleNetID((struct GflNetLink *)GFL_NET_HANDLE_GetCurrentHandle());
    heapId = COMM_TVT_SYS_GetHeapId(work);
    for (slot = 0; slot < 4; slot++) {
        if (GFL_NET_IsConnectMember(slot) == 1) {
            slotPtr = comm + slot * 64;
            if (((CtvtComm *)comm)->peers[slot].active == 0) {
                camView = (u32)COMM_TVT_SYS_GetCamView(work);
                ((CtvtComm *)comm)->peers[slot].active = 1;
                if (slot == selfSlot) {
                    ((CtvtComm *)comm)->peers[slot].isSelf = 1;
                } else {
                    u8 bufIdx;
                    for (bufIdx = 0; bufIdx < 3; bufIdx++) {
                        u32 bit = 1 << bufIdx;
                        if (!(bit & ((CtvtComm *)comm)->postWorkMask)) {
                            GFL_NET_LOWER_DATA_CreatePostWork(0xC000, slot, heapId, (u32)((CtvtComm *)comm)->postWork[bufIdx]);
                            ((CtvtComm *)comm)->postWorkMask |= (u8)bit;
                            ((CtvtComm *)comm)->peers[slot].postIndex = bufIdx;
                            break;
                        }
                    }
                    ((CtvtComm *)comm)->sendMask |= (u8)(1 << slot);
                    ((CtvtComm *)comm)->peers[slot].state = 1;
                }
                CTVT_CAMVIEW_RequestWindowAnimation((int)work, (char *)camView, slot);
                changed = 1;
            }
            count = (u8)(count + 1);
        } else {
            u32 slotOff = slot << 6;
            char *slotPtr2 = comm + slotOff;
            if (((CtvtComm *)comm)->peers[slot].active == 1) {
                ((CtvtComm *)comm)->peers[slot].active = 0;
                if (((CtvtComm *)comm)->peers[slot].isSelf == 0) {
                    GFL_NET_LOWER_DATA_DeletePostWork(slot);
                    ((CtvtComm *)comm)->postWorkMask -= (u8)(1 << ((CtvtComm *)comm)->peers[slot].postIndex);
                }
                if (((CtvtComm *)comm)->markerSlot == slot)
                    ((CtvtComm *)comm)->postBusy = 0;
                changed = 1;
                ((CtvtComm *)comm)->sendMask -= (u8)(changed << slot);
                CTVT_COMM_ClearPeerSlot((int)work, (int)comm, &((CtvtComm *)comm)->peers[slot]);
            }
        }
    }
    if (changed == 1) {
        COMM_TVT_SYS_SetMemberCount(work, count);
        COMM_TVT_SYS_SetSelfSlot(work, selfSlot);
    }
    CTVT_CAMVIEW_StartLayoutChange(work, (char *)COMM_TVT_SYS_GetCamView(work), 0, 1);
}

/*
 * True when one of three 6-byte records at +0x22 matches the probe string.
 *
 * Addresses are Black-image addresses.
 */
int CTVT_COMM_FindPeerName(unsigned char *comm, unsigned char *probe)
{
    unsigned char idx;

    for (idx = 0; idx < 3; idx++) {
        unsigned char byte;
        int match = 1;

        for (byte = 0; byte < 6; byte++) {
            if (comm[idx * 6 + byte + 0x22] != probe[byte]) {
                match = 0;
                break;
            }
        }
        if (match == 1) {
            return 1;
        }
    }
    return 0;
}

void CTVT_COMM_ClearPeerSlot(int unused, int unused2, void *slot)
{
    ((CtvtPeerSlot *)slot)->isSelf = 0;
    ((CtvtPeerSlot *)slot)->active = 0;
    ((CtvtPeerSlot *)slot)->connected = 0;
    ((CtvtPeerSlot *)slot)->reported = 0;
    ((CtvtPeerSlot *)slot)->hit = 0;
    ((CtvtPeerSlot *)slot)->postIndex = 0xff;
    ((CtvtPeerSlot *)slot)->state = 0;
}

void CTVT_COMM_UpdatePeerSlot(void *work, int comm, int *slot, int slotIdx)
{
    char *camView;
    int buf, post;
    short dims[2];
    camView = (char *)COMM_TVT_SYS_GetCamView(work);
    if (slot[0] != 0 && slot[3] != 1) {
        if (slot[2] == 0 && slot[1] == 1) {
            if (COMM_TVT_SYS_IsLaunchModeCall(work) == 0)
                COMM_TVT_SYS_SavePeerRecord((u32 *)work, slot + 7);
            slot[2] = 1;
        }
        switch (slot[6]) {
        case 0:
        case 4:
            break;
        case 1:
            if (CTVT_COMM_SendCommand((int)work, comm, 0, 0) == 1)
                slot[6] = 2;
            break;
        case 2:
            if (GFL_NET_LOWER_DATA_IsPostComplete(slotIdx) == 0) {
                CTVT_CAMVIEW_ClearWindowDirty(work, camView, slotIdx);
                slot[6] = 3;
            }
            break;
        case 3:
            if (GFL_NET_LOWER_DATA_IsPostComplete(slotIdx) == 1) {
                buf = CTVT_CAMVIEW_GetSlotBuffer(work, camView, slotIdx);
                dims[1] = CTVT_CAMVIEW_GetWindowHeight(work, (u32)camView);
                dims[0] = CTVT_CAMVIEW_GetWindowWidth(work, (u32)camView);
                post = GFL_NET_LOWER_DATA_GetPostBuffer(slotIdx);
                SSP_StartJpegDecoder((unsigned char *)post, GFL_NET_LOWER_DATA_GetPostRecvSize(slotIdx), (void *)buf, &dims[1], &dims[0], 0);
                CTVT_CAMVIEW_MarkWindowDirty(work, camView, slotIdx);
                slot[6] = 1;
            }
            break;
        }
    }
}

/*
 * Registers a 1-word/1-word record at a1[0xee..0xef] when the helper rejects the
 * request.
 *
 * Addresses are Black-image addresses.
 */
void CTVT_COMM_SendSlotHit(void *work, u32 *comm, u32 value)
{
    if (CTVT_COMM_SendCommand((int)work, (int)comm, 2, value) == 0) {
        comm[0xee] = 1;
        comm[0xef] = value;
    }
}

u32 CTVT_COMM_SendCommand(int work, int comm, u8 command, u32 value)
{
    struct { u32 w; u8 comm; } msg;
    u32 handle;
    handle = (u32)GFL_NET_HANDLE_GetCurrentHandle();
    msg.comm = command;
    msg.w = value;
    return GFL_NET_SendData(handle, 255, 0x2000, 8, (u32)&msg, 1, 0, 0);
}

void CTVT_COMM_HandleMessage(int sender, int size, u32 *msg, char *comm)
{
    u32 selfSlot;
    void *talk;
    char *camView;
    u32 value;
    selfSlot = GFL_NET_GetHandleNetID((struct GflNetLink *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    switch (((CtvtCommMsg *)msg)->command) {
    case 0:
        if (sender == selfSlot)
            break;
        ((CtvtComm *)comm)->voiceMask |= (u8)(1 << sender);
        break;
    case 1:
        value = msg[0];
        ((CtvtComm *)comm)->markerSlot = value;
        if (value != 0xff) {
            COMM_TVT_SYS_PlaceSlotMarker(((CtvtComm *)comm)->work, (u8)value);
        } else {
            talk = (void *)COMM_TVT_SYS_GetTalkStatus(((CtvtComm *)comm)->work);
            COMM_TVT_SYS_HideSlotMarker(((CtvtComm *)comm)->work);
            CTVT_MIC_StopVoice(talk);
        }
        break;
    case 3:
        DRAW_SYSTEM_SetQueueIndex((void *)COMM_TVT_SYS_GetSprites(((CtvtComm *)comm)->work), msg[0]);
        COMM_TVT_SYS_SetInputLocked(((CtvtComm *)comm)->work, 0);
        break;
    case 2:
        camView = (char *)COMM_TVT_SYS_GetCamView(((CtvtComm *)comm)->work);
        value = msg[0];
        if (value == COMM_TVT_SYS_GetHalfRes(((CtvtComm *)comm)->work))
            break;
        COMM_TVT_SYS_SetHalfRes(((CtvtComm *)comm)->work, value);
        CTVT_CAMVIEW_StartLayoutChange(((CtvtComm *)comm)->work, camView, 1, 0);
        break;
    case 4:
        if (sender == selfSlot)
            break;
        ((CtvtComm *)comm)->strokeSendPending = 1;
        break;
    case 5:
        if (sender == selfSlot)
            break;
        ((CtvtComm *)comm)->voiceStatePending = 1;
        break;
    case 6:
        if (selfSlot != 0)
            break;
        ((CtvtComm *)comm)->peers[sender].hit = 1;
        ((CtvtComm *)comm)->markerDirty = 1;
        break;
    case 7:
        talk = (void *)COMM_TVT_SYS_GetTalkStatus(((CtvtComm *)comm)->work);
        if (sender == selfSlot)
            CTVT_MIC_PlayVoice(talk, *(char * *)&((CtvtComm *)comm)->voiceRec, ((CtvtComm *)comm)->playLength, 0, ((CtvtComm *)comm)->playFreq);
        else
            CTVT_MIC_PlayVoice(talk, *(char * *)&((CtvtComm *)comm)->voiceRec, ((CtvtComm *)comm)->playLength, 0x7f, ((CtvtComm *)comm)->playFreq);
        break;
    case 8:
        if (selfSlot == 0) {
            ((CtvtComm *)comm)->peers[sender].hit = 0;
            ((CtvtComm *)comm)->markerDirty = 1;
        }
        COMM_TVT_SYS_HideSlotMarker(((CtvtComm *)comm)->work);
        break;
    case 9:
        if (sender == ((CtvtComm *)comm)->markerSlot)
            ((CtvtComm *)comm)->markerDirty = 1;
        COMM_TVT_SYS_HideSlotMarker(((CtvtComm *)comm)->work);
        break;
    case 10:
        COMM_TVT_SYS_SetEndRequested(((CtvtComm *)comm)->work, 1);
        break;
    }
}

int CTVT_COMM_SendVoiceData(void *work, char *comm, u16 *packet)
{
    u32 handle;
    int result;
    handle = (u32)GFL_NET_HANDLE_GetCurrentHandle();
    result = GFL_NET_SendData(handle, 255, 0x2001, *packet + 8, (u32)packet, 1, 0, 1);
    if (result != 0)
        ((CtvtComm *)comm)->postBusy = 1;
    return result;
}

/*
 * Sets the +0x194 flag, refills the +0x1a4 block and returns it.
 *
 * Addresses are Black-image addresses.
 */
int CTVT_COMM_ResetVoiceRecord(void *work, char *comm)
{
    ((CtvtComm *)comm)->postBusy = 1;
    MIi_CpuClear32(0, ((CtvtComm *)comm)->voiceRec, 0x208);
    return (int)((CtvtComm *)comm)->voiceRec;
}

void CTVT_COMM_ReceiveVoicePacket(int unused1, int unused2, int unused3, char *comm)
{
    void *talk;
    char *packet, *payload;
    CtvtFreqTable freqTable;
    talk = (void *)COMM_TVT_SYS_GetTalkStatus(((CtvtComm *)comm)->work);
    packet = (char *)((CtvtComm *)comm)->voiceRec;
    payload = packet + 8;
    GFL_NET_GetHandleNetID((struct GflNetLink *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    if (((CtvtTalkPacket *)packet)->index == 0) {
        CTVT_ADPCM_ResetDecoder();
        MIi_CpuClear32(0, (int)(((CtvtComm *)comm)->decodeBuf), 0xc800);
    }
    CTVT_MIC_DecodeAdpcm((int)talk, (int)payload, ((CtvtComm *)comm)->decodeBuf + (((CtvtTalkPacket *)packet)->index << 11), ((CtvtTalkPacket *)packet)->length);
    if (((CtvtTalkPacket *)packet)->last == 1) {
        freqTable = gCtvtCommFreqTable;
        ((CtvtComm *)comm)->playFreq = freqTable.value[((CtvtTalkPacket *)packet)->level];
        ((CtvtComm *)comm)->playPending = 1;
        ((CtvtComm *)comm)->playLength = ((CtvtTalkPacket *)packet)->position;
    }
    ((CtvtComm *)comm)->postBusy = 0;
}

u32 CTVT_COMM_SendStrokeQueue(int unused, char *comm)
{
    u32 handle, result;
    u8 available, writeCursor, readCursor;
    handle = (u32)GFL_NET_HANDLE_GetCurrentHandle();
    writeCursor = ((CtvtComm *)comm)->writeCursor;
    readCursor = ((CtvtComm *)comm)->readCursor;
    if (readCursor > writeCursor) available = 64 - readCursor;
    else available = writeCursor - readCursor;
    if (available > 8) available = 8;
    if (available != 0) {
        result = GFL_NET_SendData(handle, 255, 0x2002, available * 8, (u32)(((CtvtComm *)comm)->slotBuf + readCursor * 8), 1, 1, 0);
        if (result != 0) {
            ((CtvtComm *)comm)->readCursor += available;
            if (((CtvtComm *)comm)->readCursor >= 64) ((CtvtComm *)comm)->readCursor -= 64;
        }
        return result;
    }
    return 1;
}

void CTVT_COMM_PushStrokes(int work, u32 size, char *strokes, char *comm)
{
    char *sprites;
    u8 count, idx;
    sprites = (char *)COMM_TVT_SYS_GetSprites(((CtvtComm *)comm)->work);
    count = (size >> 3) & 0xff;
    GFL_NET_GetHandleNetID((struct GflNetLink *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    for (idx = 0; idx < count; idx++)
        DRAW_SYSTEM_PushStroke(sprites, strokes + idx * 8);
}

int CTVT_COMM_SendPeerStatus(int unused, char *comm)
{
    char *status = CTVT_COMM_GetPeerStatus(unused, comm);
    return GFL_NET_SendData((int)GFL_NET_HANDLE_GetCurrentHandle(), 0xFF, 0x2003, 0x21, (u32)status, 1, 1, 1);
}

/*
 * Claims the +0x68 slot of record i and releases the +0x3dc block once.
 *
 * Addresses are Black-image addresses.
 */
void CTVT_COMM_ClaimSlot(int slot, void *unused1, void *unused2, char *comm)
{
    u32 *flag = &((CtvtComm *)comm)->peers[slot].connected;

    if (*flag == 0) {
        *flag = 1;
        COMM_TVT_SYS_ClearNameWindows(((CtvtComm *)comm)->work);
    }
}

char *CTVT_COMM_GetSlotName(int slot, char *comm)
{
    return CTVT_COMM_GetSlotParam((int)((CtvtComm *)comm)->work, comm, (u8)slot);
}

/*
 * arm9 call whose result is the first argument of the second call.
 *
 * Addresses are Black-image addresses.
 */
void CTVT_COMM_SetTimingSync(void *work, u32 unused, u32 command)
{
    GFL_NET_HANDLE_SetTimingSyncRange((struct GflNetLink *)GFL_NET_HANDLE_GetCurrentHandle(), command, 0x20);
}

int CTVT_COMM_IsTimingSync(void *work, u32 unused, u32 command)
{
    return GFL_NET_HANDLE_IsTimingSyncRange((struct GflNetLink *)GFL_NET_HANDLE_GetCurrentHandle(), command, 0x20);
}

u32 CTVT_COMM_GetHandleNetId(void *unused, u32 unused2)
{
    return GFL_NET_GetHandleNetID((struct GflNetLink *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
}

/*
 * Field getter, u8 at +0x3ae of the second argument.
 *
 * Addresses are Black-image addresses.
 */
u32 CTVT_COMM_GetMarkerSlot(int unused, char *comm)
{
    return ((CtvtComm *)comm)->markerSlot;
}

int CTVT_COMM_IsPostBusy(void *unused, u8 *comm)
{
    return ((CtvtComm *)comm)->postBusy;
}

u8 *CTVT_COMM_GetMyStatusPtr(void *unused, u8 *comm)
{
    return comm + 0xc;
}

/*
 * Field getter, u32 at +0x1a4 of the second argument.
 *
 * Addresses are Black-image addresses.
 */
u32 CTVT_COMM_GetVoiceRecord(int unused, char *comm)
{
    return (u32)((CtvtComm *)comm)->voiceRec;
}

/*
 * Field getter, u32 at +0x68 of record i (stride 0x40).
 *
 * Addresses are Black-image addresses.
 */
u32 CTVT_COMM_GetSlotConnected(int unused, char *comm, int slot)
{
    return ((CtvtComm *)comm)->peers[slot].connected;
}

/*
 * Record address, +0x80, stride 0x40.
 *
 * Addresses are Black-image addresses.
 */
char *CTVT_COMM_GetSlotParam(int unused, char *comm, int slot)
{
    return (char *)((CtvtComm *)comm)->peers[slot].peerParam;
}

char *CTVT_COMM_GetPeerStatus(int unused, char *comm)
{
    return (char *)((CtvtComm *)comm)->peerStatus;
}

/*
 * Field getter, u32 at +0x64 of record i (stride 0x40).
 *
 * Addresses are Black-image addresses.
 */
u32 CTVT_COMM_IsSlotActive(int unused, char *comm, int slot)
{
    return ((CtvtComm *)comm)->peers[slot].active;
}

/*
 * Field getter, u8 at +0xa0 of record i (stride 0x40).
 *
 * Addresses are Black-image addresses.
 */
u8 CTVT_COMM_GetSlotReady(void *unused, char *comm, int slot)
{
    return ((CtvtComm *)comm)->peers[slot].readyFlag;
}

/*
 * Wraps the +0x1ac cursor; on a mismatch returns the +0x1ae slot base.
 *
 * Addresses are Black-image addresses.
 */
int CTVT_COMM_PopStroke(int unused, unsigned char *comm, int *full)
{
    unsigned char next = (unsigned char)(((CtvtComm *)comm)->writeCursor + 1);

    (void)unused;
    if (next >= 0x40) {
        next -= 0x40;
    }
    if (next == ((CtvtComm *)comm)->readCursor) {
        *full = 1;
        return 0;
    }
    *full = 0;
    return (int)(((CtvtComm *)comm)->slotBuf + ((CtvtComm *)comm)->writeCursor * 8);
}

void CTVT_COMM_AdvanceWriteCursor(int unused, u8 *comm)
{
    ((CtvtComm *)comm)->writeCursor += 1;
    if (((CtvtComm *)comm)->writeCursor >= 0x40) {
        ((CtvtComm *)comm)->writeCursor -= 0x40;
    }
}

void CTVT_COMM_ResetSlotTimer(void *unused, u8 *comm)
{
    ((CtvtComm *)comm)->slotTimer = 0x4b0;
}

u32 CTVT_COMM_IsSlotTimerDone(void *unused, u8 *comm)
{
    if (((CtvtComm *)comm)->slotTimer == 0)
        return 1;
    return 0;
}

/*
 * Return the word at +0x3C8 of the record. Filed as the call witness for
 * ov172 CTVT_TALK_UpdateVoiceSend.
 */
u32 CTVT_COMM_GetVoiceStatePending(void *unused, u8 *comm)
{
    return ((CtvtComm *)comm)->voiceStatePending;
}
