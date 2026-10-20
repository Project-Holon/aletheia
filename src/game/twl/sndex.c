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
 *   OS_SendMessage  0x02085DBC  arm  arm9
 *   OS_ReceiveMessage  0x02085E50  arm  arm9
 *   PXI_SetFifoRecvCallback  0x020885A0  arm  arm9
 *   OSi_ThreadInfo  0x02150FEC  data
 *   SNDEXi_Work  0x02734450  data
 *   SNDEXi_PostExitInfo  0x0273446C  data
 *   SNDEXi_PreSleepInfo  0x0273448C  data
 */
#include "../types.h"
#include "sndex.h"


typedef struct {
    u8 chan;
    u8 pad1[3];
    u32 busy;
    s32 retries;
    volatile u32 state;
    u32 count;
    u32 active;
    u32 waiting;
    void (*postExitCallback)(void);
    u32 postExitArg;
    u32 pad24;
    u32 pad28;
    Cb eventCallback;
    void *eventArg;
    u32 pad34;
    u32 pad38;
    void (*preSleepCallback)(void);
    u32 preSleepArg;
    u32 pad44;
    u32 pad48;
    Cb callback;
    void *callbackArg;
    void *resultPtr;
    u8 command;
} State;

extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern void PXI_Init(void);
extern s32 PXI_IsCallbackReady(s32 fifotag, s32 proc);
extern void SVC_WaitByLoop(u32);
extern void PXI_SetFifoRecvCallback(s32 fifotag, void (*)(u32, u32, u32));
struct PMiGenCallbackInfo;

extern void PMi_InsertPostExitCallbackEx(struct PMiGenCallbackInfo *info, s32 priority);
extern void PMi_InsertPreSleepCallbackEx(struct PMiGenCallbackInfo *info, s32 priority);
extern s32 OS_IsRunOnTwl(void);
extern s32 OSi_IsCodecTwlMode(void);
extern void OS_SpinWaitSysCycles(u32);
#include "../sdk_os.h"

extern void OS_InitMessageQueue(struct OSMessageQueue *mq, void **msgArray, s32 msgCount);
extern s32 OS_ReceiveMessage(struct OSMessageQueue *mq, void **msg, s32 flags);
extern s32 OS_SendMessage(struct OSMessageQueue *mq, void *msg, s32 flags);
extern int PXI_SendWordByFifo(s32 fifotag, u32 data, s32 err);
extern void PXIi_HandlerRecvFifoNotEmpty(void);
extern State SNDEXi_Work;
extern u32 SNDEXi_PostExitInfo[];
extern u32 SNDEXi_PreSleepInfo[];
extern OSThreadInfo OSi_ThreadInfo;

void SNDEXi_Init(void);
u32 SNDEXi_SetVolumeAsync(u32 volume, Cb callback, void *userData, u32 mode);
u32 SNDEXi_SetVolumeExAsync(u32 volume, Cb callback, void *userData);
u32 SNDEXi_SetIirFilterAsync(u32 target, u16 *coefficients, Cb callback, void *userData);
u32 SNDEXi_SetIirFilter(u32 target, u16 *coefficients);
u32 SNDEXi_PreProcessForShutterSound(void);
u32 SNDEXi_PostProcessForShutterSound(Cb callback, void *userData);
void CommonCallback(u32 tag, u32 data, u32 err);
void SyncCallback(u32 result, void *queue);
u32 SendCommand(u32 command, u8 data);
u32 SendCommandEx(u32 command, u32 data);
u32 CheckState(void);
void ReplyCallback(u32 result);
void SetSndexWork(Cb callback, void *callbackArg, void *resultPtr, u32 command);
void SndexSleepAndExitCallback(void);
void WaitIirFilterSetting(void);
void WaitResetSoundCallback(u32 result, void *userData);
void ResetTempVolume(void);

void SNDEXi_Init(void) {
    u32 irq = OS_DisableInterrupts();
    if (SNDEXi_Work.state != 0) {
        OS_RestoreInterrupts(irq);
        return;
    }
    SNDEXi_Work.state = 1;
    OS_RestoreInterrupts(irq);
    SetSndexWork(0, 0, 0, 0);
    PXI_Init();
    while (PXI_IsCallbackReady(0x18, 1) == 0) {
        SVC_WaitByLoop(10);
    }
    PXI_SetFifoRecvCallback(0x18, (void (*)(u32, u32, u32))CommonCallback);
    SNDEXi_Work.postExitCallback = SndexSleepAndExitCallback;
    SNDEXi_Work.postExitArg = 0;
    PMi_InsertPostExitCallbackEx((struct PMiGenCallbackInfo *)SNDEXi_PostExitInfo, 0xfffd);
    SNDEXi_Work.preSleepCallback = SndexSleepAndExitCallback;
    SNDEXi_Work.preSleepArg = 0;
    PMi_InsertPreSleepCallbackEx((struct PMiGenCallbackInfo *)SNDEXi_PreSleepInfo, 0xfffd);
    SNDEXi_Work.state = 2;
}

