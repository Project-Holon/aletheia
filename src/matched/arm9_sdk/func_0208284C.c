/*
 * function: func_0208284C
 * address:  0x0208284C
 * packet:   pkt_0208284C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MIi_FIFOCallback (libmi.TWL.HYB.a mi_dma_gxcommand.o)
 *
 * symbols:
 *   OSi_EnterDmaCallback           0x020848A4  arm
 *   MIi_DmaSetParameters           0x01FF8020  arm
 *   OS_ResetRequestIrqMask         0x020849C8  arm
 *   MIi_GXDmaParams                0x02150E6C  data
 *   MIi_DMACallback                0x02082900  arm
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

void OSi_EnterDmaCallback(u32 dmaNo, MIDmaCallback callback, void *arg);
void MIi_DmaSetParameters(u32 dmaNo, u32 src, u32 dest, u32 ctrl, u32 mode);
u32 OS_ResetRequestIrqMask(u32 intr);
void MIi_DMACallback(void *arg);

void func_0208284C(void)
{
    u32 length;
    u32 src;

    if (MIi_GXDmaParams.length == 0) {
        return;
    }

    length = (MIi_GXDmaParams.length >= 0x1D8) ? 0x1D8 : MIi_GXDmaParams.length;
    src = MIi_GXDmaParams.src;

    MIi_GXDmaParams.length -= length;
    MIi_GXDmaParams.src += length;

    if (MIi_GXDmaParams.length == 0) {
        OSi_EnterDmaCallback(MIi_GXDmaParams.dmaNo, MIi_DMACallback, 0);
        MIi_DmaSetParameters(MIi_GXDmaParams.dmaNo, src, REG_GXFIFO_ADDR, 0xC4400000 | (length / 4), 0);
        (void)OS_ResetRequestIrqMask(0x00200000);
    } else {
        MIi_DmaSetParameters(MIi_GXDmaParams.dmaNo, src, REG_GXFIFO_ADDR, 0x84400000 | (length / 4), 0);
        (void)OS_ResetRequestIrqMask(0x00200000);
    }
}
