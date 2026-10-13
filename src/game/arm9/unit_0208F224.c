/*
 * file:     unit_0208F224.c
 * unit:     yes
 * function: func_0208F224, func_0208F234, func_0208F2A0, func_0208F2E4, func_0208F328, func_0208F370, func_0208F380, func_0208F398, func_0208F400, func_0208F43C, func_0208F480, func_0208F578, func_0208F5C8, func_0208F644, func_0208F654, func_0208F698, func_0208F808, func_0208F84C, func_0208F938
 * address:  0x0208F224
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FATFSi_FormatDriveEx  0x0208F234  arm
 *   WMi_CheckStateEx                 0x0208e52c arm
 *   WMi_SetCallbackTable             0x0208e328 arm
 *   WMi_RegisterSleepCallback        0x0208ea4c arm
 *   WMi_GetSystemWork                0x0208e4bc arm
 *   WMi_SendCommand                  0x0208e3a0 arm
 *   WMi_InitializeEx                 0x0208f398 arm
 *   WM_Init                          0x0208e010 arm
 *   WMi_CheckIdle                    0x0208e4e8 arm
 *   OS_IsRunOnTwl                    0x02085d3c arm
 *   WMi_CheckEnableFlag              0x0208eaa0 arm
 *   WmCheckParentParameter           0x0208f578 arm
 *   DC_StoreRange                    0x020862d4 arm
 *   DWCi_IsSendableReliable 0x0208F5C8 arm
 *   MI_CpuCopy8                      0x02082d44 arm
 *   WMi_SendCommandDirect            0x0208e44c arm
 *   MI_CpuFill8                      0x02082bcc arm
 *   DC_InvalidateRange               0x020862b8 arm
 */
typedef unsigned long u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef long s32;

typedef short s16;

typedef int BOOL;

typedef u32 OSIntrMode;

typedef enum WMErrCode {
    WM_ERRCODE_SUCCESS = 0,
    WM_ERRCODE_FAILED = 1,
    WM_ERRCODE_OPERATING = 2,
    WM_ERRCODE_ILLEGAL_STATE = 3,
    WM_ERRCODE_WM_DISABLE = 4,
    WM_ERRCODE_NO_DATASET = 5,
    WM_ERRCODE_INVALID_PARAM = 6,
    WM_ERRCODE_NO_ENTRY = 7,
    WM_ERRCODE_MAX = 0x7FFFFFFF
} WMErrCode;

typedef void (*WMCallbackFunc)(void *arg);

typedef struct WMArm9Buf {
    struct WMArm7Buf *WM7;
    struct WMStatus *status;
    u32 *indbuf;
    u32 *fifo9to7;
    u32 *fifo7to9;
    u16 dmaNo;
    u16 scanOnlyFlag;
    WMCallbackFunc CallbackTable[44];
    WMCallbackFunc indCallback;
    WMCallbackFunc portCallbackTable[16];
    void *portCallbackArgument[16];
    u32 connectedAidBitmap;
    u16 myAid;
    u8 reserved1[174];
} WMArm9Buf;

typedef struct WMParentParam {
    u16 *userGameInfo;
    u16 userGameInfoLength;
    u16 padding;
    u32 ggid;
    u16 tgid;
    u16 entryFlag;
    u16 maxEntry;
    u16 multiBootFlag;
    u16 KS_Flag;
    u16 CS_Flag;
    u16 beaconPeriod;
    u16 rsv1[4];
    u16 rsv2[8];
    u16 channel;
    u16 parentMaxSize;
    u16 childMaxSize;
    u16 rsv[4];
} WMParentParam;

typedef struct WMScanExParam {
    struct WMBssDesc *scanBuf;
    u16 scanBufSize;
    u16 channelList;
    u16 maxChannelTime;
    u8 bssid[6];
    u16 scanType;
    u16 ssidLength;
    u8 ssid[32];
    u16 ssidMatchLength;
    u16 rsv2[7];
} WMScanExParam;

typedef struct WMStartScanExReq {
    u16 apiid;
    u16 channelList;
    struct WMBssDesc *scanBuf;
    u16 scanBufSize;
    u16 maxChannelTime;
    u8 bssid[6];
    u16 scanType;
    u16 ssidLength;
    u8 ssid[32];
    u16 ssidMatchLength;
    u16 rsv[2];
} WMStartScanExReq;

