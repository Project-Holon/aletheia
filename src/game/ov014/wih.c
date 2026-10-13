/*
 * file:     wih.c
 * unit:     yes
 * function: func_02178138, func_0217814C, func_02178168, func_02178198, func_021781BC, func_02178204, func_02178304, func_021783FC, func_021784AC, func_021784D0, func_021784F0, func_0217850C, DWCi_MOV_WH_ChildConnectAuto, DWCi_MOV_WH_StartScan, DWCi_MOV_WH_StateInStartScan, WIH_SetScanTarget, WIH_IsMatchingParent, DWCi_MOV_WH_StateOutStartScan, DWCi_MOV_WH_EndScan, func_02178964, DWCi_MOV_WH_StateOutEndScan, DWCi_MOV_WH_StateInStartChild, DWCi_MOV_WH_StateOutStartChild, DWCi_MOV_WH_StateInStartChildMP, DWCi_MOV_WH_StateOutStartChildMP, func_02178C50, func_02178C74, func_02178C98, func_02178CC4, func_02178CDC, func_02178D00, DWCi_MOV_WH_StateInSetMPData, func_02178D74, DWCi_MOV_WH_PortReceiveCallback, func_02178DE0, func_02178E1C, func_02178E28, func_02178E38, WIH_GetSysState, DWCi_MOV_WH_GetLastError, func_02178E84, func_02178F1C, func_02178F8C, func_02179010, func_02179024, WIH_PickRandomChannel, func_021790E4, WIH_FreeWork, func_02179188, func_021791A0, DWCi_MOV_WH_StateOutSetLifeTime, func_021791F8, func_02179288, func_02179328, DWCi_MOV_WH_SetReceiver, DWCi_MOV_WH_SendData, func_02179394, func_021793B8, WIH_UpdateScanTimer, DWCi_MOV_WH_StateInEndKeyShare, func_02179498, func_02179570, WIH_GetOwnAid, WIH_SetJudgeScanFunc, WIH_SetBeaconGameInfo, WIH_GetBeaconSendCount, WIH_SetConnectCallback, WIH_SetBeaconFoundCallback, WIH_SetScanWaitFrames
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
 *   func_020862F0  0x020862F0  arm
 *   func_02082D44  0x02082D44  arm
 *   g_021797A8 0x021797A8 data ov014 a4
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
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   WM_EndScan                     0x0208F808  arm
 *   WM_StartConnectEx  0x0208F84C  arm
 *   func_02178CC4 0x02178CC4 thumb ov014
 *   WM_Reset 0x0208F400 arm
 *   WM_SetMPDataToPortEx  0x0208FCB4  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_02179010  0x02179010  thumb  ov014
 *   func_0208EE60  0x0208EE60  arm
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
 * g_021797A8.
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
void func_020862F0(void *p, u32 n);
void func_02082D44(void *dst, void *src, u32 n);
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
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void func_02034714(const char *expr, u32 line, const char *file);
int func_02087988(void);
void func_0208799C(int irqState);
extern int WM_EndScan(void *callback);
int WM_StartConnectEx(void *callback, void *bssDesc, void *ssid, int powerSave, int authMode);
extern int WM_Reset(void *callback);
int WM_SetMPDataToPortEx(void *callback, u32 userCallback, u32 data, u32 size, u32 destBitmap, u32 port, u32 priority);
void func_02087C6C(u16 *p);
u16 func_0208EE60(void);
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
extern int WM_EndDataSharing(void *info);
extern int WM_End(void *callback);
extern void WM_SetGameInfo(int callback, int userGameInfo, u16 size, int ggid, u16 tgid, int attr);

/* functions of this file (and its ov014 neighbours) */
void NET_WHPIPE_OnChildDisconnected(void);
void func_02178138(int state);
void func_0217814C(int error);
int func_02178168(void);
void func_02178198(WMCallback *arg);
int func_021781BC(void);
void func_02178204(WMStartParentCallback *arg);
/*
 * Twin of DWCi_MOV_WH_StateInStartChildMP (the DWC copy of the NitroSDK wh.c MP start), with a
 * state guard in front: states 4 and 5 (sysState) already run MP, else the
 * state setter func_02178138(4) runs first, and the callback is
 * func_021783FC.
 */
BOOL func_02178304(void);
void func_021783FC(WMStartMPCallback *arg);
int func_021784AC(void);
void func_021784D0(WMCallback *arg);
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
 * WM_ERRCODE_OPERATING (2) goes to the error setter func_0217814C.
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
int func_02178C50(void);
void func_02178C74(WMCallback *arg);
int func_02178C98(void);
static void DWCi_MOV_WH_StateOutEndChild(void *arg);
int func_02178CDC(void);
void func_02178D00(WMCallback *arg);
int DWCi_MOV_WH_StateInSetMPData(u32 data, u32 size, u32 userCallback);
/* extent: two zero alignment bytes at 02178D9A precede labelled 02178D9C. */
void func_02178D74(WMPortSendCallback *arg);
void DWCi_MOV_WH_PortReceiveCallback(WMPortRecvCallback *arg);
void func_02178DE0(WMCallback *arg);
void func_02178E1C(u32 ggid);
void DWCi_MOV_WH_SetUserGameInfo(void *userGameInfo, unsigned short length);
u16 func_02178E38(void);
int WIH_GetSysState(void);
int DWCi_MOV_WH_GetLastError(void);
int func_02178E84(void);
int func_02178F1C(u16 channel);
/*
 * note: 2026-10-05 wave P16 lane E8: older draft was DIFF 101 B / 136 B because the
 * two arms kept separate copies of the u16 store. Per-function pragma
 * opt_dead_assignments off gives 132 B EXACT (also with plain literal offsets).
 * Without the pragma the same source stays 136 B. Callee types from matched
 * definitions: func_0217814C and func_02178138 void(int), func_02178F1C int(u16).
 */
