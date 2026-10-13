/*
 * file:     wih.c
 * unit:     yes
 * function: WIH_ChangeSysState, WIH_SetError, WIH_StateInSetParentParam, WIH_StateOutSetParentParam, WIH_StateInStartParent, WIH_StateOutStartParent, WIH_StateInStartParentMP, WIH_StateOutStartParentMP, WIH_StateInEndParentMP, WIH_StateOutEndParentMP, func_021784F0, func_0217850C, DWCi_MOV_WH_ChildConnectAuto, DWCi_MOV_WH_StartScan, DWCi_MOV_WH_StateInStartScan, WIH_SetScanTarget, WIH_IsMatchingParent, DWCi_MOV_WH_StateOutStartScan, DWCi_MOV_WH_EndScan, func_02178964, DWCi_MOV_WH_StateOutEndScan, DWCi_MOV_WH_StateInStartChild, DWCi_MOV_WH_StateOutStartChild, DWCi_MOV_WH_StateInStartChildMP, DWCi_MOV_WH_StateOutStartChildMP, WIH_StateInEndChildMP, WIH_StateOutEndChildMP, WIH_StateInEndChild, func_02178CC4, WIH_StateInReset, WIH_StateOutReset, DWCi_MOV_WH_StateInSetMPData, WIH_StateOutSetMPData, DWCi_MOV_WH_PortReceiveCallback, WIH_StateOutEnd, WIH_SetGgid, func_02178E28, WIH_GetBitmap, WIH_GetSysState, DWCi_MOV_WH_GetLastError, WIH_StartMeasureChannel, WIH_StateInMeasureChannel, WIH_StateOutMeasureChannel, func_02179010, WIH_GetMeasureChannel, WIH_PickRandomChannel, WIH_Initialize, WIH_FreeWork, WIH_IndicateHandler, WIH_StateInInitialize, DWCi_MOV_WH_StateOutSetLifeTime, WIH_StateOutInitialize, WIH_ParentConnect, WIH_SetJudgeAcceptFunc, DWCi_MOV_WH_SetReceiver, DWCi_MOV_WH_SendData, WIH_GetSharedDataAdr, WIH_StepDS, WIH_UpdateScanTimer, DWCi_MOV_WH_StateInEndKeyShare, WIH_Finalize, WIH_End, WIH_GetOwnAid, WIH_SetJudgeScanFunc, WIH_SetBeaconGameInfo, WIH_GetBeaconSendCount, WIH_SetConnectCallback, WIH_SetBeaconFoundCallback, WIH_SetScanWaitFrames
 * address:  0x02178138
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from wih.c at 0x02178138 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   gWihWork 0x021797A8 data ov014 a4
 *   WM_SetParentParameter 0x0208F480 arm
 *   WM_StartParent  0x0208F644  arm
 *   GFL_NET_GetUserArg  0x0203D650  arm
 *   WM_Disconnect  0x0208F938  arm
 *   GFL_NET_HANDLE_RemoveHandle  0x0203A338  arm
 *   GFL_NET_HANDLE_RequestNegotiation  0x02039A2C  arm
 *   sWihFileName                  0x02179794  data   ov014  a1
 *   WM_GetMPSendBufferSize      0x0208EC34  arm
 *   WM_GetMPReceiveBufferSize   0x0208ECA4  arm
 *   WM_StartMP                  0x0208FC4C  arm
 *   GFL_NET_FreeAligned               0x0203D7FC  arm
 *   GFL_NET_AllocAligned               0x0203D7C8  arm
 *   GFL_NET_GetGameKind               0x0203D5D4  arm
 *   GFL_NET_GetChildSendSize  0x0203D6BC  arm
 *   GFL_NET_GetMaxConnectNum  0x0203D680  arm
 *   WM_StartDataSharing  0x0209004C  arm
 *   WM_EndMP 0x0208FDEC arm
 *   func_021784F0 0x021784F0 thumb ov014
 *   WM_EndParent                 0x0208F654  arm
 *   DWCi_MOV_WH_SetError             0x0217814C  thumb
 *   DWCi_MOV_WH_ChangeSysState       0x02178138  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   WM_GetAllowedChannel         0x0208EE60  arm
 *   WM_GetDispersionScanPeriod   0x0208EFC4  arm
 *   WM_StartScanEx               0x0208F698  arm
 *   sWihAssertText          0x0217979C  data   a1
 *   func_02178964       0x02178964  thumb  ov014
 *   WIH_DWC_RequestAlertLevel       0x02010864  thumb
 *   WIH_DWC_Dummy       0x02010884  thumb
 *   DC_InvalidateRange  0x020862B8  arm
 *   MI_CpuCopy8         0x02082D44  arm
 *   func_02034714       0x02034714  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   WM_EndScan                     0x0208F808  arm
 *   WM_StartConnectEx  0x0208F84C  arm
 *   func_02178CC4 0x02178CC4 thumb ov014
 *   WM_Reset 0x0208F400 arm
 *   WM_SetMPDataToPortEx  0x0208FCB4  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   func_02179010  0x02179010  thumb  ov014
 *   WM_GetAllowedChannel  0x0208EE60  arm
 *   WM_MeasureChannel            0x02090E50  arm
 *   WM_Initialize  0x0208F370  arm
 *   WM_InitializeForListening  0x0208F380  arm
 *   WM_SetIndCallback  0x0208EAC8  arm
 *   WM_SetLifeTime  0x02090DEC  arm
 *   WM_GetDispersionBeaconPeriod  0x0208EF30  arm
 *   GFL_NET_GetParentSendSize  0x0203D6CC  arm
 *   WM_SetPortCallback 0x0208EB0C arm
 *   WM_GetSharedDataAddress 0x02090B18 arm
 *   WM_StepDataSharing  0x020902D8  arm
 *   WM_EndDataSharing 0x0209028C arm
 *   WM_EndDataSharing   0x0209028C  arm
 *   WM_End 0x0208F43C arm
 *   WM_SetGameInfo  0x02090CD4  arm
 *   NET_WHPIPE_OnChildDisconnected 0x0217807C thumb ov014
 */
struct WMDataSet;
struct WMDataSharingInfo;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef short s16;

typedef int BOOL;

/* Callback types of the work block (what the SDK calls back into). */
typedef int (*WihJudgeAcceptFunc)(void *startParentCb, u32 now);

typedef void (*WihSlotCallback)(u16 aid);

typedef void (*WihBeaconFoundCallback)(void *bssDesc, u32 now, u16 linkLevel);

typedef int (*WihJudgeScanFunc)(void *bssDesc);

typedef void (*WihResultCallback)(int ok);

typedef void (*WihRecvCallback)(u32 aid, u32 data, u32 length);

/* Common head of every WM completion callback argument. */
typedef struct { u16 apiid; u16 errcode; } WMCallback;

/* Argument of the WM_StartParent callback (the state code selects the event). */
typedef struct WMStartParentCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u8 macAddress[6];
    u16 aid;
} WMStartParentCallback;

/* Argument of the WM_StartConnectEx callback. */
typedef struct WMStartConnectCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 aid;
} WMStartConnectCallback;

/* Argument of the WM_StartMP callback. */
typedef struct WMStartMPCallback {
    u16 apiid;
    u16 errcode;
    u16 state;
} WMStartMPCallback;

/* Argument of the port send completion callback (WM_SetMPDataToPortEx). */
typedef struct WMPortSendCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 port;
    u16 destBitmap;
    u16 restBitmap;
    u16 sentBitmap;
    u8 reserved[0x10];
    WihResultCallback userCallback;     /* +0x20, the arg of WM_SetMPDataToPortEx */
} WMPortSendCallback;

/* Argument of the port receive callback. */
typedef struct WMPortRecvCallback {
    u16 apiid;
    u16 errcode;
    u16 state;
    u8 reserved[6];
    u32 data;                           /* +0x0C */
    u16 length;                         /* +0x10 */
    u16 aid;                            /* +0x12 */
} WMPortRecvCallback;

