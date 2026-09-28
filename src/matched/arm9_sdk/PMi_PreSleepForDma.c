/*
 * function: PMi_PreSleepForDma
 * address:  0x0208C0AC
 * packet:   pkt_0208C0AC
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
 *   g_02153020                     0x02153020  data
 *   MI_WaitDma                     0x02082594  arm
 *   MI_StopDma                     0x020825F0  arm
 *   OS_IsRunOnTwl                  0x02085D3C  arm
 *   PMi_PreSleepForNdma            0x027313E8  arm
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

extern u32 g_02153020[4];
extern void MI_WaitDma(u32 dmaNo);
extern void MI_StopDma(u32 dmaNo);
extern BOOL OS_IsRunOnTwl(void);
extern void PMi_PreSleepForNdma(u32 i);

#define reg_MI_MCCNT1 (*(vu32 *)0x040001A4)

void PMi_PreSleepForDma(void)
{
    u32 i;

    for (i = 0; i <= 3; i++) {
        vu32 *dmaCntp = (vu32 *)(0x040000B8 + i * 12);

        g_02153020[i] = *dmaCntp;

        switch (*dmaCntp & 0x38000000) {
        case 0x28000000:
            while (reg_MI_MCCNT1 & 0x80000000) {
            }
            break;
        case 0x18000000:
        case 0x20000000:
            MI_WaitDma(i);
            break;
        default:
            if (!(*dmaCntp & 0x02000000)) {
                MI_WaitDma(i);
            } else {
                MI_StopDma(i);
            }
            break;
        }

        if (OS_IsRunOnTwl()) {
            PMi_PreSleepForNdma(i);
        }
    }
}
