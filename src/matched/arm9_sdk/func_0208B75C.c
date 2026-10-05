/*
 * function: func_0208B75C
 * address:  0x0208B75C
 * packet:   pkt_0208B75C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MicStopAutoSampling (libspi.TWL.HYB.a mic.o)
 *
 * symbols:
 *   PXI_SendWordByFifo  0x02088610  arm
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

#define PXI_FIFO_TAG_MIC 9
#define MIC_PXI_STOP_AUTO_SAMPLING 0x03004200

extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);

BOOL func_0208B75C(void)
{
    if (PXI_SendWordByFifo(PXI_FIFO_TAG_MIC, MIC_PXI_STOP_AUTO_SAMPLING, FALSE) >= 0)
    {
        return TRUE;
    }
    return FALSE;
}