typedef struct WMBssDesc {
    u16 length;
    u16 rssi;
    u8 bssid[6];
    u16 ssidLength;
    u8 ssid[32];
    /* remaining fields not touched here */
} WMBssDesc;

typedef struct WMStartConnectReq {
    u16 apiid;
    u16 reserved;
    WMBssDesc *pInfo;
    u8 ssid[24];
    BOOL powerSave;
    u16 reserved2;
    u16 authMode;
} WMStartConnectReq;

typedef struct WMStatus {
    u16 state;
    u8 pad02[0x180];
    u16 child_bitmap;
} WMStatus;

extern WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
extern void WMi_SetCallbackTable(int id, WMCallbackFunc callback);
extern void WMi_RegisterSleepCallback(void);
extern WMArm9Buf *WMi_GetSystemWork(void);
extern WMErrCode WMi_SendCommand(int id, u16 paramNum, ...);
extern WMErrCode WMi_InitializeEx(void *wmSysBuf, WMCallbackFunc callback, u16 dmaNo, u32 miscFlags);
extern WMErrCode WM_Init(void *wmSysBuf, u16 dmaNo);
extern WMErrCode WMi_CheckIdle(void);
extern BOOL OS_IsRunOnTwl(void);
extern BOOL WMi_CheckEnableFlag(void);
extern BOOL WmCheckParentParameter(WMParentParam *param);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
extern int DWCi_IsSendableReliable(unsigned char aid, unsigned short type);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern WMErrCode WMi_SendCommandDirect(void *data, u32 length);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
int func_0208F224(WMCallbackFunc callback);
WMErrCode func_0208F234(WMCallbackFunc callback, u32 miscFlags);
WMErrCode func_0208F2A0(WMCallbackFunc callback);
WMErrCode func_0208F2E4(WMCallbackFunc callback);
WMErrCode func_0208F328(WMCallbackFunc callback);
WMErrCode WM_Initialize(void *wmSysBuf, WMCallbackFunc callback, u16 dmaNo);
WMErrCode func_0208F380(void *wmSysBuf, WMCallbackFunc callback, u16 dmaNo, BOOL blink);
WMErrCode func_0208F398(void *wmSysBuf, WMCallbackFunc callback, u16 dmaNo, u32 miscFlags);
WMErrCode func_0208F400(WMCallbackFunc callback);
WMErrCode func_0208F43C(WMCallbackFunc callback);
WMErrCode func_0208F480(WMCallbackFunc callback, WMParentParam *pparaBuf);
BOOL func_0208F578(WMParentParam *param);
WMErrCode func_0208F5C8(WMCallbackFunc callback, BOOL powerSave);
int func_0208F644(unsigned char aid);
WMErrCode func_0208F654(WMCallbackFunc callback);
WMErrCode func_0208F698(WMCallbackFunc callback, const WMScanExParam *param);
WMErrCode func_0208F808(WMCallbackFunc callback);
WMErrCode func_0208F84C(WMCallbackFunc callback, WMBssDesc *pInfo, u8 *ssid, BOOL powerSave, u16 authMode);
WMErrCode func_0208F938(WMCallbackFunc callback, u16 aid);


/*
 * sdk:      FATFS_FormatDrive (libfatfs.TWL.HYB.a fatfs_api.o)
 */
int func_0208F224(WMCallbackFunc callback)
{
    return func_0208F234(callback, 0);
}





