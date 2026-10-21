/*
 * file:     mi_ndma.c
 * unit:     yes
 * function: MIi_GetControlData, MIi_NDma_withConfig_Dev, MIi_NDmaAsync_withConfig_Dev, MI_InitNDma, MI_NDmaFill, MI_NDmaCopy, MI_NDmaFillAsync, MI_NDmaCopyAsync, MI_IsNDmaBusy, MI_WaitNDma, MI_StopNDma, MI_StopAllNDma, MIi_Wait, MI_SetNDmaArbitrament, MI_InitNDmaConfig, MI_GetNDmaConfig, MIi_CardNDmaRecv32, MI_Card_NDmaCopy, MI_Camera_NDmaRecvAsync
 * address:  0x0272F804
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libmi.TWL.HYB.a mi_ndma.o
 *
 * symbols:
 *   data_02150FEC  0x02150FEC  data
 *   OS_GetBootType  0x02087B04  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   OS_SleepThread  0x020857B0  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OS_Terminate  0x02088234  arm
 *   _u32_div_f  0x0209C2B0  arm
 *   CARDi_TouchRomHashSector  0x0272EFB0  arm twl
 *   CARDi_TouchRomHashBlock  0x0272EE98  arm twl
 *   CARDi_CompareHash  0x0272EC38  arm twl
 *   CARDi_ReadRomHashImageCaching  0x0272F570  arm twl
 *   CARDi_ReadRomHashImageDirect  0x0272F368  arm twl
 *   OSi_EnterNDmaCallback  0x020848EC  arm
 *   data_02732EFC  0x02732EFC  data twl
 *   MIi_CpuCopy32  0x02082A90  arm
 *   data_02732F3C  0x02732F3C  data twl
 *   MIi_NDMACallback  0x02730090  arm twl
 *   OS_DisableIrqMask  0x02084998  arm
 *   OS_ResetRequestIrqMask  0x020849C8  arm
 *   OS_GetIrqFunction  0x02084818  arm
 *   OS_SetIrqFunction  0x02084774  arm
 *   OS_EnableIrqMask  0x02084968  arm
 */
#include "../types.h"
#include "../sdk_ioreg.h"

#include "mi_ndma_types.h"

typedef struct {
    u32 src;
    u32 dst;
    u32 total;
    u32 block;
    u32 intv;
    u32 fill;
    u32 ctrl;
} NdmaCh;
#define NDMA ((volatile NdmaCh *)REG_MI_NDMA_SRC_ADDR)

extern NdmaConfig data_02732EFC[];
typedef unsigned int OSIntrMode;
#include "../arm9/os_system.h"
typedef unsigned int OSIrqMask;
#include "../arm9/os_interrupt.h"
extern void MIi_CpuCopy32(void *dst, const void *src, u32 n);

u32 MIi_GetControlData(u32 type);
void MIi_NDma_withConfig_Dev(int mode, int ch, u32 src, u32 dst, u32 fill, u32 size, NdmaConfig *cfg, int words, u32 flags);
void MIi_NDmaAsync_withConfig_Dev(int mode, int ch, u32 src, u32 dst, u32 fill, u32 size, void (*cb)(), u32 arg, NdmaConfig *cfg, int words, u32 flags);
void MI_InitNDma(void);
void MI_NDmaFill(int ch, int dst, int data, int size);
void MI_NDmaCopy(int ch, int src, int dst, int size);
void MI_NDmaFillAsync(int ch, u32 dst, u32 data, u32 size, void (*cb)(), u32 arg);
void MI_NDmaCopyAsync(int ch, u32 src, u32 dst, u32 size, void (*cb)(), u32 arg);
u32 MI_IsNDmaBusy(int ch);
void MI_WaitNDma(int ch);
void MI_StopNDma(int ch);
void MI_StopAllNDma(void);
static void MIi_Wait(int ch);
void MI_SetNDmaArbitrament(u32 arbitrament, u32 roundRobin);
void MI_InitNDmaConfig(void);
void MI_GetNDmaConfig(int ch, const void *src);
void MIi_CardNDmaRecv32(int ch, const void *src, void *dst);
void MI_Card_NDmaCopy(int ch, const void *src, void *dst);
void MI_Camera_NDmaRecvAsync(u32 ch, u32 dst, u32 blockWordCount, u32 size, int s0, void (*s1)(), u32 s2);