/* Argument of the WM_MeasureChannel callback. */
typedef struct WMMeasureChannelCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 channel;
    u16 ccaBusyRatio;
} WMMeasureChannelCallback;

/* One received beacon: a WMBssDesc (0xC0 bytes, only the fields read here). */
typedef struct WMBssDesc {
    u16 length;
    u16 rssi;
    u8 bssid[6];
    u16 ssidLength;
    u8 ssid[0x20];
    u16 capaInfo;                       /* +0x2C */
    u8 radioInfo[0xE];                  /* +0x2E, rate set, periods, channel */
    u16 gameInfoLength;                 /* +0x3C */
    u16 otherElementCount;
    u16 gameInfoMagic;                  /* +0x40 */
    u8 gameInfoVersion;
    u8 gameInfoPad;
    u32 ggid;                           /* +0x44 */
    u16 tgid;
    u8 userGameInfoLength;              /* +0x4A */
    u8 attribute;                       /* +0x4B, low 2 bits: entry/multiboot flags */
    u8 userGameInfo[0x74];
} WMBssDesc;

/* Argument of the WM_StartScanEx callback. */
typedef struct WMStartScanExCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 channelList;
    u16 reserved;
    u16 bssDescCount;
    WMBssDesc *bssDesc[16];
    u16 linkLevel[16];
} WMStartScanExCallback;

/* The WMParentParam at the start of the work block. */
typedef struct WihParentParam {
    void *userGameInfo;
    u16 userGameInfoLength;
    u16 padding;
    u32 ggid;
    u16 tgid;
    u16 entryFlag;
    u16 maxEntry;
    u16 multiBootFlag;
    u16 keySharing;
    u16 cswitch;
    u16 beaconPeriod;
    u16 reserved[12];
    u16 channel;                        /* +0x32 */
    u16 parentMaxSize;
    u16 childMaxSize;
} WihParentParam;

/* The WMScanExParam inside the work block. */
typedef struct WihScanParam {
    u8 *scanBuf;
    u16 scanBufSize;
    u16 channelList;                    /* one bit per channel */
    u16 maxChannelTime;
    u16 bssid[3];
    u16 scanType;
    u16 ssidLength;
    u8 ssid[0x20];
    u16 ssidMatchLength;
    u8 reserved[0xE];
} WihScanParam;

/*
 * The work block of the wireless handler (the DWC copy of the NitroSDK demo
 * wh.c work area).  One block of 0x1F00 bytes, allocated by
 * DWCi_MOV_WH_Initialize, zero filled up to 0x1EE0, pointed to by
 * gWihWork.
 */
typedef struct WihWork {
    WihParentParam parentParam;         /* +0x00, the WM_SetParentParameter argument */
    u8 reserved38[8];
    u8 wmSystemBuf[0xF00];              /* +0x40, the WM_Initialize work buffer */
    WMBssDesc scanBssDesc;              /* +0xF40, copy of the beacon being judged */
    u8 scanBuf[0x400];                  /* +0x1000, the WM_StartScanEx beacon buffer */
    WihScanParam scanParam;             /* +0x1400 */
    u8 dataSharingInfo[0x820];          /* +0x1444, the WMDataSharingInfo */
    u8 dataSet[0x200];                  /* +0x1C64, the WMDataSet */
    WihResultCallback initCallback;     /* +0x1E64, user callback of init, reset and end */
    void *sendBuf;                      /* +0x1E68, MP send buffer */
    void *recvBuf;                      /* +0x1E6C, MP receive buffer */
    int sysState;                       /* +0x1E70 */
    int connectMode;                    /* +0x1E74 */
    WihRecvCallback recvCallback;       /* +0x1E78, the port receive callback */
    WihJudgeAcceptFunc judgeAcceptFunc; /* +0x1E7C */
    WihSlotCallback disconnectCallback; /* +0x1E80 */
    WihSlotCallback connectCallback;    /* +0x1E84 */
    WihBeaconFoundCallback beaconFoundCallback; /* +0x1E88 */
    int sendBufSize;                    /* +0x1E8C */
    int recvBufSize;                    /* +0x1E90 */
    WihJudgeScanFunc judgeScanFunc;     /* +0x1E94 */
    int lastError;                      /* +0x1E98 */
    u32 randomSeed;                     /* +0x1E9C */
    u8 reserved1EA0[8];
    u16 ownAid;                         /* +0x1EA8 */
    u16 aidBitmap;                      /* +0x1EAA, one bit per connected aid */
    u16 measuredChannel;                /* +0x1EAC */
    u16 minBusyRatio;                   /* +0x1EAE, lowest CCA busy ratio seen */
    u16 bestChannelBitmap;              /* +0x1EB0, channels with that ratio */
    u16 fixedScanChannel;               /* +0x1EB2, 0 = scan every allowed channel */
    u16 autoConnect;                    /* +0x1EB4, nonzero: connect to the first accepted parent */
    u8 reserved1EB6[4];
    u16 beaconSendCount;                /* +0x1EBA */
    u16 scanCount;                      /* +0x1EBC */
    s16 scanWait;                       /* +0x1EBE, frames to the next scan step, -1 = stopped */
    u16 heapId;                         /* +0x1EC0 */
    u16 scanWaitFrames;                 /* +0x1EC2 */
    u8 connectSsid[0x1A];               /* +0x1EC4 */
    u8 scanPaused;                      /* +0x1EDE */
    u8 endScanPending;                  /* +0x1EDF */
} WihWork;

/* SDK and arm9 functions (names resolved by the SDK rename table) */
void DWCi_ScreenDC_FlushRange(void *p, u32 n);
void MI_CpuCopy8(void *dst, void *src, u32 n);
extern int WM_SetParentParameter(void *callback, void *parentParam);
int WM_StartParent(void *callback);
u32 GFL_NET_GetUserArg(void);
extern int WM_Disconnect(void *callback, u16 aid);
void GFL_NET_HANDLE_RemoveHandle(u32 aid);
void GFL_NET_HANDLE_RequestNegotiation(int aid);
extern int WM_GetMPSendBufferSize(void);
extern int WM_GetMPReceiveBufferSize(void);
extern int WM_StartMP(void (*cb)(void *), void *recvBuf, u16 recvSize,
                      void *sendBuf, u16 sendSize, u16 mpFreq);
extern void GFL_NET_FreeAligned(void *p);
extern void *GFL_NET_AllocAligned(u32 heapId, u32 size, const char *file, u16 line);
extern u32 GFL_NET_GetGameKind(void);
u32 GFL_NET_GetChildSendSize(void);
u32 GFL_NET_GetMaxConnectNum(void);
int WM_StartDataSharing(void *dataSharingInfo, u32 aidCount, u32 aidBitmap, u16 myAid, u32 isParent);
extern int WM_EndMP(void *callback);
extern int WM_EndParent(void *callback);
void MI_CpuFill8(void *p, u32 value, u32 n);
extern u16 WM_GetAllowedChannel(void);
extern u16 WM_GetDispersionScanPeriod(void);
extern int WM_StartScanEx(void (*cb)(void *), void *scanParam);
extern void WIH_DWC_RequestAlertLevel(u32 linkLevel);
extern void WIH_DWC_Dummy(void);
extern void DC_InvalidateRange(void *p, u32 size);
extern void func_02034714(const char *expr, u32 line, const char *file);
int OS_DisableInterrupts(void);
void OS_RestoreInterrupts(int irqState);
extern int WM_EndScan(void *callback);
int WM_StartConnectEx(void *callback, void *bssDesc, void *ssid, int powerSave, int authMode);
extern int WM_Reset(void *callback);
int WM_SetMPDataToPortEx(void *callback, u32 userCallback, u32 data, u32 size, u32 destBitmap, u32 port, u32 priority);
void OS_GetMacAddress(u16 *p);
extern int WM_MeasureChannel(void *callback, unsigned short ccaMode, unsigned short edThreshold, unsigned short channel, unsigned short measureTime);
extern int WM_Initialize(void *wmWork, void (*callback)(void *), int dmaNo);
extern int WM_InitializeForListening(void *wmWork, void (*callback)(void *), int dmaNo, int x);
extern int WM_SetIndCallback(void (*callback)(void));
extern void WM_SetLifeTime(void (*callback)(void), int tmptt, int camp, int frame, int ccaWait);
extern u16 WM_GetDispersionBeaconPeriod(void);
extern u32 GFL_NET_GetParentSendSize(void);
extern int WM_SetPortCallback(int port, void *callback, void *arg);
extern int WM_GetSharedDataAddress(void *info, void *dataSet, u16 aid);
extern int WM_StepDataSharing(struct WMDataSharingInfo *dsInfo, const u16 *sendData, struct WMDataSet *receiveData);
extern int WM_EndDataSharing(void *dataSharingInfo);
extern int WM_End(void *callback);
extern void WM_SetGameInfo(int callback, int userGameInfo, u16 size, int ggid, u16 tgid, int attr);

