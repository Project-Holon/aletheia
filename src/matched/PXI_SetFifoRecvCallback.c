/*
 * function: PXI_SetFifoRecvCallback
 * address:  0x020885A0
 * packet:   pkt_020885A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libpxi pxi_fifo.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * pxiHandleChecker[PXI_PROC_ARM9] lives in the OS system work area at
 * HW_MAIN_MEM_SYSTEM (0x02FFFC00) + 0x388.
 *
 * symbols:
 *   OS_DisableInterrupts   0x02087988  arm
 *   OS_RestoreInterrupts   0x0208799C  arm
 *   FifoRecvCallbackTable  0x021513A8  data
 */

typedef unsigned long u32;
typedef unsigned char u8;
typedef u32 OSIntrMode;
typedef enum PXIFifoTag { PXI_FIFO_TAG_EX = 0, PXI_MAX_FIFO_TAG = 32 } PXIFifoTag;
typedef void (*PXIFifoCallback)(PXIFifoTag tag, u32 data, int err);

typedef struct OSSystemWork {
    u8 pad[0x388];
    u32 pxiHandleChecker[2];
} OSSystemWork;

static inline OSSystemWork *OS_GetSystemWork(void)
{
    return (OSSystemWork *)0x02FFFC00;
}

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern PXIFifoCallback FifoRecvCallbackTable[32];

void PXI_SetFifoRecvCallback(int fifotag, PXIFifoCallback callback)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    FifoRecvCallbackTable[fifotag] = callback;
    if (callback) {
        OS_GetSystemWork()->pxiHandleChecker[0] |= ((u32)1 << fifotag);
    } else {
        OS_GetSystemWork()->pxiHandleChecker[0] &= ~((u32)1 << fifotag);
    }
    (void)OS_RestoreInterrupts(enabled);
}
