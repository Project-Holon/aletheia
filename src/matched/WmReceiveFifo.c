/*
 * function: WmReceiveFifo
 * address:  0x0208E5BC
 * packet:   pkt_0208E5BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libwm wm_system.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  The PXI
 * FIFO receive callback (static in the vendor object).  fifo_buf_adr and err
 * arrive in r1 and r2 behind the unused tag, which the member's DWARF leaves
 * out.  The object's .bss holds wmInitialized (u16) at +0 and wm9buf at +4,
 * addressed through one section-relative pool word (WmSystemBss); the
 * function-static cb_Port (68 bytes) sits at 0x021530B8 and is relocated by
 * its own symbol.
 *
 * symbols:
 *   g_02153058               0x02153058  data
 *   g_021530B8               0x021530B8  data
 *   DC_InvalidateRange       0x020862B8  arm
 *   DC_StoreRange            0x020862D4  arm
 *   OS_Terminate             0x02088234  arm
 *   WMi_DeleteSleepCallback  0x0208EA80  arm
 *   WM_Finish                0x0208E2B8  arm
 *   MI_CpuFill8              0x02082BCC  arm
 *   MI_CpuCopy8              0x02082D44  arm
 *   MIi_CpuCopy16            0x02082A60  arm
 *   MIi_CpuClear16           0x02082A48  arm
 *   WmClearFifoRecvFlag      0x0208E9A4  arm
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

/* wm_system.o .bss, addressed section-relative from one pool word */
typedef struct WmSystemBss {
    u16 wmInitialized;
    WMArm9Buf *wm9buf;
} WmSystemBss;

extern WmSystemBss g_02153058;
#define wmInitialized (g_02153058.wmInitialized)
#define wm9buf        (g_02153058.wm9buf)

typedef struct WMCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
} WMCallback;

typedef struct WMStartParentCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u8 macAddress[6];
    u16 aid;
    u16 reason;
    u8 ssid[24];
    u16 parentSize;
    u16 childSize;
} WMStartParentCallback;

typedef struct WMStartConnectCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 aid;
    u16 reason;
    u16 wlStatus;
    u8 macAddress[6];
    u16 parentSize;
    u16 childSize;
} WMStartConnectCallback;

typedef struct WMStartMPCallback {
    u16 apiid;
    u16 errcode;
    u16 state;
    u8 reserved[2];
    struct WMMpRecvBuf *recvBuf;
    u16 timeStamp;
    u16 rate_rssi;
    u8 destAdrs[6];
    u8 srcAdrs[6];
    u16 seqNum;
    u16 tmptt;
    u16 pollbmp;
    u16 reserved2;
} WMStartMPCallback;

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

/* the function-static cb_Port of WmReceiveFifo, in the same .bss */
extern WMPortRecvCallback g_021530B8;

extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
extern void OS_Terminate(void);
extern void WMi_DeleteSleepCallback(void);
extern WMErrCode WM_Finish(void);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void MIi_CpuCopy16(const void *srcp, void *destp, u32 size);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern void WmClearFifoRecvFlag(void);