/*
 * sdk:      WMi_EnableEx (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_0208F234(WMCallbackFunc callback, u32 miscFlags)
{
    WMErrCode result;
    WMArm9Buf *p;

    result = WMi_CheckStateEx(1, 0);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    WMi_SetCallbackTable(3, callback);
    WMi_RegisterSleepCallback();
    p = WMi_GetSystemWork();
    result = WMi_SendCommand(3, 4, (u32)p->WM7, (u32)p->status, (u32)p->fifo7to9, miscFlags);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}






/*
 * sdk:      WM_Disable (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_0208F2A0(WMCallbackFunc callback)
{
    WMErrCode result;

    result = WMi_CheckStateEx(1, 1);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    WMi_SetCallbackTable(4, callback);
    result = WMi_SendCommand(4, 0);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}






/*
 * sdk:      WM_PowerOn (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_0208F2E4(WMCallbackFunc callback)
{
    WMErrCode result;

    result = WMi_CheckStateEx(1, 1);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    WMi_SetCallbackTable(5, callback);
    result = WMi_SendCommand(5, 0);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}





/*
 * sdk:      WM_PowerOff (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_0208F328(WMCallbackFunc callback)
{
    WMErrCode result;

    result = WMi_CheckStateEx(1, 2);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    WMi_SetCallbackTable(6, callback);
    result = WMi_SendCommand(6, 0);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}




WMErrCode WM_Initialize(void *wmSysBuf, WMCallbackFunc callback, u16 dmaNo)
{
    return func_0208F398(wmSysBuf, callback, dmaNo, 0);
}





/*
 * sdk:      WM_InitializeForListening (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_0208F380(void *wmSysBuf, WMCallbackFunc callback, u16 dmaNo, BOOL blink)
{
    u32 miscFlags = 1;

    if (!blink) {
        miscFlags |= 2;
    }
    return WMi_InitializeEx(wmSysBuf, callback, dmaNo, miscFlags);
}





/*
 * sdk:      WMi_InitializeEx (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_0208F398(void *wmSysBuf, WMCallbackFunc callback, u16 dmaNo, u32 miscFlags)
{
    WMErrCode result;
    WMArm9Buf *p;

    result = WM_Init(wmSysBuf, dmaNo);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    WMi_SetCallbackTable(0, callback);
    WMi_RegisterSleepCallback();
    p = WMi_GetSystemWork();
    result = WMi_SendCommand(0, 4, (u32)p->WM7, (u32)p->status, (u32)p->fifo7to9, miscFlags);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}





/*
 * sdk:      WM_Reset (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_0208F400(WMCallbackFunc callback)
{
    WMErrCode result;

    result = WMi_CheckIdle();
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    WMi_SetCallbackTable(1, callback);
    result = WMi_SendCommand(1, 0);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}




/*
 * sdk:      WM_End (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_0208F43C(WMCallbackFunc callback)
{
    WMErrCode result;

    result = WMi_CheckStateEx(1, 2);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    WMi_SetCallbackTable(2, callback);
    result = WMi_SendCommand(2, 0);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}




/*
 * sdk:      WM_SetParentParameter (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_0208F480(WMCallbackFunc callback, WMParentParam *pparaBuf)
{
    WMErrCode result;

    result = WMi_CheckStateEx(1, 2);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    if (OS_IsRunOnTwl()) {
        if (!WMi_CheckEnableFlag()) {
            return WM_ERRCODE_WM_DISABLE;
        }
    }

    if (pparaBuf == 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (pparaBuf->userGameInfoLength > 0 && pparaBuf->userGameInfo == 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (pparaBuf->parentMaxSize + (pparaBuf->KS_Flag ? 42 : 0) > 512
        || pparaBuf->childMaxSize + (pparaBuf->KS_Flag ? 6 : 0) > 512) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    (void)WmCheckParentParameter(pparaBuf);

    WMi_SetCallbackTable(7, callback);
    DC_StoreRange(pparaBuf, sizeof(WMParentParam));
    if (pparaBuf->userGameInfoLength > 0) {
        DC_StoreRange(pparaBuf->userGameInfo, pparaBuf->userGameInfoLength);
    }
    result = WMi_SendCommand(7, 1, pparaBuf);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}




/*
 * sdk:      WmCheckParentParameter (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *           static in the object (local symbol WmCheckParentParameter)
 */
BOOL func_0208F578(WMParentParam *param)
{
    if (param->userGameInfoLength > 0x70) {
        return 0;
    }
    if (param->beaconPeriod < 10 || param->beaconPeriod > 1000) {
        return 0;
    }
    if (param->channel < 1 || param->channel > 14) {
        return 0;
    }
    return 1;
}




/*
 * sdk:      WMi_StartParentEx (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_0208F5C8(WMCallbackFunc callback, BOOL powerSave)
{
    WMErrCode result;
    WMArm9Buf *w9b;

    result = WMi_CheckStateEx(1, 2);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    if (OS_IsRunOnTwl()) {
        if (!WMi_CheckEnableFlag()) {
            return WM_ERRCODE_WM_DISABLE;
        }
    }

    w9b = WMi_GetSystemWork();
    w9b->myAid = 0;
    w9b->connectedAidBitmap = 0;

    WMi_SetCallbackTable(8, callback);
    result = WMi_SendCommand(8, 1, powerSave);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}




/*
 * sdk:      DWC_IsSendableReliable (libdwcmatch.TWL.HYB.a dwc_transport.o)
 */
