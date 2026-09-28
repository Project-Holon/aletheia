/*
 * function: WmDataSharingReceiveCallback_Parent
 * address:  0x020906E0
 * packet:   pkt_020906E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libwm wm_ds.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static in
 * the vendor object: the parent's port callback.  Stores a child's data,
 * drops a disconnected child from the pending data sets, and sends a set
 * once it is complete.
 *
 * symbols:
 *   WmDataSharingReceiveData  0x020908F8  arm
 *   WmDataSharingSendDataSet  0x020909C8  arm
 *   OS_DisableInterrupts      0x02087988  arm
 *   OS_RestoreInterrupts      0x0208799C  arm
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

typedef u32 OSIntrMode;

typedef struct WMPortRecvCallback {
    u16 apiid;
    u16 errcode;
    u16 state;
    u16 port;
    struct WMMpRecvBuf *recvBuf;
    u16 *data;
    u16 length;
    u16 aid;
    u8 macAddress[6];
    u16 seqNo;
    void *arg;
    u16 myAid;
    u16 connectedAidBitmap;
    u8 ssid[24];
    u16 reason;
    u16 rssi;
    u16 maxSendDataSize;
    u16 maxRecvDataSize;
} WMPortRecvCallback;

extern void WmDataSharingReceiveData(WMDataSharingInfo *dsInfo, u16 aid, u16 *data);
extern void WmDataSharingSendDataSet(WMDataSharingInfo *dsInfo, BOOL delayed);
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);

void WmDataSharingReceiveCallback_Parent(void *callback)
{
    WMPortRecvCallback *cb_Port = (WMPortRecvCallback *)callback;
    WMDataSharingInfo *dsInfo = (WMDataSharingInfo *)cb_Port->arg;

    if (dsInfo == 0) {
        return;
    }

    if (cb_Port->errcode == WM_ERRCODE_SUCCESS) {
        switch (cb_Port->state) {
        case 21:
            WmDataSharingReceiveData(dsInfo, cb_Port->aid, cb_Port->data);
            WmDataSharingSendDataSet(dsInfo, 0);
            break;
        case 7:
            WmDataSharingSendDataSet(dsInfo, 0);
            break;
        case 9:
        case 26:
            {
                u32 aidBit;
                u32 writeIndex;
                OSIntrMode enabled;

                aidBit = 1u << cb_Port->aid;
                enabled = OS_DisableInterrupts();
                writeIndex = dsInfo->writeIndex;
                dsInfo->ds[writeIndex].aidBitmap &= (u16)~aidBit;
                if (dsInfo->doubleMode == 1) {
                    writeIndex = (u16)((writeIndex + 1) % 4);
                    dsInfo->ds[writeIndex].aidBitmap &= (u16)~aidBit;
                }
                (void)OS_RestoreInterrupts(enabled);
                WmDataSharingSendDataSet(dsInfo, 0);
                if (dsInfo->doubleMode == 1) {
                    WmDataSharingSendDataSet(dsInfo, 0);
                }
            }
            break;
        case 25:
            break;
        }
    } else {
        dsInfo->state = 5;
    }
}
