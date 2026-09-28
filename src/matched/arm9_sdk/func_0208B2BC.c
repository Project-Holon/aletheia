/*
 * function: func_0208B2BC
 * address:  0x0208B2BC
 * packet:   pkt_0208B2BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MIC_StartAutoSamplingAsync (libspi.TWL.HYB.a mic.o)
 *
 * symbols:
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   MicStartAutoSampling           0x0208B650  arm
 *   g_02152FE0                     0x02152FE0  data
 *
 * The loop flag is a ternary with both arms masked to eight bits and the
 * result narrowed again (andne/andeq, then and into r4); an if statement or
 * an unmasked ternary allocates the join differently.
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;

typedef enum MICResult {
    MIC_RESULT_SUCCESS = 0,
    MIC_RESULT_BUSY,
    MIC_RESULT_ILLEGAL_PARAMETER,
    MIC_RESULT_SEND_ERROR,
    MIC_RESULT_INVALID_COMMAND,
    MIC_RESULT_ILLEGAL_STATUS,
    MIC_RESULT_FATAL_ERROR
} MICResult;

typedef void (*MICCallback)(MICResult result, void *arg);

/* mic.o .bss: micInitialized at +0, micWork (28 bytes) at +4 */
typedef struct MicBss {
    u16 micInitialized;
    u32 lock;
    MICCallback callback;
    void *callbackArg;
    MICResult commonResult;
    MICCallback full;
    void *fullArg;
    u16 *dst_buf;
} MicBss;

extern MicBss g_02152FE0;
#define micWork g_02152FE0

typedef struct MICAutoParam {
    int type;
    void *buffer;
    u32 size;
    u32 rate;
    BOOL loop_enable;
    MICCallback full_callback;
    void *full_arg;
} MICAutoParam;

u32 OS_DisableInterrupts(void);
u32 OS_RestoreInterrupts(u32 state);
BOOL MicStartAutoSampling(void *buf, u32 size, u32 span, u8 flags);

MICResult func_0208B2BC(const MICAutoParam *param, MICCallback callback, void *arg)
{
    u32 enabled;
    u8 flags;

    if ((u32)param->buffer & 0x1f) {
        return MIC_RESULT_ILLEGAL_PARAMETER;
    }
    if (param->size & 0x1f) {
        return MIC_RESULT_ILLEGAL_PARAMETER;
    }
    if (param->size == 0) {
        return MIC_RESULT_ILLEGAL_PARAMETER;
    }
    if (param->rate < 0x400) {
        return MIC_RESULT_ILLEGAL_PARAMETER;
    }

    switch (param->type) {
    case 0:
        flags = 0;
        break;
    case 1:
        flags = 1;
        break;
    case 2:
        flags = 2;
        break;
    case 3:
        flags = 3;
        break;
    case 4:
        flags = 5;
        break;
    case 5:
        flags = 7;
        break;
    default:
        return MIC_RESULT_ILLEGAL_PARAMETER;
    }
    flags = (u8)(param->loop_enable ? (flags | 0x10) & 0xff : flags & 0xff);

    enabled = OS_DisableInterrupts();
    if (micWork.lock) {
        (void)OS_RestoreInterrupts(enabled);
        return MIC_RESULT_BUSY;
    }
    micWork.lock = 1;
    (void)OS_RestoreInterrupts(enabled);

    micWork.callback = callback;
    micWork.callbackArg = arg;
    micWork.full = param->full_callback;
    micWork.fullArg = param->full_arg;
    if (!MicStartAutoSampling(param->buffer, param->size, param->rate, flags)) {
        micWork.lock = 0;
        return MIC_RESULT_SEND_ERROR;
    }
    return MIC_RESULT_SUCCESS;
}
