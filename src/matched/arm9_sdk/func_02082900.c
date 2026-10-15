/*
 * function: MIi_DMACallback
 * address:  0x02082900
 * packet:   pkt_02082900
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MIi_DMACallback (libmi.TWL.HYB.a mi_dma_gxcommand.o)
 *
 * symbols:
 *   OS_DisableIrqMask              0x02084998  arm
 *   OS_SetIrqFunction              0x02084774  arm
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

#define reg_G3X_GXSTAT (*(vu32 *)0x04000600)

u32 OS_DisableIrqMask(u32 intr);
void OS_SetIrqFunction(u32 intrBit, void (*function)(void));

static inline void MIi_CallCallback(MIDmaCallback callback, void *arg)
{
    if (callback) {
        (callback)(arg);
    }
}

static inline void G3X_SetFifoIntrCond(GXFifoIntrCond cond)
{
    reg_G3X_GXSTAT = (reg_G3X_GXSTAT & ~0xC0000000) | ((u32)cond << 30);
}

void MIi_DMACallback(void)
{
    (void)OS_DisableIrqMask(0x00200000);

    G3X_SetFifoIntrCond(MIi_GXDmaParams.fifoCond);
    OS_SetIrqFunction(0x00200000, MIi_GXDmaParams.fifoFunc);

    MIi_GXDmaParams.isBusy = 0;
    MIi_CallCallback(MIi_GXDmaParams.callback, MIi_GXDmaParams.arg);
}
