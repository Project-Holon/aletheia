/*
 * function: WM_StepDataSharing
 * address:  0x020902D8
 * packet:   pkt_020902D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WM_StepDataSharing (libwm.TWL.HYB.a(wm_ds.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *           The parent path passes a literal 0 as the aid to WmDataSharingReceiveData;
 *           passing the (known zero) aid keeps it live in fp and stops the constant 1
 *           from being pooled there. sendData is const (read-only source, DWARF drops it).
 *
 * symbols:
 *   WMi_CheckStateEx                 0x0208e52c arm
 *   WM_GetAID                        0x0208e9ec arm
 *   WM_GetConnectedAIDs              0x0208ea1c arm
 *   WM_SetMPDataToPortEx             0x0208fcb4 arm
 *   MIi_CpuCopy16                    0x02082a60 arm
 *   WmDataSharingSendDataSet         0x020909c8 arm
 *   WmDataSharingReceiveData         0x020908f8 arm
 *   WmDataSharingSetDataCallback     0x02090608 arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long s32;
typedef int BOOL;
#define TRUE 1
#define FALSE 0
#define NULL ((void *)0)

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
extern WMErrCode WM_SetMPDataToPortEx(WMCallbackFunc callback, void *arg, u16 *sendData,
                                      u16 sendDataSize, u16 destBitmap, u16 port, u16 prio);
extern void MIi_CpuCopy16(const void *srcp, void *destp, u32 size);
extern void WmDataSharingSendDataSet(WMDataSharingInfo *dsInfo, BOOL delayed);
extern void WmDataSharingReceiveData(WMDataSharingInfo *dsInfo, u16 aid, u16 *data);
extern void WmDataSharingSetDataCallback(void *callback);

WMErrCode WM_StepDataSharing(WMDataSharingInfo *dsInfo, const u16 *sendData, WMDataSet *receiveData)
{
    WMErrCode result;
    u16 aid;
    u16 connectedAIDs;
    u16 state;

    result = WMi_CheckStateEx(2, 9, 10);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    if (dsInfo == NULL) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (sendData == NULL) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (receiveData == NULL) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    aid = WM_GetAID();
    if (aid == 0) {
        connectedAIDs = WM_GetConnectedAIDs();
    }

    state = dsInfo->state;
    if (state == 5) {
        return WM_ERRCODE_FAILED;
    }
    if (state != 1 && state != 4) {
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    result = WM_ERRCODE_NO_DATASET;

    if (aid == 0) {
        BOOL sendFlag = FALSE;
        BOOL delayed = FALSE;

        if (state == 4) {
            int res;
            int oldWI;
            dsInfo->state = 1;
            oldWI = (dsInfo->writeIndex + 3) % 4u;
            res = WM_SetMPDataToPortEx(WmDataSharingSetDataCallback, dsInfo,
                                       (u16 *)&dsInfo->ds[oldWI], dsInfo->dataSetLength,
                                       (u16)(dsInfo->aidBitmap & connectedAIDs), dsInfo->port, 1);
            if (res == WM_ERRCODE_NO_ENTRY) {
                dsInfo->seqNum[oldWI] = 0xFFFF;
                dsInfo->sendIndex = (u16)((dsInfo->sendIndex + 1) % 4u);
            } else if (res != WM_ERRCODE_SUCCESS && res != WM_ERRCODE_OPERATING) {
                dsInfo->state = 5;
                return WM_ERRCODE_FAILED;
            }
        }

        if (dsInfo->readIndex != dsInfo->sendIndex) {
            dsInfo->ds[dsInfo->readIndex].aidBitmap |= 1;
            MIi_CpuCopy16(&dsInfo->ds[dsInfo->readIndex], receiveData, sizeof(WMDataSet));
            dsInfo->currentSeqNum = dsInfo->seqNum[dsInfo->readIndex];
            dsInfo->readIndex = (u16)((dsInfo->readIndex + 1) % 4u);
            sendFlag = TRUE;
            result = WM_ERRCODE_SUCCESS;
            if (dsInfo->doubleMode == 0 && connectedAIDs != 0
                && dsInfo->ds[dsInfo->writeIndex].aidBitmap == 1) {
                delayed = TRUE;
            } else {
                delayed = FALSE;
            }
        }

        WmDataSharingSendDataSet(dsInfo, FALSE);
        if (sendFlag) {
            WmDataSharingReceiveData(dsInfo, 0, (u16 *)sendData);
            if (dsInfo->doubleMode == 0) {
                WmDataSharingSendDataSet(dsInfo, delayed);
            }
        }
    } else {
        BOOL sendFlag = FALSE;

        if (state == 4) {
            dsInfo->state = 1;
            sendFlag = TRUE;
        } else if (dsInfo->readIndex != dsInfo->writeIndex) {
            if (!(dsInfo->ds[dsInfo->readIndex].aidBitmap & 1)) {
                dsInfo->ds[dsInfo->readIndex].aidBitmap |= 1;
            } else {
                MIi_CpuCopy16(&dsInfo->ds[dsInfo->readIndex], receiveData, sizeof(WMDataSet));
                dsInfo->currentSeqNum = dsInfo->seqNum[dsInfo->readIndex];
                dsInfo->readIndex = (u16)((dsInfo->readIndex + 1) % 4u);
                sendFlag = TRUE;
                result = WM_ERRCODE_SUCCESS;
            }
        }

        if (sendFlag) {
            WMErrCode res;
            u16 *buf = (u16 *)&dsInfo->ds[dsInfo->sendIndex] + 16;
            MIi_CpuCopy16(sendData, buf, dsInfo->dataLength);
            res = WM_SetMPDataToPortEx(WmDataSharingSetDataCallback, dsInfo, buf,
                                       dsInfo->dataLength, dsInfo->aidBitmap, dsInfo->port, 1);
            dsInfo->sendIndex = (u16)((dsInfo->sendIndex + 1) % 4u);
            if (res != WM_ERRCODE_OPERATING && res != WM_ERRCODE_SUCCESS) {
                dsInfo->state = 5;
                result = WM_ERRCODE_FAILED;
            }
        }
    }

    return result;
}