u32 SNDEXi_SetVolumeAsync(u32 volume, Cb callback, void *userData, u32 mode) {
    u32 r;
    int limit = mode ? 7 : 0x1f;
    if ((int)volume > limit) {
        return 2;
    }
    r = CheckState();
    if (r != 0) {
        return r;
    }
    SetSndexWork(callback, userData, 0, 0x84);
    if (SendCommand(SNDEXi_Work.command, (volume & 0x1f) | (mode << 6)) == 0) {
        return 5;
    }
    return 0;
}

u32 SNDEXi_SetVolumeExAsync(u32 volume, Cb callback, void *userData) {
    if (OS_IsRunOnTwl() == 0) {
        return 4;
    }
    return SNDEXi_SetVolumeAsync(volume, callback, userData, 0);
}

#define WAIT_IDLE() \
    do { \
        OS_SpinWaitSysCycles(0x82dc); \
        while (CheckState() != 0) { \
            OS_SpinWaitSysCycles(0x82dc); \
        } \
    } while (0)

u32 SNDEXi_SetIirFilterAsync(u32 target, u16 *coefficients, Cb callback, void *userData) {
    u32 r;
    if (SNDEXi_Work.busy != 0) {
        return 3;
    }
    SNDEXi_Work.busy = 1;
    if (OSi_IsCodecTwlMode() == 0) {
        SNDEXi_Work.busy = 0;
        return 4;
    }
    r = CheckState();
    if (r != 0) {
        SNDEXi_Work.busy = 0;
        return r;
    }
    SetSndexWork(0, 0, 0, 0xc1);
    if (SendCommandEx(SNDEXi_Work.command, (u16)target) == 0) {
        SNDEXi_Work.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(0, 0, 0, 0xc2);
    if (SendCommandEx(SNDEXi_Work.command, coefficients[0]) == 0) {
        SNDEXi_Work.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(0, 0, 0, 0xc3);
    if (SendCommandEx(SNDEXi_Work.command, coefficients[1]) == 0) {
        SNDEXi_Work.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(0, 0, 0, 0xc4);
    if (SendCommandEx(SNDEXi_Work.command, coefficients[2]) == 0) {
        SNDEXi_Work.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(0, 0, 0, 0xc5);
    if (SendCommandEx(SNDEXi_Work.command, coefficients[3]) == 0) {
        SNDEXi_Work.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(0, 0, 0, 0xc6);
    if (SendCommandEx(SNDEXi_Work.command, coefficients[4]) == 0) {
        SNDEXi_Work.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(callback, userData, 0, 0xc7);
    if (SendCommandEx(SNDEXi_Work.command, 0) == 0) {
        SNDEXi_Work.busy = 0;
        return 5;
    }
    return 0;
}

u32 SNDEXi_SetIirFilter(u32 target, u16 *coefficients) {
    u32 result;
    u32 buf[1];
    u32 q[8];
    if (OSi_ThreadInfo.current == 0) {
        return 4;
    }
    OS_InitMessageQueue((struct OSMessageQueue *)q, (void **)buf, 1);
    result = SNDEXi_SetIirFilterAsync(target, coefficients, SyncCallback, q);
    if (result == 0) {
        OS_ReceiveMessage((struct OSMessageQueue *)q, (void **)(&result), 1);
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
    if (OSi_ThreadInfo.current == 0) {
        return 4;
    }
    if (SNDEXi_Work.state != 4) {
        result = CheckState();
        if (result != 0) {
            return result;
        }
    } else if (SNDEXi_Work.state == 5) {
        return 3;
    }
    OS_InitMessageQueue((struct OSMessageQueue *)q, (void **)buf, 1);
    SetSndexWork(SyncCallback, q, 0, 0xfb);
    if (SendCommand(SNDEXi_Work.command, 0) == 0) {
        return 5;
    }
    OS_ReceiveMessage((struct OSMessageQueue *)q, (void **)(&result), 1);
    return result;
}

u32 SNDEXi_PostProcessForShutterSound(Cb callback, void *userData) {
    u32 r;
    if (OSi_IsCodecTwlMode() == 0 || SNDEXi_Work.state != 4) {
        return 4;
    }
    r = 5;
    SNDEXi_Work.state = 5;
    SetSndexWork(callback, userData, 0, 0xfc);
    if (SendCommand(SNDEXi_Work.command, 0) != 0) {
        r = 0;
    }
    return r;
}

void CommonCallback(u32 tag, u32 data, u32 err) {
    u8 b2 = (data & 0xff0000) >> 16;
    u8 b1 = (data & 0xff00) >> 8;
    u8 b0 = data & 0xff;
    if (b2 == 0xfd) {
        if (CheckState() != 0) {
            return;
        }
        SetSndexWork(0, 0, 0, 0xfd);
    }
    if (tag != 0x18 || err == 1
        || (SNDEXi_Work.state != 3 && SNDEXi_Work.state != 4 && SNDEXi_Work.state != 5)
        || SNDEXi_Work.command != b2) {
        ReplyCallback(7);
        return;
    }
    switch (b1) {
    case 0:
        switch (b2) {
        case 1:
            if (SNDEXi_Work.resultPtr != 0) {
                *(u32 *)SNDEXi_Work.resultPtr = b0;
            }
            break;
        case 2:
            if (SNDEXi_Work.resultPtr != 0) {
                *(u32 *)SNDEXi_Work.resultPtr = b0;
            }
            break;
        case 3:
        case 4:
            if (SNDEXi_Work.resultPtr != 0) {
                *(u8 *)SNDEXi_Work.resultPtr = b0;
            }
            break;
        case 5:
            if (SNDEXi_Work.resultPtr != 0) {
                *(u32 *)SNDEXi_Work.resultPtr = b0;
            }
            break;
        case 0xfd:
            if (SNDEXi_Work.eventCallback != 0) {
                SNDEXi_Work.eventCallback(b1, SNDEXi_Work.eventArg);
            }
            break;
        case 0xfe:
            if (SNDEXi_Work.resultPtr != 0) {
                *(u32 *)SNDEXi_Work.resultPtr = b0;
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
        if (b2 == 4 && SNDEXi_Work.resultPtr != 0) {
            *(u8 *)SNDEXi_Work.resultPtr = 0;
        }
        ReplyCallback(6);
        break;
    default:
        ReplyCallback(7);
        break;
    }
}

void SyncCallback(u32 result, void *queue) {
    OS_SendMessage(queue, (void *)result, 0);
}

u32 SendCommand(u32 command, u8 data) {
    u32 irq = OS_DisableInterrupts();
    int r = PXI_SendWordByFifo(0x18, ((command << 16) & 0xff0000) | (data & 0xff), 0);
    if (r < 0) {
        SNDEXi_Work.state = 2;
        OS_RestoreInterrupts(irq);
        return 0;
    }
    OS_RestoreInterrupts(irq);
    return 1;
}

u32 SendCommandEx(u32 command, u32 data) {
    u32 irq = OS_DisableInterrupts();
    int r = PXI_SendWordByFifo(0x18, ((command << 16) & 0xff0000) | (u16)data, 0);
    if (r < 0) {
        SNDEXi_Work.state = 2;
        OS_RestoreInterrupts(irq);
        return 0;
    }
    if (command == 0xc7) {
        SNDEXi_Work.waiting = 1;
    }
    OS_RestoreInterrupts(irq);
    return 1;
}

u32 CheckState(void) {
    u32 irq = OS_DisableInterrupts();
    switch (SNDEXi_Work.state) {
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
        SNDEXi_Work.state = 3;
        OS_RestoreInterrupts(irq);
        return 0;
    }
}

void ReplyCallback(u32 result) {
    u32 irq = OS_DisableInterrupts();
    u8 cmd = SNDEXi_Work.command;
    Cb cb = SNDEXi_Work.callback;
    void *arg = SNDEXi_Work.callbackArg;
    if (cmd == 0xc7) {
        SNDEXi_Work.waiting = 0;
        SNDEXi_Work.busy = 0;
    }
    SetSndexWork(0, 0, 0, 0);
    if (cmd == 0xfb) {
        SNDEXi_Work.state = 4;
    } else {
        SNDEXi_Work.state = 2;
    }
    OS_RestoreInterrupts(irq);
    if (cb != 0) {
        cb(result, arg);
    }
}

void SetSndexWork(Cb callback, void *callbackArg, void *resultPtr, u32 command) {
    SNDEXi_Work.callback = callback;
    SNDEXi_Work.callbackArg = callbackArg;
    SNDEXi_Work.resultPtr = resultPtr;
    SNDEXi_Work.command = command;
}

void SndexSleepAndExitCallback(void) {
    WaitIirFilterSetting();
    ResetTempVolume();
}

void WaitIirFilterSetting(void) {
    while (SNDEXi_Work.waiting != 0) {
        OS_SpinWaitSysCycles(0x82dc);
        PXIi_HandlerRecvFifoNotEmpty();
    }
}

void WaitResetSoundCallback(u32 result, void *userData) {
    if (result != 0 && SNDEXi_Work.count < 5) {
        SNDEXi_SetVolumeExAsync(SNDEXi_Work.chan, WaitResetSoundCallback, 0);
        SNDEXi_Work.count++;
        return;
    }
    SNDEXi_Work.active = 0;
}

void ResetTempVolume(void) {
    if (SNDEXi_Work.active != 0) {
        while (SNDEXi_SetVolumeExAsync(SNDEXi_Work.chan, WaitResetSoundCallback, 0) != 0 && SNDEXi_Work.retries < 5) {
            SNDEXi_Work.retries++;
        }
        while (SNDEXi_Work.active != 0) {
            OS_SpinWaitSysCycles(0x82dc);
            PXIi_HandlerRecvFifoNotEmpty();
        }
    }
}
