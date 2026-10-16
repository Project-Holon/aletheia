/*
 * file:     camera_api.c
 * unit:     yes
 * function: CAMERA_CameraIntr, CAMERA_SetVsyncCallbackCore, CAMERA_SetBufferErrorCallbackCore, CAMERA_SetRebootCallbackCore, CAMERA_GetWhiteBalanceFromPhotoMode, CAMERA_GetSharpnessFromPhotoMode, CAMERA_GetExposureFromPhotoMode, CAMERA_GoReboot, CAMERA_Reboot, CAMERA_CheckRetryCount, CAMERA_MonitorThread, CAMERA_InitCore, CAMERA_EndCore, CAMERA_StopCore, CAMERA_I2CInitAsyncCore, CAMERA_I2CInitCore, CAMERA_I2CActivateAsyncCore, CAMERA_I2CActivateCore, CAMERA_I2CContextSwitchAsyncCore, CAMERA_I2CSizeExAsyncCore, CAMERA_I2CSizeExCore, CAMERA_I2CFrameRateAsyncCore, CAMERA_I2CEffectExAsyncCore, CAMERA_I2CEffectExCore, CAMERA_I2CFlipExAsyncCore, CAMERA_I2CPhotoModeAsyncCore, CAMERA_I2CWhiteBalanceAsyncCore, CAMERA_I2CExposureAsyncCore, CAMERA_I2CSharpnessAsyncCore, CAMERA_I2CAutoExposureAsyncCore, CAMERA_I2CAutoExposureCore, CAMERA_I2CAutoWhiteBalanceAsyncCore, CAMERA_I2CAutoWhiteBalanceCore, CAMERA_SetLEDAsyncCore, CameraSendPxiCommand, CameraSendPxiData, CameraPxiCallback, CameraSyncCallback, CameraCallCallbackAndUnlock, CameraWaitBusy, CameraStandbyCallback
 * address:  0x02700078
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libcamera.TWL.HYB.a camera_api.o
 *
 * symbols:
 *   CAMERA_ResetCore  0x02702080  arm
 *   CAMERA_IsBusyCore  0x027020F0  arm
 *   CAMERA_StopCaptureCore  0x0270212C  arm
 *   CAMERA_GetErrorStatusCore  0x027021CC  arm
 *   CAMERA_ClearBufferCore  0x027021E4  arm
 *   CAMERA_SetMasterInterruptCore  0x02702208  arm
 *   CAMERA_SetVsyncInterruptCore  0x0270223C  arm
 *   CAMERA_SetBufferErrorInterruptCore  0x02702268  arm
 *   PMi_InsertPostExitCallbackEx  0x0273156C  arm
 *   PM_DeletePostExitCallback  0x02731590  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm  arm9
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
 *   PXI_SendWordByFifo  0x02088610  arm  arm9
 *   PXIi_HandlerRecvFifoNotEmpty  0x02088688  arm  arm9
 *   OS_InitMessageQueue  0x02085D94  arm  arm9
 *   PMi_InsertPreSleepCallbackEx  0x0208C848  arm  arm9
 *   PM_DeletePreSleepCallback  0x0208C86C  arm  arm9
 *   OS_SendMessage  0x02085DBC  arm  arm9
 *   OS_ReceiveMessage  0x02085E50  arm  arm9
 *   OS_GetTick  0x020870D0  arm  arm9
 *   OS_SetIrqFunction  0x02084774  arm  arm9
 *   PXI_SetFifoRecvCallback  0x020885A0  arm  arm9
 *   OS_EnableInterrupts  0x02087974  arm  arm9
 *   OS_GetCpsrIrq  0x020879E0  arm  arm9
 */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;
typedef signed long long s64;
typedef volatile u32 vu32;

typedef void (*TwlCb)(u32);
typedef void (*TwlFn)(void);
typedef void (*CamPxiCallback)(u32 result, u32 arg);

#define reg_04004004 (*(volatile u16 *)0x04004004)

typedef struct TwlShared {
    u8 pad[0x3FF8];
    vu32 flags;
} TwlShared;

/* Camera driver work area at data_02732FC8 (command block, callbacks, thread). */
typedef struct CamSys {
    u32 busy;
    CamPxiCallback callback;
    u32 f08;
    u32 arg;
    s32 command;
    s32 type;
    u8 index;
    u8 total;
    u8 pad1A[2];
    u8 *buf;
    u32 len;
    u32 pend0;
    u32 pend1;
    u32 pend2;
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
    u8 thread[0x124 - 0x64];      /* 0x0064: the thread (data_0273302C) */
    u8 stack[0x1124 - 0x124];     /* 0x0124: its stack, top at data_027340EC */
    u8 settings[0x11B4 - 0x1124]; /* 0x1124: CamState f124..f1B0 (data_02733FC8 is this object + 0x1000) */
    u8 queue[0x11D4 - 0x11B4];    /* 0x11B4: message queue (data_0273417C) */
    u32 msg[1];                   /* 0x11D4: its one-message buffer (data_0273419C); data_027341A0 follows */
} CamSys;

/* Camera settings and last-command state at data_02733FC8. */
/* The volatile members are written from the PXI callback and read in the
   settings-restore sequence; the original object needs them volatile. */
typedef struct CamState {
    u8 pad00[0x124];
    u32 f124;
    volatile s32 f128, f12c, f130, f134, f138, f13c;
    s32 f140, f144;
    s32 f148, f14c, f150, f154, f158, f15c, f160;
    volatile s32 f164, f168, f16c, f170, f174, f178;
    s32 f17c, f180, f184;
    s32 f188, f18c, f190, f194, f198, f19c;
    u32 flagsA;
    u32 flagsB;
    s32 value;
    u32 f1ac;
    s32 f1b0;
} CamState;

extern CamSys data_02732FC8;
extern CamState data_02733FC8;
extern u32 data_0273417C[];
extern u32 data_02732FC0[];
extern u32 data_02732FF8[];
extern u32 data_02733008[];
extern u32 data_0273419C[];
extern u32 data_0273302C[];
extern u32 data_027340EC[];
extern u16 data_04000208;

