/*
 * function: WM_SetIndCallback
 * address:  0x0208EAC8
 * packet:   pkt_0208EAC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WM_SetIndCallback (libwm.TWL.HYB.a(wm_sync.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *
 * symbols:
 *   OS_DisableInterrupts             0x02087988 arm
 *   WMi_CheckInitialized             0x0208e4cc arm
 *   OS_RestoreInterrupts             0x0208799c arm
 *   WMi_GetSystemWork                0x0208e4bc arm
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

extern OSIntrMode OS_DisableInterrupts(void);
extern WMErrCode WMi_CheckInitialized(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern WMArm9Buf *WMi_GetSystemWork(void);

WMErrCode WM_SetIndCallback(WMCallbackFunc callback)
{
    OSIntrMode e;
    WMErrCode result;

    e = OS_DisableInterrupts();
    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        (void)OS_RestoreInterrupts(e);
        return result;
    }

    WMi_GetSystemWork()->indCallback = callback;
    (void)OS_RestoreInterrupts(e);
    return WM_ERRCODE_SUCCESS;
}
