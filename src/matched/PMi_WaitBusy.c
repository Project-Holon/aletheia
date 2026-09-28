/*
 * function: PMi_WaitBusy
 * address:  0x0208B7BC
 * packet:   pkt_0208B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * TwlSDK libspi pm.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 *
 * symbols:
 *   g_02153000                     0x02153000  data
 *   g_020A8724                     0x020A8724  data
 *   OS_GetProcMode                 0x020879EC  arm
 *   OS_GetCpsrIrq                  0x020879E0  arm
 *   PXIi_HandlerRecvFifoNotEmpty   0x02088688  arm
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

extern int g_020A8724;
extern int OS_GetProcMode(void);
extern int OS_GetCpsrIrq(void);
extern void PXIi_HandlerRecvFifoNotEmpty(void);

#define reg_OS_IME (*(vu16 *)0x04000208)

void PMi_WaitBusy(void)
{
    volatile BOOL *p = &g_02153000.work.lock;

    while (*p) {
        if (((g_020A8724 & 2) && OS_GetProcMode() == 0x12)
            || ((g_020A8724 & 4) && OS_GetCpsrIrq() == 0x80)
            || ((g_020A8724 & 8) && reg_OS_IME == 0)) {
            PXIi_HandlerRecvFifoNotEmpty();
        }
    }
}
