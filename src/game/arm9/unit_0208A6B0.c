/*
 * file:     unit_0208A6B0.c
 * unit:     yes
 * function: TPi_TpCallback, func_0208A924, func_0208A998, func_0208AA2C, func_0208AB1C, func_0208ABB8, func_0208AC0C, func_0208AD14, func_0208ADB4, func_0208AF08, func_0208AF18, func_0208B104, func_0208B220, func_0208B238
 * address:  0x0208A6B0
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
 *   PXI_Init                       0x02088498  arm
 *   PXI_IsCallbackReady            0x020885EC  arm
 *   PXI_SetFifoRecvCallback        0x020885A0  arm
 *   TPi_TpCallback                 0x0208A6B0  arm
 *   g_02152FA4                     0x02152FA4  data
 *   TP_CalcCalibrateParam          0x0208AF18  arm
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   PXI_SendWordByFifo             0x02088610  arm
 *   TP_WaitBusy                    0x0208B220  arm
 *   OS_Terminate                   0x02088234  arm
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

typedef union TPRawData {
    struct {
        u32 x:12;
        u32 y:12;
        u32 touch:1;
        u32 validity:2;
        u32 :5;
    };
    u16 halfs[2];
} TPRawData;

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

typedef unsigned long long u64;

typedef volatile u16 vu16;

typedef volatile u32 vu32;

typedef volatile u64 vu64;

typedef struct NvTpData {
    s16 x0;
    s16 y0;
    s16 xDotSize;
    s16 yDotSize;
} NvTpData;

typedef long long s64;

void PXI_Init(void);
BOOL PXI_IsCallbackReady(int fifotag, int proc);
void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int tag, u32 data, BOOL err));
void TPi_TpCallback(int tag, u32 data, BOOL err);
int TP_CalcCalibrateParam(TPCalibrateParam *calibrate, u16 x1, u16 y1, u16 dx1, u16 dy1,
                          u16 x2, u16 y2, u16 dx2, u16 dy2);
u32 OS_DisableInterrupts(void);
u32 OS_RestoreInterrupts(u32 state);
int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);
void TP_WaitBusy(u32 command_flgs);
void func_0208A924(void);
BOOL func_0208A998(TPCalibrateParam *calibrate);
void func_0208AA2C(const TPCalibrateParam *param);
void func_0208AB1C(void);
u32 func_0208ABB8(TPData *result);
void func_0208AC0C(u16 vcount, u16 frequence, TPData samplingBufs[], u16 bufSize);
void func_0208AD14(void);
void func_0208ADB4(TPData *result);
u16 func_0208AF08(void);
u32 func_0208AF18(NvTpData *calibrate, u16 raw_x1, u16 raw_y1, u16 dx1, u16 dy1, u16 raw_x2, u16 raw_y2, u16 dx2, u16 dy2);
void func_0208B104(TPData *disp, const TPData *raw);
void func_0208B220(unsigned int command_flgs);
unsigned int func_0208B238(unsigned int command_flgs);
extern TpBss g_02152FA4;
extern void OS_Terminate(void);



#define tpState g_02152FA4




static inline void TPi_ReadRaw(TPData *data)
{
    TPRawData raw;

    raw.halfs[0] = ((volatile u16 *)0x02FFFFAA)[0];
    raw.halfs[1] = ((volatile u16 *)0x02FFFFAA)[1];
    data->x = (u16)raw.x;
    data->y = (u16)raw.y;
    data->touch = (u8)raw.touch;
    data->validity = (u8)raw.validity;
}

void TPi_TpCallback(int tag, u32 data, BOOL err)
{
    u16 result;
    u16 command;

    result = (u16)(data & 0xFFFF);
    command = (u16)((result & 0x7F00) >> 8);

    if (err) {
        tpState.err_flg |= (u16)(1 << command);
        if (tpState.callback) {
            tpState.callback(command, 4, 0);
        }
        return;
    }

    if (command == 0x10) {
        tpState.index++;
        if (tpState.index >= tpState.bufSize) {
            tpState.index = 0;
        }
        TPi_ReadRaw(&tpState.samplingBufs[tpState.index]);
        if (tpState.callback) {
            tpState.callback(command, 0, (u8)tpState.index);
        }
        return;
    }

    if (!(data & 0x1000000)) {
        return;
    }

    switch ((u8)result) {
    case 0:
        switch (command) {
        case 0:
            TPi_ReadRaw(&tpState.buf);
            tpState.state = 0;
            break;
        case 1:
            tpState.state = 2;
            break;
        case 2:
            tpState.state = 0;
            break;
        }
        tpState.command_flg &= (u16)~(1 << command);
        if (tpState.callback) {
            tpState.callback(command, 0, 0);
        }
        return;
    case 4:
        result = 3;
        break;
    case 2:
        result = 1;
        break;
    case 3:
        result = 2;
        break;
    case 1:
    default:
        goto terminate;
    }

    tpState.err_flg |= (u16)(1 << command);
    tpState.command_flg &= (u16)~(1 << command);
    if (tpState.callback) {
        tpState.callback(command, (u8)result, 0);
    }
    return;

terminate:
    OS_Terminate();
}


/*
 * sdk:      TP_Init (libspi.TWL.HYB.a tp.o)
 */
