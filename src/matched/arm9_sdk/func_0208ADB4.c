/*
 * function: TP_GetLatestRawPointInAuto
 * address:  0x0208ADB4
 * packet:   pkt_0208ADB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TP_GetLatestRawPointInAuto (libspi.TWL.HYB.a tp.o)
 *
 * symbols:
 *   g_02152FA4                     0x02152FA4  data
 *
 * The image listing runs 16 bytes past this function into
 * TP_GetLatestIndexInAuto (0x0208AF08), hence EXACT*.
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

void TP_GetLatestRawPointInAuto(TPData *result)
{
    long i;
    long curr_index;
    TPData *tp;
    long index;

    result->validity = 3;
    curr_index = tpState.index;

    if (tpState.frequence == 1 || tpState.bufSize == 1) {
        *result = tpState.samplingBufs[curr_index];
        return;
    }

    for (i = 0; i < tpState.frequence && i < tpState.bufSize - 1; i++) {
        index = curr_index - i;
        if (index < 0) {
            index += tpState.bufSize;
        }
        tp = &tpState.samplingBufs[index];

        if (!tp->touch) {
            *result = *tp;
            return;
        }
        if ((result->validity & 1) && !(tp->validity & 1)) {
            result->x = tp->x;
            if (i != 0) {
                result->validity &= ~1;
            }
        }
        if ((result->validity & 2) && !(tp->validity & 2)) {
            result->y = tp->y;
            if (i != 0) {
                result->validity &= ~2;
            }
        }
        if (result->validity == 0) {
            result->touch = 1;
            return;
        }
    }
    result->touch = 1;
}