void func_02178F8C(const WMMeasureChannelCallback *arg);
int WHi_MeasureChannel(void *callback, unsigned short channel);
u16 func_02179024(void);
int WIH_PickRandomChannel(u16 channelBitmap);
BOOL func_021790E4(u32 heapId, int unused, int listening);
void WIH_FreeWork(void);
/* extent: two zero alignment bytes at 0217919E precede labelled 021791A0. */
void func_02179188(WMCallback *arg);
/*
 * The DWC copy of WH_Initialize's WM start: WM_Initialize (0208F370) or, when
 * listening is set, WM_InitializeForListening (0208F380), on the WM system
 * buffer of the work block with completion callback func_021791F8.  Anything
 * but WM_ERRCODE_OPERATING goes to the error setter.  The unlabelled
 * follower at 021791EC (`movs r0,#1; bx` tail call to func_02178138) is why
 * the extent runs long.
 */
BOOL func_021791A0(int unused, int listening);
/*
 * Unlabelled leaf: sets state 1 by tail-calling func_02178138.  Used as the
 * callback of func_021791F8's call to WM_SetLifeTime.
 */
void DWCi_MOV_WH_StateOutSetLifeTime(void);
void func_021791F8(WMCallback *arg);
BOOL func_02179288(int mode, u16 tgid, int channel, u16 maxEntry);
void func_02179328(void *judgeAcceptFunc);
void DWCi_MOV_WH_SetReceiver(void *recvCallback);
/*
 * Guard wrapper: forwards to DWCi_MOV_WH_StateInSetMPData when WIH_GetOwnAid is nonzero or
 * one of bits 1-7 of func_02178E38 is set, else returns 0.  The unlabelled
 * follower at 02179394 (adds the block's dataSet / dataSharingInfo offsets to
 * g_021797A8, tail calls a thumb function) is why the extent runs long.
 */
BOOL DWCi_MOV_WH_SendData(int data, u16 size, int userCallback);
/* extent: existing matched 021793B8 follows the 36-byte leaf. */
int func_02179394(u16 aid);
/*
 * Calls the arm9 function at 0x020902D8 with the data-sharing info and the
 * data set of the work block behind g_021797A8; result 7 or 5 counts as
 * failure without the error setter, other nonzero results call func_0217814C
 * and fail, zero succeeds.
 */
BOOL func_021793B8(int sendData);
/*
 * lever: final counter store uses unsigned address arithmetic rather than
 * pointer arithmetic, so its offset is reloaded independently of the flag.
 * stand-in: scanWait is read and written as (u8 *)g_021797A8 + 0x1EBE here; the
 * field form folds the address into one value and the function shrinks by 4 bytes.
 */
void WIH_UpdateScanTimer(void);
/* return-chain: 0209028C result is passed to 0217814C. */
void DWCi_MOV_WH_StateInEndKeyShare(void);
/*
 * The DWC copy of the NitroSDK demo wh.c's WH_Finalize (DWCi_MOV_WH_*),
 * returning BOOL and reading its state from the work block behind
 * g_021797A8: sysState, connectMode, the data-sharing info, the lastError
 * latch and the endScanPending flag.
 */
BOOL func_02179498(void);
int func_02179570(void (*callback)(int));
unsigned short WIH_GetOwnAid(void);
void WIH_SetJudgeScanFunc(unsigned judgeScanFunc);
/*
 * When the state word (sysState) of the work block behind g_021797A8 is 4 or
 * 5, forwards the arguments to the arm9 function at 0x02090CD4 with
 * (0, userGameInfo, size, ggid, tgid, 1) and the halfword arguments truncated.
 */
void WIH_SetBeaconGameInfo(int userGameInfo, int size, int ggid, int tgid);
unsigned short WIH_GetBeaconSendCount(void);
void WIH_SetConnectCallback(unsigned connectCallback);
/*
 * Recursive MATCH unblocker: the unlabelled ov014 setter that WIH_DWC_Delete
 * (+001A) and WIH_DWC_Create (+0056) call: store the callback into
 * beaconFoundCallback of the object behind the pointer at g_021797A8.
 */
void WIH_SetBeaconFoundCallback(u32 beaconFoundCallback);
void WIH_SetScanWaitFrames(u16 scanWaitFrames);
extern WihWork *g_021797A8;
extern char sWihFileName[];
extern char sWihAssertText[];

void func_02178138(int state)
{
    g_021797A8->sysState = state;
}

void func_0217814C(int error)
{
    if ((unsigned)(g_021797A8->sysState - 9) > 1)
        g_021797A8->lastError = error;
}

