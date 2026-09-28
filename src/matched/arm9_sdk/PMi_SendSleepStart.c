/*
 * function: PMi_SendSleepStart
 * address:  0x0208BBB8
 * packet:   pkt_0208BBB8
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
 *   PMi_TryToSendPxiDataTillSuccess 0x0208BAF4  arm
 *   PMi_SetLCDPower                0x0208C44C  arm
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

extern void PMi_TryToSendPxiDataTillSuccess(u32 *sendData, int num);
extern BOOL PMi_SetLCDPower(int sw, int led, BOOL skip, BOOL isSync);

u32 PMi_SendSleepStart(u16 trigger, u16 keyIntrData)
{
    u32 sendData[2];

    sendData[0] = 0x03006000;
    PMi_TryToSendPxiDataTillSuccess(sendData, 1);

    while (PMi_SetLCDPower(0, 2, 0, 1) != 1) {
    }

    sendData[0] = 0x02000000 | 0x6200 | (trigger & 0xFF);
    sendData[1] = 0x01010000 | (keyIntrData & 0xFFFF);
    PMi_TryToSendPxiDataTillSuccess(sendData, 2);

    return 0;
}
