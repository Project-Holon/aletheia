/*
 * function: WM_SetParentParameter
 * address:  0x0208F480
 * packet:   pkt_0208F480
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WM_SetParentParameter (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *
 * symbols:
 *   WMi_CheckStateEx                 0x0208e52c arm
 *   OS_IsRunOnTwl                    0x02085d3c arm
 *   WMi_CheckEnableFlag              0x0208eaa0 arm
 *   WmCheckParentParameter           0x0208f578 arm
 *   WMi_SetCallbackTable             0x0208e328 arm
 *   DC_StoreRange                    0x020862d4 arm
 *   WMi_SendCommand                  0x0208e3a0 arm
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

extern WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
extern BOOL OS_IsRunOnTwl(void);
extern BOOL WMi_CheckEnableFlag(void);
extern BOOL WmCheckParentParameter(WMParentParam *param);
extern void WMi_SetCallbackTable(int id, WMCallbackFunc callback);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
extern WMErrCode WMi_SendCommand(int id, u16 paramNum, ...);

WMErrCode WM_SetParentParameter(WMCallbackFunc callback, WMParentParam *pparaBuf)
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
