/*
 * file:     pm.c
 * unit:     yes
 * function: PMi_WaitBusy, PMi_DummyCallback, PMi_CallCallbackAndUnlock, PMi_WaitVBlank, PM_Init, PMi_CommonCallback, PMi_TryToSendPxiData, PMi_TryToSendPxiDataTillSuccess, PMi_SendSleepStart, PM_SendUtilityCommandAsync, PM_SendUtilityCommand, PMi_SetLEDAsync, PMi_SetLED, PM_SetBackLightAsync, PM_SetBackLight, PM_ForceToPowerOffAsync, PMi_ForceToPowerOff, PM_ForceToPowerOff, PM_SetAmp, PMi_SetAmp, PM_SetAmpGain, PM_SetAmpGainLevel, PM_GetBattery, PM_GetBatteryLevel, PM_GetBackLight, PM_GetAmp, PMi_SendPxiData, PMi_PreSleepForDma, PM_GoSleepMode, PMi_SetLCDPower, PM_SetLCDPower, PM_GetLCDPower, PMi_SendLEDPatternCommand, PM_GetLEDPattern, PMi_InsertList, PMi_DeleteList, PMi_ExecuteList, PM_PrependPreSleepCallback, PM_AppendPostSleepCallback, PMi_InsertPreSleepCallbackEx, PM_DeletePreSleepCallback, PM_DeletePostSleepCallback, PMi_LCDOnAvoidReset, PMi_SetDispOffCount
 * address:  0x0208B7BC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02153000                     0x02153000  data
 *   g_020A8724                     0x020A8724  data
 *   OS_GetProcMode                 0x020879EC  arm
 *   OS_GetCpsrIrq                  0x020879E0  arm
 *   PXIi_HandlerRecvFifoNotEmpty   0x02088688  arm
 *   s_02153000               0x02153000  data
 *   PXI_Init            0x02088498  arm
 *   PXI_IsCallbackReady      0x020885EC  arm
 *   PXI_SetFifoRecvCallback  0x020885A0  arm
 *   SVC_WaitByLoop           0x02004490  thumb
 *   PMi_CommonCallback       0x0208B950  arm
 *   PMi_ProceedToExit              0x027314A4  arm
 *   PMi_BatteryLowCallbackInfo     0x02732FB0  data
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   OS_SpinWaitSysCycles           0x02087A04  arm
 *   PMi_DummyCallback              0x0208B840  arm
 *   g_02732FAC                     0x02732FAC  data
 *   OS_IsRunOnTwl                  0x02085D3C  arm
 *   PMi_ExecuteList                0x0208C7E0  arm
 *   MI_StopAllDma                  0x02082658  arm
 *   MI_StopAllNDma                 0x0272FD18  arm
 *   OS_Halt                        0x020882D0  arm
 *   PMi_SetAmp   0x0208BF08  arm
 *   PM_GetLCDPower         0x0208C688  arm
 *   PMi_GetACAdapterCore   0x027313AC  arm
 *   PXI_SendWordByFifo             0x02088610  arm
 *   MI_WaitDma                     0x02082594  arm
 *   MI_StopDma                     0x020825F0  arm
 *   PMi_PreSleepForNdma            0x027313E8  arm
 *   OS_DisableIrqMask      0x02084998  arm
 *   OS_IsTickAvailable     0x02087058  arm
 *   OS_SetIrqMask          0x0208493C  arm
 *   OS_GetBootType         0x02087B04  arm
 *   CTRDG_IsExisting       0x02090F50  arm
 *   GX_IsDispOn                    0x0207D41C  arm
 *   GX_DispOff                     0x0207D42C  arm
 *   g_0215301C     0x0215301C  data  a4
 *   PMi_InsertList 0x0208C6FC  arm
 *   g_02153004     0x02153004  data  a4
 *   PMi_PostSleepCallbackList      0x0215301C  data
 *   g_02153020                     0x02153020  data
 */
#define reg_OS_IME (*(vu16 *)0x04000208)
#define reg_MI_MCCNT1 (*(vu32 *)0x040001A4)
#define REG_DISPCNT     (*(volatile u32 *)0x04000000)
#define REG_DB_DISPCNT  (*(volatile u32 *)0x04001000)
#define REG_IME         (*(volatile u16 *)0x04000208)
#define REG_IF          (*(volatile u32 *)0x04000214)
#define reg_GX_POWCNT (*(vu16 *)0x04000304)
struct PMiGenCallbackInfo;
typedef unsigned long u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef volatile u32 vu32;

