/*
 * function: WmDataSharingReceiveCallback_Child
 * address:  0x02090814
 * packet:   pkt_02090814
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libwm wm_ds.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static in
 * the vendor object: the child's port callback.  Copies a data set received
 * from the parent into the ring when this child is part of it.
 *
 * symbols:
 *   WM_GetAID      0x0208E9EC  arm
 *   MIi_CpuCopy16  0x02082A60  arm
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

extern u16 WM_GetAID(void);
extern void MIi_CpuCopy16(const void *srcp, void *destp, u32 size);

void WmDataSharingReceiveCallback_Child(void *callback)
{
    WMPortRecvCallback *cb_Port = (WMPortRecvCallback *)callback;
    WMDataSharingInfo *dsInfo = (WMDataSharingInfo *)cb_Port->arg;

    if (dsInfo == 0) {
        return;
    }

    if (cb_Port->errcode == WM_ERRCODE_SUCCESS) {
        switch (cb_Port->state) {
        case 21:
            {
                u32 length;
                u32 aid;
                u32 aidBitmap;
                WMDataSet *dataSet;

                dataSet = (WMDataSet *)cb_Port->data;
                length = cb_Port->length;
                aidBitmap = dataSet->aidBitmap;
                aid = WM_GetAID();

                if (length != dsInfo->dataSetLength) {
                    if (length > 512) {
                        length = 512;
                    }
                }
                if (length < 4) {
                    return;
                }
                if (!(aidBitmap & (1 << aid))) {
                    return;
                }
                MIi_CpuCopy16(dataSet, &dsInfo->ds[dsInfo->writeIndex], length);
                dsInfo->seqNum[dsInfo->writeIndex] = (u16)(cb_Port->seqNo >> 1);
                dsInfo->writeIndex = (u16)((dsInfo->writeIndex + 1) % 4u);
            }
            break;
        case 7:
            break;
        case 9:
            break;
        case 25:
            break;
        case 26:
            break;
        }
    } else {
        dsInfo->state = 5;
    }
}
