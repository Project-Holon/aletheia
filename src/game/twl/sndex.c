/*
 * file:     sndex.c
 * unit:     yes
 * function: SNDEXi_Init, SNDEXi_SetVolumeAsync, SNDEXi_SetVolumeExAsync, SNDEXi_SetIirFilterAsync, SNDEXi_SetIirFilter, SNDEXi_PreProcessForShutterSound, SNDEXi_PostProcessForShutterSound, CommonCallback, SyncCallback, SendCommand, SendCommandEx, CheckState, ReplyCallback, SetSndexWork, SndexSleepAndExitCallback, WaitIirFilterSetting, WaitResetSoundCallback, ResetTempVolume
 * address:  0x02704364
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * sdk:      libsndex.TWL.HYB.a sndex.o
 * status:   EXACT
 *
 * symbols:
 *   PMi_InsertPostExitCallbackEx  0x0273156C  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm  arm9
 *   PXI_Init  0x02088498  arm  arm9
 *   SVC_WaitByLoop  0x02004490  thumb  arm9
 *   OS_DisableInterrupts  0x02087988  arm  arm9
 *   OS_RestoreInterrupts  0x0208799C  arm  arm9
 *   OS_SpinWaitSysCycles  0x02087A04  arm  arm9
 *   PXI_IsCallbackReady  0x020885EC  arm  arm9
 *   PXI_SendWordByFifo  0x02088610  arm  arm9
 *   PXIi_HandlerRecvFifoNotEmpty  0x02088688  arm  arm9
 *   OS_InitMessageQueue  0x02085D94  arm  arm9
 *   OSi_IsCodecTwlMode  0x02087B20  arm  arm9
 *   PMi_InsertPreSleepCallbackEx  0x0208C848  arm  arm9
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed int s32;

typedef void (*Cb)(u32, void *);

typedef struct {
    u8 chan;
    u8 pad1[3];
    u32 busy;
    s32 retries;
    volatile u32 state;
    u32 count;
    u32 active;
    u32 waiting;
    void (*f1c)(void);
    u32 f20;
    u32 pad24;
    u32 pad28;
    Cb f2c;
    void *f30;
    u32 pad34;
    u32 pad38;
    void (*f3c)(void);
    u32 f40;
    u32 pad44;
    u32 pad48;
    Cb f4c;
    void *f50;
    void *f54;
    u8 f58;
} State;

extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern void PXI_Init(void);
extern u32 PXI_IsCallbackReady(u32, u32);
extern void SVC_WaitByLoop(u32);
extern void func_020885A0(u32, void (*)(u32, u32, u32));

extern void PMi_InsertPostExitCallbackEx(u32 *, u32);
extern void PMi_InsertPreSleepCallbackEx(u32 *, u32);
extern u32 OS_IsRunOnTwl(void);
extern u32 OSi_IsCodecTwlMode(void);
extern void OS_SpinWaitSysCycles(u32);
extern void OS_InitMessageQueue(void *, void *, u32);
extern void func_02085E50(void *, void *, u32);
extern void func_02085DBC(void *, u32, u32);
extern int PXI_SendWordByFifo(u32, u32, u32);
extern void PXIi_HandlerRecvFifoNotEmpty(void);
extern State DAT_02734450;
extern u32 DAT_0273446c[];
extern u32 DAT_0273448c[];
extern u32 DAT_02150fec[];

void SNDEXi_Init(void);
u32 SNDEXi_SetVolumeAsync(u32 a0, Cb a1, void *a2, u32 a3);
u32 SNDEXi_SetVolumeExAsync(u32 a0, Cb a1, void *a2);
u32 SNDEXi_SetIirFilterAsync(u32 a0, u16 *a1, Cb a2, void *a3);
u32 SNDEXi_SetIirFilter(u32 a0, u16 *a1);
u32 SNDEXi_PreProcessForShutterSound(void);
u32 SNDEXi_PostProcessForShutterSound(Cb a0, void *a1);
void CommonCallback(u32 a0, u32 a1, u32 a2);
void SyncCallback(u32 a0, void *a1);
u32 SendCommand(u32 a0, u8 a1);
u32 SendCommandEx(u32 a0, u32 a1);
u32 CheckState(void);
void ReplyCallback(u32 a0);
void SetSndexWork(Cb a0, void *a1, void *a2, u32 a3);
void SndexSleepAndExitCallback(void);
void WaitIirFilterSetting(void);
void WaitResetSoundCallback(u32 a0, void *a1);
void ResetTempVolume(void);

void SNDEXi_Init(void) {
    u32 irq = OS_DisableInterrupts();
    if (DAT_02734450.state != 0) {
        OS_RestoreInterrupts(irq);
        return;
    }
    DAT_02734450.state = 1;
    OS_RestoreInterrupts(irq);
    SetSndexWork(0, 0, 0, 0);
    PXI_Init();
    while (PXI_IsCallbackReady(0x18, 1) == 0) {
        SVC_WaitByLoop(10);
    }
    func_020885A0(0x18, (void (*)(u32, u32, u32))CommonCallback);
    DAT_02734450.f1c = SndexSleepAndExitCallback;
    DAT_02734450.f20 = 0;
    PMi_InsertPostExitCallbackEx(DAT_0273446c, 0xfffd);
    DAT_02734450.f3c = SndexSleepAndExitCallback;
    DAT_02734450.f40 = 0;
    PMi_InsertPreSleepCallbackEx(DAT_0273448c, 0xfffd);
    DAT_02734450.state = 2;
}

u32 SNDEXi_SetVolumeAsync(u32 a0, Cb a1, void *a2, u32 a3) {
    u32 r;
    int limit = a3 ? 7 : 0x1f;
    if ((int)a0 > limit) {
        return 2;
    }
    r = CheckState();
    if (r != 0) {
        return r;
    }
    SetSndexWork(a1, a2, 0, 0x84);
    if (SendCommand(DAT_02734450.f58, (a0 & 0x1f) | (a3 << 6)) == 0) {
        return 5;
    }
    return 0;
}

u32 SNDEXi_SetVolumeExAsync(u32 a0, Cb a1, void *a2) {
    if (OS_IsRunOnTwl() == 0) {
        return 4;
    }
    return SNDEXi_SetVolumeAsync(a0, a1, a2, 0);
}

#define WAIT_IDLE() \
    do { \
        OS_SpinWaitSysCycles(0x82dc); \
        while (CheckState() != 0) { \
            OS_SpinWaitSysCycles(0x82dc); \
        } \
    } while (0)

u32 SNDEXi_SetIirFilterAsync(u32 a0, u16 *a1, Cb a2, void *a3) {
    u32 r;
    if (DAT_02734450.busy != 0) {
        return 3;
    }
    DAT_02734450.busy = 1;
    if (OSi_IsCodecTwlMode() == 0) {
        DAT_02734450.busy = 0;
        return 4;
    }
    r = CheckState();
    if (r != 0) {
        DAT_02734450.busy = 0;
        return r;
    }
    SetSndexWork(0, 0, 0, 0xc1);
    if (SendCommandEx(DAT_02734450.f58, (u16)a0) == 0) {
        DAT_02734450.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(0, 0, 0, 0xc2);
    if (SendCommandEx(DAT_02734450.f58, a1[0]) == 0) {
        DAT_02734450.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(0, 0, 0, 0xc3);
    if (SendCommandEx(DAT_02734450.f58, a1[1]) == 0) {
        DAT_02734450.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(0, 0, 0, 0xc4);
    if (SendCommandEx(DAT_02734450.f58, a1[2]) == 0) {
        DAT_02734450.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(0, 0, 0, 0xc5);
    if (SendCommandEx(DAT_02734450.f58, a1[3]) == 0) {
        DAT_02734450.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(0, 0, 0, 0xc6);
    if (SendCommandEx(DAT_02734450.f58, a1[4]) == 0) {
        DAT_02734450.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(a2, a3, 0, 0xc7);
    if (SendCommandEx(DAT_02734450.f58, 0) == 0) {
        DAT_02734450.busy = 0;
        return 5;
    }
    return 0;
}

u32 SNDEXi_SetIirFilter(u32 a0, u16 *a1) {
    u32 result;
    u32 buf[1];
    u32 q[8];
    if (DAT_02150fec[1] == 0) {
        return 4;
    }
    OS_InitMessageQueue(q, buf, 1);
    result = SNDEXi_SetIirFilterAsync(a0, a1, SyncCallback, q);
    if (result == 0) {
        func_02085E50(q, &result, 1);
    }
    {
        State *s = (State *)0x02734450;
        s->waiting = 0;
        s->busy = 0;
    }
    return result;
}

u32 SNDEXi_PreProcessForShutterSound(void) {
    u32 result;
    u32 buf[1];
    u32 q[8];
    if (OSi_IsCodecTwlMode() == 0) {
        return 4;
    }
    if (DAT_02150fec[1] == 0) {
        return 4;
    }
    if (DAT_02734450.state != 4) {
        result = CheckState();
        if (result != 0) {
            return result;
        }
    } else if (DAT_02734450.state == 5) {
        return 3;
    }
    OS_InitMessageQueue(q, buf, 1);
    SetSndexWork(SyncCallback, q, 0, 0xfb);
    if (SendCommand(DAT_02734450.f58, 0) == 0) {
        return 5;
    }
    func_02085E50(q, &result, 1);
    return result;
}

u32 SNDEXi_PostProcessForShutterSound(Cb a0, void *a1) {
    u32 r;
    if (OSi_IsCodecTwlMode() == 0 || DAT_02734450.state != 4) {
        return 4;
    }
    r = 5;
    DAT_02734450.state = 5;
    SetSndexWork(a0, a1, 0, 0xfc);
    if (SendCommand(DAT_02734450.f58, 0) != 0) {
        r = 0;
    }
    return r;
}

void CommonCallback(u32 a0, u32 a1, u32 a2) {
    u8 b2 = (a1 & 0xff0000) >> 16;
    u8 b1 = (a1 & 0xff00) >> 8;
    u8 b0 = a1 & 0xff;
    if (b2 == 0xfd) {
        if (CheckState() != 0) {
            return;
        }
        SetSndexWork(0, 0, 0, 0xfd);
    }
    if (a0 != 0x18 || a2 == 1
        || (DAT_02734450.state != 3 && DAT_02734450.state != 4 && DAT_02734450.state != 5)
        || DAT_02734450.f58 != b2) {
        ReplyCallback(7);
        return;
    }
    switch (b1) {
    case 0:
        switch (b2) {
        case 1:
            if (DAT_02734450.f54 != 0) {
                *(u32 *)DAT_02734450.f54 = b0;
            }
            break;
        case 2:
            if (DAT_02734450.f54 != 0) {
                *(u32 *)DAT_02734450.f54 = b0;
            }
            break;
        case 3:
        case 4:
            if (DAT_02734450.f54 != 0) {
                *(u8 *)DAT_02734450.f54 = b0;
            }
            break;
        case 5:
            if (DAT_02734450.f54 != 0) {
                *(u32 *)DAT_02734450.f54 = b0;
            }
            break;
        case 0xfd:
            if (DAT_02734450.f2c != 0) {
                DAT_02734450.f2c(b1, DAT_02734450.f30);
            }
            break;
        case 0xfe:
            if (DAT_02734450.f54 != 0) {
                *(u32 *)DAT_02734450.f54 = b0;
            }
            break;
        }
        ReplyCallback(0);
        break;
    case 2:
        ReplyCallback(2);
        break;
    case 3:
        ReplyCallback(3);
        break;
    case 4:
        ReplyCallback(4);
        break;
    case 5:
        if (b2 == 4 && DAT_02734450.f54 != 0) {
            *(u8 *)DAT_02734450.f54 = 0;
        }
        ReplyCallback(6);
        break;
    default:
        ReplyCallback(7);
        break;
    }
}

void SyncCallback(u32 a0, void *a1) {
    func_02085DBC(a1, a0, 0);
}

u32 SendCommand(u32 a0, u8 a1) {
    u32 irq = OS_DisableInterrupts();
    int r = PXI_SendWordByFifo(0x18, ((a0 << 16) & 0xff0000) | (a1 & 0xff), 0);
    if (r < 0) {
        DAT_02734450.state = 2;
        OS_RestoreInterrupts(irq);
        return 0;
    }
    OS_RestoreInterrupts(irq);
    return 1;
}

u32 SendCommandEx(u32 a0, u32 a1) {
    u32 irq = OS_DisableInterrupts();
    int r = PXI_SendWordByFifo(0x18, ((a0 << 16) & 0xff0000) | (u16)a1, 0);
    if (r < 0) {
        DAT_02734450.state = 2;
        OS_RestoreInterrupts(irq);
        return 0;
    }
    if (a0 == 0xc7) {
        DAT_02734450.waiting = 1;
    }
    OS_RestoreInterrupts(irq);
    return 1;
}

u32 CheckState(void) {
    u32 irq = OS_DisableInterrupts();
    switch (DAT_02734450.state) {
    case 0:
    case 1:
        OS_RestoreInterrupts(irq);
        return 1;
    case 3:
    case 4:
    case 5:
        OS_RestoreInterrupts(irq);
        return 3;
    default:
        DAT_02734450.state = 3;
        OS_RestoreInterrupts(irq);
        return 0;
    }
}

void ReplyCallback(u32 a0) {
    u32 irq = OS_DisableInterrupts();
    u8 cmd = DAT_02734450.f58;
    Cb cb = DAT_02734450.f4c;
    void *arg = DAT_02734450.f50;
    if (cmd == 0xc7) {
        DAT_02734450.waiting = 0;
        DAT_02734450.busy = 0;
    }
    SetSndexWork(0, 0, 0, 0);
    if (cmd == 0xfb) {
        DAT_02734450.state = 4;
    } else {
        DAT_02734450.state = 2;
    }
    OS_RestoreInterrupts(irq);
    if (cb != 0) {
        cb(a0, arg);
    }
}

void SetSndexWork(Cb a0, void *a1, void *a2, u32 a3) {
    DAT_02734450.f4c = a0;
    DAT_02734450.f50 = a1;
    DAT_02734450.f54 = a2;
    DAT_02734450.f58 = a3;
}

void SndexSleepAndExitCallback(void) {
    WaitIirFilterSetting();
    ResetTempVolume();
}

void WaitIirFilterSetting(void) {
    while (DAT_02734450.waiting != 0) {
        OS_SpinWaitSysCycles(0x82dc);
        PXIi_HandlerRecvFifoNotEmpty();
    }
}

void WaitResetSoundCallback(u32 a0, void *a1) {
    if (a0 != 0 && DAT_02734450.count < 5) {
        SNDEXi_SetVolumeExAsync(DAT_02734450.chan, WaitResetSoundCallback, 0);
        DAT_02734450.count++;
        return;
    }
    DAT_02734450.active = 0;
}

void ResetTempVolume(void) {
    if (DAT_02734450.active != 0) {
        while (SNDEXi_SetVolumeExAsync(DAT_02734450.chan, WaitResetSoundCallback, 0) != 0 && DAT_02734450.retries < 5) {
            DAT_02734450.retries++;
        }
        while (DAT_02734450.active != 0) {
            OS_SpinWaitSysCycles(0x82dc);
            PXIi_HandlerRecvFifoNotEmpty();
        }
    }
}
