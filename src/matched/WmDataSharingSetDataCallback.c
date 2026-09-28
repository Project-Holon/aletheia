/*
 * function: WmDataSharingSetDataCallback
 * address:  0x02090608
 * packet:   pkt_02090608
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libwm wm_ds.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static in
 * the vendor object: completion callback of a data sharing send.  Records
 * the sequence number on the parent, rewinds the send index on a full
 * queue, and moves the sharing state to retry or error.
 *
 * symbols:
 *   WMi_GetSystemWork                    0x0208E4BC  arm
 *   WM_GetAID                            0x0208E9EC  arm
 *   WmDataSharingReceiveCallback_Parent  0x020906E0  arm
 *   WmDataSharingReceiveCallback_Child   0x02090814  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long s32;
typedef int BOOL;

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

typedef struct WMDataSet {
    u16 aidBitmap;
    u16 receivedBitmap;
    u16 data[254];
} WMDataSet;

typedef struct WMDataSharingInfo {
    WMDataSet ds[4];
    u16 seqNum[4];
    u16 writeIndex;
    u16 sendIndex;
    u16 readIndex;
    u16 aidBitmap;
    u16 dataLength;
    u16 stationNumber;
    u16 dataSetLength;
    u16 port;
    u16 doubleMode;
    u16 currentSeqNum;
    u16 state;
    u16 reserved[1];
} WMDataSharingInfo;

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

typedef struct WMPortSendCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 port;
    u16 destBitmap;
    u16 restBitmap;
    u16 sentBitmap;
    u16 rsv;
    u16 *data;
    union {
        u16 size;
        u16 length;
    };
    u16 seqNo;
    WMCallbackFunc callback;
    void *arg;
    u16 maxSendDataSize;
    u16 maxRecvDataSize;
} WMPortSendCallback;

extern WMArm9Buf *WMi_GetSystemWork(void);
extern u16 WM_GetAID(void);
extern void WmDataSharingReceiveCallback_Parent(void *callback);
extern void WmDataSharingReceiveCallback_Child(void *callback);

void WmDataSharingSetDataCallback(void *callback)
{
    WMArm9Buf *p = WMi_GetSystemWork();
    WMPortSendCallback *cb_Port = (WMPortSendCallback *)callback;
    WMDataSharingInfo *dsInfo;
    u16 aid;

    dsInfo = (WMDataSharingInfo *)p->portCallbackArgument[cb_Port->port];
    if (p->portCallbackTable[cb_Port->port] != WmDataSharingReceiveCallback_Parent
        && p->portCallbackTable[cb_Port->port] != WmDataSharingReceiveCallback_Child) {
        return;
    }
    if (dsInfo == 0) {
        return;
    }
    if (dsInfo != cb_Port->arg) {
        return;
    }

    aid = WM_GetAID();
    if (cb_Port->errcode == WM_ERRCODE_SUCCESS) {
        if (aid == 0) {
            dsInfo->seqNum[dsInfo->sendIndex] = (u16)(cb_Port->seqNo >> 1);
            dsInfo->sendIndex = (u16)((dsInfo->sendIndex + 1) % 4u);
        }
    } else if (cb_Port->errcode == 10) {
        if (aid != 0) {
            dsInfo->sendIndex = (u16)((dsInfo->sendIndex + 3) % 4u);
        }
        dsInfo->state = 4;
    } else {
        dsInfo->state = 5;
    }
}
