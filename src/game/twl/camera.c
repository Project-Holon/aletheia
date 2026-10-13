/*
 * file:     camera.c
 * unit:     yes
 * function: CAMERA_ResetCore, CAMERA_IsBusyCore, CAMERA_StartCaptureCore, CAMERA_StopCaptureCore, CAMERA_SetTrimmingCore, CAMERA_SetOutputFormatCore, CAMERA_GetErrorStatusCore, CAMERA_ClearBufferCore, CAMERA_SetMasterInterruptCore, CAMERA_SetVsyncInterruptCore, CAMERA_SetBufferErrorInterruptCore, CAMERA_SetTransferLinesCore, CAMERA_GetTransferLinesCore, CAMERA_GetMaxLinesRoundCore, CAMERA_GetBytesAtOnceCore
 * address:  0x02702080
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libcamera.TWL.HYB.a camera.o
 *
 * symbols:
 *   OS_SpinWaitSysCycles 0x02087A04 arm twl a2
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_0209C0A4 0x0209C0A4 arm twl a2
 */
typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short s16;

typedef signed int s32;

typedef unsigned long long u64;

extern void OS_SpinWaitSysCycles(u32);
extern unsigned int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(unsigned int enable);
extern u64 func_0209C0A4(u32, u32);
void CAMERA_ResetCore(void);
s32 CAMERA_IsBusyCore(void);
void CAMERA_StartCaptureCore(void);
void CAMERA_StopCaptureCore(void);
void CAMERA_SetTrimmingCore(unsigned int enable);
void CAMERA_SetOutputFormatCore(int mode);
s32 CAMERA_GetErrorStatusCore(void);
void CAMERA_ClearBufferCore(void);
void CAMERA_SetMasterInterruptCore(unsigned int enable);
void CAMERA_SetVsyncInterruptCore(unsigned int val);
void CAMERA_SetBufferErrorInterruptCore(unsigned int enable);
void CAMERA_SetTransferLinesCore(int mode);
s32 CAMERA_GetTransferLinesCore(void);
u32 CAMERA_GetMaxLinesRoundCore(u32 a0, u32 a1);
u32 CAMERA_GetBytesAtOnceCore(u32 a0);
#define reg_04004004 (*(volatile u16 *)0x04004004)
#define reg_04004202 (*(volatile u16 *)0x04004202)
#define reg_04004200 (*(volatile u16 *)0x04004200)






void CAMERA_ResetCore(void) {
    reg_04004004 |= 4;
    reg_04004200 = 0;
    OS_SpinWaitSysCycles(0x1e);
    reg_04004004 |= 0x100;
    OS_SpinWaitSysCycles(0x1e);
    reg_04004200 = 0x22;
    OS_SpinWaitSysCycles(0x2008);
    reg_04004004 &= 0xfeff;
}






s32 CAMERA_IsBusyCore(void)
{
    return (reg_04004202 & 0x8000) >> 15;
}






void CAMERA_StartCaptureCore(void) {
    unsigned int irq = OS_DisableInterrupts();
    reg_04004202 |= 0x8000;
    OS_RestoreInterrupts(irq);
}






void CAMERA_StopCaptureCore(void) {
    unsigned int irq = OS_DisableInterrupts();
    reg_04004202 &= 0x7fff;
    OS_RestoreInterrupts(irq);
}






void CAMERA_SetTrimmingCore(unsigned int enable) {
    unsigned int irq = OS_DisableInterrupts();
    u16 v = reg_04004202;
    reg_04004202 = enable ? (v | 0x4000) : (v & ~0x4000);
    OS_RestoreInterrupts(irq);
}






void CAMERA_SetOutputFormatCore(int mode) {
    unsigned int irq = OS_DisableInterrupts();
    u16 v = reg_04004202;
    if (mode != 0) {
        if (mode == 1) {
            reg_04004202 = v | 0x2000;
        }
    } else {
        reg_04004202 = v & ~0x2000;
    }
    OS_RestoreInterrupts(irq);
}






s32 CAMERA_GetErrorStatusCore(void)
{
    return (reg_04004202 & 0x10) >> 4;
}






void CAMERA_ClearBufferCore(void) {
    unsigned int irq = OS_DisableInterrupts();
    reg_04004202 |= 0x20;
    OS_RestoreInterrupts(irq);
}






void CAMERA_SetMasterInterruptCore(unsigned int enable) {
    unsigned int irq = OS_DisableInterrupts();
    u16 v = reg_04004202;
    reg_04004202 = enable ? (v | 0x800) : (v & ~0x800);
    OS_RestoreInterrupts(irq);
}






void CAMERA_SetVsyncInterruptCore(unsigned int val) {
    unsigned int irq = OS_DisableInterrupts();
    reg_04004202 = (reg_04004202 & ~0x300) | val;
    OS_RestoreInterrupts(irq);
}






void CAMERA_SetBufferErrorInterruptCore(unsigned int enable) {
    unsigned int irq = OS_DisableInterrupts();
    u16 v = reg_04004202;
    reg_04004202 = enable ? (v | 0x400) : (v & ~0x400);
    OS_RestoreInterrupts(irq);
}





void CAMERA_SetTransferLinesCore(int mode) {
    unsigned int irq;
    if (mode < 1 || mode > 0x10) {
        return;
    }
    irq = OS_DisableInterrupts();
    reg_04004202 = (reg_04004202 & ~0xf) | (u16)(mode - 1);
    OS_RestoreInterrupts(irq);
}





s32 CAMERA_GetTransferLinesCore(void)
{
    return (reg_04004202 & 0xf) + 1;
}



u32 CAMERA_GetMaxLinesRoundCore(u32 a0, u32 a1) {
    u32 r4 = (u32)func_0209C0A4(0x400, a0);
    if ((s32)r4 > 0x10) r4 = 0x10;
    if ((s32)r4 > 1) {
        do {
            u64 res = func_0209C0A4(a1, r4);
            if ((u32)(res >> 32) == 0) return r4;
            r4--;
        } while ((s32)r4 > 1);
    }
    return 1;
}


u32 CAMERA_GetBytesAtOnceCore(u32 a0) {
    return (a0 << 1) * CAMERA_GetTransferLinesCore();
}