extern u32 OS_IsRunOnTwl(void);
extern u64 OS_GetTick(void);
extern void OS_SendMessage(u32*, u32, u32);
extern u32 OS_DisableInterrupts(void);
extern void OS_Sleep(u32);
extern u32 OS_ReceiveMessage(u32*, u32*, u32);
extern void OS_EnableInterrupts(void);
extern void PXI_Init(void);
extern u32 PXI_IsCallbackReady(u32, u32);
extern void PXI_SetFifoRecvCallback(u32, void (*)(int, u32, int));
extern void PMi_InsertPreSleepCallbackEx(u32*, u32);
extern void PMi_InsertPostExitCallbackEx(u32*, u32);
extern void OS_SetIrqFunction(u32, TwlFn);
extern void OS_EnableIrqMask(u32);
extern void OS_InitMessageQueue(u32*, u32*, u32);
extern void OS_CreateThread(u32*, void (*)(void), u32, u32*, u32, u32);
extern void OS_WakeupThreadDirect(u32*);
extern void PM_DeletePreSleepCallback(u32*);
extern void PM_DeletePostExitCallback(u32*);
extern void OS_DisableIrqMask(u32);
extern void OS_KillThread(u32*, u32);
extern void OS_SpinWaitSysCycles(u32);
extern void OS_RestoreInterrupts(u32);
extern int PXI_SendWordByFifo(u32, u32, u32);
extern u32 OS_GetCpsrIrq(void);
extern void PXIi_HandlerRecvFifoNotEmpty(void);

/* camera.o */
extern s32 CAMERA_GetErrorStatusCore(void);
extern s32 CAMERA_IsBusyCore(void);
extern void CAMERA_ResetCore(void);
extern void CAMERA_StopCaptureCore(void);
extern void CAMERA_ClearBufferCore(void);
extern void CAMERA_SetVsyncInterruptCore(u32);
extern void CAMERA_SetBufferErrorInterruptCore(u32);
extern void CAMERA_SetMasterInterruptCore(u32);

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
u32 CAMERA_InitCore(void);
void CAMERA_EndCore(void);
void CAMERA_StopCore(void);
u32 CAMERA_I2CInitAsyncCore(u32 a0, CamPxiCallback a1, u32 a2);
u32 CAMERA_I2CInitCore(u32 a0);
u32 CAMERA_I2CActivateAsyncCore(u32 a0, CamPxiCallback a1, u32 a2);
u32 CAMERA_I2CActivateCore(u32 a0);
u32 CAMERA_I2CContextSwitchAsyncCore(u32 a0, u32 a1, CamPxiCallback a2, u32 a3);
u32 CAMERA_I2CSizeExAsyncCore(u32 a0, u32 a1, u32 a2, CamPxiCallback a3, u32 a4);
u32 CAMERA_I2CSizeExCore(u32 a0, u32 a1, u32 a2);
u32 CAMERA_I2CFrameRateAsyncCore(u32 a0, s32 a1, CamPxiCallback a2, u32 a3);
u32 CAMERA_I2CEffectExAsyncCore(u32 a0, u32 a1, u32 a2, CamPxiCallback a3, u32 a4);
u32 CAMERA_I2CEffectExCore(u32 a0, u32 a1, u32 a2);
u32 CAMERA_I2CFlipExAsyncCore(u32 a0, u32 a1, s32 a2, CamPxiCallback a3, u32 a4);
u32 CAMERA_I2CPhotoModeAsyncCore(u32 a0, s32 a1, CamPxiCallback a2, u32 a3);
u32 CAMERA_I2CWhiteBalanceAsyncCore(u32 a0, s32 a1, CamPxiCallback a2, u32 a3);
u32 CAMERA_I2CExposureAsyncCore(u32 a0, s32 a1, CamPxiCallback a2, u32 a3);
u32 CAMERA_I2CSharpnessAsyncCore(u32 a0, s32 a1, CamPxiCallback a2, u32 a3);
u32 CAMERA_I2CAutoExposureAsyncCore(u32 a0, s32 a1, CamPxiCallback a2, u32 a3);
u32 CAMERA_I2CAutoExposureCore(u32 a0, u32 a1);
u32 CAMERA_I2CAutoWhiteBalanceAsyncCore(u32 a0, s32 a1, CamPxiCallback a2, u32 a3);
u32 CAMERA_I2CAutoWhiteBalanceCore(u32 a0, u32 a1);
int CAMERA_SetLEDAsyncCore(u32 command, CamPxiCallback callback, u32 arg);
int CameraSendPxiCommand(u32 a0, u32 a1, u32 a2);
void CameraSendPxiData(const u8 *ptr);
void CameraPxiCallback(int tag, u32 data, int err);
void CameraSyncCallback(u32 a0, u32 a1);
void CameraCallCallbackAndUnlock(u32 result);
void CameraWaitBusy(void);
static void CameraStandbyCallback(void);


void CAMERA_CameraIntr(void) {
    TwlShared *sh = (TwlShared *)0x02FE0000;
    u32 r;
    TwlCb cb;
    sh->flags |= 0x02000000;
    r = OS_IsRunOnTwl();
    if (r == 1) {
        r = CAMERA_GetErrorStatusCore();
    } else {
        r = 0;
    }
    if (r != 0) {
        cb = data_02732FC8.cbB;
        if (cb != 0) {
            cb(0);
        }
    } else {
        data_02732FC8.tick = OS_GetTick();
        cb = data_02732FC8.cbA;
        if (cb != 0) {
            cb(0);
        }
    }
}


void CAMERA_SetVsyncCallbackCore(TwlCb a0) {
    data_02732FC8.cbA = a0;
}


void CAMERA_SetBufferErrorCallbackCore(TwlCb a0) {
    data_02732FC8.cbB = a0;
}


