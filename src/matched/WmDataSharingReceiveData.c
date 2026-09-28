/*
 * function: WmDataSharingReceiveData
 * address:  0x020908F8
 * packet:   pkt_020908F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libwm wm_ds.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static in
 * the vendor object: stores one station's contribution into the data set
 * being written (or the next one in double mode) and marks it received.
 *
 * symbols:
 *   WmGetSharedDataAddress  0x02090B6C  arm
 *   MIi_CpuCopy16           0x02082A60  arm
 *   MIi_CpuClear16          0x02082A48  arm
 *   OS_DisableInterrupts    0x02087988  arm
 *   OS_RestoreInterrupts    0x0208799C  arm
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

extern u16 *WmGetSharedDataAddress(WMDataSharingInfo *dsInfo, u32 aidBitmap, u16 *receiveBuf, u32 aid);
extern void MIi_CpuCopy16(const void *srcp, void *destp, u32 size);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);

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
