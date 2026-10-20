#ifndef GAME_ARM9_TP_H
#define GAME_ARM9_TP_H

#include "../types.h"

/* Touch panel sample. */

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

typedef struct NvTpData {
    s16 x0;
    s16 y0;
    s16 xDotSize;
    s16 yDotSize;
} NvTpData;

void TPi_TpCallback(int tag, u32 data, BOOL err);
void TP_Init(void);
BOOL TP_GetUserInfo(TPCalibrateParam *calibrate);
void TP_SetCalibrateParam(const TPCalibrateParam *param);
void TP_RequestSamplingAsync(void);
u32 TP_WaitRawResult(TPData *result);
void TP_RequestAutoSamplingStopAsync(void);
void TP_GetLatestRawPointInAuto(TPData *result);
u16 TP_GetLatestIndexInAuto(void);
u32 TP_CalcCalibrateParam(NvTpData *calibrate, u16 raw_x1, u16 raw_y1, u16 dx1, u16 dy1, u16 raw_x2, u16 raw_y2, u16 dx2, u16 dy2);
void TP_GetCalibratedPoint(TPData *disp, const TPData *raw);
void TP_WaitBusy(unsigned int command_flgs);
unsigned int TP_CheckError(unsigned int command_flgs);

#endif
