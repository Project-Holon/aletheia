/*
 * function: PM_SendUtilityCommand
 * address:  0x0208BC8C
 * packet:   pkt_0208BC8C
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
 *   PM_SendUtilityCommandAsync     0x0208BC44  arm
 *   PMi_WaitBusy                   0x0208B7BC  arm
 *   PMi_DummyCallback              0x0208B840  arm
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

#define OS_GetVBlankCount() (*(vu32 *)0x02FFFC3C)

extern u32 PM_SendUtilityCommandAsync(u32 number, u16 parameter, u16 *retValue, PMCallback callback, void *arg);
extern void PMi_WaitBusy(void);
extern void PMi_DummyCallback(u32 result, void *arg);

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
