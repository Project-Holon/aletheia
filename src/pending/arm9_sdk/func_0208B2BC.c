/*
 * function: func_0208B2BC
 * address:  0x0208B2BC
 * packet:   pkt_0208B2BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * TwlSDK libspi mic.o, catalog MIC_StartAutoSamplingAsync.  Validates the
 * MICAutoParam, maps the sampling type to ARM7 flag bits, takes the work lock,
 * records the callbacks and starts the ARM7 auto sampling.
 *
 * symbols:
 *   g_02152FE0            0x02152FE0  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   MicStartAutoSampling  0x0208B650  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long s32;
typedef u32 OSIntrMode;

typedef enum {
    MIC_SAMPLING_TYPE_8BIT = 0,
    MIC_SAMPLING_TYPE_12BIT = 1,
    MIC_SAMPLING_TYPE_SIGNED_8BIT = 2,
    MIC_SAMPLING_TYPE_SIGNED_12BIT = 3,
    MIC_SAMPLING_TYPE_12BIT_FILTER_OFF = 4,
    MIC_SAMPLING_TYPE_SIGNED_12BIT_FILTER_OFF = 5
} MICSamplingType;

typedef enum {
    MIC_RESULT_SUCCESS = 0,
    MIC_RESULT_BUSY = 1,
    MIC_RESULT_ILLEGAL_PARAMETER = 2,
    MIC_RESULT_SEND_ERROR = 3,
    MIC_RESULT_INVALID_COMMAND = 4,
    MIC_RESULT_ILLEGAL_STATUS = 5,
    MIC_RESULT_FATAL_ERROR = 6,
    MIC_RESULT_MAX = 7
} MICResult;

typedef void (*MICCallback)(MICResult result, void *arg);

typedef struct MICAutoParam {
    MICSamplingType type;
    void *buffer;
    u32 size;
    u32 rate;
    int loop_enable;
    MICCallback full_callback;
    void *full_arg;
} MICAutoParam;

typedef struct MICWork {
    u16 micInitialized;
    u8  pad02[2];
    int lock;
    MICCallback callback;
    void *callbackArg;
    MICResult commonResult;
    MICCallback full;
    void *fullArg;
    void *dst_buf;
} MICWork;

extern MICWork g_02152FE0;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern int MicStartAutoSampling(void *buffer, u32 size, u32 rate, u8 flags);

MICResult func_0208B2BC(MICAutoParam *param, MICCallback callback, void *arg)
{
    OSIntrMode enabled;
    u8 flags;

    if (((u32)param->buffer & 0x1f) != 0)
        return MIC_RESULT_ILLEGAL_PARAMETER;
    if ((param->size & 0x1f) != 0)
        return MIC_RESULT_ILLEGAL_PARAMETER;
    if (param->size == 0)
        return MIC_RESULT_ILLEGAL_PARAMETER;
    if (param->rate < 0x400)
        return MIC_RESULT_ILLEGAL_PARAMETER;

    switch (param->type)
    {
    case MIC_SAMPLING_TYPE_8BIT:
        flags = 0;
        break;
    case MIC_SAMPLING_TYPE_12BIT:
        flags = 1;
        break;
    case MIC_SAMPLING_TYPE_SIGNED_8BIT:
        flags = 2;
        break;
    case MIC_SAMPLING_TYPE_SIGNED_12BIT:
        flags = 3;
        break;
    case MIC_SAMPLING_TYPE_12BIT_FILTER_OFF:
        flags = 5;
        break;
    case MIC_SAMPLING_TYPE_SIGNED_12BIT_FILTER_OFF:
        flags = 7;
        break;
    default:
        return MIC_RESULT_ILLEGAL_PARAMETER;
    }

    flags = (param->loop_enable != 0) ? (u8)(flags | 0x10) : (u8)flags;

    enabled = OS_DisableInterrupts();
    if (g_02152FE0.lock != 0)
    {
        (void)OS_RestoreInterrupts(enabled);
        return MIC_RESULT_BUSY;
    }
    g_02152FE0.lock = 1;
    (void)OS_RestoreInterrupts(enabled);
    g_02152FE0.callback = callback;
    g_02152FE0.callbackArg = arg;
    g_02152FE0.full = param->full_callback;
    g_02152FE0.fullArg = param->full_arg;
    if (MicStartAutoSampling(param->buffer, param->size, param->rate, flags) == 0)
    {
        g_02152FE0.lock = 0;
        return MIC_RESULT_SEND_ERROR;
    }
    return MIC_RESULT_SUCCESS;
}
