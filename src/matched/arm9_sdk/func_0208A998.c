/*
 * function: func_0208A998
 * address:  0x0208A998
 * packet:   pkt_0208A998
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TP_GetUserInfo (libspi.TWL.HYB.a tp.o)
 *
 * symbols:
 *   TP_CalcCalibrateParam          0x0208AF18  arm
 *
 * The base pointer w is not in the DWARF; without it the compiler folds
 * 0x02FFFC80+0x58 into one pool constant.
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

/* touch-panel calibration points in the NVRAM user info at 0x02FFFC80 */
typedef struct NvTpPoints {
    u8 pad_00[0x58];
    u16 raw_x1;
    u16 raw_y1;
    u8 dx1;
    u8 dy1;
    u16 raw_x2;
    u16 raw_y2;
    u8 dx2;
    u8 dy2;
} NvTpPoints;

int TP_CalcCalibrateParam(TPCalibrateParam *calibrate, u16 x1, u16 y1, u16 dx1, u16 dy1,
                          u16 x2, u16 y2, u16 dx2, u16 dy2);

BOOL func_0208A998(TPCalibrateParam *calibrate)
{
    u16 x1, y1, x2, y2, dx1, dy1, dx2, dy2;
    NvTpPoints *w = (NvTpPoints *)0x02FFFC80;

    x1 = w->raw_x1;
    y1 = w->raw_y1;
    x2 = w->raw_x2;
    y2 = w->raw_y2;
    dx1 = w->dx1;
    dy1 = w->dy1;
    dx2 = w->dx2;
    dy2 = w->dy2;

    if ((x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0)
        || TP_CalcCalibrateParam(calibrate, x1, y1, dx1, dy1, x2, y2, dx2, dy2) != 0) {
        calibrate->x0 = 0;
        calibrate->y0 = 0;
        calibrate->xDotSize = 0;
        calibrate->yDotSize = 0;
        return 1;
    }
    return 1;
}