void CAMERA_SetRebootCallbackCore(TwlCb a0) {
    data_02732FC8.cbC = a0;
}


u32 CAMERA_GetWhiteBalanceFromPhotoMode(u32 a0) {
    switch (a0) {
    case 0:
    case 1:
        return 0;
    case 2:
        return 3;
    case 3:
    case 4:
        return 0;
    default:
        return 0;
    }
}


s32 CAMERA_GetSharpnessFromPhotoMode(u32 a0) {
    switch (a0) {
    case 0:
        return 0;
    case 1:
        return -2;
    case 2:
        return 1;
    case 3:
        return -1;
    case 4:
        return 2;
    default:
        return 0;
    }
}


u32 CAMERA_GetExposureFromPhotoMode(u32 a0) {
    switch (a0) {
    case 0:
    case 1:
    case 2:
        return 0;
    case 3:
    case 4:
        return 2;
    default:
        return 0;
    }
}


void CAMERA_GoReboot(void) {
    data_02732FC8.busy = 1;
    data_02733FC8.f1ac++;
    OS_SendMessage(data_0273417C, 0, 0);
}


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
        if (data_02733FC8.f17c != 0) {
            CAMERA_I2CPhotoModeAsyncCore(2, data_02733FC8.f17c, CAMERA_Reboot, 3);
            return;
        }
    case 3:
        if (data_02733FC8.f128 != 5) {
            CAMERA_I2CSizeExAsyncCore(1, 1, data_02733FC8.f128, CAMERA_Reboot, 4);
            return;
        }
    case 4:
        if (data_02733FC8.f12c != 0) {
            CAMERA_I2CSizeExAsyncCore(1, 2, data_02733FC8.f12c, CAMERA_Reboot, 5);
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
        if (data_02733FC8.f16c != 0) {
            CAMERA_I2CEffectExAsyncCore(2, 1, data_02733FC8.f16c, CAMERA_Reboot, 0xC);
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
        if (data_02733FC8.f13c != 2) {
            CAMERA_I2CFlipExAsyncCore(1, 2, data_02733FC8.f13c, CAMERA_Reboot, 0xF);
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
        t = CAMERA_GetWhiteBalanceFromPhotoMode(data_02733FC8.f17c);
        if (data_02733FC8.f180 != t) {
            CAMERA_I2CWhiteBalanceAsyncCore(2, data_02733FC8.f180, CAMERA_Reboot, 0x13);
            return;
        }
    case 19:
        if (data_02733FC8.f14c != CAMERA_GetExposureFromPhotoMode(data_02733FC8.f140)) {
            CAMERA_I2CExposureAsyncCore(1, data_02733FC8.f14c, CAMERA_Reboot, 0x14);
            return;
        }
    case 20:
        if (data_02733FC8.f188 != CAMERA_GetExposureFromPhotoMode(data_02733FC8.f17c)) {
            CAMERA_I2CExposureAsyncCore(2, data_02733FC8.f188, CAMERA_Reboot, 0x15);
            return;
        }
    case 21:
        if (data_02733FC8.f150 != CAMERA_GetSharpnessFromPhotoMode(data_02733FC8.f140)) {
            CAMERA_I2CSharpnessAsyncCore(1, data_02733FC8.f150, CAMERA_Reboot, 0x16);
            return;
        }
    case 22:
        if (data_02733FC8.f18c != CAMERA_GetSharpnessFromPhotoMode(data_02733FC8.f17c)) {
            CAMERA_I2CSharpnessAsyncCore(2, data_02733FC8.f18c, CAMERA_Reboot, 0x17);
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
        t = data_02733FC8.f15c;
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
        if (data_02733FC8.f124 == 2 && data_02733FC8.f19c == 1) {
            if (OS_IsRunOnTwl() == 1) {
                CAMERA_SetLEDAsyncCore(1, CAMERA_Reboot, 0x1F);
            }
            return;
        }
    default:
        break;
    }
    data_02733FC8.f1ac = 0;
    if (data_02732FC8.cbC != 0) {
        data_02732FC8.cbC(0);
    }
}


u32 CAMERA_CheckRetryCount(void) {
    u32 n = data_02733FC8.f1ac;
    if (n > 2) {
        if (data_02733FC8.f124 != 0) {
            data_02732FC8.pend2 = 1;
            data_02733FC8.f124 = 0;
            CameraSendPxiCommand(0x10, 1, 0);
        }
        return 7;
    }
    if (n != 0) {
        return 6;
    }
    return 0;
}


void CAMERA_MonitorThread(void) {
    u32 msg;
    TwlCb cb;
    s32 d;
    OS_DisableInterrupts();
    for (;;) {
        OS_Sleep(100);
        if (OS_ReceiveMessage(data_0273417C, &msg, 0) != 0) {
            goto handle;
        }
        if (data_02733FC8.f1ac != 0) {
            continue;
        }
        if (data_02733FC8.f124 == 0) {
            continue;
        }
        if (data_02732FC8.busy != 0) {
            continue;
        }
        data_02733FC8.f1b0++;
        if (data_02733FC8.f1b0 < 10) {
            continue;
        }
        data_02733FC8.f1b0 = 0;
        d = (s32)(OS_GetTick() - data_02732FC8.tick);
        if ((u64)(s64)d < 0x7FD88) {
            continue;
        }
        data_02732FC8.busy = 1;
        data_02733FC8.f1ac++;
handle:
        if (CAMERA_CheckRetryCount() == 7) {
            data_02732FC8.busy = 0;
            cb = data_02732FC8.cbC;
            if (cb != 0) {
                cb(7);
            }
            return;
        }
        OS_EnableInterrupts();
        CAMERA_ResetCore();
        OS_DisableInterrupts();
        data_02732FC8.busy = 0;
        CAMERA_Reboot(0, 0);
    }
}


u32 CAMERA_InitCore(void) {
    if (data_02732FC0[0] != 0) {
        return 2;
    }
    data_02732FC0[0] = 1;
    data_02732FC8.cbA = 0;
    data_02732FC8.cbB = 0;
    data_02732FC8.cbC = 0;
    data_02732FC8.busy = 0;
    data_02732FC8.callback = 0;
    data_02732FC8.pend1 = 0;
    data_02732FC8.pend2 = 0;
    data_02733FC8.f124 = 0;
    data_02733FC8.f1ac = 0;
    data_02733FC8.f1b0 = 0;
    PXI_Init();
    if (PXI_IsCallbackReady(0x15, 1) == 0) {
        return 7;
    }
    PXI_SetFifoRecvCallback(0x15, CameraPxiCallback);
    CAMERA_ResetCore();
    CAMERA_StopCaptureCore();
    CAMERA_ClearBufferCore();
    data_02732FC8.f30 = CameraStandbyCallback;
    data_02732FC8.f34 = 0;
    PMi_InsertPreSleepCallbackEx(data_02732FF8, 0x3FC);
    data_02732FC8.f40 = CameraStandbyCallback;
    data_02732FC8.f44 = 0;
    PMi_InsertPostExitCallbackEx(data_02733008, 0x3FC);
    CAMERA_SetVsyncInterruptCore(0x200);
    CAMERA_SetBufferErrorInterruptCore(1);
    CAMERA_SetMasterInterruptCore(1);
    OS_SetIrqFunction(0x02000000, CAMERA_CameraIntr);
    OS_EnableIrqMask(0x02000000);
    data_02733FC8.f128 = 5;
    data_02733FC8.f12c = 0;
    data_02733FC8.f130 = 0;
    data_02733FC8.f134 = 0;
    data_02733FC8.f138 = 2;
    data_02733FC8.f13c = 2;
    data_02733FC8.f140 = 1;
    data_02733FC8.f144 = 0;
    data_02733FC8.f148 = 0;
    data_02733FC8.f14c = 0;
    data_02733FC8.f150 = -2;
    data_02733FC8.f154 = 1;
    data_02733FC8.f158 = 1;
    data_02733FC8.f15c = 1;
    data_02733FC8.f160 = 0;
    data_02733FC8.f164 = 5;
    data_02733FC8.f168 = 0;
    data_02733FC8.f16c = 0;
    data_02733FC8.f170 = 0;
    data_02733FC8.f174 = 0;
    data_02733FC8.f178 = 0;
    data_02733FC8.f17c = 0;
    data_02733FC8.f180 = 0;
    data_02733FC8.f184 = 0;
    data_02733FC8.f188 = 0;
    data_02733FC8.f18c = 0;
    data_02733FC8.f190 = 1;
    data_02733FC8.f194 = 1;
    data_02733FC8.f198 = 1;
    data_02733FC8.f19c = 0;
    OS_InitMessageQueue(data_0273417C, data_0273419C, 1);
    OS_CreateThread(data_0273302C, CAMERA_MonitorThread, 0, data_027340EC, 0x1000, 4);
    OS_WakeupThreadDirect(data_0273302C);
    return 0;
}


void CAMERA_EndCore(void) {
    if (data_02732FC0[0] == 0) return;
    data_02732FC0[0] = 0;
    PM_DeletePreSleepCallback(data_02732FF8);
    PM_DeletePostExitCallback(data_02733008);
    CAMERA_I2CActivateCore(0);
    CAMERA_ResetCore();
    CAMERA_StopCaptureCore();
    CAMERA_ClearBufferCore();
    PXI_SetFifoRecvCallback(0x15, 0);
    CAMERA_SetVsyncInterruptCore(0);
    CAMERA_SetBufferErrorInterruptCore(0);
    CAMERA_SetMasterInterruptCore(0);
    OS_SetIrqFunction(0x02000000, 0);
    OS_DisableIrqMask(0x02000000);
    OS_KillThread(data_0273302C, 0);
}


void CAMERA_StopCore(void) {
    s32 r5 = 0x001991B0;
    u32 r4 = 4;
    CAMERA_StopCaptureCore();
    goto entry;
    do {
        OS_SpinWaitSysCycles(r4);
entry:
        if (r5-- <= 0) break;
    } while (CAMERA_IsBusyCore() != 0);

    CAMERA_ClearBufferCore();
    CAMERA_I2CActivateCore(0);
}


u32 CAMERA_I2CInitAsyncCore(u32 a0, CamPxiCallback a1, u32 a2) {
    u32 st = CAMERA_CheckRetryCount();
    u32 irq;
    u32 ret;
    if (st == 7) {
        return st;
    }
    if (a0 != 1 && a0 != 2 && a0 != 3) {
        return 3;
    }
    irq = OS_DisableInterrupts();
    if (data_02732FC8.busy != 0) {
        OS_RestoreInterrupts(irq);
        ret = 6;
        if (st != 6) {
            ret = 2;
        }
        return ret;
    }
    data_02732FC8.busy = 1;
    OS_RestoreInterrupts(irq);
    data_02732FC8.callback = a1;
    ret = 0;
    data_02732FC8.arg = a2;
    data_02732FC8.pend2 = 1;
    if (CameraSendPxiCommand(0, 1, a0 & 0xFF) == 0) {
        ret = 4;
    }
    return ret;
}


u32 CAMERA_I2CInitCore(u32 a0) {
    u32 ret = CAMERA_I2CInitAsyncCore(a0, CameraSyncCallback, 0);
    data_02732FC8.f08 = ret;
    if (ret == 0) {
        CameraWaitBusy();
    }
    return data_02732FC8.f08;
}


u32 CAMERA_I2CActivateAsyncCore(u32 a0, CamPxiCallback a1, u32 a2)
{
    u32 status = CAMERA_CheckRetryCount();
    u64 tick;
    u32 irq;
    u32 ret;

    if (status == 7) {
        return status;
    }
    if (a0 != 0 && a0 != 1 && a0 != 2) {
        return 3;
    }
    irq = OS_DisableInterrupts();
    if (data_02732FC8.busy != 0) {
        OS_RestoreInterrupts(irq);
        ret = 6;
        if (status != 6) {
            ret = 2;
        }
        return ret;
    }
    data_02732FC8.busy = 1;
    OS_RestoreInterrupts(irq);
    data_02732FC8.callback = a1;
    data_02732FC8.arg = a2;
    if (a0 == 0) {
        data_02732FC8.pend2 = 1;
    } else {
        data_02732FC8.pend1 = 1;
    }
    data_02733FC8.f124 = a0;
    if (data_02733FC8.f1ac == 0) {
        data_02733FC8.value = 0;
    }
    tick = OS_GetTick();
    data_02732FC8.tick = tick;
    return CameraSendPxiCommand(0x10, 1, a0 & 0xff) != 0 ? 0 : 4;
}


u32 CAMERA_I2CActivateCore(u32 a0) {
    u32 ret = CAMERA_I2CActivateAsyncCore(a0, CameraSyncCallback, 0);
    data_02732FC8.f08 = ret;
    if (ret == 0) {
        CameraWaitBusy();
    }
    return data_02732FC8.f08;
}


u32 CAMERA_I2CContextSwitchAsyncCore(u32 a0, u32 a1, CamPxiCallback a2, u32 a3)
{
    u32 status = CAMERA_CheckRetryCount();
    u32 irq;
    u32 ret;
    u8 buf[2];

    if (status == 7) {
        return status;
    }
    if (a0 != 1 && a0 != 2) {
        return 3;
    }
    if (a1 != 1 && a1 != 2) {
        return 3;
    }
    irq = OS_DisableInterrupts();
    if (data_02732FC8.busy != 0) {
        OS_RestoreInterrupts(irq);
        ret = 6;
        if (status != 6) {
            ret = 2;
        }
        return ret;
    }
    data_02732FC8.busy = 1;
    OS_RestoreInterrupts(irq);
    data_02732FC8.callback = a2;
    data_02732FC8.arg = a3;
    buf[0] = a0;
    buf[1] = a1;
    data_02733FC8.flagsA = a0;
    data_02733FC8.value = a1;
    if (CameraSendPxiCommand(0x12, 2, buf[0]) == 0) {
        return 4;
    }
    CameraSendPxiData(&buf[1]);
    return 0;
}


u32 CAMERA_I2CSizeExAsyncCore(u32 a0, u32 a1, u32 a2, CamPxiCallback a3, u32 a4)
{
    u32 status = CAMERA_CheckRetryCount();
    u32 irq;
    u32 ret;
    u8 buf[8];

    if (status == 7) {
        return status;
    }
    if (a0 != 1 && a0 != 2 && a0 != 3) {
        return 3;
    }
    if (a1 != 1 && a1 != 2 && a1 != 3) {
        return 3;
    }
    switch (a2) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        break;
    default:
        return 3;
    }
    irq = OS_DisableInterrupts();
    if (data_02732FC8.busy != 0) {
        OS_RestoreInterrupts(irq);
        ret = 6;
        if (status != 6) {
            ret = 2;
        }
        return ret;
    }
    data_02732FC8.busy = 1;
    OS_RestoreInterrupts(irq);
    data_02732FC8.callback = a3;
    data_02732FC8.arg = a4;
    buf[0] = a0;
    buf[1] = a1;
    buf[2] = a2;
    data_02733FC8.flagsA = a0;
    data_02733FC8.flagsB = a1;
    data_02733FC8.value = a2;
    if (CameraSendPxiCommand(0x30, 3, buf[0]) == 0) {
        return 4;
    }
    CameraSendPxiData(&buf[1]);
    return 0;
}


u32 CAMERA_I2CSizeExCore(u32 a0, u32 a1, u32 a2) {
    u32 ret = CAMERA_I2CSizeExAsyncCore(a0, a1, a2, CameraSyncCallback, 0);
    data_02732FC8.f08 = ret;
    if (ret == 0) {
        CameraWaitBusy();
    }
    return data_02732FC8.f08;
}


u32 CAMERA_I2CFrameRateAsyncCore(u32 a0, s32 a1, CamPxiCallback a2, u32 a3)
{
    u32 status = CAMERA_CheckRetryCount();
    u32 irq;
    u32 ret;
    u8 buf[2];

    if (status == 7) {
        return status;
    }
    if (a0 != 1 && a0 != 2 && a0 != 3) {
        return 3;
    }
    switch (a1) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        break;
    default:
        return 3;
    }
    irq = OS_DisableInterrupts();
    if (data_02732FC8.busy != 0) {
        OS_RestoreInterrupts(irq);
        ret = 6;
        if (status != 6) {
            ret = 2;
        }
        return ret;
    }
    data_02732FC8.busy = 1;
    OS_RestoreInterrupts(irq);
    data_02732FC8.callback = a2;
    data_02732FC8.arg = a3;
    buf[0] = a0;
    buf[1] = a1;
    data_02733FC8.flagsA = a0;
    data_02733FC8.value = a1;
    if (CameraSendPxiCommand(0x31, 2, buf[0]) == 0) {
        return 4;
    }
    CameraSendPxiData(&buf[1]);
    return 0;
}


