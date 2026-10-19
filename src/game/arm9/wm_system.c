/*
 * file:     wm_system.c
 * unit:     yes
 * function: WM_Init, WmInitCore, WM_Finish, WMi_SetCallbackTable, WmGetCommandBuffer4Arm7, WMi_SendCommand, WMi_SendCommandDirect, WMi_GetSystemWork, WMi_CheckInitialized, WMi_CheckIdle, WMi_CheckStateEx, WmReceiveFifo, WmClearFifoRecvFlag, WMi_GetStatusAddress, WM_GetAID, WM_GetConnectedAIDs, WMi_RegisterSleepCallback, WMi_DeleteSleepCallback, WmSleepCallback, WMi_CheckEnableFlag
 * address:  0x0208E010
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
 *   g_02153058                     0x02153058  data
 *   WmInitCore                     0x0208E038  arm
 *   OS_DisableInterrupts             0x02087988 arm
 *   OS_IsRunOnTwl                    0x02085D3C arm
 *   NWM_CheckInitialized             0x02090ED8 arm
 *   OS_RestoreInterrupts             0x0208799C arm
 *   OS_IsOnVram                      0x02086CBC arm
 *   OS_IsOnExtendedMainMemory        0x02086C70 arm
 *   PXI_Init                         0x02088498 arm
 *   PXI_IsCallbackReady              0x020885EC arm
 *   DC_InvalidateRange               0x020862B8 arm
 *   MIi_DmaFill32                    0x020821C0 arm
 *   OS_InitMessageQueue              0x02085D94 arm
 *   DC_StoreRange                    0x020862D4 arm
 *   OS_SendMessage                   0x02085DBC arm
 *   PXI_SetFifoRecvCallback          0x020885A0 arm
 *   bufMsgQ                          0x02153070 data
 *   bufMsg                           0x02153090 data
 *   fifoBuf                          0x02153100 data
 *   OS_ReceiveMessage   0x02085E50  arm
 *   OS_JamMessage       0x02085EF0  arm
 *   PXI_SendWordByFifo       0x02088610  arm
 *   MI_CpuCopy8                    0x02082D44  arm
 *   gWmSystemWork  0x02153058  data
 *   g_021530B8               0x021530B8  data
 *   OS_Terminate             0x02088234  arm
 *   WMi_DeleteSleepCallback  0x0208EA80  arm
 *   MI_CpuFill8              0x02082BCC  arm
 *   MIi_CpuCopy16            0x02082A60  arm
 *   MIi_CpuClear16           0x02082A48  arm
 *   PMi_InsertPreSleepCallbackEx   0x0208C848  arm
 *   OS_IsAvailableWireless           0x02087dc4 arm
 *   OS_IsForceDisableWireless        0x02087e84 arm
 *   PM_DeletePreSleepCallback  0x0208C86C  arm
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
    WM_ERRCODE_NO_DATASET = 5,
    WM_ERRCODE_INVALID_PARAM = 6,
    WM_ERRCODE_NO_ENTRY = 7,
    WM_ERRCODE_FIFO_ERROR = 8,
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

typedef struct PMiGenCallbackInfo {
    void (*callback)(void *);
    void *arg;
    int priority;
    struct PMiGenCallbackInfo *next;
} PMGenCallbackInfo;

/* wm_system.o .bss, addressed section-relative from one pool word */
typedef struct WmSystemBss {
    u16 wmInitialized;
    WMArm9Buf *wm9buf;
    PMGenCallbackInfo sleepCbInfo;
} WmSystemBss;

typedef void *OSMessage;

typedef struct _OSThreadQueue {
    struct _OSThread *head;
    struct _OSThread *tail;
} OSThreadQueue;

typedef struct OSMessageQueue {
    OSThreadQueue queueSend;
    OSThreadQueue queueReceive;
    OSMessage *msgArray;
    s32 msgCount;
    s32 firstIndex;
    s32 usedCount;
} OSMessageQueue;

typedef enum WMApiid {
    WM_APIID_MAX = 0x7FFFFFFF
} WMApiid;

typedef char *va_list;

struct WMSystemWork {
    void *reserved;
    void *work;
};

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

typedef short s16;