typedef volatile u16 vu16;

typedef int BOOL;

typedef u32 OSIntrMode;

typedef void (*PMCallback)(u32 result, void *arg);

typedef struct PMiGenCallbackInfo {
    void (*callback)(void *);
    void *arg;
    int priority;
    struct PMiGenCallbackInfo *next;
} PMGenCallbackInfo;

typedef struct PMiWork {
    volatile BOOL lock;
    PMCallback callback;
    void *callbackArg;
    void *work;
} PMiWork;

/* pm.o .bss */
typedef struct PmBss {
    u16 isInit;
    PMGenCallbackInfo *postSleepCallbackList;
    volatile BOOL sleepEndFlag;
    u32 lcdCount;
    u32 dispOffCount;
    u32 exitFactor;
    u32 ampSwitch;
    PMGenCallbackInfo *preSleepCallbackList;
    u32 preDmaCnt[4];
    PMiWork work;
} PmBss;

typedef u32 OSIrqMask;

extern int OS_GetProcMode(void);
extern int OS_GetCpsrIrq(void);
extern void PXIi_HandlerRecvFifoNotEmpty(void);
extern void PXI_Init(void);
extern BOOL PXI_IsCallbackReady(int fifotag, int proc);
extern void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int, u32, BOOL));
extern void SVC_WaitByLoop(int count);
extern void PMi_CommonCallback(int tag, u32 data, BOOL err);
void PMi_ProceedToExit(u32 factor);
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void OS_SpinWaitSysCycles(u32 cycle);
extern void PMi_DummyCallback(u32 result, void *arg);
extern BOOL OS_IsRunOnTwl(void);
extern void PMi_ExecuteList(PMGenCallbackInfo *listp);
extern void MI_StopAllDma(void);
extern void MI_StopAllNDma(void);
extern void OS_Halt(void);
unsigned int PMi_SetAmp(unsigned int status);
int PM_GetLCDPower(void);
unsigned int PMi_GetACAdapterCore(void *buf);
extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);
extern void MI_WaitDma(u32 dmaNo);
extern void MI_StopDma(u32 dmaNo);
extern void PMi_PreSleepForNdma(int ch);
extern OSIrqMask OS_DisableIrqMask(OSIrqMask intr);
extern BOOL OS_IsTickAvailable(void);
extern OSIrqMask OS_SetIrqMask(OSIrqMask intr);
extern u16 OS_GetBootType(void);
extern BOOL CTRDG_IsExisting(void);
extern u16 GX_IsDispOn(void);
extern void GX_DispOff(void);
void PMi_InsertList(PMGenCallbackInfo **listp, PMGenCallbackInfo *info, int priority, int compare);
void PMi_WaitBusy(void);
void PMi_CallCallbackAndUnlock(u32 result);
void PMi_WaitVBlank(void);
void PM_Init(void);
u32 PMi_TryToSendPxiData(u32 *sendData, int num, u16 *retValue, PMCallback callback, void *arg);
void PMi_TryToSendPxiDataTillSuccess(u32 *sendData, int num);
u32 PMi_SendSleepStart(u16 trigger, u16 keyIntrData);
u32 PM_SendUtilityCommandAsync(u32 number, u16 parameter, u16 *retValue, PMCallback callback, void *arg);
u32 PM_SendUtilityCommand(u32 number, u16 parameter, u16 *retValue);
u32 PMi_SetLEDAsync(int status, PMCallback callback, void *arg);
u32 PMi_SetLED(int status);
u32 PM_SetBackLightAsync(int target, int sw, PMCallback callback, void *arg);
u32 PM_SetBackLight(int target, int sw);
u32 PM_ForceToPowerOffAsync(PMCallback callback, void *arg);
u32 PMi_ForceToPowerOff(void);
u32 PM_ForceToPowerOff(void);
unsigned int PM_SetAmp(unsigned int status);
unsigned int PM_SetAmpGain(unsigned int gain);
unsigned int PM_SetAmpGainLevel(u8 level);
u32 PM_GetBattery(int *batteryBuf);
unsigned int PM_GetBatteryLevel(void *isConnectedBuf);
u32 PM_GetBackLight(int *top, int *bottom);
u32 PM_GetAmp(int *swBuf);
void PMi_SendPxiData(u32 data);
void PMi_PreSleepForDma(void);
void PM_GoSleepMode(u32 trigger, u32 logic, u16 keyPattern);
BOOL PMi_SetLCDPower(int sw, int led, BOOL skip, BOOL isSync);
BOOL PM_SetLCDPower(int sw);
unsigned int PMi_SendLEDPatternCommand(unsigned int pattern);
u32 PM_GetLEDPattern(int *patternBuf);
void PMi_DeleteList(PMGenCallbackInfo **listp, PMGenCallbackInfo *info);
void PM_PrependPreSleepCallback(void *info);
void PM_AppendPostSleepCallback(void *info);
void PMi_InsertPreSleepCallbackEx(struct PMiGenCallbackInfo *info, int priority);
void PM_DeletePreSleepCallback(PMGenCallbackInfo *info);
void PM_DeletePostSleepCallback(PMGenCallbackInfo *info);
void PMi_LCDOnAvoidReset(void);
void PMi_SetDispOffCount(void);
extern PmBss g_02153000;
extern int g_020A8724;
extern PMGenCallbackInfo PMi_BatteryLowCallbackInfo;
extern PMGenCallbackInfo *g_02732FAC;
extern u32 g_02153020[4];
extern int g_0215301C[];
extern int g_02153004[];
extern struct PMiGenCallbackInfo *PMi_PostSleepCallbackList;