u32 CAMERA_I2CEffectExAsyncCore(u32 a0, u32 a1, u32 a2, CamPxiCallback a3, u32 a4)
{
    u32 status = CAMERA_CheckRetryCount();
    u32 irq;
    u32 ret;
    u8 buf[8];

    if (status == 7) {
        return status;
    }
    if (a0 != 1 && a0 != 2 && a0 != 3) {
        return 3;
    }
    if (a1 != 1 && a1 != 2 && a1 != 3) {
        return 3;
    }
    switch (a2) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    default:
        return 3;
    }
    irq = OS_DisableInterrupts();
    if (data_02732FC8.busy != 0) {
        OS_RestoreInterrupts(irq);
        ret = 6;
        if (status != 6) {
            ret = 2;
        }
        return ret;
    }
    data_02732FC8.busy = 1;
    OS_RestoreInterrupts(irq);
    data_02732FC8.callback = a3;
    data_02732FC8.arg = a4;
    buf[0] = a0;
    buf[1] = a1;
    buf[2] = a2;
    data_02733FC8.flagsA = a0;
    data_02733FC8.flagsB = a1;
    data_02733FC8.value = a2;
    if (CameraSendPxiCommand(0x32, 3, buf[0]) == 0) {
        return 4;
    }
    CameraSendPxiData(&buf[1]);
    return 0;
}


