/*
 * function: CAMERA_EndCore
 * address:  0x02700B34
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02732FC0  0x02732FC0  data twl a2
 *   data_02732FF8  0x02732FF8  data twl a2
 *   data_02733008  0x02733008  data twl a2
 *   data_0273302C  0x0273302C  data twl a2
 *   func_0208C86C  0x0208C86C  arm twl a2
 *   PM_DeletePostExitCallback  0x02731590  arm twl a2
 *   CAMERA_I2CActivateCore  0x02700DB8  arm twl a2
 *   CAMERA_ResetCore  0x02702080  arm twl a2
 *   CAMERA_StopCaptureCore  0x0270212C  arm twl a2
 *   CAMERA_ClearBufferCore  0x027021E4  arm twl a2
 *   func_020885A0  0x020885A0  arm twl a2
 *   CAMERA_SetVsyncInterruptCore  0x0270223C  arm twl a2
 *   CAMERA_SetBufferErrorInterruptCore  0x02702268  arm twl a2
 *   CAMERA_SetMasterInterruptCore  0x02702208  arm twl a2
 *   func_02084774  0x02084774  arm twl a2
 *   OS_DisableIrqMask  0x02084998  arm twl a2
 *   OS_KillThread  0x02085638  arm twl a2
 */

typedef unsigned int u32;

extern u32 data_02732FC0[];
extern u32 data_02732FF8[];
extern u32 data_02733008[];
extern u32 data_0273302C[];

extern void func_0208C86C(u32*);
extern void PM_DeletePostExitCallback(u32*);
extern u32 CAMERA_I2CActivateCore(u32 a0);
extern void CAMERA_ResetCore(void);
extern void CAMERA_StopCaptureCore(void);
extern void CAMERA_ClearBufferCore(void);
extern void func_020885A0(u32, u32);
extern void CAMERA_SetVsyncInterruptCore(u32);
extern void CAMERA_SetBufferErrorInterruptCore(u32);
extern void CAMERA_SetMasterInterruptCore(u32);
extern void func_02084774(u32, u32);
extern void OS_DisableIrqMask(u32);
extern void OS_KillThread(u32*, u32);

void CAMERA_EndCore(void) {
    if (data_02732FC0[0] == 0) return;
    data_02732FC0[0] = 0;
    func_0208C86C(data_02732FF8);
    PM_DeletePostExitCallback(data_02733008);
    CAMERA_I2CActivateCore(0);
    CAMERA_ResetCore();
    CAMERA_StopCaptureCore();
    CAMERA_ClearBufferCore();
    func_020885A0(0x15, 0);
    CAMERA_SetVsyncInterruptCore(0);
    CAMERA_SetBufferErrorInterruptCore(0);
    CAMERA_SetMasterInterruptCore(0);
    func_02084774(0x02000000, 0);
    OS_DisableIrqMask(0x02000000);
    OS_KillThread(data_0273302C, 0);
}
