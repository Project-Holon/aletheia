/*
 * file:     unit_0208B24C.c
 * unit:     yes
 * function: func_0208B24C, func_0208B2BC, func_0208B3EC, func_0208B424, func_0208B480, func_0208B4B8, func_0208B4C8, func_0208B500, func_0208B528, func_0208B548, func_0208B650, func_0208B75C, func_0208B788, func_0208B798
 * address:  0x0208B24C
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
 *   MIC_Init  0x0208B24C  arm
 *   MIC_StartAutoSamplingAsync  0x0208B2BC  arm
 *   MicWaitBusy  0x0208B798  arm
 *   MicGetResultCallback  0x0208B788  arm
 *   mic_bss  0x02152FE0  data
 *   g_02152FE4  0x02152FE4  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   MicStopAutoSampling  0x0208B75C  arm
 *   MIC_StopAutoSamplingAsync  0x0208B424  arm
 *   OSi_IsCodecTwlMode  0x02087B20  arm
 *   MICEXi_StartLimitedSamplingAsync  0x02703CDC  arm
 *   MICEXi_StartLimitedSampling  0x02703C60  arm
 *   MIC_StartAutoSampling  0x0208B3EC  arm
 *   MICEXi_StopLimitedSampling  0x02703E90  arm
 *   MIC_StopAutoSampling  0x0208B480  arm
 *   MicStartAutoSampling  0x0208B650  arm
 *   MicCommonCallback  0x0208B548  arm
 *   PXI_Init  0x02088498  arm
 *   PXI_IsCallbackReady  0x020885EC  arm
 *   PXI_SetFifoRecvCallback  0x020885A0  arm
 *   PXI_SendWordByFifo  0x02088610  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

#define TRUE 1
#define FALSE 0
#define NULL ((void *)0)

#define PXI_FIFO_TAG_MIC 9
#define PXI_PROC_ARM7 1
#define HW_MIC_LAST_ADDRESS (*(u32 *)0x02FFFF90)
#define MIC_PXI_STOP_AUTO_SAMPLING 0x03004200

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

typedef struct MICWork
{
    u32 lock;
    MICCallback callback;
    void *arg;
    MICResult result;
    MICCallback full;
    void *fullArg;
    u16 *dst_buf;
} MICWork;

/* mic.o .bss: micInitialized (u16) at +0, micWork (28 bytes) at +4 */
typedef struct MicBss
{
    u16 micInitialized;
    MICWork micWork;
} MicBss;

extern MicBss mic_bss;
extern u32 g_02152FE4;

extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern BOOL OSi_IsCodecTwlMode(void);
extern void PXI_Init(void);
extern BOOL PXI_IsCallbackReady(int fifotag, int proc);
extern void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int tag, u32 data, BOOL err));
extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);
extern void MicCommonCallback(int tag, u32 data, BOOL err);
extern BOOL MicStartAutoSampling(void *buf, u32 size, u32 span, u8 flags);
extern BOOL MicStopAutoSampling(void);
extern void MicWaitBusy(void);
extern void MicGetResultCallback(MICResult result, void *arg);
extern MICResult MIC_StartAutoSamplingAsync(const MICAutoParam *param, MICCallback callback, void *arg);
extern MICResult MIC_StopAutoSamplingAsync(MICCallback callback, void *arg);
extern MICResult MIC_StartAutoSampling(const MICAutoParam *param);
extern MICResult MIC_StopAutoSampling(void);
extern MICResult MICEXi_StartLimitedSamplingAsync(const MICAutoParam *param, MICCallback callback, void *arg);
extern MICResult MICEXi_StartLimitedSampling(const MICAutoParam *param);
extern MICResult MICEXi_StopLimitedSampling(void);

/*
 * notes:    mic_bss models mic.o .bss as one struct: micInitialized (u16) at 0x02152FE0 and
 *            micWork (28 bytes) at 0x02152FE4; the object reaches both through one pool word.
 *
 * sdk:      MIC_Init (libspi.TWL.HYB.a mic.o)
 */
void func_0208B24C(void)
{
    if (mic_bss.micInitialized)
    {
        return;
    }
    mic_bss.micInitialized = 1;
    mic_bss.micWork.lock = 0;
    mic_bss.micWork.callback = NULL;

    PXI_Init();
    while (!PXI_IsCallbackReady(PXI_FIFO_TAG_MIC, PXI_PROC_ARM7))
    {
    }
    HW_MIC_LAST_ADDRESS = 0;
    PXI_SetFifoRecvCallback(PXI_FIFO_TAG_MIC, MicCommonCallback);
}

