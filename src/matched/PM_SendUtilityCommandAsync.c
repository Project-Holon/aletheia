/*
 * function: PM_SendUtilityCommandAsync
 * address:  0x0208BC44
 * packet:   pkt_0208BC44
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
 *   PMi_TryToSendPxiData           0x0208BA70  arm
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

extern u32 PMi_TryToSendPxiData(u32 *sendData, int num, u16 *retValue, PMCallback callback, void *arg);

u32 PM_SendUtilityCommandAsync(u32 number, u16 parameter, u16 *retValue, PMCallback callback, void *arg)
{
    u32 sendData[2];

    sendData[0] = 0x02000000 | 0x6100 | (number & 0xFF);
    sendData[1] = 0x01010000 | (parameter & 0xFFFF);
    return PMi_TryToSendPxiData(sendData, 2, retValue, callback, arg);
}
