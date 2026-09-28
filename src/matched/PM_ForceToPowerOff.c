/*
 * function: PM_ForceToPowerOff
 * address:  0x0208BEA4
 * packet:   pkt_0208BEA4
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
 *   PMi_ForceToPowerOff            0x0208BE58  arm
 *   OS_SpinWaitSysCycles           0x02087A04  arm
 *   OS_DisableInterrupts           0x02087988  arm
 *   MI_StopAllDma                  0x02082658  arm
 *   OS_IsRunOnTwl                  0x02085D3C  arm
 *   MI_StopAllNDma                 0x0272FD18  arm
 *   OS_Halt                        0x020882D0  arm
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

extern u32 PMi_ForceToPowerOff(void);
extern void OS_SpinWaitSysCycles(u32 cycle);
extern OSIntrMode OS_DisableInterrupts(void);
extern void MI_StopAllDma(void);
extern BOOL OS_IsRunOnTwl(void);
extern void MI_StopAllNDma(void);
extern void OS_Halt(void);

u32 PM_ForceToPowerOff(void)
{
    while (PMi_ForceToPowerOff() != 0) {
        OS_SpinWaitSysCycles(0x51D23);
    }

    (void)OS_DisableInterrupts();
    MI_StopAllDma();
    if (OS_IsRunOnTwl()) {
        MI_StopAllNDma();
    }

    while (1) {
        OS_Halt();
    }
    return 0;
}
