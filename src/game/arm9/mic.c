/*
 * file:     mic.c
 * unit:     yes
 * function: MIC_Init, MIC_StartAutoSamplingAsync, MIC_StartAutoSampling, MIC_StopAutoSamplingAsync, MIC_StopAutoSampling, MIC_GetLastSamplingAddress, MIC_StartLimitedSamplingAsync, MIC_StartLimitedSampling, MIC_StopLimitedSampling, MicCommonCallback, MicStartAutoSampling, MicStopAutoSampling, MicGetResultCallback, MicWaitBusy, MICEXi_GetLimitedSamplingCallback
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
 * Unlabelled 12-byte ARM pointer thunk in a .word run:
 *   ldr r0, [pc, #0]; bx lr; .word func_02152FE4
 * It is not one of the two linker-veneer encodings the `veneer` class
 * recognises (it loads r0 and returns through lr rather than branching through
 * ip/pc), so only a `matched` entry can witness it.  Matching it lets the two
 * TWL parks src/pending/MICEXi_StartLimitedSamplingAsync.c and src/pending/MICEXi_StopLimitedSamplingAsync.c
 * resolve their `bl` sites.  The pointer word resolves `literal x1` against
 * the duplicate 0x02152FE4 word at 0x0208B7AC.
 * Addresses are Black-image addresses.
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
 *   func_02152FE4  0x02152FE4  arm
 */
#define TRUE 1
#define FALSE 0
#define NULL ((void *)0)
#define PXI_FIFO_TAG_MIC 9
#define PXI_PROC_ARM7 1
#define HW_MIC_LAST_ADDRESS (*(u32_0208B24C *)0x02FFFF90)
#define MIC_PXI_STOP_AUTO_SAMPLING 0x03004200
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32_0208B24C;

typedef int BOOL;

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
    u32_0208B24C size;
    u32_0208B24C rate;
    BOOL loop_enable;
    MICCallback full_callback;
    void *full_arg;
} MICAutoParam;

typedef struct MICWork
{
    u32_0208B24C lock;
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

typedef unsigned int u32_0208B7B0;

extern u32_0208B24C OS_DisableInterrupts(void);
extern u32_0208B24C OS_RestoreInterrupts(u32_0208B24C state);
extern BOOL OSi_IsCodecTwlMode(void);
extern void PXI_Init(void);
extern BOOL PXI_IsCallbackReady(int fifotag, int proc);
extern void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int tag, u32_0208B24C data, BOOL err));
extern int PXI_SendWordByFifo(int fifotag, u32_0208B24C data, BOOL err);
extern void MicCommonCallback(int tag, u32_0208B24C data, BOOL err);
extern BOOL MicStartAutoSampling(void *buf, u32_0208B24C size, u32_0208B24C span, u8 flags);
extern BOOL MicStopAutoSampling(void);
extern void MicWaitBusy(void);
extern void MicGetResultCallback(MICResult result, void *arg);
extern MICResult MIC_StartAutoSamplingAsync(const MICAutoParam *param, MICCallback callback, void *arg);
extern MICResult MIC_StopAutoSamplingAsync(MICCallback callback, void *arg);
extern MICResult MIC_StopAutoSampling(void);
extern MICResult MICEXi_StartLimitedSamplingAsync(const MICAutoParam *param, MICCallback callback, void *arg);
extern MICResult MICEXi_StartLimitedSampling(const MICAutoParam *param);
extern MICResult MICEXi_StopLimitedSampling(void);
extern void func_02152FE4(void);
void MIC_Init(void);
MICResult MIC_StartAutoSampling(MICAutoParam *param);
void *MIC_GetLastSamplingAddress(void);
MICResult MIC_StartLimitedSamplingAsync(MICAutoParam *param, MICCallback callback, void *arg);
MICResult MIC_StartLimitedSampling(MICAutoParam *param);
MICResult MIC_StopLimitedSampling(void);
void *MICEXi_GetLimitedSamplingCallback(void);
extern MicBss mic_bss;
extern u32_0208B24C g_02152FE4;


/*
 * notes:    mic_bss models mic.o .bss as one struct: micInitialized (u16) at 0x02152FE0 and
 *            micWork (28 bytes) at 0x02152FE4; the object reaches both through one pool word.
 *
 * sdk:      MIC_Init (libspi.TWL.HYB.a mic.o)
 */
void MIC_Init(void)
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
MICResult MIC_StartAutoSamplingAsync(const MICAutoParam *param, MICCallback callback, void *arg)
{
    u32_0208B24C enabled;
    u8 flags;

    if ((u32_0208B24C)param->buffer & 0x1f) {
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
MICResult MIC_StartAutoSampling(MICAutoParam *param)
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
MICResult MIC_StopAutoSamplingAsync(MICCallback callback, void *arg)
{
    u32_0208B24C enabled = OS_DisableInterrupts();

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
MICResult MIC_StopAutoSampling(void)
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
void *MIC_GetLastSamplingAddress(void)
{
    return *(void **)0x02FFFF90;
}


/*
 * sdk:      MIC_StartLimitedSamplingAsync (libspi.TWL.HYB.a mic.o)
 */
MICResult MIC_StartLimitedSamplingAsync(MICAutoParam *param, MICCallback callback, void *arg)
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
MICResult MIC_StartLimitedSampling(MICAutoParam *param)
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
MICResult MIC_StopLimitedSampling(void)
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
void MicCommonCallback(int tag, u32_0208B24C data, BOOL err)
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
BOOL MicStartAutoSampling(void *buf, u32_0208B24C size, u32_0208B24C span, u8 flags)
{
    if (PXI_SendWordByFifo(9, 0x02000000 | 0x4100 | flags, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, 0x10000 | ((u32_0208B24C)buf >> 16), 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, 0x20000 | ((u32_0208B24C)buf & 0xffff), 0) < 0) {
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
BOOL MicStopAutoSampling(void)
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
void MicGetResultCallback(MICResult result, void *arg)
{
    mic_bss.micWork.result = result;
}


/* hand-written in the original: spin-wait on the lock word with the address in ip; mwccarm never picks ip for a leaf load (9 C variants tried) */
asm void MicWaitBusy(void)
{
    ldr ip, =g_02152FE4
loc_0208B79C:
    ldr	r0, [ip]
    cmp	r0, #1
    beq loc_0208B79C
    bx	lr
}


void *MICEXi_GetLimitedSamplingCallback(void)
{
    return (void *)func_02152FE4;
}