void WmReceiveFifo(int tag, u32 fifo_buf_adr, BOOL err)
{
    WMCallback *callback_p = (WMCallback *)fifo_buf_adr;
    WMArm9Buf *w9b = wm9buf;

    if (err) {
        return;
    }

    DC_InvalidateRange(w9b->fifo7to9, 0x100);
    if (!w9b->scanOnlyFlag) {
        DC_InvalidateRange(w9b->status, 0x800);
    }
    if ((u32)callback_p != (u32)w9b->fifo7to9) {
        DC_InvalidateRange(callback_p, 0x100);
    }

    if (callback_p->apiid >= 44) {
        if (callback_p->apiid == 0x80) {
            if (callback_p->errcode == 19) {
                OS_Terminate();
            }
            if (w9b->indCallback != 0) {
                w9b->indCallback((void *)callback_p);
            }
        } else if (callback_p->apiid == 0x82) {
            WMPortRecvCallback *cb_Port = (WMPortRecvCallback *)callback_p;
            if (w9b->portCallbackTable[cb_Port->port] != 0) {
                cb_Port->arg = w9b->portCallbackArgument[cb_Port->port];
                cb_Port->connectedAidBitmap = (u16)w9b->connectedAidBitmap;
                DC_InvalidateRange(cb_Port->recvBuf, w9b->status->mp_recvBufSize);
                (w9b->portCallbackTable[cb_Port->port])((void *)cb_Port);
            }
        } else if (callback_p->apiid == 0x81) {
            WMPortSendCallback *cb_Port = (WMPortSendCallback *)callback_p;
            callback_p->apiid = 15;
            if (cb_Port->callback) {
                (cb_Port->callback)((void *)cb_Port);
            }
        }
    } else {
        if (callback_p->apiid == 14) {
            WMStartMPCallback *cb_StartMP = (WMStartMPCallback *)callback_p;
            if ((cb_StartMP->state == 11 || cb_StartMP->state == 12)
                && cb_StartMP->errcode == WM_ERRCODE_SUCCESS) {
                DC_InvalidateRange(cb_StartMP->recvBuf, w9b->status->mp_recvBufSize);
            }
        }

        if (((callback_p->apiid == 4 || callback_p->apiid == 2)
             && callback_p->errcode == WM_ERRCODE_SUCCESS)
            || ((callback_p->apiid == 3 || callback_p->apiid == 0)
                && callback_p->errcode != WM_ERRCODE_SUCCESS)) {
            WMi_DeleteSleepCallback();
        }

        if (callback_p->apiid == 2 && callback_p->errcode == WM_ERRCODE_SUCCESS) {
            WMCallbackFunc cb = w9b->CallbackTable[callback_p->apiid];
            (void)WM_Finish();
            if (cb != 0) {
                cb((void *)callback_p);
            }
            return;
        }

        if (w9b->CallbackTable[callback_p->apiid] != 0) {
            (w9b->CallbackTable[callback_p->apiid])((void *)callback_p);
            if (!wmInitialized) {
                return;
            }
        }

        if (callback_p->apiid == 8 || callback_p->apiid == 12) {
            u16 state, aid, myAid, reason;
            u8 *macAddress;
            u8 *ssid;
            u16 parentSize, childSize;

            if (callback_p->apiid == 8) {
                WMStartParentCallback *cb = (WMStartParentCallback *)callback_p;
                state = cb->state;
                aid = cb->aid;
                myAid = 0;
                macAddress = cb->macAddress;
                ssid = cb->ssid;
                reason = cb->reason;
                parentSize = cb->parentSize;
                childSize = cb->childSize;
            } else if (callback_p->apiid == 12) {
                WMStartConnectCallback *cb = (WMStartConnectCallback *)callback_p;
                state = cb->state;
                aid = 0;
                myAid = cb->aid;
                macAddress = cb->macAddress;
                ssid = 0;
                reason = cb->reason;
                parentSize = cb->parentSize;
                childSize = cb->childSize;
            }
            if (state == 7 || state == 9 || state == 26) {
                u16 iPort;

                if (state == 7) {
                    w9b->connectedAidBitmap |= (1 << aid);
                } else {
                    w9b->connectedAidBitmap &= ~(1 << aid);
                }
                w9b->myAid = myAid;

                MI_CpuFill8(&g_021530B8, 0, sizeof(WMPortRecvCallback));
                g_021530B8.apiid = 0x82;
                g_021530B8.errcode = WM_ERRCODE_SUCCESS;
                g_021530B8.state = state;
                g_021530B8.recvBuf = 0;
                g_021530B8.data = 0;
                g_021530B8.length = 0;
                g_021530B8.aid = aid;
                g_021530B8.myAid = myAid;
                g_021530B8.connectedAidBitmap = (u16)w9b->connectedAidBitmap;
                g_021530B8.seqNo = 0xFFFF;
                g_021530B8.reason = reason;
                MI_CpuCopy8(macAddress, g_021530B8.macAddress, 6);
                if (ssid != 0) {
                    MIi_CpuCopy16(ssid, g_021530B8.ssid, 24);
                } else {
                    MIi_CpuClear16(0, g_021530B8.ssid, 24);
                }
                g_021530B8.maxSendDataSize = (u16)((myAid == 0) ? parentSize : childSize);
                g_021530B8.maxRecvDataSize = (u16)((myAid == 0) ? childSize : parentSize);

                for (iPort = 0; iPort < 16; iPort++) {
                    g_021530B8.port = iPort;
                    if (w9b->portCallbackTable[iPort] != 0) {
                        g_021530B8.arg = w9b->portCallbackArgument[iPort];
                        (w9b->portCallbackTable[iPort])((void *)&g_021530B8);
                    }
                }
            }
        }
    }

    DC_InvalidateRange(w9b->fifo7to9, 0x100);
    WmClearFifoRecvFlag();

    if ((u32)callback_p != (u32)w9b->fifo7to9) {
        callback_p->apiid |= 0x8000;
        DC_StoreRange(callback_p, 0x100);
    }
}