/* functions of this file (and its ov014 neighbours) */
void NET_WHPIPE_OnChildDisconnected(void);
void WIH_ChangeSysState(int state);
void WIH_SetError(int error);
int WIH_StateInSetParentParam(void);
void WIH_StateOutSetParentParam(WMCallback *arg);
int WIH_StateInStartParent(void);
void WIH_StateOutStartParent(WMStartParentCallback *arg);
/*
 * Twin of DWCi_MOV_WH_StateInStartChildMP (the DWC copy of the NitroSDK wh.c MP start), with a
 * state guard in front: states 4 and 5 (sysState) already run MP, else the
 * state setter WIH_ChangeSysState(4) runs first, and the callback is
 * WIH_StateOutStartParentMP.
 */
BOOL WIH_StateInStartParentMP(void);
void WIH_StateOutStartParentMP(WMStartMPCallback *arg);
int WIH_StateInEndParentMP(void);
void WIH_StateOutEndParentMP(WMCallback *arg);
int DWCi_MOV_WH_StateInEndParent(void);
static void DWCi_MOV_WH_StateOutEndParent(void *arg);
/*
 * macAddr is const: that is what lets the ldrh of macAddr[1] schedule above
 * the strh of bssid[2] (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md).
 */
int DWCi_MOV_WH_ChildConnectAuto(u32 mode, const u16 *macAddr, u32 channel);
int DWCi_MOV_WH_StartScan(u32 judgeScanFunc, u16 *macAddr, u32 channel);
/*
 * The DWC copy of the NitroSDK demo wh.c's scan start: checks
 * WM_GetAllowedChannel (0x8000 -> error 3, 0 -> error 0x16), picks the next
 * allowed channel after the one in the scan parameter's channel list (or the
 * fixed channel), fills the WMScanExParam (buffer, 0x400 bytes, scan type 1,
 * no SSID) and calls WM_StartScanEx with callback DWCi_MOV_WH_StateOutStartScan; anything but
 * WM_ERRCODE_OPERATING (2) goes to the error setter WIH_SetError.
 */
BOOL DWCi_MOV_WH_StateInStartScan(void);
void WIH_SetScanTarget(u16 channel, void *macAddr);
int WIH_IsMatchingParent(WMBssDesc *bssDesc);
void DWCi_MOV_WH_StateOutStartScan(void *arg);
int DWCi_MOV_WH_EndScan(void);
static int DWCi_MOV_WH_StateInEndScan(void);
void DWCi_MOV_WH_StateOutEndScan(WMCallback *arg);
int DWCi_MOV_WH_StateInStartChild(void);
void DWCi_MOV_WH_StateOutStartChild(WMStartConnectCallback *arg);
BOOL DWCi_MOV_WH_StateInStartChildMP(void);
void DWCi_MOV_WH_StateOutStartChildMP(WMStartMPCallback *arg);
int WIH_StateInEndChildMP(void);
void WIH_StateOutEndChildMP(WMCallback *arg);
int WIH_StateInEndChild(void);
static void DWCi_MOV_WH_StateOutEndChild(void *arg);
int WIH_StateInReset(void);
void WIH_StateOutReset(WMCallback *arg);
int DWCi_MOV_WH_StateInSetMPData(u32 data, u32 size, u32 userCallback);
/* extent: two zero alignment bytes at 02178D9A precede labelled 02178D9C. */
void WIH_StateOutSetMPData(WMPortSendCallback *arg);
void DWCi_MOV_WH_PortReceiveCallback(WMPortRecvCallback *arg);
void WIH_StateOutEnd(WMCallback *arg);
void WIH_SetGgid(u32 ggid);
void DWCi_MOV_WH_SetUserGameInfo(void *userGameInfo, unsigned short length);
u16 WIH_GetBitmap(void);
int WIH_GetSysState(void);
int DWCi_MOV_WH_GetLastError(void);
int WIH_StartMeasureChannel(void);
int WIH_StateInMeasureChannel(u16 channel);
/*
 * note: 2026-10-05 wave P16 lane E8: older draft was DIFF 101 B / 136 B because the
 * two arms kept separate copies of the u16 store. Per-function pragma
 * opt_dead_assignments off gives 132 B EXACT (also with plain literal offsets).
 * Without the pragma the same source stays 136 B. Callee types from matched
 * definitions: WIH_SetError and WIH_ChangeSysState void(int), WIH_StateInMeasureChannel int(u16).
 */
void WIH_StateOutMeasureChannel(const WMMeasureChannelCallback *arg);
int WHi_MeasureChannel(void *callback, unsigned short channel);
u16 WIH_GetMeasureChannel(void);
int WIH_PickRandomChannel(u16 channelBitmap);
BOOL WIH_Initialize(u32 heapId, int unused, int listening);
void WIH_FreeWork(void);
/* extent: two zero alignment bytes at 0217919E precede labelled 021791A0. */
void WIH_IndicateHandler(WMCallback *arg);
/*
 * The DWC copy of WH_Initialize's WM start: WM_Initialize (0208F370) or, when
 * listening is set, WM_InitializeForListening (0208F380), on the WM system
 * buffer of the work block with completion callback WIH_StateOutInitialize.  Anything
 * but WM_ERRCODE_OPERATING goes to the error setter.  The unlabelled
 * follower at 021791EC (`movs r0,#1; bx` tail call to WIH_ChangeSysState) is why
 * the extent runs long.
 */
BOOL WIH_StateInInitialize(int unused, int listening);
/*
 * Unlabelled leaf: sets state 1 by tail-calling WIH_ChangeSysState.  Used as the
 * callback of WIH_StateOutInitialize's call to WM_SetLifeTime.
 */
void DWCi_MOV_WH_StateOutSetLifeTime(void);
void WIH_StateOutInitialize(WMCallback *arg);
BOOL WIH_ParentConnect(int mode, u16 tgid, int channel, u16 maxEntry);
void WIH_SetJudgeAcceptFunc(void *judgeAcceptFunc);
void DWCi_MOV_WH_SetReceiver(void *recvCallback);
/*
 * Guard wrapper: forwards to DWCi_MOV_WH_StateInSetMPData when WIH_GetOwnAid is nonzero or
 * one of bits 1-7 of WIH_GetBitmap is set, else returns 0.  The unlabelled
 * follower at 02179394 (adds the block's dataSet / dataSharingInfo offsets to
 * gWihWork, tail calls a thumb function) is why the extent runs long.
 */
BOOL DWCi_MOV_WH_SendData(int data, u16 size, int userCallback);
/* extent: existing matched 021793B8 follows the 36-byte leaf. */
int WIH_GetSharedDataAdr(u16 aid);
/*
 * Calls the arm9 function at 0x020902D8 with the data-sharing info and the
 * data set of the work block behind gWihWork; result 7 or 5 counts as
 * failure without the error setter, other nonzero results call WIH_SetError
 * and fail, zero succeeds.
 */