int func_0208F644(unsigned char aid)
{
    return DWCi_IsSendableReliable(aid, 1);
}




/*
 * sdk:      WM_EndParent (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_0208F654(WMCallbackFunc callback)
{
    WMErrCode result;

    result = WMi_CheckStateEx(1, 7);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    WMi_SetCallbackTable(9, callback);
    result = WMi_SendCommand(9, 0);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}




/*
 * sdk:      WM_StartScanEx (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_0208F698(WMCallbackFunc callback, const WMScanExParam *param)
{
    WMErrCode result;
    WMStartScanExReq Req;

    result = WMi_CheckStateEx(3, 2, 3, 5);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    if (OS_IsRunOnTwl()) {
        if (!WMi_CheckEnableFlag()) {
            return WM_ERRCODE_WM_DISABLE;
        }
    }

    if (param == 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (param->scanBuf == 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (param->scanBufSize > 1024) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (param->ssidLength > 32) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (param->scanType != 0 && param->scanType != 1 && param->scanType != 2
        && param->scanType != 3) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (param->scanType == 2 || param->scanType == 3) {
        if (param->ssidMatchLength > 32) {
            return WM_ERRCODE_INVALID_PARAM;
        }
    }

    WMi_SetCallbackTable(38, callback);

    Req.apiid = 38;
    Req.channelList = param->channelList;
    Req.scanBuf = param->scanBuf;
    Req.scanBufSize = param->scanBufSize;
    Req.maxChannelTime = param->maxChannelTime;
    MI_CpuCopy8(param->bssid, Req.bssid, 6);
    Req.scanType = param->scanType;
    Req.ssidMatchLength = param->ssidMatchLength;
    Req.ssidLength = param->ssidLength;
    MI_CpuCopy8(param->ssid, Req.ssid, 32);

    result = WMi_SendCommandDirect(&Req, sizeof(Req));
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}




/*
 * sdk:      WM_EndScan (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_0208F808(WMCallbackFunc callback)
{
    WMErrCode result;

    result = WMi_CheckStateEx(1, 5);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    WMi_SetCallbackTable(11, callback);
    result = WMi_SendCommand(11, 0);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}




/*
 * sdk:      WM_StartConnectEx (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_0208F84C(WMCallbackFunc callback, WMBssDesc *pInfo, u8 *ssid, BOOL powerSave, u16 authMode)
{
    WMErrCode result;
    WMArm9Buf *w9b;
    WMStartConnectReq Req;

    result = WMi_CheckStateEx(1, 2);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    if (OS_IsRunOnTwl()) {
        if (!WMi_CheckEnableFlag()) {
            return WM_ERRCODE_WM_DISABLE;
        }
    }

    if (pInfo == 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    DC_StoreRange(pInfo, (u32)(pInfo->length * 2));

    w9b = WMi_GetSystemWork();
    w9b->myAid = 0;
    w9b->connectedAidBitmap = 0;

    WMi_SetCallbackTable(12, callback);

    Req.apiid = 12;
    Req.pInfo = pInfo;
    if (ssid != 0) {
        MI_CpuCopy8(ssid, Req.ssid, 24);
    } else {
        MI_CpuFill8(Req.ssid, 0, 24);
    }
    Req.powerSave = powerSave;
    Req.authMode = authMode;

    result = WMi_SendCommandDirect(&Req, sizeof(Req));
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}




/*
 * sdk:      WM_Disconnect (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode func_0208F938(WMCallbackFunc callback, u16 aid)
{
    WMErrCode result;
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckStateEx(5, 7, 9, 8, 10, 11);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    if (p->status->state == 7 || p->status->state == 9) {
        if (aid < 1 || aid > 15) {
            return WM_ERRCODE_INVALID_PARAM;
        }
        DC_InvalidateRange(&p->status->child_bitmap, 2);
        if (!(p->status->child_bitmap & (1 << aid))) {
            return WM_ERRCODE_NO_ENTRY;
        }
    } else {
        if (aid != 0) {
            return WM_ERRCODE_INVALID_PARAM;
        }
    }

    WMi_SetCallbackTable(13, callback);
    result = WMi_SendCommand(13, 1, (u32)(1 << aid));
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}
