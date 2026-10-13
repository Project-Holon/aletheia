/*
 * function: WM_StartConnectEx
 * address:  0x0208F84C
 * packet:   pkt_0208F84C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WM_StartConnectEx (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *
 * symbols:
 *   WMi_CheckStateEx                 0x0208e52c arm
 *   OS_IsRunOnTwl                    0x02085d3c arm
 *   WMi_CheckEnableFlag              0x0208eaa0 arm
 *   DC_StoreRange                    0x020862d4 arm
 *   WMi_GetSystemWork                0x0208e4bc arm
 *   WMi_SetCallbackTable             0x0208e328 arm
 *   MI_CpuCopy8                      0x02082d44 arm
 *   MI_CpuFill8                      0x02082bcc arm
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

extern WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
extern BOOL OS_IsRunOnTwl(void);
extern BOOL WMi_CheckEnableFlag(void);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
extern WMArm9Buf *WMi_GetSystemWork(void);
extern void WMi_SetCallbackTable(int id, WMCallbackFunc callback);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern WMErrCode WMi_SendCommandDirect(void *data, u32 length);

WMErrCode WM_StartConnectEx(WMCallbackFunc callback, WMBssDesc *pInfo, u8 *ssid, BOOL powerSave, u16 authMode)
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