void func_0208A924(void)
{
    if (tpState.initial) {
        return;
    }
    tpState.initial = 1;

    PXI_Init();

    tpState.index = 0;
    tpState.callback = 0;
    tpState.samplingBufs = 0;
    tpState.state = 0;
    tpState.calibrate_flg = 0;
    tpState.command_flg = 0;
    tpState.err_flg = 0;

    while (!PXI_IsCallbackReady(6, 1)) {
    }
    PXI_SetFifoRecvCallback(6, TPi_TpCallback);
}




/*
 * sdk:      TP_GetUserInfo (libspi.TWL.HYB.a tp.o)
 *
 * The base pointer w is not in the DWARF; without it the compiler folds
 * 0x02FFFC80+0x58 into one pool constant.
 */
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




/*
 * sdk:      TP_SetCalibrateParam (libspi.TWL.HYB.a tp.o)
 */
void func_0208AA2C(const TPCalibrateParam *param)
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




static inline BOOL TPi_SendData(u32 data)
{
    if (PXI_SendWordByFifo(6, data, 0) < 0) {
        return 0;
    }
    return 1;
}




/*
 * sdk:      TP_RequestSamplingAsync (libspi.TWL.HYB.a tp.o)
 */
void func_0208AB1C(void)
{
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (!TPi_SendData(0x03000000)) {
        (void)OS_RestoreInterrupts(enabled);
        tpState.err_flg |= 1;
        if (tpState.callback) {
            tpState.callback(0, 4, 0);
        }
        return;
    }
    tpState.command_flg |= 1;
    tpState.err_flg &= ~1;
    (void)OS_RestoreInterrupts(enabled);
}




/*
 * sdk:      TP_WaitRawResult (libspi.TWL.HYB.a tp.o)
 */
u32 func_0208ABB8(TPData *result)
{
    TP_WaitBusy(1);
    if (tpState.err_flg & 1) {
        return 1;
    }
    *result = tpState.buf;
    return 0;
}




static inline BOOL TPi_SendAutoStart(u16 vcount, u8 frequence)
{
    if (PXI_SendWordByFifo(6, 0x02000000 | 0x100 | frequence, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(6, 0x01000000 | 0x10000 | vcount, 0) < 0) {
        return 0;
    }
    return 1;
}




/*
 * sdk:      TP_RequestAutoSamplingStartAsync (libspi.TWL.HYB.a tp.o)
 *
 * The send result is tested through a u8 cast (tst #0xff); a BOOL or u8
 * return type alone gives cmp #0.
 */
void func_0208AC0C(u16 vcount, u16 frequence, TPData samplingBufs[], u16 bufSize)
{
    u32 enabled;
    u32 i;

    tpState.samplingBufs = samplingBufs;
    tpState.index = 0;
    tpState.frequence = frequence;
    tpState.bufSize = bufSize;
    for (i = 0; i < bufSize; i++) {
        tpState.samplingBufs[i].touch = 0;
    }

    enabled = OS_DisableInterrupts();
    if (!(u8)TPi_SendAutoStart(vcount, frequence)) {
        (void)OS_RestoreInterrupts(enabled);
        tpState.err_flg |= 2;
        if (tpState.callback) {
            tpState.callback(1, 4, 0);
        }
        return;
    }
    tpState.command_flg |= 2;
    tpState.err_flg &= ~2;
    (void)OS_RestoreInterrupts(enabled);
}



/*
 * sdk:      TP_RequestAutoSamplingStopAsync (libspi.TWL.HYB.a tp.o)
 */
void func_0208AD14(void)
{
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (!TPi_SendData(0x03000200)) {
        (void)OS_RestoreInterrupts(enabled);
        tpState.err_flg |= 4;
        if (tpState.callback) {
            tpState.callback(2, 4, 0);
        }
        return;
    }
    tpState.command_flg |= 4;
    tpState.err_flg &= ~4;
    (void)OS_RestoreInterrupts(enabled);
}



/*
 * sdk:      TP_GetLatestRawPointInAuto (libspi.TWL.HYB.a tp.o)
 *
 * The image listing runs 16 bytes past this function into
 * TP_GetLatestIndexInAuto (0x0208AF08), hence EXACT*.
 */
void func_0208ADB4(TPData *result)
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



/*
 * sdk:      TP_GetLatestIndexInAuto (libspi.TWL.HYB.a tp.o)
 */
u16 func_0208AF08(void)
{
    return tpState.index;
}



/*
 * sdk:      TP_CalcCalibrateParam (libspi.TWL.HYB.a tp.o)
 *
 * The divider's 64-bit denominator is a plain (non-volatile) u64 store,
 * which lets the second one become an stm; ry_width is computed before
 * dy_width even though the DWARF declares ry_width first.
 */
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



/*
 * sdk:      TP_GetCalibratedPoint (libspi.TWL.HYB.a tp.o)
 */
void func_0208B104(TPData *disp, const TPData *raw)
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



/*
 * note:     spi/ARM9/tp.o TP_WaitBusy.
 */
void func_0208B220(unsigned int command_flgs)
{
    while (tpState.command_flg & command_flgs) {
    }
}



/*
 * note:     spi/ARM9/tp.o TP_CheckError.
 */
unsigned int func_0208B238(unsigned int command_flgs)
{
    return (unsigned int)(tpState.err_flg & command_flgs);
}
