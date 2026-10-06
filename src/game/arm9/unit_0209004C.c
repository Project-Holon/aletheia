/*
 * file:     unit_0209004C.c
 * unit:     yes
 * function: func_0209004C, func_0209028C, func_020902D8, func_02090608, func_020906E0, func_02090814, func_020908F8, func_020909C8, func_02090B18, func_02090B6C
 * address:  0x0209004C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   WMi_CheckStateEx                     0x0208E52C  arm
 *   WM_GetAID                            0x0208E9EC  arm
 *   WM_GetConnectedAIDs                  0x0208EA1C  arm
 *   MIi_CpuClearFast                     0x02082AC0  arm
 *   MATH_CountPopulation                 0x02080D24  arm
 *   WM_SetPortCallback                   0x0208EB0C  arm
 *   WM_SetMPDataToPortEx                 0x0208FCB4  arm
 *   MIi_CpuCopy16                    0x02082a60 arm
 *   WMi_GetSystemWork                    0x0208E4BC  arm
 *   OS_DisableInterrupts      0x02087988  arm
 *   OS_RestoreInterrupts      0x0208799C  arm
 *   MIi_CpuClear16          0x02082A48  arm
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

extern WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
extern u16 WM_GetAID(void);
extern u16 WM_GetConnectedAIDs(void);
extern void MIi_CpuClearFast(u32 data, void *destp, u32 size);
extern u8 MATH_CountPopulation(u32 x);
extern WMErrCode WM_SetPortCallback(u16 port, WMCallbackFunc callback, void *arg);
extern WMErrCode WM_SetMPDataToPortEx(WMCallbackFunc callback, void *arg, u16 *sendData,
                                      u16 sendDataSize, u16 destBitmap, u16 port, u16 prio);
extern void MIi_CpuCopy16(const void *srcp, void *destp, u32 size);
extern WMArm9Buf *WMi_GetSystemWork(void);
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
WMErrCode WM_StartDataSharing(WMDataSharingInfo *dsInfo, u16 port, u16 aidBitmap, u16 dataLength, BOOL doubleMode);
WMErrCode WM_EndDataSharing(WMDataSharingInfo *dsInfo);
WMErrCode func_020902D8(WMDataSharingInfo *dsInfo, const u16 *sendData, WMDataSet *receiveData);
void WmDataSharingSetDataCallback(void *callback);
void WmDataSharingReceiveCallback_Parent(void *callback);
void WmDataSharingReceiveCallback_Child(void *callback);
void WmDataSharingReceiveData(WMDataSharingInfo *dsInfo, u16 aid, u16 *data);
void WmDataSharingSendDataSet(WMDataSharingInfo *dsInfo, BOOL delayed);
u16 *WM_GetSharedDataAddress(WMDataSharingInfo *dsInfo, WMDataSet *receiveData, u16 aid);
u16 *WmGetSharedDataAddress(WMDataSharingInfo *dsInfo, u32 aidBitmap, u16 *receiveBuf, u32 aid);


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

#define TRUE 1

#define FALSE 0

#define NULL ((void *)0)


/*
 * sdk:      WM_StepDataSharing (libwm.TWL.HYB.a(wm_ds.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *           The parent path passes a literal 0 as the aid to WmDataSharingReceiveData;
 *           passing the (known zero) aid keeps it live in fp and stops the constant 1
 *           from being pooled there. sendData is const (read-only source, DWARF drops it).
 */
WMErrCode func_020902D8(WMDataSharingInfo *dsInfo, const u16 *sendData, WMDataSet *receiveData)
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


void WmDataSharingReceiveData(WMDataSharingInfo *dsInfo, u16 aid, u16 *data)
{
    u16 aidBit = (u16)(1 << aid);
    u16 *buf;
    u16 writeIndex;
    OSIntrMode enabled;

    if (!(dsInfo->aidBitmap & aidBit)) {
        return;
    }
    writeIndex = dsInfo->writeIndex;
    if (!(dsInfo->ds[writeIndex].aidBitmap & aidBit)) {
        if (dsInfo->doubleMode != 1) {
            return;
        }
        writeIndex = (u16)((writeIndex + 1) % 4u);
        if (!(dsInfo->ds[writeIndex].aidBitmap & aidBit)) {
            return;
        }
    }

    buf = WmGetSharedDataAddress(dsInfo, dsInfo->aidBitmap, dsInfo->ds[writeIndex].data, aid);
    if (data != 0) {
        MIi_CpuCopy16(data, buf, dsInfo->dataLength);
    } else {
        MIi_CpuClear16(0, buf, dsInfo->dataLength);
    }

    enabled = OS_DisableInterrupts();
    dsInfo->ds[writeIndex].aidBitmap &= ~aidBit;
    dsInfo->ds[writeIndex].receivedBitmap |= aidBit;
    (void)OS_RestoreInterrupts(enabled);
}


void WmDataSharingSendDataSet(WMDataSharingInfo *dsInfo, BOOL delayed)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (dsInfo->ds[dsInfo->writeIndex].aidBitmap == 0) {
        u16 connectedAIDs;
        u16 oldWI;
        u16 nowWI;
        u16 nextWI;
        WMErrCode res;

        connectedAIDs = WM_GetConnectedAIDs();
        oldWI = dsInfo->writeIndex;
        nowWI = (u16)((oldWI + 1) % 4u);
        if (dsInfo->doubleMode == 1) {
            nextWI = (u16)((nowWI + 1) % 4u);
        } else {
            nextWI = nowWI;
        }
        MIi_CpuClear16(0, &dsInfo->ds[nextWI], sizeof(WMDataSet));
        dsInfo->ds[nextWI].aidBitmap = (u16)(dsInfo->aidBitmap & (connectedAIDs | 1));
        dsInfo->writeIndex = nowWI;
        dsInfo->ds[oldWI].aidBitmap = dsInfo->aidBitmap;
        if (delayed == 1) {
            dsInfo->ds[oldWI].aidBitmap &= ~1;
        }
        (void)OS_RestoreInterrupts(enabled);

        res = WM_SetMPDataToPortEx(WmDataSharingSetDataCallback, dsInfo,
                                   (u16 *)&dsInfo->ds[oldWI], dsInfo->dataSetLength,
                                   (u16)(dsInfo->aidBitmap & connectedAIDs), dsInfo->port, 1);
        if (res == WM_ERRCODE_NO_ENTRY) {
            dsInfo->seqNum[oldWI] = 0xFFFF;
            dsInfo->sendIndex = (u16)((dsInfo->sendIndex + 1) % 4u);
        } else if (res != WM_ERRCODE_SUCCESS && res != WM_ERRCODE_OPERATING) {
            dsInfo->state = 5;
        }
    } else {
        (void)OS_RestoreInterrupts(enabled);
    }
}


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


u16 *WmGetSharedDataAddress(WMDataSharingInfo *dsInfo, u32 aidBitmap, u16 *receiveBuf, u32 aid)
{
    u32 count = MATH_CountPopulation(aidBitmap & ((1 << aid) - 1));

    return (u16 *)((u8 *)receiveBuf + dsInfo->dataLength * count);
}