BOOL WIH_StepDS(int sendData);
/*
 * lever: final counter store uses unsigned address arithmetic rather than
 * pointer arithmetic, so its offset is reloaded independently of the flag.
 * stand-in: scanWait is read and written as (u8 *)gWihWork + 0x1EBE here; the
 * field form folds the address into one value and the function shrinks by 4 bytes.
 */
void WIH_UpdateScanTimer(void);
/* return-chain: 0209028C result is passed to 0217814C. */
void DWCi_MOV_WH_StateInEndKeyShare(void);
/*
 * The DWC copy of the NitroSDK demo wh.c's WH_Finalize (DWCi_MOV_WH_*),
 * returning BOOL and reading its state from the work block behind
 * gWihWork: sysState, connectMode, the data-sharing info, the lastError
 * latch and the endScanPending flag.
 */
BOOL WIH_Finalize(void);
int WIH_End(void (*callback)(int));
unsigned short WIH_GetOwnAid(void);
void WIH_SetJudgeScanFunc(unsigned judgeScanFunc);
/*
 * When the state word (sysState) of the work block behind gWihWork is 4 or
 * 5, forwards the arguments to the arm9 function at 0x02090CD4 with
 * (0, userGameInfo, size, ggid, tgid, 1) and the halfword arguments truncated.
 */
void WIH_SetBeaconGameInfo(int userGameInfo, int size, int ggid, int tgid);
unsigned short WIH_GetBeaconSendCount(void);
void WIH_SetConnectCallback(unsigned connectCallback);
/*
 * Recursive MATCH unblocker: the unlabelled ov014 setter that WIH_DWC_Delete
 * (+001A) and WIH_DWC_Create (+0056) call: store the callback into
 * beaconFoundCallback of the object behind the pointer at gWihWork.
 */
void WIH_SetBeaconFoundCallback(u32 beaconFoundCallback);
void WIH_SetScanWaitFrames(u16 scanWaitFrames);
extern WihWork *gWihWork;
extern char sWihFileName[];
extern char sWihAssertText[];

void WIH_ChangeSysState(int state)
{
    gWihWork->sysState = state;
}

void WIH_SetError(int error)
{
    if ((unsigned)(gWihWork->sysState - 9) > 1)
        gWihWork->lastError = error;
}

int WIH_StateInSetParentParam(void)
{
    int result;
    WIH_ChangeSysState(3);
    result = WM_SetParentParameter(WIH_StateOutSetParentParam, gWihWork);
    if (result != 2) {
        WIH_SetError(result);
        WIH_ChangeSysState(9);
        return 0;
    }
    return 1;
}

void WIH_StateOutSetParentParam(WMCallback *arg)
{
    int result = arg->errcode;
    if (result != 0) {
        WIH_SetError(result);
        WIH_ChangeSysState(9);
        return;
    }
    if (WIH_StateInStartParent() == 0)
        WIH_ChangeSysState(9);
}

int WIH_StateInStartParent(void)
{
    int result;

    if ((u32)(gWihWork->sysState - 4) <= 1)
        return 1;
    result = WM_StartParent(WIH_StateOutStartParent);
    if (result != 2) {
        WIH_SetError(result);
        return 0;
    }
    gWihWork->ownAid = 0;
    gWihWork->aidBitmap = 1;
    return 1;
}

void WIH_StateOutStartParent(WMStartParentCallback *arg)
{
    int accepted = 1;
    u16 aidMask = 1 << arg->aid;
    WihSlotCallback slotCallback;
    int result;

    if (arg->errcode != 0) {
        WIH_SetError(arg->errcode);
        WIH_ChangeSysState(9);
        return;
    }
    switch (arg->state) {
    case 2:
        gWihWork->beaconSendCount += 1;
        break;
    case 7:
        if (gWihWork->judgeAcceptFunc != 0)
            accepted = gWihWork->judgeAcceptFunc(arg, GFL_NET_GetUserArg());
        if (accepted == 0) {
            result = WM_Disconnect(0, arg->aid);
            if (result != 2) {
                WIH_SetError(result);
                WIH_ChangeSysState(9);
            }
        } else {
            gWihWork->aidBitmap |= aidMask;
            slotCallback = gWihWork->connectCallback;
            if (slotCallback != 0)
                slotCallback(arg->aid);
        }
        break;
    case 9:
    case 0x1A:
        if (gWihWork->aidBitmap & (1 << arg->aid)) {
            gWihWork->aidBitmap &= ~aidMask;
            slotCallback = gWihWork->disconnectCallback;
            if (slotCallback != 0)
                slotCallback(arg->aid);
            NET_WHPIPE_OnChildDisconnected();
            GFL_NET_HANDLE_RemoveHandle(arg->aid);
            GFL_NET_HANDLE_RequestNegotiation(arg->aid);
        }
        break;
    case 0:
        if (WIH_StateInStartParentMP() == 0)
            WIH_ChangeSysState(9);
        break;
    }
}

BOOL WIH_StateInStartParentMP(void)
{
    int result;
    u16 mpFreq;

    if (gWihWork->sysState == 4 || gWihWork->sysState == 5)
        return 1;

    WIH_ChangeSysState(4);

    WM_GetMPReceiveBufferSize();
    WM_GetMPSendBufferSize();

    if (gWihWork->recvBuf != 0) {
        GFL_NET_FreeAligned(gWihWork->recvBuf);
        GFL_NET_FreeAligned(gWihWork->sendBuf);
    }

    gWihWork->recvBufSize = WM_GetMPReceiveBufferSize();
    gWihWork->sendBufSize = WM_GetMPSendBufferSize();

    gWihWork->recvBuf =
        GFL_NET_AllocAligned(gWihWork->heapId, gWihWork->recvBufSize + 0x20, sWihFileName, 0x4A7);
    gWihWork->sendBuf =
        GFL_NET_AllocAligned(gWihWork->heapId, gWihWork->sendBufSize + 0x20, sWihFileName, 0x4A8);

    mpFreq = (GFL_NET_GetGameKind() == 2) ? 1 : 2;

    result = WM_StartMP((void (*)(void *))WIH_StateOutStartParentMP,
                        gWihWork->recvBuf,
                        (u16)gWihWork->recvBufSize,
                        gWihWork->sendBuf,
                        (u16)gWihWork->sendBufSize,
                        mpFreq);
    if (result != 2) {
        WIH_SetError(result);
        return 0;
    }
    return 1;
}

void WIH_StateOutStartParentMP(WMStartMPCallback *arg)
{
    u16 errcode = arg->errcode;
    u16 aidBitmap;
    u32 myAid;
    u32 isParent;
    u32 aidCount;
    int result;
    if (errcode != 0) {
        WIH_SetError(errcode);
        WIH_ChangeSysState(9);
        return;
    }
    switch (arg->state) {
    case 10:
        if (gWihWork->connectMode == 4) {
            myAid = GFL_NET_GetChildSendSize();
            aidCount = GFL_NET_GetMaxConnectNum() - 1;
            aidBitmap = (1 << (aidCount + 1)) - 1;
            isParent = 1;
            if (GFL_NET_GetGameKind() == 2)
                isParent = 0;
            result = WM_StartDataSharing(gWihWork->dataSharingInfo, 13, aidBitmap, myAid, isParent);
            if (result != 0) {
                WIH_SetError(result);
                WIH_ChangeSysState(9);
                return;
            }
            WIH_ChangeSysState(5);
            return;
        }
        WIH_ChangeSysState(4);
        break;
    case 11:
    case 12:
    case 13:
        break;
    }
}

int WIH_StateInEndParentMP(void)
{
    int result;
    WIH_ChangeSysState(3);
    result = WM_EndMP(WIH_StateOutEndParentMP);
    if (result != 2) {
        WIH_SetError(result);
        return 0;
    }
    return 1;
}

