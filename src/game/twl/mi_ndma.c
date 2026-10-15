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
 *   func_0209C2B0  0x0209C2B0  arm
 *   CARDi_TouchRomHashSector  0x0272EFB0  arm twl
 *   CARDi_TouchRomHashBlock  0x0272EE98  arm twl
 *   CARDi_CompareHash  0x0272EC38  arm twl
 *   CARDi_ReadRomHashImageCaching  0x0272F570  arm twl
 *   CARDi_ReadRomHashImageDirect  0x0272F368  arm twl
 *   func_020848EC  0x020848EC  arm
 *   data_02732EFC  0x02732EFC  data twl
 *   MIi_CpuCopy32  0x02082A90  arm
 *   data_02732F3C  0x02732F3C  data twl
 *   MIi_NDMACallback  0x02730090  arm twl
 *   OS_DisableIrqMask  0x02084998  arm
 *   func_020849C8  0x020849C8  arm
 *   func_02084818  0x02084818  arm
 *   func_02084774  0x02084774  arm
 *   OS_EnableIrqMask  0x02084968  arm
 */
typedef unsigned int u32;

/* per-channel NDMA configuration, 16 bytes */
typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} NdmaConfig;

typedef struct {
    u32 src;
    u32 dst;
    u32 total;
    u32 block;
    u32 intv;
    u32 fill;
    u32 ctrl;
} NdmaCh;
#define NDMA ((volatile NdmaCh *)0x04004104)

extern NdmaConfig data_02732EFC[];
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern void func_020848EC(u32 ch, void (*cb)(), u32 arg);
extern void MIi_CpuCopy32(void *dst, const void *src, u32 n);

u32 MIi_GetControlData(u32 type);
void MIi_NDma_withConfig_Dev(int mode, int ch, u32 src, u32 dst, u32 fill, u32 size, NdmaConfig *cfg, int words, u32 flags);
void MIi_NDmaAsync_withConfig_Dev(int mode, int ch, u32 src, u32 dst, u32 fill, u32 size, void (*cb)(), u32 arg, NdmaConfig *cfg, int words, u32 flags);
void MI_InitNDma(void);
void MI_NDmaFill(int a0, int a1, int a2, int a3);
void MI_NDmaCopy(int a0, int a1, int a2, int a3);
void MI_NDmaFillAsync(int ch, u32 a1, u32 a2, u32 size, void (*cb)(), u32 arg);
void MI_NDmaCopyAsync(int ch, u32 a1, u32 a2, u32 size, void (*cb)(), u32 arg);
u32 MI_IsNDmaBusy(int ch);
void MI_WaitNDma(int ch);
void MI_StopNDma(int ch);
void MI_StopAllNDma(void);
static void MIi_Wait(int a0);
void MI_SetNDmaArbitrament(u32 a0, u32 a1);
void MI_InitNDmaConfig(void);
void MI_GetNDmaConfig(int a0, const void *src);
void MIi_CardNDmaRecv32(int ch, const void *src, void *dst);
void MI_Card_NDmaCopy(int ch, const void *src, void *dst);
void MI_Camera_NDmaRecvAsync(u32 a0, u32 a1, u32 a2, u32 a3, int s0, void (*s1)(), u32 s2);

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
    NDMA[ch].intv = cfg->unk0 | cfg->unk4;
    if (mode == 0) {
        NDMA[ch].fill = fill;
    }
    if (words == -1) {
        NDMA[ch].block = size >> 2;
    } else {
        u32 w;
        w = size >> 2;
        NDMA[ch].total = w;
        if (cfg->unkC != -1) {
            w = cfg->unkC;
        }
        NDMA[ch].block = w;
    }
    ctrl = cfg->unk8 | (flags & 0x80000000);
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
        func_020848EC(ch, cb, arg);
    }
    if (mode != 0) {
        NDMA[ch].src = src;
    }
    NDMA[ch].dst = dst;
    NDMA[ch].intv = cfg->unk0 | cfg->unk4;
    if (mode == 0) {
        NDMA[ch].fill = fill;
    }
    if (words == -1) {
        NDMA[ch].block = size >> 2;
    } else {
        u32 w;
        w = size >> 2;
        NDMA[ch].total = w;
        if (cfg->unkC != -1) {
            w = cfg->unkC;
        }
        NDMA[ch].block = w;
    }
    ctrl = cfg->unk8 | (flags & 0x80000000);
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