u32 CAMERA_I2CEffectExCore(u32 a0, u32 a1, u32 a2) {
    u32 ret = CAMERA_I2CEffectExAsyncCore(a0, a1, a2, CameraSyncCallback, 0);
    data_02732FC8.f08 = ret;
    if (ret == 0) {
        CameraWaitBusy();
    }
    return data_02732FC8.f08;
}


u32 CAMERA_I2CFlipExAsyncCore(u32 a0, u32 a1, s32 a2, CamPxiCallback a3, u32 a4) {
    u8 buf[8];
    u32 st = CAMERA_CheckRetryCount();
    u32 irq;
    if (st == 7) {
        return st;
    }
    if (a0 != 1 && a0 != 2 && a0 != 3) {
        return 3;
    }
    if (a1 != 1 && a1 != 2 && a1 != 3) {
        return 3;
    }
    switch (a2) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    default:
        return 3;
    }
    irq = OS_DisableInterrupts();
    if (data_02732FC8.busy != 0) {
        OS_RestoreInterrupts(irq);
        return (st == 6) ? 6 : 2;
    }
    data_02732FC8.busy = 1;
    OS_RestoreInterrupts(irq);
    data_02732FC8.callback = a3;
    data_02732FC8.arg = a4;
    buf[0] = a0;
    buf[1] = a1;
    buf[2] = a2;
    data_02733FC8.flagsA = a0;
    data_02733FC8.flagsB = a1;
    data_02733FC8.value = a2;
    if (CameraSendPxiCommand(0x33, 3, buf[0]) == 0) {
        return 4;
    }
    CameraSendPxiData(&buf[1]);
    return 0;
}


