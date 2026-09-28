/*
 * function: PM_ForceToPowerOffAsync
 * address:  0x0208BE00
 * packet:   pkt_0208BE00
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
 *   g_02732FAC                     0x02732FAC  data
 *   PMi_LCDOnAvoidReset            0x0208C89C  arm
 *   OS_IsRunOnTwl                  0x02085D3C  arm
 *   PMi_ExecuteList                0x0208C7E0  arm
 *   PM_SendUtilityCommandAsync     0x0208BC44  arm
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

extern PMGenCallbackInfo *g_02732FAC;
extern void PMi_LCDOnAvoidReset(void);
extern BOOL OS_IsRunOnTwl(void);
extern void PMi_ExecuteList(PMGenCallbackInfo *listp);
extern u32 PM_SendUtilityCommandAsync(u32 number, u16 parameter, u16 *retValue, PMCallback callback, void *arg);

u32 PM_ForceToPowerOffAsync(PMCallback callback, void *arg)
{
    g_02153000.exitFactor = 3;
    PMi_LCDOnAvoidReset();
    if (OS_IsRunOnTwl()) {
        PMi_ExecuteList(g_02732FAC);
    }
    return PM_SendUtilityCommandAsync(0xE, 0, 0, callback, arg);
}
