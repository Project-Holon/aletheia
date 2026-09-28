/*
 * function: func_0208ED70
 * address:  0x0208ED70
 * packet:   pkt_0208ED70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WM_ReadMPData (libwm.TWL.HYB.a(wm_sync.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *
 * symbols:
 *   WMi_GetSystemWork                0x0208e4bc arm
 *   WMi_CheckInitialized             0x0208e4cc arm
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
    u8 pad02[0x180];
    u16 child_bitmap;
} WMStatus;

typedef struct WMMpRecvData {
    u16 length;
    u16 rate_rssi;
    u16 aid;
    u16 noResponse;
    u16 wmHeader;
    u16 cdata[1];
} WMMpRecvData;

typedef struct WMMpRecvHeader {
    u16 bitmap;
    u16 errBitmap;
    u16 count;
    u16 length;
    u16 txCount;
    WMMpRecvData data[1];
} WMMpRecvHeader;

extern WMArm9Buf *WMi_GetSystemWork(void);
extern WMErrCode WMi_CheckInitialized(void);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);

WMMpRecvData *func_0208ED70(const WMMpRecvHeader *header, u16 aid)
{
    int i;
    WMErrCode result;
    WMMpRecvData *recvdata_p[15];
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        return 0;
    }

    if (aid < 1 || aid > 15) {
        return 0;
    }

    DC_InvalidateRange(&p->status->child_bitmap, 2);
    if (!(p->status->child_bitmap & (1 << aid))) {
        return 0;
    }

    if (header->count == 0 || header->count > 15) {
        return 0;
    }

    recvdata_p[0] = (WMMpRecvData *)&header->data[0];
    i = 0;
    do {
        if (recvdata_p[i]->aid == aid) {
            return recvdata_p[i];
        }
        i++;
        recvdata_p[i] = (WMMpRecvData *)((u32)recvdata_p[i - 1] + header->length);
    } while (i < header->count);

    return 0;
}