u32 CAMERA_I2CPhotoModeAsyncCore(u32 a0, s32 a1, CamPxiCallback a2, u32 a3) {
    u8 buf[2];
    u32 st = CAMERA_CheckRetryCount();
    u32 irq;
    if (st == 7) {
        return st;
    }
    if (a0 != 1 && a0 != 2 && a0 != 3) {
        return 3;
    }
    switch (a1) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        break;
    default:
        return 3;
    }
    irq = OS_DisableInterrupts();
    if (data_02732FC8.busy != 0) {
        OS_RestoreInterrupts(irq);
        return (st == 6) ? 6 : 2;
    }
    data_02732FC8.busy = 1;
    OS_RestoreInterrupts(irq);
    data_02732FC8.callback = a2;
    data_02732FC8.arg = a3;
    buf[0] = a0;
    buf[1] = a1;
    data_02733FC8.flagsA = a0;
    data_02733FC8.value = a1;
    if (CameraSendPxiCommand(0x34, 2, buf[0]) == 0) {
        return 4;
    }
    CameraSendPxiData(&buf[1]);
    return 0;
}


u32 CAMERA_I2CWhiteBalanceAsyncCore(u32 a0, s32 a1, CamPxiCallback a2, u32 a3) {
    u8 buf[2];
    u32 st = CAMERA_CheckRetryCount();
    u32 irq;
    if (st == 7) {
        return st;
    }
    if (a0 != 1 && a0 != 2 && a0 != 3) {
        return 3;
    }
    switch (a1) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    default:
        return 3;
    }
    irq = OS_DisableInterrupts();
    if (data_02732FC8.busy != 0) {
        OS_RestoreInterrupts(irq);
        return (st == 6) ? 6 : 2;
    }
    data_02732FC8.busy = 1;
    OS_RestoreInterrupts(irq);
    data_02732FC8.callback = a2;
    data_02732FC8.arg = a3;
    buf[0] = a0;
    buf[1] = a1;
    data_02733FC8.flagsA = a0;
    data_02733FC8.value = a1;
    if (CameraSendPxiCommand(0x35, 2, buf[0]) == 0) {
        return 4;
    }
    CameraSendPxiData(&buf[1]);
    return 0;
}


u32 CAMERA_I2CExposureAsyncCore(u32 a0, s32 a1, CamPxiCallback a2, u32 a3) {
    u8 buf[2];
    u32 st = CAMERA_CheckRetryCount();
    u32 irq;
    if (st == 7) {
        return st;
    }
    if (a0 != 1 && a0 != 2 && a0 != 3) {
        return 3;
    }
    if (a1 < -5 || a1 > 5) {
        return 3;
    }
    irq = OS_DisableInterrupts();
    if (data_02732FC8.busy != 0) {
        OS_RestoreInterrupts(irq);
        return (st == 6) ? 6 : 2;
    }
    data_02732FC8.busy = 1;
    OS_RestoreInterrupts(irq);
    data_02732FC8.callback = a2;
    data_02732FC8.arg = a3;
    buf[0] = a0;
    buf[1] = a1;
    data_02733FC8.flagsA = a0;
    data_02733FC8.value = a1;
    if (CameraSendPxiCommand(0x36, 2, buf[0]) == 0) {
        return 4;
    }
    CameraSendPxiData(&buf[1]);
    return 0;
}