int func_02178168(void)
{
    int result;
    func_02178138(3);
    result = WM_SetParentParameter(func_02178198, g_021797A8);
    if (result != 2) {
        func_0217814C(result);
        func_02178138(9);
        return 0;
    }
    return 1;
}

void func_02178198(WMCallback *arg)
{
    int result = arg->errcode;
    if (result != 0) {
        func_0217814C(result);
        func_02178138(9);
        return;
    }
    if (func_021781BC() == 0)
        func_02178138(9);
}

int func_021781BC(void)
{
    int result;

    if ((u32)(g_021797A8->sysState - 4) <= 1)
        return 1;
    result = WM_StartParent(func_02178204);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    g_021797A8->ownAid = 0;
    g_021797A8->aidBitmap = 1;
    return 1;
}

void func_02178204(WMStartParentCallback *arg)
{
    int accepted = 1;
    u16 aidMask = 1 << arg->aid;
    WihSlotCallback slotCallback;
    int result;

    if (arg->errcode != 0) {
        func_0217814C(arg->errcode);
        func_02178138(9);
        return;
    }
    switch (arg->state) {
    case 2:
        g_021797A8->beaconSendCount += 1;
        break;
    case 7:
        if (g_021797A8->judgeAcceptFunc != 0)
            accepted = g_021797A8->judgeAcceptFunc(arg, GFL_NET_GetUserArg());
        if (accepted == 0) {
            result = WM_Disconnect(0, arg->aid);
            if (result != 2) {
                func_0217814C(result);
                func_02178138(9);
            }
        } else {
            g_021797A8->aidBitmap |= aidMask;
            slotCallback = g_021797A8->connectCallback;
            if (slotCallback != 0)
                slotCallback(arg->aid);
        }
        break;
    case 9:
    case 0x1A:
        if (g_021797A8->aidBitmap & (1 << arg->aid)) {
            g_021797A8->aidBitmap &= ~aidMask;
            slotCallback = g_021797A8->disconnectCallback;
            if (slotCallback != 0)
                slotCallback(arg->aid);
            NET_WHPIPE_OnChildDisconnected();
            GFL_NET_HANDLE_RemoveHandle(arg->aid);
            GFL_NET_HANDLE_RequestNegotiation(arg->aid);
        }
        break;
    case 0:
        if (func_02178304() == 0)
            func_02178138(9);
        break;
    }
}

BOOL func_02178304(void)
{
    int result;
    u16 mpFreq;

    if (g_021797A8->sysState == 4 || g_021797A8->sysState == 5)
        return 1;

    func_02178138(4);

    WM_GetMPReceiveBufferSize();
    WM_GetMPSendBufferSize();

    if (g_021797A8->recvBuf != 0) {
        GFL_NET_FreeAligned(g_021797A8->recvBuf);
        GFL_NET_FreeAligned(g_021797A8->sendBuf);
    }

    g_021797A8->recvBufSize = WM_GetMPReceiveBufferSize();
    g_021797A8->sendBufSize = WM_GetMPSendBufferSize();

    g_021797A8->recvBuf =
        GFL_NET_AllocAligned(g_021797A8->heapId, g_021797A8->recvBufSize + 0x20, sWihFileName, 0x4A7);
    g_021797A8->sendBuf =
        GFL_NET_AllocAligned(g_021797A8->heapId, g_021797A8->sendBufSize + 0x20, sWihFileName, 0x4A8);

    mpFreq = (GFL_NET_GetGameKind() == 2) ? 1 : 2;

    result = WM_StartMP((void (*)(void *))func_021783FC,
                        g_021797A8->recvBuf,
                        (u16)g_021797A8->recvBufSize,
                        g_021797A8->sendBuf,
                        (u16)g_021797A8->sendBufSize,
                        mpFreq);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}

void func_021783FC(WMStartMPCallback *arg)
{
    u16 errcode = arg->errcode;
    u16 aidBitmap;
    u32 myAid;
    u32 isParent;
    u32 aidCount;
    int result;
    if (errcode != 0) {
        func_0217814C(errcode);
        func_02178138(9);
        return;
    }
    switch (arg->state) {
    case 10:
        if (g_021797A8->connectMode == 4) {
            myAid = GFL_NET_GetChildSendSize();
            aidCount = GFL_NET_GetMaxConnectNum() - 1;
            aidBitmap = (1 << (aidCount + 1)) - 1;
            isParent = 1;
            if (GFL_NET_GetGameKind() == 2)
                isParent = 0;
            result = WM_StartDataSharing(g_021797A8->dataSharingInfo, 13, aidBitmap, myAid, isParent);
            if (result != 0) {
                func_0217814C(result);
                func_02178138(9);
                return;
            }
            func_02178138(5);
            return;
        }
        func_02178138(4);
        break;
    case 11:
    case 12:
    case 13:
        break;
    }
}

int func_021784AC(void)
{
    int result;
    func_02178138(3);
    result = WM_EndMP(func_021784D0);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}

void func_021784D0(WMCallback *arg)
{
    int result = arg->errcode;
    if (result != 0) {
        func_0217814C(result);
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
        func_0217814C(result);
        return 0;
    }
    return 1;
}

static void DWCi_MOV_WH_StateOutEndParent(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != 0) {
        func_0217814C(cb->errcode);
        return;
    }
    func_02178138(1);
}

