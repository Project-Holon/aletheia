/*
 * file:     mi_dma_gxcommand.c
 * unit:     yes
 * function: MI_SendGXCommandAsync, func_0208284C, func_02082900, MI_SendGXCommandAsyncFast, func_02082A1C
 * address:  0x02082760
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
 *   MIi_CheckDma0SourceAddress     0x0208270C  arm
 *   MI_WaitDma                     0x02082594  arm
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_GetIrqFunction              0x02084818  arm
 *   OS_SetIrqFunction              0x02084774  arm
 *   OS_EnableIrqMask               0x02084968  arm
 *   MIi_FIFOCallback               0x0208284C  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   MIi_GXDmaParams                0x02150E6C  data
 *   OSi_EnterDmaCallback           0x020848A4  arm
 *   MIi_DmaSetParameters           0x01FF8020  arm
 *   OS_ResetRequestIrqMask         0x020849C8  arm
 *   MIi_DMACallback                0x02082900  arm
 *   OS_DisableIrqMask              0x02084998  arm
 *   MIi_CheckAnotherAutoDMA        0x02082680  arm
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

void MIi_CheckDma0SourceAddress(u32 dmaNo, u32 src, u32 size, u32 dir);
void MI_WaitDma(u32 dmaNo);
OSIntrMode OS_DisableInterrupts(void);
OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
void OS_SetIrqFunction(u32 intrBit, void (*function)(void));
u32 OS_EnableIrqMask(u32 intr);
void MIi_FIFOCallback(void);
void OSi_EnterDmaCallback(u32 dmaNo, MIDmaCallback callback, void *arg);
void MIi_DmaSetParameters(u32 dmaNo, u32 src, u32 dest, u32 ctrl, u32 mode);
u32 OS_ResetRequestIrqMask(u32 intr);
void MIi_DMACallback(void *arg);
u32 OS_DisableIrqMask(u32 intr);
void MIi_CheckAnotherAutoDMA(u32 dmaNo, u32 dmaType);
void MIi_DMAFastCallback(void *arg);
void MI_SendGXCommandAsync(u32 dmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg);
void func_0208284C(void);
void func_02082900(void);
void MI_SendGXCommandAsyncFast(u32 dmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg);
void func_02082A1C(void);
extern MIiGXDmaParams MIi_GXDmaParams;





#define reg_G3X_GXSTAT (*(vu32 *)0x04000600)




void (*OS_GetIrqFunction(u32 intrBit))(void);





static inline void MIi_CallCallback(MIDmaCallback callback, void *arg)
{
    if (callback) {
        (callback)(arg);
    }
}





static inline u32 G3X_GetFifoStatus(void)
{
    return (reg_G3X_GXSTAT & 0x07000000) >> 24;
}





static inline GXFifoIntrCond G3X_GetFifoIntrCond(void)
{
    return (GXFifoIntrCond)((reg_G3X_GXSTAT & 0xC0000000) >> 30);
}





static inline void G3X_SetFifoIntrCond(GXFifoIntrCond cond)
{
    reg_G3X_GXSTAT = (reg_G3X_GXSTAT & ~0xC0000000) | ((u32)cond << 30);
}





/*
 * sdk:      MI_SendGXCommandAsync (libmi.TWL.HYB.a mi_dma_gxcommand.o)
 */
void MI_SendGXCommandAsync(u32 dmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg)
{
    if (commandLength == 0) {
        MIi_CallCallback(callback, arg);
        return;
    }

    while (MIi_GXDmaParams.isBusy) {
    }
    while (!(G3X_GetFifoStatus() & 2)) {
    }

    MIi_GXDmaParams.isBusy = 1;
    MIi_GXDmaParams.dmaNo = dmaNo;
    MIi_GXDmaParams.src = (u32)src;
    MIi_GXDmaParams.length = commandLength;
    MIi_GXDmaParams.callback = callback;
    MIi_GXDmaParams.arg = arg;

    MIi_CheckDma0SourceAddress(dmaNo, (u32)src, commandLength, 0);
    MI_WaitDma(dmaNo);
    {
        OSIntrMode enabled = OS_DisableInterrupts();

        MIi_GXDmaParams.fifoCond = G3X_GetFifoIntrCond();
        MIi_GXDmaParams.fifoFunc = OS_GetIrqFunction(0x00200000);

        G3X_SetFifoIntrCond(GX_FIFOINTR_COND_UNDERHALF);
        OS_SetIrqFunction(0x00200000, MIi_FIFOCallback);
        (void)OS_EnableIrqMask(0x00200000);

        MIi_FIFOCallback();

        (void)OS_RestoreInterrupts(enabled);
    }
}





#define REG_GXFIFO_ADDR 0x04000400





/*
 * sdk:      MIi_FIFOCallback (libmi.TWL.HYB.a mi_dma_gxcommand.o)
 */
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




#define reg_G3X_GXSTAT (*(vu32 *)0x04000600)




/*
 * sdk:      MIi_DMACallback (libmi.TWL.HYB.a mi_dma_gxcommand.o)
 */
void func_02082900(void)
{
    (void)OS_DisableIrqMask(0x00200000);

    G3X_SetFifoIntrCond(MIi_GXDmaParams.fifoCond);
    OS_SetIrqFunction(0x00200000, MIi_GXDmaParams.fifoFunc);

    MIi_GXDmaParams.isBusy = 0;
    MIi_CallCallback(MIi_GXDmaParams.callback, MIi_GXDmaParams.arg);
}



#define REG_GXFIFO_ADDR 0x04000400



/*
 * sdk:      MI_SendGXCommandAsyncFast (libmi.TWL.HYB.a mi_dma_gxcommand.o)
 */
void MI_SendGXCommandAsyncFast(u32 dmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg)
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


/*
 * sdk:      MIi_DMAFastCallback (libmi.TWL.HYB.a mi_dma_gxcommand.o)
 */
void func_02082A1C(void)
{
    MIi_GXDmaParams.isBusy = 0;
    MIi_CallCallback(MIi_GXDmaParams.callback, MIi_GXDmaParams.arg);
}
