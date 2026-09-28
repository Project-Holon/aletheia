/*
 * function: PMi_LCDOnAvoidReset
 * address:  0x0208C89C
 * packet:   pkt_0208C89C
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
 *   g_020A8724                     0x020A8724  data
 *   OS_SpinWaitSysCycles           0x02087A04  arm
 *   PM_GetLCDPower                 0x0208C688  arm
 *   PM_SetBackLight                0x0208BDD8  arm
 *   PM_SetLCDPower                 0x0208C64C  arm
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

extern int g_020A8724;
extern void OS_SpinWaitSysCycles(u32 cycle);
extern int PM_GetLCDPower(void);
extern u32 PM_SetBackLight(int target, int sw);
extern BOOL PM_SetLCDPower(int sw);

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