void PMi_WaitBusy(void)
{
    volatile BOOL *p = &g_02153000.work.lock;

    while (*p) {
        if (((g_020A8724 & 2) && OS_GetProcMode() == 0x12)
            || ((g_020A8724 & 4) && OS_GetCpsrIrq() == 0x80)
            || ((g_020A8724 & 8) && reg_OS_IME == 0)) {
            PXIi_HandlerRecvFifoNotEmpty();
        }
    }
}





/*
 * note:     spi/ARM9/pm.o PMi_DummyCallback.
 */
void PMi_DummyCallback(u32 result, void *arg)
{
    if (arg) {
        *(u32 *)arg = result;
    }
}








void PMi_CallCallbackAndUnlock(u32 result)
{
    PMCallback callback = g_02153000.work.callback;
    void *arg = g_02153000.work.callbackArg;

    g_02153000.work.lock = 0;
    if (callback) {
        g_02153000.work.callback = 0;
        callback(result, arg);
    }
}





static inline u32 OS_GetVBlankCount(void)
{
    return *(vu32 *)0x02FFFC3C;
}





void PMi_WaitVBlank(void)
{
    vu32 vcount = OS_GetVBlankCount();
    while (vcount == OS_GetVBlankCount()) {
    }
}


/*
 * TwlSDK libspi pm.o, the init entry (PM_Init shape): a once-only latch on
 * the module work's +0x00 halfword, clear the two callback-list heads at
 * +0x30/+0x34 and the shared word 0x02FFF684, run the lock setup behind the
 * veneer at 0x02088498, spin with SVC_WaitByLoop(100) until the ARM7 side's
 * PM FIFO tag (8) is ready, install PMi_CommonCallback, then seed +0x10 and
 * +0x0c from one read of the VBlank counter (0x02FFFC3C).
 *
 * The 9-byte r0/r1 swap in docs/notes/pkt_0208B8B0.c.txt was the last
 * statement: the counter is READ ONCE (volatile, through an inline
 * OS_GetVBlankCount) and assigned in a chain, so its address is materialised
 * before the work pointer.  0x02FFF684 and 0x02FFFC3C are fixed shared-memory
 * addresses, written as cast constants, so the site that note left without a
 * witness is not a relocation at all.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/PM_Init.c \
 *       --func PM_Init --addr 0x0208B8B0 --arm --cc 1.1p1
 */