extern WMErrCode WmInitCore(void *wmSysBuf, u16 dmaNo, u32 bufSize);
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern BOOL OS_IsRunOnTwl(void);
extern u32 NWM_CheckInitialized(void);
extern BOOL OS_IsOnVram(void *ptr);
extern BOOL OS_IsOnExtendedMainMemory(void *ptr);
extern void PXI_Init(void);
extern BOOL PXI_IsCallbackReady(int fifotag, int proc);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
extern void MIi_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size, BOOL dmaEnable);
extern void OS_InitMessageQueue(OSMessageQueue *mq, void **msgArray, s32 msgCount);
extern BOOL OS_SendMessage(OSMessageQueue *mq, OSMessage msg, s32 flags);
extern void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int tag, u32 data, BOOL err));
extern BOOL OS_ReceiveMessage(OSMessageQueue *mq, OSMessage *msg, s32 flags);
extern BOOL OS_JamMessage(OSMessageQueue *mq, OSMessage msg, s32 flags);
extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void OS_Terminate(void);
extern void WMi_DeleteSleepCallback(void);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void MIi_CpuCopy16(const void *srcp, void *destp, u32 size);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern void PMi_InsertPreSleepCallbackEx(struct PMiGenCallbackInfo *info, s32 priority);
extern void PM_DeletePreSleepCallback(struct PMiGenCallbackInfo *info);
extern BOOL OS_IsAvailableWireless(void);
extern BOOL OS_IsForceDisableWireless(void);
WMErrCode WM_Init(void *wmSysBuf, u16 dmaNo);
WMErrCode WM_Finish(void);
void WMi_SetCallbackTable(int id, WMCallbackFunc callback);
u32 *WmGetCommandBuffer4Arm7(void);
WMErrCode WMi_SendCommand(WMApiid id, u16 paramNum, ...);
WMErrCode WMi_SendCommandDirect(void *data, u32 length);
void *WMi_GetSystemWork(void);
WMErrCode WMi_CheckInitialized(void);
WMErrCode WMi_CheckIdle(void);
WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
void WmReceiveFifo(int tag, u32 fifo_buf_adr, BOOL err);
void WmClearFifoRecvFlag(void);
WMStatus *WMi_GetStatusAddress(void);
u16 WM_GetAID(void);
u16 WM_GetConnectedAIDs(void);
void WMi_RegisterSleepCallback(void);
void WmSleepCallback(void *arg);
BOOL WMi_CheckEnableFlag(void);
extern WmSystemBss g_02153058;
extern OSMessageQueue bufMsgQ;
extern void *bufMsg[10];
extern u32 fifoBuf[10][64];
extern struct WMSystemWork gWmSystemWork;
/* the function-static cb_Port of WmReceiveFifo, in the same .bss */
extern WMPortRecvCallback g_021530B8;





WMErrCode WM_Init(void *wmSysBuf, u16 dmaNo)
{
    WMErrCode result = WmInitCore(wmSysBuf, dmaNo, 0xF00);

    if (result == WM_ERRCODE_SUCCESS) {
        g_02153058.wm9buf->scanOnlyFlag = 0;
    }
    return result;
}





/*
 * sdk:      WmInitCore (libwm.TWL.HYB.a wm_system.o, static)
 *           Both counted loops are entered with a b to their bottom test and the constant
 *           first test is not folded; a loop condition written as `(c) ? 1 : 0` keeps that
 *           form (docs/idioms/a-loop-entered-by-a-branch-to-its-bottom-test-has-a-ternary-condition.md).
 *           The fifo header store is spelled as a halfword index into the whole buffer:
 *           with `*(u16 *)fifoBuf[i]` the buffer base and 0x8000 swap registers (r4/sl).
 *           wm_system.o .bss: wmInitialized (u16) at +0 and wm9buf at +4 share one pool
 *           word; bufMsgQ, bufMsg and fifoBuf each have their own.
 */