void WIH_StateOutEndParentMP(WMCallback *arg)
{
    int result = arg->errcode;
    if (result != 0) {
        WIH_SetError(result);
        DWCi_MOV_WH_StateInEndKeyShare();
        return;
    }
    if (DWCi_MOV_WH_StateInEndParent() == 0)
        DWCi_MOV_WH_StateInEndKeyShare();
}

int DWCi_MOV_WH_StateInEndParent(void)
{
    int result = WM_EndParent((void *)DWCi_MOV_WH_StateOutEndParent);
    if (result != 2) {
        WIH_SetError(result);
        return 0;
    }
    return 1;
}

static void DWCi_MOV_WH_StateOutEndParent(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != 0) {
        WIH_SetError(cb->errcode);
        return;
    }
    WIH_ChangeSysState(1);
}

int DWCi_MOV_WH_ChildConnectAuto(u32 mode, const u16 *macAddr, u32 channel)
{
    WIH_ChangeSysState(2);
    if (macAddr != 0) {
        gWihWork->scanParam.bssid[2] = macAddr[2];
        gWihWork->scanParam.bssid[1] = macAddr[1];
        gWihWork->scanParam.bssid[0] = macAddr[0];
    } else {
        MI_CpuFill8(gWihWork->scanParam.bssid, 0xff, 6);
    }
    gWihWork->connectMode = mode;
    gWihWork->judgeScanFunc = 0;
    gWihWork->fixedScanChannel = channel;
    gWihWork->scanParam.channelList = 1;
    gWihWork->autoConnect = 1;
    if (DWCi_MOV_WH_StateInStartScan() == 0) {
        WIH_ChangeSysState(9);
        return 0;
    }
    return 1;
}

int DWCi_MOV_WH_StartScan(u32 judgeScanFunc, u16 *macAddr, u32 channel)
{
    WIH_ChangeSysState(2);
    gWihWork->judgeScanFunc = (WihJudgeScanFunc)judgeScanFunc;
    gWihWork->fixedScanChannel = channel;
    gWihWork->scanParam.channelList = 1;
    gWihWork->autoConnect = 0;
    gWihWork->scanCount = 0;
    if (macAddr != 0) {
        gWihWork->scanParam.bssid[2] = macAddr[2];
        gWihWork->scanParam.bssid[1] = macAddr[1];
        gWihWork->scanParam.bssid[0] = macAddr[0];
    } else {
        MI_CpuFill8(gWihWork->scanParam.bssid, 0xff, 6);
    }
    if (DWCi_MOV_WH_StateInStartScan() == 0) {
        WIH_ChangeSysState(9);
        return 0;
    }
    return 1;
}

BOOL DWCi_MOV_WH_StateInStartScan(void)
{
    int result;
    u16 allowedChannels;
    WihWork *work;

    allowedChannels = WM_GetAllowedChannel();
    if (allowedChannels == 0x8000) {
        WIH_SetError(3);
        return 0;
    }
    if (allowedChannels == 0) {
        WIH_SetError(0x16);
        return 0;
    }
    work = gWihWork;
    if (work->fixedScanChannel == 0) {
        int bit;
        u32 channel = work->scanParam.channelList;
        for (bit = 0; bit < 32; bit++) {
            if (channel & 1)
                break;
            channel >>= 1;
        }
        channel = bit + 1;
        while (1) {
            channel++;
            if (channel > 16)
                channel = 1;
            if (allowedChannels & (1 << (channel - 1)))
                break;
        }
        work->scanParam.channelList = (u16)(1 << (channel - 1));
    } else {
        work->scanParam.channelList = (u16)(1 << (work->fixedScanChannel - 1));
    }
    gWihWork->scanParam.maxChannelTime = WM_GetDispersionScanPeriod();
    gWihWork->scanParam.scanBuf = gWihWork->scanBuf;
    gWihWork->scanParam.scanBufSize = 0x400;
    gWihWork->scanParam.scanType = 1;
    gWihWork->scanParam.ssidLength = 0;
    result = WM_StartScanEx(DWCi_MOV_WH_StateOutStartScan, &gWihWork->scanParam);
    if (result != 2) {
        WIH_SetError(result);
        return 0;
    }
    return 1;
}

void WIH_SetScanTarget(u16 channel, void *macAddr)
{
    gWihWork->fixedScanChannel = channel;
    MI_CpuCopy8(macAddr, gWihWork->scanParam.bssid, 6);
}

int WIH_IsMatchingParent(WMBssDesc *bssDesc)
{
    u32 gameInfoLength = bssDesc->gameInfoLength;
    if (gameInfoLength < 0x10 || gameInfoLength > 0x80
        || gameInfoLength != (u32)bssDesc->userGameInfoLength + 0x10
        || bssDesc->gameInfoMagic != 1 || gameInfoLength < 8
        || bssDesc->ggid != gWihWork->parentParam.ggid)
        return 0;
    if ((bssDesc->attribute & 3) == 1)
        return 1;
    return 0;
}

/*
 * The WM_StartScanEx callback that DWCi_MOV_WH_StateInStartScan installs (the DWC copy of
 * the NitroSDK demo wh.c's scan callback).  Each found BSS is copied to
 * scanBssDesc of the work block and offered to the hooks beaconFoundCallback
 * and judgeScanFunc.
 */
void DWCi_MOV_WH_StateOutStartScan(void *arg)
{
    WMStartScanExCallback *cb = arg;
    u16 state = cb->state;
    int found;
    int i;
    WihWork *work;

    gWihWork->scanCount += 1;
    gWihWork->scanWait = 0;
    if (cb->errcode != 0) {
        WIH_SetError(cb->errcode);
        WIH_ChangeSysState(9);
        return;
    }
    if (gWihWork->sysState != 2) {
        gWihWork->autoConnect = 0;
        if (DWCi_MOV_WH_StateInEndScan() == 0)
            WIH_ChangeSysState(9);
        return;
    }
    gWihWork->scanWait = gWihWork->scanWaitFrames;
    switch (state) {
    case 4:
        WIH_DWC_Dummy();
        return;
    case 5:
        if (cb->bssDescCount != 0)
            DC_InvalidateRange(gWihWork->scanBuf, 0x400);
        found = 0;
        for (i = 0; i < cb->bssDescCount; i++) {
            work = gWihWork;
            MI_CpuCopy8(cb->bssDesc[i], &work->scanBssDesc, 0xC0);
            WIH_DWC_RequestAlertLevel((u8)cb->linkLevel[i]);
            if (gWihWork->beaconFoundCallback != 0)
                gWihWork->beaconFoundCallback(&work->scanBssDesc, GFL_NET_GetUserArg(),
                                                cb->linkLevel[i]);
            if (WIH_IsMatchingParent(&work->scanBssDesc) != 0) {
                if (gWihWork->judgeScanFunc == 0)
                    func_02034714(sWihAssertText, 0, sWihAssertText);
                if (gWihWork->judgeScanFunc(&work->scanBssDesc) != 0)
                    found = 1;
            }
        }
        if (gWihWork->autoConnect != 0 && found != 0) {
            gWihWork->scanWait = 0;
            if (DWCi_MOV_WH_StateInEndScan() == 0)
                WIH_ChangeSysState(9);
        }
        break;
    }
}

int DWCi_MOV_WH_EndScan(void)
{
    int irqState;
    int stopped = 0;
    irqState = OS_DisableInterrupts();
    if (gWihWork->sysState == 2) {
        if (gWihWork->scanWait != 0) {
            if (DWCi_MOV_WH_StateInStartScan() == 0)
                WIH_ChangeSysState(9);
        }
        gWihWork->scanWait = -1;
        gWihWork->autoConnect = 0;
        stopped = 1;
        gWihWork->endScanPending = 1;
        WIH_ChangeSysState(3);
    }
    OS_RestoreInterrupts(irqState);
    return stopped;
}

