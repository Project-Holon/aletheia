/*
 * function: WmDataSharingSendDataSet
 * address:  0x020909C8
 * packet:   pkt_020909C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libwm wm_ds.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static in
 * the vendor object: once every station has contributed to the data set
 * being written, advances the write index, prepares the next set and sends
 * the completed one to the children.
 *
 * symbols:
 *   OS_DisableInterrupts          0x02087988  arm
 *   WM_GetConnectedAIDs           0x0208EA1C  arm
 *   MIi_CpuClear16                0x02082A48  arm
 *   OS_RestoreInterrupts          0x0208799C  arm
 *   WM_SetMPDataToPortEx          0x0208FCB4  arm
 *   WmDataSharingSetDataCallback  0x02090608  arm
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

extern OSIntrMode OS_DisableInterrupts(void);
extern u16 WM_GetConnectedAIDs(void);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern WMErrCode WM_SetMPDataToPortEx(WMCallbackFunc callback, void *arg, u16 *sendData,
                                      u16 sendDataSize, u16 destBitmap, u16 port, u16 prio);
extern void WmDataSharingSetDataCallback(void *callback);

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
