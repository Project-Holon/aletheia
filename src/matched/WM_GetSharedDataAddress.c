/*
 * function: WM_GetSharedDataAddress
 * address:  0x02090B18
 * packet:   pkt_02090B18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libwm wm_ds.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Returns one station's data inside a received data set, or NULL when that station is not part of it or has not contributed.
 *
 * symbols:
 *   WmGetSharedDataAddress  0x02090B6C  arm
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

extern u16 *WmGetSharedDataAddress(WMDataSharingInfo *dsInfo, u32 aidBitmap, u16 *receiveBuf, u32 aid);

u16 *WM_GetSharedDataAddress(WMDataSharingInfo *dsInfo, WMDataSet *receiveData, u16 aid)
{
    u32 aidBitmap;
    u32 receivedBitmap;
    u32 aidBit = 1u << aid;

    if (dsInfo == 0) {
        return 0;
    }
    if (receiveData == 0) {
        return 0;
    }
    aidBitmap = receiveData->aidBitmap;
    receivedBitmap = receiveData->receivedBitmap;
    if (!(aidBitmap & aidBit)) {
        return 0;
    }
    if (!(receivedBitmap & aidBit)) {
        return 0;
    }
    return WmGetSharedDataAddress(dsInfo, aidBitmap, receiveData->data, aid);
}
