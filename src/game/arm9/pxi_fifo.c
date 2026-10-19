/*
 * file:     pxi_fifo.c
 * unit:     yes
 * function: PXI_Init, PXI_InitFifo, PXI_SetFifoRecvCallback, PXI_IsCallbackReady, PXI_SendWordByFifo, PXIi_HandlerRecvFifoNotEmpty
 * address:  0x02088498
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
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_ResetRequestIrqMask         0x020849C8  arm
 *   OS_SetIrqFunction              0x02084774  arm
 *   OS_EnableIrqMask               0x02084968  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   FifoCtrlInit                   0x021513A4  data
 *   FifoRecvCallbackTable          0x021513A8  data
 *   PXIi_HandlerRecvFifoNotEmpty   0x02088688  arm
 */
#define reg_PXI_SUBP_FIFO_CNT (*(vu16 *)0x04000184)
#define reg_PXI_SEND_FIFO     (*(vu32 *)0x04000188)
#define reg_PXI_RECV_FIFO     (*(vu32 *)0x04100000)
#define reg_PXI_SUBPINTF (*(vu16 *)0x04000180)
#include "../types.h"

#include "../sdk_os.h"

typedef union PXIFifoMessage {
    struct {
        u32 tag:5;
        u32 err:1;
        u32 data:26;
    } e;
    u32 raw;
} PXIFifoMessage;

typedef void (*PXIFifoCallback)(int tag, u32 data, BOOL err);

#include "os_system_work_types.h"

typedef enum PXIFifoTag { PXI_FIFO_TAG_EX = 0, PXI_MAX_FIFO_TAG = 32 } PXIFifoTag;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern u32 OS_ResetRequestIrqMask(u32 intr);
extern void OS_SetIrqFunction(u32 intrBit, void (*function)(void));
extern u32 OS_EnableIrqMask(u32 intr);
void PXIi_HandlerRecvFifoNotEmpty(void);
void PXI_Init(void);
void PXI_InitFifo(void);
void PXI_SetFifoRecvCallback(int fifotag, PXIFifoCallback callback);
BOOL PXI_IsCallbackReady(int fifotag, int proc);
int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);
extern u16 FifoCtrlInit;
extern PXIFifoCallback FifoRecvCallbackTable[32];

void PXI_Init(void)
{
    PXI_InitFifo();
}

enum {
    PXI_FIFO_SUCCESS = 0,
    PXI_FIFO_FAIL_SEND_ERR = -1,
    PXI_FIFO_FAIL_SEND_FULL = -2,
    PXI_FIFO_FAIL_RECV_ERR = -3,
    PXI_FIFO_FAIL_RECV_EMPTY = -4
};

static inline OSSystemWork *OS_GetSystemWork(void)
{
    return (OSSystemWork *)0x02FFFC00;
}

/*
 * sdk:      PXI_InitFifo (libpxi.TWL.HYB.a pxi_fifo.o)
 */
void PXI_InitFifo(void)
{
    OSIntrMode enabled;
    int i;

    enabled = OS_DisableInterrupts();

    if (!FifoCtrlInit) {
        FifoCtrlInit = 1;

        OS_GetSystemWork()->pxiHandleChecker[0] = 0;

        for (i = 0; i < 32; i++) {
            FifoRecvCallbackTable[i] = 0;
        }

        reg_PXI_SUBP_FIFO_CNT = 0xC408;

        (void)OS_ResetRequestIrqMask(0x40000);
        OS_SetIrqFunction(0x40000, PXIi_HandlerRecvFifoNotEmpty);
        (void)OS_EnableIrqMask(0x40000);

        {
            int timeout;
            long c;

            for (i = 0;; i++) {
                c = reg_PXI_SUBPINTF & 15;
                reg_PXI_SUBPINTF = (u16)(c << 8);

                if (c == 0 && i > 4) {
                    break;
                }
                timeout = 1000;
                while ((reg_PXI_SUBPINTF & 15) == c) {
                    if (timeout <= 0) {
                        i = 0;
                        break;
                    }
                    timeout--;
                }
            }
        }
    }
    (void)OS_RestoreInterrupts(enabled);
}

