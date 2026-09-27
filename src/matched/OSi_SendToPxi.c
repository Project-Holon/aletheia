/*
 * function: OSi_SendToPxi
 * address:  0x02084A84
 * packet:   pkt_02084A84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_pxi.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 *
 * symbols:
 *   PXI_SendWordByFifo  0x02088610  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;

extern int PXI_SendWordByFifo(int fifotag, u32 data, int err);

void OSi_SendToPxi(u16 data)
{
    u32 pxi_send_data = (u32)data << 8;

    while (PXI_SendWordByFifo(12, pxi_send_data, 0) != 0) {
    }
}
