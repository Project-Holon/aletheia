/*
 * function: DSP_SendDataIsEmptyCore
 * address:  0x02704FE4
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DAT_0400430c   0x0400430c  data twl
 *   DSP_PowerOnCore  0x02704E90  arm
 *   DSP_PowerOffCore  0x02704EE8  arm
 *   DSP_ResetOnCore  0x02704F1C  arm
 *   DSP_ResetOffExCore  0x02704F4C  arm
 *   DSP_ResetInterfaceCore  0x02704F9C  arm
 *   DSP_RecvDataIsReadyCore  0x02705008  arm
 *   DSP_SendDataCore  0x0270502C  arm
 *   DSP_RecvDataCore  0x0270505C  arm
 *   DSP_SendFifoExCore  0x02705088  arm
 *   DSP_RecvFifoExCore  0x02705150  arm
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
asm void DSP_ResetOffExCore(u32 a0);
void DSP_ResetInterfaceCore(void);
u32 DSP_SendDataIsEmptyCore(u32 a0);
u32 DSP_RecvDataIsReadyCore(u32 a0);
void DSP_SendDataCore(u32 a0, u32 a1);
u16 DSP_RecvDataCore(u32 ch);
void DSP_SendFifoExCore(u32 a, u16 v, u16 *src, s32 n, u16 flags);
void DSP_RecvFifoExCore(u32 a, u16 *dst, u16 v, s32 n, u16 flags);
extern u32 DAT_04004308[];
extern u32 DAT_0400430c[];

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

u32 DSP_SendDataIsEmptyCore(u32 a0)
{
    return (REG_STAT & ((1u << a0) << 13)) ? 0 : 1;
}