static int DWCi_MOV_WH_StateInEndScan(void)
{
    int result;
    result = WM_EndScan((void *)DWCi_MOV_WH_StateOutEndScan);
    if (result != 2) {
        WIH_SetError(result);
        return 0;
    }
    return 1;
}

void DWCi_MOV_WH_StateOutEndScan(WMCallback *arg)
{
    WihWork *work;
    gWihWork->endScanPending = 0;
    if (arg->errcode != 0) {
        WIH_SetError(arg->errcode);
        return;
    }
    WIH_ChangeSysState(1);
    work = gWihWork;
    if (work->autoConnect != 0) {
        work->autoConnect = 0;
        if (DWCi_MOV_WH_StateInStartChild() == 0)
            WIH_ChangeSysState(9);
    }
}

int DWCi_MOV_WH_StateInStartChild(void)
{
    int result;
    if ((u32)(gWihWork->sysState - 4) <= 1)
        return 1;
    WIH_ChangeSysState(3);
    result = WM_StartConnectEx((void *)DWCi_MOV_WH_StateOutStartChild, &gWihWork->scanBssDesc, gWihWork->connectSsid, 1, 0);
    if (result != 2) {
        WIH_SetError(result);
        return 0;
    }
    return 1;
}

void DWCi_MOV_WH_StateOutStartChild(WMStartConnectCallback *arg)
{
    u32 value;
    WihSlotCallback slotCallback;
    if (arg->errcode != 0) {
        WIH_SetError(arg->errcode);
        value = arg->errcode;
        if (value == 0xC) {
            WIH_ChangeSysState(9);
            return;
        }
        if (value == 0xB) {
            WIH_ChangeSysState(9);
            return;
        }
        if (value == 1) {
            WIH_ChangeSysState(8);
            return;
        }
        WIH_ChangeSysState(9);
        return;
    }
    value = arg->state;
    if (value == 8)
        return;
    if (value == 7) {
        WIH_ChangeSysState(4);
        if (DWCi_MOV_WH_StateInStartChildMP() == 0) {
            WIH_ChangeSysState(3);
            return;
        }
        gWihWork->ownAid = arg->aid;
        slotCallback = gWihWork->connectCallback;
        if (slotCallback != 0)
            slotCallback(arg->aid);
        return;
    }
    if (value == 6)
        return;
    if (value == 9) {
        WIH_SetError(0x14);
        WIH_ChangeSysState(9);
        return;
    }
    if (value == 0x1A)
        return;
    WIH_ChangeSysState(9);
}

/*
 * The DWC copy of the NitroSDK demo wh.c's MP start (DWCi_MOV_WH_*): frees
 * and re-allocates the MP receive and send buffers (sizes from
 * WM_GetMP{Receive,Send}BufferSize, kept in recvBufSize and sendBufSize of
 * the work block behind gWihWork), then calls WM_StartMP with callback
 * DWCi_MOV_WH_StateOutStartChildMP; anything but WM_ERRCODE_OPERATING (2) goes to the error
 * setter WIH_SetError.
 */
BOOL DWCi_MOV_WH_StateInStartChildMP(void)
{
    int result;
    u16 mpFreq;

    WM_GetMPReceiveBufferSize();
    WM_GetMPSendBufferSize();

    if (gWihWork->recvBuf != 0) {
        GFL_NET_FreeAligned(gWihWork->recvBuf);
        GFL_NET_FreeAligned(gWihWork->sendBuf);
    }

    gWihWork->recvBufSize = WM_GetMPReceiveBufferSize();
    gWihWork->sendBufSize = WM_GetMPSendBufferSize();

    gWihWork->recvBuf =
        GFL_NET_AllocAligned(gWihWork->heapId, gWihWork->recvBufSize + 0x20, sWihFileName, 0x7FA);
    gWihWork->sendBuf =
        GFL_NET_AllocAligned(gWihWork->heapId, gWihWork->sendBufSize + 0x20, sWihFileName, 0x7FB);

    mpFreq = (GFL_NET_GetGameKind() == 2) ? 1 : 2;

    result = WM_StartMP((void (*)(void *))DWCi_MOV_WH_StateOutStartChildMP,
                        gWihWork->recvBuf,
                        (u16)gWihWork->recvBufSize,
                        gWihWork->sendBuf,
                        (u16)gWihWork->sendBufSize,
                        mpFreq);
    if (result != 2) {
        WIH_SetError(result);
        return 0;
    }
    return 1;
}

void DWCi_MOV_WH_StateOutStartChildMP(WMStartMPCallback *arg)
{
    u32 errcode = arg->errcode;
    u32 aidBitmap;
    u32 myAid;
    int isParent;

    if (errcode != 0) {
        if (errcode == 0xF || errcode == 9 || errcode == 0xD)
            return;
        WIH_SetError(errcode);
        WIH_ChangeSysState(9);
        return;
    }
    switch (arg->state) {
    case 0xA:
        if (gWihWork->connectMode == 5) {
            int result;
            int aidCount;
            myAid = GFL_NET_GetChildSendSize();
            aidCount = GFL_NET_GetMaxConnectNum() - 1;
            aidBitmap = (u16)((1 << (aidCount + 1)) - 1);
            isParent = 1;
            if (GFL_NET_GetGameKind() == 2)
                isParent = 0;
            result = WM_StartDataSharing(gWihWork->dataSharingInfo, 0xD, aidBitmap, (u16)myAid, isParent);
            if (result != 0) {
                WIH_SetError(result);
                WIH_Finalize();
                return;
            }
            WIH_ChangeSysState(5);
            return;
        }
        WIH_ChangeSysState(4);
        break;
    case 0xB:
    case 0xC:
    case 0xD:
        break;
    }
}

int WIH_StateInEndChildMP(void)
{
    int result;
    WIH_ChangeSysState(3);
    result = WM_EndMP(WIH_StateOutEndChildMP);
    if (result != 2) {
        WIH_SetError(result);
        return 0;
    }
    return 1;
}

void WIH_StateOutEndChildMP(WMCallback *arg)
{
    int result = arg->errcode;
    if (result != 0) {
        WIH_SetError(result);
        WIH_Finalize();
        return;
    }
    if (WIH_StateInEndChild() == 0)
        WIH_ChangeSysState(9);
}

int WIH_StateInEndChild(void)
{
    int result;
    int failed = 0;
    WIH_ChangeSysState(3);
    result = WM_Disconnect(DWCi_MOV_WH_StateOutEndChild, 0);
    if (result != 2) {
        WIH_SetError(result);
        DWCi_MOV_WH_StateInEndKeyShare();
        return failed;
    }
    return 1;
}

static void DWCi_MOV_WH_StateOutEndChild(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode != 0) {
        WIH_SetError(cb->errcode);
        return;
    }
    WIH_ChangeSysState(1);
}

int WIH_StateInReset(void)
{
    int result;
    WIH_ChangeSysState(3);
    result = WM_Reset(WIH_StateOutReset);
    if (result != 2) {
        WIH_SetError(result);
        return 0;
    }
    return 1;
}

void WIH_StateOutReset(WMCallback *arg)
{
    if (arg->errcode != 0) {
        WIH_ChangeSysState(9);
        WIH_SetError(arg->errcode);
    } else {
        WIH_ChangeSysState(1);
    }
}

int DWCi_MOV_WH_StateInSetMPData(u32 data, u32 size, u32 userCallback)
{
    DWCi_ScreenDC_FlushRange(gWihWork->sendBuf, gWihWork->sendBufSize);
    if (WM_SetMPDataToPortEx((void *)WIH_StateOutSetMPData, userCallback, data, size, 0xFFFF, 0xE, 2) == 2)
        return 1;
    return 0;
}