/*
 * sdk:      MIC_StartAutoSamplingAsync (libspi.TWL.HYB.a mic.o)
 *
 * The loop flag is a ternary with both arms masked to eight bits and the
 * result narrowed again (andne/andeq, then and into r4); an if statement or
 * an unmasked ternary allocates the join differently.
 */
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
    if (mic_bss.micWork.lock) {
        (void)OS_RestoreInterrupts(enabled);
        return MIC_RESULT_BUSY;
    }
    mic_bss.micWork.lock = 1;
    (void)OS_RestoreInterrupts(enabled);

    mic_bss.micWork.callback = callback;
    mic_bss.micWork.arg = arg;
    mic_bss.micWork.full = param->full_callback;
    mic_bss.micWork.fullArg = param->full_arg;
    if (!MicStartAutoSampling(param->buffer, param->size, param->rate, flags)) {
        mic_bss.micWork.lock = 0;
        return MIC_RESULT_SEND_ERROR;
    }
    return MIC_RESULT_SUCCESS;
}

/*
 * notes:    mic_bss models mic.o .bss as one struct: micInitialized (u16) at 0x02152FE0 and
 *            micWork (28 bytes) at 0x02152FE4; the object reaches both through one pool word.
 *
 * sdk:      MIC_StartAutoSampling (libspi.TWL.HYB.a mic.o)
 */
MICResult func_0208B3EC(MICAutoParam *param)
{
    mic_bss.micWork.result = MIC_StartAutoSamplingAsync(param, MicGetResultCallback, NULL);
    if (mic_bss.micWork.result == MIC_RESULT_SUCCESS)
    {
        MicWaitBusy();
    }
    return mic_bss.micWork.result;
}

/*
 * notes:    mic_bss models mic.o .bss as one struct: micInitialized (u16) at 0x02152FE0 and
 *            micWork (28 bytes) at 0x02152FE4; the object reaches both through one pool word.
 *
 * sdk:      MIC_StopAutoSamplingAsync (libspi.TWL.HYB.a mic.o)
 */
MICResult func_0208B424(MICCallback callback, void *arg)
{
    u32 enabled = OS_DisableInterrupts();

    if (mic_bss.micWork.lock)
    {
        (void)OS_RestoreInterrupts(enabled);
        return MIC_RESULT_BUSY;
    }
    mic_bss.micWork.lock = 1;
    (void)OS_RestoreInterrupts(enabled);

    mic_bss.micWork.callback = callback;
    mic_bss.micWork.arg = arg;
    if (!MicStopAutoSampling())
    {
        mic_bss.micWork.lock = 0;
        return MIC_RESULT_SEND_ERROR;
    }
    return MIC_RESULT_SUCCESS;
}

/*
 * notes:    mic_bss models mic.o .bss as one struct: micInitialized (u16) at 0x02152FE0 and
 *            micWork (28 bytes) at 0x02152FE4; the object reaches both through one pool word.
 *
 * sdk:      MIC_StopAutoSampling (libspi.TWL.HYB.a mic.o)
 */
MICResult func_0208B480(void)
{
    mic_bss.micWork.result = MIC_StopAutoSamplingAsync(MicGetResultCallback, NULL);
    if (mic_bss.micWork.result == MIC_RESULT_SUCCESS)
    {
        MicWaitBusy();
    }
    return mic_bss.micWork.result;
}

/*
 * sdk:      MIC_GetLastSamplingAddress (libspi.TWL.HYB.a mic.o)
 */
void *func_0208B4B8(void)
{
    return *(void **)0x02FFFF90;
}

/*
 * sdk:      MIC_StartLimitedSamplingAsync (libspi.TWL.HYB.a mic.o)
 */
MICResult func_0208B4C8(MICAutoParam *param, MICCallback callback, void *arg)
{
    if (OSi_IsCodecTwlMode() == TRUE)
    {
        return MICEXi_StartLimitedSamplingAsync(param, callback, arg);
    }
    return MIC_StartAutoSamplingAsync(param, callback, arg);
}

/*
 * sdk:      MIC_StartLimitedSampling (libspi.TWL.HYB.a mic.o)
 */