u32 CAMERA_I2CSharpnessAsyncCore(u32 a0, s32 a1, CamPxiCallback a2, u32 a3) {
    u8 buf[2];
    u32 st = CAMERA_CheckRetryCount();
    u32 irq;
    if (st == 7) {
        return st;
    }
    if (a0 != 1 && a0 != 2 && a0 != 3) {
        return 3;
    }
    if (a1 < -3 || a1 > 5) {
        return 3;
    }
    irq = OS_DisableInterrupts();
    if (data_02732FC8.busy != 0) {
        OS_RestoreInterrupts(irq);
        return (st == 6) ? 6 : 2;
    }
    data_02732FC8.busy = 1;
    OS_RestoreInterrupts(irq);
    data_02732FC8.callback = a2;
    data_02732FC8.arg = a3;
    buf[0] = a0;
    buf[1] = a1;
    data_02733FC8.flagsA = a0;
    data_02733FC8.value = a1;
    if (CameraSendPxiCommand(0x37, 2, buf[0]) == 0) {
        return 4;
    }
    CameraSendPxiData(&buf[1]);
    return 0;
}


u32 CAMERA_I2CAutoExposureAsyncCore(u32 a0, s32 a1, CamPxiCallback a2, u32 a3) {
    u8 buf[2];
    u32 st = CAMERA_CheckRetryCount();
    u32 irq;
    if (st == 7) {
        return st;
    }
    if (a0 != 1 && a0 != 2 && a0 != 3) {
        return 3;
    }
    irq = OS_DisableInterrupts();
    if (data_02732FC8.busy != 0) {
        OS_RestoreInterrupts(irq);
        return (st == 6) ? 6 : 2;
    }
    data_02732FC8.busy = 1;
    OS_RestoreInterrupts(irq);
    data_02732FC8.callback = a2;
    data_02732FC8.arg = a3;
    buf[0] = a0;
    buf[1] = (a1 != 0) ? 1 : 0;
    data_02733FC8.flagsA = a0;
    data_02733FC8.value = a1;
    if (CameraSendPxiCommand(0x39, 2, buf[0]) == 0) {
        return 4;
    }
    CameraSendPxiData(&buf[1]);
    return 0;
}


u32 CAMERA_I2CAutoExposureCore(u32 a0, u32 a1) {
    u32 ret = CAMERA_I2CAutoExposureAsyncCore(a0, a1, CameraSyncCallback, 0);
    data_02732FC8.f08 = ret;
    if (ret == 0) {
        CameraWaitBusy();
    }
    return data_02732FC8.f08;
}


u32 CAMERA_I2CAutoWhiteBalanceAsyncCore(u32 a0, s32 a1, CamPxiCallback a2, u32 a3) {
    u8 buf[2];
    u32 st = CAMERA_CheckRetryCount();
    u32 irq;
    if (st == 7) {
        return st;
    }
    if (a0 != 1 && a0 != 2 && a0 != 3) {
        return 3;
    }
    if ((a0 & 1) && data_02733FC8.f144 != 0) {
        return 5;
    }
    if ((a0 & 2) && data_02733FC8.f180 != 0) {
        return 5;
    }
    irq = OS_DisableInterrupts();
    if (data_02732FC8.busy != 0) {
        OS_RestoreInterrupts(irq);
        return (st == 6) ? 6 : 2;
    }
    data_02732FC8.busy = 1;
    OS_RestoreInterrupts(irq);
    data_02732FC8.callback = a2;
    data_02732FC8.arg = a3;
    buf[0] = a0;
    buf[1] = (a1 != 0) ? 1 : 0;
    data_02733FC8.flagsA = a0;
    data_02733FC8.value = a1;
    if (CameraSendPxiCommand(0x3a, 2, buf[0]) == 0) {
        return 4;
    }
    CameraSendPxiData(&buf[1]);
    return 0;
}


u32 CAMERA_I2CAutoWhiteBalanceCore(u32 a0, u32 a1) {
    u32 ret = CAMERA_I2CAutoWhiteBalanceAsyncCore(a0, a1, CameraSyncCallback, 0);
    data_02732FC8.f08 = ret;
    if (ret == 0) {
        CameraWaitBusy();
    }
    return data_02732FC8.f08;
}


int CAMERA_SetLEDAsyncCore(u32 command, CamPxiCallback callback, u32 arg) {
    u32 irq = OS_DisableInterrupts();
    if (data_02732FC8.busy != 0) {
        OS_RestoreInterrupts(irq);
        return 2;
    }
    data_02732FC8.busy = 1;
    OS_RestoreInterrupts(irq);
    data_02732FC8.callback = callback;
    data_02732FC8.arg = arg;
    data_02733FC8.value = command;
    if (CameraSendPxiCommand(0x40, 1, command & 0xff) != 0) {
        return 0;
    }
    return 4;
}


int CameraSendPxiCommand(u32 a0, u32 a1, u32 a2) {
    u32 word = ((a0 << 8) & 0x7f00) | 0x2000000 | ((a1 << 16) & 0xff0000) | (a2 & 0xff);
    u32 irq = OS_DisableInterrupts();
    u16 old = reg_04004004;
    s32 had;
    reg_04004004 = old | 0x100;
    OS_RestoreInterrupts(irq);
    had = old & 0x100;
    if (had == 0) {
        OS_SpinWaitSysCycles(0x14);
    }
    data_02732FC8.pend0 = had >> 8;
    if (PXI_SendWordByFifo(0x15, word, 0) < 0) {
        if (data_02732FC8.pend0 == 0) {
            u32 irq2 = OS_DisableInterrupts();
            reg_04004004 = reg_04004004 & ~0x100;
            OS_RestoreInterrupts(irq2);
        }
        return 0;
    }
    return 1;
}


void CameraSendPxiData(const u8 *ptr) {
    u32 word = (ptr[0] << 16) | (ptr[1] << 8) | ptr[2];
    do {
    } while (PXI_SendWordByFifo(0x15, word, 0) < 0);
}


