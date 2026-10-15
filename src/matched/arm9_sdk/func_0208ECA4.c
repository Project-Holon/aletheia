/*
 * function: WM_GetMPReceiveBufferSize
 * address:  0x0208ECA4
 * packet:   pkt_0208ECA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WM_GetMPReceiveBufferSize (libwm.TWL.HYB.a(wm_sync.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *
 * symbols:
 *   WMi_GetSystemWork                0x0208e4bc arm
 *   WMi_CheckStateEx                 0x0208e52c arm
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

typedef struct WMStatus {
    u16 state;
    u8 pad02[0xA];
    u32 mp_flag;
    u8 pad10[0x2E];
    u16 mp_recvSize;
    u8 pad40[0xB8];
    u16 pparam_maxEntry;
    u8 padFA[0x8E];
    u16 aid;
} WMStatus;

extern WMArm9Buf *WMi_GetSystemWork(void);
extern WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);

int WM_GetMPReceiveBufferSize(void)
{
    WMErrCode result;
    BOOL isParent;
    int maxReceiveSize;
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckStateEx(2, 7, 8);
    if (result != WM_ERRCODE_SUCCESS) {
        return 0;
    }

    DC_InvalidateRange(&p->status->mp_flag, 4);
    if (p->status->mp_flag == 1) {
        return 0;
    }

    DC_InvalidateRange(&p->status->aid, 2);
    isParent = (p->status->aid == 0) ? 1 : 0;
    DC_InvalidateRange(&p->status->mp_recvSize, 2);
    maxReceiveSize = p->status->mp_recvSize;
    if (isParent == 1) {
        DC_InvalidateRange(&p->status->pparam_maxEntry, 2);
        return (((maxReceiveSize + 12) * p->status->pparam_maxEntry + 10 + 31) & ~31) * 2;
    }
    return ((maxReceiveSize + 50 + 31) & ~31) * 2;
}
