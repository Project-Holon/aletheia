/*
 * function: PM_SetBackLightAsync
 * address:  0x0208BD50
 * packet:   pkt_0208BD50
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

extern u32 PM_SendUtilityCommandAsync(u32 number, u16 parameter, u16 *retValue, PMCallback callback, void *arg);

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
