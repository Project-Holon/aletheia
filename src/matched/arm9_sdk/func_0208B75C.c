/*
 * function: func_0208B75C
 * address:  0x0208B75C
 * packet:   pkt_0208B75C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * TwlSDK libspi mic.o, catalog MicStopAutoSampling.  Sends the ARM7 stop
 * command over the mic FIFO and reports whether it was accepted.
 *
 * symbols:
 *   PXI_SendWordByFifo  0x02088610  arm
 */

typedef long s32;
typedef unsigned long u32;
typedef int BOOL;

extern s32 PXI_SendWordByFifo(s32 fifotag, u32 data, s32 err);

BOOL func_0208B75C(void)
{
    BOOL ret = 0;

    if (PXI_SendWordByFifo(9, 0x03004200, 0) >= 0)
    {
        ret = 1;
    }
    return ret;
}
