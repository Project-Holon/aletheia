/*
 * function: WM_StartScanEx
 * address:  0x0208F698
 * packet:   pkt_0208F698
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WM_StartScanEx (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *
 * symbols:
 *   WMi_CheckStateEx                 0x0208e52c arm
 *   OS_IsRunOnTwl                    0x02085d3c arm
 *   WMi_CheckEnableFlag              0x0208eaa0 arm
 *   WMi_SetCallbackTable             0x0208e328 arm
 *   MI_CpuCopy8                      0x02082d44 arm
 *   WMi_SendCommandDirect            0x0208e44c arm
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

extern WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
extern BOOL OS_IsRunOnTwl(void);
extern BOOL WMi_CheckEnableFlag(void);
extern void WMi_SetCallbackTable(int id, WMCallbackFunc callback);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern WMErrCode WMi_SendCommandDirect(void *data, u32 length);

WMErrCode WM_StartScanEx(WMCallbackFunc callback, const WMScanExParam *param)
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