void PM_Init(void)
{
    if (g_02153000.isInit) return;
    g_02153000.isInit = 1;
    g_02153000.work.lock = 0;
    g_02153000.work.callback = 0;
    *(vu32 *)0x02FFF684 = 0;
    PXI_Init();
    while (!PXI_IsCallbackReady(8, 1)) {
        SVC_WaitByLoop(100);
    }
    PXI_SetFifoRecvCallback(8, PMi_CommonCallback);
    g_02153000.lcdCount = g_02153000.dispOffCount = OS_GetVBlankCount();
}








/*
 * sdk:      PMi_CommonCallback (libspi.TWL.HYB.a pm.o)
 *
 * The DWARF lists (data, err); the body reads r1 and r2, so this is the
 * 3-argument PXI FIFO callback. The pool word at 0x02153000 is the pm.o bss
 * base; the object addresses its statics from it (+0x08, +0x3c). The two
 * switches keep their explicit no-op case labels (0x62; 1, 2, 3) so that
 * both lower to jump tables.
 */
void PMi_CommonCallback(int tag, u32 data, BOOL err)
{
    u16 command;
    u16 pxiResult;
    BOOL callCallback = 1;

    command = (u16)((data & 0x7f00) >> 8);
    pxiResult = (u16)(data & 0xff);

    if (err) {
        PMi_CallCallbackAndUnlock((command == 0x61 || command == 0x62) ? 1 : 2);
        return;
    }

    switch (command) {
    case 0x61:
        if (g_02153000.work.work) {
            *(u16 *)g_02153000.work.work = pxiResult;
        }
        pxiResult = 0;
        break;
    case 0x60:
        pxiResult = 0;
        break;
    case 0x62:
        break;
    case 0x63:
        g_02153000.sleepEndFlag = 1;
        break;
    case 0x70:
        switch (pxiResult) {
        case 0:
            PMi_ProceedToExit(1);
            *(vu32 *)0x02FFF684 = 1;
            break;
        case 1:
        case 2:
        case 3:
            break;
        case 4:
            if (PMi_BatteryLowCallbackInfo.callback) {
                PMi_BatteryLowCallbackInfo.callback(PMi_BatteryLowCallbackInfo.arg);
            }
            break;
        case 5:
            PMi_ProceedToExit(2);
            *(vu32 *)0x02FFF684 = 1;
            break;
        }
        callCallback = 0;
        break;
    }

    if (callCallback) {
        PMi_CallCallbackAndUnlock(pxiResult);
    }
}

































u32 PMi_TryToSendPxiData(u32 *sendData, int num, u16 *retValue, PMCallback callback, void *arg)
{
    OSIntrMode enabled = OS_DisableInterrupts();
    int n;

    if (g_02153000.work.lock) {
        (void)OS_RestoreInterrupts(enabled);
        return 1;
    }
    g_02153000.work.lock = 1;
    g_02153000.work.work = retValue;
    g_02153000.work.callback = callback;
    g_02153000.work.callbackArg = arg;

    for (n = 0; n < num; n++) {
        PMi_SendPxiData(sendData[n]);
    }

    (void)OS_RestoreInterrupts(enabled);
    return 0;
}




















void PMi_TryToSendPxiDataTillSuccess(u32 *sendData, int num)
{
    volatile u32 result;

    while (1) {
        result = 0xFFFF0000;
        while (PMi_TryToSendPxiData(sendData, num, 0, PMi_DummyCallback, (void *)&result) != 0) {
            OS_SpinWaitSysCycles(0x51D23);
        }
        while (result == 0xFFFF0000) {
            OS_SpinWaitSysCycles(0x51D23);
        }
        if (result == 0) {
            break;
        }
        OS_SpinWaitSysCycles(0x51D23);
    }
}




















u32 PMi_SendSleepStart(u16 trigger, u16 keyIntrData)
{
    u32 sendData[2];

    sendData[0] = 0x03006000;
    PMi_TryToSendPxiDataTillSuccess(sendData, 1);

    while (PMi_SetLCDPower(0, 2, 0, 1) != 1) {
    }

    sendData[0] = 0x02000000 | 0x6200 | (trigger & 0xFF);
    sendData[1] = 0x01010000 | (keyIntrData & 0xFFFF);
    PMi_TryToSendPxiDataTillSuccess(sendData, 2);

    return 0;
}




















