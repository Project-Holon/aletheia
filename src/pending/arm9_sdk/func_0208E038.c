/*
 * function: func_0208E038
 * address:  0x0208E038
 * packet:   pkt_0208E038
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      WmInitCore (libwm.TWL.HYB.a(wm_system.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *           DIFF under -O4,p: both counted loops come out rotated (first test folded); the object enters
 *           each loop with an unconditional b to a bottom test. Under -O2,p the whole body matches
 *           except an r5/r6 swap (e and bufSize), but the rest of wm_system.o is -O4,p only.
 *           static in the object (local symbol WmInitCore).  wm_system.o .bss: wmInitialized (u16)
 *           at +0 and wm9buf at +4 share one pool word (g_02153058, as in WM_Init.c); bufMsgQ,
 *           bufMsg and fifoBuf each have their own pool word.
 *
 * symbols:
 *   OS_DisableInterrupts             0x02087988 arm
 *   OS_IsRunOnTwl                    0x02085d3c arm
 *   NWM_CheckInitialized             0x02090ed8 arm
 *   OS_RestoreInterrupts             0x0208799c arm
 *   OS_IsOnVram                      0x02086cbc arm
 *   OS_IsOnExtendedMainMemory        0x02086c70 arm
 *   PXI_Init                         0x02088498 arm
 *   PXI_IsCallbackReady              0x020885ec arm
 *   DC_InvalidateRange               0x020862b8 arm
 *   MIi_DmaFill32                    0x020821c0 arm
 *   WmClearFifoRecvFlag              0x0208e9a4 arm
 *   OS_InitMessageQueue              0x02085d94 arm
 *   DC_StoreRange                    0x020862d4 arm
 *   OS_SendMessage                   0x02085dbc arm
 *   PXI_SetFifoRecvCallback          0x020885a0 arm
 *   wmInitialized                    0x02153058 data
 *   bufMsgQ                          0x02153070 data
 *   bufMsg                           0x02153090 data
 *   fifoBuf                          0x02153100 data
 *   WmReceiveFifo                    0x0208e5bc arm
 *   g_02153058                       0x02153058 data
 *   g_02153070                       0x02153070 data
 *   g_02153090                       0x02153090 data
 *   g_02153100                       0x02153100 data
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long s32;
typedef short s16;
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
    WM_ERRCODE_MAX = 0x7FFFFFFF
} WMErrCode;

typedef void (*WMCallbackFunc)(void *arg);

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

typedef struct OSMessageQueue {
    u8 opaque[0x20];
} OSMessageQueue;

/* wm_system.o .bss, addressed section-relative from one pool word */
typedef struct WmSystemBss {
    u16 wmInitialized;
    WMArm9Buf *wm9buf;
} WmSystemBss;

extern WmSystemBss g_02153058;
#define wmInitialized (g_02153058.wmInitialized)
#define wm9buf        (g_02153058.wm9buf)
extern OSMessageQueue g_02153070;
#define bufMsgQ g_02153070
extern void *g_02153090[10];
#define bufMsg g_02153090
extern u32 g_02153100[10][64];
#define fifoBuf g_02153100

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern BOOL OS_IsRunOnTwl(void);
extern int NWM_CheckInitialized(void);
extern BOOL OS_IsOnVram(const void *ptr);
extern BOOL OS_IsOnExtendedMainMemory(const void *ptr);
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

    if (wmInitialized) {
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

    wm9buf = (WMArm9Buf *)wmSysBuf;
    wm9buf->WM7 = (struct WMArm7Buf *)((u32)wm9buf + 0x200);
    wm9buf->status = (struct WMStatus *)((u32)wm9buf->WM7 + 0x300);
    wm9buf->fifo9to7 = (u32 *)((u32)wm9buf->status + 0x800);
    wm9buf->fifo7to9 = (u32 *)((u32)wm9buf->fifo9to7 + 0x100);

    WmClearFifoRecvFlag();

    wm9buf->dmaNo = dmaNo;
    wm9buf->connectedAidBitmap = 0;
    wm9buf->myAid = 0;

    {
        s32 i;

        for (i = 0; i < 16; i++) {
            wm9buf->portCallbackTable[i] = 0;
            wm9buf->portCallbackArgument[i] = 0;
        }
    }

    OS_InitMessageQueue(&bufMsgQ, bufMsg, 10);
    {
        s32 i;

        for (i = 0; i < 10; i++) {
            *(u16 *)fifoBuf[i] = 0x8000;
            DC_StoreRange(fifoBuf[i], 2);
            (void)OS_SendMessage(&bufMsgQ, fifoBuf[i], 1);
        }
    }

    PXI_SetFifoRecvCallback(10, WmReceiveFifo);

    wmInitialized = 1;
    (void)OS_RestoreInterrupts(e);
    return WM_ERRCODE_SUCCESS;
}