WMErrCode WmInitCore(void *wmSysBuf, u16 dmaNo, u32 bufSize)
{
    OSIntrMode e;

    e = OS_DisableInterrupts();

    if (OS_IsRunOnTwl()) {
        if (NWM_CheckInitialized() != 3) {
            (void)OS_RestoreInterrupts(e);
            return WM_ERRCODE_ILLEGAL_STATE;
        }
    }
    if (g_02153058.wmInitialized) {
        (void)OS_RestoreInterrupts(e);
        return WM_ERRCODE_ILLEGAL_STATE;
    }
    if (wmSysBuf == 0) {
        (void)OS_RestoreInterrupts(e);
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (OS_IsOnVram(wmSysBuf) || (OS_IsRunOnTwl() && OS_IsOnExtendedMainMemory(wmSysBuf))) {
        (void)OS_RestoreInterrupts(e);
        return WM_ERRCODE_INVALID_PARAM;
    }
    if (dmaNo > 3) {
        (void)OS_RestoreInterrupts(e);
        return WM_ERRCODE_INVALID_PARAM;
    }
    if ((u32)wmSysBuf & 0x1F) {
        (void)OS_RestoreInterrupts(e);
        return WM_ERRCODE_INVALID_PARAM;
    }

    PXI_Init();
    if (!PXI_IsCallbackReady(10, 1)) {
        (void)OS_RestoreInterrupts(e);
        return WM_ERRCODE_WM_DISABLE;
    }

    DC_InvalidateRange(wmSysBuf, bufSize);
    MIi_DmaFill32(dmaNo, wmSysBuf, 0, bufSize, 1);

    g_02153058.wm9buf = (WMArm9Buf *)wmSysBuf;
    g_02153058.wm9buf->WM7 = (void *)((u32)g_02153058.wm9buf + 0x200);
    g_02153058.wm9buf->status = (void *)((u32)g_02153058.wm9buf->WM7 + 0x300);
    g_02153058.wm9buf->fifo9to7 = (u32 *)((u32)g_02153058.wm9buf->status + 0x800);
    g_02153058.wm9buf->fifo7to9 = (u32 *)((u32)g_02153058.wm9buf->fifo9to7 + 0x100);

    WmClearFifoRecvFlag();

    g_02153058.wm9buf->dmaNo = dmaNo;
    g_02153058.wm9buf->connectedAidBitmap = 0;
    g_02153058.wm9buf->myAid = 0;

    {
        s32 i;

        for (i = 0; (i < 16) ? 1 : 0; i++) {
            g_02153058.wm9buf->portCallbackTable[i] = 0;
            g_02153058.wm9buf->portCallbackArgument[i] = 0;
        }
    }

    OS_InitMessageQueue(&bufMsgQ, bufMsg, 10);
    {
        s32 i;

        for (i = 0; (i < 10) ? 1 : 0; i++) {
            ((u16 *)fifoBuf)[i * (sizeof(fifoBuf[0]) / sizeof(u16))] = 0x8000;
            DC_StoreRange(fifoBuf[i], 2);
            (void)OS_SendMessage(&bufMsgQ, fifoBuf[i], 1);
        }
    }

    PXI_SetFifoRecvCallback(10, WmReceiveFifo);

    g_02153058.wmInitialized = 1;
    (void)OS_RestoreInterrupts(e);
    return WM_ERRCODE_SUCCESS;
}







WMErrCode WM_Finish(void)
{
    OSIntrMode e;
    WMErrCode result;

    e = OS_DisableInterrupts();
    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        (void)OS_RestoreInterrupts(e);
        return WM_ERRCODE_ILLEGAL_STATE;
    }

    result = WMi_CheckStateEx(1, 0);
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    WmClearFifoRecvFlag();
    PXI_SetFifoRecvCallback(10, 0);
    g_02153058.wm9buf = 0;
    g_02153058.wmInitialized = 0;
    (void)OS_RestoreInterrupts(e);
    return WM_ERRCODE_SUCCESS;
}







void WMi_SetCallbackTable(int id, WMCallbackFunc callback)
{
    g_02153058.wm9buf->CallbackTable[id] = callback;
}







u32 *WmGetCommandBuffer4Arm7(void)
{
    u32 *tmpAddr;

    if (OS_ReceiveMessage(&bufMsgQ, (OSMessage *)&tmpAddr, 0) == 0) {
        return 0;
    }
    DC_InvalidateRange(tmpAddr, 2);
    if (*(u16 *)tmpAddr & 0x8000) {
        return tmpAddr;
    }
    (void)OS_JamMessage(&bufMsgQ, tmpAddr, 1);
    return 0;
}





#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))





#define __va_size(t) ((sizeof(t) + 3) & ~3u)





#define va_arg(ap, t) (*(t *)((ap += __va_size(t)) - __va_size(t)))





#define va_end(v)






WMErrCode WMi_SendCommand(WMApiid id, u16 paramNum, ...)
{
    va_list vlist;
    s32 i;
    int result;
    u32 *tmpAddr;

    tmpAddr = WmGetCommandBuffer4Arm7();
    if (tmpAddr == 0) {
        return WM_ERRCODE_FIFO_ERROR;
    }

    *(u16 *)tmpAddr = (u16)id;
    va_start(vlist, paramNum);
    for (i = 0; i < paramNum; i++) {
        tmpAddr[i + 1] = va_arg(vlist, u32);
    }
    va_end(vlist);

    DC_StoreRange(tmpAddr, 0x100);
    result = PXI_SendWordByFifo(10, (u32)tmpAddr, 0);
    (void)OS_SendMessage(&bufMsgQ, tmpAddr, 1);
    if (result < 0) {
        return WM_ERRCODE_FIFO_ERROR;
    }
    return WM_ERRCODE_OPERATING;
}