void CameraPxiCallback(int tag, u32 data, int err)
{
    u32 result;
    u8 *buf;

    if (err) {
        CameraCallCallbackAndUnlock(7);
        return;
    }
    if (data & 0x2000000) {
        data_02732FC8.total = (data & 0xff0000) >> 16;
        data_02732FC8.index = 0;
        data_02732FC8.command = (data & 0x7f00) >> 8;
        data_02732FC8.type = data & 0xff;
    } else {
        buf = data_02732FC8.buf;
        if (buf == 0) {
            CameraCallCallbackAndUnlock(7);
            return;
        }
        if (data_02732FC8.index < data_02732FC8.len) {
            buf[data_02732FC8.index++] = (data & 0xff0000) >> 16;
        }
        if (data_02732FC8.index < data_02732FC8.len) {
            data_02732FC8.buf[data_02732FC8.index++] = (data & 0xff00) >> 8;
        }
        if (data_02732FC8.index < data_02732FC8.len) {
            data_02732FC8.buf[data_02732FC8.index++] = data;
        }
    }
    if (data_02732FC8.index < data_02732FC8.total - 1) {
        return;
    }
    if (data_02732FC8.pend2 != 0 || (data_02732FC8.pend1 == 0 && data_02732FC8.pend0 == 0)) {
        u32 irq = OS_DisableInterrupts();
        reg_04004004 = reg_04004004 & ~0x100;
        OS_RestoreInterrupts(irq);
    }
    result = 0;
    data_02732FC8.pend1 = result;
    data_02732FC8.pend2 = result;
    switch (data_02732FC8.type) {
    case 0:
        switch (data_02732FC8.command) {
        case 0x10:
            data_02733FC8.f19c = data_02733FC8.value;
            break;
        case 0x12:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f15c = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f198 = data_02733FC8.value;
            break;
        case 0x30:
            if (data_02733FC8.flagsA & 1) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f128 = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f12c = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f164 = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f168 = data_02733FC8.value;
            break;
        case 0x31:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f148 = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f184 = data_02733FC8.value;
            break;
        case 0x32:
            if (data_02733FC8.flagsA & 1) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f130 = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f134 = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f16c = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f170 = data_02733FC8.value;
            break;
        case 0x33:
            if (data_02733FC8.flagsA & 1) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f138 = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f13c = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f174 = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f178 = data_02733FC8.value;
            break;
        case 0x34:
            if (data_02733FC8.flagsA & 1) {
                data_02733FC8.f140 = data_02733FC8.value;
                switch (data_02733FC8.value) {
                case 0:
                    data_02733FC8.f150 = 0;
                    data_02733FC8.f14c = 0;
                    data_02733FC8.f144 = 0;
                    break;
                case 1:
                    data_02733FC8.f150 = -2;
                    data_02733FC8.f14c = 0;
                    data_02733FC8.f144 = 0;
                    break;
                case 2:
                    data_02733FC8.f150 = 1;
                    data_02733FC8.f14c = 0;
                    data_02733FC8.f144 = 3;
                    break;
                case 3:
                    data_02733FC8.f150 = -1;
                    data_02733FC8.f14c = 2;
                    data_02733FC8.f144 = 0;
                    break;
                case 4:
                    data_02733FC8.f150 = 2;
                    data_02733FC8.f14c = 2;
                    data_02733FC8.f144 = 0;
                    break;
                }
            }
            if (data_02733FC8.flagsA & 2) {
                data_02733FC8.f17c = data_02733FC8.value;
                switch (data_02733FC8.value) {
                case 0:
                    data_02733FC8.f18c = 0;
                    data_02733FC8.f188 = 0;
                    data_02733FC8.f180 = 0;
                    break;
                case 1:
                    data_02733FC8.f18c = -2;
                    data_02733FC8.f188 = 0;
                    data_02733FC8.f180 = 0;
                    break;
                case 2:
                    data_02733FC8.f18c = 1;
                    data_02733FC8.f188 = 0;
                    data_02733FC8.f180 = 3;
                    break;
                case 3:
                    data_02733FC8.f18c = -1;
                    data_02733FC8.f188 = 2;
                    data_02733FC8.f180 = 0;
                    break;
                case 4:
                    data_02733FC8.f18c = 2;
                    data_02733FC8.f188 = 2;
                    data_02733FC8.f180 = 0;
                    break;
                }
            }
            break;
        case 0x35:
            if (data_02733FC8.flagsA & 1) {
                data_02733FC8.f144 = data_02733FC8.value;
                data_02733FC8.f158 = 1;
            }
            if (data_02733FC8.flagsA & 2) {
                data_02733FC8.f180 = data_02733FC8.value;
                data_02733FC8.f194 = 1;
            }
            break;
        case 0x36:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f14c = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f188 = data_02733FC8.value;
            break;
        case 0x37:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f150 = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f18c = data_02733FC8.value;
            break;
        case 0x39:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f154 = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f190 = data_02733FC8.value;
            break;
        case 0x3a:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f158 = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f194 = data_02733FC8.value;
            break;
        case 0x40:
            data_02733FC8.f19c = data_02733FC8.value;
            break;
        }
        break;
    case 1:
        result = 1;
        break;
    case 4:
        result = 6;
        break;
    case 2:
    case 3:
    case 5:
    default:
        result = 7;
        break;
    }
    CameraCallCallbackAndUnlock(result);
    if (result == 6) {
        CAMERA_GoReboot();
    }
}


void CameraSyncCallback(u32 a0, u32 a1) {
    data_02732FC8.f08 = a0;
}


void CameraCallCallbackAndUnlock(u32 result) {
    CamPxiCallback cb;
    if (data_02732FC8.busy != 0) {
        data_02732FC8.busy = 0;
    }
    cb = data_02732FC8.callback;
    if (cb == 0) {
        return;
    }
    data_02732FC8.callback = 0;
    cb(result, data_02732FC8.arg);
}


void CameraWaitBusy(void) {
    if (data_02732FC8.busy == 0) {
        return;
    }
    do {
        u32 mode = OS_GetCpsrIrq();
        if (mode == 0x80 || data_04000208 == 0) {
            PXIi_HandlerRecvFifoNotEmpty();
        }
    } while (data_02732FC8.busy != 0);
}


static void CameraStandbyCallback(void) {
    CAMERA_I2CActivateCore(0);
}