u32 MIi_GetControlData(u32 type)
{
    switch (type) {
    case 0:
        return 0x6000;
    case 1:
        return 0;
    case 2:
    case 8:
        return 0x800;
    case 9:
        return 0x40000800;
    case 3:
        return 0x4000;
    case 4:
        return 0x4800;
    case 10:
        return 0x60005000;
    case 5:
        return 0x20001000;
    case 6:
        return 0x60001000;
    case 7:
        return 0x20000800;
    default:
        return 0;
    }
}

void MIi_NDma_withConfig_Dev(int mode, int ch, u32 src, u32 dst, u32 fill, u32 size, NdmaConfig *cfg, int words, u32 flags)
{
    u32 irq;
    u32 ctrl;

    if (size == 0) {
        return;
    }
    irq = OS_DisableInterrupts();
    MIi_Wait(ch);
    if (mode != 0) {
        NDMA[ch].src = src;
    }
    NDMA[ch].dst = dst;
    NDMA[ch].intv = cfg->intervalTimer | cfg->prescaler;
    if (mode == 0) {
        NDMA[ch].fill = fill;
    }
    if (words == -1) {
        NDMA[ch].block = size >> 2;
    } else {
        u32 w;
        w = size >> 2;
        NDMA[ch].total = w;
        if (cfg->blockWordCount != -1) {
            w = cfg->blockWordCount;
        }
        NDMA[ch].block = w;
    }
    ctrl = cfg->blockSize | (flags & 0x80000000);
    ctrl |= MIi_GetControlData(mode);
    NDMA[ch].ctrl = ctrl | (words == -1 ? 0x10000000 : words);
    MIi_Wait(ch);
    OS_RestoreInterrupts(irq);
}

void MIi_NDmaAsync_withConfig_Dev(int mode, int ch, u32 src, u32 dst, u32 fill, u32 size, void (*cb)(), u32 arg, NdmaConfig *cfg, int words, u32 flags)
{
    u32 irq;
    u32 ctrl;

    if (size == 0) {
        if (cb != 0) {
            cb(arg);
        }
        return;
    }
    irq = OS_DisableInterrupts();
    MIi_Wait(ch);
    if (cb != 0) {
        OSi_EnterNDmaCallback(ch, cb, (void *)arg);
    }
    if (mode != 0) {
        NDMA[ch].src = src;
    }
    NDMA[ch].dst = dst;
    NDMA[ch].intv = cfg->intervalTimer | cfg->prescaler;
    if (mode == 0) {
        NDMA[ch].fill = fill;
    }
    if (words == -1) {
        NDMA[ch].block = size >> 2;
    } else {
        u32 w;
        w = size >> 2;
        NDMA[ch].total = w;
        if (cfg->blockWordCount != -1) {
            w = cfg->blockWordCount;
        }
        NDMA[ch].block = w;
    }
    ctrl = cfg->blockSize | (flags & 0x80000000);
    ctrl |= MIi_GetControlData(mode);
    ctrl |= (words == -1 ? 0x10000000 : words);
    if (cb != 0) {
        ctrl |= 0x40000000;
    }
    NDMA[ch].ctrl = ctrl;
    OS_RestoreInterrupts(irq);
}

void MI_InitNDma(void) {
    MI_SetNDmaArbitrament(0x80000000, 0x60000);
    MI_InitNDmaConfig();
}

void MI_NDmaFill(int ch, int dst, int data, int size)
{
    MIi_NDma_withConfig_Dev(0, ch, 0, dst, data, size, (void *)(((char *)data_02732EFC) + (ch << 4)), -1, 0x80000000);
}

void MI_NDmaCopy(int ch, int src, int dst, int size)
{
    MIi_NDma_withConfig_Dev(1, ch, src, dst, 0, size, (void *)(((char *)data_02732EFC) + (ch << 4)), -1, 0x80000000);
}