/* extent: two zero alignment bytes at 02178D9A precede labelled 02178D9C. */
void WIH_StateOutSetMPData(WMPortSendCallback *arg)
{
    int errcode = arg->errcode;
    if (errcode != 0 && errcode != 15) {
        WIH_SetError(errcode);
    } else {
        WihResultCallback userCallback = arg->userCallback;
        if (userCallback != 0)
            userCallback(errcode == 0);
    }
}

void DWCi_MOV_WH_PortReceiveCallback(WMPortRecvCallback *arg)
{
    WihRecvCallback recvCallback;
    if (arg->errcode != 0) {
        WIH_SetError(arg->errcode);
        return;
    }
    recvCallback = gWihWork->recvCallback;
    if (recvCallback != 0) {
        if (arg->state == 0x15)
            recvCallback(arg->aid, arg->data, arg->length);
        else if (arg->state == 9)
            recvCallback(arg->aid, 0, 0);
    }
}

void WIH_StateOutEnd(WMCallback *arg)
{
    WihResultCallback callback = gWihWork->initCallback;
    if (callback != 0)
        callback(arg->errcode == 0 ? 1 : 0);
    if (arg->errcode != 0)
        WIH_ChangeSysState(10);
    else
        WIH_ChangeSysState(0);
}

void WIH_SetGgid(u32 ggid)
{
    gWihWork->parentParam.ggid = ggid;
}

void DWCi_MOV_WH_SetUserGameInfo(void *userGameInfo, unsigned short length)
{
    gWihWork->parentParam.userGameInfo = userGameInfo;
    gWihWork->parentParam.userGameInfoLength = length;
}

u16 WIH_GetBitmap(void)
{
    return gWihWork->aidBitmap;
}

int WIH_GetSysState(void)
{
    if (gWihWork == 0)
        return 0;
    return gWihWork->sysState;
}

int DWCi_MOV_WH_GetLastError(void)
{
    if (gWihWork != 0)
        return gWihWork->lastError;
    return 0;
}

int WIH_StartMeasureChannel(void)
{
    u16 dateTime[3];
    int result;
    int ok;
    u32 vblankCount;

    OS_GetMacAddress(dateTime);
    /* the VBlank counter in the shared main memory area */
    vblankCount = *(volatile u32 *)0x02FFFC3C;
    gWihWork->randomSeed = dateTime[2] + (dateTime[1] + (dateTime[0] + vblankCount));
    gWihWork->randomSeed = gWihWork->randomSeed * 0x10DCD + 0x3039;
    gWihWork->measuredChannel = 0;
    gWihWork->minBusyRatio = 0x65;
    WIH_ChangeSysState(3);
    ok = 1;
    result = WIH_StateInMeasureChannel(1);
    if (result == 0x18) {
        WIH_SetError(0x18);
        WIH_ChangeSysState(9);
        return 0;
    }
    if (result != 2) {
        WIH_SetError(result);
        WIH_ChangeSysState(9);
        return 0;
    }
    return ok;
}

int WIH_StateInMeasureChannel(u16 channel)
{
    u32 allowedChannels = WM_GetAllowedChannel();
    if (allowedChannels == 0x8000) {
        WIH_SetError(3);
        WIH_ChangeSysState(9);
        return 3;
    }
    if (allowedChannels == 0) {
        WIH_SetError(0x16);
        WIH_ChangeSysState(9);
        return 0x18;
    }
    if (!((1 << (channel - 1)) & allowedChannels)) {
        do {
            channel = channel + 1;
            if (channel > 0x10)
                return 0x18;
        } while (!((1 << (channel - 1)) & allowedChannels));
    }
    return (u16)WHi_MeasureChannel((void *)WIH_StateOutMeasureChannel, channel);
}

#pragma opt_dead_assignments off
void WIH_StateOutMeasureChannel(const WMMeasureChannelCallback *arg)
{
    u32 channel;
    u32 busyRatio;
    u32 value;
    int result;
    if (arg->errcode != 0) {
        WIH_SetError(arg->errcode);
        WIH_ChangeSysState(9);
        return;
    }
    channel = arg->channel;
    busyRatio = arg->ccaBusyRatio;
    value = gWihWork->minBusyRatio;
    if (value > busyRatio) {
        gWihWork->minBusyRatio = busyRatio;
        value = 1 << (channel - 1);
        gWihWork->bestChannelBitmap = value;
    } else if (value == busyRatio) {
        value = (u16)(1 << (channel - 1)) | gWihWork->bestChannelBitmap;
        gWihWork->bestChannelBitmap = value;
    }
    result = WIH_StateInMeasureChannel(channel + 1);
    if (result == 0x18 && gWihWork->sysState != 9) {
        WIH_ChangeSysState(7);
        return;
    }
    if (result != 2)
        WIH_ChangeSysState(9);
}
#pragma opt_dead_assignments reset

int WHi_MeasureChannel(void *callback, unsigned short channel)
{
    return WM_MeasureChannel(callback, 3, 0x11, channel, 0x1E);
}

u16 WIH_GetMeasureChannel(void)
{
    WIH_ChangeSysState(1);
    gWihWork->measuredChannel = WIH_PickRandomChannel(gWihWork->bestChannelBitmap);
    return gWihWork->measuredChannel;
}

int WIH_PickRandomChannel(u16 channelBitmap)
{
    s16 lastChannel = 0;
    s16 i;
    u16 count = 0;
    u32 pick;
    for (i = 0; i < 16; i++) {
        if (channelBitmap & (1 << i)) {
            lastChannel = i + 1;
            count++;
        }
    }
    if (count > 1) {
        s16 j;
        gWihWork->randomSeed = gWihWork->randomSeed * 0x10DCD + 0x3039;
        pick = (u32)(count * (u8)gWihWork->randomSeed) << 8 >> 16;
        for (j = 0; j < 16; j++) {
            if (channelBitmap & 1) {
                if (pick == 0)
                    return (s16)(j + 1);
                pick = (u16)(pick - 1);
            }
            channelBitmap = channelBitmap >> 1;
        }
        return 0;
    }
    return lastChannel;
}

BOOL WIH_Initialize(u32 heapId, int unused, int listening)
{
    BOOL ok;
    if (gWihWork != 0)
        return 0;
    gWihWork = GFL_NET_AllocAligned(heapId, 0x1F00, sWihFileName, 0xC33);
    MI_CpuFill8(gWihWork, 0, 0x1EE0);
    gWihWork->scanWaitFrames = 1;
    gWihWork->aidBitmap = 1;
    gWihWork->lastError = 0;
    gWihWork->heapId = heapId;
    ok = 1;
    if (!WIH_StateInInitialize(unused, listening))
        ok = 0;
    return ok;
}

void WIH_FreeWork(void)
{
    if (gWihWork != 0) {
        GFL_NET_FreeAligned(gWihWork->recvBuf);
        GFL_NET_FreeAligned(gWihWork->sendBuf);
        GFL_NET_FreeAligned(gWihWork);
        gWihWork = 0;
    }
}

void WIH_IndicateHandler(WMCallback *arg)
{
    if (arg->errcode == 8) {
        WIH_ChangeSysState(9);
        WIH_SetError(25);
    }
}

BOOL WIH_StateInInitialize(int unused, int listening)
{
    int result;
    WIH_ChangeSysState(3);
    if (listening == 0)
        result = WM_Initialize(gWihWork->wmSystemBuf, (void (*)(void *))WIH_StateOutInitialize, 2);
    else
        result = WM_InitializeForListening(gWihWork->wmSystemBuf, (void (*)(void *))WIH_StateOutInitialize, 2, 0);
    if (result != 2) {
        WIH_SetError(result);
        WIH_ChangeSysState(10);
        return 0;
    }
    return 1;
}

void DWCi_MOV_WH_StateOutSetLifeTime(void)
{
    WIH_ChangeSysState(1);
}