int DWCi_MOV_WH_ChildConnectAuto(u32 mode, const u16 *macAddr, u32 channel)
{
    func_02178138(2);
    if (macAddr != 0) {
        g_021797A8->scanParam.bssid[2] = macAddr[2];
        g_021797A8->scanParam.bssid[1] = macAddr[1];
        g_021797A8->scanParam.bssid[0] = macAddr[0];
    } else {
        MI_CpuFill8(g_021797A8->scanParam.bssid, 0xff, 6);
    }
    g_021797A8->connectMode = mode;
    g_021797A8->judgeScanFunc = 0;
    g_021797A8->fixedScanChannel = channel;
    g_021797A8->scanParam.channelList = 1;
    g_021797A8->autoConnect = 1;
    if (DWCi_MOV_WH_StateInStartScan() == 0) {
        func_02178138(9);
        return 0;
    }
    return 1;
}

int DWCi_MOV_WH_StartScan(u32 judgeScanFunc, u16 *macAddr, u32 channel)
{
    func_02178138(2);
    g_021797A8->judgeScanFunc = (WihJudgeScanFunc)judgeScanFunc;
    g_021797A8->fixedScanChannel = channel;
    g_021797A8->scanParam.channelList = 1;
    g_021797A8->autoConnect = 0;
    g_021797A8->scanCount = 0;
    if (macAddr != 0) {
        g_021797A8->scanParam.bssid[2] = macAddr[2];
        g_021797A8->scanParam.bssid[1] = macAddr[1];
        g_021797A8->scanParam.bssid[0] = macAddr[0];
    } else {
        MI_CpuFill8(g_021797A8->scanParam.bssid, 0xff, 6);
    }
    if (DWCi_MOV_WH_StateInStartScan() == 0) {
        func_02178138(9);
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
        func_0217814C(3);
        return 0;
    }
    if (allowedChannels == 0) {
        func_0217814C(0x16);
        return 0;
    }
    work = g_021797A8;
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
    g_021797A8->scanParam.maxChannelTime = WM_GetDispersionScanPeriod();
    g_021797A8->scanParam.scanBuf = g_021797A8->scanBuf;
    g_021797A8->scanParam.scanBufSize = 0x400;
    g_021797A8->scanParam.scanType = 1;
    g_021797A8->scanParam.ssidLength = 0;
    result = WM_StartScanEx(DWCi_MOV_WH_StateOutStartScan, &g_021797A8->scanParam);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}

void WIH_SetScanTarget(u16 channel, void *macAddr)
{
    g_021797A8->fixedScanChannel = channel;
    func_02082D44(macAddr, g_021797A8->scanParam.bssid, 6);
}

int WIH_IsMatchingParent(WMBssDesc *bssDesc)
{
    u32 gameInfoLength = bssDesc->gameInfoLength;
    if (gameInfoLength < 0x10 || gameInfoLength > 0x80
        || gameInfoLength != (u32)bssDesc->userGameInfoLength + 0x10
        || bssDesc->gameInfoMagic != 1 || gameInfoLength < 8
        || bssDesc->ggid != g_021797A8->parentParam.ggid)
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

    g_021797A8->scanCount += 1;
    g_021797A8->scanWait = 0;
    if (cb->errcode != 0) {
        func_0217814C(cb->errcode);
        func_02178138(9);
        return;
    }
    if (g_021797A8->sysState != 2) {
        g_021797A8->autoConnect = 0;
        if (DWCi_MOV_WH_StateInEndScan() == 0)
            func_02178138(9);
        return;
    }
    g_021797A8->scanWait = g_021797A8->scanWaitFrames;
    switch (state) {
    case 4:
        WIH_DWC_Dummy();
        return;
    case 5:
        if (cb->bssDescCount != 0)
            DC_InvalidateRange(g_021797A8->scanBuf, 0x400);
        found = 0;
        for (i = 0; i < cb->bssDescCount; i++) {
            work = g_021797A8;
            MI_CpuCopy8(cb->bssDesc[i], &work->scanBssDesc, 0xC0);
            WIH_DWC_RequestAlertLevel((u8)cb->linkLevel[i]);
            if (g_021797A8->beaconFoundCallback != 0)
                g_021797A8->beaconFoundCallback(&work->scanBssDesc, GFL_NET_GetUserArg(),
                                                cb->linkLevel[i]);
            if (WIH_IsMatchingParent(&work->scanBssDesc) != 0) {
                if (g_021797A8->judgeScanFunc == 0)
                    func_02034714(sWihAssertText, 0, sWihAssertText);
                if (g_021797A8->judgeScanFunc(&work->scanBssDesc) != 0)
                    found = 1;
            }
        }
        if (g_021797A8->autoConnect != 0 && found != 0) {
            g_021797A8->scanWait = 0;
            if (DWCi_MOV_WH_StateInEndScan() == 0)
                func_02178138(9);
        }
        break;
    }
}

int DWCi_MOV_WH_EndScan(void)
{
    int irqState;
    int stopped = 0;
    irqState = func_02087988();
    if (g_021797A8->sysState == 2) {
        if (g_021797A8->scanWait != 0) {
            if (DWCi_MOV_WH_StateInStartScan() == 0)
                func_02178138(9);
        }
        g_021797A8->scanWait = -1;
        g_021797A8->autoConnect = 0;
        stopped = 1;
        g_021797A8->endScanPending = 1;
        func_02178138(3);
    }
    func_0208799C(irqState);
    return stopped;
}

