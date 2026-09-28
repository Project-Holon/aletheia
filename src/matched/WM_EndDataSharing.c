/*
 * function: WM_EndDataSharing
 * address:  0x0209028C
 * packet:   pkt_0209028C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libwm wm_ds.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Ends data
 * sharing: releases the port callback and clears the station bitmap.
 *
 * symbols:
 *   WM_SetPortCallback  0x0208EB0C  arm
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

extern WMErrCode WM_SetPortCallback(u16 port, WMCallbackFunc callback, void *arg);

WMErrCode WM_EndDataSharing(WMDataSharingInfo *dsInfo)
{
    if (dsInfo == 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (dsInfo->aidBitmap == 0) {
        return WM_ERRCODE_ILLEGAL_STATE;
    }
    (void)WM_SetPortCallback(dsInfo->port, 0, 0);
    dsInfo->aidBitmap = 0;
    dsInfo->state = 0;
    return WM_ERRCODE_SUCCESS;
}
