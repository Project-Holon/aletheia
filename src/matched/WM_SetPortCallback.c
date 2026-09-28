/*
 * function: WM_SetPortCallback
 * address:  0x0208EB0C
 * packet:   pkt_0208EB0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libwm wm_sync.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Installs
 * the receive callback of one port and, when one is given, calls it once
 * with a port-init notification.
 *
 * symbols:
 *   MI_CpuFill8           0x02082BCC  arm
 *   OS_GetMacAddress      0x02087C6C  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   WMi_CheckInitialized  0x0208E4CC  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   WMi_GetSystemWork     0x0208E4BC  arm
 *   WM_GetConnectedAIDs   0x0208EA1C  arm
 *   WM_GetAID             0x0208E9EC  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long s32;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef enum WMErrCode {
    WM_ERRCODE_SUCCESS = 0,
    WM_ERRCODE_FAILED = 1,
    WM_ERRCODE_OPERATING = 2,
    WM_ERRCODE_ILLEGAL_STATE = 3,
    WM_ERRCODE_WM_DISABLE = 4,
    WM_ERRCODE_MAX = 0x7FFFFFFF
} WMErrCode;

typedef void (*WMCallbackFunc)(void *arg);

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

extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void OS_GetMacAddress(u8 *macAddress);
extern OSIntrMode OS_DisableInterrupts(void);
extern WMErrCode WMi_CheckInitialized(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern WMArm9Buf *WMi_GetSystemWork(void);
extern u16 WM_GetConnectedAIDs(void);
extern u16 WM_GetAID(void);

WMErrCode WM_SetPortCallback(u16 port, WMCallbackFunc callback, void *arg)
{
    WMErrCode result;
    OSIntrMode e;
    WMPortRecvCallback cb_Port;
    WMArm9Buf *p;

    if (callback != 0) {
        MI_CpuFill8(&cb_Port, 0, sizeof(cb_Port));
        cb_Port.apiid = 0x82;
        cb_Port.errcode = WM_ERRCODE_SUCCESS;
        cb_Port.state = 25;
        cb_Port.port = port;
        cb_Port.recvBuf = 0;
        cb_Port.data = 0;
        cb_Port.length = 0;
        cb_Port.seqNo = 0xFFFF;
        cb_Port.arg = arg;
        cb_Port.aid = 0;
        OS_GetMacAddress(cb_Port.macAddress);
    }

    e = OS_DisableInterrupts();
    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        (void)OS_RestoreInterrupts(e);
        return result;
    }

    p = WMi_GetSystemWork();
    p->portCallbackTable[port] = callback;
    p->portCallbackArgument[port] = arg;
    if (callback != 0) {
        cb_Port.connectedAidBitmap = WM_GetConnectedAIDs();
        cb_Port.myAid = WM_GetAID();
        (*callback)(&cb_Port);
    }
    (void)OS_RestoreInterrupts(e);
    return WM_ERRCODE_SUCCESS;
}
