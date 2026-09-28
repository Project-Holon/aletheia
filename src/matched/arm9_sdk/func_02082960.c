/*
 * function: func_02082960
 * address:  0x02082960
 * packet:   pkt_02082960
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MI_SendGXCommandAsyncFast (libmi.TWL.HYB.a mi_dma_gxcommand.o)
 *
 * symbols:
 *   MIi_CheckAnotherAutoDMA        0x02082680  arm
 *   MIi_CheckDma0SourceAddress     0x0208270C  arm
 *   MI_WaitDma                     0x02082594  arm
 *   OSi_EnterDmaCallback           0x020848A4  arm
 *   MIi_DmaSetParameters           0x01FF8020  arm
 *   MIi_GXDmaParams                0x02150E6C  data
 *   MIi_DMAFastCallback            0x02082A1C  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef volatile u32 vu32;
typedef volatile u16 vu16;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef void (*MIDmaCallback)(void *arg);

typedef enum {
    GX_FIFOINTR_COND_DISABLE = 0,
    GX_FIFOINTR_COND_UNDERHALF = 1,
    GX_FIFOINTR_COND_EMPTY = 2
} GXFifoIntrCond;

typedef struct MIiGXDmaParams {
    volatile BOOL isBusy;
    u32 dmaNo;
    u32 src;
    u32 length;
    MIDmaCallback callback;
    void *arg;
    GXFifoIntrCond fifoCond;
    void (*fifoFunc)(void);
} MIiGXDmaParams;

extern MIiGXDmaParams MIi_GXDmaParams;

#define REG_GXFIFO_ADDR 0x04000400

void MIi_CheckAnotherAutoDMA(u32 dmaNo, u32 dmaType);
void MIi_CheckDma0SourceAddress(u32 dmaNo, u32 src, u32 size, u32 dir);
void MI_WaitDma(u32 dmaNo);
void OSi_EnterDmaCallback(u32 dmaNo, MIDmaCallback callback, void *arg);
void MIi_DmaSetParameters(u32 dmaNo, u32 src, u32 dest, u32 ctrl, u32 mode);
void MIi_DMAFastCallback(void *arg);

static inline void MIi_CallCallback(MIDmaCallback callback, void *arg)
{
    if (callback) {
        (callback)(arg);
    }
}

void func_02082960(u32 dmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg)
{
    if (commandLength == 0) {
        MIi_CallCallback(callback, arg);
        return;
    }

    while (MIi_GXDmaParams.isBusy) {
    }

    MIi_GXDmaParams.isBusy = 1;
    MIi_GXDmaParams.dmaNo = dmaNo;
    MIi_GXDmaParams.callback = callback;
    MIi_GXDmaParams.arg = arg;

    MIi_CheckAnotherAutoDMA(dmaNo, 0x38000000);
    MIi_CheckDma0SourceAddress(dmaNo, (u32)src, commandLength, 0);
    MI_WaitDma(dmaNo);

    OSi_EnterDmaCallback(dmaNo, MIi_DMAFastCallback, 0);
    MIi_DmaSetParameters(dmaNo, (u32)src, REG_GXFIFO_ADDR, 0xFC400000 | (commandLength / 4), 0);
}