static int DWCi_MOV_WH_StateInEndScan(void)
{
    int result;
    result = WM_EndScan((void *)DWCi_MOV_WH_StateOutEndScan);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}

void DWCi_MOV_WH_StateOutEndScan(WMCallback *arg)
{
    WihWork *work;
    g_021797A8->endScanPending = 0;
    if (arg->errcode != 0) {
        func_0217814C(arg->errcode);
        return;
    }
    func_02178138(1);
    work = g_021797A8;
    if (work->autoConnect != 0) {
        work->autoConnect = 0;
        if (DWCi_MOV_WH_StateInStartChild() == 0)
            func_02178138(9);
    }
}

int DWCi_MOV_WH_StateInStartChild(void)
{
    int result;
    if ((u32)(g_021797A8->sysState - 4) <= 1)
        return 1;
    func_02178138(3);
    result = WM_StartConnectEx((void *)DWCi_MOV_WH_StateOutStartChild, &g_021797A8->scanBssDesc, g_021797A8->connectSsid, 1, 0);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}

void DWCi_MOV_WH_StateOutStartChild(WMStartConnectCallback *arg)
{
    u32 value;
    WihSlotCallback slotCallback;
    if (arg->errcode != 0) {
        func_0217814C(arg->errcode);
        value = arg->errcode;
        if (value == 0xC) {
            func_02178138(9);
            return;
        }
        if (value == 0xB) {
            func_02178138(9);
            return;
        }
        if (value == 1) {
            func_02178138(8);
            return;
        }
        func_02178138(9);
        return;
    }
    value = arg->state;
    if (value == 8)
        return;
    if (value == 7) {
        func_02178138(4);
        if (DWCi_MOV_WH_StateInStartChildMP() == 0) {
            func_02178138(3);
            return;
        }
        g_021797A8->ownAid = arg->aid;
        slotCallback = g_021797A8->connectCallback;
        if (slotCallback != 0)
            slotCallback(arg->aid);
        return;
    }
    if (value == 6)
        return;
    if (value == 9) {
        func_0217814C(0x14);
        func_02178138(9);
        return;
    }
    if (value == 0x1A)
        return;
    func_02178138(9);
}

/*
 * The DWC copy of the NitroSDK demo wh.c's MP start (DWCi_MOV_WH_*): frees
 * and re-allocates the MP receive and send buffers (sizes from
 * WM_GetMP{Receive,Send}BufferSize, kept in recvBufSize and sendBufSize of
 * the work block behind g_021797A8), then calls WM_StartMP with callback
 * DWCi_MOV_WH_StateOutStartChildMP; anything but WM_ERRCODE_OPERATING (2) goes to the error
 * setter func_0217814C.
 */
BOOL DWCi_MOV_WH_StateInStartChildMP(void)
{
    int result;
    u16 mpFreq;

    WM_GetMPReceiveBufferSize();
    WM_GetMPSendBufferSize();

    if (g_021797A8->recvBuf != 0) {
        GFL_NET_FreeAligned(g_021797A8->recvBuf);
        GFL_NET_FreeAligned(g_021797A8->sendBuf);
    }

    g_021797A8->recvBufSize = WM_GetMPReceiveBufferSize();
    g_021797A8->sendBufSize = WM_GetMPSendBufferSize();

    g_021797A8->recvBuf =
        GFL_NET_AllocAligned(g_021797A8->heapId, g_021797A8->recvBufSize + 0x20, sWihFileName, 0x7FA);
    g_021797A8->sendBuf =
        GFL_NET_AllocAligned(g_021797A8->heapId, g_021797A8->sendBufSize + 0x20, sWihFileName, 0x7FB);

    mpFreq = (GFL_NET_GetGameKind() == 2) ? 1 : 2;

    result = WM_StartMP((void (*)(void *))DWCi_MOV_WH_StateOutStartChildMP,
                        g_021797A8->recvBuf,
                        (u16)g_021797A8->recvBufSize,
                        g_021797A8->sendBuf,
                        (u16)g_021797A8->sendBufSize,
                        mpFreq);
    if (result != 2) {
        func_0217814C(result);
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
        func_0217814C(errcode);
        func_02178138(9);
        return;
    }
    switch (arg->state) {
    case 0xA:
        if (g_021797A8->connectMode == 5) {
            int result;
            int aidCount;
            myAid = GFL_NET_GetChildSendSize();
            aidCount = GFL_NET_GetMaxConnectNum() - 1;
            aidBitmap = (u16)((1 << (aidCount + 1)) - 1);
            isParent = 1;
            if (GFL_NET_GetGameKind() == 2)
                isParent = 0;
            result = WM_StartDataSharing(g_021797A8->dataSharingInfo, 0xD, aidBitmap, (u16)myAid, isParent);
            if (result != 0) {
                func_0217814C(result);
                func_02179498();
                return;
            }
            func_02178138(5);
            return;
        }
        func_02178138(4);
        break;
    case 0xB:
    case 0xC:
    case 0xD:
        break;
    }
}

