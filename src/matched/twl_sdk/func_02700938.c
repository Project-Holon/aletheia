/*
 * function: CAMERA_InitCore
 * address:  0x02700938
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
 *   data_02732FC8  0x02732FC8  data twl a2
 *   data_02733FC8  0x02733FC8  data twl a2
 *   data_02701AA0  0x02701AA0  arm twl a2
 *   data_02702070  0x02702070  arm twl a2
 *   data_02732FF8  0x02732FF8  data twl a2
 *   data_02733008  0x02733008  data twl a2
 *   data_02700078  0x02700078  arm twl a2
 *   data_0273417C  0x0273417C  data twl a2
 *   data_0273419C  0x0273419C  data twl a2
 *   data_0273302C  0x0273302C  data twl a2
 *   data_02700824  0x02700824  arm twl a2
 *   data_027340EC  0x027340EC  data twl a2
 *   PXI_Init  0x02088498  arm twl a2
 *   PXI_IsCallbackReady  0x020885EC  arm twl a2
 *   func_020885A0  0x020885A0  arm twl a2
 *   CAMERA_ResetCore  0x02702080  arm twl a2
 *   CAMERA_StopCaptureCore  0x0270212C  arm twl a2
 *   CAMERA_ClearBufferCore  0x027021E4  arm twl a2
 *   PMi_InsertPreSleepCallbackEx  0x0208C848  arm twl a2
 *   PMi_InsertPostExitCallbackEx  0x0273156C  arm twl a2
 *   CAMERA_SetVsyncInterruptCore  0x0270223C  arm twl a2
 *   CAMERA_SetBufferErrorInterruptCore  0x02702268  arm twl a2
 *   CAMERA_SetMasterInterruptCore  0x02702208  arm twl a2
 *   func_02084774  0x02084774  arm twl a2
 *   OS_EnableIrqMask  0x02084968  arm twl a2
 *   OS_InitMessageQueue  0x02085D94  arm twl a2
 *   OS_CreateThread  0x020853C0  arm twl a2
 *   OS_WakeupThreadDirect  0x02085868  arm twl a2
 *   CameraPxiCallback  0x02701AA0  arm twl a2
 *   CameraStandbyCallback  0x02702070  arm twl a2
 *   CAMERA_CameraIntr  0x02700078  arm twl a2
 *   CAMERA_MonitorThread  0x02700824  arm twl a2
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef signed int s32;
typedef unsigned long long u64;
typedef void (*TwlCb)(u32);
typedef void (*CamPxiCallback)(u32 result, u32 arg);
typedef void (*TwlFn)(void);

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
    u8 thread[0x124 - 0x64];      /* 0x0064: the thread (data_0273302C) */
    u8 stack[0x1124 - 0x124];     /* 0x0124: its stack, top at data_027340EC */
    u8 settings[0x11B4 - 0x1124]; /* 0x1124: TwlSysB f124..f1B0 (data_02733FC8 is this object + 0x1000) */
    u8 queue[0x11D4 - 0x11B4];    /* 0x11B4: message queue (data_0273417C) */
    u32 msg[1];                   /* 0x11D4: its one-message buffer (data_0273419C); data_027341A0 follows */
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
extern u32 data_02732FC0[];
extern u32 data_02732FF8[];
extern u32 data_02733008[];
extern u32 data_0273417C[];
extern u32 data_0273419C[];
extern u32 data_0273302C[];
extern u32 data_027340EC[];

extern void PXI_Init(void);
extern u32 PXI_IsCallbackReady(u32, u32);
extern void func_020885A0(u32, void (*)(int, u32, int));
extern void CameraPxiCallback(int, u32, int);
extern void CAMERA_ResetCore(void);
extern void CAMERA_StopCaptureCore(void);
extern void CAMERA_ClearBufferCore(void);
extern void CameraStandbyCallback(void);
extern void PMi_InsertPreSleepCallbackEx(u32*, u32);
extern void PMi_InsertPostExitCallbackEx(u32*, u32);
extern void CAMERA_SetVsyncInterruptCore(u32);
extern void CAMERA_SetBufferErrorInterruptCore(u32);
extern void CAMERA_SetMasterInterruptCore(u32);
extern void func_02084774(u32, TwlFn);
extern void OS_EnableIrqMask(u32);
extern void OS_InitMessageQueue(u32*, u32*, u32);
extern void OS_CreateThread(u32*, void (*)(void), u32, u32*, u32, u32);
extern void OS_WakeupThreadDirect(u32*);
extern void CAMERA_CameraIntr(void);
extern void CAMERA_MonitorThread(void);

u32 CAMERA_InitCore(void) {
    if (data_02732FC0[0] != 0) {
        return 2;
    }
    data_02732FC0[0] = 1;
    data_02732FC8.cbA = 0;
    data_02732FC8.cbB = 0;
    data_02732FC8.cbC = 0;
    data_02732FC8.f00 = 0;
    data_02732FC8.f04 = 0;
    data_02732FC8.f28 = 0;
    data_02732FC8.f2C = 0;
    data_02733FC8.f124 = 0;
    data_02733FC8.f1AC = 0;
    data_02733FC8.f1B0 = 0;
    PXI_Init();
    if (PXI_IsCallbackReady(0x15, 1) == 0) {
        return 7;
    }
    func_020885A0(0x15, CameraPxiCallback);
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
    func_02084774(0x02000000, CAMERA_CameraIntr);
    OS_EnableIrqMask(0x02000000);
    data_02733FC8.f128 = 5;
    data_02733FC8.f12C = 0;
    data_02733FC8.f130 = 0;
    data_02733FC8.f134 = 0;
    data_02733FC8.f138 = 2;
    data_02733FC8.f13C = 2;
    data_02733FC8.f140 = 1;
    data_02733FC8.f144 = 0;
    data_02733FC8.f148 = 0;
    data_02733FC8.f14C = 0;
    data_02733FC8.f150 = -2;
    data_02733FC8.f154 = 1;
    data_02733FC8.f158 = 1;
    data_02733FC8.f15C = 1;
    data_02733FC8.f160 = 0;
    data_02733FC8.f164 = 5;
    data_02733FC8.f168 = 0;
    data_02733FC8.f16C = 0;
    data_02733FC8.f170 = 0;
    data_02733FC8.f174 = 0;
    data_02733FC8.f178 = 0;
    data_02733FC8.f17C = 0;
    data_02733FC8.f180 = 0;
    data_02733FC8.f184 = 0;
    data_02733FC8.f188 = 0;
    data_02733FC8.f18C = 0;
    data_02733FC8.f190 = 1;
    data_02733FC8.f194 = 1;
    data_02733FC8.f198 = 1;
    data_02733FC8.f19C = 0;
    OS_InitMessageQueue(data_0273417C, data_0273419C, 1);
    OS_CreateThread(data_0273302C, CAMERA_MonitorThread, 0, data_027340EC, 0x1000, 4);
    OS_WakeupThreadDirect(data_0273302C);
    return 0;
}
