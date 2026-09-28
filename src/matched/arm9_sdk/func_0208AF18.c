/*
 * function: func_0208AF18
 * address:  0x0208AF18
 * packet:   pkt_0208AF18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TP_CalcCalibrateParam (libspi.TWL.HYB.a tp.o)
 *
 * symbols:
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *
 * The divider's 64-bit denominator is a plain (non-volatile) u64 store,
 * which lets the second one become an stm; ry_width is computed before
 * dy_width even though the DWARF declares ry_width first.
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

typedef struct NvTpData {
    s16 x0;
    s16 y0;
    s16 xDotSize;
    s16 yDotSize;
} NvTpData;
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

u32 func_0208AF18(NvTpData *calibrate, u16 raw_x1, u16 raw_y1, u16 dx1, u16 dy1,
                  u16 raw_x2, u16 raw_y2, u16 dx2, u16 dy2)
{
    long ry_width;
    long dy_width;
    long tmp32;
    u32 enabled;

    if (raw_x1 >= 0x1000 || raw_y1 >= 0x1000 || raw_x2 >= 0x1000 || raw_y2 >= 0x1000) {
        return 1;
    }
    if (dx1 >= 0x100 || dx2 >= 0x100 || dy1 >= 0xc0 || dy2 >= 0xc0) {
        return 1;
    }
    if (dx1 == dx2 || dy1 == dy2 || raw_x1 == raw_x2 || raw_y1 == raw_y2) {
        return 1;
    }

    enabled = OS_DisableInterrupts();

    CP_SetDiv32_32((u32)((raw_x1 - raw_x2) << 8), (u32)(dx1 - dx2));
    ry_width = raw_y1 - raw_y2;
    dy_width = dy1 - dy2;
    CP_WaitDiv();
    tmp32 = CP_GetDivResult32();
    CP_SetDiv32_32((u32)(ry_width << 8), (u32)dy_width);

    if (tmp32 >= 0x8000 || tmp32 < -0x8000) {
        (void)OS_RestoreInterrupts(enabled);
        return 1;
    }
    calibrate->xDotSize = (s16)tmp32;
    tmp32 = (s16)((((raw_x1 + raw_x2) << 8) - calibrate->xDotSize * (dx1 + dx2)) >> 7);
    if (tmp32 >= 0x8000 || tmp32 < -0x8000) {
        (void)OS_RestoreInterrupts(enabled);
        return 1;
    }
    calibrate->x0 = (s16)tmp32;

    CP_WaitDiv();
    tmp32 = CP_GetDivResult32();
    (void)OS_RestoreInterrupts(enabled);

    if (tmp32 >= 0x8000 || tmp32 < -0x8000) {
        return 1;
    }
    calibrate->yDotSize = (s16)tmp32;
    tmp32 = (s16)((((raw_y1 + raw_y2) << 8) - calibrate->yDotSize * (dy1 + dy2)) >> 7);
    if (tmp32 >= 0x8000 || tmp32 < -0x8000) {
        return 1;
    }
    calibrate->y0 = (s16)tmp32;
    return 0;
}