void PXI_SetFifoRecvCallback(int fifotag, PXIFifoCallback callback)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    FifoRecvCallbackTable[fifotag] = callback;
    if (callback) {
        OS_GetSystemWork()->pxiHandleChecker[0] |= ((u32)1 << fifotag);
    } else {
        OS_GetSystemWork()->pxiHandleChecker[0] &= ~((u32)1 << fifotag);
    }
    (void)OS_RestoreInterrupts(enabled);
}

/*
 * sdk:      PXI_IsCallbackReady (libpxi.TWL.HYB.a pxi_fifo.o)
 */
BOOL PXI_IsCallbackReady(int fifotag, int proc)
{
    OSSystemWork *w = OS_GetSystemWork();

    return (w->pxiHandleChecker[proc] & (1UL << fifotag)) ? 1 : 0;
}

int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err)
{
    PXIFifoMessage fifomsg;

    fifomsg.e.tag = fifotag;
    fifomsg.e.err = err;
    fifomsg.e.data = data;

    if (reg_PXI_SUBP_FIFO_CNT & 0x4000) {
        reg_PXI_SUBP_FIFO_CNT |= 0x8000 | 0x4000;
        return -1;
    }

    {
        OSIntrMode enabled = OS_DisableInterrupts();
        if (reg_PXI_SUBP_FIFO_CNT & 0x0002) {
            (void)OS_RestoreInterrupts(enabled);
            return -2;
        }
        reg_PXI_SEND_FIFO = fifomsg.raw;
        (void)OS_RestoreInterrupts(enabled);
    }
    return 0;
}

static inline int PXIi_SetToFifo(u32 data)
{
    OSIntrMode enabled;

    if (reg_PXI_SUBP_FIFO_CNT & 0x4000) {
        reg_PXI_SUBP_FIFO_CNT |= 0x8000 | 0x4000;
        return PXI_FIFO_FAIL_SEND_ERR;
    }
    enabled = OS_DisableInterrupts();
    if (reg_PXI_SUBP_FIFO_CNT & 0x0002) {
        (void)OS_RestoreInterrupts(enabled);
        return PXI_FIFO_FAIL_SEND_FULL;
    }
    reg_PXI_SEND_FIFO = data;
    (void)OS_RestoreInterrupts(enabled);
    return PXI_FIFO_SUCCESS;
}

static inline int PXIi_GetFromFifo(u32 *data)
{
    OSIntrMode enabled;

    if (reg_PXI_SUBP_FIFO_CNT & 0x4000) {
        reg_PXI_SUBP_FIFO_CNT |= 0x8000 | 0x4000;
        return PXI_FIFO_FAIL_RECV_ERR;
    }
    enabled = OS_DisableInterrupts();
    if (reg_PXI_SUBP_FIFO_CNT & 0x0100) {
        (void)OS_RestoreInterrupts(enabled);
        return PXI_FIFO_FAIL_RECV_EMPTY;
    }
    *data = reg_PXI_RECV_FIFO;
    (void)OS_RestoreInterrupts(enabled);
    return PXI_FIFO_SUCCESS;
}

/*
 * sdk:      PXIi_HandlerRecvFifoNotEmpty (libpxi.TWL.HYB.a pxi_fifo.o)
 */
void PXIi_HandlerRecvFifoNotEmpty(void)
{
    int tag;
    int ret_code;
    PXIFifoMessage fifomsg;

    while (1) {
        ret_code = PXIi_GetFromFifo(&fifomsg.raw);
        if (ret_code == PXI_FIFO_FAIL_RECV_EMPTY) {
            break;
        }
        if (ret_code == PXI_FIFO_FAIL_RECV_ERR) {
            continue;
        }
        tag = (int)fifomsg.e.tag;
        if (tag) {
            if (FifoRecvCallbackTable[tag]) {
                FifoRecvCallbackTable[tag](tag, fifomsg.e.data, (BOOL)fifomsg.e.err);
            } else {
                if (fifomsg.e.err) {
                } else {
                    fifomsg.e.err = 1;
                    (void)PXIi_SetToFifo(fifomsg.raw);
                }
            }
        }
    }
}
