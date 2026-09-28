/*
 * function: PM_GoSleepMode
 * address:  0x0208C154
 * packet:   pkt_0208C154
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libspi pm.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Puts the
 * system to sleep: runs the pre-sleep callbacks, masks interrupts down to
 * the PXI FIFO (and the tick timer), drops unusable wake triggers, turns
 * the backlights and displays off, asks ARM7 to sleep and halts until the
 * wake notification, then restores the display, the LCD or LED state and
 * the interrupt state, powers off if the card was pulled, and runs the
 * post-sleep callbacks.
 *
 * pm.o .bss from 0x02153000 (PM_Init's static PMi_IsInit at +0, the
 * post-sleep list at +4, the sleep-end flag at +8, the pre-sleep list at
 * +0x1C) is addressed through one section-relative pool word.  The IME
 * swaps are an inline helper (no call, no DWARF local).  The wake-trigger
 * temporaries have no DWARF entries either; they are what pins the backlight
 * flags ahead of OS_SetIrqMask and the or-chain's operand order.
 *
 * symbols:
 *   g_02153000             0x02153000  data
 *   PMi_ExecuteList        0x0208C7E0  arm
 *   OS_DisableInterrupts   0x02087988  arm
 *   OS_DisableIrqMask      0x02084998  arm
 *   OS_IsTickAvailable     0x02087058  arm
 *   OS_SetIrqMask          0x0208493C  arm
 *   OS_RestoreInterrupts   0x0208799C  arm
 *   OS_GetBootType         0x02087B04  arm
 *   OS_IsRunOnTwl          0x02085D3C  arm
 *   CTRDG_IsExisting       0x02090F50  arm
 *   PM_GetLCDPower         0x0208C688  arm
 *   PM_GetBackLight        0x0208BFD0  arm
 *   OS_SpinWaitSysCycles   0x02087A04  arm
 *   PM_SetBackLight        0x0208BDD8  arm
 *   PMi_WaitVBlank         0x0208B87C  arm
 *   PMi_PreSleepForDma     0x0208C0AC  arm
 *   PMi_SendSleepStart     0x0208BBB8  arm
 *   OS_Halt                0x020882D0  arm
 *   PMi_SetLCDPower        0x0208C44C  arm
 *   PMi_SetLED             0x0208BD28  arm
 *   PM_ForceToPowerOff     0x0208BEA4  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;
typedef u32 OSIntrMode;
typedef u32 OSIrqMask;

typedef struct PMiGenCallbackInfo PMGenCallbackInfo;

typedef enum { PM_LCD_POWER_OFF = 0, PM_LCD_POWER_ON = 1 } PMLCDPower;
typedef enum { PM_BACKLIGHT_OFF = 0, PM_BACKLIGHT_ON = 1 } PMBackLightSwitch;

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
} PmBss;

extern PmBss g_02153000;

#define REG_DISPCNT     (*(volatile u32 *)0x04000000)
#define REG_DB_DISPCNT  (*(volatile u32 *)0x04001000)
#define REG_IME         (*(volatile u16 *)0x04000208)
#define REG_IF          (*(volatile u32 *)0x04000214)

static inline u16 swap_ime(u16 enable)
{
    u16 prep = REG_IME;
    REG_IME = enable;
    return prep;
}

extern void PMi_ExecuteList(PMGenCallbackInfo *listp);
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIrqMask OS_DisableIrqMask(OSIrqMask intr);
extern BOOL OS_IsTickAvailable(void);
extern OSIrqMask OS_SetIrqMask(OSIrqMask intr);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern u16 OS_GetBootType(void);
extern BOOL OS_IsRunOnTwl(void);
extern BOOL CTRDG_IsExisting(void);
extern PMLCDPower PM_GetLCDPower(void);
extern u32 PM_GetBackLight(PMBackLightSwitch *top, PMBackLightSwitch *bottom);
extern void OS_SpinWaitSysCycles(u32 cycle);
extern u32 PM_SetBackLight(int target, PMBackLightSwitch sw);
extern void PMi_WaitVBlank(void);
extern void PMi_PreSleepForDma(void);
extern u32 PMi_SendSleepStart(u16 trigger, u16 keyIntrData);
extern void OS_Halt(void);
extern BOOL PMi_SetLCDPower(int sw, int led, BOOL skip, BOOL isSync);
extern u32 PMi_SetLED(int status);
extern u32 PM_ForceToPowerOff(void);

void PM_GoSleepMode(u32 trigger, u32 logic, u16 keyPattern)
{
    OSIntrMode prepIntrMode;
    OSIrqMask prepIntrMask;
    BOOL powerOffFlag = 0;
    PMBackLightSwitch preTop;
    PMBackLightSwitch preBottom;
    u32 preGX;
    u32 preGXS;
    PMLCDPower preLCDPower;
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
