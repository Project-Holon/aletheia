/*
 * function: PMi_SetLCDPower
 * address:  0x0208C44C
 * packet:   pkt_0208C44C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libspi pm.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 *
 * symbols:
 *   g_02153000                     0x02153000  data
 *   PMi_SetLED                     0x0208BD28  arm
 *   OS_SpinWaitSysCycles           0x02087A04  arm
 *   PMi_SetLEDAsync                0x0208BCC4  arm
 *   PMi_SetAmp                     0x0208BF08  arm
 *   PMi_WaitVBlank                 0x0208B87C  arm
 */

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

extern PmBss g_02153000;

static inline u32 OS_GetVBlankCount(void)
{
    return *(vu32 *)0x02FFFC3C;
}

extern u32 PMi_SetLED(int status);
extern void OS_SpinWaitSysCycles(u32 cycle);
extern u32 PMi_SetLEDAsync(int status, PMCallback callback, void *arg);
extern u32 PMi_SetAmp(int status);
extern void PMi_WaitVBlank(void);

#define reg_GX_POWCNT (*(vu16 *)0x04000304)

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
