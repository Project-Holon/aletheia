/*
 * function: WMi_SendCommandDirect
 * address:  0x0208E44C
 * packet:   pkt_0208E44C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libwm wm system.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 *
 * symbols:
 *   g_02153070                     0x02153070  data
 *   WmGetCommandBuffer4Arm7        0x0208E340  arm
 *   MI_CpuCopy8                    0x02082D44  arm
 *   DC_StoreRange                  0x020862D4  arm
 *   PXI_SendWordByFifo             0x02088610  arm
 *   OS_SendMessage                 0x02085DBC  arm
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
    WM_ERRCODE_FIFO_ERROR = 8,
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

typedef struct PMiGenCallbackInfo {
    void (*callback)(void *);
    void *arg;
    int priority;
    struct PMiGenCallbackInfo *next;
} PMGenCallbackInfo;

/* wm_system.o .bss, addressed section-relative from one pool word */
typedef struct WmSystemBss {
    u16 wmInitialized;
    WMArm9Buf *wm9buf;
    PMGenCallbackInfo sleepCbInfo;
} WmSystemBss;

extern WmSystemBss g_02153058;
#define wmInitialized (g_02153058.wmInitialized)
#define wm9buf        (g_02153058.wm9buf)

typedef struct OSMessageQueue OSMessageQueue;

extern OSMessageQueue g_02153070;
extern u32 *WmGetCommandBuffer4Arm7(void);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);
extern BOOL OS_SendMessage(OSMessageQueue *mq, void *msg, s32 flags);

WMErrCode WMi_SendCommandDirect(void *data, u32 length)
{
    u32 *tmpAddr;
    int result;

    tmpAddr = WmGetCommandBuffer4Arm7();
    if (tmpAddr == 0) {
        return WM_ERRCODE_FIFO_ERROR;
    }

    MI_CpuCopy8(data, tmpAddr, length);
    DC_StoreRange(tmpAddr, length);
    result = PXI_SendWordByFifo(10, (u32)tmpAddr, 0);
    (void)OS_SendMessage(&g_02153070, tmpAddr, 1);
    if (result < 0) {
        return WM_ERRCODE_FIFO_ERROR;
    }
    return WM_ERRCODE_OPERATING;
}