int func_02178C50(void)
{
    int result;
    func_02178138(3);
    result = WM_EndMP(func_02178C74);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}

void func_02178C74(WMCallback *arg)
{
    int result = arg->errcode;
    if (result != 0) {
        func_0217814C(result);
        func_02179498();
        return;
    }
    if (func_02178C98() == 0)
        func_02178138(9);
}

int func_02178C98(void)
{
    int result;
    int failed = 0;
    func_02178138(3);
    result = WM_Disconnect(DWCi_MOV_WH_StateOutEndChild, 0);
    if (result != 2) {
        func_0217814C(result);
        DWCi_MOV_WH_StateInEndKeyShare();
        return failed;
    }
    return 1;
}

static void DWCi_MOV_WH_StateOutEndChild(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode != 0) {
        func_0217814C(cb->errcode);
        return;
    }
    func_02178138(1);
}

int func_02178CDC(void)
{
    int result;
    func_02178138(3);
    result = WM_Reset(func_02178D00);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}

void func_02178D00(WMCallback *arg)
{
    if (arg->errcode != 0) {
        func_02178138(9);
        func_0217814C(arg->errcode);
    } else {
        func_02178138(1);
    }
}

int DWCi_MOV_WH_StateInSetMPData(u32 data, u32 size, u32 userCallback)
{
    func_020862F0(g_021797A8->sendBuf, g_021797A8->sendBufSize);
    if (WM_SetMPDataToPortEx((void *)func_02178D74, userCallback, data, size, 0xFFFF, 0xE, 2) == 2)
        return 1;
    return 0;
}

/* extent: two zero alignment bytes at 02178D9A precede labelled 02178D9C. */
void func_02178D74(WMPortSendCallback *arg)
{
    int errcode = arg->errcode;
    if (errcode != 0 && errcode != 15) {
        func_0217814C(errcode);
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
        func_0217814C(arg->errcode);
        return;
    }
    recvCallback = g_021797A8->recvCallback;
    if (recvCallback != 0) {
        if (arg->state == 0x15)
            recvCallback(arg->aid, arg->data, arg->length);
        else if (arg->state == 9)
            recvCallback(arg->aid, 0, 0);
    }
}

void func_02178DE0(WMCallback *arg)
{
    WihResultCallback callback = g_021797A8->initCallback;
    if (callback != 0)
        callback(arg->errcode == 0 ? 1 : 0);
    if (arg->errcode != 0)
        func_02178138(10);
    else
        func_02178138(0);
}

void func_02178E1C(u32 ggid)
{
    g_021797A8->parentParam.ggid = ggid;
}

void DWCi_MOV_WH_SetUserGameInfo(void *userGameInfo, unsigned short length)
{
    g_021797A8->parentParam.userGameInfo = userGameInfo;
    g_021797A8->parentParam.userGameInfoLength = length;
}

u16 func_02178E38(void)
{
    return g_021797A8->aidBitmap;
}

int WIH_GetSysState(void)
{
    if (g_021797A8 == 0)
        return 0;
    return g_021797A8->sysState;
}

int DWCi_MOV_WH_GetLastError(void)
{
    if (g_021797A8 != 0)
        return g_021797A8->lastError;
    return 0;
}

int func_02178E84(void)
{
    u16 dateTime[3];
    int result;
    int ok;
    u32 vblankCount;

    func_02087C6C(dateTime);
    /* the VBlank counter in the shared main memory area */
    vblankCount = *(volatile u32 *)0x02FFFC3C;
    g_021797A8->randomSeed = dateTime[2] + (dateTime[1] + (dateTime[0] + vblankCount));
    g_021797A8->randomSeed = g_021797A8->randomSeed * 0x10DCD + 0x3039;
    g_021797A8->measuredChannel = 0;
    g_021797A8->minBusyRatio = 0x65;
    func_02178138(3);
    ok = 1;
    result = func_02178F1C(1);
    if (result == 0x18) {
        func_0217814C(0x18);
        func_02178138(9);
        return 0;
    }
    if (result != 2) {
        func_0217814C(result);
        func_02178138(9);
        return 0;
    }
    return ok;
}

int func_02178F1C(u16 channel)
{
    u32 allowedChannels = func_0208EE60();
    if (allowedChannels == 0x8000) {
        func_0217814C(3);
        func_02178138(9);
        return 3;
    }
    if (allowedChannels == 0) {
        func_0217814C(0x16);
        func_02178138(9);
        return 0x18;
    }
    if (!((1 << (channel - 1)) & allowedChannels)) {
        do {
            channel = channel + 1;
            if (channel > 0x10)
                return 0x18;
        } while (!((1 << (channel - 1)) & allowedChannels));
    }
    return (u16)WHi_MeasureChannel((void *)func_02178F8C, channel);
}