void MI_NDmaFill(int a0, int a1, int a2, int a3)
{
    MIi_NDma_withConfig_Dev(0, a0, 0, a1, a2, a3, (void *)(((char *)data_02732EFC) + (a0 << 4)), -1, 0x80000000);
}

void MI_NDmaCopy(int a0, int a1, int a2, int a3)
{
    MIi_NDma_withConfig_Dev(1, a0, a1, a2, 0, a3, (void *)(((char *)data_02732EFC) + (a0 << 4)), -1, 0x80000000);
}

void MI_NDmaFillAsync(int ch, u32 a1, u32 a2, u32 size, void (*cb)(), u32 arg)
{
    MIi_NDmaAsync_withConfig_Dev(0, ch, 0, a1, a2, size, cb, arg, (void *)(((char *)data_02732EFC) + (ch << 4)), -1, 0x80000000);
}

void MI_NDmaCopyAsync(int ch, u32 a1, u32 a2, u32 size, void (*cb)(), u32 arg)
{
    MIi_NDmaAsync_withConfig_Dev(1, ch, a1, a2, 0, size, cb, arg, (void *)(((char *)data_02732EFC) + (ch << 4)), -1, 0x80000000);
}

u32 MI_IsNDmaBusy(int ch)
{
    return (*(volatile u32 *)(0x0400411C + ch * 0x1C) & 0x80000000) >> 31;
}

void MI_WaitNDma(int ch)
{
    int irq = OS_DisableInterrupts();
    volatile u32 *reg = (volatile u32 *)(0x0400411C + ch * 0x1C);
    while (*reg & 0x80000000) {
    }
    OS_RestoreInterrupts(irq);
}

void MI_StopNDma(int ch)
{
    int irq = OS_DisableInterrupts();
    volatile u32 *reg = (volatile u32 *)(0x04004000 + 0x11C + ch * 0x1C);
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

static void MIi_Wait(int a0) {
    do {
    } while (MI_IsNDmaBusy(a0) == 1);
}

void MI_SetNDmaArbitrament(u32 a0, u32 a1) {
    if (a0 == 0x80000000) {
        *(volatile u32 *)0x04004100 = a1 | 0x80000000;
    } else {
        *(volatile u32 *)0x04004100 = 0;
    }
}

void MI_InitNDmaConfig(void) {
    register NdmaConfig *e = ((NdmaConfig *)data_02732EFC);
    register int i = 0;
    do {
        e->unk0 = 1;
        e->unk4 = 0;
        e->unk8 = 0x40000;
        i++;
        e->unkC = -1;
        e++;
    } while (i <= 3);
}

void MI_GetNDmaConfig(int a0, const void *src)
{
    MIi_CpuCopy32(&data_02732EFC[a0], src, 16);
}

void MIi_CardNDmaRecv32(int ch, const void *src, void *dst)
{
    u32 irq = OS_DisableInterrupts();
    u32 base;
    NdmaConfig *e;
    MIi_Wait(ch);
    base = 0x04000000 + ch * 0x1C;
    e = &data_02732EFC[ch];
    *(volatile u32 *)(base + 0x4104) = (u32)src;
    *(volatile u32 *)(base + 0x4108) = (u32)dst;
    *(volatile u32 *)(base + 0x410C) = 1;
    *(volatile u32 *)(base + 0x4110) = 1;
    *(volatile u32 *)(base + 0x411C) = e->unk8 | 0x4000 | 0xA4000000;
    OS_RestoreInterrupts(irq);
}

void MI_Card_NDmaCopy(int ch, const void *src, void *dst)
{
    MIi_CardNDmaRecv32(ch, src, dst);
}

void MI_Camera_NDmaRecvAsync(u32 a0, u32 a1, u32 a2, u32 a3, int s0, void (*s1)(), u32 s2)
{
    NdmaConfig buf;
    u32 n = 10;
    if (s0 == 0) {
        n = 3;
    }
    MI_GetNDmaConfig(a0, &buf);
    buf.unk0 = 2;
    buf.unk4 = 0;
    buf.unk8 = 0x40000;
    buf.unkC = a2;
    MIi_NDmaAsync_withConfig_Dev(n, a0, 0x04004204, a1, 0, a3, s1, s2, &buf, 0x0b000000, 0x80000000);
}
