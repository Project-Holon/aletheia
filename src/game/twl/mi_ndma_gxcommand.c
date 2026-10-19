/*
 * file:     mi_ndma_gxcommand.c
 * unit:     yes
 * function: MI_SendNDmaGXCommandAsync, MIi_FIFOCallback, MIi_NDMACallback, MI_SendNDmaGXCommandAsyncFast, MIi_NDMAFastCallback
 * address:  0x0272FEF4
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libmi.TWL.HYB.a mi_ndma_gxcomman
 *
 * symbols:
 *   MI_IsNDmaBusy  0x0272FC90  arm twl
 *   data_02732EFC  0x02732EFC  data twl
 *   MIi_CpuCopy32  0x02082A90  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   data_02732F3C  0x02732F3C  data twl
 *   MIi_NDmaAsync_withConfig_Dev  0x0272F9C4  arm twl
 *   MI_WaitNDma  0x0272FCB0  arm twl
 *   OS_DisableIrqMask  0x02084998  arm
 *   OS_ResetRequestIrqMask  0x020849C8  arm
 *   OS_GetIrqFunction  0x02084818  arm
 *   OS_SetIrqFunction  0x02084774  arm
 *   OS_EnableIrqMask  0x02084968  arm
 */
#include "../types.h"

typedef struct {
    int intervalTimer;
    int prescaler;
    int blockSize;
    int blockWordCount;
} NdmaConfig;

typedef void (*IrqHandler)(void);

typedef struct {
    volatile u32 busy;
    u32 ch;
    u32 src;
    u32 remaining;
    void (*callback)(u32);
    u32 arg;
    u32 savedFifoIrqMode;
    IrqHandler savedIrqHandler;
} GxState;

extern GxState data_02732F3C;
extern NdmaConfig data_02732EFC[];
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern void MI_WaitNDma(int);
extern void MIi_NDmaAsync_withConfig_Dev(int mode, int ch, u32 src, u32 dst, u32 fill, u32 size, void (*cb)(), u32 arg, NdmaConfig *cfg, int words, u32 flags);
extern u32 OS_DisableIrqMask(u32);
extern u32 OS_ResetRequestIrqMask(u32);
extern IrqHandler OS_GetIrqFunction(u32);
extern void OS_SetIrqFunction(u32, IrqHandler);
extern u32 OS_EnableIrqMask(u32);

void MI_SendNDmaGXCommandAsync(u32 ch, u32 src, u32 size, void (*cb)(u32), u32 arg);
static void MIi_FIFOCallback(void);
void MIi_NDMACallback(void);
void MI_SendNDmaGXCommandAsyncFast(u32 ch, u32 src, u32 size, void (*cb)(u32), u32 arg);
void MIi_NDMAFastCallback(void);

void MI_SendNDmaGXCommandAsync(u32 ch, u32 src, u32 size, void (*cb)(u32), u32 arg)
{
    u32 irq;
    GxState *s;
    if (size == 0) {
        if (cb != 0) {
            cb(arg);
        }
        return;
    }
    while (((volatile GxState *)&data_02732F3C)->busy != 0) {
    }
    while ((((*(volatile u32 *)0x04000600) & 0x7000000) >> 24 & 2) == 0) {
    }
    s = &data_02732F3C;
    s->busy = 1;
    s->ch = ch;
    s->src = src;
    s->remaining = size;
    s->callback = cb;
    s->arg = arg;
    MI_WaitNDma(ch);
    irq = OS_DisableInterrupts();
    s->savedFifoIrqMode = (*(volatile u32 *)0x04000600 & 0xc0000000) >> 0x1e;
    s->savedIrqHandler = OS_GetIrqFunction(0x200000);
    *(volatile u32 *)0x04000600 = (*(volatile u32 *)0x04000600 & ~0xc0000000) | 0x40000000;
    OS_SetIrqFunction(0x200000, MIi_FIFOCallback);
    OS_EnableIrqMask(0x200000);
    MIi_FIFOCallback();
    OS_RestoreInterrupts(irq);
}

static void MIi_FIFOCallback(void)
{
    u32 pos;
    u32 n = data_02732F3C.remaining;
    void (*cb)();
    u32 rem;
    u32 idx;
    if (n == 0) {
        return;
    }
    if (n >= 0x1d8) {
        n = 0x1d8;
    }
    pos = data_02732F3C.src;
    data_02732F3C.remaining -= n;
    data_02732F3C.src = pos + n;
    if (data_02732F3C.remaining == 0) {
        OS_DisableIrqMask(0x200000);
    }
    OS_ResetRequestIrqMask(0x200000);
    rem = data_02732F3C.remaining;
    cb = MIi_NDMACallback;
    if (rem != 0) {
        cb = 0;
    }
    idx = data_02732F3C.ch;
    MIi_NDmaAsync_withConfig_Dev(rem == 0 ? 9 : 8, idx, pos, 0x04000400, 0, n, cb, 0,
                  (void *)((char *)data_02732EFC + (idx << 4)), -1, 0x80000000);
}

void MIi_NDMACallback(void)
{
    GxState *s = &data_02732F3C;
    void (*cb)(u32);
    u32 arg;
    volatile u32 *reg = (volatile u32 *)0x04000600;
    OS_DisableIrqMask(0x200000);
    *reg = (s->savedFifoIrqMode << 30) | (*reg & ~0xC0000000);
    OS_SetIrqFunction(0x200000, s->savedIrqHandler);
    s->busy = 0;
    cb = s->callback;
    arg = s->arg;
    if (cb != 0) {
        cb(arg);
    }
}

void MI_SendNDmaGXCommandAsyncFast(u32 ch, u32 src, u32 size, void (*cb)(u32), u32 arg)
{
    GxState *s;
    if (size == 0) {
        if (cb != 0) {
            cb(arg);
        }
        return;
    }
    while (data_02732F3C.busy != 0) {
    }
    s = &data_02732F3C;
    s->busy = 1;
    s->ch = ch;
    s->callback = cb;
    s->arg = arg;
    MI_WaitNDma(ch);
    MIi_NDmaAsync_withConfig_Dev(9, ch, src, 0x04000400, 0, size, MIi_NDMAFastCallback, 0, (void *)((char *)data_02732EFC + (ch << 4)), -1, 0x80000000);
}

void MIi_NDMAFastCallback(void)
{
    GxState *s = &data_02732F3C;
    void (*cb)(u32);
    u32 arg;
    s->busy = 0;
    cb = s->callback;
    arg = s->arg;
    if (cb != 0) {
        cb(arg);
    }
}
