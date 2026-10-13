/*
 * function: CAMERA_Reboot
 * address:  0x02700230
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02732FC8 0x02732FC8 data twl a2
 *   data_02733FC8 0x02733FC8 data twl a2
 *   OS_IsRunOnTwl 0x02085D3C arm twl a2
 *   CAMERA_GetWhiteBalanceFromPhotoMode 0x02700128  arm twl a2
 *   CAMERA_GetSharpnessFromPhotoMode 0x02700168  arm twl a2
 *   CAMERA_GetExposureFromPhotoMode 0x027001B8  arm twl a2
 *   CAMERA_Reboot 0x02700230  arm twl a2
 *   CAMERA_I2CInitAsyncCore 0x02700C18  arm twl a2
 *   CAMERA_I2CActivateAsyncCore 0x02700CEC  arm twl a2
 *   CAMERA_I2CContextSwitchAsyncCore 0x02700DF0  arm twl a2
 *   CAMERA_I2CSizeExAsyncCore 0x02700EB8  arm twl a2
 *   CAMERA_I2CFrameRateAsyncCore 0x02701020  arm twl a2
 *   CAMERA_I2CEffectExAsyncCore 0x02701120  arm twl a2
 *   CAMERA_I2CFlipExAsyncCore 0x02701284  arm twl a2
 *   CAMERA_I2CPhotoModeAsyncCore 0x027013A4  arm twl a2
 *   CAMERA_I2CWhiteBalanceAsyncCore 0x02701488  arm twl a2
 *   CAMERA_I2CExposureAsyncCore 0x02701570  arm twl a2
 *   CAMERA_I2CSharpnessAsyncCore 0x02701644  arm twl a2
 *   CAMERA_I2CAutoExposureAsyncCore 0x02701718  arm twl a2
 *   CAMERA_I2CAutoWhiteBalanceAsyncCore 0x02701814  arm twl a2
 *   CAMERA_SetLEDAsyncCore 0x02701940  arm twl a2
 *   CAMERA_CameraIntr  0x02700078  arm
 *   CAMERA_SetVsyncCallbackCore  0x027000F8  arm
 *   CAMERA_SetBufferErrorCallbackCore  0x02700108  arm
 *   CAMERA_SetRebootCallbackCore  0x02700118  arm
 *   CAMERA_GoReboot  0x027001F0  arm
 *   CAMERA_CheckRetryCount  0x027007C8  arm
 *   CAMERA_MonitorThread  0x02700824  arm
 *   CAMERA_EndCore  0x02700B34  arm
 *   CAMERA_StopCore  0x02700BD0  arm
 *   CAMERA_I2CActivateCore  0x02700DB8  arm
 *   CameraSendPxiCommand  0x027019B4  arm
 *   CameraPxiCallback  0x02701AA0  arm
 *   CAMERA_ResetCore  0x02702080  arm
 *   CAMERA_IsBusyCore  0x027020F0  arm
 *   CAMERA_StopCaptureCore  0x0270212C  arm
 *   CAMERA_GetErrorStatusCore  0x027021CC  arm
 *   CAMERA_ClearBufferCore  0x027021E4  arm
 *   CAMERA_SetMasterInterruptCore  0x02702208  arm
 *   CAMERA_SetVsyncInterruptCore  0x0270223C  arm
 *   CAMERA_SetBufferErrorInterruptCore  0x02702268  arm
 *   CameraStandbyCallback  0x02702070  arm
 *   PMi_InsertPostExitCallbackEx  0x0273156C  arm
 *   PM_DeletePostExitCallback  0x02731590  arm
 *   PXI_Init  0x02088498  arm  arm9
 *   OS_EnableIrqMask  0x02084968  arm  arm9
 *   OS_DisableIrqMask  0x02084998  arm  arm9
 *   OS_CreateThread  0x020853C0  arm  arm9
 *   OS_KillThread  0x02085638  arm  arm9
 *   OS_WakeupThreadDirect  0x02085868  arm  arm9
 *   OS_Sleep  0x02085A38  arm  arm9
 *   OS_DisableInterrupts  0x02087988  arm  arm9
 *   OS_RestoreInterrupts  0x0208799C  arm  arm9
 *   OS_SpinWaitSysCycles  0x02087A04  arm  arm9
 *   PXI_IsCallbackReady  0x020885EC  arm  arm9
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef signed int     s32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef void (*TwlCb)(u32);
typedef void (*CamPxiCallback)(u32 result, u32 arg);
typedef void (*TwlFn)(void);
typedef volatile u32 vu32;

typedef struct TwlShared {
    u8 pad[0x3FF8];
    vu32 flags;
} TwlShared;

extern u32 OS_IsRunOnTwl(void);
extern s32 CAMERA_GetErrorStatusCore(void);
extern u64 func_020870D0(void);
extern void func_02085DBC(u32*, u32, u32);
extern void CameraPxiCallback(int, u32, int);
extern void CameraStandbyCallback(void);
extern u32 CAMERA_I2CActivateAsyncCore(u32, CamPxiCallback, u32);
extern u32 CAMERA_I2CContextSwitchAsyncCore(u32, u32, CamPxiCallback, u32);
extern u32 CAMERA_I2CSizeExAsyncCore(u32, u32, u32, CamPxiCallback, u32);
extern u32 CAMERA_I2CFrameRateAsyncCore(u32, s32, CamPxiCallback, u32);
extern u32 CAMERA_I2CEffectExAsyncCore(u32, u32, u32, CamPxiCallback, u32);
extern u32 CAMERA_I2CFlipExAsyncCore(u32, u32, s32, CamPxiCallback, u32);
extern u32 CAMERA_I2CPhotoModeAsyncCore(u32, s32, CamPxiCallback, u32);
extern u32 CAMERA_I2CWhiteBalanceAsyncCore(u32, s32, CamPxiCallback, u32);
extern u32 CAMERA_I2CExposureAsyncCore(u32, s32, CamPxiCallback, u32);
extern u32 CAMERA_I2CSharpnessAsyncCore(u32, s32, CamPxiCallback, u32);
extern u32 CAMERA_I2CAutoExposureAsyncCore(u32, s32, CamPxiCallback, u32);
extern u32 CAMERA_I2CAutoWhiteBalanceAsyncCore(u32, s32, CamPxiCallback, u32);
extern int CAMERA_SetLEDAsyncCore(u32, CamPxiCallback, u32);
extern u32 CameraSendPxiCommand(u32, u32, u32);
extern u32 OS_DisableInterrupts(void);
extern void OS_Sleep(u32);
extern u32 func_02085E50(u32*, u32*, u32);
extern void func_02087974(void);
extern void CAMERA_ResetCore(void);
extern void PXI_Init(void);
extern u32 PXI_IsCallbackReady(u32, u32);
extern void func_020885A0(u32, void (*)(int, u32, int));
extern void CAMERA_StopCaptureCore(void);
extern void CAMERA_ClearBufferCore(void);
extern void func_0208C848(u32*, u32);
extern void PMi_InsertPostExitCallbackEx(u32*, u32);
extern void CAMERA_SetVsyncInterruptCore(u32);
extern void CAMERA_SetBufferErrorInterruptCore(u32);
extern void CAMERA_SetMasterInterruptCore(u32);
extern void func_02084774(u32, TwlFn);
extern void OS_EnableIrqMask(u32);
extern void func_02085D94(u32*, u32*, u32);
extern void OS_CreateThread(u32*, void (*)(void), u32, u32*, u32, u32);
extern void OS_WakeupThreadDirect(u32*);
extern void func_0208C86C(u32*);
extern void PM_DeletePostExitCallback(u32*);
extern u32 CAMERA_I2CActivateCore(u32 a0);
extern void OS_DisableIrqMask(u32);
extern void OS_KillThread(u32*, u32);
extern void OS_SpinWaitSysCycles(u32);
extern s32 CAMERA_IsBusyCore(void);
extern void OS_RestoreInterrupts(u32);
void CAMERA_CameraIntr(void);
void CAMERA_SetVsyncCallbackCore(TwlCb a0);
void CAMERA_SetBufferErrorCallbackCore(TwlCb a0);
void CAMERA_SetRebootCallbackCore(TwlCb a0);
u32 CAMERA_GetWhiteBalanceFromPhotoMode(u32 a0);
s32 CAMERA_GetSharpnessFromPhotoMode(u32 a0);
u32 CAMERA_GetExposureFromPhotoMode(u32 a0);
void CAMERA_GoReboot(void);
void CAMERA_Reboot(u32 a0, u32 a1);
u32 CAMERA_CheckRetryCount(void);
void CAMERA_MonitorThread(void);
void CAMERA_EndCore(void);
void CAMERA_StopCore(void);
u32 CAMERA_I2CInitAsyncCore(u32 a0, CamPxiCallback a1, u32 a2);
typedef struct {
    u32 f00;
    CamPxiCallback f04;
    u32 f08;
    u32 f0C;
    u32 pad10[(0x28 - 0x10) / 4];
    u32 f28;
    u32 f2C;
    TwlFn f30;
    u32 f34;
    u32 pad38[(0x40 - 0x38) / 4];
    TwlFn f40;
    u32 f44;
    u32 pad48[(0x50 - 0x48) / 4];
    u64 tick;
    TwlCb cbA;
    TwlCb cbB;
    TwlCb cbC;
} TwlSysA;

extern TwlSysA data_02732FC8;
typedef struct {
    u32 pad[0x124 / 4];
    u32 f124;
    volatile u32 f128;
    volatile u32 f12C;
    volatile u32 f130;
    volatile u32 f134;
    volatile u32 f138;
    volatile u32 f13C;
    u32 f140;
    u32 f144;
    u32 f148;
    u32 f14C;
    s32 f150;
    u32 f154;
    u32 f158;
    u32 f15C;
    u32 f160;
    volatile u32 f164;
    volatile u32 f168;
    volatile u32 f16C;
    volatile u32 f170;
    volatile u32 f174;
    volatile u32 f178;
    u32 f17C;
    u32 f180;
    u32 f184;
    u32 f188;
    u32 f18C;
    u32 f190;
    u32 f194;
    u32 f198;
    u32 f19C;
    u32 f1A0;
    u32 f1A4;
    u32 f1A8;
    u32 f1AC;
    s32 f1B0;
} TwlSysB;

extern TwlSysB data_02733FC8;
extern u32 data_0273417C[];
extern u32 data_02732FC0[];
extern u32 data_02701AA0[];
extern u32 data_02702070[];
extern u32 data_02700078[];
extern u32 data_02700824[];
extern u32 data_02732FF8[];
extern u32 data_02733008[];
extern u32 data_0273419C[];
extern u32 data_0273302C[];
extern u32 data_027340EC[];

void CAMERA_Reboot(u32 a0, u32 a1) {
    u32 t;
    if (a0 != 0) {
        return;
    }
    switch (a1) {
    case 0:
        CAMERA_I2CInitAsyncCore(3, CAMERA_Reboot, 1);
        return;
    case 1:
        if (data_02733FC8.f140 != 1) {
            CAMERA_I2CPhotoModeAsyncCore(1, data_02733FC8.f140, CAMERA_Reboot, 2);
            return;
        }
    case 2:
        if (data_02733FC8.f17C != 0) {
            CAMERA_I2CPhotoModeAsyncCore(2, data_02733FC8.f17C, CAMERA_Reboot, 3);
            return;
        }
    case 3:
        if (data_02733FC8.f128 != 5) {
            CAMERA_I2CSizeExAsyncCore(1, 1, data_02733FC8.f128, CAMERA_Reboot, 4);
            return;
        }
    case 4:
        if (data_02733FC8.f12C != 0) {
            CAMERA_I2CSizeExAsyncCore(1, 2, data_02733FC8.f12C, CAMERA_Reboot, 5);
            return;
        }
    case 5:
        if (data_02733FC8.f164 != 5) {
            CAMERA_I2CSizeExAsyncCore(2, 1, data_02733FC8.f164, CAMERA_Reboot, 6);
            return;
        }
    case 6:
        if (data_02733FC8.f168 != 0) {
            CAMERA_I2CSizeExAsyncCore(2, 2, data_02733FC8.f168, CAMERA_Reboot, 7);
            return;
        }
    case 7:
        if (data_02733FC8.f148 != 0) {
            CAMERA_I2CFrameRateAsyncCore(1, data_02733FC8.f148, CAMERA_Reboot, 8);
            return;
        }
    case 8:
        if (data_02733FC8.f184 != 0) {
            CAMERA_I2CFrameRateAsyncCore(2, data_02733FC8.f184, CAMERA_Reboot, 9);
            return;
        }
    case 9:
        if (data_02733FC8.f130 != 0) {
            CAMERA_I2CEffectExAsyncCore(1, 1, data_02733FC8.f130, CAMERA_Reboot, 0xA);
            return;
        }
    case 10:
        if (data_02733FC8.f134 != 0) {
            CAMERA_I2CEffectExAsyncCore(1, 2, data_02733FC8.f134, CAMERA_Reboot, 0xB);
            return;
        }
    case 11:
        if (data_02733FC8.f16C != 0) {
            CAMERA_I2CEffectExAsyncCore(2, 1, data_02733FC8.f16C, CAMERA_Reboot, 0xC);
            return;
        }
    case 12:
        if (data_02733FC8.f170 != 0) {
            CAMERA_I2CEffectExAsyncCore(2, 2, data_02733FC8.f170, CAMERA_Reboot, 0xD);
            return;
        }
    case 13:
        if (data_02733FC8.f138 != 2) {
            CAMERA_I2CFlipExAsyncCore(1, 1, data_02733FC8.f138, CAMERA_Reboot, 0xE);
            return;
        }
    case 14:
        if (data_02733FC8.f13C != 2) {
            CAMERA_I2CFlipExAsyncCore(1, 2, data_02733FC8.f13C, CAMERA_Reboot, 0xF);
            return;
        }
    case 15:
        if (data_02733FC8.f174 != 0) {
            CAMERA_I2CFlipExAsyncCore(2, 1, data_02733FC8.f174, CAMERA_Reboot, 0x10);
            return;
        }
    case 16:
        if (data_02733FC8.f178 != 0) {
            CAMERA_I2CFlipExAsyncCore(2, 2, data_02733FC8.f178, CAMERA_Reboot, 0x11);
            return;
        }
    case 17:
        t = CAMERA_GetWhiteBalanceFromPhotoMode(data_02733FC8.f140);
        if (data_02733FC8.f144 != t) {
            CAMERA_I2CWhiteBalanceAsyncCore(1, data_02733FC8.f144, CAMERA_Reboot, 0x12);
            return;
        }
    case 18:
        t = CAMERA_GetWhiteBalanceFromPhotoMode(data_02733FC8.f17C);
        if (data_02733FC8.f180 != t) {
            CAMERA_I2CWhiteBalanceAsyncCore(2, data_02733FC8.f180, CAMERA_Reboot, 0x13);
            return;
        }
    case 19:
        if (data_02733FC8.f14C != CAMERA_GetExposureFromPhotoMode(data_02733FC8.f140)) {
            CAMERA_I2CExposureAsyncCore(1, data_02733FC8.f14C, CAMERA_Reboot, 0x14);
            return;
        }
    case 20:
        if (data_02733FC8.f188 != CAMERA_GetExposureFromPhotoMode(data_02733FC8.f17C)) {
            CAMERA_I2CExposureAsyncCore(2, data_02733FC8.f188, CAMERA_Reboot, 0x15);
            return;
        }
    case 21:
        if (data_02733FC8.f150 != CAMERA_GetSharpnessFromPhotoMode(data_02733FC8.f140)) {
            CAMERA_I2CSharpnessAsyncCore(1, data_02733FC8.f150, CAMERA_Reboot, 0x16);
            return;
        }
    case 22:
        if (data_02733FC8.f18C != CAMERA_GetSharpnessFromPhotoMode(data_02733FC8.f17C)) {
            CAMERA_I2CSharpnessAsyncCore(2, data_02733FC8.f18C, CAMERA_Reboot, 0x17);
            return;
        }
    case 23:
        if (data_02733FC8.f154 != 1) {
            CAMERA_I2CAutoExposureAsyncCore(1, data_02733FC8.f154, CAMERA_Reboot, 0x18);
            return;
        }
    case 24:
        if (data_02733FC8.f190 != 1) {
            CAMERA_I2CAutoExposureAsyncCore(2, data_02733FC8.f190, CAMERA_Reboot, 0x19);
            return;
        }
    case 25:
        if (data_02733FC8.f158 != 1) {
            CAMERA_I2CAutoWhiteBalanceAsyncCore(1, data_02733FC8.f158, CAMERA_Reboot, 0x1A);
            return;
        }
    case 26:
        if (data_02733FC8.f194 != 1) {
            CAMERA_I2CAutoWhiteBalanceAsyncCore(2, data_02733FC8.f194, CAMERA_Reboot, 0x1B);
            return;
        }
    case 27:
        t = data_02733FC8.f15C;
        if (t != 1) {
            if (OS_IsRunOnTwl() == 1) {
                CAMERA_I2CContextSwitchAsyncCore(1, t, CAMERA_Reboot, 0x1C);
            }
            return;
        }
    case 28:
        t = data_02733FC8.f198;
        if (t != 1) {
            if (OS_IsRunOnTwl() == 1) {
                CAMERA_I2CContextSwitchAsyncCore(2, t, CAMERA_Reboot, 0x1D);
            }
            return;
        }
    case 29:
        if (data_02733FC8.f124 != 0) {
            CAMERA_I2CActivateAsyncCore(data_02733FC8.f124, CAMERA_Reboot, 0x1E);
            return;
        }
    case 30:
        if (data_02733FC8.f124 == 2 && data_02733FC8.f19C == 1) {
            if (OS_IsRunOnTwl() == 1) {
                CAMERA_SetLEDAsyncCore(1, CAMERA_Reboot, 0x1F);
            }
            return;
        }
    default:
        break;
    }
    data_02733FC8.f1AC = 0;
    if (data_02732FC8.cbC != 0) {
        data_02732FC8.cbC(0);
    }
}
