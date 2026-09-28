/*
 * function: func_02082A1C
 * address:  0x02082A1C
 * packet:   pkt_02082A1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MIi_DMAFastCallback (libmi.TWL.HYB.a mi_dma_gxcommand.o)
 *
 * symbols:
 *   MIi_GXDmaParams                0x02150E6C  data
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

static inline void MIi_CallCallback(MIDmaCallback callback, void *arg)
{
    if (callback) {
        (callback)(arg);
    }
}

void func_02082A1C(void)
{
    MIi_GXDmaParams.isBusy = 0;
    MIi_CallCallback(MIi_GXDmaParams.callback, MIi_GXDmaParams.arg);
}
