#ifndef GAME_ARM9_MIC_H
#define GAME_ARM9_MIC_H

#include "../types.h"

/* Microphone driver interface. */

typedef enum MICResult
{
    MIC_RESULT_SUCCESS = 0,
    MIC_RESULT_BUSY,
    MIC_RESULT_ILLEGAL_PARAMETER,
    MIC_RESULT_SEND_ERROR,
    MIC_RESULT_INVALID_COMMAND,
    MIC_RESULT_ILLEGAL_STATUS,
    MIC_RESULT_FATAL_ERROR
} MICResult;

typedef void (*MICCallback)(MICResult result, void *arg);

typedef struct MICAutoParam
{
    int type;
    void *buffer;
    u32 size;
    u32 rate;
    BOOL loop_enable;
    MICCallback full_callback;
    void *full_arg;
} MICAutoParam;

void MIC_Init(void);
MICResult MIC_StartAutoSamplingAsync(const MICAutoParam *param, MICCallback callback, void *arg);
MICResult MIC_StartAutoSampling(MICAutoParam *param);
MICResult MIC_StopAutoSamplingAsync(MICCallback callback, void *arg);
MICResult MIC_StopAutoSampling(void);
void *MIC_GetLastSamplingAddress(void);
MICResult MIC_StartLimitedSamplingAsync(MICAutoParam *param, MICCallback callback, void *arg);
MICResult MIC_StartLimitedSampling(MICAutoParam *param);
MICResult MIC_StopLimitedSampling(void);
void MicCommonCallback(int tag, u32 data, BOOL err);
BOOL MicStartAutoSampling(void *buf, u32 size, u32 span, u8 flags);
BOOL MicStopAutoSampling(void);
void MicGetResultCallback(MICResult result, void *arg);
void MicWaitBusy(void);
void *MICEXi_GetLimitedSamplingCallback(void);

#endif
