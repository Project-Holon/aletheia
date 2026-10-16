/*
 * function: MIC_Init
 * address:  0x0208B24C
 * packet:   pkt_0208B24C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * notes:    mic_bss models mic.o .bss as one struct: micInitialized (u16) at 0x02152FE0 and
 *            micWork (28 bytes) at 0x02152FE4; the object reaches both through one pool word.
 *
 * sdk:      MIC_Init (libspi.TWL.HYB.a mic.o)
 *
 * symbols:
 *   PXI_Init  0x02088498  arm
 *   PXI_IsCallbackReady  0x020885EC  arm
 *   PXI_SetFifoRecvCallback  0x020885A0  arm
 *   mic_bss  0x02152FE0  data
 *   MicCommonCallback  0x0208B548  arm
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

#define PXI_FIFO_TAG_MIC 9
#define PXI_PROC_ARM7 1
#define HW_MIC_LAST_ADDRESS (*(u32 *)0x02FFFF90)

extern void PXI_Init(void);
extern BOOL PXI_IsCallbackReady(int fifotag, int proc);
extern void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int tag, u32 data, BOOL err));
extern void MicCommonCallback(int tag, u32 data, BOOL err);

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
