/*
 * function: PMi_CallCallbackAndUnlock
 * address:  0x0208B84C
 * packet:   pkt_0208B84C
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
