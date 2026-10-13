/*
 * file:     dsp_if.c
 * unit:     yes
 * function: DSP_PowerOnCore, DSP_PowerOffCore, DSP_ResetOnCore, DSP_ResetOffExCore, DSP_ResetInterfaceCore, DSP_SendDataIsEmptyCore, DSP_RecvDataIsReadyCore, DSP_SendDataCore, DSP_RecvDataCore, DSP_SendFifoExCore, DSP_RecvFifoExCore, DSP_GetSemaphoreCore, DSP_ClearSemaphoreCore, DSP_MaskSemaphoreCore
 * address:  0x02704E90
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libdsp.TWL.HYB.a dsp_if.o
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm  arm9
 *   OS_RestoreInterrupts  0x0208799C  arm  arm9
 *   OS_SpinWaitSysCycles  0x02087A04  arm  arm9
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef volatile u16 vu16;

extern void OS_SpinWaitSysCycles(u32);
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
void DSP_PowerOnCore(void);
void DSP_PowerOffCore(void);
void DSP_ResetOnCore(void);
void DSP_ResetOffExCore(u32 a0);
void DSP_ResetInterfaceCore(void);
u32 DSP_SendDataIsEmptyCore(u32 a0);
u32 DSP_RecvDataIsReadyCore(u32 a0);
void DSP_SendDataCore(u32 a0, u32 a1);
u16 DSP_RecvDataCore(u32 ch);
void DSP_SendFifoExCore(u32 a, u16 v, u16 *src, s32 n, u16 flags);
void DSP_RecvFifoExCore(u32 a, u16 *dst, u16 v, s32 n, u16 flags);
u16 DSP_GetSemaphoreCore(void);
void DSP_ClearSemaphoreCore(u16 v);
void DSP_MaskSemaphoreCore(u16 v);

#define REG_PWR (*(vu16 *)0x04004006)
#define REG_CNT (*(vu16 *)0x04004004)
#define REG_CH0_CTRL (*(vu16 *)0x04004310)
#define REG_CH0_SEL (*(vu16 *)0x04004318)
#define REG_CH0_A (*(vu16 *)0x04004324)
#define REG_CH0_B (*(vu16 *)0x0400432C)
#define REG_CH0_C (*(vu16 *)0x04004334)
#define REG_DATA (*(vu16 *)0x04004300)
#define REG_CTRL (*(vu16 *)0x04004304)
#define REG_MODE (*(vu16 *)0x04004308)
#define REG_STAT (*(vu16 *)0x0400430C)




void DSP_PowerOnCore(void)
{
    REG_PWR &= 0xFFFE;
    REG_CNT = (REG_CNT & 0xFFFD) | 2;
    OS_SpinWaitSysCycles(2);
    REG_PWR = (REG_PWR & 0xFFFE) | 1;
    DSP_ResetOnCore();
}




void DSP_PowerOffCore(void)
{
    REG_PWR &= 0xFFFE;
    REG_CNT &= 0xFFFD;
}




void DSP_ResetOnCore(void)
{
    if (REG_MODE & 1) {
        return;
    }
    REG_MODE |= 1;
    while (REG_STAT & 4) {
    }
}




void DSP_ResetOffExCore(u32 a0)
{
    while (REG_STAT & 4) {
    }
    DSP_ResetInterfaceCore();
    REG_MODE |= a0 << 9;
    REG_MODE &= ~1;
}




void DSP_ResetInterfaceCore(void)
{
    if (!(REG_MODE & 1)) {
        return;
    }
    REG_MODE &= 0xF1FF;
    REG_CH0_CTRL = 0;
    REG_CH0_SEL = 0xFFFF;
    (void)REG_CH0_A;
    (void)REG_CH0_B;
    (void)REG_CH0_C;
}




u32 DSP_SendDataIsEmptyCore(u32 a0)
{
    return (REG_STAT & ((1u << a0) << 13)) ? 0 : 1;
}




u32 DSP_RecvDataIsReadyCore(u32 a0)
{
    return (REG_STAT & ((1u << a0) << 10)) ? 1 : 0;
}




void DSP_SendDataCore(u32 a0, u32 a1)
{
    while (!DSP_SendDataIsEmptyCore(a0)) {
    }
    *(vu16 *)(0x04004300 + a0 * 8 + 0x20) = a1;
}


u16 DSP_RecvDataCore(u32 ch)
{
    while (!DSP_RecvDataIsReadyCore(ch)) {
    }
    return *(volatile u16 *)(0x04004300 + ch * 8 + 0x24);
}


void DSP_SendFifoExCore(u32 a, u16 v, u16 *src, s32 n, u16 flags)
{
    u32 irq = OS_DisableInterrupts();
    u32 x = (u16)((flags & 2) ? 0 : 2);
    REG_CTRL = v;
    REG_MODE = (REG_MODE & ~0xF002) | a | x;
    if (flags & 1) {
        while (n-- > 0) {
            while (REG_STAT & 0x80) {
            }
            REG_DATA = *src;
        }
    } else {
        while (n-- > 0) {
            while (REG_STAT & 0x80) {
            }
            REG_DATA = *src++;
        }
    }
    OS_RestoreInterrupts(irq);
}


void DSP_RecvFifoExCore(u32 a, u16 *dst, u16 v, s32 n, u16 flags)
{
    u32 irq = OS_DisableInterrupts();
    u32 x = (u16)((flags & 1) ? 0 : 2);
    u32 sel;
    switch (flags & 0x300) {
    case 0x100: sel = 0; n = 1; break;
    case 0x200: sel = 4; n = 8; break;
    case 0x300: sel = 8; n = 16; break;
    default: sel = 12; break;
    }
    REG_CTRL = v;
    REG_MODE = (REG_MODE & ~0xF00E) | a | sel | x | 0x10;
    if (flags & 2) {
        while (n-- > 0) {
            while (!(REG_STAT & 0x40)) {
            }
            *dst = REG_DATA;
        }
    } else {
        while (n-- > 0) {
            while (!(REG_STAT & 0x40)) {
            }
            *dst++ = REG_DATA;
        }
    }
    REG_MODE &= 0xFFEF;
    OS_RestoreInterrupts(irq);
}

u16 DSP_GetSemaphoreCore(void)
{
    return *(volatile u16 *)0x0400431C;
}

void DSP_ClearSemaphoreCore(u16 v)
{
    *(volatile u16 *)0x04004318 = v;
}

void DSP_MaskSemaphoreCore(u16 v)
{
    *(volatile u16 *)0x04004314 = v;
}
