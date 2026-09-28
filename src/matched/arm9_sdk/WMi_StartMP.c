/*
 * function: WMi_StartMP
 * address:  0x0208FA28
 * packet:   pkt_0208FA28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libwm wm_mp.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Starts MP communication as parent or child: checks the state, power mode,
 * that MP is not already running and the buffer size alignment (and, unless
 * the precheck is disabled, the minimum sizes), registers the callback, then
 * builds a WMStartMPReq with a zeroed WMMPParam and a copy of the temporary
 * parameters and sends it to the ARM7.
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
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
typedef int BOOL;

typedef int WMErrCode;
typedef void (*WMCallbackFunc)(void *arg);

#define WM_ERRCODE_SUCCESS        0
#define WM_ERRCODE_OPERATING      2
#define WM_ERRCODE_ILLEGAL_STATE  3
#define WM_ERRCODE_INVALID_PARAM  6

#define WM_STATE_PARENT  7
#define WM_STATE_CHILD   8
#define WM_APIID_START_MP 14

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

typedef struct WMStatus {
    u8 pad00[0xC];
    BOOL mp_flag;
    u8 pad10[0x9C - 0x10];
    u16 mp_ignoreSizePrecheckMode;
    u8 pad9E[0xC6 - 0x9E];
    u16 pwrMgtMode;
    u8 padC8[0x188 - 0xC8];
    u16 aid;
} WMStatus;

typedef struct WMArm9Buf {
    void *WM7;
    WMStatus *status;
} WMArm9Buf;

extern WMArm9Buf *WMi_GetSystemWork(void);
extern WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern int WM_GetMPReceiveBufferSize(void);
extern int WM_GetMPSendBufferSize(void);
extern void WMi_SetCallbackTable(int id, WMCallbackFunc callback);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern void MIi_CpuCopy32(const void *srcp, void *destp, u32 size);
extern WMErrCode WMi_SendCommandDirect(void *data, u32 length);

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
