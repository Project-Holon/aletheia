/*
 * function: func_0208E038
 * address:  0x0208E038
 * packet:   pkt_0208E038
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WmInitCore (libwm.TWL.HYB.a wm_system.o, static)
 *           Both counted loops are entered with a b to their bottom test and the constant
 *           first test is not folded; a loop condition written as `(c) ? 1 : 0` keeps that
 *           form (docs/idioms/a-loop-entered-by-a-branch-to-its-bottom-test-has-a-ternary-condition.md).
 *           The fifo header store is spelled as a halfword index into the whole buffer:
 *           with `*(u16 *)fifoBuf[i]` the buffer base and 0x8000 swap registers (r4/sl).
 *           wm_system.o .bss: wmInitialized (u16) at +0 and wm9buf at +4 share one pool
 *           word; bufMsgQ, bufMsg and fifoBuf each have their own.
 *
 * symbols:
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
 *   WmClearFifoRecvFlag              0x0208E9A4 arm
 *   OS_InitMessageQueue              0x02085D94 arm
 *   DC_StoreRange                    0x020862D4 arm
 *   OS_SendMessage                   0x02085DBC arm
 *   PXI_SetFifoRecvCallback          0x020885A0 arm
 *   WmReceiveFifo                    0x0208E5BC arm
 *   wmSystemBss                      0x02153058 data
 *   bufMsgQ                          0x02153070 data
 *   bufMsg                           0x02153090 data
 *   fifoBuf                          0x02153100 data
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long s32;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef enum WMErrCode {
    WM_ERRCODE_SUCCESS = 0,
    WM_ERRCODE_ILLEGAL_STATE = 3,
    WM_ERRCODE_WM_DISABLE = 4,
    WM_ERRCODE_INVALID_PARAM = 6,
    WM_ERRCODE_MAX = 0x7FFFFFFF
} WMErrCode;

typedef void (*WMCallbackFunc)(void *arg);

typedef struct WMArm9Buf {
    void *WM7;                            /* +0x000 */
    void *status;                         /* +0x004 */
    u32 *indbuf;                          /* +0x008 */
    u32 *fifo9to7;                        /* +0x00C */
    u32 *fifo7to9;                        /* +0x010 */
    u16 dmaNo;                            /* +0x014 */
    u16 scanOnlyFlag;                     /* +0x016 */
    WMCallbackFunc CallbackTable[44];     /* +0x018 */
    WMCallbackFunc indCallback;           /* +0x0C8 */
    WMCallbackFunc portCallbackTable[16]; /* +0x0CC */
    void *portCallbackArgument[16];       /* +0x10C */
    u32 connectedAidBitmap;               /* +0x14C */
    u16 myAid;                            /* +0x150 */
} WMArm9Buf;

typedef struct OSMessageQueue {
    u32 opaque[8];
} OSMessageQueue;

typedef struct WmSystemBss {
    u16 wmInitialized;
    WMArm9Buf *wm9buf;
} WmSystemBss;

extern WmSystemBss wmSystemBss;
extern OSMessageQueue bufMsgQ;
extern void *bufMsg[10];
extern u32 fifoBuf[10][64];

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern BOOL OS_IsRunOnTwl(void);
extern int NWM_CheckInitialized(void);
extern BOOL OS_IsOnVram(void *ptr);
extern BOOL OS_IsOnExtendedMainMemory(void *ptr);
extern void PXI_Init(void);
extern BOOL PXI_IsCallbackReady(int fifotag, int proc);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
extern void MIi_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size, BOOL dmaEnable);
extern void WmClearFifoRecvFlag(void);
extern void OS_InitMessageQueue(OSMessageQueue *mq, void **msgArray, s32 msgCount);
extern BOOL OS_SendMessage(OSMessageQueue *mq, void *msg, s32 flags);
extern void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int tag, u32 data, BOOL err));
extern void WmReceiveFifo(int tag, u32 fifo_buf_adr, BOOL err);

WMErrCode func_0208E038(void *wmSysBuf, u16 dmaNo, u32 bufSize)
{
    OSIntrMode e;

    e = OS_DisableInterrupts();

    if (OS_IsRunOnTwl()) {
        if (NWM_CheckInitialized() != 3) {
            (void)OS_RestoreInterrupts(e);
            return WM_ERRCODE_ILLEGAL_STATE;
        }
    }
    if (wmSystemBss.wmInitialized) {
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

    wmSystemBss.wm9buf = (WMArm9Buf *)wmSysBuf;
    wmSystemBss.wm9buf->WM7 = (void *)((u32)wmSystemBss.wm9buf + 0x200);
    wmSystemBss.wm9buf->status = (void *)((u32)wmSystemBss.wm9buf->WM7 + 0x300);
    wmSystemBss.wm9buf->fifo9to7 = (u32 *)((u32)wmSystemBss.wm9buf->status + 0x800);
    wmSystemBss.wm9buf->fifo7to9 = (u32 *)((u32)wmSystemBss.wm9buf->fifo9to7 + 0x100);

    WmClearFifoRecvFlag();

    wmSystemBss.wm9buf->dmaNo = dmaNo;
    wmSystemBss.wm9buf->connectedAidBitmap = 0;
    wmSystemBss.wm9buf->myAid = 0;

    {
        s32 i;

        for (i = 0; (i < 16) ? 1 : 0; i++) {
            wmSystemBss.wm9buf->portCallbackTable[i] = 0;
            wmSystemBss.wm9buf->portCallbackArgument[i] = 0;
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

    wmSystemBss.wmInitialized = 1;
    (void)OS_RestoreInterrupts(e);
    return WM_ERRCODE_SUCCESS;
}
