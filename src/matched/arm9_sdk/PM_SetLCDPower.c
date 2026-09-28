/*
 * function: PM_SetLCDPower
 * address:  0x0208C64C
 * packet:   pkt_0208C64C
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
 *   GX_IsDispOn                    0x0207D41C  arm
 *   GX_DispOff                     0x0207D42C  arm
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

extern BOOL GX_IsDispOn(void);
extern void GX_DispOff(void);
extern BOOL PMi_SetLCDPower(int sw, int led, BOOL skip, BOOL isSync);

BOOL PM_SetLCDPower(int sw)
{
    if (sw != 1) {
        sw = 0;
        if (GX_IsDispOn()) {
            GX_DispOff();
        }
    }
    return PMi_SetLCDPower(sw, 0, 0, 1);
}
