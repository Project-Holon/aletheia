/*
 * function: TP_SetCalibrateParam
 * address:  0x0208AA2C
 * packet:   pkt_0208AA2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TP_SetCalibrateParam (libspi.TWL.HYB.a tp.o)
 *
 * symbols:
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   g_02152FA4                     0x02152FA4  data
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;
typedef int BOOL;

typedef void (*TPRecvCallback)(int command, int result, u16 index);

typedef struct TPData {
    u16 x;
    u16 y;
    u16 touch;
    u16 validity;
} TPData;

typedef struct TPCalibrateParam {
    s16 x0;
    s16 y0;
    s16 xDotSize;
    s16 yDotSize;
} TPCalibrateParam;

typedef struct TPiCalibrateParam {
    long x0;
    long xDotSize;
    long xDotSizeInv;
    long y0;
    long yDotSize;
    long yDotSizeInv;
} TPiCalibrateParam;

/* tp.o .bss: TP_Init's static `initial` at +0, tpState (56 bytes) at +4.
   The object addresses both from the section base. */
typedef struct TpBss {
    u16 initial;
    TPRecvCallback callback;
    TPData buf;
    u16 index;
    u16 frequence;
    TPData *samplingBufs;
    u16 bufSize;
    TPiCalibrateParam calibrate;
    u16 calibrate_flg;
    u16 state;
    u16 err_flg;
    volatile u16 command_flg;
} TpBss;

extern TpBss g_02152FA4;
#define tpState g_02152FA4
typedef unsigned long long u64;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;

u32 OS_DisableInterrupts(void);
u32 OS_RestoreInterrupts(u32 state);

static inline void CP_SetDiv32_32(u32 numer, u32 denom)
{
    *(vu16 *)0x04000280 = 0;
    *(vu32 *)0x04000290 = numer;
    *(u64 *)0x04000298 = denom;
}

static inline void CP_WaitDiv(void)
{
    while (*(vu16 *)0x04000280 & 0x8000) {
    }
}

static inline long CP_GetDivResult32(void)
{
    return *(volatile long *)0x040002A0;
}

void TP_SetCalibrateParam(const TPCalibrateParam *param)
{
    u32 enabled;

    if (param == 0) {
        tpState.calibrate_flg = 0;
        return;
    }

    enabled = OS_DisableInterrupts();

    if (param->xDotSize != 0) {
        CP_SetDiv32_32(0x10000000, (u32)param->xDotSize);
        tpState.calibrate.x0 = param->x0;
        tpState.calibrate.xDotSize = param->xDotSize;
        CP_WaitDiv();
        tpState.calibrate.xDotSizeInv = CP_GetDivResult32();
    } else {
        tpState.calibrate.x0 = 0;
        tpState.calibrate.xDotSize = 0;
        tpState.calibrate.xDotSizeInv = 0;
    }

    if (param->yDotSize != 0) {
        CP_SetDiv32_32(0x10000000, (u32)param->yDotSize);
        tpState.calibrate.y0 = param->y0;
        tpState.calibrate.yDotSize = param->yDotSize;
        CP_WaitDiv();
        tpState.calibrate.yDotSizeInv = CP_GetDivResult32();
    } else {
        tpState.calibrate.y0 = 0;
        tpState.calibrate.yDotSize = 0;
        tpState.calibrate.yDotSizeInv = 0;
    }

    (void)OS_RestoreInterrupts(enabled);
    tpState.calibrate_flg = 1;
}
