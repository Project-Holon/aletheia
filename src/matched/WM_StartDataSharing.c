/*
 * function: WM_StartDataSharing
 * address:  0x0209004C
 * packet:   pkt_0209004C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libwm wm_ds.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Starts data
 * sharing on a port: clears the sharing state, sizes the data set from the
 * station count, installs the port callback and, on the parent, sends the
 * first (two in double mode) empty sets.
 *
 * symbols:
 *   WMi_CheckStateEx                     0x0208E52C  arm
 *   WM_GetAID                            0x0208E9EC  arm
 *   WM_GetConnectedAIDs                  0x0208EA1C  arm
 *   MIi_CpuClearFast                     0x02082AC0  arm
 *   MATH_CountPopulation                 0x02080D24  arm
 *   WM_SetPortCallback                   0x0208EB0C  arm
 *   WM_SetMPDataToPortEx                 0x0208FCB4  arm
 *   WmDataSharingReceiveCallback_Parent  0x020906E0  arm
 *   WmDataSharingSetDataCallback         0x02090608  arm
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

extern WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
extern u16 WM_GetAID(void);
extern u16 WM_GetConnectedAIDs(void);
extern void MIi_CpuClearFast(u32 data, void *destp, u32 size);
extern u8 MATH_CountPopulation(u32 x);
extern WMErrCode WM_SetPortCallback(u16 port, WMCallbackFunc callback, void *arg);
extern WMErrCode WM_SetMPDataToPortEx(WMCallbackFunc callback, void *arg, u16 *sendData,
                                      u16 sendDataSize, u16 destBitmap, u16 port, u16 prio);
extern void WmDataSharingReceiveCallback_Parent(void *callback);
extern void WmDataSharingSetDataCallback(void *callback);
extern void WmDataSharingReceiveCallback_Child(void *callback);

WMErrCode WM_StartDataSharing(WMDataSharingInfo *dsInfo, u16 port, u16 aidBitmap, u16 dataLength,
                              BOOL doubleMode)
{
    WMErrCode result;
    int aid;
    u16 connectedAIDs = 1;
    u16 count;

    result = WMi_CheckStateEx(2, 9, 10);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    if (dsInfo == 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (port >= 16) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (aidBitmap == 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    aid = WM_GetAID();
    if (aid == 0) {
        connectedAIDs = WM_GetConnectedAIDs();
    }

    MIi_CpuClearFast(0, dsInfo, sizeof(WMDataSharingInfo));
    dsInfo->writeIndex = 0;
    dsInfo->sendIndex = 0;
    dsInfo->readIndex = 0;
    dsInfo->aidBitmap = 0;
    dsInfo->dataLength = dataLength;
    dsInfo->port = port;
    dsInfo->doubleMode = (u16)(doubleMode ? 1 : 0);
    aidBitmap |= (u16)(1 << aid);
    dsInfo->aidBitmap = aidBitmap;

    count = MATH_CountPopulation(aidBitmap);
    dsInfo->dataSetLength = (u16)(dataLength * count);
    dsInfo->stationNumber = count;
    if (dsInfo->dataSetLength > 508) {
        dsInfo->aidBitmap = 0;
        return WM_ERRCODE_INVALID_PARAM;
    }
    dsInfo->dataSetLength += 4;
    dsInfo->state = 1;

    if (aid == 0) {
        int i;
        int res;

        for (i = 0; i < 4; i++) {
            dsInfo->ds[i].aidBitmap = (u16)(dsInfo->aidBitmap & (connectedAIDs | 1));
        }
        (void)WM_SetPortCallback(port, WmDataSharingReceiveCallback_Parent, dsInfo);

        for (i = 0; i < ((dsInfo->doubleMode == 1) ? 2 : 1); i++) {
            dsInfo->writeIndex = (u16)((dsInfo->writeIndex + 1) % 4u);
            res = WM_SetMPDataToPortEx(WmDataSharingSetDataCallback, dsInfo, (u16 *)&dsInfo->ds[i],
                                       dsInfo->dataSetLength,
                                       (u16)(dsInfo->aidBitmap & connectedAIDs), dsInfo->port, 1);
            if (res == WM_ERRCODE_NO_ENTRY) {
                dsInfo->seqNum[i] = 0xFFFF;
                dsInfo->sendIndex = (u16)((dsInfo->sendIndex + 1) % 4u);
            } else if (res != WM_ERRCODE_SUCCESS && res != WM_ERRCODE_OPERATING) {
                dsInfo->state = 5;
                return WM_ERRCODE_FAILED;
            }
        }
    } else {
        dsInfo->sendIndex = 3;
        (void)WM_SetPortCallback(port, WmDataSharingReceiveCallback_Child, dsInfo);
    }
    return WM_ERRCODE_SUCCESS;
}
