/*
 * function: func_02088688
 * address:  0x02088688
 * packet:   pkt_02088688
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      PXIi_HandlerRecvFifoNotEmpty (libpxi.TWL.HYB.a pxi_fifo.o)
 *
 * symbols:
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   FifoRecvCallbackTable          0x021513A8  data
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef volatile u32 vu32;
typedef volatile u16 vu16;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef union PXIFifoMessage {
    struct {
        u32 tag:5;
        u32 err:1;
        u32 data:26;
    } e;
    u32 raw;
} PXIFifoMessage;

typedef void (*PXIFifoCallback)(int tag, u32 data, BOOL err);

#define reg_PXI_SUBP_FIFO_CNT (*(vu16 *)0x04000184)
#define reg_PXI_SEND_FIFO     (*(vu32 *)0x04000188)
#define reg_PXI_RECV_FIFO     (*(vu32 *)0x04100000)

enum {
    PXI_FIFO_SUCCESS = 0,
    PXI_FIFO_FAIL_SEND_ERR = -1,
    PXI_FIFO_FAIL_SEND_FULL = -2,
    PXI_FIFO_FAIL_RECV_ERR = -3,
    PXI_FIFO_FAIL_RECV_EMPTY = -4
};

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);

extern PXIFifoCallback FifoRecvCallbackTable[32];

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

void func_02088688(void)
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