u32 PM_SendUtilityCommandAsync(u32 number, u16 parameter, u16 *retValue, PMCallback callback, void *arg)
{
    u32 sendData[2];

    sendData[0] = 0x02000000 | 0x6100 | (number & 0xFF);
    sendData[1] = 0x01010000 | (parameter & 0xFFFF);
    return PMi_TryToSendPxiData(sendData, 2, retValue, callback, arg);
}




















u32 PM_SendUtilityCommand(u32 number, u16 parameter, u16 *retValue)
{
    u32 commandResult;
    u32 sendResult = PM_SendUtilityCommandAsync(number, parameter, retValue, PMi_DummyCallback, &commandResult);

    if (sendResult == 0) {
        PMi_WaitBusy();
        return commandResult;
    }
    return sendResult;
}

















u32 PMi_SetLEDAsync(int status, PMCallback callback, void *arg)
{
    u32 command;

    switch (status) {
    case 1:
        command = 1;
        break;
    case 3:
        command = 2;
        break;
    case 2:
        command = 3;
        break;
    default:
        command = 0;
    }

    if (!command) {
        return 0xFFFF;
    }
    return PM_SendUtilityCommandAsync(command, 0, 0, callback, arg);
}
















u32 PMi_SetLED(int status)
{
    u32 commandResult;
    u32 sendResult = PMi_SetLEDAsync(status, PMi_DummyCallback, &commandResult);

    if (sendResult == 0) {
        PMi_WaitBusy();
        return commandResult;
    }
    return sendResult;
}















u32 PM_SetBackLightAsync(int target, int sw, PMCallback callback, void *arg)
{
    u32 command = 0;

    if (target == 0) {
        if (sw == 1) {
            command = 6;
        }
        if (sw == 0) {
            command = 7;
        }
    } else if (target == 1) {
        if (sw == 1) {
            command = 4;
        }
        if (sw == 0) {
            command = 5;
        }
    } else if (target == 2) {
        if (sw == 1) {
            command = 8;
        }
        if (sw == 0) {
            command = 9;
        }
    }

    if (!command) {
        return 0xFFFF;
    }
    return PM_SendUtilityCommandAsync(command, 0, 0, callback, arg);
}














u32 PM_SetBackLight(int target, int sw)
{
    u32 commandResult;
    u32 sendResult = PM_SetBackLightAsync(target, sw, PMi_DummyCallback, &commandResult);

    if (sendResult == 0) {
        PMi_WaitBusy();
        return commandResult;
    }
    return sendResult;
}













u32 PM_ForceToPowerOffAsync(PMCallback callback, void *arg)
{
    g_02153000.exitFactor = 3;
    PMi_LCDOnAvoidReset();
    if (OS_IsRunOnTwl()) {
        PMi_ExecuteList(g_02732FAC);
    }
    return PM_SendUtilityCommandAsync(0xE, 0, 0, callback, arg);
}












u32 PMi_ForceToPowerOff(void)
{
    u32 commandResult;
    u32 sendResult = PM_ForceToPowerOffAsync(PMi_DummyCallback, &commandResult);

    if (sendResult == 0) {
        g_020A8724 = 0xC;
        PMi_WaitBusy();
        g_020A8724 = 2;
        return commandResult;
    }
    return sendResult;
}











u32 PM_ForceToPowerOff(void)
{
    while (PMi_ForceToPowerOff() != 0) {
        OS_SpinWaitSysCycles(0x51D23);
    }

    (void)OS_DisableInterrupts();
    MI_StopAllDma();
    if (OS_IsRunOnTwl()) {
        MI_StopAllNDma();
    }

    while (1) {
        OS_Halt();
    }
    return 0;
}












/*
 * note:     spi/ARM9/pm.o PM_SetAmp.
 */
unsigned int PM_SetAmp(unsigned int status)
{
    g_02153000.ampSwitch = status;
    return PMi_SetAmp(status);
}













/*
 * note:     spi/ARM9/pm.o PMi_SetAmp.
 */
unsigned int PMi_SetAmp(unsigned int status)
{
    if (PM_GetLCDPower()) {
        return PM_SendUtilityCommand(0x10, (u16)status, 0);
    }
    return 0;
}













/*
 * note:     spi/ARM9/pm.o PM_SetAmpGain.
 */