MICResult func_0208B500(MICAutoParam *param)
{
    if (OSi_IsCodecTwlMode() == TRUE)
    {
        return MICEXi_StartLimitedSampling(param);
    }
    return MIC_StartAutoSampling(param);
}

/*
 * sdk:      MIC_StopLimitedSampling (libspi.TWL.HYB.a mic.o)
 */
MICResult func_0208B528(void)
{
    if (OSi_IsCodecTwlMode() == TRUE)
    {
        return MICEXi_StopLimitedSampling();
    }
    return MIC_StopAutoSampling();
}

/*
 * sdk:      MicCommonCallback (libspi.TWL.HYB.a mic.o)
 *
 * The DWARF lists (data, err); the body reads r1 and r2, so this is the
 * 3-argument PXI FIFO callback. The error path does not return. The
 * switch operand needs the (u16) cast; the plain mask swaps r5 and r6.
 */
void func_0208B548(int tag, u32 data, BOOL err)
{
    MICResult result;
    u16 command;

    if (err) {
        if (mic_bss.micWork.lock) {
            mic_bss.micWork.lock = 0;
        }
        if (mic_bss.micWork.callback) {
            MICCallback cb = mic_bss.micWork.callback;
            mic_bss.micWork.callback = 0;
            cb(MIC_RESULT_FATAL_ERROR, mic_bss.micWork.arg);
        }
    }

    command = (u16)((data & 0x7f00) >> 8);
    switch ((u16)(data & 0xff)) {
    case 0:
        result = MIC_RESULT_SUCCESS;
        break;
    case 1:
        result = MIC_RESULT_INVALID_COMMAND;
        break;
    case 2:
        result = MIC_RESULT_ILLEGAL_PARAMETER;
        break;
    case 3:
        result = MIC_RESULT_ILLEGAL_STATUS;
        break;
    case 4:
        result = MIC_RESULT_BUSY;
        break;
    default:
        result = MIC_RESULT_FATAL_ERROR;
        break;
    }

    if (command == 0x51) {
        if (mic_bss.micWork.full) {
            mic_bss.micWork.full(result, mic_bss.micWork.fullArg);
        }
        return;
    }
    if (command == 0x40) {
        if (mic_bss.micWork.dst_buf) {
            *mic_bss.micWork.dst_buf = *(volatile u16 *)0x02FFFF94;
        }
    }
    if (mic_bss.micWork.lock) {
        mic_bss.micWork.lock = 0;
    }
    if (mic_bss.micWork.callback) {
        MICCallback cb = mic_bss.micWork.callback;
        mic_bss.micWork.callback = 0;
        cb(result, mic_bss.micWork.arg);
    }
}

/*
 * sdk:      MicStartAutoSampling (libspi.TWL.HYB.a mic.o)
 */
BOOL func_0208B650(void *buf, u32 size, u32 span, u8 flags)
{
    if (PXI_SendWordByFifo(9, 0x02000000 | 0x4100 | flags, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, 0x10000 | ((u32)buf >> 16), 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, 0x20000 | ((u32)buf & 0xffff), 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, 0x30000 | (size >> 16), 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, 0x40000 | (size & 0xffff), 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, 0x50000 | (span >> 16), 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, 0x01000000 | 0x60000 | (span & 0xffff), 0) < 0) {
        return 0;
    }
    return 1;
}



/*
 * sdk:      MicStopAutoSampling (libspi.TWL.HYB.a mic.o)
 */
BOOL func_0208B75C(void)
{
    if (PXI_SendWordByFifo(PXI_FIFO_TAG_MIC, MIC_PXI_STOP_AUTO_SAMPLING, FALSE) >= 0)
    {
        return TRUE;
    }
    return FALSE;
}

/*
 * sdk:      DWC_Netcheck_SetAllow302 (libdwcauth.TWL.HYB.a dwc_netcheck.o)
 */
void func_0208B788(MICResult result, void *arg)
{
    mic_bss.micWork.result = result;
}

/* hand-written in the original: spin-wait on the lock word with the address in ip; mwccarm never picks ip for a leaf load (9 C variants tried) */
asm void func_0208B798(void)
{
    ldr ip, =g_02152FE4
loc_0208B79C:
    ldr	r0, [ip]
    cmp	r0, #1
    beq loc_0208B79C
    bx	lr
}
