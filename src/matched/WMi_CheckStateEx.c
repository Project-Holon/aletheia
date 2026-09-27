/*
 * function: WMi_CheckStateEx
 * address:  0x0208E52C
 * packet:   pkt_0208E52C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libwm wm_system.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  The
 * object's .bss holds wmInitialized (u16) at +0 and wm9buf at +4, addressed
 * through one section-relative pool word; WmSystemBss below is that section.
 *
 * symbols:
 *   g_02153058            0x02153058  data
 *   WMi_CheckInitialized  0x0208E4CC  arm
 *   DC_InvalidateRange    0x020862B8  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long s32;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef enum WMErrCode {
    WM_ERRCODE_SUCCESS = 0,
    WM_ERRCODE_FAILED = 1,
    WM_ERRCODE_OPERATING = 2,
    WM_ERRCODE_ILLEGAL_STATE = 3,
    WM_ERRCODE_WM_DISABLE = 4,
    WM_ERRCODE_MAX = 0x7FFFFFFF
} WMErrCode;

typedef void (*WMCallbackFunc)(void *arg);

typedef struct WMStatus {
    u16 state;
    u8 pad02[0x70];
    u16 mp_recvBufSize;
} WMStatus;

typedef struct WMArm9Buf {
    struct WMArm7Buf *WM7;
    WMStatus *status;
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

/* wm_system.o .bss, addressed section-relative from one pool word */
typedef struct WmSystemBss {
    u16 wmInitialized;
    WMArm9Buf *wm9buf;
} WmSystemBss;

extern WmSystemBss g_02153058;
#define wmInitialized (g_02153058.wmInitialized)
#define wm9buf        (g_02153058.wm9buf)

typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define __va_size(t) ((sizeof(t) + 3) & ~3u)
#define va_arg(ap, t) (*(t *)((ap += __va_size(t)) - __va_size(t)))
#define va_end(v)

extern WMErrCode WMi_CheckInitialized(void);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);

WMErrCode WMi_CheckStateEx(s32 paramNum, ...)
{
    WMErrCode result;
    u16 now;
    va_list vlist;

    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    DC_InvalidateRange(&wm9buf->status->state, 2);
    now = wm9buf->status->state;

    result = WM_ERRCODE_ILLEGAL_STATE;
    va_start(vlist, paramNum);
    for (; paramNum; paramNum--) {
        if (va_arg(vlist, u32) == now) {
            result = WM_ERRCODE_SUCCESS;
        }
    }
    va_end(vlist);

    return result;
}
