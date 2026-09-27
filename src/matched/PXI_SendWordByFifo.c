/*
 * function: PXI_SendWordByFifo
 * address:  0x02088610
 * packet:   pkt_02088610
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libpxi pxi_fifo.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
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

#define reg_PXI_SUBP_FIFO_CNT (*(vu16 *)0x04000184)
#define reg_PXI_SEND_FIFO     (*(vu32 *)0x04000188)

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);

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
