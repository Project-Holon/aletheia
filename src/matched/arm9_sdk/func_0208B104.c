/*
 * function: TP_GetCalibratedPoint
 * address:  0x0208B104
 * packet:   pkt_0208B104
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TP_GetCalibratedPoint (libspi.TWL.HYB.a tp.o)
 *
 * symbols:
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
typedef long long s64;

void TP_GetCalibratedPoint(TPData *disp, const TPData *raw)
{
    TPiCalibrateParam *cal;

    if (!tpState.calibrate_flg) {
        *disp = *raw;
        return;
    }

    cal = &tpState.calibrate;

    disp->touch = raw->touch;
    disp->validity = raw->validity;
    if (raw->touch == 0) {
        disp->x = 0;
        disp->y = 0;
        return;
    }

    disp->x = (u16)((((s64)(raw->x * 4) - cal->x0) * cal->xDotSizeInv) >> 22);
    if ((s16)disp->x < 0) {
        disp->x = 0;
    } else if ((s16)disp->x > 255) {
        disp->x = 255;
    }

    disp->y = (u16)((((s64)(raw->y * 4) - cal->y0) * cal->yDotSizeInv) >> 22);
    if ((s16)disp->y < 0) {
        disp->y = 0;
    } else if ((s16)disp->y > 191) {
        disp->y = 191;
    }
}
