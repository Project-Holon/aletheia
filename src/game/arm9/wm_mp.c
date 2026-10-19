/*
 * file:     wm_mp.c
 * unit:     yes
 * function: WMi_StartMP, WM_StartMPEx, WM_StartMP, WM_SetMPDataToPortEx, WM_EndMP
 * address:  0x0208FA28
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
 *   WMi_GetSystemWork          0x0208E4BC  arm
 *   WMi_CheckStateEx           0x0208E52C  arm
 *   DC_InvalidateRange         0x020862B8  arm
 *   WM_GetMPReceiveBufferSize  0x0208ECA4  arm
 *   WM_GetMPSendBufferSize     0x0208EC34  arm
 *   WMi_SetCallbackTable       0x0208E328  arm
 *   MIi_CpuClear32             0x02082A7C  arm
 *   MIi_CpuCopy32              0x02082A90  arm
 *   WMi_SendCommandDirect      0x0208E44C  arm
 *   DC_StoreRange       0x020862D4  arm
 *   WMi_SendCommand     0x0208E3A0  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef long s32;

typedef int BOOL;

typedef void (*WMCallbackFunc)(void *arg);

typedef struct WMMPParam {
    u32 mask;
    u16 minFrequency;
    u16 frequency;
    u16 maxFrequency;
    u16 defaultRetryCount;
    u8 minPollBmpMode;
    u8 singlePacketMode;
    u8 ignoreFatalErrorMode;
    u8 ignoreSizePrecheckMode;
    u16 parentInterval;
    u16 childInterval;
    u16 parentVCount;
    u16 childVCount;
    u8 reserved[4];
} WMMPParam;

typedef struct WMMPTmpParam {
    u32 mask;
    u16 minFrequency;
    u16 frequency;
    u16 maxFrequency;
    u16 defaultRetryCount;
    u8 minPollBmpMode;
    u8 singlePacketMode;
    u8 ignoreFatalErrorMode;
    u8 reserved[1];
} WMMPTmpParam;

typedef struct WMStartMPReq {
    u16 apiid;
    u16 rsv1;
    u32 *recvBuf;
    u32 recvBufSize;
    u32 *sendBuf;
    u32 sendBufSize;
    WMMPParam param;
    WMMPTmpParam tmpParam;
} WMStartMPReq;

typedef short s16;

typedef u32 OSIntrMode;

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

typedef struct WMStatus {
    u16 state;
    u8 pad02[0xA];
    BOOL mp_flag;
    u8 pad10[0x7C - 0x10];
    u32 *mp_sendBuf;
    u16 mp_sendBufSize;
    u16 mp_ackTime;
    u16 mp_waitAckFlag;
    u16 mp_readyBitmap;
    u8 pad88[0x9C - 0x88];
    u16 mp_ignoreSizePrecheckMode;
    u8 pad9E[0xC6 - 0x9E];
    u16 pwrMgtMode;
    u8 padC8[0x182 - 0xC8];
    u16 child_bitmap;
    struct WMBssDesc *pInfoBuf;
    u16 aid;
} WMStatus;

typedef struct WMArm9Buf {
    struct WMArm7Buf *WM7;
    struct WMStatus *status;
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

typedef enum WMApiid {
    WM_APIID_SET_MP_DATA = 15,
    WM_APIID_MAX = 0x7FFFFFFF
} WMApiid;

extern void *WMi_GetSystemWork(void);
extern WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern int WM_GetMPReceiveBufferSize(void);
extern int WM_GetMPSendBufferSize(void);
extern void WMi_SetCallbackTable(int id, WMCallbackFunc callback);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern void MIi_CpuCopy32(const void *srcp, void *destp, u32 size);
extern WMErrCode WMi_SendCommandDirect(void *data, u32 length);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
extern WMErrCode WMi_SendCommand(WMApiid id, u16 paramNum, ...);
WMErrCode WMi_StartMP(WMCallbackFunc callback, u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize, WMMPTmpParam *tmpParam);
WMErrCode WM_StartMPEx(WMCallbackFunc callback, u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize, u16 mpFreq, u16 defaultRetryCount, BOOL minPollBmpMode, BOOL singlePacketMode, BOOL fixFreqMode, BOOL ignoreFatalError);
WMErrCode WM_StartMP(WMCallbackFunc callback, u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize, u16 mpFreq);
WMErrCode WM_SetMPDataToPortEx(WMCallbackFunc callback, void *arg, u16 *sendData, u16 sendDataSize, u16 destBitmap, u16 port, u16 prio);
WMErrCode WM_EndMP(WMCallbackFunc callback);

#define WM_ERRCODE_SUCCESS        0

#define WM_ERRCODE_OPERATING      2

#define WM_ERRCODE_ILLEGAL_STATE  3

#define WM_ERRCODE_INVALID_PARAM  6

#define WM_STATE_PARENT  7

#define WM_STATE_CHILD   8

#define WM_APIID_START_MP 14

WMErrCode WMi_StartMP(WMCallbackFunc callback, u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize, WMMPTmpParam *tmpParam)
{
    WMErrCode result;
    WMArm9Buf *p = WMi_GetSystemWork();
    WMStatus *status = p->status;
    WMStartMPReq Req;

    result = WMi_CheckStateEx(2, WM_STATE_PARENT, WM_STATE_CHILD);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    DC_InvalidateRange(&status->aid, 2);
    DC_InvalidateRange(&status->pwrMgtMode, 2);
    if (status->aid != 0 && status->pwrMgtMode != 1) {
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    DC_InvalidateRange(&status->mp_flag, 4);
    if (status->mp_flag == 1) {
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    if ((recvBufSize & 0x3f) != 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if ((sendBufSize & 0x1f) != 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    DC_InvalidateRange(&status->mp_ignoreSizePrecheckMode, 2);
    if (status->mp_ignoreSizePrecheckMode == 0) {
        if (recvBufSize < WM_GetMPReceiveBufferSize()) {
            return WM_ERRCODE_INVALID_PARAM;
        }
        if (sendBufSize < WM_GetMPSendBufferSize()) {
            return WM_ERRCODE_INVALID_PARAM;
        }
    }

    WMi_SetCallbackTable(WM_APIID_START_MP, callback);

    MIi_CpuClear32(0, &Req, sizeof(Req));
    Req.apiid = WM_APIID_START_MP;
    Req.recvBuf = (u32 *)recvBuf;
    Req.recvBufSize = (u32)(recvBufSize / 2);
    Req.sendBuf = (u32 *)sendBuf;
    Req.sendBufSize = (u32)sendBufSize;
    MIi_CpuClear32(0, &Req.param, sizeof(Req.param));
    MIi_CpuCopy32(tmpParam, &Req.tmpParam, sizeof(Req.tmpParam));

    result = WMi_SendCommandDirect(&Req, sizeof(Req));
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}

/*
 * sdk:      WM_StartMPEx (libwm.TWL.HYB.a(wm_mp.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode WM_StartMPEx(WMCallbackFunc callback, u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize, u16 mpFreq, u16 defaultRetryCount, BOOL minPollBmpMode, BOOL singlePacketMode, BOOL fixFreqMode, BOOL ignoreFatalError)
{
    WMMPTmpParam tmpParam;

    MIi_CpuClear32(0, &tmpParam, sizeof(tmpParam));
    tmpParam.mask = 0x0001 | 0x0002 | 0x0200 | 0x0400 | 0x0800 | 0x1000;
    tmpParam.minFrequency = mpFreq;
    tmpParam.frequency = mpFreq;
    tmpParam.defaultRetryCount = defaultRetryCount;
    tmpParam.minPollBmpMode = (u8)minPollBmpMode;
    tmpParam.singlePacketMode = (u8)singlePacketMode;
    tmpParam.ignoreFatalErrorMode = (u8)ignoreFatalError;

    if (fixFreqMode && mpFreq != 0) {
        tmpParam.mask |= 0x0004;
        tmpParam.maxFrequency = mpFreq;
    }

    return WMi_StartMP(callback, recvBuf, recvBufSize, sendBuf, sendBufSize, &tmpParam);
}

/*
 * sdk:      WM_StartMP (libwm.TWL.HYB.a(wm_mp.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode WM_StartMP(WMCallbackFunc callback, u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize, u16 mpFreq)
{
    WMMPTmpParam tmpParam;

    MIi_CpuClear32(0, &tmpParam, sizeof(tmpParam));
    tmpParam.mask = 1 | 2;
    tmpParam.minFrequency = mpFreq;
    tmpParam.frequency = mpFreq;

    return WMi_StartMP(callback, recvBuf, recvBufSize, sendBuf, sendBufSize, &tmpParam);
}

WMErrCode WM_SetMPDataToPortEx(WMCallbackFunc callback, void *arg, u16 *sendData, u16 sendDataSize,
                               u16 destBitmap, u16 port, u16 prio)
{
    WMErrCode result;
    u16 childBitmap = 1;
    WMArm9Buf *p = WMi_GetSystemWork();
    WMStatus *status = p->status;

    result = WMi_CheckStateEx(2, 9, 10);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    DC_InvalidateRange(&status->aid, 2);
    if (status->aid == 0) {
        DC_InvalidateRange(&status->child_bitmap, 2);
        childBitmap = status->child_bitmap;
        DC_InvalidateRange(&status->mp_readyBitmap, 2);
    }

    if (sendData == 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (childBitmap == 0) {
        return WM_ERRCODE_NO_ENTRY;
    }

    DC_InvalidateRange(&status->mp_sendBuf, 2);
    if ((u32 *)sendData == status->mp_sendBuf) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (sendDataSize > 512) {
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (sendDataSize == 0) {
        return WM_ERRCODE_INVALID_PARAM;
    }

    DC_StoreRange(sendData, sendDataSize);

    result = WMi_SendCommand(WM_APIID_SET_MP_DATA, 7, sendData, sendDataSize, destBitmap, port,
                             prio, callback, arg);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}

/*
 * sdk:      WM_EndMP (libwm.TWL.HYB.a(wm_mp.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
WMErrCode WM_EndMP(WMCallbackFunc callback)
{
    WMErrCode result;
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckStateEx(2, 9, 10);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    DC_InvalidateRange(&p->status->mp_flag, 4);
    if (!p->status->mp_flag) {
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    WMi_SetCallbackTable(16, callback);
    result = WMi_SendCommand(16, 0);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }
    return WM_ERRCODE_OPERATING;
}
