/*
 * function: PMi_TryToSendPxiData
 * address:  0x0208BA70
 * packet:   pkt_0208BA70
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
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   PMi_SendPxiData                0x0208C080  arm
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

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void PMi_SendPxiData(u32 data);

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