unsigned int PM_SetAmpGain(unsigned int gain)
{
    return PM_SendUtilityCommand(0x11, (u16)gain, 0);
}













/*
 * note:     spi/ARM9/pm.o PM_SetAmpGainLevel.
 */
unsigned int PM_SetAmpGainLevel(u8 level)
{
    return PM_SendUtilityCommand(0x16, (u16)level, 0);
}



















u32 PM_GetBattery(int *batteryBuf)
{
    u16 status;
    u32 result = PM_SendUtilityCommand(0xF, 0, &status);

    if (result == 0) {
        if (batteryBuf) {
            *batteryBuf = status ? 1 : 0;
        }
    }
    return result;
}












/*
 * note:     spi/ARM9/pm.o PM_GetACAdapter.
 */
unsigned int PM_GetBatteryLevel(void *isConnectedBuf)
{
    if (OS_IsRunOnTwl()) {
        return PMi_GetACAdapterCore(isConnectedBuf);
    }
    return 2;
}












u32 PM_GetBackLight(int *top, int *bottom)
{
    u16 status;
    u32 result = PM_SendUtilityCommand(0xF, 3, &status);

    if (result == 0) {
        if (top) {
            *top = (status & 8) ? 1 : 0;
        }
        if (bottom) {
            *bottom = (status & 4) ? 1 : 0;
        }
    }
    return result;
}













u32 PM_GetAmp(int *swBuf)
{
    u16 status;
    u32 result = PM_SendUtilityCommand(0xF, 6, &status);

    if (result == 0) {
        if (swBuf) {
            *swBuf = status ? 1 : 0;
        }
    }
    return result;
}













void PMi_SendPxiData(u32 data)
{
    while (PXI_SendWordByFifo(8, data, 0) != 0) {
    }
}








void PMi_PreSleepForDma(void)
{
    u32 i;

    for (i = 0; i <= 3; i++) {
        vu32 *dmaCntp = (vu32 *)(0x040000B8 + i * 12);

        g_02153020[i] = *dmaCntp;

        switch (*dmaCntp & 0x38000000) {
        case 0x28000000:
            while (reg_MI_MCCNT1 & 0x80000000) {
            }
            break;
        case 0x18000000:
        case 0x20000000:
            MI_WaitDma(i);
            break;
        default:
            if (!(*dmaCntp & 0x02000000)) {
                MI_WaitDma(i);
            } else {
                MI_StopDma(i);
            }
            break;
        }

        if (OS_IsRunOnTwl()) {
            PMi_PreSleepForNdma(i);
        }
    }
}






enum { PM_LCD_POWER_OFF = 0, PM_LCD_POWER_ON = 1 };






enum { PM_BACKLIGHT_OFF = 0, PM_BACKLIGHT_ON = 1 };









static inline u16 swap_ime(u16 enable)
{
    u16 prep = REG_IME;
    REG_IME = enable;
    return prep;
}









