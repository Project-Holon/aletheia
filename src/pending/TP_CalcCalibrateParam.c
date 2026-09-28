/*
 * function: TP_CalcCalibrateParam
 * address:  0x0208AF18
 * packet:   pkt_0208AF18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * TwlSDK libspi tp.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Computes the
 * touch panel calibration (dot sizes and origins, 8.8 fixed point) from two
 * raw/screen point pairs through the hardware divider, with interrupts off
 * while the divider is in use.  Returns 1 on an invalid input or a result
 * that does not fit an s16, else 0.
 *
 * Near miss: 492/492 bytes, 17 bytes out, all in the y tail (the -0x8000
 * bound and the y0 value swap r0/r1).  See docs/notes/pkt_0208AF18.c.txt.
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

typedef unsigned long u32;
typedef long s32;
typedef unsigned short u16;
typedef short s16;
typedef unsigned long long u64;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile s32 vs32;

typedef struct NvTpData {
    s16 x0;
    s16 y0;
    s16 xDotSize;
    s16 yDotSize;
} NvTpData;

typedef u32 OSIntrMode;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);

#define reg_CP_DIVCNT       (*(vu16 *)0x04000280)
#define reg_CP_DIV_NUMER_L  (*(vu32 *)0x04000290)
#define REG_CP_DIV_DENOM    (*(u64 *)0x04000298)
#define reg_CP_DIV_RESULT_L (*(vs32 *)0x040002A0)

#define REG_CP_DIVCNT_BUSY_MASK 0x8000
#define CP_DIV_32_32 0

#define TP_RAW_MAX 4096
#define GX_LCD_SIZE_X 256
#define GX_LCD_SIZE_Y 192

u32 TP_CalcCalibrateParam(NvTpData *calibrate, u16 raw_x1, u16 raw_y1, u16 dx1, u16 dy1,
                          u16 raw_x2, u16 raw_y2, u16 dx2, u16 dy2)
{
    s32 ry_width;
    s32 dy_width;
    s32 tmp32;
    OSIntrMode enabled;

    if (raw_x1 >= TP_RAW_MAX || raw_y1 >= TP_RAW_MAX || raw_x2 >= TP_RAW_MAX || raw_y2 >= TP_RAW_MAX) {
        return 1;
    }
    if (dx1 >= GX_LCD_SIZE_X || dx2 >= GX_LCD_SIZE_X || dy1 >= GX_LCD_SIZE_Y || dy2 >= GX_LCD_SIZE_Y) {
        return 1;
    }
    if (dx1 == dx2 || dy1 == dy2 || raw_x1 == raw_x2 || raw_y1 == raw_y2) {
        return 1;
    }

    enabled = OS_DisableInterrupts();

    reg_CP_DIVCNT = CP_DIV_32_32;
    reg_CP_DIV_NUMER_L = (u32)((raw_x1 - raw_x2) << 8);
    REG_CP_DIV_DENOM = (u32)(dx1 - dx2);

    ry_width = raw_y1 - raw_y2;
    dy_width = dy1 - dy2;

    while (reg_CP_DIVCNT & REG_CP_DIVCNT_BUSY_MASK) {
    }
    tmp32 = reg_CP_DIV_RESULT_L;

    reg_CP_DIVCNT = CP_DIV_32_32;
    reg_CP_DIV_NUMER_L = (u32)(ry_width << 8);
    REG_CP_DIV_DENOM = (u32)dy_width;

    if (tmp32 >= 0x8000 || tmp32 < -0x8000) {
        (void)OS_RestoreInterrupts(enabled);
        return 1;
    }
    calibrate->xDotSize = (s16)tmp32;
    tmp32 = (s32)((((raw_x1 + raw_x2) << 8) - calibrate->xDotSize * (dx1 + dx2)) << 9) >> 16;
    if (tmp32 >= 0x8000 || tmp32 < -0x8000) {
        (void)OS_RestoreInterrupts(enabled);
        return 1;
    }
    calibrate->x0 = (s16)tmp32;

    while (reg_CP_DIVCNT & REG_CP_DIVCNT_BUSY_MASK) {
    }
    tmp32 = reg_CP_DIV_RESULT_L;
    (void)OS_RestoreInterrupts(enabled);

    if (tmp32 >= 0x8000 || tmp32 < -0x8000) {
        return 1;
    }
    calibrate->yDotSize = (s16)tmp32;
    tmp32 = (s32)((((raw_y1 + raw_y2) << 8) - calibrate->yDotSize * (dy1 + dy2)) << 9) >> 16;
    if (tmp32 >= 0x8000 || tmp32 < -0x8000) {
        return 1;
    }
    calibrate->y0 = (s16)tmp32;
    return 0;
}
