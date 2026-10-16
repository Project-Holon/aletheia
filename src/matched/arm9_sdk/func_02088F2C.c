/*
 * function: RtcSendPxiCommand
 * address:  0x02088F2C
 * packet:   pkt_02088F2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      RtcSendPxiCommand (librtc.TWL.HYB.a internal.o)
 *
 * symbols:
 *   PXI_SendWordByFifo             0x02088610  arm
 */

typedef unsigned long u32;
typedef int BOOL;

int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);

BOOL RtcSendPxiCommand(u32 command)
{
    command = (command << 8) & 0x7F00;
    if (PXI_SendWordByFifo(5, command, 0) < 0) {
        return 0;
    }
    return 1;
}