void PM_GoSleepMode(u32 trigger, u32 logic, u16 keyPattern)
{
    OSIntrMode prepIntrMode;
    OSIrqMask prepIntrMask;
    BOOL powerOffFlag = 0;
    int preTop;
    int preBottom;
    u32 preGX;
    u32 preGXS;
    int preLCDPower;
    u16 prepIME;

    PMi_ExecuteList(g_02153000.preSleepCallbackList);

    prepIME = swap_ime(0);
    prepIntrMode = OS_DisableInterrupts();
    prepIntrMask = OS_DisableIrqMask(0xFFFFFFFF);
    (void)OS_SetIrqMask(0x40000 | (OS_IsTickAvailable() ? 8 : 0));
    (void)OS_RestoreInterrupts(prepIntrMode);
    (void)swap_ime(1);

    if (trigger & 8) {
        u16 type = OS_GetBootType();
        if (type == 2 || type == 3) {
            trigger &= ~8;
        }
    }
    if (trigger & 0x10) {
        if (OS_IsRunOnTwl() || !CTRDG_IsExisting()) {
            trigger &= ~0x10;
        }
    }

    preGX = REG_DISPCNT;
    preGXS = REG_DB_DISPCNT;
    preLCDPower = PM_GetLCDPower();

    while (PM_GetBackLight(&preTop, &preBottom) != 0) {
        OS_SpinWaitSysCycles(0x51D23);
    }
    while (PM_SetBackLight(2, PM_BACKLIGHT_OFF) != 0) {
        OS_SpinWaitSysCycles(0x51D23);
    }

    PMi_WaitVBlank();
    REG_DISPCNT &= ~0x30000;
    REG_DB_DISPCNT &= ~0x10000;
    PMi_WaitVBlank();
    PMi_WaitVBlank();

    PMi_PreSleepForDma();
    g_02153000.sleepEndFlag = 0;
    {
        u32 topFlag;
        u32 bottomFlag;
        u32 wake;

        bottomFlag = preBottom ? 0x80 : 0;
        topFlag = preTop ? 0x40 : 0;
        (void)OS_SetIrqMask(0x40000);

        wake = trigger | topFlag;
        wake |= bottomFlag;
        (void)PMi_SendSleepStart((u16)wake, (u16)(logic | keyPattern));
    }

    while (!g_02153000.sleepEndFlag) {
        OS_Halt();
    }

    (void)OS_SetIrqMask(0x40000 | (OS_IsTickAvailable() ? 8 : 0));

    if (trigger & 8) {
        if (REG_IF & 0x100000) {
            powerOffFlag = 1;
        }
    }

    if (!powerOffFlag) {
        if (preLCDPower == PM_LCD_POWER_ON) {
            while (PMi_SetLCDPower(1, 1, 1, 1) != 1) {
            }
        } else {
            while (PMi_SetLED(1) != 0) {
                OS_SpinWaitSysCycles(0x51D23);
            }
        }
        REG_DISPCNT = preGX;
        REG_DB_DISPCNT = preGXS;
    }

    OS_SpinWaitSysCycles(0x360000);

    (void)swap_ime(0);
    (void)OS_SetIrqMask(prepIntrMask);
    (void)OS_RestoreInterrupts(prepIntrMode);
    (void)swap_ime(prepIME);

    if (powerOffFlag) {
        (void)PM_ForceToPowerOff();
    }

    PMi_ExecuteList(g_02153000.postSleepCallbackList);
}









BOOL PMi_SetLCDPower(int sw, int led, BOOL skip, BOOL isSync)
{
    switch (sw) {
    case 1:
        if (!skip && OS_GetVBlankCount() - g_02153000.lcdCount <= 7) {
            return 0;
        }
        if (led != 0) {
            if (isSync) {
                while (PMi_SetLED(led) != 0) {
                    OS_SpinWaitSysCycles(0x51D23);
                }
            } else {
                while (PMi_SetLEDAsync(led, 0, 0) != 0) {
                    OS_SpinWaitSysCycles(0x51D23);
                }
            }
        }
        reg_GX_POWCNT |= 1;
        while (PMi_SetAmp(g_02153000.ampSwitch) != 0) {
            OS_SpinWaitSysCycles(0x51D23);
        }
        break;
    case 0:
        while (PMi_SetAmp(0) != 0) {
            OS_SpinWaitSysCycles(0x51D23);
        }
        if (OS_GetVBlankCount() - g_02153000.dispOffCount <= 2) {
            PMi_WaitVBlank();
            PMi_WaitVBlank();
        }
        reg_GX_POWCNT &= ~1;
        g_02153000.lcdCount = OS_GetVBlankCount();
        if (led != 0) {
            if (isSync) {
                while (PMi_SetLED(led) != 0) {
                    OS_SpinWaitSysCycles(0x51D23);
                }
            } else {
                while (PMi_SetLEDAsync(led, 0, 0) != 0) {
                    OS_SpinWaitSysCycles(0x51D23);
                }
            }
        }
        break;
    }
    return 1;
}












BOOL PM_SetLCDPower(int sw)
{
    if (sw != 1) {
        sw = 0;
        if (GX_IsDispOn()) {
            GX_DispOff();
        }
    }
    return PMi_SetLCDPower(sw, 0, 0, 1);
}








/*
 * note:     spi/ARM9/pm.o PM_GetLCDPower.
 */
int PM_GetLCDPower(void)
{
    return (*(volatile unsigned short *)0x04000304 & 1) ? 1 : 0;
}









/*
 * note:     spi/ARM9/pm.o PMi_SendLEDPatternCommand.
 */