void MI_NDmaFillAsync(int ch, u32 dst, u32 data, u32 size, void (*cb)(), u32 arg)
{
    MIi_NDmaAsync_withConfig_Dev(0, ch, 0, dst, data, size, cb, arg, (void *)(((char *)data_02732EFC) + (ch << 4)), -1, 0x80000000);
}

void MI_NDmaCopyAsync(int ch, u32 src, u32 dst, u32 size, void (*cb)(), u32 arg)
{
    MIi_NDmaAsync_withConfig_Dev(1, ch, src, dst, 0, size, cb, arg, (void *)(((char *)data_02732EFC) + (ch << 4)), -1, 0x80000000);
}

u32 MI_IsNDmaBusy(int ch)
{
    return (*(volatile u32 *)(REG_MI_NDMA_CNT_ADDR + ch * 0x1C) & 0x80000000) >> 31;
}

void MI_WaitNDma(int ch)
{
    int irq = OS_DisableInterrupts();
    volatile u32 *reg = (volatile u32 *)(REG_MI_NDMA_CNT_ADDR + ch * 0x1C);
    while (*reg & 0x80000000) {
    }
    OS_RestoreInterrupts(irq);
}

void MI_StopNDma(int ch)
{
    int irq = OS_DisableInterrupts();
    volatile u32 *reg = (volatile u32 *)(REG_SCFG_ROM_ADDR + 0x11C + ch * 0x1C);
    *reg &= ~0x80000000;
    (void)*reg;
    (void)*reg;
    OS_RestoreInterrupts(irq);
}

void MI_StopAllNDma(void) {
    MI_StopNDma(0);
    MI_StopNDma(1);
    MI_StopNDma(2);
    MI_StopNDma(3);
}

static void MIi_Wait(int ch) {
    do {
    } while (MI_IsNDmaBusy(ch) == 1);
}

void MI_SetNDmaArbitrament(u32 arbitrament, u32 roundRobin) {
    if (arbitrament == 0x80000000) {
        *(volatile u32 *)0x04004100 = roundRobin | 0x80000000;
    } else {
        *(volatile u32 *)0x04004100 = 0;
    }
}

void MI_InitNDmaConfig(void) {
    register NdmaConfig *e = ((NdmaConfig *)data_02732EFC);
    register int i = 0;
    do {
        e->intervalTimer = 1;
        e->prescaler = 0;
        e->blockSize = 0x40000;
        i++;
        e->blockWordCount = -1;
        e++;
    } while (i <= 3);
}

void MI_GetNDmaConfig(int ch, const void *src)
{
    MIi_CpuCopy32(&data_02732EFC[ch], src, 16);
}

void MIi_CardNDmaRecv32(int ch, const void *src, void *dst)
{
    u32 irq = OS_DisableInterrupts();
    uptr base;
    NdmaConfig *e;
    MIi_Wait(ch);
    base = REG_DISPCNT_ADDR + ch * 0x1C;
    e = &data_02732EFC[ch];
    *(volatile u32 *)(base + 0x4104) = (uptr)src;
    *(volatile u32 *)(base + 0x4108) = (uptr)dst;
    *(volatile u32 *)(base + 0x410C) = 1;
    *(volatile u32 *)(base + 0x4110) = 1;
    *(volatile u32 *)(base + 0x411C) = e->blockSize | 0x4000 | 0xA4000000;
    OS_RestoreInterrupts(irq);
}

void MI_Card_NDmaCopy(int ch, const void *src, void *dst)
{
    MIi_CardNDmaRecv32(ch, src, dst);
}

void MI_Camera_NDmaRecvAsync(u32 ch, u32 dst, u32 blockWordCount, u32 size, int mode, void (*callback)(), u32 arg)
{
    NdmaConfig buf;
    u32 n = 10;
    if (mode == 0) {
        n = 3;
    }
    MI_GetNDmaConfig(ch, &buf);
    buf.intervalTimer = 2;
    buf.prescaler = 0;
    buf.blockSize = 0x40000;
    buf.blockWordCount = blockWordCount;
    MIi_NDmaAsync_withConfig_Dev(n, ch, REG_DSP_PCFG_ADDR, dst, 0, size, callback, arg, &buf, 0x0b000000, 0x80000000);
}