#pragma opt_dead_assignments off
void func_02178F8C(const WMMeasureChannelCallback *arg)
{
    u32 channel;
    u32 busyRatio;
    u32 value;
    int result;
    if (arg->errcode != 0) {
        func_0217814C(arg->errcode);
        func_02178138(9);
        return;
    }
    channel = arg->channel;
    busyRatio = arg->ccaBusyRatio;
    value = g_021797A8->minBusyRatio;
    if (value > busyRatio) {
        g_021797A8->minBusyRatio = busyRatio;
        value = 1 << (channel - 1);
        g_021797A8->bestChannelBitmap = value;
    } else if (value == busyRatio) {
        value = (u16)(1 << (channel - 1)) | g_021797A8->bestChannelBitmap;
        g_021797A8->bestChannelBitmap = value;
    }
    result = func_02178F1C(channel + 1);
    if (result == 0x18 && g_021797A8->sysState != 9) {
        func_02178138(7);
        return;
    }
    if (result != 2)
        func_02178138(9);
}
#pragma opt_dead_assignments reset

int WHi_MeasureChannel(void *callback, unsigned short channel)
{
    return WM_MeasureChannel(callback, 3, 0x11, channel, 0x1E);
}

u16 func_02179024(void)
{
    func_02178138(1);
    g_021797A8->measuredChannel = WIH_PickRandomChannel(g_021797A8->bestChannelBitmap);
    return g_021797A8->measuredChannel;
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
        g_021797A8->randomSeed = g_021797A8->randomSeed * 0x10DCD + 0x3039;
        pick = (u32)(count * (u8)g_021797A8->randomSeed) << 8 >> 16;
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

BOOL func_021790E4(u32 heapId, int unused, int listening)
{
    BOOL ok;
    if (g_021797A8 != 0)
        return 0;
    g_021797A8 = GFL_NET_AllocAligned(heapId, 0x1F00, sWihFileName, 0xC33);
    MI_CpuFill8(g_021797A8, 0, 0x1EE0);
    g_021797A8->scanWaitFrames = 1;
    g_021797A8->aidBitmap = 1;
    g_021797A8->lastError = 0;
    g_021797A8->heapId = heapId;
    ok = 1;
    if (!func_021791A0(unused, listening))
        ok = 0;
    return ok;
}

void WIH_FreeWork(void)
{
    if (g_021797A8 != 0) {
        GFL_NET_FreeAligned(g_021797A8->recvBuf);
        GFL_NET_FreeAligned(g_021797A8->sendBuf);
        GFL_NET_FreeAligned(g_021797A8);
        g_021797A8 = 0;
    }
}

void func_02179188(WMCallback *arg)
{
    if (arg->errcode == 8) {
        func_02178138(9);
        func_0217814C(25);
    }
}

BOOL func_021791A0(int unused, int listening)
{
    int result;
    func_02178138(3);
    if (listening == 0)
        result = WM_Initialize(g_021797A8->wmSystemBuf, (void (*)(void *))func_021791F8, 2);
    else
        result = WM_InitializeForListening(g_021797A8->wmSystemBuf, (void (*)(void *))func_021791F8, 2, 0);
    if (result != 2) {
        func_0217814C(result);
        func_02178138(10);
        return 0;
    }
    return 1;
}

void DWCi_MOV_WH_StateOutSetLifeTime(void)
{
    func_02178138(1);
}

/*
 * WM_Initialize completion callback of the DWC WH copy: on an error result,
 * or when func_02179188 cannot be installed as the indication callback, it
 * sets the error state (10) and calls the user callback at initCallback with
 * 0; otherwise it sets state 1, calls WM_SetLifeTime with the unlabelled leaf
 * DWCi_MOV_WH_StateOutSetLifeTime and calls the user callback with 1.
 */
void func_021791F8(WMCallback *arg)
{
    WihResultCallback callback;
    int result;
    if (arg->errcode != 0) {
        func_0217814C(arg->errcode);
        func_02178138(10);
        callback = g_021797A8->initCallback;
        if (callback != 0)
            callback(0);
        return;
    }
    result = WM_SetIndCallback((void (*)(void))func_02179188);
    if (result != 0) {
        func_0217814C(result);
        func_02178138(10);
        callback = g_021797A8->initCallback;
        if (callback != 0)
            callback(0);
        return;
    }
    func_02178138(1);
    WM_SetLifeTime(DWCi_MOV_WH_StateOutSetLifeTime, 0xFFFF, 0x28, 5, 0x28);
    callback = g_021797A8->initCallback;
    if (callback != 0)
        callback(1);
}

BOOL func_02179288(int mode, u16 tgid, int channel, u16 maxEntry)
{
    g_021797A8->beaconSendCount = 0;
    g_021797A8->connectMode = mode;
    func_02178138(3);
    g_021797A8->parentParam.tgid = tgid;
    g_021797A8->parentParam.channel = channel;
    g_021797A8->parentParam.beaconPeriod = WM_GetDispersionBeaconPeriod();
    if (GFL_NET_GetParentSendSize() != 0) {
        g_021797A8->parentParam.parentMaxSize = GFL_NET_GetParentSendSize();
    } else {
        g_021797A8->parentParam.parentMaxSize = GFL_NET_GetChildSendSize() * GFL_NET_GetMaxConnectNum() + 4;
    }
    g_021797A8->parentParam.childMaxSize = GFL_NET_GetChildSendSize();
    g_021797A8->parentParam.maxEntry = maxEntry;
    g_021797A8->parentParam.cswitch = 0;
    g_021797A8->parentParam.multiBootFlag = 0;
    g_021797A8->parentParam.entryFlag = 1;
    g_021797A8->parentParam.keySharing = (mode == 2);
    if (mode == 0 || mode == 2 || mode == 4)
        return func_02178168();
    return 0;
}

void func_02179328(void *judgeAcceptFunc)
{
    g_021797A8->judgeAcceptFunc = (WihJudgeAcceptFunc)judgeAcceptFunc;
}

void DWCi_MOV_WH_SetReceiver(void *recvCallback)
{
    g_021797A8->recvCallback = (WihRecvCallback)recvCallback;
    if (WM_SetPortCallback(14, DWCi_MOV_WH_PortReceiveCallback, 0) != 0)
        func_02178138(9);
}

BOOL DWCi_MOV_WH_SendData(int data, u16 size, int userCallback)
{
    if (WIH_GetOwnAid() == 0 && (func_02178E38() & 0xFE) == 0)
        return 0;
    return DWCi_MOV_WH_StateInSetMPData(data, size, userCallback);
}

int func_02179394(u16 aid)
{
    return WM_GetSharedDataAddress(g_021797A8->dataSharingInfo, g_021797A8->dataSet, aid);
}

BOOL func_021793B8(int sendData)
{
    int result;
    result = WM_StepDataSharing((struct WMDataSharingInfo *)g_021797A8->dataSharingInfo, (const u16 *)sendData, (struct WMDataSet *)g_021797A8->dataSet);
    if (result == 7)
        return 0;
    if (result == 5)
        return 0;
    if (result != 0) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}

void WIH_UpdateScanTimer(void)
{
    if (g_021797A8 != 0 && *(s16 *)((u8 *)g_021797A8 + 0x1EBE) > 0) {
        *(s16 *)((u8 *)g_021797A8 + 0x1EBE) =
            (g_021797A8->sysState != 2) ? 0 : *(s16 *)((u8 *)g_021797A8 + 0x1EBE) - 1;
        if (*(s16 *)((u8 *)g_021797A8 + 0x1EBE) == 0) {
            if (g_021797A8->sysState == 2 && g_021797A8->scanPaused == 0) {
                if (DWCi_MOV_WH_StateInStartScan() == 0)
                    func_02178138(9);
            } else {
                *(s16 *)((unsigned int)g_021797A8 + 0x1EBE) = 1;
            }
        }
    }
}

void DWCi_MOV_WH_StateInEndKeyShare(void)
{
    int error;
    if (g_021797A8->sysState == 5) {
        error = WM_EndDataSharing(g_021797A8->dataSharingInfo);
        if (error != 0)
            func_0217814C(error);
    }
    if (func_02178CDC() == 0)
        func_02178138(10);
}

BOOL func_02179498(void)
{
    int state;
    if (g_021797A8 == 0 || (state = g_021797A8->sysState) == 1)
        return 1;
    if (g_021797A8->lastError != 0) {
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
    if (g_021797A8->endScanPending != 0)
        return 1;
    if (state != 5 && state != 4) {
        func_02178138(3);
        DWCi_MOV_WH_StateInEndKeyShare();
        return 1;
    }
    func_02178138(3);
    switch (g_021797A8->connectMode) {
    case 5:
        if (WM_EndDataSharing(g_021797A8->dataSharingInfo) != 0) {
            DWCi_MOV_WH_StateInEndKeyShare();
            break;
        }
    case 1:
        if (!func_02178C50())
            DWCi_MOV_WH_StateInEndKeyShare();
        break;
    case 2:
    case 3:
        break;
    case 4:
        if (WM_EndDataSharing(g_021797A8->dataSharingInfo) != 0) {
            DWCi_MOV_WH_StateInEndKeyShare();
            break;
        }
    case 0:
        if (!func_021784AC())
            DWCi_MOV_WH_StateInEndKeyShare();
        break;
    }
    return 1;
}

int func_02179570(void (*callback)(int))
{
    g_021797A8->initCallback = callback;
    func_02178138(3);
    if (WM_End(func_02178DE0) != 2) {
        func_02178138(9);
        return 0;
    }
    return 1;
}

unsigned short WIH_GetOwnAid(void)
{
    if (g_021797A8 != 0)
        return g_021797A8->ownAid;
    return 0;
}

void WIH_SetJudgeScanFunc(unsigned judgeScanFunc)
{
    g_021797A8->judgeScanFunc = (WihJudgeScanFunc)judgeScanFunc;
}

void WIH_SetBeaconGameInfo(int userGameInfo, int size, int ggid, int tgid)
{
    if (g_021797A8 != 0 && (unsigned)(g_021797A8->sysState - 4) <= 1)
        WM_SetGameInfo(0, userGameInfo, (u16)size, ggid, (u16)tgid, 1);
}

unsigned short WIH_GetBeaconSendCount(void)
{
    return g_021797A8->beaconSendCount;
}

void WIH_SetConnectCallback(unsigned connectCallback)
{
    g_021797A8->connectCallback = (WihSlotCallback)connectCallback;
}

void WIH_SetBeaconFoundCallback(u32 beaconFoundCallback)
{
    g_021797A8->beaconFoundCallback = (WihBeaconFoundCallback)beaconFoundCallback;
}

void WIH_SetScanWaitFrames(u16 scanWaitFrames)
{
    g_021797A8->scanWaitFrames = scanWaitFrames;
}
