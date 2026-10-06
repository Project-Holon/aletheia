/*
 * file:     unit_0208B7BC_p01.c
 * unit:     yes
 * function: func_0208B7BC, func_0208B840, PMi_CallCallbackAndUnlock, PMi_WaitVBlank, func_0208B8B0
 * address:  0x0208B7BC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02153000                     0x02153000  data
 *   g_020A8724                     0x020A8724  data
 *   OS_GetProcMode                 0x020879EC  arm
 *   OS_GetCpsrIrq                  0x020879E0  arm
 *   PXIi_HandlerRecvFifoNotEmpty   0x02088688  arm
 *   s_02153000               0x02153000  data
 *   func_02088498            0x02088498  arm
 *   PXI_IsCallbackReady      0x020885EC  arm
 *   PXI_SetFifoRecvCallback  0x020885A0  arm
 *   SVC_WaitByLoop           0x02004490  thumb
 *   PMi_CommonCallback       0x0208B950  arm
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

extern int OS_GetProcMode(void);
extern int OS_GetCpsrIrq(void);
extern void PXIi_HandlerRecvFifoNotEmpty(void);
void PMi_WaitBusy(void);
void func_0208B840(unsigned int result, unsigned int *arg);
void PMi_CallCallbackAndUnlock(u32 result);
void PMi_WaitVBlank(void);
extern PmBss g_02153000;
extern int g_020A8724;








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



/*
 * note:     spi/ARM9/pm.o PMi_DummyCallback.
 */
void func_0208B840(unsigned int result, unsigned int *arg)
{
    if (arg) {
        *arg = result;
    }
}






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



static inline u32 OS_GetVBlankCount(void)
{
    return *(vu32 *)0x02FFFC3C;
}



void PMi_WaitVBlank(void)
{
    vu32 vcount = OS_GetVBlankCount();
    while (vcount == OS_GetVBlankCount()) {
    }
}