WMErrCode WMi_SendCommandDirect(void *data, u32 length)
{
    u32 *tmpAddr;
    int result;

    tmpAddr = WmGetCommandBuffer4Arm7();
    if (tmpAddr == 0) {
        return WM_ERRCODE_FIFO_ERROR;
    }

    MI_CpuCopy8(data, tmpAddr, length);
    DC_StoreRange(tmpAddr, length);
    result = PXI_SendWordByFifo(10, (u32)tmpAddr, 0);
    (void)OS_SendMessage(&bufMsgQ, tmpAddr, 1);
    if (result < 0) {
        return WM_ERRCODE_FIFO_ERROR;
    }
    return WM_ERRCODE_OPERATING;
}





/*
 * Function matched as standalone.
 *
 * Global state member accessor.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WMi_GetSystemWork.c \
 *       --func WMi_GetSystemWork --addr 0x0208E4BC --arm
 */
void *WMi_GetSystemWork(void)
{
    return gWmSystemWork.work;
}




WMErrCode WMi_CheckInitialized(void)
{
    if (g_02153058.wmInitialized) {
        return WM_ERRCODE_SUCCESS;
    }
    return WM_ERRCODE_ILLEGAL_STATE;
}

















WMErrCode WMi_CheckIdle(void)
{
    WMErrCode result = WMi_CheckInitialized();

    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    DC_InvalidateRange(&g_02153058.wm9buf->status->state, 2);
    if (g_02153058.wm9buf->status->state == 0 || g_02153058.wm9buf->status->state == 1) {
        return WM_ERRCODE_ILLEGAL_STATE;
    }
    return WM_ERRCODE_SUCCESS;
}






















#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))








#define __va_size(t) ((sizeof(t) + 3) & ~3u)








#define va_arg(ap, t) (*(t *)((ap += __va_size(t)) - __va_size(t)))








#define va_end(v)









WMErrCode WMi_CheckStateEx(s32 paramNum, ...)
{
    WMErrCode result;
    u16 now;
    va_list vlist;

    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        return result;
    }

    DC_InvalidateRange(&g_02153058.wm9buf->status->state, 2);
    now = g_02153058.wm9buf->status->state;

    result = WM_ERRCODE_ILLEGAL_STATE;
    va_start(vlist, paramNum);
    for (; paramNum; paramNum--) {
        if (va_arg(vlist, u32) == now) {
            result = WM_ERRCODE_SUCCESS;
        }
    }
    va_end(vlist);

    return result;
}























void WmReceiveFifo(int tag, u32 fifo_buf_adr, BOOL err)
{
    WMCallback *callback_p = (WMCallback *)fifo_buf_adr;
    WMArm9Buf *w9b = g_02153058.wm9buf;

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
            if (!g_02153058.wmInitialized) {
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







void WmClearFifoRecvFlag(void)
{
    u16 *flag = (u16 *)0x02FFFF96;

    if (*flag & 1) {
        *flag = (u16)(*flag & 0xFFFE);
    }
}














WMStatus *WMi_GetStatusAddress(void)
{
    if (WMi_CheckInitialized() != WM_ERRCODE_SUCCESS) {
        return 0;
    }
    return g_02153058.wm9buf->status;
}














u16 WM_GetAID(void)
{
    u16 myAid;
    OSIntrMode e = OS_DisableInterrupts();

    if (g_02153058.wm9buf != 0) {
        myAid = g_02153058.wm9buf->myAid;
    } else {
        myAid = 0;
    }
    (void)OS_RestoreInterrupts(e);
    return myAid;
}














u16 WM_GetConnectedAIDs(void)
{
    u32 connectedAidBitmap;
    OSIntrMode e = OS_DisableInterrupts();

    if (g_02153058.wm9buf != 0) {
        connectedAidBitmap = g_02153058.wm9buf->connectedAidBitmap;
    } else {
        connectedAidBitmap = 0;
    }
    (void)OS_RestoreInterrupts(e);
    return (u16)connectedAidBitmap;
}








void WMi_RegisterSleepCallback(void)
{
    g_02153058.sleepCbInfo.callback = WmSleepCallback;
    g_02153058.sleepCbInfo.arg = 0;
    PMi_InsertPreSleepCallbackEx(&g_02153058.sleepCbInfo, 1000);
}



void WMi_DeleteSleepCallback(void){ PM_DeletePreSleepCallback((void *)0x02153060); }




void WmSleepCallback(void *arg)
{
    OS_Terminate();
}




/*
 * sdk:      NWMi_CheckEnableFlag (libnwm.TWL.HYB.a(nwm_init.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 */
BOOL WMi_CheckEnableFlag(void)
{
    if (OS_IsAvailableWireless() == 1 && OS_IsForceDisableWireless() == 0) {
        return 1;
    }
    return 0;
}
