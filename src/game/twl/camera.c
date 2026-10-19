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
 *   _s32_div_f 0x0209C0A4 arm twl a2
 */
#include "../types.h"

extern void OS_SpinWaitSysCycles(u32);
extern unsigned int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(unsigned int enable);
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
u32 CAMERA_GetMaxLinesRoundCore(u32 width, u32 height);
u32 CAMERA_GetBytesAtOnceCore(u32 width);
/* DSi camera hardware registers.  0x04004200 is REG_CAM_MCNT (camera master
 * control), 0x04004202 is REG_CAM_CNT (camera control) and 0x04004004 is the
 * system control clock REG_SCFG_CLK (the camera clock gate).  The REG_ names
 * are the DSi SDK register names; symbols_sdk.json lists functions only. */
#define REG_SCFG_CLK (*(volatile u16 *)0x04004004)
#define REG_CAM_MCNT (*(volatile u16 *)0x04004200)
#define REG_CAM_CNT (*(volatile u16 *)0x04004202)

void CAMERA_ResetCore(void) {
    REG_SCFG_CLK |= 4;
    REG_CAM_MCNT = 0;
    OS_SpinWaitSysCycles(0x1e);
    REG_SCFG_CLK |= 0x100;
    OS_SpinWaitSysCycles(0x1e);
    REG_CAM_MCNT = 0x22;
    OS_SpinWaitSysCycles(0x2008);
    REG_SCFG_CLK &= 0xfeff;
}

s32 CAMERA_IsBusyCore(void)
{
    return (REG_CAM_CNT & 0x8000) >> 15;
}

void CAMERA_StartCaptureCore(void) {
    unsigned int irq = OS_DisableInterrupts();
    REG_CAM_CNT |= 0x8000;
    OS_RestoreInterrupts(irq);
}

void CAMERA_StopCaptureCore(void) {
    unsigned int irq = OS_DisableInterrupts();
    REG_CAM_CNT &= 0x7fff;
    OS_RestoreInterrupts(irq);
}

void CAMERA_SetTrimmingCore(unsigned int enable) {
    unsigned int irq = OS_DisableInterrupts();
    u16 v = REG_CAM_CNT;
    REG_CAM_CNT = enable ? (v | 0x4000) : (v & ~0x4000);
    OS_RestoreInterrupts(irq);
}

void CAMERA_SetOutputFormatCore(int mode) {
    unsigned int irq = OS_DisableInterrupts();
    u16 v = REG_CAM_CNT;
    if (mode != 0) {
        if (mode == 1) {
            REG_CAM_CNT = v | 0x2000;
        }
    } else {
        REG_CAM_CNT = v & ~0x2000;
    }
    OS_RestoreInterrupts(irq);
}

s32 CAMERA_GetErrorStatusCore(void)
{
    return (REG_CAM_CNT & 0x10) >> 4;
}

void CAMERA_ClearBufferCore(void) {
    unsigned int irq = OS_DisableInterrupts();
    REG_CAM_CNT |= 0x20;
    OS_RestoreInterrupts(irq);
}

void CAMERA_SetMasterInterruptCore(unsigned int enable) {
    unsigned int irq = OS_DisableInterrupts();
    u16 v = REG_CAM_CNT;
    REG_CAM_CNT = enable ? (v | 0x800) : (v & ~0x800);
    OS_RestoreInterrupts(irq);
}

void CAMERA_SetVsyncInterruptCore(unsigned int val) {
    unsigned int irq = OS_DisableInterrupts();
    REG_CAM_CNT = (REG_CAM_CNT & ~0x300) | val;
    OS_RestoreInterrupts(irq);
}

void CAMERA_SetBufferErrorInterruptCore(unsigned int enable) {
    unsigned int irq = OS_DisableInterrupts();
    u16 v = REG_CAM_CNT;
    REG_CAM_CNT = enable ? (v | 0x400) : (v & ~0x400);
    OS_RestoreInterrupts(irq);
}

void CAMERA_SetTransferLinesCore(int mode) {
    unsigned int irq;
    if (mode < 1 || mode > 0x10) {
        return;
    }
    irq = OS_DisableInterrupts();
    REG_CAM_CNT = (REG_CAM_CNT & ~0xf) | (u16)(mode - 1);
    OS_RestoreInterrupts(irq);
}

s32 CAMERA_GetTransferLinesCore(void)
{
    return (REG_CAM_CNT & 0xf) + 1;
}

u32 CAMERA_GetMaxLinesRoundCore(u32 width, u32 height) {
    s32 lines = 0x400 / (s32)width;
    if (lines > 0x10) lines = 0x10;
    while (lines > 1) {
        if ((s32)height % lines == 0) return lines;
        lines--;
    }
    return 1;
}

u32 CAMERA_GetBytesAtOnceCore(u32 width) {
    return (width << 1) * CAMERA_GetTransferLinesCore();
}