unsigned int PMi_SendLEDPatternCommand(unsigned int pattern)
{
    return PM_SendUtilityCommand(0x12, (u16)pattern, 0);
}









u32 PM_GetLEDPattern(int *patternBuf)
{
    u16 status;
    u32 result = PM_SendUtilityCommand(0xF, 8, &status);

    if (result == 0) {
        if (patternBuf) {
            *patternBuf = (int)status;
        }
    }
    return result;
}





/*
 * sdk:      PMi_InsertList (libspi.TWL.HYB.a pm.o)
 */
void PMi_InsertList(PMGenCallbackInfo **listp, PMGenCallbackInfo *info, int priority, int method)
{
    PMGenCallbackInfo *p;
    PMGenCallbackInfo *pre;
    unsigned long intr;

    if (!listp) {
        return;
    }
    info->priority = priority;
    intr = OS_DisableInterrupts();
    pre = 0;
    p = *listp;
    while (p) {
        if (method == 0 && p->priority > priority) {
            break;
        }
        if (method == 1 && p->priority >= priority) {
            break;
        }
        pre = p;
        p = p->next;
    }
    if (p) {
        info->next = p;
    } else {
        info->next = 0;
    }
    if (pre) {
        pre->next = info;
    } else {
        *listp = info;
    }
    OS_RestoreInterrupts(intr);
}





/*
 * sdk:      PMi_DeleteList (libspi.TWL.HYB.a pm.o)
 */
void PMi_DeleteList(PMGenCallbackInfo **listp, PMGenCallbackInfo *info)
{
    PMGenCallbackInfo *pre;
    PMGenCallbackInfo *p;
    unsigned long intr;

    if (!listp) {
        return;
    }
    intr = OS_DisableInterrupts();
    pre = p = *listp;
    while (p) {
        if (p == info) {
            if (p == pre) {
                *listp = p->next;
            } else {
                pre->next = p->next;
            }
            break;
        }
        pre = p;
        p = p->next;
    }
    OS_RestoreInterrupts(intr);
}





/*
 * note:     spi/ARM9/pm.o PMi_ExecuteList.
 */
void PMi_ExecuteList(PMGenCallbackInfo *listp)
{
    while (listp) {
        (listp->callback)(listp->arg);
        listp = listp->next;
    }
}





/*
 * note:     spi/ARM9/pm.o PM_PrependPostSleepCallback.
 */
void PM_PrependPreSleepCallback(void *info)
{
    PMi_InsertList((PMGenCallbackInfo **)g_0215301C, info, -255, 1);
}




/*
 * note:     spi/ARM9/pm.o PM_AppendPostSleepCallback.  Pool word is 0x02153004
 *           (distinct from PM_PrependPostSleepCallback's 0x0215301C); libmatch
 *           may have swapped the two list names.
 */
void PM_AppendPostSleepCallback(void *info)
{
    PMi_InsertList((PMGenCallbackInfo **)g_02153004, info, 255, 0);
}




/*
 * sdk:      PMi_InsertPostSleepCallbackEx (libspi.TWL.HYB.a pm.o)
 */
void PMi_InsertPreSleepCallbackEx(struct PMiGenCallbackInfo *info, int priority)
{
    PMi_InsertList(&PMi_PostSleepCallbackList, info, priority, 0);
}



void PM_DeletePreSleepCallback(PMGenCallbackInfo *info)
{
    PMi_DeleteList((PMGenCallbackInfo **)g_0215301C, info);
}




void PM_DeletePostSleepCallback(PMGenCallbackInfo *info)
{
    PMi_DeleteList(&g_02153000.postSleepCallbackList, info);
}







void PMi_LCDOnAvoidReset(void)
{
    int preMethod;

    OS_SpinWaitSysCycles(0x360000);
    preMethod = g_020A8724;
    g_020A8724 = 0xE;

    if (PM_GetLCDPower() != 1) {
        while (PM_SetBackLight(2, 0) != 0) {
            OS_SpinWaitSysCycles(0x51D23);
        }
        while (!PM_SetLCDPower(1)) {
            OS_SpinWaitSysCycles(5);
        }
    }
    g_020A8724 = preMethod;
}




void PMi_SetDispOffCount(void)
{
    g_02153000.dispOffCount = OS_GetVBlankCount();
}
