/*
 * function: func_0208F808
 * address:  0x0208F808
 * packet:   pkt_0208F808
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WM_EndScan (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *
 * symbols:
 *   WMi_CheckStateEx                 0x0208e52c arm
 *   WMi_SetCallbackTable             0x0208e328 arm
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

extern WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
extern void WMi_SetCallbackTable(int id, WMCallbackFunc callback);
extern WMErrCode WMi_SendCommand(int id, u16 paramNum, ...);

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
