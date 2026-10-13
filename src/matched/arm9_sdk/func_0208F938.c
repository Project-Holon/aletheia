/*
 * function: WM_Disconnect
 * address:  0x0208F938
 * packet:   pkt_0208F938
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WM_Disconnect (libwm.TWL.HYB.a(wm_standard.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *
 * symbols:
 *   WMi_GetSystemWork                0x0208e4bc arm
 *   WMi_CheckStateEx                 0x0208e52c arm
 *   DC_InvalidateRange               0x020862b8 arm
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

typedef struct WMStatus {
    u16 state;
    u8 pad02[0x180];
    u16 child_bitmap;
} WMStatus;

extern WMArm9Buf *WMi_GetSystemWork(void);
extern WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void WMi_SetCallbackTable(int id, WMCallbackFunc callback);
extern WMErrCode WMi_SendCommand(int id, u16 paramNum, ...);

WMErrCode WM_Disconnect(WMCallbackFunc callback, u16 aid)
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
