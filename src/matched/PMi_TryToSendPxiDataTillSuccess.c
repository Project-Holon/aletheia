/*
 * function: PMi_TryToSendPxiDataTillSuccess
 * address:  0x0208BAF4
 * packet:   pkt_0208BAF4
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
 *   OS_SpinWaitSysCycles           0x02087A04  arm
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

extern u32 PMi_TryToSendPxiData(u32 *sendData, int num, u16 *retValue, PMCallback callback, void *arg);
extern void OS_SpinWaitSysCycles(u32 cycle);
extern void PMi_DummyCallback(u32 result, void *arg);

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
