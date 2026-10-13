/*
 * function: CAMERA_SetRebootCallbackCore
 * address: 0x02700118
 * packet: pkt_twl_02700118
 * region: twl
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/twl/unit_02700078.c and filed here.
 *
 * symbols:
 *   data_02732FC8 0x02732FC8 data twl a2
 *   CAMERA_SetRebootCallbackCore 0x02700118  arm twl a2
 *   CAMERA_CameraIntr  0x02700078  arm
 *   CAMERA_SetVsyncCallbackCore  0x027000F8  arm
 *   CAMERA_SetBufferErrorCallbackCore  0x02700108  arm
 *   CAMERA_GetWhiteBalanceFromPhotoMode  0x02700128  arm
 *   CAMERA_GetSharpnessFromPhotoMode  0x02700168  arm
 *   CAMERA_GetExposureFromPhotoMode  0x027001B8  arm
 *   CAMERA_GoReboot  0x027001F0  arm
 *   CAMERA_Reboot  0x02700230  arm
 *   CAMERA_CheckRetryCount  0x027007C8  arm
 *   CAMERA_MonitorThread  0x02700824  arm
 *   CAMERA_EndCore  0x02700B34  arm
 *   CAMERA_StopCore  0x02700BD0  arm
 *   CAMERA_I2CInitAsyncCore  0x02700C18  arm
 *   CAMERA_I2CActivateAsyncCore  0x02700CEC  arm
 *   CAMERA_I2CActivateCore  0x02700DB8  arm
 *   CAMERA_I2CContextSwitchAsyncCore  0x02700DF0  arm
 *   CAMERA_I2CSizeExAsyncCore  0x02700EB8  arm
 *   CAMERA_I2CFrameRateAsyncCore  0x02701020  arm
 *   CAMERA_I2CEffectExAsyncCore  0x02701120  arm
 *   CAMERA_I2CFlipExAsyncCore  0x02701284  arm
 *   CAMERA_I2CPhotoModeAsyncCore  0x027013A4  arm
 *   CAMERA_I2CWhiteBalanceAsyncCore  0x02701488  arm
 *   CAMERA_I2CExposureAsyncCore  0x02701570  arm
 *   CAMERA_I2CSharpnessAsyncCore  0x02701644  arm
 *   CAMERA_I2CAutoExposureAsyncCore  0x02701718  arm
 *   CAMERA_I2CAutoWhiteBalanceAsyncCore  0x02701814  arm
 *   CAMERA_SetLEDAsyncCore  0x02701940  arm
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
 *   OS_IsRunOnTwl  0x02085D3C  arm  arm9
 *   PXI_Init  0x02088498  arm  arm9
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
extern u32 func_02087988(void);
extern void func_02085A38(u32);
extern u32 func_02085E50(u32*, u32*, u32);
extern void func_02087974(void);
extern void CAMERA_ResetCore(void);
extern void PXI_Init(void);
extern u32 func_020885EC(u32, u32);
extern void func_020885A0(u32, void (*)(int, u32, int));
extern void CAMERA_StopCaptureCore(void);
extern void CAMERA_ClearBufferCore(void);
extern void func_0208C848(u32*, u32);
extern void PMi_InsertPostExitCallbackEx(u32*, u32);
extern void CAMERA_SetVsyncInterruptCore(u32);
extern void CAMERA_SetBufferErrorInterruptCore(u32);
extern void CAMERA_SetMasterInterruptCore(u32);
extern void func_02084774(u32, TwlFn);
extern void func_02084968(u32);
extern void func_02085D94(u32*, u32*, u32);
extern void func_020853C0(u32*, void (*)(void), u32, u32*, u32, u32);
extern void func_02085868(u32*);
extern void func_0208C86C(u32*);
extern void PM_DeletePostExitCallback(u32*);
extern u32 CAMERA_I2CActivateCore(u32 a0);
extern void func_02084998(u32);
extern void func_02085638(u32*, u32);
extern void func_02087A04(u32);
extern s32 CAMERA_IsBusyCore(void);
extern void func_0208799C(u32);
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

void CAMERA_SetRebootCallbackCore(TwlCb a0) {
    data_02732FC8.cbC = a0;
}
