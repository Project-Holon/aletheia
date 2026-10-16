/*
 * function: MIC_StartAutoSampling
 * address:  0x0208B3EC
 * packet:   pkt_0208B3EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * notes:    mic_bss models mic.o .bss as one struct: micInitialized (u16) at 0x02152FE0 and
 *            micWork (28 bytes) at 0x02152FE4; the object reaches both through one pool word.
 *
 * sdk:      MIC_StartAutoSampling (libspi.TWL.HYB.a mic.o)
 *
 * symbols:
 *   MIC_StartAutoSamplingAsync  0x0208B2BC  arm
 *   MicWaitBusy  0x0208B798  arm
 *   MicGetResultCallback  0x0208B788  arm
 *   mic_bss  0x02152FE0  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

#define TRUE 1
#define FALSE 0
#define NULL ((void *)0)

typedef enum MICResult
{
    MIC_RESULT_SUCCESS = 0,
    MIC_RESULT_BUSY = 1,
    MIC_RESULT_ILLEGAL_PARAMETER = 2,
    MIC_RESULT_SEND_ERROR = 3
} MICResult;

typedef void (*MICCallback)(MICResult result, void *arg);

typedef struct MICAutoParam MICAutoParam;

typedef struct MICWork
{
    u32 lock;
    MICCallback callback;
    void *arg;
    MICResult result;
    u32 reserved[3];
} MICWork;

/* mic.o .bss: micInitialized (u16) at +0, micWork (28 bytes) at +4 */
typedef struct MicBss
{
    u16 micInitialized;
    MICWork micWork;
} MicBss;

extern MicBss mic_bss;

extern MICResult MIC_StartAutoSamplingAsync(MICAutoParam *param, MICCallback callback, void *arg);
extern void MicWaitBusy(void);
extern void MicGetResultCallback(MICResult result, void *arg);

MICResult MIC_StartAutoSampling(MICAutoParam *param)
{
    mic_bss.micWork.result = MIC_StartAutoSamplingAsync(param, MicGetResultCallback, NULL);
    if (mic_bss.micWork.result == MIC_RESULT_SUCCESS)
    {
        MicWaitBusy();
    }
    return mic_bss.micWork.result;
}