/*
 * WM_Initialize completion callback of the DWC WH copy: on an error result,
 * or when WIH_IndicateHandler cannot be installed as the indication callback, it
 * sets the error state (10) and calls the user callback at initCallback with
 * 0; otherwise it sets state 1, calls WM_SetLifeTime with the unlabelled leaf
 * DWCi_MOV_WH_StateOutSetLifeTime and calls the user callback with 1.
 */
void WIH_StateOutInitialize(WMCallback *arg)
{
    WihResultCallback callback;
    int result;
    if (arg->errcode != 0) {
        WIH_SetError(arg->errcode);
        WIH_ChangeSysState(10);
        callback = gWihWork->initCallback;
        if (callback != 0)
            callback(0);
        return;
    }
    result = WM_SetIndCallback((void (*)(void))WIH_IndicateHandler);
    if (result != 0) {
        WIH_SetError(result);
        WIH_ChangeSysState(10);
        callback = gWihWork->initCallback;
        if (callback != 0)
            callback(0);
        return;
    }
    WIH_ChangeSysState(1);
    WM_SetLifeTime(DWCi_MOV_WH_StateOutSetLifeTime, 0xFFFF, 0x28, 5, 0x28);
    callback = gWihWork->initCallback;
    if (callback != 0)
        callback(1);
}

BOOL WIH_ParentConnect(int mode, u16 tgid, int channel, u16 maxEntry)
{
    gWihWork->beaconSendCount = 0;
    gWihWork->connectMode = mode;
    WIH_ChangeSysState(3);
    gWihWork->parentParam.tgid = tgid;
    gWihWork->parentParam.channel = channel;
    gWihWork->parentParam.beaconPeriod = WM_GetDispersionBeaconPeriod();
    if (GFL_NET_GetParentSendSize() != 0) {
        gWihWork->parentParam.parentMaxSize = GFL_NET_GetParentSendSize();
    } else {
        gWihWork->parentParam.parentMaxSize = GFL_NET_GetChildSendSize() * GFL_NET_GetMaxConnectNum() + 4;
    }
    gWihWork->parentParam.childMaxSize = GFL_NET_GetChildSendSize();
    gWihWork->parentParam.maxEntry = maxEntry;
    gWihWork->parentParam.cswitch = 0;
    gWihWork->parentParam.multiBootFlag = 0;
    gWihWork->parentParam.entryFlag = 1;
    gWihWork->parentParam.keySharing = (mode == 2);
    if (mode == 0 || mode == 2 || mode == 4)
        return WIH_StateInSetParentParam();
    return 0;
}

void WIH_SetJudgeAcceptFunc(void *judgeAcceptFunc)
{
    gWihWork->judgeAcceptFunc = (WihJudgeAcceptFunc)judgeAcceptFunc;
}

void DWCi_MOV_WH_SetReceiver(void *recvCallback)
{
    gWihWork->recvCallback = (WihRecvCallback)recvCallback;
    if (WM_SetPortCallback(14, DWCi_MOV_WH_PortReceiveCallback, 0) != 0)
        WIH_ChangeSysState(9);
}

BOOL DWCi_MOV_WH_SendData(int data, u16 size, int userCallback)
{
    if (WIH_GetOwnAid() == 0 && (WIH_GetBitmap() & 0xFE) == 0)
        return 0;
    return DWCi_MOV_WH_StateInSetMPData(data, size, userCallback);
}

int WIH_GetSharedDataAdr(u16 aid)
{
    return WM_GetSharedDataAddress(gWihWork->dataSharingInfo, gWihWork->dataSet, aid);
}

BOOL WIH_StepDS(int sendData)
{
    int result;
    result = WM_StepDataSharing((struct WMDataSharingInfo *)gWihWork->dataSharingInfo, (const u16 *)sendData, (struct WMDataSet *)gWihWork->dataSet);
    if (result == 7)
        return 0;
    if (result == 5)
        return 0;
    if (result != 0) {
        WIH_SetError(result);
        return 0;
    }
    return 1;
}

void WIH_UpdateScanTimer(void)
{
    if (gWihWork != 0 && *(s16 *)((u8 *)gWihWork + 0x1EBE) > 0) {
        *(s16 *)((u8 *)gWihWork + 0x1EBE) =
            (gWihWork->sysState != 2) ? 0 : *(s16 *)((u8 *)gWihWork + 0x1EBE) - 1;
        if (*(s16 *)((u8 *)gWihWork + 0x1EBE) == 0) {
            if (gWihWork->sysState == 2 && gWihWork->scanPaused == 0) {
                if (DWCi_MOV_WH_StateInStartScan() == 0)
                    WIH_ChangeSysState(9);
            } else {
                *(s16 *)((unsigned int)gWihWork + 0x1EBE) = 1;
            }
        }
    }
}

void DWCi_MOV_WH_StateInEndKeyShare(void)
{
    int error;
    if (gWihWork->sysState == 5) {
        error = WM_EndDataSharing(gWihWork->dataSharingInfo);
        if (error != 0)
            WIH_SetError(error);
    }
    if (WIH_StateInReset() == 0)
        WIH_ChangeSysState(10);
}

BOOL WIH_Finalize(void)
{
    int state;
    if (gWihWork == 0 || (state = gWihWork->sysState) == 1)
        return 1;
    if (gWihWork->lastError != 0) {
        DWCi_MOV_WH_StateInEndKeyShare();
        return 1;
    }
    if (state == 3)
        return 0;
    if (state == 2) {
        if (!DWCi_MOV_WH_EndScan())
            DWCi_MOV_WH_StateInEndKeyShare();
        return 1;
    }
    if (gWihWork->endScanPending != 0)
        return 1;
    if (state != 5 && state != 4) {
        WIH_ChangeSysState(3);
        DWCi_MOV_WH_StateInEndKeyShare();
        return 1;
    }
    WIH_ChangeSysState(3);
    switch (gWihWork->connectMode) {
    case 5:
        if (WM_EndDataSharing(gWihWork->dataSharingInfo) != 0) {
            DWCi_MOV_WH_StateInEndKeyShare();
            break;
        }
    case 1:
        if (!WIH_StateInEndChildMP())
            DWCi_MOV_WH_StateInEndKeyShare();
        break;
    case 2:
    case 3:
        break;
    case 4:
        if (WM_EndDataSharing(gWihWork->dataSharingInfo) != 0) {
            DWCi_MOV_WH_StateInEndKeyShare();
            break;
        }
    case 0:
        if (!WIH_StateInEndParentMP())
            DWCi_MOV_WH_StateInEndKeyShare();
        break;
    }
    return 1;
}

int WIH_End(void (*callback)(int))
{
    gWihWork->initCallback = callback;
    WIH_ChangeSysState(3);
    if (WM_End(WIH_StateOutEnd) != 2) {
        WIH_ChangeSysState(9);
        return 0;
    }
    return 1;
}

unsigned short WIH_GetOwnAid(void)
{
    if (gWihWork != 0)
        return gWihWork->ownAid;
    return 0;
}

void WIH_SetJudgeScanFunc(unsigned judgeScanFunc)
{
    gWihWork->judgeScanFunc = (WihJudgeScanFunc)judgeScanFunc;
}

void WIH_SetBeaconGameInfo(int userGameInfo, int size, int ggid, int tgid)
{
    if (gWihWork != 0 && (unsigned)(gWihWork->sysState - 4) <= 1)
        WM_SetGameInfo(0, userGameInfo, (u16)size, ggid, (u16)tgid, 1);
}

unsigned short WIH_GetBeaconSendCount(void)
{
    return gWihWork->beaconSendCount;
}

void WIH_SetConnectCallback(unsigned connectCallback)
{
    gWihWork->connectCallback = (WihSlotCallback)connectCallback;
}

void WIH_SetBeaconFoundCallback(u32 beaconFoundCallback)
{
    gWihWork->beaconFoundCallback = (WihBeaconFoundCallback)beaconFoundCallback;
}

void WIH_SetScanWaitFrames(u16 scanWaitFrames)
{
    gWihWork->scanWaitFrames = scanWaitFrames;
}
